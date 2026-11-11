================================================================================
        POLYMORPHISM — COMPLETE QUESTION BANK
        Compiled from all_in_one, all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        Added company-asked questions not in source files (marked with ★)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding
  ★  = Added question (commonly asked in real interviews, not in source files)

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. COMPILE-TIME (STATIC) POLYMORPHISM
--------------------------------------------------------------------------------

  [T][ ] What is polymorphism? What are its two types in C++?
         (Compile-time/Static: function & operator overloading;
          Runtime/Dynamic: virtual functions + base pointer/reference)
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What is function overloading? Can you overload based on return type alone?
         (No — return type alone is not enough, parameters must differ)
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] What is the difference between function overloading and function overriding?
         (Overloading: same name, different params, same class, compile-time;
          Overriding: same signature, different class, virtual, runtime)
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What is the difference between overloading, overriding, and hiding?
         Give an example of function hiding (name hiding).
         Asked at: TCS, Zoho, Persistent, L&T Infotech

  [T][ ] What is early binding vs late binding (static vs dynamic dispatch)?
         Asked at: TCS, Wipro, Infosys, Amazon, Microsoft

  [T][ ] What is operator overloading? Which operators cannot be overloaded?
         (Cannot overload: ::  .  .*  ?:  sizeof  typeid)
         Asked at: TCS, Wipro, Zoho, Samsung, Adobe

  ★[T][ ] What is the difference between static polymorphism and dynamic polymorphism
          from a memory and performance perspective?
          (Static: resolved at compile-time, zero overhead;
           Dynamic: vtable/vptr, indirect call, slight runtime overhead)
          Asked at: Google, Dolat Capital, Goldman Sachs, HFT firms

--------------------------------------------------------------------------------
1B. RUNTIME (DYNAMIC) POLYMORPHISM — VIRTUAL FUNCTIONS
--------------------------------------------------------------------------------

  [T][ ] What is a virtual function? Why do we need it?
         Asked at: TCS, Wipro, Amazon, Zoho, L&T Infotech

  [T][ ] What is a vtable (virtual function table)? How does it work?
         Asked at: TCS, Wipro, Amazon, Samsung, Zoho

  [T][ ] Explain the vtable and vptr mechanism in detail.
         (Each class with virtual functions gets its own vtable;
          each object gets a hidden vptr pointing to its class's vtable)
         Asked at: Amazon, Samsung, Sasken, embedded C++ roles

  [T][ ] What is the overhead of a virtual function call vs a direct call?
         (Extra pointer dereference through vptr → vtable → function pointer)
         Asked at: Dolat Capital, HFT firms, Sasken

  [T][ ] What is devirtualization? When can the compiler perform it?
         (Compiler replaces virtual call with direct call when it can prove the type)
         Asked at: Dolat Capital, HFT firms

  [T][ ] What is a virtual destructor? Why is it important?
         (Without it: deleting derived object via base pointer = undefined behavior / memory leak)
         Asked at: Amazon, Microsoft, Google, TCS, Wipro, Adobe

  [T][ ] Can constructors be virtual? Can destructors be virtual?
         (Constructors: No — vtable not ready yet.
          Destructors: Yes — ALWAYS make base destructor virtual when using polymorphism)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] Can you call a virtual function from a constructor or destructor? What happens?
         (Calls the base class version — vtable not yet/no longer pointing to derived)
         Asked at: Amazon, Microsoft, Adobe

  [T][ ] Can you call a non-virtual function polymorphically? Explain.
         (No — non-virtual uses static binding based on pointer type, not actual object type)
         Asked at: Zoho, Persistent

  [T][ ] What is the difference between the override and final keywords?
         (override: compiler checks that you're actually overriding a virtual;
          final: prevents further overriding in subclasses)
         Asked at: Persistent, Nagarro, L&T Infotech

  [T][ ] What is a covariant return type? Give an example.
         (Overriding method can return pointer/reference to a more derived type)
         Asked at: Advanced C++ roles, Google

  [T][ ] What is RTTI (Run Time Type Information)?
         (dynamic_cast and typeid — enable runtime type queries)
         Asked at: Amazon, Microsoft, Adobe

  [T][ ] What is the difference between dynamic_cast and static_cast?
         (dynamic_cast: runtime type check, safe downcast, returns nullptr on failure;
          static_cast: compile-time, no runtime check, unsafe if wrong)
         Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] Can a virtual function be inline? Is it ever actually inlined?
          (Declared inline is valid, but usually NOT inlined when called via pointer/reference —
           only inlined if compiler knows exact type at compile time)
          Asked at: Samsung, L&T Infotech, Persistent

  ★[T][ ] What happens to the vtable when a class uses multiple inheritance
          with multiple virtual base classes?
          (Each base gets its own vtable entry; object layout has multiple vptrs)
          Asked at: Samsung, Sasken, advanced C++ roles

--------------------------------------------------------------------------------
1C. STATIC POLYMORPHISM — CRTP & TEMPLATES
--------------------------------------------------------------------------------

  [T][ ] What is CRTP (Curiously Recurring Template Pattern)?
         How does it achieve static polymorphism without vtable overhead?
         Asked at: Dolat Capital, HFT firms, Advanced C++ roles

  ★[T][ ] When would you prefer CRTP over virtual functions?
          (Performance-critical code, HFT, embedded; when type known at compile time)
          Asked at: Dolat Capital, Goldman Sachs, HFT firms

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Create a base class Shape with a virtual method draw().
             Derive Circle and Square. Override draw() in each.
             Create an array of Shape* and call draw() on each.
             Demonstrate runtime polymorphism.
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Create an abstract Animal class with pure virtual speak().
             Derive Dog, Cat, Cow — each speaks differently.
             Store in vector<Animal*> and call speak() polymorphically.
             Asked at: TCS, Wipro, Infosys, Zoho

  [C][ ] (E) Overload the + operator for a Vector2D class (x, y).
             Also overload << to print the vector.
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Overload the == and != operators for a Point class (x, y).
             Asked at: Zoho, TCS, Wipro

  [C][ ] (E) Design a class Complex with operator+, -, *, ==, and <<.
             Asked at: Zoho, Samsung, L&T Infotech

  ★[C][ ] (E) Show function hiding vs overriding:
              Base class has a non-virtual method print() and a virtual method show().
              Derived class defines both print() and show().
              Call both using Base* pointing to Derived object.
              Explain and verify the output.
              Asked at: TCS, Zoho, Persistent, L&T Infotech

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Design an Animal hierarchy: Animal -> Dog, Cat with speak().
             Demonstrate dynamic dispatch using base class pointer.
             Asked at: Zoho, TCS, Infosys

  [C][ ] (M) Implement a class for Complex numbers with operator overloading
             (+, -, *, /) and stream operators (<< and >>).
             Asked at: Samsung, Adobe, Zoho

  [C][ ] (M) Implement CRTP (Curiously Recurring Template Pattern) for static polymorphism:
             Base<Derived> with non-virtual interface() that calls Derived::implementation().
             Show it avoids vtable overhead.
             Asked at: Dolat Capital, HFT firms, advanced C++ roles

  [C][ ] (M) Create a class Matrix with operator+ and operator* overloaded.
             operator* should perform actual matrix multiplication.
             Asked at: Samsung, Adobe, Goldman Sachs

  [C][ ] (M) Implement a Payment system using runtime polymorphism:
             Abstract base: Payment with virtual processPayment()
             Derived: CreditCard, UPI, Cash — each with its own logic.
             Asked at: Amazon, Flipkart, Paytm, Swiggy

  [C][ ] (M) Implement the Strategy design pattern using polymorphism:
             Abstract SortStrategy, concrete BubbleSort, QuickSort, MergeSort.
             SortContext holds a pointer to SortStrategy and delegates sorting.
             Switch strategy at runtime.
             Asked at: Amazon, Microsoft, Adobe, Atlassian

  [C][ ] (M) Design a notification system using polymorphism:
             Abstract Notifier with virtual send(string message)
             Derived: EmailNotifier, SMSNotifier, PushNotifier
             NotificationService holds vector<Notifier*> and broadcasts.
             Asked at: Amazon, Flipkart, Swiggy, Adobe

  ★[C][ ] (M) Demonstrate object slicing and how to prevent it:
              Pass a Derived object by value to a Base parameter — show data loss.
              Fix using Base& or Base* and virtual functions.
              Asked at: Amazon, Microsoft, Zoho, Persistent

  ★[C][ ] (M) Design a plugin/factory system using polymorphism:
              ShapeFactory creates Circle, Square, Triangle based on string input.
              Return Shape* (base pointer). Client calls area() polymorphically.
              Asked at: Amazon, Flipkart, Adobe

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (M) Design an event system using the Observer pattern:
             IListener interface (pure virtual onEvent()), EventSource class.
             Multiple concrete listeners registered at runtime.
             Asked at: Amazon, Adobe, Atlassian

  [C][ ] (H) Implement CRTP-based static polymorphism for a draw framework:
             Base<Derived> with drawImpl() dispatched at compile time.
             Compare binary size and performance with virtual version.
             Asked at: Dolat Capital, HFT firms, advanced C++ roles

  [C][ ] (H) Implement a type-safe variant class (like std::variant) from scratch:
             Stores one of several types, supports get<T>() and visit().
             Asked at: Google, advanced C++ roles

  ★[C][ ] (H) Design and implement an expression evaluator using OOP + polymorphism:
              Abstract: Expression with virtual evaluate() -> double
              Derived: Literal, Add, Subtract, Multiply, Divide (BinaryExpression)
              Build an AST from a given expression string, then evaluate.
              Asked at: Atlassian, Adobe, Google

  ★[C][ ] (H) Design a Chess game leveraging polymorphism:
              Abstract Piece with virtual isValidMove() and virtual getSymbol()
              Derived: King, Queen, Rook, Bishop, Knight, Pawn
              Board stores Piece* grid.
              Asked at: Amazon, Microsoft, Google, Atlassian

================================================================================
SUMMARY COUNT
================================================================================

  Category                                     | E  | M  | H  | Total
  ---------------------------------------------|----|----|----|---------
  Theory — Compile-time Polymorphism           |  7 |  0 |  0 |     7
  Theory — Runtime Polymorphism                | 15 |  0 |  0 |    15
  Theory — CRTP / Static Polymorphism          |  2 |  0 |  0 |     2
  Coding Easy                                  |  6 |  0 |  0 |     6
  Coding Medium                                |  0 |  9 |  0 |     9
  Coding Hard                                  |  0 |  1 |  4 |     5
  ---------------------------------------------|----|----|----|---------
  TOTAL                                        | 30 | 10 |  4 |    44

  ★ = 10 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI:
    → Two types of polymorphism, overloading vs overriding, virtual functions,
      operator overloading, Shape/Animal hierarchy programs

  ZOHO:
    → Function hiding vs overriding, operator overloading (Complex, Vector),
      runtime polymorphism demo with base pointer

  AMAZON / MICROSOFT / FLIPKART:
    → vtable/vptr internals, virtual destructor, object slicing,
      Factory pattern, Observer pattern, Strategy pattern

  GOOGLE / ATLASSIAN / ADOBE:
    → Covariant return types, expression evaluator (Visitor/OOP),
      CRTP, dynamic_cast vs static_cast, type-safe variant

  DOLAT CAPITAL / HFT FIRMS / SAMSUNG:
    → vtable overhead, devirtualization, CRTP vs virtual benchmark,
      virtual call cost, static vs dynamic dispatch performance

================================================================================
END
================================================================================
