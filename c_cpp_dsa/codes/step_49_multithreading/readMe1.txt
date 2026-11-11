####################################################################################################
C++ MULTITHREADING AND CONCURRENCY - COMPLETE ROADMAP (C++11 TO C++20)
####################################################################################################
Re-organised topic by topic. Every module has two parts: (1) READ - the topics and sub-topics to
study, then (2) PRACTICE QUESTIONS - complete problem statements to solve right after reading that
module. Modules are ordered as a learning path, so earlier modules are prerequisites for later ones.


HOW TO READ THIS FILE
  [NEW]            = topic or question added in this revision (not in your original file).
  (original Qn)    = question carried over from your original 35-question list (number kept for tracking).
  [Easy/Medium/Hard] = suggested difficulty. Tick the [ ] box when you have solved and tested a question.
  Every question: write the code, compile it, run it many times, and run it under ThreadSanitizer
  (-fsanitize=thread) whenever it uses threads. A solution that only works once is not a solution.


BUILD FLAGS YOU WILL NEED
  g++ -std=c++20 -O2 -g -pthread file.cpp -o file          (normal build)
  g++ -std=c++20 -O1 -g -pthread -fsanitize=thread  ...      (ThreadSanitizer; do not mix with ASan)
  g++ -std=c++20 -O1 -g -pthread -fsanitize=address ...      (AddressSanitizer / use-after-free)
  add -ltbb for C++17 parallel algorithms with libstdc++ (GCC 9+), -latomic / -mcx16 for 16-byte atomics.
  Library support differs per compiler: jthread (GCC 10+), latch/barrier/semaphore/osyncstream (GCC 11+),
  hardware_destructive_interference_size and atomic<shared_ptr> (GCC 12+). Check your compiler first.


####################################################################################################
SECTION 0 - CONCURRENCY FEATURES BY C++ STANDARD
####################################################################################################
C++11  std::thread, mutex family (mutex, recursive_mutex, timed_mutex, recursive_timed_mutex), lock_guard,
       unique_lock, std::lock / std::try_lock, condition_variable(_any), promise / future / shared_future /
       packaged_task / async, std::atomic + atomic_flag, the memory model (memory_order_*), fences,
       thread_local, thread-safe static initialisation, call_once / once_flag, std::chrono, exception_ptr,
       system_error / future_error, notify_all_at_thread_exit, quick_exit / at_quick_exit.
C++14  shared_timed_mutex + shared_lock, generic lambdas, init-captures (move into lambdas), chrono literals
       (100ms, 2s), std::make_unique, std::exchange, relaxed constexpr.
C++17  scoped_lock, shared_mutex, parallel algorithms + execution policies (seq / par / par_unseq), new
       algorithms (reduce, transform_reduce, inclusive/exclusive_scan, for_each_n), hardware_destructive /
       constructive_interference_size, atomic::is_always_lock_free, CTAD for lock wrappers, if/switch with
       initialiser, inline variables, std::invoke, std::apply, [*this] capture, constexpr lambdas,
       pmr synchronized_pool_resource.
C++20  std::jthread + stop_token / stop_source / stop_callback, counting_semaphore / binary_semaphore, latch,
       barrier, atomic_ref, atomic<shared_ptr> / atomic<weak_ptr>, atomic wait/notify, atomic_flag
       test/wait/notify, atomic<float/double> arithmetic, atomic default-initialisation, osyncstream,
       coroutines, std::span, concepts (std::invocable), std::bind_front, template lambdas, unseq policy,
       condition_variable_any + stop_token, memory-model clarifications, [=] implicit this deprecated.
Out of scope (C++23/26): std::move_only_function, std::generator, std::expected, std::execution
       (senders/receivers), std::hazard_pointer, std::rcu. They are mentioned only where they explain why
       something is missing from C++11-20.


####################################################################################################
PART A - FOUNDATIONS
####################################################################################################

====================================================================================================
MODULE 1: Multithreading Fundamentals   [Concepts, OS and hardware]
====================================================================================================

READ - topics & subtopics:
  * Process vs. Thread: address space layout, context switching costs, kernel vs. user space
    threads.
  * Execution Paradigms: single-threading vs. multithreading, Concurrency vs. Parallelism.
  * Hardware Integration: CPU cores, logical cores, hyperthreading,
    std::thread::hardware_concurrency().
  * Thread Execution Lifecycle: creation, execution, blocking, ready state, termination.
  * Main Thread Roles: application initialization, static variable initialization, thread joining
    responsibilities.
  * Context Switching & Scheduling: quantum allocation, preemptive vs. cooperative scheduling, cache
    thrashing.
  * Data Scopes: shared data vs. stack memory vs. thread-local storage (thread_local).
  * Costs & Limitations: over-subscription, lock overhead, cache coherence traffic,
    non-deterministic execution.
  * [NEW] Memory hierarchy: registers, L1/L2/L3 caches, cache lines (64 bytes), main memory latency
    numbers, MESI coherence protocol (overview).
  * [NEW] CPU and compiler reordering: store buffers, out-of-order execution, strong (x86 TSO) vs.
    weak (ARM/POWER) memory models.
  * [NEW] CPU-bound vs. I/O-bound workloads and how each decides the sensible number of threads.
  * [NEW] Concurrency models: thread-per-request, thread pool, event loop / reactor, green threads
    and fibers vs. kernel threads, coroutines.
  * [NEW] Per-thread resources: stack size (ulimit -s), thread creation cost, TLS block, kernel task
    structure.
  * [NEW] Vocabulary: thread-safe vs. reentrant vs. async-signal-safe; atomicity, visibility,
    ordering (the three problems).
  * [NEW] Amdahl's Law and Gustafson's Law (theoretical speedup limits).
  * [NEW] Compiling and linking threaded programs (-pthread), checking threads with ps -L / top -H /
    /proc/<pid>/status.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q1.1   [Easy]   [NEW]
        Print std::thread::hardware_concurrency(). Then spawn exactly that many threads, each
        running a busy CPU loop for 5 seconds, and watch per-core usage with htop or top (press 1).
        Deliverable: write down logical cores vs. physical cores (lscpu) and what changes if you
        start 2x that many threads.

  [ ] Q1.2   [Medium]   [NEW]
        Measure thread creation cost. Create and join 10,000 threads whose body is empty and report
        the average microseconds per create+join. Compare it with calling a function 10,000 times
        and with handing 10,000 tasks to one long-lived thread through a queue.
        Deliverable: a three-row table and one sentence on why thread pools exist.

  [ ] Q1.3   [Medium]   [NEW]
        Measure context-switch latency. Two threads ping-pong a token through two pipes (or two
        condition variables) 1,000,000 times. Compute the average one-way latency. Repeat with both
        threads pinned to the same core (taskset -c 0) and to different cores.
        Deliverable: both numbers and an explanation of the difference.

  [ ] Q1.4   [Easy]   [NEW]
        Amdahl's Law by calculation. A program has a 20% serial fraction. Compute the maximum
        speedup for 2, 4, 8, 16 and infinite cores. Then write a program with an artificially serial
        part (e.g. a mutex-protected 20% section) and compare measured speedup with the prediction.
        Deliverable: predicted vs. measured table for 1, 2, 4, 8 threads.

  [ ] Q1.5   [Easy]   [NEW]
        Written answers (no code). (a) Define concurrency vs. parallelism with one example each. (b)
        List what a thread shares with other threads of the same process and what it owns privately.
        (c) Give 3 CPU-bound and 3 I/O-bound examples and say which kind benefits from more threads
        than cores, and why.

  [ ] Q1.6   [Medium]   [NEW]
        Thread stack limits. Write a recursive function that touches a local array and recurse in a
        worker thread until it crashes; record the maximum depth. Repeat after changing ulimit -s,
        and again for a thread created with a custom stack size (pthread_attr_setstacksize through
        pthread_create).
        Deliverable: depth vs. stack size table and why deep recursion in a worker thread is riskier
        than in main.

====================================================================================================
MODULE 2: C++11 Thread Management (std::thread)   [C++11]
====================================================================================================

READ - topics & subtopics:
  * Basic Threading: std::thread, header <thread>.
  * Callable Objects: function pointers, functors, and lambda expressions as entry points.
  * Argument Passing: passing parameters by value, by pointer, and by reference using std::ref /
    std::cref.
  * Thread Identification: std::thread::id, get_id(), and std::this_thread::get_id().
  * Lifetime Management: join(), detach(), checking joinable().
  * Detached Thread Risks: dangling references, accessing destroyed stack resources, process
    shutdown behaviors.
  * Move Semantics: thread ownership transfer via move constructors and move assignment.
  * Exception Handling: uncaught exceptions in worker threads, standard behavior of calling
    std::terminate on destruction of a joinable thread.
  * Thread Execution Helpers: std::this_thread::sleep_for(), sleep_until(), yield().
  * RAII Thread Management: custom wrappers for safe thread join/detach on scope termination.
  * [NEW] std::thread constructor semantics: arguments are decay-copied (or moved) into internal
    storage, then invoked as rvalues; why std::ref is needed.
  * [NEW] std::thread is movable but not copyable; swap(); default-constructed (non-joinable)
    thread; moving into containers (vector<thread>).
  * [NEW] Running member functions: std::thread t(&Class::method, &obj, args...) and the lifetime of
    obj.
  * [NEW] Failure to create a thread: std::system_error (resource_unavailable_try_again) and OS
    limits (ulimit -u, memory).
  * [NEW] What happens when main() returns or exit() is called while detached threads still run;
    interaction with static destruction.
  * [NEW] std::thread::native_handle() to reach pthread_t for names, affinity, priority (see Module
    21).
  * [NEW] std::notify_all_at_thread_exit and at_thread_exit semantics (overview), quick_exit /
    at_quick_exit.
  * [NEW] Partitioning work across N threads: chunking, one result slot per thread, avoiding a
    shared hot variable.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q2.1   [Easy]   (original Q1)
        Launch a thread that prints "Hello from thread <id>" and join it. Print main's thread id
        too.
        Extend: start three threads from (a) a free function, (b) a functor with operator(), (c) a
        lambda. Show that std::thread::id can be printed, compared and hashed (use it as an
        unordered_map key).

  [ ] Q2.2   [Medium]   (original Q2)
        Pass arguments to a thread (1) by value, (2) by reference using std::ref, (3) as a move-only
        type (std::unique_ptr<int>). For each, write a version that works and a version that fails:
        e.g. int& without std::ref (compile error), pointer to a local plus detach (dangling),
        unique_ptr passed without std::move (compile error).
        In comments explain why each works or fails, including the decay-copy rule and why the
        callee sees an rvalue.

  [ ] Q2.3   [Medium]   (original Q5)
        State (in comments, with a demo) what happens when a joinable std::thread is destroyed
        without join() or detach() (std::terminate). Then write an RAII wrapper (a mini jthread
        called scoped_thread): takes a std::thread by move, joins in the destructor if joinable, is
        move-only, and exposes get_id().
        Test it: throw an exception between creating the thread and the end of scope and prove the
        thread is still joined.

  [ ] Q2.4   [Medium]   (original Q14)
        Sum a std::vector<long long> of 100 million elements with N threads (N = 1, 2, 4, ... up to
        2 x hardware_concurrency). Each thread sums its own chunk into its own local variable, then
        the results are added. Produce a table of time and speedup vs. N and the speedup curve.
        Explain where the curve flattens (physical cores, hyperthreads, memory bandwidth) and
        compare with a version that has all threads add into one shared atomic.

  [ ] Q2.5   [Easy]   [NEW]
        Run a member function in a thread two ways: std::thread t(&Worker::run, &w, 42) and a lambda
        capturing &w. Then create the bug: let w go out of scope while a detached thread still uses
        it. Show it with AddressSanitizer and fix it by joining (or by sharing ownership with
        shared_ptr).

  [ ] Q2.6   [Medium]   [NEW]
        Thread creation failure. Spawn threads in a loop (holding them blocked on a latch/flag)
        until std::thread throws. Catch std::system_error, print code() and what(), then release and
        join everything cleanly.
        Deliverable: the maximum thread count on your machine and which limit you hit (ulimit -u,
        memory, cgroup).

  [ ] Q2.7   [Medium]   [NEW]
        Uncaught exception in a worker. Make the thread function throw and observe std::terminate.
        Then wrap the body in try/catch(...), store std::current_exception() in a slot protected by
        a mutex, join, and rethrow it in main with std::rethrow_exception. (A fuller treatment with
        futures comes in Module 8.)

  [ ] Q2.8   [Medium]   [NEW]
        Detached thread vs. process exit. Start a detached thread that prints a line every 100 ms
        and let main return after 350 ms. Observe truncated/undefined behaviour at exit, especially
        when the thread touches a global object that is already destroyed.
        Fix it properly with a stop flag + join, and explain why detach is rarely the right answer.

====================================================================================================
MODULE 3: Lambda Expressions, Callables and Forwarding   [C++11 - C++20]
====================================================================================================

READ - topics & subtopics:
  * Capture Clauses: value captures ([=]), reference captures ([&]), mixed captures.
  * Object Lifetime: dangling reference pitfalls when passing captured scopes to worker threads.
  * Class Member Captures: capturing this by reference vs. *this by value (C++17).
  * Generalized Lambda Captures (C++14): moving move-only types (std::unique_ptr,
    std::packaged_task) into lambdas using [ptr = std::move(ptr)].
  * Generic Lambdas (C++14): using auto parameter types in concurrent callback implementations.
  * Mutable Lambdas: modifying value-captured variables within concurrent worker lambdas.
  * Type Wrappers: using std::function vs. direct template instantiation for thread target
    callables.
  * Perfect Forwarding: forwarding thread target arguments safely with std::forward.
  * [NEW] std::bind and its pitfalls vs. lambdas; std::bind_front (C++20).
  * [NEW] std::invoke (C++17) for uniform calls of functions, member pointers and functors;
    std::apply for unpacking tuples; std::invoke_result_t, std::decay_t, std::remove_cvref_t.
  * [NEW] Move-only callables: std::function requires copy-constructible targets
    (std::move_only_function is C++23) - workarounds with shared_ptr or a custom unique_function.
  * [NEW] C++20 lambda changes: pack expansion in init-capture, template lambdas ([]<class T>(T
    x){}), [=] implicit capture of this is deprecated, constexpr lambdas (C++17).
  * [NEW] Concepts for task APIs (C++20): std::invocable, std::regular_invocable,
    std::invoke_result.
  * [NEW] std::reference_wrapper, std::make_unique (C++14), perfect-forwarding pack capture
    pitfalls.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q3.1   [Easy]   [NEW]
        Dangling captures. Write a function that starts a detached thread with a lambda capturing a
        local variable by reference ([&]) and returns. Observe garbage/crash and confirm with
        AddressSanitizer (stack-use-after-return). Fix it three ways: capture by value, move the
        object in, share ownership with std::shared_ptr.

  [ ] Q3.2   [Medium]   [NEW]
        Move a std::unique_ptr<Widget> into a thread using a C++14 init-capture ([p =
        std::move(p)]). Show that the lambda must be mutable if the body modifies or moves p, and
        explain why. Show the C++11 workaround with std::bind or a shared_ptr wrapper.

  [ ] Q3.3   [Medium]   [NEW]
        Write template<class F, class... Args> std::thread run_async(F&& f, Args&&... args) using
        perfect forwarding, std::invoke and an init-capture pack (C++20) or std::apply with a tuple
        (C++17). Test it with a free function, a member-function pointer + object, a lambda, a
        functor, and a move-only argument.

  [ ] Q3.4   [Medium]   [NEW]
        The [this] trap. Make a class that owns a std::thread member whose lambda captures [this].
        Destroy the object while the thread is still running (bug), then fix it by joining in the
        destructor and declaring the thread as the LAST data member. Show what [*this] (C++17)
        changes and when copying the object is acceptable.

  [ ] Q3.5   [Easy]   [NEW]
        Generic lambda: write auto add = [](auto a, auto b){ return a + b; } and run it from three
        threads with int, double and std::string. Then write a C++20 template lambda constrained
        with std::integral (and show the compile error for a double).

  [ ] Q3.6   [Medium]   [NEW]
        std::function vs. templates. Benchmark calling a trivial callable 100 million times through
        (a) a template parameter F, (b) a function pointer, (c) std::function. Explain the overhead
        (type erasure, possible heap allocation). Then explain why std::function cannot hold a
        move-only lambda and implement a small move-only unique_function<void()> (type-erased, owns
        the callable) - you will need it for the thread pool in Module 17.

====================================================================================================
MODULE 4: Time, Clocks and Timeouts (std::chrono)   [C++11 / C++14 literals]
====================================================================================================

READ - topics & subtopics:
  * [NEW] Clocks: steady_clock (monotonic) vs. system_clock (can jump) vs. high_resolution_clock
    (usually an alias); which one to use for timeouts and measurement.
  * [NEW] duration, time_point, duration_cast, ratio; integer vs. floating-point durations; chrono
    literals (C++14): 100ms, 2s, 5us.
  * [NEW] Sleeping and deadlines: sleep_for vs. sleep_until, relative vs. absolute timeouts, drift
    when sleeping repeatedly.
  * [NEW] Timed APIs across the library: try_lock_for/until, condition_variable::wait_for/until,
    future::wait_for/until, counting_semaphore::try_acquire_for (C++20), jthread timed waits.
  * [NEW] Sleeps can return late (scheduler) and clocks have finite resolution; yield() vs. sleep(0)
    vs. spinning.
  * [NEW] Measuring correctly: warm-up, repeat runs, avoid compiler elimination of benchmarked code,
    report median and tail.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q4.1   [Easy]   [NEW]
        Write an RAII Stopwatch class based on steady_clock that prints elapsed microseconds when it
        goes out of scope. Use it to re-time Q1.2 and Q2.4 and print results in a consistent table.

  [ ] Q4.2   [Medium]   [NEW]
        Write a deadline-based retry loop: try_lock_until(deadline) on a std::timed_mutex while
        another thread holds the lock for 2 seconds; deadline = steady_clock::now() + 500ms. Explain
        in comments what would go wrong if you used system_clock and the wall clock jumped backwards
        (NTP step).

  [ ] Q4.3   [Medium]   [NEW]
        Periodic task runner: run a callback every 100 ms for one minute. Implement (a) naive
        sleep_for(100ms) after each run and (b) drift-free sleep_until(next += 100ms). Record the
        actual start time of each iteration and print max/avg drift for both.

  [ ] Q4.4   [Medium]   [NEW]
        Timed wait with a predicate: a worker waits on a condition_variable with wait_for(lock, 2s,
        pred). In run A main sets the flag after 1 s; in run B it never does. Print which outcome
        occurred (predicate result vs. timeout) and how long the wait lasted. Also repeat with
        wait_until and an absolute deadline.

####################################################################################################
PART B - SYNCHRONIZATION
####################################################################################################

====================================================================================================
MODULE 5: Mutexes and Locking Mechanisms   [C++11, C++14, C++17]
====================================================================================================

READ - topics & subtopics:
  * Critical Sections: race conditions, data races, and mutual exclusion.
  * Basic Mutex: std::mutex, manual lock() and unlock() risks.
  * RAII Lock Wrappers: std::lock_guard (C++11) - basic scope-bound locking.
  * RAII Lock Wrappers: std::unique_lock (C++11) - flexible locking, defer locking, timed locking,
    explicit unlock, moveability.
  * RAII Lock Wrappers: std::scoped_lock (C++17) - variadic RAII lock manager that safely locks
    multiple mutexes using deadlock-avoidance algorithms.
  * Lock Strategies/Flags: std::adopt_lock, std::defer_lock, std::try_to_lock.
  * Deadlocks: causes, detection, prevention, and hierarchical locking order.
  * Deadlock Avoidance API: std::lock() for multi-mutex acquiring without deadlock.
  * Specialized Mutexes: std::recursive_mutex - re-entrant locking semantics and performance
    penalties.
  * Specialized Mutexes: std::timed_mutex and std::recursive_timed_mutex - try_lock_for(),
    try_lock_until().
  * Specialized Mutexes: std::shared_mutex (C++17) and std::shared_timed_mutex (C++14) -
    reader-writer locks.
  * std::shared_lock - shared acquisition wrapper for reader threads (correction: it arrived in
    C++14 together with shared_timed_mutex, not C++17).
  * [NEW] std::try_lock (multiple mutexes) and std::mutex::try_lock; mutexes are neither copyable
    nor movable; destroying a locked mutex is UB.
  * [NEW] Lock granularity: coarse vs. fine-grained locking, keeping critical sections short, never
    doing I/O or calling unknown callbacks while holding a lock.
  * [NEW] Interface races (check-then-act): the top()/pop() problem; designing thread-safe
    interfaces (try_pop, return by value / shared_ptr).
  * [NEW] Don't leak references/pointers to guarded data; mutable mutex for const member functions;
    lock ownership documented in class design.
  * [NEW] The four Coffman conditions for deadlock; lock hierarchy implementation; lock ordering by
    address.
  * [NEW] CTAD for lock wrappers (C++17: std::scoped_lock lk(a, b);), if-with-initialiser (if
    (std::lock_guard g(m); cond) {...}), unique_lock::release().
  * [NEW] Fairness and starvation: std::mutex gives no fairness guarantee; lock convoys; priority
    inversion (see Module 21).
  * [NEW] Static analysis: Clang thread-safety annotations (-Wthread-safety, GUARDED_BY, REQUIRES).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q5.1   [Easy]   (original Q3)
        Start N = 8 threads in a loop; each prints "Thread <id> started" and "Thread <id> done"
        using std::cout without any lock and notice the garbled/interleaved output. Fix it with a
        std::mutex and std::lock_guard.
        Then write a SafeLogger class whose log(...) builds the whole line in a local string first
        and takes the lock only for the single write, so the critical section is as short as
        possible.

  [ ] Q5.2   [Medium]   (original Q4)
        Increment one shared int counter 1,000,000 times from each of 4 threads (expected
        4,000,000). (a) Show the race: run 10 times and print the final values. (b) Fix with
        std::mutex. (c) Fix with std::atomic<int> (fetch_add). (d) Fix with a per-thread local
        counter merged at the end.
        Time all four (average of 10 runs) and compare; explain the differences. (Do parts (c)-(d)
        after Module 9 if you have not met atomics yet.)

  [ ] Q5.3   [Medium]   (original Q11)
        Reproduce a deadlock: two threads lock mutexA and mutexB in opposite order (add a short
        sleep between the two locks to make it deterministic). Show that the program hangs and
        locate the cycle with gdb (info threads, thread apply all bt).
        Fix it three ways: (a) a global lock order (e.g. by address), (b) std::lock +
        std::adopt_lock, (c) std::scoped_lock. Name the Coffman condition each fix breaks.

  [ ] Q5.4   [Hard]   (original Q15)
        Dining Philosophers (5 philosophers, 5 forks). Implement at least three deadlock-free
        solutions: (a) resource hierarchy (always pick the lower-numbered fork first), (b) allow at
        most 4 philosophers at the table (counting semaphore or condition variable), (c)
        std::scoped_lock on both forks (or try_lock + randomised backoff).
        Each philosopher eats 1000 times. Record meals per philosopher to prove there is no
        starvation (max/min ratio), and add a watchdog that fails the test if no progress happens
        for 5 seconds.

  [ ] Q5.5   [Medium]   (original Q18)
        Build a read-heavy cache Cache<K, V> with get(key) and put(key, value) guarded by
        std::shared_mutex (std::shared_lock for get, std::unique_lock for put). Benchmark it against
        the same cache guarded by a plain std::mutex for read/write mixes of 99/1, 90/10 and 50/50
        with 1, 2, 4 and 8 threads.
        Deliverable: a throughput table and an explanation of when shared_mutex is slower than a
        plain mutex (bookkeeping overhead, writer contention).

  [ ] Q5.6   [Medium]   [NEW]
        Interface race. With std::stack<int> + a mutex around each call, show the race in if
        (!s.empty()) { x = s.top(); s.pop(); } across two threads. Then design ThreadSafeStack<T>
        with bool try_pop(T&) and std::shared_ptr<T> pop() (or std::optional<T>) that is free of the
        race and safe if T's copy/move throws.

  [ ] Q5.7   [Medium]   [NEW]
        Exercise every unique_lock feature: (a) std::defer_lock followed by std::lock(a, b); (b)
        std::try_to_lock to do optional work only if the lock is free; (c) unlock() in the middle of
        a scope to call a slow function outside the lock and lock() again; (d) a function that
        returns a std::unique_lock so the caller keeps the lock (ownership transfer).

  [ ] Q5.8   [Medium]   [NEW]
        Timed mutex. Thread A holds a std::timed_mutex for 2 seconds. Thread B calls
        try_lock_for(300ms) in a loop of 8 attempts and prints success/failure and elapsed time of
        each attempt. Implement a helper "lock with timeout, else throw timeout_error" and use it.

  [ ] Q5.9   [Medium]   [NEW]
        Recursive mutex. Write an Account class with deposit(), withdraw() and transfer() where
        transfer() calls the other two; first make it work with std::recursive_mutex. Then refactor
        to a plain std::mutex using private *_locked() helpers that assume the lock is held. Explain
        why recursive_mutex is often considered a design smell.

  [ ] Q5.10   [Hard]   [NEW]
        Lock hierarchy. Implement HierarchicalMutex(level) that satisfies the Lockable requirements
        (lock/unlock/try_lock) so it works with std::lock_guard, uses a thread_local "current
        level", and throws std::logic_error when a thread tries to lock a mutex whose level is not
        lower than the one it already holds. Demonstrate with a correct order and a violating order.

  [ ] Q5.11   [Medium]   [NEW]
        Callback under lock. Build an EventBus with subscribe() and publish() that invokes
        subscriber callbacks while holding the internal mutex. Show a deadlock when a callback calls
        subscribe(). Fix it by copying the callback list under the lock and invoking the copies
        outside the lock; discuss the new semantics (a callback may run after unsubscribe).

  [ ] Q5.12   [Medium]   [NEW]
        const-correctness and escaping references. Write a class with mutable std::mutex and size()
        const that locks; explain why mutable is needed. Then add a method that returns a reference
        to the guarded vector and show how the caller can race on it. Fix it by returning a copy and
        by offering with_lock(F&&) that passes a reference only inside the critical section.

====================================================================================================
MODULE 6: Condition Variables and Thread Coordination   [C++11]
====================================================================================================

READ - topics & subtopics:
  * Synchronization Primitives: std::condition_variable vs. std::condition_variable_any.
  * Wait Mechanics: wait(), wait_for(), wait_until().
  * Predicate-Based Wait: avoiding bugs via cv.wait(lock, predicate).
  * Spurious and Lost Wakeups: why predicates are mandatory in concurrent design.
  * Notification APIs: notify_one() vs. notify_all().
  * Mutex & CV Interaction: the atomicity of unlocking the mutex and putting the thread to sleep.
  * Classic Patterns: producer-consumer pattern, bounded vs. unbounded synchronized queues.
  * Shutdown Coordination: notifying worker threads to stop processing via state predicates.
  * [NEW] Why wait() needs std::unique_lock (it must unlock and relock) and cannot take lock_guard;
    std::cv_status return of timed waits.
  * [NEW] The shared state in the predicate must be modified under the mutex even if it is an atomic
    (otherwise a notification can be lost between the check and the sleep).
  * [NEW] Notify while holding the mutex vs. after unlocking: correctness and performance; the
    thundering-herd effect of notify_all.
  * [NEW] condition_variable_any with custom lockables; std::notify_all_at_thread_exit.
  * [NEW] One condition variable per condition vs. many waiters on one; avoiding broadcast storms.
  * [NEW] Condition variables are not signal-safe and not a counter (use a semaphore when you need
    counting).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q6.1   [Medium]   (original Q7)
        Print the numbers 1..N alternately with two threads: one prints odd numbers, the other even,
        in strict order 1, 2, 3, ... N. Use one mutex + one condition_variable + a shared "turn"
        variable. No sleeps, no busy waiting.
        Must terminate cleanly for odd and even N. Test N = 1, 2, 3 and 1000.

  [ ] Q6.2   [Medium]   (original Q8)
        Print 1..N with 3 threads in strict round-robin (T1: 1, 4, 7 ...; T2: 2, 5, 8 ...; T3: 3, 6,
        9 ...). Then generalise to K threads (K from the command line) with a single condition
        variable and a turn index.
        Optional: use one condition variable per thread to avoid waking everybody, and compare the
        number of wakeups.

  [ ] Q6.3   [Medium]   (original Q9)
        Print "ABABAB..." with two threads (one prints 'A', the other 'B') for N pairs, strictly
        alternating. Implement it three ways: (a) mutex + condition_variable, (b) two
        std::binary_semaphore (C++20, after Module 15), (c) std::atomic<int> wait/notify (C++20,
        after Module 16). Compare the code size and the per-iteration time of the three.

  [ ] Q6.4   [Hard]   (original Q10)
        Bounded-buffer producer-consumer with capacity C, P producers and Q consumers. Each producer
        produces M integers; consumers consume until everything is done. Use one mutex and two
        condition variables (not_full, not_empty).
        Requirements: no lost and no duplicated items (verify with a checksum and a set), clean
        shutdown without deadlock (done counter or poison pill). Test C=1,P=Q=1; C=8,P=4,Q=2;
        C=8,P=2,Q=8.

  [ ] Q6.5   [Medium]   (original Q12)
        Lost wakeup and spurious wakeups. (a) Write buggy code where notify_one() is called BEFORE
        the waiter starts waiting and the waiter uses wait(lock) with no predicate: it hangs
        forever. (b) Fix it with wait(lock, pred). (c) Explain spurious wakeups and why the
        while(!pred) wait(lock) loop is required.
        (d) Show the subtle bug when a bool predicate is changed WITHOUT holding the mutex (even if
        atomic): describe the interleaving that loses the wakeup.

  [ ] Q6.6   [Hard]   (original Q16)
        Build a thread-safe BlockingQueue<T> with push(T), pop() (blocks), try_pop(T&),
        pop_for(timeout), size(), and close()/shutdown() that wakes all waiters. After shutdown, pop
        returns "empty" only once the queue is drained, and push fails. Support move-only T.
        Test with 4 producers + 4 consumers and a shutdown in the middle of the run. This queue is
        reused in Modules 14, 17 and 18.

  [ ] Q6.7   [Hard]   (original Q19)
        Implement from scratch with mutex + condition_variable: (a) a counting Semaphore (acquire,
        release, try_acquire); (b) a reusable Barrier(N). Use a generation counter so a fast thread
        cannot "lap" slow threads, and explain why a simple counter-only barrier is broken.
        Test: 4 threads x 1000 phases; assert that no thread enters phase k+1 before all finished
        phase k. You will redo this with the C++20 types in Module 15.

  [ ] Q6.8   [Medium]   [NEW]
        One-shot Event / start gate. Implement Event with set(), reset(), wait(), wait_for(). Use it
        as a "starting gun" so 8 threads begin a benchmark at exactly the same moment. You will need
        this helper in Module 7 and Module 12.

  [ ] Q6.9   [Medium]   [NEW]
        Thundering herd. Put 100 threads to sleep on one condition variable; wake them with
        notify_all while only one task is available and count how many wake up for nothing. Redesign
        with notify_one and with one condition variable per waiter group. Also compare notify under
        lock vs. after unlock and explain the result.

  [ ] Q6.10   [Medium]   [NEW]
        State machine with a condition variable: three threads implement a traffic light (RED ->
        GREEN -> YELLOW -> RED ...) where each thread only acts in its own state. Run N full cycles,
        then stop all threads gracefully without deadlock.

  [ ] Q6.11   [Medium]   [NEW]
        Debouncer: events arrive from many threads; a worker waits with wait_until(deadline) and
        extends the deadline whenever a new event arrives; when 200 ms pass without a new event it
        calls a callback exactly once. Test with bursts of events and verify the callback count.

====================================================================================================
MODULE 7: Thread-Local Storage and One-Time Initialization   [C++11, C++17, C++20]
====================================================================================================

READ - topics & subtopics:
  * Thread-Local Variables: thread_local specifier, per-thread state, initialization and cleanup
    timing.
  * Dynamic Local Initialization: thread-safe static local initialization (Meyers Singleton
    guarantee in C++11).
  * One-Time Call Guarantee: std::call_once() and std::once_flag.
  * Shutdown Ordering: static object destruction ordering pitfalls in multithreaded applications.
  * [NEW] thread_local with classes (constructor/destructor per thread), function-local vs.
    namespace-scope thread_local, static thread_local members, cost of TLS access (dynamic
    libraries).
  * [NEW] How "magic statics" work (compiler guard variable, __cxa_guard_acquire), recursive
    initialisation deadlock, -fno-threadsafe-statics.
  * [NEW] call_once with exceptions (the next caller retries), once_flag per object.
  * [NEW] Double-checked locking: why the naive version is a data race; the correct acquire/release
    version.
  * [NEW] inline variables (C++17) and constinit (C++20) to avoid dynamic-initialisation order
    problems; static initialisation order fiasco.
  * [NEW] errno and other per-thread state; per-thread random generators and per-thread
    caches/counters.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q7.1   [Hard]   (original Q13)
        Thread-safe singleton in three ways: (a) Meyers singleton (function-local static), (b)
        std::call_once + std::once_flag with a unique_ptr, (c) double-checked locking with
        std::atomic<T*> (acquire/release) plus a mutex on the slow path.
        For each: the constructor sleeps 100 ms and prints; start 16 threads at the same moment
        (Event from Q6.8) and verify the constructor ran exactly once. Also write the naive DCL
        (plain pointer) and explain in comments exactly why it is broken (reordering of
        allocate/construct/publish, data race = UB). Finally discuss destruction order at exit.

  [ ] Q7.2   [Medium]   (original Q24)
        Per-thread counters. Each of 8 threads increments a thread_local uint64_t 10 million times
        in a hot loop with no lock and no atomic. At thread exit, add its value to a global total
        (registry protected by a mutex, or a single atomic add).
        Compare time with (a) one shared atomic and (b) one shared mutex. Explain how to read a
        correct approximate total while threads are still running (registry of per-thread atomics
        read with relaxed loads).

  [ ] Q7.3   [Medium]   [NEW]
        Observe thread_local lifetimes: create a class that prints in its constructor/destructor and
        the owning thread id; use it as a thread_local variable (namespace scope and function
        scope). Spawn 3 threads and print when each object is constructed and destroyed, including
        the main thread at program exit. Show the hazard when a thread_local destructor uses a
        static object that has already been destroyed.

  [ ] Q7.4   [Medium]   [NEW]
        call_once with exceptions. The callable throws on the first call and succeeds on the second.
        Start 4 threads that all call std::call_once on the same flag and show which thread retries.
        Explain what once_flag guarantees about visibility of the initialised data.

  [ ] Q7.5   [Easy]   [NEW]
        Monte Carlo estimation of pi with 8 threads. First share one std::mt19937 between threads
        without protection (show wrong/crashing results under TSan), then give each thread its own
        thread_local std::mt19937 seeded differently (std::seed_seq with the thread id hash), and
        finally compare with mutex-protected sharing. Report times.

  [ ] Q7.6   [Medium]   [NEW]
        Static initialisation traps. (a) Create a function-local static whose initialiser calls the
        same function recursively and observe the behaviour. (b) Reproduce a
        static-initialisation-order fiasco across two translation units. (c) Fix (b) with a
        function-local static and with constinit (C++20) for a constant-initialised global. Explain
        the thread-safety guarantee of each approach.

====================================================================================================
MODULE 8: Promises, Futures and Asynchronous Tasks   [C++11]
====================================================================================================

READ - topics & subtopics:
  * Task-Based Abstractions: decoupling thread management from return values.
  * Core Components: std::promise<T> - input channel for setting values or exceptions.
  * Core Components: std::future<T> - output channel for consuming values or exceptions (get(),
    wait()).
  * Core Components: std::shared_future<T> - copyable future enabling multiple consumer threads.
  * Core Components: std::packaged_task<Signature> - wrapping callable targets for asynchronous
    execution.
  * Asynchronous Execution: std::async() launcher.
  * Launch Policies: std::launch::async vs. std::launch::deferred.
  * Futures Mechanics: std::future_status (ready, timeout, deferred).
  * Exception Propagation: rethrowing exceptions across thread boundaries via
    std::promise::set_exception().
  * Destructor Behavior: the blocking behavior of the implicit destructor of std::future returned
    from std::async.
  * [NEW] future::valid(), future::share(), wait_for/wait_until, one-shot get() (second get throws),
    future<void> and future<T&>.
  * [NEW] std::future_error and std::future_errc: promise_already_satisfied, broken_promise,
    future_already_retrieved, no_state.
  * [NEW] promise::set_value_at_thread_exit, packaged_task::make_ready_at_thread_exit,
    packaged_task::reset().
  * [NEW] std::exception_ptr, std::current_exception, std::make_exception_ptr,
    std::rethrow_exception.
  * [NEW] std::async default policy is implementation-defined (async|deferred); deferred tasks run
    lazily in the thread that calls get()/wait(); thread_local pitfalls with async.
  * [NEW] What the standard future lacks: continuations (.then), when_all / when_any, cancellation -
    and the usual workarounds.
  * [NEW] async vs. thread vs. thread pool: when each is appropriate.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q8.1   [Medium]   (original Q6)
        Return a value from a thread in four ways: (a) std::promise/std::future, (b)
        std::async(std::launch::async), (c) std::async(std::launch::deferred), (d) std::async with
        the default policy. Compute something non-trivial (e.g. the 40th Fibonacci number) and print
        the thread id where the callable actually ran in each case.
        Answer: when does std::async really run in parallel? Prove the deferred case with
        wait_for(0s) == future_status::deferred.

  [ ] Q8.2   [Medium]   (original Q23)
        Propagate an exception from a worker to the caller. Show: (a) raw std::thread ->
        std::terminate; (b) std::async -> future.get() rethrows in the caller; (c) std::promise with
        catch(...) { p.set_exception(std::current_exception()); }; (d) std::packaged_task.
        Then build a pool of 4 workers where the first exception wins: it is stored through an
        exception_ptr slot, an atomic<bool> tells the other workers to stop, and the caller rethrows
        after joining.

  [ ] Q8.3   [Easy]   [NEW]
        The future destructor trap. Run std::async(std::launch::async, slow_task) as a temporary
        (not stored) twice in a row and measure: the two calls run one after the other because the
        temporary future's destructor blocks. Prove it with timestamps, then fix it by keeping the
        futures in a vector so the tasks overlap.

  [ ] Q8.4   [Medium]   [NEW]
        shared_future. One producer sets a promise<int>; 5 consumer threads each hold a copy of the
        same shared_future and call get(). Show that calling future::get() twice throws future_error
        (no_state), and show broken_promise when the promise is destroyed without a value.

  [ ] Q8.5   [Medium]   [NEW]
        Asynchronous pipeline with packaged_task, promise and future (your original program #6):
        stage 1 parse, stage 2 transform, stage 3 aggregate; each stage runs in its own thread and
        the stages are chained through futures. Write a small then(future<T>, F) helper that returns
        future<R> and explain its limits (it blocks one thread; the std future has no real
        continuations).

  [ ] Q8.6   [Medium]   [NEW]
        Write when_all(vector<future<int>>) and when_any (poll with wait_for or use a shared state
        with a condition variable), then parallel_map(vector<T>, F, chunk_count) using std::async.
        Benchmark against the sequential map.

  [ ] Q8.7   [Easy]   [NEW]
        Use a promise<void> as a readiness signal: a worker initialises something, sets the promise,
        and keeps running; main waits on the future. Compare with a condition-variable version and
        note which is simpler and what each cannot do.

  [ ] Q8.8   [Medium]   [NEW]
        Reuse a packaged_task<int(int)>: move it into a thread, get its future, run it, then call
        reset() and run it again. Show the error you get from calling get_future() twice. Wrap the
        whole thing in a small TaskRunner class.

####################################################################################################
PART C - ATOMICS, MEMORY MODEL AND LOCK-FREE PROGRAMMING
####################################################################################################

====================================================================================================
MODULE 9: Atomics (std::atomic)   [C++11, C++17]
====================================================================================================

READ - topics & subtopics:
  * Atomicity Fundamentals: instruction-level atomicity, non-blocking operations.
  * Template Specializations: std::atomic<T>, std::atomic<bool>, integral/pointer specializations.
  * Basic Atomic APIs: load(), store(), exchange().
  * Read-Modify-Write (RMW): fetch_add(), fetch_sub(), fetch_and(), fetch_or(), fetch_xor().
  * Compare-And-Swap (CAS): compare_exchange_weak() vs. compare_exchange_strong().
  * Atomic Flag: std::atomic_flag guarantees lock-free execution across platforms (clear(),
    test_and_set(), test() in C++20).
  * Spinlocks: implementing lightweight spinlocks using std::atomic_flag or std::atomic<bool>.
  * Lock-Free Concepts: lock-free, wait-free, and obstruction-free progress guarantees;
    is_lock_free().
  * [NEW] std::atomic<T> for trivially copyable structs, std::atomic<T*> pointer arithmetic,
    operators (++, +=) and their implicit seq_cst ordering.
  * [NEW] is_always_lock_free (C++17), 16-byte atomics (cmpxchg16b, -mcx16, -latomic), atomics that
    silently use a hidden lock.
  * [NEW] CAS loop patterns: atomic max/min, bounded counters, why the "expected" value is updated
    on failure, separate success/failure memory orders.
  * [NEW] Why compare_exchange_weak may fail spuriously (LL/SC on ARM) and why it is preferred
    inside loops.
  * [NEW] volatile is NOT atomic; atomic<T> is neither copyable nor movable; std::atomic_init and
    ATOMIC_FLAG_INIT (deprecated in C++20); free functions std::atomic_load/store.
  * [NEW] Atomics and signal handlers (std::atomic_signal_fence, lock-free requirement,
    sig_atomic_t).
  * [NEW] Typical lock-free building blocks: ticket counters, flags, reference counts, sequence
    numbers, once-flags.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q9.1   [Medium]   (original Q25)
        Spinlock. Implement SpinLock with std::atomic_flag (test_and_set with acquire, clear with
        release) so that it works with std::lock_guard. Use it to protect a counter incremented 1M
        times by each of 4 threads. Then improve it: (a) test-and-test-and-set (spin on a plain read
        until the lock looks free before attempting test_and_set), (b) exponential backoff with a
        pause instruction (_mm_pause) or std::this_thread::yield().
        Compare against std::mutex for a very short and a long (100 microsecond) critical section
        with 1, 2, 4, 8 and 16 threads, including more threads than cores. Explain why spinlocks are
        dangerous with oversubscription. (The memory-order comparison continues in Q10.4.)

  [ ] Q9.2   [Easy]   [NEW]
        Atomic basics. Use load/store/exchange/fetch_add/fetch_or in a small demo. Implement a
        worker loop controlled by std::atomic<bool> stop. Then replace it by a plain bool, compile
        with -O2 and show that the loop can spin forever (the compiler hoists the read). Explain why
        volatile does not fix it.

  [ ] Q9.3   [Medium]   [NEW]
        CAS loops. Implement atomic_max(std::atomic<int>&, int) and
        atomic_multiply(std::atomic<int>&, int) with compare_exchange_weak loops and test them with
        8 threads. Explain why weak is preferred in loops and why the "expected" argument is updated
        when the CAS fails.

  [ ] Q9.4   [Medium]   [NEW]
        Count CAS retries. Implement a lock-free increment with a CAS loop and count how many
        retries happen with 1, 2, 4 and 8 contending threads. Compare time with a single fetch_add.
        On ARM/Apple Silicon (if you have it) also count spurious failures of compare_exchange_weak;
        on x86 explain why you see none.

  [ ] Q9.5   [Medium]   [NEW]
        Which atomics are really lock-free? Print is_lock_free() and is_always_lock_free for
        atomic<char>, <int>, <long long>, <void*>, <float>, struct{int,int}, struct{char[3]}, a
        16-byte struct and atomic<long double>. Build with and without -mcx16 and -latomic and
        explain every difference you see.

  [ ] Q9.6   [Medium]   [NEW]
        Atomic ticket distribution ("parallel for" without a lock): 8 threads claim work indices
        with idx.fetch_add(1) until idx >= N. Verify that every index 0..N-1 is processed exactly
        once (use a vector of atomic counters), then compare performance for tiny work items vs.
        chunked claiming (fetch_add(chunk)).

  [ ] Q9.7   [Easy]   [NEW]
        Written: classify each of these as wait-free, lock-free, obstruction-free or blocking, with
        a one-line justification: fetch_add counter; CAS-loop increment; spinlock-protected counter;
        mutex-protected counter; Treiber stack push; SPSC ring buffer push/pop.

  [ ] Q9.8   [Medium]   [NEW]
        Torn statistics. Maintain count and sum in two separate atomics and show with a reader
        thread that (count, sum) read together can be inconsistent. Fix it three ways: a mutex,
        packing both values into a single 64-bit atomic, and a std::atomic of a 16-byte struct
        (check is_lock_free).

====================================================================================================
MODULE 10: C++ Memory Model and Memory Ordering   [C++11, C++20 clarifications]
====================================================================================================

READ - topics & subtopics:
  * Undefined Behavior: data race definitions under standard specifications.
  * Relational Rules: sequenced-before, synchronizes-with, and happens-before relationships.
  * Modification Order: total modification order of atomic objects.
  * memory_order_relaxed: operations are atomic; no synchronization or ordering guarantees.
  * memory_order_consume: data dependency ordering (discouraged; compiler limitations).
  * memory_order_acquire: acquire semantics for read operations.
  * memory_order_release: release semantics for write operations.
  * memory_order_acq_rel: combined acquire-release for RMW operations.
  * memory_order_seq_cst: sequentially consistent ordering (default).
  * Acquire-Release Semantics: establishing happens-before relationships without full hardware
    memory barriers.
  * Fences: std::atomic_thread_fence(), std::atomic_signal_fence().
  * Object Publication: safely publishing objects concurrently without explicit mutex locks.
  * [NEW] Why reordering exists: compiler optimisations, store buffers, caches; x86-TSO (only
    store->load reorders) vs. ARM/POWER (almost everything reorders).
  * [NEW] Standard-library synchronisation points: thread construction/join, mutex unlock->lock,
    promise->future, call_once, latch/barrier/semaphore, atomic release->acquire.
  * [NEW] Release sequences (clarified in C++20), the single total order S of seq_cst operations,
    fence-to-fence and fence-to-atomic synchronisation.
  * [NEW] SC-for-DRF: data-race-free programs behave as sequentially consistent; there is no such
    thing as a "benign" data race.
  * [NEW] Litmus tests: message passing (MP), store buffering (SB), load buffering (LB), IRIW,
    coherence tests - and what each ordering allows.
  * [NEW] Legitimate uses of relaxed (counters, statistics, flags that publish no data); seqlocks;
    Dekker/Peterson need seq_cst.
  * [NEW] C++20: memory_order became a scoped enum (memory_order::acquire) with the old names kept
    as constants.
  * [NEW] Inspecting the generated assembly (Compiler Explorer) for x86-64 vs. AArch64: mov vs.
    ldar/stlr/dmb.
  * [NEW] Tools: ThreadSanitizer, CDSChecker, Relacy, cppmem / herd7 for checking small litmus
    tests.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q10.1   [Medium]   [NEW]
        Store-buffering litmus test. Thread 1: x = 1; r1 = y. Thread 2: y = 1; r2 = x (x and y are
        atomics starting at 0). Run 10 million iterations per mode (reset and synchronise start with
        a barrier or spin) for relaxed, release/acquire and seq_cst, and count how often r1 == 0 &&
        r2 == 0.
        Explain which modes allow that outcome and why it is visible even on x86.

  [ ] Q10.2   [Hard]   (original Q26)
        Message passing. Producer: data = 42 (plain int); ready.store(true, release). Consumer:
        while(!ready.load(acquire)); read data. Prove it always prints 42. Then change both
        operations to memory_order_relaxed and write a stress test; explain why the bug may be
        unobservable on x86 but is still undefined behaviour (compiler reordering) and show TSan
        reporting the race.
        Compare the generated assembly on x86-64 and AArch64 (ldar/stlr/dmb) with Compiler Explorer.

  [ ] Q10.3   [Hard]   (original Q30)
        Write your own shared_ptr<T> with an atomic reference count (control block, copy/move,
        reset, use_count, custom deleter optional). Decide the minimum safe memory orders: increment
        can be relaxed; the decrement must be release (or acq_rel) and the thread that drops the
        count to zero must acquire before deleting. Explain the happens-before argument in comments.
        Test with 8 threads each copying and dropping the same shared_ptr 1M times under TSan; then
        weaken the decrement to relaxed and explain what can go wrong.

  [ ] Q10.4   [Hard]   (original Q25)
        Memory orders for the spinlock of Q9.1. Run it with (a) seq_cst everywhere, (b) acquire on
        lock / release on unlock, (c) relaxed lock (incorrect) protecting a plain variable - show
        TSan reporting the data race. Benchmark (a) vs. (b) on x86 and, if available, on ARM;
        explain why the difference is small on x86 and larger on ARM.

  [ ] Q10.5   [Medium]   [NEW]
        Fences. Rewrite Q10.2 with relaxed atomic operations plus std::atomic_thread_fence(release)
        before the store and std::atomic_thread_fence(acquire) after the load. State the
        fence-atomic synchronisation rules and show a variant where the fence is placed on the wrong
        side of the atomic and no longer synchronises.

  [ ] Q10.6   [Hard]   [NEW]
        Seqlock. Implement a seqlock protecting a struct of two 64-bit fields: the single writer
        increments seq (odd = writing), writes, increments again; readers retry if seq is odd or
        changed. Explain why copying a plain struct in the reader is a data race in C++ even though
        it works on hardware, and make it legal with atomic fields (relaxed) plus fences. Stress
        test with 1 writer and 4 readers and check that readers never see a torn pair.

  [ ] Q10.7   [Hard]   [NEW]
        Peterson's algorithm for two threads. Implement it with seq_cst atomics and verify mutual
        exclusion with a stress test. Then weaken to acquire/release and show (with a counter or
        "inside critical section" flag) that mutual exclusion breaks, even on x86. Explain the
        store->load ordering that is missing.

  [ ] Q10.8   [Easy]   [NEW]
        Written: for each of these list the synchronizes-with edge and give a tiny example showing
        why data written before is visible after - thread constructor/join, mutex unlock->lock,
        promise::set_value -> future::get, call_once, latch count_down -> wait, counting_semaphore
        release -> acquire, atomic release store -> acquire load.

  [ ] Q10.9   [Medium]   [NEW]
        Predict, then verify. For the five litmus tests MP, SB, LB, IRIW and CoRR write which
        outcomes are allowed under relaxed, acquire/release and seq_cst. Verify at least three by
        stress test or with a tool (cppmem, herd7, CDSChecker, Relacy). Submit a 5x3 table.

====================================================================================================
MODULE 11: Common Pitfalls and Thread Safety of the Standard Library   [C++11 - C++20]
====================================================================================================

READ - topics & subtopics:
  * Taxonomy of Bugs: race conditions vs. data races, deadlocks, livelocks, starvation.
  * Performance Degradation: priority inversion, false sharing (cache-line ping-pong).
  * Cache Alignment: struct padding and alignas to mitigate false sharing.
  * Cache Line Hardware Hints (C++17): std::hardware_destructive_interference_size - avoiding false
    sharing.
  * Cache Line Hardware Hints (C++17): std::hardware_constructive_interference_size - maximizing
    cache locality.
  * Memory Pitfalls: double-checked locking pitfalls, dangling references to thread stacks,
    use-after-free bugs in shared objects.
  * Reentrancy: thread-safe vs. reentrant functions.
  * Exception Safety: exception-safe lock handling and safe state cleanup in concurrent modules.
  * [NEW] Standard-library guarantees: concurrent const access is safe; different objects are safe;
    modifying the same container needs synchronisation; iterator invalidation across threads.
  * [NEW] Memory locations: distinct array elements are separate locations; adjacent bit-fields and
    vector<bool> bits share one location (race).
  * [NEW] std::shared_ptr: control block is thread-safe, the pointee and the shared_ptr object
    itself are not; weak_ptr::lock; enable_shared_from_this with threads.
  * [NEW] I/O: std::cout is data-race-free per operation but output interleaves; std::osyncstream /
    <syncstream> (C++20); sync_with_stdio.
  * [NEW] Non-reentrant C functions (strtok, localtime, rand, strerror) and their _r replacements;
    async-signal-safe functions.
  * [NEW] Livelock and backoff, lock convoys, thundering herd, tail latency, allocator contention
    (glibc arenas, tcmalloc/jemalloc), NUMA effects.
  * [NEW] ABA problem (introduced here, solved in Module 12); heisenbugs and why concurrent bugs
    hide.
  * [NEW] Caveat: hardware_destructive_interference_size is implementation-defined and may warn
    (-Winterference-size) - many projects still hard-code 64 or 128.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q11.1   [Medium]   [NEW]
        False sharing alone. Create an array of 8 structs { uint64_t v; } (adjacent). Eight threads
        each increment their own slot 100 million times; time it. Then pad each slot with
        alignas(64) (and also try alignas(std::hardware_destructive_interference_size)). Report the
        speedup and confirm the effect with perf stat (cache-misses) or perf c2c.

  [ ] Q11.2   [Medium]   [NEW]
        Data race vs. race condition. (a) Write a real data race (non-atomic counter) and show
        TSan's report. (b) Write a race condition WITHOUT a data race: each operation of a
        thread-safe set is individually locked, but "if (!s.contains(x)) s.insert(x)" or "withdraw
        if balance >= amount" is not atomic as a whole, so updates are lost. Fix (b) by making the
        compound operation one critical section. Answer: can a data race exist without undefined
        behaviour? (No - by definition.)

  [ ] Q11.3   [Medium]   [NEW]
        Container misuse. (a) Two threads push_back into one std::vector without a lock: reproduce
        crash/corruption under TSan/ASan. (b) Show what IS safe: concurrent reads of a const vector,
        and threads writing distinct elements v[i]. (c) Show the vector<bool> race on adjacent
        elements and fix it with vector<char> or atomics.

  [ ] Q11.4   [Medium]   [NEW]
        shared_ptr thread safety. Part A: 8 threads copy the same shared_ptr<Data> into their own
        variables (safe). Part B: one thread assigns to a shared_ptr object that other threads read
        (race) - show it with TSan and fix it with a mutex, with std::atomic_load/atomic_store
        (C++11 free functions) and later with std::atomic<std::shared_ptr> (Module 16). Part C:
        observer lifetime with weak_ptr::lock().

  [ ] Q11.5   [Easy]   [NEW]
        Output interleaving. Print from 4 threads with std::cout << a << b << c and observe the
        mixing. Fix it with (a) a mutex, (b) formatting into an ostringstream and writing once, (c)
        std::osyncstream (C++20). Compare readability and cost.

  [ ] Q11.6   [Medium]   [NEW]
        Livelock. Make two "polite" threads that each try_lock their mutex, try_lock the other, and
        back off by unlocking if the second fails - with identical timing so they livelock. Fix with
        randomised exponential backoff. Also describe the difference between livelock and
        starvation.

  [ ] Q11.7   [Medium]   [NEW]
        Lock convoy. Run 16 threads that repeatedly take one mutex for a tiny critical section and
        call yield() inside it; measure throughput as the number of threads grows beyond the core
        count and show the collapse. Explain priority inversion with the Mars Pathfinder example in
        a few sentences.

  [ ] Q11.8   [Medium]   [NEW]
        Non-reentrant libc. Call strtok, localtime and rand from several threads and show corrupted
        results. Replace them with strtok_r, localtime_r and <random> / rand_r. Explain thread-safe
        vs. reentrant vs. async-signal-safe with one example each.

  [ ] Q11.9   [Medium]   [NEW]
        Exception safety under locks. Write a function that locks manually, calls code that can
        throw, and forgets to unlock - show the deadlock on the next call - then fix it with RAII.
        Also write an update operation with the strong exception guarantee using copy-and-swap under
        a lock.

====================================================================================================
MODULE 12: Lock-Free Data Structures and Memory Reclamation   [C++11 - C++20]
====================================================================================================

READ - topics & subtopics:
  * Memory Reclamation Issues: the ABA problem, tagged pointers, epoch-based reclamation, hazard
    pointers.
  * [NEW] Treiber stack (push/pop with CAS on the head pointer); Michael-Scott queue (dummy node,
    helping); Harris linked list (overview).
  * [NEW] SPSC ring buffer: power-of-two capacity, index masking, one writer per index,
    acquire/release, cached remote index, head/tail on separate cache lines.
  * [NEW] Bounded MPMC queue (Vyukov): per-cell sequence numbers, enqueue/dequeue positions.
  * [NEW] Tagged pointers and double-width CAS (cmpxchg16b) vs. packing a counter into unused
    pointer bits (portability: 48-bit addresses, ARM PAC/TBI).
  * [NEW] Reclamation schemes compared: hazard pointers, epoch-based reclamation,
    quiescent-state/RCU, reference counting, atomic<shared_ptr> (C++20); C++26 adds <hazard_pointer>
    and <rcu> (out of scope).
  * [NEW] Correctness: linearizability, how to test lock-free code (stress + checkers,
    Relacy/CDSChecker, TSan limitations with fences).
  * [NEW] Lock-free is not automatically faster: contention, cache misses, backoff, and when a mutex
    is the better engineering choice.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q12.1   [Hard]   (original Q27)
        Treiber stack. Part 1: lock-free push/pop with compare_exchange_weak on atomic<Node*> head
        (leak popped nodes for now). Part 2: reproduce the ABA problem with a deterministic 3-thread
        scenario (T1 reads head A and pauses; T2 pops A, pops B, pushes A back; T1's CAS succeeds
        and corrupts the stack). Part 3: fix with a tagged pointer (pointer + counter packed in 64
        bits or 128-bit CAS).
        Verify with 8 threads and 1M operations: every pushed value is popped exactly once (compare
        sums and counts).

  [ ] Q12.2   [Hard]   (original Q28)
        SPSC ring buffer. Fixed power-of-two capacity, try_push/try_pop with two atomic indices (the
        producer only writes tail, the consumer only writes head), acquire/release only, no locks.
        Verify FIFO order and a checksum over 100 million items.
        Then demonstrate false sharing by putting head and tail in the same cache line, fix it with
        alignas(64) padding, and add a cached copy of the other side's index. Report ops/second for
        the three variants.

  [ ] Q12.3   [Hard]   (original Q29)
        Bounded MPMC queue (Vyukov style): an array of cells each with an atomic sequence number,
        plus atomic enqueue and dequeue positions; implement try_enqueue/try_dequeue and explain the
        sequence protocol in comments.
        Test with 4 producers and 4 consumers moving 10M items: each item exactly once and
        per-producer FIFO. Compare throughput with the mutex BlockingQueue (Q6.6).

  [ ] Q12.4   [Hard]   (original Q33)
        Safe memory reclamation for the Treiber stack. Implement either (a) simple hazard pointers
        (per-thread hazard slots, retire list, scan when the list exceeds a threshold; pop publishes
        the hazard then re-validates the head) or (b) epoch-based reclamation (global epoch,
        per-thread epoch, three limbo lists).
        Test with 8 threads x 1M push/pop under AddressSanitizer (no use-after-free) and count that
        all retired nodes are eventually freed. Compare throughput with the leaking version and a
        mutex stack.

  [ ] Q12.5   [Hard]   [NEW]
        Michael-Scott queue: an unbounded lock-free MPMC queue with a dummy node, CAS on tail with
        helping, and CAS on head for dequeue; reclaim nodes with the hazard pointers from Q12.4.
        Check that every value is dequeued once and per-producer order is preserved.

  [ ] Q12.6   [Medium]   [NEW]
        Queue shoot-out. Benchmark (1) mutex + deque, (2) the BlockingQueue of Q6.6, (3) SPSC ring,
        (4) Vyukov MPMC, (5) Michael-Scott queue, with producer:consumer ratios 1:1, 4:4 and 8:1.
        Present a table and conclude when lock-free is NOT faster.

  [ ] Q12.7   [Medium]   [NEW]
        Tagged pointers. Implement struct TaggedPtr { Node* p; uintptr_t tag; } inside std::atomic
        and check is_lock_free() with and without -mcx16 / -latomic. Implement a second version that
        packs a 16-bit tag into the upper bits of a 48-bit pointer. Compare both and list
        portability risks.

  [ ] Q12.8   [Hard]   [NEW]
        (Stretch) Linearizability check. Write a tiny harness that records invocation/response
        timestamps of stack operations from 3 threads x 4 operations and brute-forces whether some
        sequential order explains every result. Run it on your Treiber stack and on a deliberately
        broken one.

####################################################################################################
PART D - C++17 AND C++20 LIBRARY FEATURES
####################################################################################################

====================================================================================================
MODULE 13: C++17 Parallel Algorithms   [C++17]
====================================================================================================

READ - topics & subtopics:
  * Standard Headers: <algorithm>, <numeric>, <execution>.
  * Execution Policies: std::execution::seq - sequential execution.
  * Execution Policies: std::execution::par - parallel execution across multiple software threads.
  * Execution Policies: std::execution::par_unseq - parallelized and vectorised (SIMD) execution.
  * Execution Policies: std::execution::unseq (C++20) - vectorised execution on the calling thread.
  * Algorithms Support: parallel versions of std::sort, std::for_each, std::transform, std::find,
    etc.
  * Parallel Reductions: std::reduce vs. std::accumulate, std::transform_reduce.
  * Correctness Constraints: avoiding data races inside element-access functions, requirements for
    associativity and commutativity.
  * [NEW] Toolchain: libstdc++ needs Intel TBB (-ltbb); MSVC has its own backend; libc++ support is
    partial. Implementation chooses the thread pool - you cannot control it.
  * [NEW] New C++17 algorithms: for_each_n, reduce, transform_reduce, inclusive_scan,
    exclusive_scan, transform_inclusive_scan, transform_exclusive_scan.
  * [NEW] Exceptions: if an element-access function throws from ANY policy overload (even seq),
    std::terminate is called; the overloads without a policy propagate exceptions normally.
  * [NEW] par_unseq rules: no locks, no allocation, no blocking inside the function (steps may
    interleave on one thread; vectorisation-unsafe).
  * [NEW] Iterator requirements (forward iterators or better), floating-point non-determinism of
    reduce, granularity (small inputs are slower in parallel), nested parallelism.
  * [NEW] C++20: ranges algorithms do not take execution policies; std::span for chunking data
    across threads.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q13.1   [Easy]   [NEW]
        Generate 50 million random doubles. Time std::sort and std::transform (e.g. sqrt) with seq,
        par and par_unseq. Present a speedup table and list the exact compile flags (-std=c++17
        -ltbb).

  [ ] Q13.2   [Medium]   [NEW]
        std::accumulate vs. std::reduce(seq) vs. std::reduce(par) on 100 million floats: print the
        three sums and explain the differences (floating-point addition is not associative). Repeat
        with integers (identical) and with Kahan summation. State the associativity/commutativity
        requirements of reduce.

  [ ] Q13.3   [Medium]   [NEW]
        Dot product with std::transform_reduce(par, ...). Implement the same with your hand-written
        N-thread version from Q2.4 and compare run time and code complexity.

  [ ] Q13.4   [Medium]   [NEW]
        Data race in a parallel algorithm: std::for_each(par, v.begin(), v.end(), [&](int x){ total
        += x; }). Show the race (TSan), fix it with an atomic (and note why it is slow) and then
        correctly with std::reduce. Explain why putting a std::mutex inside the lambda is forbidden
        with par_unseq.

  [ ] Q13.5   [Medium]   [NEW]
        Exceptions. Throw from the lambda of std::for_each without a policy (propagates) and with
        std::execution::par (and seq): observe std::terminate (run it in a child process or a death
        test). Implement a wrapper that captures the first exception in an exception_ptr and
        rethrows it after the algorithm returns.

  [ ] Q13.6   [Medium]   [NEW]
        Prefix sums. Compute a prefix sum with std::inclusive_scan(par, ...). Then implement a
        two-phase parallel prefix sum by hand (local scans per chunk, scan of chunk totals, add
        offsets) with N threads and verify it equals the sequential result.

  [ ] Q13.7   [Easy]   [NEW]
        Find the break-even size at which par beats seq for (a) a trivial operation and (b) an
        expensive operation (e.g. 200 multiplications per element). Plot or tabulate time vs. n and
        explain the thread start-up/scheduling overhead.

====================================================================================================
MODULE 14: C++20 std::jthread and Cooperative Cancellation   [C++20]
====================================================================================================

READ - topics & subtopics:
  * Improved Thread Wrapper: std::jthread features (auto-joining on destruction, request-stop
    integration).
  * Stop Token Infrastructure: std::stop_source - issuer of stop requests.
  * Stop Token Infrastructure: std::stop_token - observer checking for pending stop requests.
  * Stop Token Infrastructure: std::stop_callback - registering callbacks for cancellation events.
  * Cooperative Cancellation Patterns: polling stop_requested(), integrating std::stop_token into
    worker loops.
  * CV Stop Awareness: std::condition_variable_any::wait() taking a std::stop_token.
  * [NEW] jthread passes a stop_token as the first argument automatically when the callable accepts
    one; the destructor calls request_stop() and then join().
  * [NEW] get_stop_source(), get_stop_token(), request_stop(), stop_possible(), std::nostopstate;
    stop_source/token share state and are cheap to copy.
  * [NEW] stop_callback semantics: runs in the thread that calls request_stop() (or immediately in
    the constructor if a stop was already requested); keep callbacks short and non-blocking.
  * [NEW] Cancelling blocked operations: condition_variable_any with stop_token, stop_callback to
    wake a blocked read/poll, what jthread cannot interrupt (blocking syscalls).
  * [NEW] Hierarchical cancellation, why std::async/std::future have no cancellation, and library
    support status (check your standard library).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q14.1   [Easy]   [NEW]
        Redo Q2.3 with std::jthread. Show automatic join at scope exit. Add a worker that loops
        while(!st.stop_requested()), let main call request_stop() after 2 seconds, and print the
        order of events including the destructor.

  [ ] Q14.2   [Hard]   (original Q22)
        Cooperative cancellation. Create a pool of 4 std::jthread workers that take tasks from the
        BlockingQueue of Q6.6 and block using std::condition_variable_any::wait(lock, stop_token,
        pred). Main calls request_stop(); every worker must exit promptly even when idle inside the
        wait. Add a variant that uses timed waits (wait_for(lock, st, 100ms, pred)) to run a
        periodic heartbeat until stopped.
        Test: 1000 runs with random stop times - no hang, no lost join.

  [ ] Q14.3   [Medium]   [NEW]
        stop_callback. Register a std::stop_callback that closes the write end of a pipe so a thread
        blocked in read() wakes up when stop is requested. Print the thread ids to show where the
        callback ran, and show that a callback registered after the stop request runs immediately.

  [ ] Q14.4   [Medium]   [NEW]
        Hierarchical cancellation. A parent task starts 3 child jthreads, each with its own
        stop_source; a stop_callback on the parent's token forwards request_stop() to each child.
        Prove: stopping the parent stops all children; stopping one child does not affect the others
        or the parent.

  [ ] Q14.5   [Medium]   [NEW]
        Write async_cancellable(f): runs f(stop_token) on a jthread and returns a small struct with
        std::future<R> and a stop_source. Compare it with std::async, which cannot be cancelled, and
        handle the exception case.

====================================================================================================
MODULE 15: C++20 Primitives: Semaphores, Latches and Barriers   [C++20]
====================================================================================================

READ - topics & subtopics:
  * Semaphores: std::counting_semaphore<least_max_value> - resource counting, acquire(), release(),
    try_acquire().
  * Semaphores: std::binary_semaphore - alias for counting_semaphore with max value of 1.
  * Latches: std::latch - single-use countdown counter (count_down(), wait(), arrive_and_wait()).
  * Barriers: std::barrier<CompletionFunction> - reusable phase synchronization, completion
    callbacks, arrive_and_wait(), arrive_and_drop().
  * Primitive Selection: guidelines on choosing between mutexes, semaphores, latches, and barriers.
  * [NEW] counting_semaphore::max(), release(n), acquire_for/acquire_until/try_acquire_for;
    semaphores have no owner (they can signal across threads, unlike a mutex).
  * [NEW] latch::try_wait(), count_down(n); counting below zero is undefined behaviour; a latch
    cannot be reset.
  * [NEW] barrier::arrive() returns a token consumed by wait(token); the completion function runs
    once per phase and must be noexcept; arrive_and_drop shrinks the participant count for later
    phases.
  * [NEW] Typical uses: connection/rate limiting, start gates, phase-based simulations,
    producer/consumer signalling, thread pool shutdown.
  * [NEW] Build support: GCC 11+ (<semaphore>, <latch>, <barrier>); relation to pthread_barrier and
    futex-based implementations.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q15.1   [Medium]   [NEW]
        Rewrite the Semaphore and Barrier of Q6.7 using std::counting_semaphore and std::barrier.
        Run the same tests and compare the speed of your condition-variable version with the
        standard one.

  [ ] Q15.2   [Medium]   [NEW]
        Resource rate limiter (your original program #11). Allow at most 3 concurrent "database
        connections" across 10 threads using std::counting_semaphore<3>. Track in-flight use with an
        atomic counter, assert it never exceeds 3 and print the maximum observed. Add a
        try_acquire_for(50ms) path that prints "busy" on timeout.

  [ ] Q15.3   [Medium]   [NEW]
        Binary-semaphore ping-pong. Two threads alternate through two binary_semaphores 1 million
        times. Measure round-trip latency and compare it with the condition-variable version of
        Q6.3. Explain why a semaphore does not need an external mutex.

  [ ] Q15.4   [Medium]   [NEW]
        Latch start gate and completion. 8 workers wait on std::latch start(1) which main releases
        (so they begin together) and each calls done.count_down() on std::latch done(8) while main
        waits. Demonstrate that a latch cannot be reused and explain what happens if you count down
        too far.

  [ ] Q15.5   [Hard]   [NEW]
        Parallel Game of Life (or a Jacobi stencil) on a 1024x1024 grid with 8 threads, each owning
        a band of rows. Each generation writes into a back buffer; a std::barrier whose completion
        function swaps the buffers and counts generations separates generations. Run 1000
        generations and verify against the single-threaded result; then use arrive_and_drop to
        remove a thread from later phases.

  [ ] Q15.6   [Medium]   [NEW]
        Multi-phase synchronisation (your original program #10): 4 workers perform phases load ->
        compute -> write with a std::barrier between phases (completion function logs the phase
        number) and a std::latch that main waits on at the end. Add assertions proving no worker
        enters phase k+1 early.

  [ ] Q15.7   [Easy]   [NEW]
        Written decision table: choose between mutex, shared_mutex, condition_variable, semaphore,
        latch, barrier, atomic and future for 10 scenarios that you write yourself (e.g. "wait until
        8 workers have finished initialising", "limit to 3 concurrent uploads", "swap frame buffers
        each iteration"). Justify each choice in one sentence.

====================================================================================================
MODULE 16: C++20 Atomic Enhancements   [C++20]
====================================================================================================

READ - topics & subtopics:
  * Advanced Atomics (C++20): std::atomic_ref<T> - applying atomic operations on non-atomic
    variables.
  * Advanced Atomics (C++20): std::atomic<std::shared_ptr<T>> and std::atomic<std::weak_ptr<T>>.
  * Advanced Atomics (C++20): atomic wait/notify methods - std::atomic::wait(), notify_one(),
    notify_all().
  * [NEW] atomic_ref rules: required_alignment, the referenced object must not be accessed
    non-atomically while any atomic_ref exists, use with arrays, legacy structs and memory-mapped
    data, combined with std::span.
  * [NEW] atomic wait/notify: wait(old) blocks until the value differs from old; may return
    spuriously; implemented with futex on Linux; compare with condition variables and with spinning.
  * [NEW] atomic_flag::test(), wait(), notify_one()/notify_all() (C++20) and the C++20 atomic_flag
    default constructor (cleared); ATOMIC_FLAG_INIT deprecated.
  * [NEW] std::atomic<float/double> fetch_add/fetch_sub (C++20); atomic<T> default constructor now
    value-initialises.
  * [NEW] The free functions std::atomic_load/store for shared_ptr are deprecated in C++20 in favour
    of std::atomic<std::shared_ptr>; the C++20 version is often not lock-free.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q16.1   [Medium]   [NEW]
        Parallel histogram with std::atomic_ref. Keep a plain std::vector<int> hist(256); each
        thread updates it via std::atomic_ref<int>(hist[b]).fetch_add(1, relaxed). Compare with
        per-thread histograms merged at the end and with a vector<atomic<int>>. Print
        atomic_ref<int>::required_alignment.
        Interview angle: explain how atomic_ref enables atomic operations on arrays or C-style data
        structures and what rule you must not break while the atomic_ref exists.

  [ ] Q16.2   [Medium]   [NEW]
        atomic wait/notify. Implement the Event of Q6.8 and a one-shot "start flag" with
        std::atomic<int>::wait/notify_all (no mutex, no condition variable). Run 16 waiters and
        measure wake-up latency vs. the condition-variable Event; confirm with strace -f that futex
        calls are used. Rewrite the ABAB printer (Q6.3) with it.

  [ ] Q16.3   [Hard]   [NEW]
        Hot-swappable configuration with std::atomic<std::shared_ptr<const Config>> (GCC 12+). 8
        reader threads load and read the config in a loop while a writer publishes a new Config
        every 10 ms. Verify readers always see a consistent snapshot and that old configs are
        destroyed (count destructors). Compare with mutex + shared_ptr copy and print
        is_lock_free().

  [ ] Q16.4   [Medium]   [NEW]
        Sum doubles with 8 threads using (a) atomic<double>::fetch_add (C++20) and (b) a CAS loop
        (C++11). Compare time and show that the result varies slightly between runs (floating-point
        order). Explain why.

  [ ] Q16.5   [Medium]   [NEW]
        Parking lock. Turn the spinlock of Q9.1 into a lock that spins briefly and then blocks with
        flag.wait(true); unlock does clear() + notify_one(). Compare with the pure spinlock and with
        std::mutex when there are more threads than cores.

####################################################################################################
PART E - ARCHITECTURE AND DESIGN
####################################################################################################

====================================================================================================
MODULE 17: Thread Pool and Queue Architecture   [C++11 - C++20]
====================================================================================================

READ - topics & subtopics:
  * Thread Pool Architecture: task queues, worker loops, thread management.
  * Queue Implementations: single-producer single-consumer (SPSC), multi-producer multi-consumer
    (MPMC), bounded vs. unbounded queues.
  * Work Scheduling: work stealing algorithms, thread-local work queues.
  * Backpressure Management: preventing task queue exhaustion under high load.
  * Graceful Termination: draining task queues vs. immediate cancellation upon pool destruction.
  * Standardization Rationale: why C++ standard libraries currently lack a general-purpose thread
    pool executor.
  * [NEW] Task type erasure with move-only wrappers; submit() returning std::future via
    packaged_task; perfect forwarding; std::invoke_result_t for the return type.
  * [NEW] Choosing the number of threads (CPU-bound vs. I/O-bound; hardware_concurrency can be wrong
    inside containers).
  * [NEW] Pool pitfalls: tasks that block on other tasks of the same pool (pool starvation
    deadlock), exceptions inside tasks, long-running tasks, shutdown while tasks submit tasks.
  * [NEW] Priority queues, delayed/timer tasks, parallel_for with grain size, task granularity.
  * [NEW] Work stealing in detail: per-worker deques, LIFO for the owner and FIFO for thieves,
    Chase-Lev deque, random victim selection, idle-worker parking.
  * [NEW] Metrics: queue depth, wait time, utilisation; alternatives (Boost.Asio thread_pool, Intel
    TBB, OpenMP, std::execution in C++26).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q17.1   [Hard]   (original Q17)
        Build a fixed-size ThreadPool(n) with template<class F, class... Args> auto submit(F&&,
        Args&&...) -> std::future<std::invoke_result_t<F, Args...>>. Use std::packaged_task (stored
        in your move-only function wrapper from Q3.6) and perfect forwarding; workers loop over the
        BlockingQueue of Q6.6.
        The destructor must shut down gracefully (finish queued tasks, then join); add
        shutdown_now() that discards pending tasks. Exceptions must reach the caller through the
        future. Tests: 10,000 tiny tasks, tasks returning values / void / references, submit after
        shutdown (error), and destruction with pending tasks (no deadlock).

  [ ] Q17.2   [Medium]   [NEW]
        Pool starvation. In a pool of 2 threads, make each task submit a sub-task to the same pool
        and block on its future: show the deadlock. Fix it with (a) a helping wait (the waiting
        worker executes other queued tasks), (b) continuations instead of blocking, (c) a separate
        pool for sub-tasks.

  [ ] Q17.3   [Medium]   [NEW]
        Priorities and delays. Extend the pool with three priority levels (std::priority_queue with
        a sequence number to keep FIFO inside a level) and submit_after(delay, f) using one timer
        thread with a min-heap and condition_variable::wait_until.

  [ ] Q17.4   [Hard]   (original Q31)
        Work-stealing pool. Each worker owns a deque (mutex-protected first; optionally a lock-free
        Chase-Lev deque later). The owner pushes/pops at one end (LIFO); thieves steal from the
        other end (FIFO) of a random victim; external submissions go to a global queue; idle workers
        sleep and are woken when work appears.
        Show the benefit with a recursive workload (fib(35) or parallel quicksort) against the
        single-queue pool of Q17.1 and report speedup and steal counts.

  [ ] Q17.5   [Medium]   [NEW]
        Pool sizing experiment. Run (a) CPU-bound tasks and (b) tasks that sleep 10 ms (simulated
        I/O) on pools of 1, 2, 4, ..., 64 threads and plot throughput. Derive the rule of thumb for
        each kind of workload and compare with your core count.

  [ ] Q17.6   [Medium]   [NEW]
        Backpressure. Make the task queue bounded and implement three policies when it is full:
        block the submitter, reject (return false / throw), and caller-runs. Drive it with a fast
        producer and slow workers and show memory staying bounded.

  [ ] Q17.7   [Medium]   [NEW]
        parallel_for(pool, begin, end, grain, f) that splits a range into chunks, submits them and
        waits using a latch or futures. Benchmark chunk sizes and compare with std::for_each(par).

  [ ] Q17.8   [Hard]   [NEW]
        Pool instrumentation. Add metrics (tasks submitted/completed, queue depth, average queue
        wait time, per-worker utilisation) with minimal overhead (per-thread counters, relaxed
        atomics) and print a report. Use perf or lock-timing to find the hottest lock.

====================================================================================================
MODULE 18: Concurrent Design Patterns   [C++11 - C++20]
====================================================================================================

READ - topics & subtopics:
  * Producer-Consumer: lock-based vs. lock-free implementations.
  * Readers-Writers Pattern: shared vs. exclusive access strategies.
  * Pipeline Parallelism: multistage thread execution streams.
  * Fork-Join Parallelism: task decomposition and synthesis.
  * Double-Buffering: swapping execution buffers under locks for concurrent low-latency consumption.
  * Read-Copy-Update (RCU): concepts and applicability in concurrent read-heavy systems.
  * [NEW] Active Object (private thread + mailbox) and Monitor Object; Actor model and channels
    (Go-style); Thread confinement and immutable/copy-on-write data.
  * [NEW] Reactor / Proactor, Half-Sync/Half-Async, Leader/Followers, thread-per-request - how they
    relate to pools and coroutines.
  * [NEW] Scatter-gather and map-reduce on a single machine; fork-join with depth cutoff; shutdown
    patterns (poison pill, close(), stop_token).
  * [NEW] Data-structure patterns: lock striping/sharding, concurrent hash map design, thread-safe
    LRU cache, token-bucket rate limiting.
  * [NEW] Reader-writer fairness policies: reader preference, writer preference, fair
    (turnstile/ticket).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q18.1   [Hard]   (original Q20)
        Readers-Writers WITHOUT std::shared_mutex (use mutex + condition_variable). Version A:
        reader preference (writers can starve). Version B: writer preference (waiting writers block
        new readers; readers can starve). Version C: fair (ticket/turnstile) with no starvation.
        Workload: 10 readers and 2 writers with random durations.
        Assert that a writer never overlaps with a reader or another writer, record the maximum wait
        time per class, and show starvation in A and B but bounded waits in C.

  [ ] Q18.2   [Hard]   (original Q21)
        Parallel merge sort. Sort a vector<int> of 20 million elements; recursion splits in halves
        and spawns a new thread/async task only if size > cutoff (e.g. 100,000) and depth is below
        log2(cores); otherwise it sorts sequentially. Compare (a) sequential, (b) naive
        thread-per-recursion (show the thread explosion or cap it), (c) cutoff version, (d)
        pool-based version.
        Report speedup vs. cutoff size, and verify the output is sorted and a permutation of the
        input. Stretch: parallel merge step.

  [ ] Q18.3   [Hard]   (original Q32)
        Multi-stage pipeline: parse -> process -> write (e.g. read lines of a file, transform them,
        write the output). Each stage has its own thread(s) connected by bounded BlockingQueues so a
        slow stage applies backpressure. Requirements: clean shutdown (close() propagates
        downstream), exception in stage 2 cancels the whole pipeline, order preserved when stage 2
        has several workers (sequence numbers + reorder buffer), and per-stage throughput numbers to
        find the bottleneck.

  [ ] Q18.4   [Medium]   [NEW]
        Fork-join with std::async: parallel Fibonacci and parallel quicksort with a depth cutoff.
        Explain why a naive async-per-call fib(40) is far slower than the sequential version and how
        a cutoff fixes it.

  [ ] Q18.5   [Medium]   [NEW]
        Double buffering. A producer fills buffer A while a consumer reads buffer B; the buffers
        swap at a "frame boundary" (under a mutex or through an atomic pointer/index). Simulate 60
        frames per second for 10 seconds and verify the consumer never sees a half-written frame.

  [ ] Q18.6   [Hard]   [NEW]
        Active Object. A class owns one worker thread and a mailbox (queue of commands); public
        methods return futures and the object's state is touched only by its worker, so no data
        locks are needed (example: a Logger or BankAccount). Shut it down properly with
        std::jthread.

  [ ] Q18.7   [Medium]   [NEW]
        Concurrent hash map with lock striping: 16 shards, each a mutex + unordered_map;
        get/put/erase/get_or_compute. Benchmark against a single-mutex map and a
        shared_mutex-per-shard variant with 1..16 threads and discuss why resizing is the hard part.

  [ ] Q18.8   [Medium]   [NEW]
        Thread-safe token-bucket rate limiter (allow N operations per second, burst B) implemented
        with atomics or a mutex. Hammer it from 8 threads and verify the measured rate is within 5%
        of the target.

  [ ] Q18.9   [Medium]   [NEW]
        RCU-style copy-on-write: a read-mostly routing table published through
        std::atomic<std::shared_ptr<const Table>> (or the hazard/epoch scheme of Q12.4). Readers
        never block; the writer copies, modifies and publishes. Compare reader throughput with a
        shared_mutex implementation.

  [ ] Q18.10   [Medium]   [NEW]
        Go-style Channel<T>: buffered and unbuffered variants, send/receive, close(), range-for over
        a channel. Use it for a fan-out/fan-in pipeline with 4 workers; stretch: a select-like
        helper that waits on two channels.

  [ ] Q18.11   [Medium]   [NEW]
        Thread-safe LRU cache (an interview classic): unordered_map + doubly linked list guarded by
        one mutex; then a sharded version. Test with a skewed access pattern and report hit rate and
        throughput for 1..8 threads.

####################################################################################################
PART F - C++20 COROUTINES
####################################################################################################

====================================================================================================
MODULE 19: C++20 Coroutines and Concurrency Integration   [C++20]
====================================================================================================

READ - topics & subtopics:
  * Keywords: co_await, co_yield, co_return.
  * Infrastructure: promise types, std::coroutine_handle, awaitables, awaiters (await_ready,
    await_suspend, await_resume).
  * Execution Realities: coroutines as state machines vs. OS threads; suspension vs. thread
    blocking.
  * Asynchronous Integration: combining coroutines with event loops, task schedulers, and
    multi-threaded worker pools.
  * Thread Safety: managing shared state safety when a coroutine resumes on a different thread.
  * [NEW] Stackless coroutines: the coroutine frame (usually heap-allocated, sometimes elided),
    suspension points, destroy() and ownership of the frame.
  * [NEW] promise_type interface: get_return_object, initial_suspend, final_suspend (noexcept),
    return_value / return_void, yield_value, unhandled_exception; std::suspend_always /
    std::suspend_never; std::coroutine_traits.
  * [NEW] Symmetric transfer (await_suspend returning a coroutine_handle) to avoid unbounded stack
    growth; lazy vs. eager tasks; generators (std::generator is C++23).
  * [NEW] Lifetime hazards: reference parameters dangle after the first suspension (parameters are
    copied, references are not), lambda coroutines with captures, resuming a finished coroutine,
    resuming the same handle from two threads.
  * [NEW] Races inside await_suspend (scheduling the resume before the suspension is complete);
    thread-switching awaiters (resume_on a pool), timers, cancellation with stop_token.
  * [NEW] Practical libraries: cppcoro, libunifex, Boost.Asio awaitable, folly::coro; compiler flags
    (GCC 10 needs -fcoroutines).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q19.1   [Medium]   [NEW]
        Generator<T>. Implement a Generator with promise_type, co_yield, begin()/end() iteration and
        proper frame destruction. Write fibonacci() and range(a, b) generators and a take(n)
        adaptor. Run under AddressSanitizer to prove there is no leak.

  [ ] Q19.2   [Hard]   [NEW]
        Lazy Task<T>. Implement a Task<T> with co_return that other coroutines can co_await; the
        continuation is stored in the promise and resumed from final_suspend via symmetric transfer.
        Add sync_wait(task) using a std::binary_semaphore. Test a chain of 3 tasks and a
        100,000-deep chain to prove symmetric transfer avoids stack overflow.

  [ ] Q19.3   [Hard]   [NEW]
        Thread-switching awaiter. Implement co_await pool.schedule() so the coroutine suspends and
        resumes on a worker of your ThreadPool (Q17.1). Print thread ids before and after the
        co_await. Then implement co_await sleep_for(100ms) using the delayed tasks of Q17.3. Show a
        thread_local pitfall and a data race caused by the coroutine moving between threads, and fix
        both.

  [ ] Q19.4   [Medium]   [NEW]
        Coroutine lifetime bugs. (a) A coroutine taking const std::string& that suspends and resumes
        after the caller's temporary died (ASan) - fix by taking the parameter by value. (b) A
        lambda coroutine whose captures die before resume - fix it. (c) Forgetting destroy() leaks
        the frame. (d) Resuming a coroutine that is already done().

  [ ] Q19.5   [Hard]   [NEW]
        Single-thread event loop. Build a small timer queue / epoll loop where coroutines co_await
        timers or readiness. Run 10,000 concurrent "sleep 1 second then increment a counter"
        coroutines on ONE thread and compare memory and time with 10,000 std::threads.

  [ ] Q19.6   [Medium]   [NEW]
        Awaiter anatomy. Write three awaitables: always ready (await_ready returns true),
        suspend-and-resume-immediately, and one whose await_suspend returns bool. Print the order of
        await_ready/await_suspend/await_resume. Then write an awaiter that waits for a std::future
        without blocking the coroutine's thread (completion via a helper thread).

  [ ] Q19.7   [Easy]   [NEW]
        Written: explain the difference between a coroutine, a thread and std::async; why a
        coroutine alone does not give parallelism; and when you would pick each in a real system.

####################################################################################################
PART G - TOOLS AND PLATFORM
####################################################################################################

====================================================================================================
MODULE 20: Profiling, Sanitizers and Debugging   [C++11 - C++20]
====================================================================================================

READ - topics & subtopics:
  * Sanitizers: ThreadSanitizer (-fsanitize=thread), AddressSanitizer (-fsanitize=address).
  * Debugging Tools: using GDB / LLDB for thread inspection, detecting deadlocks with stack dumps.
  * Performance Analysis: measuring thread contention, Amdahl's Law, NUMA nodes, CPU affinity
    configuration basics.
  * [NEW] ThreadSanitizer in depth: reading reports (data race, lock-order inversion, thread leak,
    race on destroyed mutex), 5-15x slowdown, suppressions, false positives with fence-based
    synchronisation; TSan cannot be combined with ASan; UBSan.
  * [NEW] Valgrind Helgrind and DRD; gdb commands: info threads, thread apply all bt, set
    scheduler-locking, thread <n>; rr record/replay (rr record --chaos) for deterministic debugging
    of flaky bugs.
  * [NEW] Linux observability: perf stat / perf record -g / perf c2c / perf lock, strace -f, ltrace,
    ps -eLf, top -H, /proc/<pid>/task, flame graphs, bpftrace on pthread_mutex_lock.
  * [NEW] Benchmarking: Google Benchmark ->Threads(n), DoNotOptimize, warm-up, pinning, noise
    control; Universal Scalability Law (contention + coherency).
  * [NEW] Testing concurrent code: stress loops, random yield/sleep injection, running under
    taskset/stress-ng, deterministic schedulers, linearizability checks.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q20.1   [Hard]   (original Q34)
        Debugging round. Take (or write) three programs: (1) a data race (unsynchronised
        counter/flag or a shared std::map), (2) a lock-order inversion (A->B vs. B->A), (3) a missed
        notify (condition changed without the mutex). For each: reproduce the bug, detect it with
        ThreadSanitizer (-fsanitize=thread) AND with Helgrind (valgrind --tool=helgrind), save and
        explain the report, then fix and re-verify clean.
        Also catch the deadlock live in gdb with thread apply all bt.

  [ ] Q20.2   [Medium]   [NEW]
        TSan workflow. Build your Treiber stack (Q12.1) and spinlock (Q9.1) under TSan, interpret
        each warning, and classify one true positive and one false positive (e.g. synchronisation
        through fences that TSan does not model). Silence the false positive properly (restructure
        with atomics, a suppression file, or no_sanitize) and document why.

  [ ] Q20.3   [Medium]   [NEW]
        Contention analysis. Run an 8-thread mutex counter and an 8-thread atomic counter. Use perf
        stat (cache-misses, context-switches, cpu-migrations), perf record -g (flame graph) and perf
        c2c / perf lock to locate the contention point. Deliver a one-page report with numbers.

  [ ] Q20.4   [Medium]   [NEW]
        Google Benchmark with threads. Benchmark mutex, atomic and spinlock counters with
        ->Threads(1)->Threads(2)->Threads(4)->Threads(8); use benchmark::DoNotOptimize; plot
        throughput vs. threads and explain the scalability curves.

  [ ] Q20.5   [Medium]   [NEW]
        rr. Record an intermittently failing concurrency test with rr record --chaos until it fails,
        then replay it and use reverse-continue/watchpoints to find the first bad write.

  [ ] Q20.6   [Medium]   [NEW]
        Chaos harness. Write a chaos_point() macro that randomly yields or sleeps (enabled by an
        environment variable) and place it at synchronisation points of your queue. Insert one
        deliberate bug and run the test 10,000 times with and without injection; report how often
        the bug is caught.

  [ ] Q20.7   [Easy]   [NEW]
        Fit Amdahl's Law to the speedup data from Q2.4 to estimate the serial fraction, and explain
        the deviation of the measured curve (memory bandwidth, hyperthreads, overheads). Add the
        Universal Scalability Law coherency term if the curve bends downward.

====================================================================================================
MODULE 21: Linux and POSIX Interoperability   [Platform]
====================================================================================================

READ - topics & subtopics:
  * [NEW] pthread mapping: pthread_create/join/detach, mutex attributes (recursive, errorcheck,
    robust, priority-inheritance, process-shared), condition variables, barriers, rwlocks;
    std::thread::native_handle().
  * [NEW] futex(2): FUTEX_WAIT/FUTEX_WAKE, how std::mutex, condition_variable and atomic::wait are
    built on it, the three-state mutex (0 unlocked, 1 locked, 2 locked with waiters).
  * [NEW] Scheduling: SCHED_OTHER / SCHED_FIFO / SCHED_RR, nice, chrt, priority inversion and
    priority inheritance (PTHREAD_PRIO_INHERIT).
  * [NEW] CPU affinity (pthread_setaffinity_np, sched_setaffinity, taskset, cpusets), NUMA and
    first-touch placement (numactl), isolcpus, cache topology (lscpu).
  * [NEW] Signals and threads: pthread_sigmask, sigwait on a dedicated signal thread,
    async-signal-safe functions, why mutex/printf in a handler is unsafe.
  * [NEW] fork() in a multithreaded process (only the calling thread survives), pthread_atfork,
    posix_spawn; pthread_cancel hazards (avoid).
  * [NEW] Wake-up primitives for event loops: eventfd, timerfd, pipe, epoll; thread names
    (pthread_setname_np), ps -eLf, top -H.
  * [NEW] Containers and cgroups: hardware_concurrency vs. sched_getaffinity vs. cpu.max; sizing
    pools in Docker/Kubernetes.
  * [NEW] Shared memory between processes: process-shared and robust mutexes (EOWNERDEAD,
    pthread_mutex_consistent).

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q21.1   [Hard]   (original Q35)
        Futex mutex. Implement a mutex with raw syscall(SYS_futex, ...) on a std::atomic<int> using
        three states (0 unlocked, 1 locked, 2 locked with waiters, as in Drepper's "Futexes Are
        Tricky"): lock fast path by CAS in user space, slow path with FUTEX_WAIT, unlock wakes one
        waiter only if the state was 2.
        Test with 8 threads x 10M increments; compare with std::mutex and the spinlock; use strace
        -f -c to count futex calls and show they are rare under low contention.

  [ ] Q21.2   [Medium]   (original Q35)
        CPU pinning and cache effects. Pin threads with pthread_setaffinity_np (through
        native_handle) / sched_setaffinity. Ping-pong an atomic variable between two threads placed
        (a) on two hyperthreads of one core, (b) on different cores of one socket, (c) on different
        sockets if you have them; report round-trip nanoseconds. Repeat the false-sharing test of
        Q11.1 pinned and unpinned. Explain every number with the cache hierarchy.

  [ ] Q21.3   [Medium]   [NEW]
        pthread attributes. Create a thread with pthread_create and a 64 MB stack for deep
        recursion; give threads names with pthread_setname_np and check them in top -H. If you have
        CAP_SYS_NICE, run a SCHED_FIFO demonstration of priority inversion with a normal mutex and
        fix it with PTHREAD_PRIO_INHERIT.

  [ ] Q21.4   [Medium]   [NEW]
        Signals and threads. Block all signals before starting threads and create a dedicated
        sigwait thread that handles SIGINT/SIGTERM and triggers a graceful shutdown (stop_source,
        eventfd or condition variable) of your thread pool. Verify Ctrl-C shuts down cleanly and
        explain why using std::mutex or std::cout inside a signal handler is unsafe.

  [ ] Q21.5   [Medium]   [NEW]
        fork() and threads. Show that after fork() only the calling thread exists in the child, and
        reproduce a child deadlock when another thread held a mutex at the moment of fork. Fix it
        with pthread_atfork handlers and with fork+exec / posix_spawn.

  [ ] Q21.6   [Medium]   [NEW]
        eventfd + epoll. Worker threads finish tasks and write to an eventfd; one thread runs an
        epoll loop that wakes up and processes a completion queue. Compare latency and CPU use with
        a condition-variable design and explain why reactors use fds.

  [ ] Q21.7   [Hard]   [NEW]
        Robust process-shared mutex. Two processes share an mmap'd region containing a mutex with
        PTHREAD_PROCESS_SHARED and PTHREAD_MUTEX_ROBUST. Kill the process that owns the lock inside
        its critical section; the other process gets EOWNERDEAD, repairs the data and calls
        pthread_mutex_consistent.

  [ ] Q21.8   [Easy]   [NEW]
        Container awareness. Print hardware_concurrency(), sysconf(_SC_NPROCESSORS_ONLN), the size
        of sched_getaffinity and the cgroup cpu.max inside a CPU-limited Docker container. Explain
        the mismatch and write a function that returns the right number of worker threads.

  [ ] Q21.9   [Medium]   [NEW]
        NUMA (if you have a multi-socket or NUMA-emulated machine): measure memory-bound throughput
        with numactl --cpunodebind=0 --membind=0 vs. --membind=1 and explain first-touch page
        placement.

####################################################################################################
PART H - PUTTING IT ALL TOGETHER
####################################################################################################

====================================================================================================
MODULE 22: Capstone Programs to Build   [Projects]
====================================================================================================

READ - topics & subtopics:
  * 1. Basic: print thread IDs and execute lambdas taking value/reference arguments.
  * 2. Basic: thread-safe counter using std::mutex vs. std::atomic<uint64_t>.
  * 3. Intermediate: thread-safe Singleton utilizing std::call_once and static initialization.
  * 4. Intermediate: bounded thread-safe queue using std::mutex and std::condition_variable.
  * 5. Intermediate: reader-writer lock demonstration using std::shared_mutex and std::shared_lock.
  * 6. Intermediate: asynchronous pipeline using std::packaged_task, std::promise, and std::future.
  * 7. Advanced: production-grade thread pool with dynamic task submission, returning
    std::future<R>.
  * 8. Advanced: lock-free spinlock implemented via std::atomic_flag (test_and_set, clear).
  * 9. Advanced: lock-free stack or queue using compare_exchange_weak.
  * 10. Advanced: multi-phase thread worker sync using std::barrier and std::latch (C++20).
  * 11. Advanced: resource rate-limiter using std::counting_semaphore (C++20).
  * [NEW] 12. Parallel log analyser: read a large log file in chunks, parse in a thread pool,
    aggregate counts in a sharded concurrent map, print top-K; compare with std::execution::par and
    with a single thread.
  * [NEW] 13. Mini async runtime: a thread pool + timer queue + coroutine Task<T> (co_await sleep,
    co_await schedule) that runs 100,000 timers.
  * [NEW] 14. In-memory key-value store: sharded locks, readers-writers, RCU-style snapshot for
    read-mostly keys, TTL expiry thread using jthread/stop_token, and a benchmark.
  * [NEW] 15. Low-latency logger: per-thread SPSC ring buffers drained by one background jthread,
    with backpressure policy and a flush-on-signal path (Module 21).
  * [NEW] 16. Parallel image/matrix workload (blur, matrix multiply) implemented four ways: single
    thread, std::thread chunks, thread pool, std::execution::par - with a speedup report.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q22.1   [Hard]   [NEW]
        Choose any THREE capstones (at least one from 12-16). For each: write a one-page design note
        (threads, locks/atomics, shutdown, failure handling), implement it, run it under TSan and
        ASan, benchmark it with 1, 2, 4, 8 threads and record the results.

====================================================================================================
MODULE 23: Interview Theory Questions to Master   [Interviews]
====================================================================================================

READ - topics & subtopics:
  * Threads & Management - What occurs if a joinable std::thread is destroyed? How does std::jthread
    resolve this?
  * Threads & Management - Explain the difference between passing arguments to a thread function
    directly versus via std::ref.
  * Synchronization & Mutexes - Differentiate a data race from a race condition. Can a data race
    occur without undefined behavior?
  * Synchronization & Mutexes - What advantage does std::scoped_lock provide over using
    std::lock_guard with std::lock()?
  * Synchronization & Mutexes - Why must std::condition_variable::wait() be passed a
    std::unique_lock instead of a std::lock_guard?
  * Atomics & Memory Model - What is the difference between compare_exchange_weak() and
    compare_exchange_strong()? Why use weak inside loops?
  * Atomics & Memory Model - Explain acquire-release memory order semantics. How do they differ from
    sequential consistency?
  * Atomics & Memory Model - Define False Sharing. How does
    std::hardware_destructive_interference_size assist in avoiding it?
  * C++20 Features - How does cooperative cancellation operate via std::stop_token and std::jthread?
  * C++20 Features - What is the difference between a std::latch and a std::barrier?
  * C++20 Features - Explain how std::atomic_ref enables atomic operations on arrays or C-style data
    structures.
  * [NEW] Threads - join vs. detach; why does std::thread copy its arguments; what happens when the
    thread function throws; can you copy a thread; std::thread vs. std::async vs. a thread pool; why
    does the destructor of an async future block?
  * [NEW] Mutexes - why never call lock()/unlock() by hand; lock_guard vs. unique_lock vs.
    scoped_lock; the four conditions for deadlock and how to prevent each; recursive_mutex - when
    and why not; mutex vs. spinlock; shared_mutex pitfalls (writer starvation, recursion); is
    std::mutex fair?
  * [NEW] Condition variables - what is a spurious wakeup; why a predicate; what is a lost wakeup;
    notify while holding the lock or not; condition variable vs. semaphore vs. future for
    signalling.
  * [NEW] Atomics - what makes an operation atomic; is atomic<T> always lock-free; what is the ABA
    problem and three ways to fix it; volatile vs. atomic; when is relaxed correct; what does
    seq_cst cost; what are happens-before and synchronizes-with; why is naive double-checked locking
    broken; what is a data race.
  * [NEW] Library - which operations on shared_ptr are thread-safe; is std::cout thread-safe; which
    STL containers can be read concurrently; what are thread-safe statics.
  * [NEW] C++20 - jthread vs. thread; stop_callback; semaphore vs. mutex; latch vs. barrier; atomic
    wait/notify vs. condition_variable; coroutine vs. thread; what C++20 still lacks (executors,
    continuations).
  * [NEW] Design - design a thread pool; design a bounded blocking queue; how to shut down a
    pipeline cleanly; how to choose the number of threads; lock-free vs. lock-based trade-offs;
    Amdahl's Law; how to debug a deadlock in production; how to test concurrent code; how to avoid
    false sharing.
  * [NEW] Coding-round classics (practise writing each from memory in 15-20 minutes): odd/even
    printing, ABAB, round-robin with K threads, producer-consumer, singleton, thread pool, blocking
    queue, semaphore, barrier, dining philosophers, readers-writers, parallel sum, rate limiter,
    thread-safe LRU cache.

PRACTICE QUESTIONS - solve these after reading the topics above:

  [ ] Q23.1   [Medium]   [NEW]
        Write a written answer (4-8 sentences, plus a code snippet where useful) to EVERY question
        in the list above and in your own words. Record yourself explaining five of them aloud in
        under two minutes each. Mark any question where you hesitated and re-read the matching
        module.

  [ ] Q23.2   [Hard]   [NEW]
        Timed mock round: pick 4 of the coding-round classics at random and write each on a blank
        editor in 20 minutes with no compiler help, then compile, fix and run under TSan. Track
        which ones you could not finish and repeat them next week.

####################################################################################################
SECTION 24 - STUDY PLAN AND CROSS-REFERENCE
####################################################################################################

ORIGINAL QUESTION NUMBER -> NEW QUESTION ID
  Orig  1->Q2.1    2->Q2.2    3->Q5.1    4->Q5.2    5->Q2.3    6->Q8.1    7->Q6.1    8->Q6.2    9->Q6.3
  Orig 10->Q6.4   11->Q5.3   12->Q6.5   13->Q7.1   14->Q2.4   15->Q5.4   16->Q6.6   17->Q17.1  18->Q5.5
  Orig 19->Q6.7   20->Q18.1  21->Q18.2  22->Q14.2  23->Q8.2   24->Q7.2   25->Q9.1 + Q10.4   26->Q10.2
  Orig 27->Q12.1  28->Q12.2  29->Q12.3  30->Q10.3  31->Q17.4  32->Q18.3  33->Q12.4  34->Q20.1
  Orig 35->Q21.1 + Q21.2


MOST ASKED IN INTERVIEWS (from your original note: original Q7-9, 10, 13, 16, 17 and 19)
  Q6.1 odd/even, Q6.2 round-robin, Q6.3 ABAB, Q6.4 bounded buffer, Q7.1 singleton, Q6.6 blocking queue,
  Q17.1 thread pool, Q6.7 semaphore + barrier. Add: Q5.4 dining philosophers, Q18.1 readers-writers,
  Q18.11 thread-safe LRU cache, Q18.8 rate limiter.


YOUR ORIGINAL 7-DAY PLAN, MAPPED TO NEW IDS (fast track for the 35 original questions)
  Day 1      : Q2.1, Q2.2, Q5.1, Q5.2, Q2.3, Q8.1                     (original 1-6)
  Days 2-3   : Q6.1, Q6.2, Q6.3, Q6.4, Q5.3, Q6.5, Q7.1, Q2.4, Q5.4   (original 7-15)
  Days 4-5   : Q6.6, Q17.1, Q5.5, Q6.7, Q18.1, Q18.2, Q14.2, Q8.2, Q7.2 (original 16-24)
  Days 6-7   : Q9.1, Q10.2, Q12.1, Q12.2, Q12.3, Q10.3, Q17.4, Q18.3, Q12.4, Q20.1, Q21.1/Q21.2 (original 25-35)


FULL MODULE-BY-MODULE SCHEDULE (all 21 modules, about 9 weeks at 1-2 hours per day)
  Week 1 : Modules 1, 2, 3, 4          (foundations, std::thread, lambdas, chrono)
  Week 2 : Modules 5, 6                (mutexes, condition variables)  <- most interview value
  Week 3 : Modules 7, 8                (thread_local / once, futures / async)
  Week 4 : Modules 9, 10               (atomics, memory model)
  Week 5 : Modules 11, 12              (pitfalls and STL thread safety, lock-free structures)
  Week 6 : Modules 13, 14, 15, 16      (C++17 parallel algorithms, then C++20 jthread / sync / atomics)
  Week 7 : Modules 17, 18              (thread pools, design patterns)
  Week 8 : Modules 19, 20, 21          (coroutines, debugging tools, Linux/POSIX)
  Week 9 : Module 22 capstones + Module 23 interview round
  Daily rhythm: 30-40 min reading, 60-90 min coding the questions, 15 min writing what you learnt.


COVERAGE CHECKLIST - every C++11-C++20 concurrency feature and the module that covers it
  C++11  thread, this_thread, chrono ............ 2, 4          mutex family, lock_guard/unique_lock, lock ... 5
          condition_variable(_any) ................ 6            promise/future/packaged_task/async ........... 8
          atomic, atomic_flag, memory_order, fences ... 9, 10   thread_local, call_once, magic statics ....... 7
          exception_ptr, system_error, future_error ... 2, 8    notify_all_at_thread_exit, quick_exit ........ 2, 6
  C++14  shared_timed_mutex, shared_lock ........ 5            generic lambda, init-capture ................. 3
          chrono literals, make_unique, exchange ... 3, 4
  C++17  scoped_lock, shared_mutex .............. 5            parallel algorithms, new algorithms .......... 13
          interference-size constants, is_always_lock_free ... 9, 11     invoke/apply, [*this], CTAD, if-init ... 3, 5
          inline variables .......................... 7       pmr synchronized pools (overview) ............ 11
  C++20  jthread, stop_token/source/callback .... 14           semaphore, latch, barrier .................... 15
          atomic_ref, atomic<shared_ptr>, wait/notify ...... 16     atomic<float>, atomic_flag test/wait ........ 16
          osyncstream ............................ 11          coroutines ................................... 19
          template lambdas, bind_front, concepts ... 3         unseq policy, span ........................... 13
          constinit ............................... 7          memory-model clarifications .................. 10


WHAT CHANGED IN THIS REVISION
  * Re-ordered into 23 modules as a learning path (foundations -> sync -> atomics -> C++17/20 library ->
    architecture -> coroutines -> tools -> Linux -> capstones -> interview).
  * Every one of your 35 original questions was kept (with its original number) and expanded into a complete
    problem statement; they now sit right after the topic that teaches them.
  * Added new topics/sub-topics (marked [NEW]) for: chrono and timeouts, STL/shared_ptr/iostream thread
    safety, lock-free structures and reclamation, C++17 scan/for_each_n algorithms and exception rules,
    C++20 atomic_flag/atomic<float>/default-init/osyncstream/bind_front/template lambdas, coroutine
    internals, work stealing, pool pitfalls, patterns, debugging tools and Linux/POSIX interop.
  * Added new practice questions for all added material (164 practice questions in total: your 35 + 129 new).
  * Correction: std::shared_lock arrived in C++14 (with shared_timed_mutex), not C++17.
  * Correction/clarification: parallel algorithm overloads taking ANY execution policy call std::terminate if
    the user function throws; only the policy-less overloads propagate exceptions.
  * Moved the C++20 atomics (atomic_ref, atomic<shared_ptr>, wait/notify) out of the generic atomics module into
    their own module, and moved ABA / hazard pointers / epoch reclamation into the lock-free module.
  * Removed the stray markdown code fence at the end of the original file.
