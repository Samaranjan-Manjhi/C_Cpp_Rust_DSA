================================================================================
        SMART POINTERS & MODERN C++ — COMPLETE REFERENCE + QUESTION BANK
        Topics: unique_ptr, shared_ptr, weak_ptr, move semantics, rvalue refs,
                perfect forwarding, auto, nullptr, lambda, structured bindings,
                constexpr, if-init, string_view, optional, variant, span
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
1.1  WHY SMART POINTERS?
────────────────────────────────────────────────────────────────────────────────

  Problems with raw pointers:
    int* p = new int(42);
    // What if exception thrown here? → memory leaked forever
    delete p;

    • Manual delete is error-prone — double-free, use-after-free, leaks.
    • Raw pointers don't express OWNERSHIP — who is responsible for deletion?
    • Smart pointers encode ownership and automate cleanup (RAII).

  The three smart pointers in <memory>:
  ┌──────────────┬──────────────────────────────────────────────────────────┐
  │ Type         │ Ownership Model                                          │
  ├──────────────┼──────────────────────────────────────────────────────────┤
  │ unique_ptr   │ Exclusive ownership — one owner, no copies               │
  │ shared_ptr   │ Shared ownership — reference counted, many owners        │
  │ weak_ptr     │ Non-owning observer — breaks cyclic references           │
  └──────────────┴──────────────────────────────────────────────────────────┘

────────────────────────────────────────────────────────────────────────────────
1.2  unique_ptr — EXCLUSIVE OWNERSHIP
────────────────────────────────────────────────────────────────────────────────

  Declaration and construction:
    unique_ptr<int> p = make_unique<int>(42);  // preferred (C++14)
    unique_ptr<int> p(new int(42));            // also works, but less safe

  Operations:
    *p              // dereference — gets the value
    p.get()         // raw pointer (borrow, do NOT delete it)
    p.reset()       // delete owned object, p becomes nullptr
    p.reset(new int(10))  // delete old, own new object
    p.release()     // give up ownership, returns raw ptr (YOU must delete)
    bool(p)         // true if non-null

  Arrays:
    unique_ptr<int[]> arr = make_unique<int[]>(10);  // calls delete[]
    arr[0] = 5;

  CANNOT copy — CAN move:
    auto p2 = p;               // ERROR — copy deleted
    auto p2 = move(p);         // OK — p is now nullptr, p2 owns the object

  Custom deleter:
    auto del = [](FILE* f){ fclose(f); };
    unique_ptr<FILE, decltype(del)> fp(fopen("f.txt","r"), del);

  When to use:
    • Default choice for dynamic memory.
    • Factory functions that return ownership.
    • Pimpl idiom (pointer to implementation).
    • Replacing raw new/delete everywhere.

────────────────────────────────────────────────────────────────────────────────
1.3  shared_ptr — SHARED OWNERSHIP
────────────────────────────────────────────────────────────────────────────────

  Declaration and construction:
    shared_ptr<int> p = make_shared<int>(42);  // preferred — single allocation
    shared_ptr<int> p(new int(42));            // two allocations (object + control block)

  Reference counting:
    shared_ptr<int> p1 = make_shared<int>(5);  // ref count = 1
    shared_ptr<int> p2 = p1;                   // ref count = 2 (copy)
    p1.reset();                                // ref count = 1
    p2.reset();                                // ref count = 0 → object deleted

  Operations:
    p.use_count()   // current reference count
    p.unique()      // true if use_count() == 1 (deprecated in C++20)
    *p              // dereference
    p.get()         // raw pointer
    p.reset()       // release this ownership

  Thread safety:
    • The reference count itself is atomically updated — thread-safe.
    • The pointed-to OBJECT is NOT automatically thread-safe.
    • Copying/destroying shared_ptr from multiple threads is safe.

  When to use:
    • Shared ownership of a resource (multiple objects need same data).
    • Shared data structures (shared graph nodes, caches).
    • When returning the same object to multiple callers.

  Cost vs unique_ptr:
    • Extra heap allocation for control block (unless make_shared).
    • Atomic reference count increment/decrement — has cost.
    • Prefer unique_ptr when ownership is not actually shared.

────────────────────────────────────────────────────────────────────────────────
1.4  weak_ptr — NON-OWNING OBSERVER
────────────────────────────────────────────────────────────────────────────────

  What it is:
    • Holds a non-owning "weak" reference to an object managed by shared_ptr.
    • Does NOT increment the reference count.
    • Used to OBSERVE without OWNING — breaks cyclic references.

  Usage:
    shared_ptr<int> sp = make_shared<int>(42);
    weak_ptr<int> wp = sp;            // does NOT increment count

    if (auto locked = wp.lock()) {    // lock() returns shared_ptr (or empty if dead)
        cout << *locked;              // safe — object alive during this scope
    }

    wp.expired()                      // true if object has been deleted

  Cyclic reference problem (why weak_ptr exists):
    struct Node {
        shared_ptr<Node> next;    // if two nodes point to each other:
        // ~Node() never called → memory leak
    };

    struct Node {
        weak_ptr<Node> next;      // breaks the cycle — node can be freed
    };

  When to use:
    • Observer/listener pattern (observer should not keep subject alive).
    • Parent-child relationships where parent owns children and children
      have a reference back to parent.
    • Caches (allow cache entries to be evicted even if weakly observed).

────────────────────────────────────────────────────────────────────────────────
1.5  MOVE SEMANTICS & RVALUE REFERENCES (C++11)
────────────────────────────────────────────────────────────────────────────────

  The problem before move semantics:
    vector<string> v;
    v.push_back(veryLargeString);   // COPIES the entire string — expensive

  lvalue vs rvalue:
    int x = 5;     // x is lvalue (has name, address)
    5;             // 5 is rvalue (temporary, no name)
    string s = string("hello");  // string("hello") is rvalue

  Rvalue reference (T&&):
    string&& r = string("hello");  // binds to rvalue
    void process(string&& s);      // accepts only rvalues

  Move constructor and move assignment:
    class Buffer {
        int* data; int size;
    public:
        // Move constructor — steal from other
        Buffer(Buffer&& other) noexcept
            : data(other.data), size(other.size) {
            other.data = nullptr;  // leave other in valid empty state
            other.size = 0;
        }
        // Move assignment
        Buffer& operator=(Buffer&& other) noexcept {
            if (this != &other) {
                delete[] data;
                data = other.data; size = other.size;
                other.data = nullptr; other.size = 0;
            }
            return *this;
        }
    };

  std::move():
    • Does NOT move anything — it's a CAST to rvalue reference.
    • Tells the compiler "treat this lvalue as if it were an rvalue."
    • After move, the moved-from object is in a valid but unspecified state.

    string a = "hello";
    string b = move(a);    // b takes a's buffer; a is now empty
    // a is valid but empty — can be assigned or destroyed safely

  When move semantics apply automatically:
    • Return local variable (RVO / NRVO may eliminate copy entirely).
    • Push temporary into container.
    • Returning named local (implicit move since C++11).

────────────────────────────────────────────────────────────────────────────────
1.6  PERFECT FORWARDING (C++11)
────────────────────────────────────────────────────────────────────────────────

  The problem:
    template <typename T>
    void wrapper(T arg) { target(arg); }   // always passes as lvalue
    // Loses rvalue-ness — can't use move semantics through wrapper

  Solution — forwarding reference + std::forward:
    template <typename T>
    void wrapper(T&& arg) {               // forwarding reference (NOT rvalue ref)
        target(forward<T>(arg));           // forward preserves value category
    }

  T&& is a forwarding reference when:
    • T is a deduced template parameter.
    • forward<T> reads T's deduced type to decide lvalue or rvalue.

  Rule:
    T&& where T is deduced type → forwarding reference (may bind lvalue or rvalue)
    string&& → plain rvalue reference (does NOT forward)

  Use case — emplace:
    template <typename... Args>
    void emplace_back(Args&&... args) {
        new (slot) T(forward<Args>(args)...);  // construct in place, no copy/move
    }

────────────────────────────────────────────────────────────────────────────────
1.7  KEY MODERN C++ FEATURES
────────────────────────────────────────────────────────────────────────────────

  auto — Type inference:
    auto x = 42;                  // int
    auto v = vector<int>{1,2,3};  // vector<int>
    auto it = m.find("key");      // map iterator
    // Pitfall: auto strips references and const — use auto& or const auto&

  nullptr — Replaces NULL and 0:
    int* p = nullptr;             // type-safe null pointer
    // NULL is just 0 — can match int overload; nullptr only matches pointer

  Range-based for loop:
    for (const auto& x : vec) { }   // read-only
    for (auto& x : vec) { x *= 2; } // modify in place

  Lambda expressions:
    auto add = [](int a, int b) -> int { return a + b; };
    auto addX = [x](int a) { return a + x; };      // capture by value
    auto addRef = [&x](int a) { return a + x; };   // capture by reference
    auto addAll = [=](int a) { return a + x + y; }; // capture all by value
    auto addAllRef = [&](...) { ... };              // capture all by reference

  Structured bindings (C++17):
    auto [first, second] = make_pair(1, "hi");
    auto [key, val] = *myMap.find("x");
    auto [x, y, z] = myTuple;

  constexpr — compile-time evaluation:
    constexpr int sq(int x) { return x * x; }
    constexpr int s = sq(5);          // evaluated at compile time

  if with initializer (C++17):
    if (auto it = m.find("key"); it != m.end()) { use(it->second); }
    // it's scope is limited to the if block — clean, no pollution

  std::string_view (C++17):
    // Non-owning view of a string — no heap allocation, no copy
    void print(string_view sv);        // accepts string, const char*, string_view
    string_view sv = "hello";          // points to literal — no copy
    // WARNING: string_view must NOT outlive the string it views

  std::optional (C++17):
    optional<int> find(vector<int>& v, int x) {
        for (int i = 0; i < v.size(); ++i)
            if (v[i] == x) return i;
        return nullopt;
    }
    if (auto idx = find(v, 5)) cout << *idx;

  std::variant (C++17):
    variant<int, string, double> v = 42;
    v = "hello";
    get<string>(v);                    // throws bad_variant_access if wrong type
    visit([](auto& x){ cout << x; }, v); // pattern matching style

  std::span (C++20):
    // Non-owning view over contiguous memory (array, vector, raw array)
    void process(span<int> data);      // works with any contiguous container

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

────────────────────────────────────────────────────────────────────────────────
2A. CORE THEORY (from source files)
────────────────────────────────────────────────────────────────────────────────

  [T][ ] What is a smart pointer? What types exist in C++?
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the difference between unique_ptr, shared_ptr, weak_ptr?
         Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [T][ ] What is a reference count? How does shared_ptr use it?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is a circular reference? How does weak_ptr solve it?
         Asked at: Amazon, Microsoft, Google, Atlassian

  [T][ ] What is RAII? Give an example with smart pointer.
         Asked at: Persistent, L&T Infotech, Google, Nagarro

  [T][ ] What is move semantics? What is an rvalue reference?
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the difference between std::move and std::forward?
         (move: unconditional cast to rvalue; forward: conditional — preserves
          value category depending on deduced type T)
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is a move constructor? When is it called automatically?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is perfect forwarding?
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is auto type deduction? What are its pitfalls?
         (Strips const and references; use auto& or const auto& to preserve)
         Asked at: Amazon, Microsoft, Adobe

  [T][ ] What is nullptr vs NULL vs 0?
         (nullptr is type-safe; NULL is #define 0; 0 can match int overloads)
         Asked at: TCS, Wipro, Amazon, Microsoft

  [T][ ] What is the range-based for loop? How does it work internally?
         (Calls begin() and end() on the container; works with any type that
          provides those; uses operator++ and operator!= on iterators)
         Asked at: TCS, Amazon, Microsoft

  [T][ ] What is std::function and std::bind?
         (std::function: type-erased callable wrapper; bind: partial application)
         Asked at: Amazon, Microsoft, Adobe, Google

  [T][ ] What is copy elision and RVO (Return Value Optimization)?
         (Compiler eliminates unnecessary copy/move of return values;
          guaranteed in C++17 for prvalues — NRVO is optional)
         Asked at: Google, Dolat Capital, advanced C++ roles

  [T][ ] What is the Rule of Zero in modern C++?
         (If you use RAII members like smart pointers, you don't need to write
          destructor, copy/move constructors, or assignment operators)
         Asked at: Google, Atlassian, advanced C++ roles

────────────────────────────────────────────────────────────────────────────────
2B. ADVANCED THEORY (★ extra questions)
────────────────────────────────────────────────────────────────────────────────

  ★[T][ ] Why is make_shared preferred over shared_ptr(new T)?
           (make_shared: single allocation for object + control block;
            shared_ptr(new T): two allocations — 2x overhead, worse cache locality)
           Asked at: Amazon, Google, Microsoft, Adobe

  ★[T][ ] Why should move constructors be marked noexcept?
           (vector reallocation uses move if noexcept, else falls back to copy;
            without noexcept on move ctor, push_back may copy instead of move)
           Asked at: Amazon, Google, advanced C++ roles

  ★[T][ ] What is the difference between shared_ptr and a raw pointer passed
           by reference to a function?
           (shared_ptr shares ownership — extends lifetime; raw pointer borrows
            — caller must ensure the object outlives the call)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] After std::move(x), what state is x in?
           (Valid but unspecified — can be destroyed or assigned to, but
            should NOT be read unless re-initialized)
           Asked at: Amazon, Google, Microsoft, Atlassian

  ★[T][ ] What is the difference between shared_ptr<T> and shared_ptr<const T>?
           (shared_ptr<const T>: can read *p but cannot modify it; useful when
            sharing read-only access to data)
           Asked at: Google, advanced C++ roles

  ★[T][ ] What is std::weak_ptr::lock()? What does it return?
           (Returns shared_ptr — non-empty if object still alive, empty if
            already destroyed; the only safe way to access from weak_ptr)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] Can you store a unique_ptr in a standard container like vector?
           (Yes — vector<unique_ptr<T>> works; push_back requires std::move
            since unique_ptr is move-only, not copyable)
           Asked at: Amazon, Google, Microsoft

  ★[T][ ] What is string_view? When should you NOT use it?
           (Non-owning view — never use it to store a temporary string;
            string_view must NOT outlive the string it was created from)
           Asked at: Google, Amazon, Microsoft, Adobe

  ★[T][ ] What is std::optional? How is it better than returning nullptr?
           (optional<T> avoids heap allocation and null pointer bugs;
            communicates "no value" via type system, not magic pointer values)
           Asked at: Google, Amazon, Microsoft, Atlassian

  ★[T][ ] What are small string optimization (SSO) and copy-on-write (COW)?
           (SSO: stores short strings in the string object itself — no heap alloc;
            COW: deprecated in C++11 — multiple strings share a buffer until modified)
           Asked at: Goldman Sachs, Google, advanced C++ roles

================================================================================
PART 3 — CODING QUESTIONS
================================================================================

EASY
─────
  [C][ ] (E) Implement a generic swap using templates (demonstrate move semantics)
             Asked at: Amazon, Zoho, TCS

  [C][ ] (E) Demonstrate move semantics: write a class that moves a heap buffer
             instead of copying; show it with a timing or step trace
             Asked at: Persistent, Nagarro, Google

  [C][ ] (E) Write a function that returns a local array. Why is it dangerous?
             Then fix it with unique_ptr<int[]>
             Asked at: TCS, Wipro, L&T Infotech

  [C][ ] (E) Rewrite a BankAccount class to use unique_ptr for internal data
             (Pimpl idiom)
             Asked at: Amazon, TCS, Persistent

  ★[C][ ] (E) Demonstrate unique_ptr non-copyable behavior: try to copy, see
              error; then show correct move semantics
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Show the difference between auto x = val, auto& x = val, and
              const auto& x = val with examples where each is appropriate
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Write a lambda that captures a counter by reference and increments
              it each time the lambda is called; pass it to std::for_each
              Asked at: Amazon, TCS, Adobe

  ★[C][ ] (E) Demonstrate nullptr vs NULL: write two overloads f(int) and f(int*)
              and show which is called with nullptr vs 0 vs NULL
              Asked at: TCS, Amazon, Microsoft

MEDIUM
───────
  [C][ ] (M) Implement a smart pointer like unique_ptr from scratch:
             operator*, operator->, destructor, no copy, move-only
             Asked at: Google, Atlassian, advanced C++ roles

  [C][ ] (M) Implement a reference-counted smart pointer like shared_ptr:
             copy constructor, copy assignment, destructor (with ref count)
             Asked at: Advanced C++ roles, Google

  [C][ ] (M) Demonstrate circular reference leak with shared_ptr; fix it with weak_ptr
             (Node class where two nodes point to each other)
             Asked at: Amazon, Microsoft, Google, Atlassian

  [C][ ] (M) Implement a memory pool custom allocator that pre-allocates a
             block and hands out memory from it
             Asked at: Dolat Capital, HFT firms, game dev roles

  [C][ ] (M) Shared linked list nodes using shared_ptr — implement the list
             and ensure no memory leak even if middle nodes are released
             Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Implement a generic factory function make_thing<T>(args...)
              that returns unique_ptr<T> using perfect forwarding
              Asked at: Google, Amazon, Atlassian

  ★[C][ ] (M) Implement an Observer pattern using weak_ptr for observers
              (Subject holds weak_ptr<Observer>; auto-cleanup when observers die)
              Asked at: Adobe, Google, game dev roles

  ★[C][ ] (M) Write a thread-safe shared_ptr use case: multiple threads read
              shared data via shared_ptr; one thread replaces the pointer
              using atomic_store (demonstrate safe use)
              Asked at: Google, Goldman Sachs, concurrent programming roles

  ★[C][ ] (M) Implement a function using std::optional to safely search a map:
              optional<string> find_name(map<int,string>& m, int id)
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Write a generic event dispatcher using std::function and a
              vector of callbacks; support subscribe, unsubscribe, dispatch
              Asked at: Adobe, Amazon, game dev roles

HARD
─────
  [C][ ] (M→H) Find and fix all bugs in code with: double-free, null deref,
               use-after-free, memory leak — multiple pointer errors
               Asked at: Samsung, Persistent, L&T Infotech

  ★[C][ ] (H) Implement an intrusive reference-counted base class (like COM's
              IUnknown) using CRTP — objects manage their own ref count
              Asked at: Google, Microsoft, game engines, advanced C++ roles

  ★[C][ ] (H) Implement a small_unique_ptr that stores the object inline (no
              heap allocation) if it fits in N bytes, heap otherwise (SBO pattern)
              Asked at: Goldman Sachs, Dolat Capital, HFT roles

  ★[C][ ] (H) Implement a generic scope_guard that executes a cleanup lambda
              on scope exit, even on exception; support dismiss() to cancel
              Asked at: Google, advanced C++ roles, Atlassian

================================================================================
QUICK REFERENCE CHEATSHEET
================================================================================

  #include <memory>

  // unique_ptr
  auto p = make_unique<int>(42);     // preferred
  *p;  p.get();  p.reset();  p.release();
  auto p2 = move(p);                 // transfer ownership

  // shared_ptr
  auto sp = make_shared<MyClass>(args);  // single allocation
  sp.use_count();  sp.reset();  sp.get();
  auto sp2 = sp;                     // ref count++

  // weak_ptr
  weak_ptr<MyClass> wp = sp;
  if (auto locked = wp.lock()) { use(*locked); }
  wp.expired();                      // true if object deleted

  // Move semantics
  string a = "hello";
  string b = move(a);                // b = "hello", a = ""

  // Perfect forwarding
  template <typename T>
  void wrap(T&& arg) { target(forward<T>(arg)); }

  // Lambda
  auto f = [x, &y](int a) -> int { return a + x + y; };

  // auto pitfalls
  auto x = v[0];      // copies (even if v[0] is int&)
  auto& x = v[0];     // reference — correct for modification
  const auto& x = v[0]; // const reference — correct for reading

  // optional
  optional<int> opt = 42;
  if (opt) cout << *opt;
  opt.value_or(0);           // default if empty

  // string_view
  void f(string_view sv);    // no copy, accepts any string type

  // if with initializer (C++17)
  if (auto it = m.find(k); it != m.end()) { use(it->second); }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Concept Explanations       | 7 sections fully documented
  Theory (from files)        | 15 |  0 |  0 |    15
  Theory (★ added)           | 10 |  0 |  0 |    10
  Coding Easy (from files)   |  4 |  0 |  0 |     4
  Coding Easy (★ added)      |  4 |  0 |  0 |     4
  Coding Medium (from files) |  0 |  5 |  0 |     5
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  1 |     1
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL Q&A                  | 33 | 10 |  4 |    47

================================================================================
END
================================================================================
