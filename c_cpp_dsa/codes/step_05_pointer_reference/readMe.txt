================================================================================
        POINTERS & REFERENCES — COMPLETE QUESTION BANK
        Compiled from all 5 files (roadmap + 4 question banks)
        No duplicates | Theory + Coding | All difficulties
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. POINTERS — CORE CONCEPTS
--------------------------------------------------------------------------------

  [T][ ] What is a pointer? What is a reference? What is the difference?
         Asked at: Most C++ developer roles, Amazon, Microsoft

  [T][ ] What is a null pointer? What is a dangling pointer?
         Asked at: Amazon, Microsoft, Adobe, L&T Infotech

  [T][ ] What is a wild pointer? How is it different from a dangling pointer?
         Asked at: L&T Infotech, Mphasis, Hexaware

  [T][ ] What is a memory leak? How do you detect and prevent it?
         What tools exist for Linux? (valgrind, ASan)
         Asked at: Most C++ developer roles, Amazon, Microsoft, Persistent

  [T][ ] What is the difference between stack memory and heap memory?
         Asked at: Most C++ developer roles, L&T Infotech, Persistent

  [T][ ] What does new and delete do? What happens if you forget to delete?
         Asked at: L&T Infotech, Persistent, Nagarro, Mphasis

  [T][ ] What is the difference between delete and delete[]?
         What happens if you use delete on a heap-allocated array?
         Asked at: L&T Infotech, Persistent, Wipro, C++ developer roles

  [T][ ] What is a void pointer? What are its limitations?
         Asked at: Amazon, Microsoft, C++ developer roles

  [T][ ] What is a double pointer (pointer to pointer)?
         Asked at: Persistent, Nagarro, L&T Infotech

  [T][ ] What is the difference between array name and pointer?
         Asked at: Amazon, Microsoft, L&T Infotech

  [T][ ] What is pointer arithmetic? Is it safe to go out of bounds?
         Asked at: Amazon, Samsung, L&T Infotech, Sasken

  [T][ ] Can you have a pointer to a function in C++? Show the syntax.
         int (*fp)(int, int);
         Asked at: L&T Infotech, Persistent, Sasken

  [T][ ] What is a fat pointer?
         Asked at: Advanced C++ / Rust developer interviews

  [T][ ] Can you have a reference to a reference in C++?
         What about pointer to reference?
         Asked at: Advanced C++ roles, Google

--------------------------------------------------------------------------------
1B. REFERENCES
--------------------------------------------------------------------------------

  [T][ ] What is a reference in C++? How is it different from a pointer?
         Key differences:
           - Reference cannot be null
           - Reference cannot be reassigned to another variable
           - No need to dereference (no * needed)
           - Must be initialized at declaration
         Asked at: Amazon, Microsoft, Zoho, TCS

  [T][ ] What is a const reference? When should you prefer it for function parameters?
         (void print(const string& s) — no copy made, cannot modify)
         Asked at: Amazon, Microsoft, Adobe, Persistent

  [T][ ] What is a dangling reference? How is it different from a dangling pointer?
         Asked at: L&T Infotech, Persistent

  [T][ ] What is the lifetime of a temporary object in C++?
         Can a const reference extend it?
         Asked at: Google, advanced C++ roles

  [T][ ] What is pass by value vs pass by reference?
         When should you use each?
         Asked at: TCS, Wipro, Infosys, Amazon, Microsoft

  [T][ ] Can a function return a reference? When is it safe / unsafe?
         (Unsafe to return reference to local variable — dangling reference)
         Asked at: Amazon, Microsoft, Persistent

--------------------------------------------------------------------------------
1C. SMART POINTERS & MODERN C++
--------------------------------------------------------------------------------

  [T][ ] What is a smart pointer? What types exist in C++?
         (unique_ptr, shared_ptr, weak_ptr)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the difference between unique_ptr, shared_ptr, and weak_ptr?
         Asked at: Amazon, Microsoft, Google, Adobe, Persistent

  [T][ ] What is a reference count? How does shared_ptr use it?
         Asked at: Amazon, Microsoft, Persistent, Nagarro

  [T][ ] What is a circular reference? How does weak_ptr solve it?
         Asked at: Amazon, Microsoft, Persistent

  [T][ ] What is RAII (Resource Acquisition Is Initialization)?
         Give an example. Why is it important?
         Asked at: Persistent, L&T Infotech, Nagarro, Google

  [T][ ] What does valgrind do? What does AddressSanitizer (ASan) do?
         Asked at: Persistent, Nagarro, Adobe

  [T][ ] What is a segmentation fault? What causes it?
         Asked at: L&T Infotech, Persistent, Wipro, TCS

  [T][ ] What is move semantics? What is an rvalue reference?
         Asked at: Persistent, Nagarro, Adobe, Dolat Capital

  [T][ ] What is std::move? Does it actually move anything?
         (It's just a cast to rvalue reference — actual move happens in move ctor)
         Asked at: Persistent, Nagarro, Adobe

  [T][ ] What is a move constructor? When is it called automatically?
         Asked at: Persistent, Nagarro, Adobe

  [T][ ] What is the Rule of Three? The Rule of Five in C++11?
         (destructor, copy ctor, copy=, move ctor, move=)
         Asked at: Persistent, Nagarro, Adobe, Google, Atlassian

  [T][ ] What is the Rule of Zero?
         (If you don't manage raw resources, don't write any of the five)
         Asked at: Advanced C++ roles, Dolat Capital

  [T][ ] What is copy elision and RVO (Return Value Optimization)?
         Asked at: Google, advanced C++ roles, Dolat Capital, Persistent

  [T][ ] What happens if you throw an exception inside a destructor?
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is the difference between shallow copy and deep copy?
         Specifically in context of copy constructor.
         Asked at: Zoho, TCS, Wipro, Persistent, L&T Infotech

--------------------------------------------------------------------------------
1D. MEMORY MODEL & DYNAMIC ALLOCATION
--------------------------------------------------------------------------------

  [T][ ] What are the different memory segments in a C++ program?
         (Text/Code, Data, BSS, Heap, Stack)
         Asked at: Sasken, L&T Infotech, Persistent, Nagarro

  [T][ ] What is stored in the stack vs heap?
         Asked at: Most C++ developer roles

  [T][ ] What is the BSS segment? What variables go there?
         (Uninitialized global and static variables)
         Asked at: Sasken, Samsung, Embedded roles

  [T][ ] What is the difference between malloc/free and new/delete?
         Asked at: L&T Infotech, Persistent, Nagarro, Mphasis

  [T][ ] What does malloc return if allocation fails? What does new do?
         (malloc returns NULL; new throws std::bad_alloc)
         Asked at: L&T Infotech, Persistent

  [T][ ] What is placement new? When would you use it?
         Asked at: Sasken, Google, advanced C++ roles

  [T][ ] What is a memory pool? Why is it used in trading/finance systems?
         Asked at: Dolat Capital, ICICI Securities, HFT firms

  [T][ ] What is the difference between stack overflow and heap overflow?
         Asked at: L&T Infotech, Persistent, Mphasis

  [T][ ] What is a core dump? How do you analyze it?
         Asked at: Sasken, L&T Infotech, Linux developer roles

  [T][ ] What is the difference between calloc and malloc?
         (calloc zero-initializes, malloc does not)
         Asked at: L&T Infotech, Mphasis, Hexaware

  [T][ ] What is realloc? What happens if the new block cannot be grown in place?
         Asked at: L&T Infotech, Persistent

  [T][ ] What is memory alignment? Why does the CPU care about it?
         Asked at: Sasken, Samsung, Qualcomm, Dolat Capital

  [T][ ] What is struct padding? Why does it happen? How to minimize it?
         Example: struct { char a; int b; char c; } — what is sizeof?
         Asked at: Samsung, Sasken, Qualcomm, Persistent

  [T][ ] What is the difference between delete and delete[] (deeper)?
         (delete[] calls destructor for each element; delete only calls once)
         Asked at: Amazon, Microsoft, C++ developer roles

--------------------------------------------------------------------------------
1E. ADDITIONAL POINTER THEORY
(Freshly asked — not in other sections)
--------------------------------------------------------------------------------

  [T][ ] What is the difference between const int* p, int* const p, and const int* const p?
         (pointer to const, const pointer, const pointer to const)
         Asked at: Amazon, Microsoft, Google, Samsung, Sasken

  [T][ ] What is an opaque pointer (PIMPL idiom)?
         Why is it used? What are its advantages?
         Asked at: Persistent, Nagarro, Adobe, advanced C++ roles

  [T][ ] What is a function pointer? What is a callback function?
         Give a real-world example.
         Asked at: L&T Infotech, Persistent, Sasken

  [T][ ] What is std::function? How is it different from a function pointer?
         Asked at: Persistent, Nagarro, Adobe

  [T][ ] What is a functor (function object)? Why use it over a function pointer?
         Asked at: L&T Infotech, Persistent, Sasken

  [T][ ] What is a lambda? How is it related to pointers and functors?
         Explain [=], [&], [x], [&x], [this] in the capture clause.
         Asked at: Persistent, Nagarro, Adobe, Amazon

  [T][ ] What is the overhead of a pointer dereference vs a direct access?
         Asked at: Dolat Capital, HFT firms, Samsung

  [T][ ] What is aliasing? What is the strict aliasing rule in C++?
         Asked at: Dolat Capital, Sasken, advanced C++ roles

  [T][ ] What is an iterator? Is an iterator a generalization of a pointer?
         Asked at: Amazon, Microsoft, Persistent, Nagarro

  [T][ ] What is object pooling? Why is it preferred over repeated new/delete
         in low-latency/high-frequency systems?
         Asked at: Dolat Capital, HFT firms, ICICI Securities

================================================================================
SECTION 2 — CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. EASY CODING
--------------------------------------------------------------------------------

  [C][ ] (E) Print the address of a variable and its value using pointer.
             Show: &x, *p, p itself — what each prints and why.
             Asked at: TCS, Wipro, L&T Infotech, Infosys

  [C][ ] (E) Write a function that doubles the value of an integer using a pointer.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Swap two numbers using pointers (pass as function arguments).
             Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [C][ ] (E) Swap two numbers using references.
             Show why this is cleaner than the pointer version.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Access elements of an array using pointer arithmetic only (no arr[i]).
             Asked at: TCS, L&T Infotech, Sasken

  [C][ ] (E) What is the output? int a = 5; int *p = &a; *p = 10; cout << a;
             Explain why.
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][ ] (E) Dynamically allocate an integer, assign value 42, print, then free it.
             Show correct use of new and delete.
             Asked at: TCS, Wipro, L&T Infotech

  [C][ ] (E) Dynamically allocate an array of size N, fill with values, print, then delete.
             Use new[] and delete[].
             Asked at: TCS, Wipro, L&T Infotech, Persistent

  [C][ ] (E) Pass a large struct to a function using const reference.
             Demonstrate that no copy is made (use print address trick).
             Asked at: TCS, Wipro, Amazon, Persistent

  [C][ ] (E) Write a class with explicit copy constructor that does deep copy.
             (String class example with char* data member)
             Asked at: Zoho, Persistent, Adobe

  [C][ ] (E) Demonstrate move semantics: write a class that moves resources
             instead of copying them. Compare performance with copy.
             Asked at: Persistent, Nagarro, Google

  [C][ ] (E) Write a function that returns a local array. Explain why this is dangerous.
             Then fix it properly (use vector or unique_ptr).
             Asked at: TCS, Wipro, L&T Infotech

  [C][ ] (E) Implement a function that deep-copies a 2D array that was dynamically allocated.
             Signature: int** deepCopy(int** src, int rows, int cols);
             Asked at: L&T Infotech, Persistent

  [C][ ] (E) Implement a generic swap using templates without using std::swap.
             Asked at: Amazon, Zoho, Persistent

  [C][ ] (E) Return reference from function (show safe vs unsafe versions).
             (Returning ref to static is safe; to local is dangling)
             Asked at: Amazon, Persistent, Nagarro

--------------------------------------------------------------------------------
2B. MEDIUM CODING
--------------------------------------------------------------------------------

  [C][ ] (M) Implement a function that takes a double pointer and modifies the original
             pointer to point to a new dynamically allocated integer.
             Asked at: Persistent, Nagarro, L&T Infotech

  [C][ ] (M) Write a generic swap function using void pointers (C-style).
             Signature: void swap(void* a, void* b, size_t size);
             Asked at: Sasken, L&T Infotech, Persistent

  [C][ ] (M) Detect if a given pointer is pointing to stack or heap memory.
             Hint: compare pointer address with a local variable's address.
             Asked at: Dolat Capital, Sasken

  [C][ ] (M) Implement a function that returns a pointer to a static local array.
             Explain why this works but returning pointer to local (non-static) doesn't.
             Asked at: L&T Infotech, Persistent, Sasken

  [C][ ] (M) Implement reference counting manually for a shared resource.
             (Increment on copy, decrement on destroy, free when count reaches 0)
             Asked at: Persistent, Nagarro, Dolat Capital

  [C][ ] (M) Implement a smart pointer (like unique_ptr) from scratch.
             Must include: operator*, operator->, destructor, no copy, move-only.
             Asked at: Google, Microsoft, Atlassian, advanced C++ roles

  [C][ ] (M) Write a reference-counted smart pointer (like shared_ptr) from scratch.
             Include copy constructor, copy assignment, and destructor.
             Asked at: Advanced C++ roles, Google

  [C][ ] (M) Implement your own unique_ptr:
             - Constructor, destructor (auto delete)
             - Move constructor and move assignment
             - Deleted copy constructor and copy assignment
             - operator* and operator->
             Asked at: Google, Microsoft

  [C][ ] (M) Implement a custom allocator that manages a fixed memory pool.
             alloc(size) and dealloc(ptr) from a pre-allocated char buffer.
             (Pool/arena allocator pattern)
             Asked at: Dolat Capital, HFT firms, game dev roles

  [C][ ] (M) Find and fix all the bugs in a code snippet that contains:
             - Double-free
             - Null pointer dereference
             - Use-after-free
             - Missing delete[]
             Asked at: Samsung, Persistent, L&T Infotech

  [C][ ] (M) Traverse a linked list using pointer arithmetic — do NOT use
             the -> operator directly; use raw pointer manipulation.
             Asked at: Sasken, Samsung, embedded C++ roles

  [C][ ] (M) Implement a simple stack using dynamic array and raw pointer.
             Operations: push, pop, peek, isFull, isEmpty.
             Asked at: Amazon, TCS

  [C][ ] (M) Find if there is a memory leak in a given code snippet.
             (Code review question — identify missing delete / delete[])
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Implement a circular buffer (ring buffer) using raw pointer to fixed array.
             push(), pop(), isFull(), isEmpty(), peek() — all O(1).
             Asked at: Dolat Capital, HFT firms, Sasken

  [C][ ] (M) Implement a fixed-size memory pool allocator for type T.
             Pre-allocate N objects; allocate() and deallocate() in O(1).
             Asked at: Dolat Capital, HFT firms

  [C][ ] (M) Rewrite a class (e.g., BankAccount) using unique_ptr for internal data.
             Demonstrate ownership semantics.
             Asked at: Amazon, Microsoft

  [C][ ] (M) Implement a shared linked list using shared_ptr for nodes.
             Show automatic memory management — no manual delete.
             Asked at: Amazon, Microsoft, Persistent

  [C][ ] (M) Implement reference counting:
             class SharedResource {
               int* refCount;
               int* data;
             public:
               SharedResource(int val);          // sets refCount = 1
               SharedResource(const SharedResource&); // increments refCount
               ~SharedResource();               // decrements, frees when 0
               SharedResource& operator=(const SharedResource&);
             };
             Asked at: Persistent, Nagarro, Dolat Capital

--------------------------------------------------------------------------------
2C. HARD CODING
--------------------------------------------------------------------------------

  [C][ ] (H) Implement a custom allocator that manages a fixed memory pool.
             alloc(size) and dealloc(ptr) from a pre-allocated char buffer.
             Support fragmentation with free list.
             Asked at: Dolat Capital, HFT firms, Sasken

  [C][ ] (H) Implement a garbage collector using reference counting
             with cycle detection using mark-and-sweep.
             Asked at: Google, Microsoft, advanced C++ roles

  [C][ ] (H) Given a memory layout diagram, identify all padding bytes in a struct.
             struct { char a; int b; char c; double d; } — draw layout, find sizeof.
             Then reorder fields to minimize padding.
             Asked at: Sasken, Samsung, Dolat Capital, Qualcomm

  [C][ ] (H) Implement a type-erased function wrapper (like std::function<>) from scratch.
             Use template + virtual dispatch inside.
             Asked at: Google, advanced C++ roles

  [C][ ] (H) Implement a copy-on-write smart pointer.
             Multiple readers share same array; deep copy only on write.
             Asked at: Dolat Capital, Adobe, Persistent

  [C][ ] (H) Implement a thread-safe object pool with acquire() and release().
             Objects are reused (not re-allocated). Support templated type.
             Asked at: Dolat Capital, HFT firms, Persistent

--------------------------------------------------------------------------------
2D. COMMONLY ASKED INTERVIEW RIDDLES / TRAPS ON POINTERS
(asked verbally or as "what's the output?" questions)
--------------------------------------------------------------------------------

  [C][ ] (E) What is the output?
             int* p = nullptr;
             if (p) cout << "not null";
             else   cout << "null";
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) What is the difference between:
             int* const p = &x;  // const pointer, non-const int
             const int* p = &x;  // non-const pointer, const int
             const int* const p = &x; // both const
             Asked at: Amazon, Microsoft, Google, Samsung, Sasken

  [C][ ] (E) What is the output? Explain each line.
             int a = 10;
             int* p = &a;
             int** pp = &p;
             **pp = 20;
             cout << a;  // prints 20
             Asked at: Samsung, L&T Infotech, Sasken

  [C][ ] (M) What is the output?
             int arr[] = {10, 20, 30, 40};
             int* p = arr;
             cout << *(p + 2);   // 30
             cout << p[3];       // 40
             cout << 2[p];       // 30  (C++ allows this — pointer + index is commutative)
             Asked at: Samsung, Sasken, HFT firms

  [C][ ] (M) Predict the output and explain struct padding:
             struct A { char a; int b; char c; };
             struct B { char a; char c; int b; };
             cout << sizeof(A) << " " << sizeof(B);
             (Typical output on 64-bit: 12 and 8)
             Asked at: Samsung, Sasken, Qualcomm, Dolat Capital

================================================================================
SECTION 3 — ADDITIONAL IMPORTANT QUESTIONS
(Interview-relevant questions across all levels that should NOT be missed)
================================================================================

  [T][ ] What is the PIMPL (Pointer to Implementation) idiom?
         Why does it improve compile times and binary compatibility?
         Asked at: Persistent, Nagarro, Adobe

  [T][ ] What is a handle-body pattern? How is it related to PIMPL?
         Asked at: Persistent, advanced C++ roles

  [T][ ] What is std::weak_ptr::lock()? Why is it needed?
         Asked at: Amazon, Microsoft, Persistent

  [T][ ] What is the difference between std::make_unique and new with unique_ptr?
         (Exception safety — make_unique is safer)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is std::make_shared vs new with shared_ptr?
         (make_shared allocates control block + object in one allocation — more efficient)
         Asked at: Amazon, Microsoft, Google, Persistent

  [C][ ] (M) Rewrite this memory-unsafe code using smart pointers:
             Widget* w = new Widget();
             process(w);
             delete w;
             Show: unique_ptr, shared_ptr versions + exception safety.
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Implement a doubly linked list using raw pointers.
             Ensure all memory is properly freed in the destructor.
             Implement: insertFront, insertBack, deleteFront, deleteBack, print.
             Asked at: Amazon, Flipkart, TCS, Wipro

  [C][ ] (M) Implement a doubly linked list using shared_ptr for next and
             weak_ptr for prev (to avoid circular reference).
             Asked at: Amazon, Persistent, advanced C++ roles

================================================================================
SECTION 4 — TOPICS FROM ROADMAP (STEPS 12 & 13) PRACTICE PROBLEMS
(Directly from the C++ DSA roadmap for self-study)
================================================================================

  [C][ ] (E) Print value and address using pointer.
             Understand: &x, *p, p — what each means.
             Roadmap Step 12

  [C][ ] (E) Swap two numbers using pointers (function).
             Roadmap Step 12

  [C][ ] (E) Traverse array using pointer arithmetic.
             Roadmap Step 12

  [C][ ] (E) Dynamically allocate array of size N, fill, print, delete.
             Roadmap Step 12

  [C][ ] (M) Implement a simple stack using dynamic array and pointer.
             Roadmap Step 12

  [C][ ] (E) Swap two numbers using references.
             Roadmap Step 13

  [C][ ] (M) Pass large struct to function using const reference (measure speed difference).
             Roadmap Step 13

  [C][ ] (M) Return reference from function (understand when safe / unsafe).
             Roadmap Step 13

================================================================================
SUMMARY COUNT
================================================================================

  Category                          |  E  |  M  |  H  | Total
  ----------------------------------|-----|-----|-----|-------
  Theory — Core Pointers            |  14 |   0 |   0 |    14
  Theory — References               |   6 |   0 |   0 |     6
  Theory — Smart Pointers/Modern    |  15 |   0 |   0 |    15
  Theory — Memory Model             |  14 |   0 |   0 |    14
  Theory — Advanced / Additional    |  10 |   0 |   0 |    10
  Coding — Easy                     |  15 |   0 |   0 |    15
  Coding — Medium                   |   0 |  18 |   0 |    18
  Coding — Hard                     |   0 |   0 |   6 |     6
  Coding — Output Traps/Riddles     |   3 |   2 |   0 |     5
  Additional Theory Questions       |   5 |   0 |   0 |     5
  Additional Coding                 |   0 |   3 |   0 |     3
  Roadmap Practice                  |   5 |   3 |   0 |     8
  ----------------------------------|-----|-----|-----|-------
  TOTAL                             |  59 |  26 |   6 |   119

================================================================================
COMPANY FOCUS GUIDE
================================================================================

  AMAZON / MICROSOFT / GOOGLE:
    Must know: All smart pointer theory and implementation, RAII, move semantics,
    deep vs shallow copy, dangling pointer detection, memory leak identification.
    Focus: Smart pointers, Rule of Three/Five, implementing unique_ptr/shared_ptr.

  SAMSUNG / SASKEN / QUALCOMM (Embedded/Systems):
    Must know: Raw pointer arithmetic, struct padding, memory alignment,
    stack vs heap, volatile/const pointer semantics.
    Focus: Memory layout, pointer arithmetic traps, const correctness.

  DOLAT CAPITAL / HFT FIRMS (Low Latency C++):
    Must know: Memory pools, custom allocators, cache-aware memory layout,
    smart vs raw pointer performance trade-offs, lock-free data structures.
    Focus: Custom allocators, memory pool, circular buffer, struct padding.

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    Must know: Basic pointer operations, swap by pointer/reference, pass by reference,
    dynamic allocation/deallocation, difference between pointer and reference.
    Focus: Easy coding section + core theory sections.

  L&T INFOTECH / PERSISTENT / NAGARRO (Mid-tier C++ roles):
    Must know: Full pointer theory, RAII, smart pointers, copy/move semantics,
    dangling pointer/reference, memory segments, destructor behavior.
    Focus: All theory sections + medium coding.

================================================================================
END
================================================================================
