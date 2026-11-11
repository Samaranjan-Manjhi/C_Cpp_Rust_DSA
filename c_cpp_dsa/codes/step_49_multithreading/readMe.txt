Level 1: Basics (std::thread)
Launch a thread that prints a message, then join it.
Pass arguments to a thread by value, by reference (std::ref), and as a move-only type (unique_ptr). Explain why each works or fails.
Start N threads in a loop, each printing its ID. Notice the garbled output, then fix it with a mutex.
Increment a shared counter 1M times from 4 threads. Show the race, then fix it with mutex and with atomic, and compare timings.
Write what happens when a std::thread is destroyed without join or detach, then write an RAII wrapper (a mini jthread) that fixes it.
Return a value from a thread using std::promise/future, then again with std::async. When does std::async actually run in parallel?
Level 2: Synchronization
Print odd and even numbers alternately using two threads (mutex + condition_variable).
Print 1..N using 3 threads in round-robin (T1: 1, 4, 7; T2: 2, 5, 8; T3: 3, 6, 9).
Print “ABABAB...” with two threads, N times.
Implement a bounded-buffer producer-consumer with multiple producers and consumers.
Reproduce a deadlock with two mutexes, then fix it with lock ordering and with std::scoped_lock.
Demonstrate a lost wakeup (notify before wait), and explain why a predicate in wait fixes it along with spurious wakeups.
Write a thread-safe singleton three ways: Meyers, std::call_once, and double-checked locking with atomics. Explain why naive DCL is broken.
Compute the sum of a huge vector with N threads, then find the speedup curve vs. thread count.
Solve Dining Philosophers without deadlock or starvation.
Level 3: Intermediate Design
Build a thread-safe blocking queue with push, pop, try_pop, and graceful shutdown.
Build a fixed-size thread pool where submit(f, args...) returns a std::future (use packaged_task).
Implement a read-heavy cache using std::shared_mutex, and benchmark it against a plain mutex.
Implement a counting semaphore and a reusable barrier from scratch with mutex + condvar.
Solve Readers-Writers with writer preference, then with fairness (no starvation).
Write a parallel merge sort with a depth or size cutoff so you don’t spawn too many threads.
Implement cooperative cancellation with std::jthread and std::stop_token, including timed waits (wait_for).
Propagate an exception from a worker thread back to the caller (exception_ptr, future::get).
Use thread_local for per-thread counters, then aggregate them at the end without locks on the hot path.
Level 4: Advanced
Write a spinlock with atomic_flag, then improve it with test-and-test-and-set and backoff. Compare memory orders (seq_cst vs acquire/release).
Demonstrate message passing with release/acquire and show a case where relaxed breaks it.
Implement a lock-free stack (Treiber), reproduce the ABA problem, and fix it with a tagged pointer.
Implement a lock-free SPSC ring buffer. Then demonstrate false sharing and fix it with alignas(64) padding.
Implement a bounded MPMC queue (Vyukov-style).
Write your own shared_ptr with an atomic reference count. Which memory orders are the minimum safe ones for increment and decrement?
Build a work-stealing thread pool with per-thread deques.
Build a multi-stage pipeline (parse → process → write) with backpressure and clean shutdown.
Implement a simple hazard-pointer scheme or epoch-based reclamation for your lock-free stack.
Debugging round: take code with a data race, a lock-order inversion, and a missed notify. Find each using TSan and Helgrind, then fix them.
Linux-specific: reimplement a mutex using futex syscalls, pin threads to cores with pthread_setaffinity_np, and measure the cache effects.
Suggested Order
Day 1: Questions 1 to 6
Days 2 to 3: Questions 7 to 15
Days 4 to 5: Questions 16 to 24
Days 6 to 7: Questions 25 to 35

Questions 7 to 9, 10, 13, 16, 17, and 19 come up the most in interviews. Want me to write reference solutions for any of these, or turn the list into a day-by-day plan?







# Complete C++ Multithreading Roadmap: C++11 to C++20

This roadmap provides a complete, structured syllabus for mastering modern C++ multithreading, concurrency, and memory management for system programming and technical interviews.

---

## 1. Overview of C++ Concurrency Standards

| Standard | Key Concurrency Features Introduced / Refined |
| :--- | :--- |
| **C++11** | Core concurrency framework: `std::thread`, `std::mutex`, `std::condition_variable`, `std::promise`/`std::future`, `std::atomic`, `thread_local`, memory model. |
| **C++14** | Generic lambdas, generalized capture expressions (`std::move` in captures), relaxed `constexpr` rules. |
| **C++17** | Parallel algorithms, execution policies, `std::shared_mutex`, `std::shared_lock`, `std::scoped_lock`, `std::hardware_destructive_interference_size`. |
| **C++20** | `std::jthread`, cooperative cancellation (`std::stop_token`), semaphores (`std::counting_semaphore`), `std::latch`, `std::barrier`, `std::atomic_ref`, atomic wait/notify, coroutines. |

---

## 2. Complete Study Syllabus

### Module 1: Multithreading Fundamentals
* **Process vs. Thread:** Address space layout, context switching costs, kernel vs. user space threads.
* **Execution Paradigms:** Single-threading vs. multithreading, Concurrency vs. Parallelism.
* **Hardware Integration:** CPU cores, logical cores, hyperthreading, `std::thread::hardware_concurrency()`.
* **Thread Execution Lifecycle:** Creation, execution, blocking, ready state, termination.
* **Main Thread Roles:** Application initialization, static variable initialization, thread joining responsibilities.
* **Context Switching & Scheduling:** Quantum allocation, preemptive vs. cooperative scheduling, cache thrashing.
* **Data Scopes:** Shared data vs. stack memory vs. thread-local storage (`thread_local`).
* **Costs & Limitations:** Over-subscription, lock overhead, cache coherence traffic, non-deterministic execution.

### Module 2: C++11 Thread Management
* **Basic Threading:** `std::thread` header `<thread>`.
* **Callable Objects:** Function pointers, functors, and lambda expressions as entry points.
* **Argument Passing:** Passing parameters by value, by pointer, and by reference using `std::ref` / `std::cref`.
* **Thread Identification:** `std::thread::id`, `get_id()`, and `std::this_thread::get_id()`.
* **Lifetime Management:** `join()`, `detach()`, checking `joinable()`.
* **Detached Thread Risks:** Dangling references, accessing destroyed stack resources, process shutdown behaviors.
* **Move Semantics:** Thread ownership transfer via move constructors and move assignment.
* **Exception Handling:** Uncaught exceptions in worker threads, standard behavior of calling `std::terminate` on destruction of a joinable thread.
* **Thread Execution Helpers:** `std::this_thread::sleep_for()`, `sleep_until()`, `yield()`.
* **RAII Thread Management:** Custom wrappers for safe thread join/detach on scope termination.

### Module 3: Lambda Expressions and Callable Objects (C++11–C++14)
* **Capture Clauses:** Value captures (`[=]`), reference captures (`[&]`), mixed captures.
* **Object Lifetime:** Dangling reference pitfalls when passing captured scopes to worker threads.
* **Class Member Captures:** Capturing `this` by reference vs. `*this` by value (C++17).
* **Generalized Lambda Captures (C++14):** Moving move-only types (`std::unique_ptr`, `std::packaged_task`) into lambdas using `[ptr = std::move(ptr)]`.
* **Generic Lambdas (C++14):** Using `auto` parameter types in concurrent callback implementations.
* **Mutable Lambdas:** Modifying value-captured variables within concurrent worker lambdas.
* **Type Wrappers:** Using `std::function` vs. direct template instantiation for thread target callables.
* **Perfect Forwarding:** forwarding thread target arguments safely with `std::forward`.

### Module 4: Mutexes and Locking Mechanisms
* **Critical Sections:** Race conditions, data races, and mutual exclusion.
* **Basic Mutex:** `std::mutex`, manual `lock()` and `unlock()` risks.
* **RAII Lock Wrappers:**
  * `std::lock_guard` (C++11): Basic scope-bound locking.
  * `std::unique_lock` (C++11): Flexible locking, defer locking, timed locking, explicit unlock, moveability.
  * `std::scoped_lock` (C++17): Variadic RAII lock manager that safely locks multiple mutexes using deadlock-avoidance algorithms.
* **Lock Strategies/Flags:** `std::adopt_lock`, `std::defer_lock`, `std::try_to_lock`.
* **Deadlocks:** Causes, detection, prevention, and hierarchical locking order.
* **Deadlock Avoidance API:** `std::lock()` for multi-mutex acquiring without deadlock.
* **Specialized Mutexes:**
  * `std::recursive_mutex`: Re-entrant locking semantics and performance penalties.
  * `std::timed_mutex` & `std::recursive_timed_mutex`: `try_lock_for()`, `try_lock_until()`.
  * `std::shared_mutex` (C++17) & `std::shared_timed_mutex` (C++14): Reader-writer locks.
  * `std::shared_lock` (C++17): Shared acquisition wrapper for reader threads.

### Module 5: Condition Variables & Thread Coordination
* **Synchronization Primitives:** `std::condition_variable` vs. `std::condition_variable_any`.
* **Wait Mechanics:** `wait()`, `wait_for()`, `wait_until()`.
* **Predicate-Based Wait:** Avoiding bugs via `cv.wait(lock, predicate)`.
* **Spurious and Lost Wakeups:** Why predicates are mandatory in concurrent design.
* **Notification APIs:** `notify_one()` vs. `notify_all()`.
* **Mutex & CV Interaction:** The atomicity of unlocking the mutex and putting the thread to sleep.
* **Classic Patterns:** Producer-consumer pattern, bounded vs. unbounded synchronized queues.
* **Shutdown Coordination:** Notifying worker threads to stop processing via state predicates.

### Module 6: Promises, Futures, and Asynchronous Tasks
* **Task-Based Abstractions:** Decoupling thread management from return values.
* **Core Components:**
  * `std::promise<T>`: Input channel for setting values or exceptions.
  * `std::future<T>`: Output channel for consuming values or exceptions (`get()`, `wait()`).
  * `std::shared_future<T>`: Copyable future enabling multiple consumer threads.
  * `std::packaged_task<Signature>`: Wrapping callable targets for asynchronous execution.
* **Asynchronous Execution:** `std::async()` launcher.
* **Launch Policies:** `std::launch::async` vs. `std::launch::deferred`.
* **Futures Mechanics:** `std::future_status` (`ready`, `timeout`, `deferred`).
* **Exception Propagation:** Rethrowing exceptions across thread boundaries via `std::promise::set_exception()`.
* **Destructor Behavior:** The blocking behavior of the implicit destructor of `std::future` returned from `std::async`.

### Module 7: Atomics and Lock-Free Programming
* **Atomicity Fundamentals:** Instruction-level atomicity, non-blocking operations.
* **Template Specializations:** `std::atomic<T>`, `std::atomic<bool>`, integral/pointer specializations.
* **Basic Atomic APIs:** `load()`, `store()`, `exchange()`.
* **Read-Modify-Write (RMW):** `fetch_add()`, `fetch_sub()`, `fetch_and()`, `fetch_or()`, `fetch_xor()`.
* **Compare-And-Swap (CAS):** `compare_exchange_weak()` vs. `compare_exchange_strong()`.
* **Atomic Flag:** `std::atomic_flag` guarantees lock-free execution across platforms (`clear()`, `test_and_set()`, `test()` in C++20).
* **Spinlocks:** Implementing lightweight spinlocks using `std::atomic_flag` or `std::atomic<bool>`.
* **Lock-Free Concepts:** Lock-free, wait-free, and obstruction-free progress guarantees; `is_lock_free()`.
* **Advanced Atomics (C++20):**
  * `std::atomic_ref<T>`: Applying atomic operations on non-atomic variables.
  * `std::atomic<std::shared_ptr<T>>` and `std::atomic<std::weak_ptr<T>>`.
  * Atomic wait/notify methods: `std::atomic::wait()`, `notify_one()`, `notify_all()`.
* **Memory Reclamation Issues:** The ABA problem, tagged pointers, epoch-based reclamation, hazard pointers.

### Module 8: C++ Memory Model and Memory Ordering
* **Undefined Behavior:** Data race definitions under standard specifications.
* **Relational Rules:** *Sequenced-before*, *Synchronizes-with*, and *Happens-before* relationships.
* **Modification Order:** Total modification order of atomic objects.
* **Memory Order Enum Values (`std::memory_order`):**
  * `memory_order_relaxed`: Operations are atomic; no synchronization or ordering guarantees.
  * `memory_order_consume`: Data dependency ordering (discouraged; compiler limitations).
  * `memory_order_acquire`: Acquire semantics for read operations.
  * `memory_order_release`: Release semantics for write operations.
  * `memory_order_acq_rel`: Combined acquire-release for RMW operations.
  * `memory_order_seq_cst`: Sequentially consistent ordering (default).
* **Acquire-Release Semantics:** Establishing happens-before relationships without full hardware memory barriers.
* **Fences:** `std::atomic_thread_fence()`, `std::atomic_signal_fence()`.
* **Object Publication:** Safely publishing objects concurrently without explicit mutex locks.

### Module 9: Thread-Local Storage and One-Time Initialization
* **Thread-Local Variables:** `thread_local` specifier, per-thread state, initialization and cleanup timing.
* **Dynamic Local Initialization:** Thread-safe static local initialization (Meyers Singleton guarantee in C++11).
* **One-Time Call Guarantee:** `std::call_once()` and `std::once_flag`.
* **Shutdown Ordering:** Static object destruction ordering pitfalls in multithreaded applications.

### Module 10: Common Concurrency Pitfalls and Thread Safety
* **Taxonomy of Bugs:** Race conditions vs. Data races, Deadlocks, Livelocks, Starvation.
* **Performance Degradation:** Priority inversion, False sharing (cache-line ping-pong).
* **Cache Alignment:** Struct padding and `alignas` to mitigate false sharing.
* **Memory Pitfalls:** Double-checked locking pitfalls, Dangling references to thread stacks, Use-after-free bugs in shared objects.
* **Reentrancy:** Thread-safe vs. reentrant functions.
* **Exception Safety:** Exception-safe lock handling and safe state cleanup in concurrent modules.

### Module 11: C++17 Parallel Algorithms
* **Standard Headers:** `<algorithm>`, `<numeric>`, `<execution>`.
* **Execution Policies:**
  * `std::execution::seq`: Sequential execution.
  * `std::execution::par`: Parallel execution across multiple software threads.
  * `std::execution::par_unseq`: Parallelized and vectorised (SIMD) execution.
  * `std::execution::unseq` (C++20): Vectorised execution on the calling thread.
* **Algorithms Support:** Parallel versions of `std::sort`, `std::for_each`, `std::transform`, `std::find`, etc.
* **Parallel Reductions:** `std::reduce` vs. `std::accumulate`, `std::transform_reduce`.
* **Correctness Constraints:** Avoiding data races inside element-access functions, requirements for associativity and commutativity.

### Module 12: C++20 Thread Management and Cooperative Cancellation
* **Improved Thread Wrapper:** `std::jthread` features (auto-joining on destruction, request-stop integration).
* **Stop Token Infrastructure:**
  * `std::stop_source`: Issuer of stop requests.
  * `std::stop_token`: Observer checking for pending stop requests.
  * `std::stop_callback`: Registering callbacks for cancellation events.
* **Cooperative Cancellation Patterns:** Polling `stop_requested()`, integrating `std::stop_token` into worker loops.
* **CV Stop Awareness:** `std::condition_variable_any::wait()` taking a `std::stop_token`.

### Module 13: C++20 Primitives: Semaphores, Latches, and Barriers
* **Semaphores:**
  * `std::counting_semaphore<least_max_value>`: Resource counting, `acquire()`, `release()`, `try_acquire()`.
  * `std::binary_semaphore`: Alias for counting_semaphore with max value of 1.
* **Latches:**
  * `std::latch`: Single-use countdown counter (`count_down()`, `wait()`, `arrive_and_wait()`).
* **Barriers:**
  * `std::barrier<CompletionFunction>`: Reusable phase synchronization, completion callbacks, `arrive_and_wait()`, `arrive_and_drop()`.
* **Primitive Selection:** Guidelines on choosing between Mutexes, Semaphores, Latches, and Barriers.

### Module 14: C++20 Coroutines and Concurrency Integration
* **Keywords:** `co_await`, `co_yield`, `co_return`.
* **Infrastructure:** Promise types, `std::coroutine_handle`, Awaitables, Awaiters (`await_ready`, `await_suspend`, `await_resume`).
* **Execution Realities:** Coroutines as state machines vs. OS threads; suspension vs. thread blocking.
* **Asynchronous Integration:** Combining coroutines with event loops, task schedulers, and multi-threaded worker pools.
* **Thread Safety:** Managing shared state safety when a coroutine resumes on a different thread.

### Module 15: Architecture and Thread Pool Design
* **Thread Pool Architecture:** Task queues, worker loops, thread management.
* **Queue Implementations:** Single-producer single-consumer (SPSC), multi-producer multi-consumer (MPMC), bounded vs. unbounded queues.
* **Work Scheduling:** Work stealing algorithms, thread-local work queues.
* **Backpressure Management:** Preventing task queue exhaustion under high load.
* **Graceful Termination:** Draining task queues vs. immediate cancellation upon pool destruction.
* **Standardization Rationale:** Why C++ standard libraries currently lack a general-purpose thread pool executor.

### Module 16: Profiling, Sanitizers, and Debugging
* **Cache Line Hardware Hints (C++17):**
  * `std::hardware_destructive_interference_size`: Avoiding false sharing.
  * `std::hardware_constructive_interference_size`: Maximizing cache-locality.
* **Sanitizers:** ThreadSanitizer (`-fsanitize=thread`), AddressSanitizer (`-fsanitize=address`).
* **Debugging Tools:** Using GDB / LLDB for thread inspection, detecting deadlocks with stack dumps.
* **Performance Analysis:** Measuring thread contention, Amdahl's Law, NUMA nodes, CPU affinity configuration basics.

### Module 17: Concurrent Design Patterns
* **Producer-Consumer:** Lock-based vs. Lock-free implementations.
* **Readers-Writers Pattern:** Shared vs. Exclusive access strategies.
* **Pipeline Parallelism:** Multistage thread execution streams.
* **Fork-Join Parallelism:** Task decomposition and synthesis.
* **Double-Buffering:** Swapping execution buffers under locks for concurrent low-latency consumption.
* **Read-Copy-Update (RCU):** Concepts and applicability in concurrent read-heavy systems.

---

## 3. Recommended Hands-on Programs to Build

1. **Basic:** Print thread IDs and execute lambdas taking value/reference arguments.
2. **Basic:** Thread-safe counter using `std::mutex` vs. `std::atomic<uint64_t>`.
3. **Intermediate:** Thread-safe Singleton utilizing `std::call_once` and static initialization.
4. **Intermediate:** Bounded Thread-Safe Queue using `std::mutex` and `std::condition_variable`.
5. **Intermediate:** Reader-Writer Lock demonstration using `std::shared_mutex` and `std::shared_lock`.
6. **Intermediate:** Asynchronous pipeline using `std::packaged_task`, `std::promise`, and `std::future`.
7. **Advanced:** Production-grade Thread Pool with dynamic task submission, returning `std::future<R>`.
8. **Advanced:** Lock-Free Spinlock implemented via `std::atomic_flag` (`test_and_set`, `clear`).
9. **Advanced:** Lock-Free Stack or Queue using `compare_exchange_weak`.
10. **Advanced:** Multi-phase thread worker sync using `std::barrier` and `std::latch` (C++20).
11. **Advanced:** Resource rate-limiter using `std::counting_semaphore` (C++20).

---

## 4. Key Interview Questions to Master

* **Threads & Management:**
  * What occurs if a joinable `std::thread` is destroyed? How does `std::jthread` resolve this?
  * Explain the difference between passing arguments to a thread function directly versus via `std::ref`.
* **Synchronization & Mutexes:**
  * Differentiate a *data race* from a *race condition*. Can a data race occur without undefined behavior?
  * What advantage does `std::scoped_lock` provide over using `std::lock_guard` with `std::lock()`?
  * Why must `std::condition_variable::wait()` be passed a `std::unique_lock` instead of a `std::lock_guard`?
* **Atomics & Memory Model:**
  * What is the difference between `compare_exchange_weak()` and `compare_exchange_strong()`? Why use weak inside loops?
  * Explain acquire-release memory order semantics. How do they differ from sequential consistency?
  * Define *False Sharing*. How does `std::hardware_destructive_interference_size` assist in avoiding it?
* **C++20 Features:**
  * How does cooperative cancellation operate via `std::stop_token` and `std::jthread`?
  * What is the difference between a `std::latch` and a `std::barrier`?
  * Explain how `std::atomic_ref` enables atomic operations on arrays or C-style data structures.
```



