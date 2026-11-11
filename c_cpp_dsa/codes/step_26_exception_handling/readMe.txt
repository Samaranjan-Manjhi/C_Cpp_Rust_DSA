================================================================================
        EXCEPTION HANDLING — COMPLETE REFERENCE + QUESTION BANK
        Topics: try/catch/throw, Standard Exceptions, Custom Exceptions,
                RAII, noexcept, Exception Safety, Stack Unwinding
        Compiled from all_in_one + all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        ★ = Extra question added (real company interview, not in source files)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
PART 1 — CONCEPT EXPLANATIONS
================================================================================

────────────────────────────────────────────────────────────────────────────────
1.1  BASIC MECHANISM — try / catch / throw
────────────────────────────────────────────────────────────────────────────────

  How it works:
    • throw  — raises an exception object of any type.
    • try    — marks the block of code that may throw.
    • catch  — handles a specific exception type (matched top to bottom).

  Syntax:
    try {
        if (x == 0) throw runtime_error("Division by zero");
        return 10 / x;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << "\n";
    }
    catch (const exception& e) {        // base class — catches most std exceptions
        cerr << "Exception: " << e.what() << "\n";
    }
    catch (...) {                       // catch-all — catches everything
        cerr << "Unknown exception\n";
    }

  Key Points:
    • Catch handlers are checked top-to-bottom — order matters.
    • Derived exception classes must be caught BEFORE base class handlers.
    • Catch by const reference (const T&) — avoids slicing and copying.
    • catch(...) should be a last resort; it swallows all exception info.
    • Re-throw with bare throw; inside a catch block:
        catch (const exception& e) { log(e.what()); throw; }

────────────────────────────────────────────────────────────────────────────────
1.2  STANDARD EXCEPTION HIERARCHY
────────────────────────────────────────────────────────────────────────────────

  std::exception  (base class, in <exception>)
  │
  ├── logic_error          — detectable before runtime
  │   ├── invalid_argument — bad argument passed
  │   ├── domain_error     — math domain violation
  │   ├── length_error     — exceeds maximum size
  │   └── out_of_range     — index/value out of valid range
  │
  ├── runtime_error        — detectable only at runtime
  │   ├── overflow_error   — arithmetic overflow
  │   ├── underflow_error  — arithmetic underflow
  │   └── range_error      — range violation
  │
  ├── bad_alloc            — new[] fails (out of memory)
  ├── bad_cast             — dynamic_cast on invalid type
  ├── bad_typeid           — typeid on null pointer
  └── bad_exception        — unexpected exception type

  Common headers:
    #include <stdexcept>    // runtime_error, logic_error, out_of_range, etc.
    #include <exception>    // std::exception base class
    #include <new>          // bad_alloc

────────────────────────────────────────────────────────────────────────────────
1.3  CUSTOM EXCEPTIONS
────────────────────────────────────────────────────────────────────────────────

  Basic custom exception:
    class DatabaseError : public exception {
        string message;
    public:
        explicit DatabaseError(const string& msg) : message(msg) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };

  Hierarchy of custom exceptions:
    class AppError : public runtime_error {
    public:
        explicit AppError(const string& msg) : runtime_error(msg) {}
    };

    class NetworkError : public AppError {
        int errorCode;
    public:
        NetworkError(const string& msg, int code)
            : AppError(msg), errorCode(code) {}
        int code() const { return errorCode; }
    };

  Key Points:
    • Always override what() with noexcept — standard interface.
    • Inherit from std::exception or its children (not from arbitrary classes).
    • Store message in string member if you need a dynamic message.
    • Multiple-level hierarchy lets you catch at the right granularity.

────────────────────────────────────────────────────────────────────────────────
1.4  STACK UNWINDING
────────────────────────────────────────────────────────────────────────────────

  What it is:
    When an exception is thrown and not caught in the current scope,
    C++ automatically destroys all local objects (calls destructors) as
    it walks back up the call stack looking for a matching catch.

  This is the guarantee that makes RAII work:
    void f() {
        ifstream file("data.txt");      // opened
        // ... code that might throw ...
        // Even if exception thrown here, file.~ifstream() IS called
    }                                   // file closed automatically

  Key Points:
    • Stack unwinding calls destructors of all local objects in reverse order.
    • If another exception is thrown DURING stack unwinding, std::terminate()
      is called — the program crashes. This is why destructors should be
      noexcept.

────────────────────────────────────────────────────────────────────────────────
1.5  RAII — Resource Acquisition Is Initialization
────────────────────────────────────────────────────────────────────────────────

  The pattern:
    • Acquire resource in constructor.
    • Release resource in destructor.
    • The destructor is ALWAYS called (even on exception), so the resource
      is ALWAYS released.

  Classic RAII wrapper example:
    class FileGuard {
        FILE* fp;
    public:
        explicit FileGuard(const char* name) : fp(fopen(name, "r")) {
            if (!fp) throw runtime_error("Cannot open file");
        }
        ~FileGuard() { if (fp) fclose(fp); }
        // Delete copy, allow move
        FileGuard(const FileGuard&) = delete;
        FileGuard& operator=(const FileGuard&) = delete;
        FILE* get() { return fp; }
    };

  RAII in STL:
    • unique_ptr / shared_ptr  — memory
    • lock_guard / unique_lock — mutexes
    • ifstream / ofstream      — file handles
    • vector / string          — heap buffers

  Key Points:
    • RAII is the CORE idiom of modern C++ resource management.
    • No need for try/finally (unlike Java/Python) — destructors do the job.
    • Combine RAII with exceptions: throw in constructor if acquisition fails.

────────────────────────────────────────────────────────────────────────────────
1.6  noexcept SPECIFIER
────────────────────────────────────────────────────────────────────────────────

  Syntax:
    void f() noexcept;               // promises not to throw
    void g() noexcept(true);         // same
    void h() noexcept(is_nothrow_move_constructible_v<T>); // conditional

  What happens if a noexcept function throws?
    std::terminate() is called immediately — no stack unwinding.

  Key Points:
    • Destructors are implicitly noexcept in C++11 — never throw from them.
    • Move constructors/operators should be noexcept — enables safe use
      in vector reallocation (without it, vector falls back to copy).
    • swap() should be noexcept — required for strong exception guarantee.
    • noexcept enables compiler optimizations (no landing pads needed).

────────────────────────────────────────────────────────────────────────────────
1.7  EXCEPTION SAFETY LEVELS
────────────────────────────────────────────────────────────────────────────────

  Level 0 — No Guarantee:
    If exception thrown, object may be in corrupted/undefined state.

  Level 1 — Basic Guarantee (minimum acceptable):
    If exception thrown, no resources are leaked, and the object is in
    a valid (though possibly changed) state.

  Level 2 — Strong Guarantee (commit-or-rollback):
    If exception thrown, the operation has NO effect — state unchanged.
    Achieved using copy-then-swap idiom.

  Level 3 — No-throw Guarantee:
    Operation never throws. Marked noexcept.

  Copy-and-Swap Idiom (achieves strong guarantee):
    String& operator=(String other) {   // "other" is a copy
        swap(*this, other);             // swap — noexcept
        return *this;
    }                                   // old data destroyed in "other"'s dtor

────────────────────────────────────────────────────────────────────────────────
1.8  EXCEPTION HANDLING PITFALLS
────────────────────────────────────────────────────────────────────────────────

  ✗ Throwing from a destructor:
      If a destructor throws during stack unwinding → std::terminate().
      Rule: Destructors MUST be noexcept.

  ✗ Catching by value (causes slicing):
      catch (exception e) { ... }    // BAD — copies and slices
      catch (const exception& e) { } // GOOD

  ✗ Using catch (...) without re-throw:
      catch (...) { /* silently swallowed */ }   // hides bugs

  ✗ Throwing raw pointers:
      throw new MyError();    // BAD — caller may not know to delete it

  ✓ Correct pattern:
      throw MyError("msg");   // throw by value, catch by const reference

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

────────────────────────────────────────────────────────────────────────────────
2A. CORE THEORY (from source files)
────────────────────────────────────────────────────────────────────────────────

  [T][ ] What is exception handling? What are the 3 keywords?
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What standard exceptions exist in C++? Name at least 5.
         Asked at: Amazon, TCS, Wipro, Adobe

  [T][ ] What is RAII? Give an example.
         (Constructor acquires, destructor releases — always, even on exception)
         Asked at: Persistent, L&T Infotech, Nagarro, Google

  [T][ ] What happens if you throw an exception inside a destructor?
         (If thrown during stack unwinding → std::terminate() called)
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is the Rule of Three? Rule of Five in C++11?
         (Rule of 3: destructor + copy ctor + copy assign.
          Rule of 5: adds move ctor + move assign. Rule of 0: use RAII members.)
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is the difference between logic_error and runtime_error?
         Asked at: Amazon, TCS, Adobe

  [T][ ] What is noexcept? What happens if a noexcept function throws?
         (std::terminate() is called — no stack unwinding)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is stack unwinding?
         (Destructors of local objects called in reverse as exception propagates)
         Asked at: Amazon, Google, Microsoft

  [T][ ] Why should destructors never throw exceptions?
         Asked at: Amazon, Microsoft, Google, Atlassian

  [T][ ] What are the exception safety levels (basic, strong, no-throw)?
         Asked at: Google, Goldman Sachs, advanced C++ roles

────────────────────────────────────────────────────────────────────────────────
2B. ADVANCED THEORY (★ extra questions)
────────────────────────────────────────────────────────────────────────────────

  ★[T][ ] What is the difference between throw and throw e inside a catch block?
           (bare throw re-throws original exception preserving type and stack;
            throw e creates a new exception of the static type of e — may slice)
           Asked at: Google, Atlassian, advanced C++ roles

  ★[T][ ] What is std::terminate()? What calls it? How can you set a custom handler?
           (Called on unhandled exception, noexcept violation, throw in destructor;
            set_terminate() installs custom handler)
           Asked at: Amazon, Google, advanced C++ roles

  ★[T][ ] What is the copy-and-swap idiom and how does it achieve strong exception safety?
           (Make a copy, swap with current object — swap is noexcept)
           Asked at: Google, Goldman Sachs, advanced C++ roles

  ★[T][ ] What is the difference between catching exception by value vs by reference?
           (By value: slices derived type, copies object.
            By const ref: no slicing, no copy, preserves dynamic type)
           Asked at: Amazon, TCS, Wipro, Adobe

  ★[T][ ] What is a function-try-block? When is it useful?
           (try/catch wrapping entire function body including initializer list —
            needed to catch exceptions from base class constructors)
           Asked at: Google, advanced C++ roles

  ★[T][ ] What is std::current_exception() and std::rethrow_exception()?
           (Capture exception as exception_ptr to rethrow in another thread)
           Asked at: Google, concurrent programming roles

  ★[T][ ] Can constructors throw? What happens to partially constructed objects?
           (Yes; if ctor throws, destructor is NOT called — any already-initialized
            members ARE destroyed via their own destructors)
           Asked at: Google, Microsoft, Adobe

  ★[T][ ] What is std::expected (C++23)? When would you prefer it over exceptions?
           (Return type that holds either a value or an error — zero-overhead,
            explicit error handling without try/catch, better for perf-critical paths)
           Asked at: Google, advanced C++ roles

  ★[T][ ] What is exception neutral code? Why is it important for generic libraries?
           (Code that doesn't catch exceptions — lets them propagate to the caller;
            generic containers must be exception neutral so user types can throw)
           Asked at: Google, Boost-level library authors, advanced C++ roles

  ★[T][ ] What is -fno-exceptions in GCC/Clang? What are the trade-offs?
           (Disables exception support entirely — smaller binary, no overhead;
            used in embedded systems and kernels; STL still usable but won't throw)
           Asked at: Embedded systems roles, Qualcomm, Samsung

================================================================================
PART 3 — CODING QUESTIONS
================================================================================

EASY
─────
  [C][ ] (E) Safe division function that throws on divide by zero
             Use: throw invalid_argument("Division by zero");
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Stack with out_of_range exception on empty pop/top
             throw out_of_range("Stack is empty");
             Asked at: Amazon, TCS, Google

  [C][ ] (E) File reading with exception handling
             throw runtime_error if file doesn't open
             Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Write a function that converts string to int and throws
              invalid_argument if the string is not a valid number
              Asked at: Amazon, TCS, Wipro

  ★[C][ ] (E) Write a safe array wrapper class that throws out_of_range
              on invalid index access (like std::vector::at())
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Demonstrate catching exceptions in order: derived before base;
              show what happens if order is reversed (dead catch handler warning)
              Asked at: TCS, Wipro, Amazon

MEDIUM
───────
  [C][ ] (M) Design a generic Stack class using templates with exception on pop/top when empty
             Asked at: Amazon, Google, Atlassian

  [C][ ] (M) Write a class where constructor throws if initialization fails
             (e.g., DatabaseConnection that throws if connection fails)
             and demonstrate the partially-constructed object behavior
             Asked at: Google, Microsoft, Adobe

  ★[C][ ] (M) Implement a custom exception hierarchy for a banking application:
              BankException → InsufficientFundsException, AccountFrozenException,
              InvalidAmountException. Demonstrate catching at different levels.
              Asked at: Amazon, Flipkart, Paytm, Zoho

  ★[C][ ] (M) Implement a RAII FileGuard class that opens a FILE* in constructor,
              closes in destructor, throws on failure, and cannot be copied
              Asked at: Google, Persistent, L&T Infotech

  ★[C][ ] (M) Implement the copy-and-swap idiom for a String class to achieve
              strong exception safety in operator=
              Asked at: Google, Goldman Sachs, advanced C++ roles

  ★[C][ ] (M) Write a transaction class where execute() either fully completes
              or rolls back all changes if any step throws (strong guarantee)
              Asked at: Amazon, Goldman Sachs, database roles

  ★[C][ ] (M) Demonstrate re-throw with bare "throw" inside catch; compare
              behavior to "throw e" (show slicing problem)
              Asked at: Google, Atlassian, advanced C++ roles

HARD
─────
  ★[C][ ] (H) Thread-safe exception propagation: throw an exception in a worker
              thread, capture it with std::current_exception(), and rethrow in
              the main thread using std::rethrow_exception()
              Asked at: Google, advanced C++ roles, concurrent programming

  ★[C][ ] (H) Implement a retry() wrapper function template that executes a
              callable up to N times, catching and logging exceptions between
              retries, re-throwing on final failure
              Asked at: Amazon, Flipkart, backend dev roles

  ★[C][ ] (H) Implement a scoped_resource RAII template that wraps any resource
              (any handle type) with a custom deleter — generalizing unique_ptr
              Asked at: Google, advanced C++ roles, HFT firms

================================================================================
QUICK REFERENCE CHEATSHEET
================================================================================

  // Basic structure
  try {
      throw runtime_error("msg");
  }
  catch (const runtime_error& e) { cerr << e.what(); }
  catch (const exception& e)     { cerr << e.what(); }
  catch (...)                    { cerr << "unknown"; }

  // Custom exception
  class MyError : public runtime_error {
  public:
      explicit MyError(const string& msg) : runtime_error(msg) {}
  };

  // noexcept
  void safe_func() noexcept;          // promises no throw
  ~MyClass() noexcept;               // implicit for destructors
  MyClass(MyClass&&) noexcept;       // move ctor should be noexcept

  // RAII pattern
  class Guard {
      Resource* r;
  public:
      Guard() : r(acquire()) { if (!r) throw runtime_error("fail"); }
      ~Guard() noexcept { release(r); }
      Guard(const Guard&) = delete;
      Guard& operator=(const Guard&) = delete;
  };

  // Re-throw original exception
  catch (const exception& e) {
      log(e.what());
      throw;          // re-throw, preserves original type
  }

  // Exception safety levels at a glance
  // No-throw:  noexcept — guaranteed never throws
  // Strong:    copy-and-swap — no effect on failure
  // Basic:     no leaks, valid state — minimum requirement

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Concept Explanations       | 8 sections fully documented
  Theory (from files)        | 10 |  0 |  0 |    10
  Theory (★ added)           | 10 |  0 |  0 |    10
  Coding Easy (from files)   |  3 |  0 |  0 |     3
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 |  2 |  0 |     2
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  0 |     0
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL Q&A                  | 29 |  7 |  3 |    39

================================================================================
END
================================================================================
