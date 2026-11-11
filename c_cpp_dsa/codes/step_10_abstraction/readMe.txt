================================================================================
        ABSTRACTION — COMPLETE QUESTION BANK
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
1A. PURE VIRTUAL FUNCTIONS & ABSTRACT CLASSES
--------------------------------------------------------------------------------

  [T][ ] What is a pure virtual function? What is an abstract class?
         (Pure virtual: virtual void f() = 0;
          Abstract class: has at least one pure virtual function)
         Asked at: TCS, Wipro, Amazon, Zoho, Infosys

  [T][ ] What is a pure virtual function? Can it have a body?
         (Yes — pure virtual CAN have a body; it still forces derived to override it)
         Asked at: Amazon, Microsoft, Persistent

  [T][ ] What is an abstract class? Can you instantiate it?
         (No — you must derive from it and override ALL pure virtual functions)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is an interface in C++? How do you implement it?
         (Abstract class with ALL pure virtual functions and ideally no data members)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is the difference between an abstract class and a concrete class?
         Asked at: TCS, Wipro, Infosys

  ★[T][ ] When should you use an abstract class vs a pure interface in C++?
          (Abstract class: shared default behavior + interface contract;
           Interface: only a contract, no state or implementation)
          Asked at: Amazon, Microsoft, Adobe, Atlassian

  ★[T][ ] Can an abstract class have a constructor? If yes, when is it called?
          (Yes — called by derived class constructor via initializer list)
          Asked at: TCS, Wipro, Zoho, Amazon

  ★[T][ ] What happens if a derived class does NOT override all pure virtual functions?
          (It also becomes abstract and cannot be instantiated)
          Asked at: TCS, Wipro, Infosys

--------------------------------------------------------------------------------
1B. ENCAPSULATION — THE FOUNDATION OF ABSTRACTION
--------------------------------------------------------------------------------

  [T][ ] What is encapsulation? Why is it important?
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What is the difference between public, private, and protected access specifiers?
         Asked at: TCS, Wipro, Infosys, Zoho

  [T][ ] What is a friend function? When would you use it?
         Asked at: TCS, Wipro, Infosys, Zoho

  [T][ ] What is the 'this' pointer? Give an example of when you would use it.
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is a static member variable? How is it different from a regular member?
         (Shared across all objects of the class; belongs to the class, not the instance)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What does the explicit keyword do in constructors?
         (Prevents implicit/automatic type conversions)
         Asked at: Amazon, Adobe, Persistent, Nagarro

  [T][ ] What is a mutable member? When would you use it?
         (Can be modified even in a const method — e.g. caching, logging, mutex)
         Asked at: Amazon, Adobe, advanced C++ roles

  [T][ ] What is the difference between struct and class in C++?
         (Only difference: struct defaults to public, class defaults to private)
         Asked at: TCS, Wipro, Infosys (very common)

  ★[T][ ] What is data hiding? How is it different from encapsulation?
          (Data hiding: restricting access to internal data via private/protected;
           Encapsulation: bundling data + behavior into a single unit)
          Asked at: TCS, Wipro, Infosys, Zoho

--------------------------------------------------------------------------------
1C. OBJECT SLICING & RTTI
--------------------------------------------------------------------------------

  [T][ ] What is object slicing? When does it happen? How do you prevent it?
         (Passing derived by value to base type — extra members get cut off;
          Prevent: use pointer or reference to base)
         Asked at: Amazon, Microsoft, Zoho, Persistent

  [T][ ] What is RTTI (Run Time Type Information)?
         (dynamic_cast, typeid — enable type queries at runtime)
         Asked at: Amazon, Microsoft, Adobe

  [T][ ] What is the difference between dynamic_cast and static_cast?
         (dynamic_cast: runtime check, safe downcast, returns nullptr on failure;
          static_cast: compile-time, no runtime check)
         Asked at: Amazon, Microsoft, Adobe, Persistent

--------------------------------------------------------------------------------
1D. DESIGN PRINCIPLES AROUND ABSTRACTION
--------------------------------------------------------------------------------

  ★[T][ ] What is the Open/Closed Principle (OCP)?
          How do abstract classes and polymorphism enable it?
          (Open for extension, closed for modification — add new derived classes
           without changing existing code)
          Asked at: Amazon, Google, Atlassian, Adobe

  ★[T][ ] Explain the SOLID principles. How does OOP abstraction support each one?
          (Single Responsibility, Open/Closed, Liskov Substitution,
           Interface Segregation, Dependency Inversion)
          Asked at: Amazon, Microsoft, Google, Atlassian, Adobe

  ★[T][ ] What is the Dependency Inversion Principle?
          How do abstract classes/interfaces support it?
          (Depend on abstractions, not concrete implementations)
          Asked at: Amazon, Microsoft, Google, Adobe

  ★[T][ ] What is the difference between abstraction and encapsulation?
          (Abstraction: hiding complexity/implementation details via interface;
           Encapsulation: hiding internal data via access specifiers)
          Asked at: TCS, Wipro, Infosys, Amazon, Zoho

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Create a class Counter with increment(), decrement(), reset(), getValue().
             Use private members — demonstrate encapsulation.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Create a class Rectangle with private width and height.
             Add methods: area(), perimeter(), isSquare()
             Use getter/setter methods to access private data.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Create a class with a static member that counts total objects created.
             Destructor decrements count when object is destroyed.
             Print count after each creation/destruction.
             Asked at: Zoho, TCS, Wipro

  [C][ ] (E) Design an abstract shape class and derive Circle, Rectangle, Triangle.
             Each must implement area() and perimeter() as pure virtual methods.
             Instantiate only the derived types.
             Asked at: TCS, Wipro, Zoho, Infosys

  [C][ ] (E) Implement the Singleton pattern (Meyers Singleton — thread-safe):
             Private constructor, static instance method, no copy/assignment.
             Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (E) Demonstrate what happens when a derived class does NOT override
              a pure virtual function — show compiler error.
              Then fix it by overriding in derived.
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Create an abstract class Vehicle with pure virtual fuelType()
              and pure virtual maxSpeed().
              Derive: ElectricCar, PetrolBike, DieselTruck.
              Show that Vehicle* v = new Vehicle() fails, but
              Vehicle* v = new ElectricCar() works.
              Asked at: TCS, Wipro, Zoho

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Design a singleton class (thread-safe using std::call_once or local static).
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Design an immutable class in C++:
             All members set in constructor, no setters, all methods const.
             Asked at: Persistent, Nagarro, Google

  [C][ ] (M) Implement a generic Stack<T> class template with:
             push(), pop(), top(), isEmpty(), size()
             Handle underflow with a custom exception.
             Demonstrate encapsulation of internal array/vector.
             Asked at: Amazon, Microsoft, Zoho, Persistent

  [C][ ] (M) Implement copy-on-write string class:
             Only performs a deep copy when a write happens (lazy copy).
             Asked at: Dolat Capital, Adobe, advanced C++ roles

  [C][ ] (M) Design a publish-subscribe (Observer) system using abstraction:
             IListener abstract interface with pure virtual onEvent().
             EventBus: subscribers register, publisher calls notify().
             Multiple concrete listener types.
             Asked at: Adobe, Persistent, Nagarro

  [C][ ] (M) Implement the Builder pattern for constructing a complex Pizza order:
             Abstract IBuilder, concrete PizzaBuilder.
             setPizzaSize(), addTopping(), setBase(), build() -> Pizza object
             Asked at: Persistent, Nagarro, Amazon

  [C][ ] (M) Design and implement a simple expression parser using OOP:
             Abstract Expression base class with virtual evaluate() -> double
             Derived: Literal, BinaryExpression (Add, Subtract, Multiply, Divide)
             Visitor pattern for evaluation.
             Asked at: Atlassian, Adobe, Google

  [C][ ] (M) Implement an Iterator pattern for a custom linked list class:
             Abstract IIterator interface.
             Support range-based for: for (auto x : myList) {...}
             Requires begin(), end(), operator++, operator*, operator!=
             Asked at: Adobe, Atlassian, Persistent

  ★[C][ ] (M) Design a Logger system using abstraction:
              Abstract ILogger with pure virtual log(string message)
              Derived: ConsoleLogger, FileLogger, DatabaseLogger
              LogManager holds ILogger* and delegates.
              Switch logger at runtime without changing client code.
              Asked at: Amazon, Adobe, Persistent

  ★[C][ ] (M) Implement the Template Method pattern:
              Abstract class DataProcessor with a template method process():
              steps: readData() -> processData() -> writeData()
              readData() and writeData() are pure virtual.
              processData() has a default implementation.
              Concrete: CSVProcessor, JSONProcessor override read/write.
              Asked at: Amazon, Google, Adobe, Atlassian

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement a thread-safe object pool with acquire() and release():
             Objects are reused — not re-allocated each time.
             Support templated type T. Demonstrate abstraction of memory management.
             Asked at: Dolat Capital, HFT firms, Persistent

  [C][ ] (H) Design a plugin system where plugins are loaded as .so files at runtime:
             Abstract IPlugin interface with init(), execute(), getName().
             Plugins discovered and loaded via dlopen/dlsym.
             Host program works only with IPlugin* — no knowledge of concrete types.
             Asked at: L&T Infotech, Sasken, advanced roles

  ★[C][ ] (H) Design an ATM machine using OOP and abstraction:
              Abstract IState with pure virtual: insertCard(), enterPIN(),
              selectTransaction(), ejectCard()
              Concrete states: IdleState, HasCardState, AuthenticatedState, TransactionState
              ATM holds IState* and delegates all actions.
              Asked at: Zoho, TCS, Wipro, Infosys

  ★[C][ ] (H) Design a type-safe variant class (like std::variant) from scratch:
              Stores one of several types using a union + type tag.
              Supports get<T>() with runtime type check, and visit(callable).
              Demonstrates abstraction over raw union.
              Asked at: Google, advanced C++ roles

  ★[C][ ] (H) Design an Elevator system using abstraction:
              Abstract IScheduler with pure virtual addRequest() and nextFloor()
              Concrete: FCFSScheduler, SCANScheduler
              Elevator holds IScheduler*. Swap scheduling strategy at runtime.
              Asked at: Amazon, Microsoft, Zoho

================================================================================
SUMMARY COUNT
================================================================================

  Category                                     | E  | M  | H  | Total
  ---------------------------------------------|----|----|----|---------
  Theory — Pure Virtual & Abstract Classes     |  8 |  0 |  0 |     8
  Theory — Encapsulation                       |  9 |  0 |  0 |     9
  Theory — Object Slicing & RTTI               |  3 |  0 |  0 |     3
  Theory — Design Principles                   |  4 |  0 |  0 |     4
  Coding Easy                                  |  7 |  0 |  0 |     7
  Coding Medium                                |  0 | 10 |  0 |    10
  Coding Hard                                  |  0 |  0 |  5 |     5
  ---------------------------------------------|----|----|----|---------
  TOTAL                                        | 31 | 10 |  5 |    46

  ★ = 14 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI:
    → Pure virtual function, abstract class, can you instantiate abstract class,
      encapsulation, access specifiers, struct vs class, what if derived
      doesn't override pure virtual

  ZOHO:
    → Abstract Shape class coding, Singleton, Observer pattern,
      encapsulation demo, ATM machine design

  AMAZON / MICROSOFT / FLIPKART:
    → Abstract class vs interface, Singleton (thread-safe), Builder pattern,
      Iterator pattern, object slicing, SOLID principles, dependency inversion

  GOOGLE / ATLASSIAN / ADOBE:
    → Open/Closed principle, Template Method pattern, Visitor/expression parser,
      type-safe variant, plugin system, SOLID in depth

  DOLAT CAPITAL / HFT FIRMS / PERSISTENT:
    → Object pool, copy-on-write, mutable keyword, CRTP vs abstract,
      pure virtual with body, thread-safe designs

================================================================================
END
================================================================================
