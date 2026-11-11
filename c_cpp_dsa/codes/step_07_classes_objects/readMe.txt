================================================================================
        CLASSES & OBJECTS — COMPLETE QUESTION BANK
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
1A. CLASS & OBJECT BASICS
--------------------------------------------------------------------------------

  [T][ ] What is a class? What is an object? What is the difference?
         (Class = blueprint/type; Object = instance of a class in memory)
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What are the 4 pillars of OOP? Explain each with a real-world example.
         (Encapsulation, Abstraction, Inheritance, Polymorphism)
         Asked at: TCS, Wipro, Infosys, Amazon, Microsoft, Zoho

  [T][ ] What is encapsulation? Why is it important?
         (Bundling data + methods; hiding internal state via access specifiers)
         Asked at: TCS, Wipro, Infosys, Zoho, Persistent

  [T][ ] What is abstraction? How is it different from encapsulation?
         (Abstraction = hiding complexity; Encapsulation = hiding data)
         Asked at: TCS, Wipro, Zoho, L&T Infotech

  [T][ ] What is the difference between public, private, and protected?
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] What is the default access specifier for a class vs struct in C++?
         (class = private by default; struct = public by default)
         Asked at: TCS, Wipro, Infosys (very common!)

  [T][ ] What is the difference between struct and class in C++?
         (Only difference = default access specifier and default inheritance mode)
         Asked at: TCS, Wipro, Infosys, Amazon, Samsung

  [T][ ] Can a class have another class as a member? What is this called?
         (Yes — composition / aggregation / has-a relationship)
         Asked at: TCS, Wipro, Zoho, L&T Infotech

  [T][ ] What is the difference between aggregation, composition, and association?
         - Composition: strong ownership (Car has Engine — engine dies with car)
         - Aggregation: weak ownership (Library has Books — books exist independently)
         - Association: uses relationship (Teacher teaches Students)
         Asked at: TCS, Infosys, L&T Infotech, Persistent

  [T][ ] What is a member function? What is a member variable?
         Asked at: TCS, Wipro, Capgemini

  [T][ ] What does the scope resolution operator (::) do?
         Asked at: TCS, Wipro, Infosys, L&T Infotech

  [T][ ] What is object slicing? When does it happen? How do you prevent it?
         (Assigning derived to base object loses derived-specific data)
         (Prevent: use pointers or references to base)
         Asked at: Amazon, Microsoft, Zoho, Persistent

--------------------------------------------------------------------------------
1B. CONSTRUCTORS & DESTRUCTORS
--------------------------------------------------------------------------------

  [T][ ] What is a constructor? What are the types of constructors in C++?
         (Default, Parameterized, Copy, Move — C++11)
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] What is a default constructor? When does the compiler auto-generate one?
         (When no user-defined constructor exists — suppressed if any constructor defined)
         Asked at: TCS, Wipro, Zoho, Persistent

  [T][ ] What is a parameterized constructor?
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is a copy constructor? When is it called automatically?
         - Object initialized from another object: MyClass b = a;
         - Object passed by value to a function
         - Object returned by value from a function (unless RVO applies)
         Asked at: TCS, Wipro, Amazon, Zoho, Persistent, L&T Infotech

  [T][ ] What is the difference between shallow copy and deep copy?
         (Shallow: copies pointer address. Deep: copies pointed-to data)
         When does shallow copy cause problems?
         Asked at: Zoho, TCS, Wipro, Persistent, L&T Infotech

  [T][ ] What is a destructor? When is it called?
         (Called when object goes out of scope or is deleted)
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] Can a constructor be virtual? Can a destructor be virtual?
         (Constructor: NO. Destructor: YES — and should be virtual in base classes)
         Asked at: Amazon, Microsoft, Zoho, Persistent

  [T][ ] What is a virtual destructor? Why is it important?
         (Without it, deleting a derived object via base pointer causes
          undefined behavior — derived destructor never called)
         Asked at: Amazon, Microsoft, Zoho, Persistent, L&T Infotech

  [T][ ] What is an initializer list? Why is it preferred over assignment in constructor body?
         (More efficient — constructs directly instead of default-construct then assign;
          required for const members, references, and base class constructors)
         Asked at: Amazon, Microsoft, Persistent, Nagarro, Zoho

  [T][ ] What is delegating constructor (C++11)?
         (A constructor calling another constructor of the same class)
         Asked at: Persistent, Nagarro, modern C++ roles

  [T][ ] What is the order of constructor and destructor calls in inheritance?
         (Base constructor -> Derived constructor -> ... then destructors in reverse)
         Asked at: TCS, Wipro, Zoho, Persistent, L&T Infotech

  [T][ ] What is the Rule of Three? When do you need all three?
         (If you define destructor, copy constructor, or copy assignment —
          define all three. Needed when managing raw resources like heap memory.)
         Asked at: Persistent, Nagarro, Adobe, advanced C++ roles

  [T][ ] What is the Rule of Five (C++11)?
         (Adds move constructor and move assignment to Rule of Three)
         Asked at: Persistent, Nagarro, Adobe, Google, Atlassian

  [T][ ] What is the Rule of Zero?
         (Prefer to NOT define any of the five — use RAII types that manage
          resources automatically; then compiler-generated versions are correct)
         Asked at: Advanced C++ roles, Dolat Capital, Google

  [T][ ] What is the explicit keyword on constructors? Why use it?
         (Prevents implicit/accidental single-argument conversions)
         e.g. void f(MyClass x); f(42); — implicit conversion if not explicit
         Asked at: Zoho, Persistent, Nagarro, Amazon

  [T][ ] Can you call a virtual function from a constructor? What happens?
         (It calls the BASE class version — vtable for derived not yet set up)
         Asked at: Amazon, Microsoft, Adobe, Persistent

  [T][ ] What is a conversion constructor? What is a converting constructor?
         (Single-argument constructor that allows implicit type conversion)
         Asked at: Persistent, Nagarro, advanced C++ roles

  [T][ ] What is the difference between = default and = delete?
         (= default: ask compiler to generate; = delete: explicitly forbid)
         Asked at: Persistent, Nagarro, Google, Atlassian

--------------------------------------------------------------------------------
1C. THIS POINTER
--------------------------------------------------------------------------------

  [T][ ] What is the 'this' pointer? What does it point to?
         (Implicit pointer to the current object — available in non-static methods)
         Asked at: TCS, Wipro, Zoho, Amazon, Persistent

  [T][ ] When would you explicitly use 'this' pointer?
         - When parameter name shadows member name: this->name = name;
         - To return a reference to self (method chaining): return *this;
         - To pass current object to another function
         Asked at: TCS, Wipro, Zoho, Persistent

  [T][ ] Is 'this' available in static member functions? Why not?
         (No — static functions are not tied to any object instance)
         Asked at: TCS, Wipro, Persistent, Nagarro

  [T][ ] Can you delete 'this' inside a member function?
         (Yes, if object was heap-allocated — but must not use 'this' after delete)
         Asked at: Advanced C++ roles, Persistent

  [T][ ] What is method chaining? How is 'this' used to implement it?
         (Return *this as reference so calls can be chained: obj.set(1).set(2).set(3))
         Asked at: Persistent, Nagarro, Adobe

--------------------------------------------------------------------------------
1D. STATIC MEMBERS
--------------------------------------------------------------------------------

  [T][ ] What is a static member variable? How is it different from a regular member?
         (Shared across ALL instances of the class; exists even if no objects exist)
         Asked at: TCS, Wipro, Zoho, Amazon, Persistent

  [T][ ] How do you define and initialize a static member variable?
         (Declare inside class; define OUTSIDE the class — once in .cpp)
         static int count; // declaration in class
         int MyClass::count = 0; // definition outside
         Asked at: TCS, Wipro, Zoho, Persistent

  [T][ ] What is a static member function?
         (Can be called without an object — ClassName::func(); — no 'this' pointer)
         Asked at: TCS, Wipro, Zoho, Amazon

  [T][ ] Can a static member function access non-static members?
         (No — it has no 'this' pointer and no access to instance data)
         Asked at: TCS, Wipro, Persistent

  [T][ ] What is the difference between static local variable and static member variable?
         (Static local: persists between calls but scoped to function;
          Static member: shared across all class instances)
         Asked at: TCS, Wipro, L&T Infotech

  [T][ ] What is an inline static member variable (C++17)?
         (Can be defined and initialized inside the class without separate .cpp definition)
         Asked at: Modern C++ roles, Nagarro, Persistent

  [T][ ] What is the Meyers Singleton? Why is the local static version thread-safe in C++11?
         (C++11 guarantees that local static initialization is thread-safe)
         static MyClass& getInstance() { static MyClass instance; return instance; }
         Asked at: Amazon, Microsoft, Dolat Capital, Persistent

--------------------------------------------------------------------------------
1E. FRIEND FUNCTIONS & CLASSES
--------------------------------------------------------------------------------

  [T][ ] What is a friend function? When would you use it?
         (Non-member function with access to private/protected members of a class)
         Asked at: TCS, Wipro, Zoho, Persistent, L&T Infotech

  [T][ ] What is a friend class?
         (All member functions of the friend class can access private members)
         Asked at: TCS, Wipro, Zoho

  [T][ ] Is friendship transitive? Is it inherited?
         (No to both — friendship is not transitive or inherited)
         Asked at: Advanced C++ roles, Persistent

  [T][ ] When would you use a friend function vs a member function?
         (When the left operand of an operator is not of your class type,
          e.g. operator<< for cout — cout is ostream, not MyClass)
         Asked at: Zoho, Persistent, Samsung

--------------------------------------------------------------------------------
1F. CONST MEMBER FUNCTIONS & MUTABLE
--------------------------------------------------------------------------------

  [T][ ] What is a const member function?
         (Promises not to modify the object — can be called on const objects)
         void show() const { ... }
         Asked at: TCS, Wipro, Amazon, Persistent, Nagarro

  [T][ ] Can a const member function call a non-const member function?
         (No — would violate the const guarantee)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] What is a mutable member variable? When would you use it?
         (Can be modified even inside const member functions)
         Use case: caching/memoization inside a logically-const function
         Asked at: Amazon, Microsoft, Persistent, Nagarro

  [T][ ] What is the difference between const object and const member function?
         (const object: cannot call non-const methods;
          const method: can be called on const objects, cannot modify *this)
         Asked at: Amazon, Persistent

  [T][ ] What is const correctness? Why is it important?
         (Marking everything const that should not be modified — prevents bugs,
          enables optimizations, documents intent)
         Asked at: Amazon, Google, Persistent, Nagarro, Dolat Capital

--------------------------------------------------------------------------------
1G. OPERATOR OVERLOADING
--------------------------------------------------------------------------------

  [T][ ] What is operator overloading? Which operators can and cannot be overloaded?
         Cannot overload: :: (scope), . (member access), .* (member pointer),
         ?: (ternary), sizeof, typeid, alignof
         Asked at: TCS, Wipro, Zoho, Amazon, Samsung

  [T][ ] What is the difference between overloading as member function vs friend function?
         (Member: left operand is *this; Friend/non-member: explicit both operands;
          Use non-member for symmetry when left operand isn't your type)
         Asked at: Zoho, Persistent, Samsung, L&T Infotech

  [T][ ] How do you overload operator<< for cout?
         (Must be non-member: friend ostream& operator<<(ostream& os, const MyClass& obj))
         Asked at: Zoho, TCS, Samsung, Persistent

  [T][ ] How do you overload the assignment operator (=)?
         (MyClass& operator=(const MyClass& other) — return *this for chaining;
          must handle self-assignment; performs deep copy if needed)
         Asked at: Zoho, Amazon, Persistent, L&T Infotech

  [T][ ] How do you overload prefix ++ vs postfix ++?
         (Prefix: MyClass& operator++();
          Postfix: MyClass operator++(int); — dummy int parameter distinguishes them)
         Asked at: Zoho, Persistent, Samsung

  [T][ ] How do you overload the [] (subscript) operator?
         (Provide both const and non-const versions for proper usage)
         Asked at: Persistent, Nagarro, Samsung

  [T][ ] How do you overload the () (function call) operator? What is a functor?
         (Makes the object callable — used in STL algorithms, comparators)
         Asked at: Persistent, Nagarro, L&T Infotech

  [T][ ] What is the spaceship operator <=> (three-way comparison, C++20)?
         (Returns std::strong_ordering — auto-generates all 6 comparison operators)
         Asked at: Google, modern C++ roles, Atlassian

  [T][ ] Should operator== be a member or non-member function?
         (Prefer non-member (or friend) for symmetry — allows both sides to convert)
         Asked at: Persistent, Nagarro

  [T][ ] What is a conversion operator? Give an example.
         (operator bool() const — allows implicit/explicit conversion to bool)
         Asked at: Persistent, Nagarro, advanced C++ roles

--------------------------------------------------------------------------------
1H. INHERITANCE (covered here as it directly relates to class design)
--------------------------------------------------------------------------------

  [T][ ] What is inheritance? What are the types of inheritance in C++?
         (Single, Multiple, Multilevel, Hierarchical, Hybrid)
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What is the diamond problem? How is it solved in C++?
         (Multiple inheritance ambiguity — solved with virtual base class:
          class B : virtual public A { ... };)
         Asked at: TCS, Wipro, L&T Infotech, Persistent

  [T][ ] What is the difference between public, private, and protected inheritance?
         Public: public->public, protected->protected
         Protected: public->protected, protected->protected
         Private: public->private, protected->private
         Asked at: TCS, Wipro, Zoho, Persistent

  [T][ ] What is the difference between overloading, overriding, and hiding?
         - Overloading: same name, different params, same class
         - Overriding: same name, same params, derived class overrides base virtual
         - Hiding: derived has same name (non-virtual) — hides base version
         Asked at: TCS, Zoho, Persistent, L&T Infotech

  [T][ ] What is a virtual function? Why do we need it?
         (Enables runtime polymorphism — correct derived function called via base pointer)
         Asked at: TCS, Wipro, Amazon, Zoho, Persistent, L&T Infotech

  [T][ ] What is a pure virtual function? What is an abstract class?
         (Pure virtual: virtual void f() = 0; — forces derived to override;
          Abstract class: has at least one pure virtual function — cannot instantiate)
         Asked at: TCS, Wipro, Amazon, Zoho, Persistent

  [T][ ] Can a pure virtual function have a body?
         (YES — it can have a default implementation, but derived must still override)
         Asked at: Amazon, Microsoft, Persistent

  [T][ ] What is early binding vs late binding (static vs dynamic dispatch)?
         (Early: resolved at compile time (non-virtual);
          Late: resolved at runtime via vtable (virtual))
         Asked at: TCS, Wipro, Zoho, Persistent, L&T Infotech

  [T][ ] What is the vtable (virtual function table)? What is a vptr?
         (vtable: per-class table of function pointers for virtual functions;
          vptr: per-object pointer to its class vtable — added by compiler)
         Asked at: Amazon, Samsung, Sasken, Zoho, embedded C++ roles

  [T][ ] What is the overhead of a virtual function call?
         (One extra pointer dereference via vptr -> vtable; prevents inlining)
         Asked at: Dolat Capital, HFT firms, Samsung, Sasken

  [T][ ] What is devirtualization? When can the compiler do it?
         (Compiler resolves virtual call at compile time when object type is known)
         Asked at: Dolat Capital, HFT firms, advanced C++ roles

  [T][ ] What is RTTI (Run Time Type Information)?
         What is dynamic_cast? What is typeid?
         (RTTI allows querying object type at runtime — has overhead)
         Asked at: Persistent, Nagarro, advanced C++ roles

  [T][ ] What is covariant return type? Give an example.
         (Overriding function can return pointer/ref to a more derived type)
         Base* clone() vs Derived* clone() — valid override!
         Asked at: Advanced C++ roles, Google

  [T][ ] What is the override keyword (C++11)? What about final?
         (override: explicitly marks an override — compiler error if not overriding;
          final: prevents further overriding or class derivation)
         Asked at: Persistent, Nagarro, L&T Infotech, Amazon

  [T][ ] What is the difference between function overloading and function overriding?
         (Overloading: same class, different signatures, compile-time;
          Overriding: base+derived, same signature, runtime via virtual)
         Asked at: TCS, Wipro, Infosys, Zoho

  [T][ ] Can you call a non-virtual function polymorphically?
         (No — non-virtual calls are resolved at compile time based on pointer type,
          not object type)
         Asked at: Zoho, Persistent

--------------------------------------------------------------------------------
1I. OOP DESIGN PRINCIPLES (asked in interviews)
--------------------------------------------------------------------------------

  [T][ ] What are the SOLID principles? Explain each briefly.
         S — Single Responsibility: class does one thing
         O — Open/Closed: open for extension, closed for modification
         L — Liskov Substitution: derived class can replace base without breaking
         I — Interface Segregation: many small interfaces > one large
         D — Dependency Inversion: depend on abstractions, not concretes
         Asked at: Amazon, Microsoft, Persistent, Nagarro, Adobe

  [T][ ] What is the Liskov Substitution Principle? Give a violation example.
         (Square extends Rectangle — setWidth on Square breaks Rectangle contract)
         Asked at: Amazon, Microsoft, Google, Atlassian

  [T][ ] What is DRY (Don't Repeat Yourself) principle?
         Asked at: TCS, Wipro, Persistent, Nagarro

  [T][ ] What is the difference between IS-A and HAS-A relationships?
         (IS-A = inheritance; HAS-A = composition/aggregation)
         Asked at: TCS, Wipro, L&T Infotech, Zoho

  [T][ ] When should you prefer composition over inheritance?
         (When the HAS-A relationship is more accurate; avoids tight coupling)
         Asked at: Amazon, Google, Persistent, Nagarro

================================================================================
SECTION 2 — CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. EASY CODING
--------------------------------------------------------------------------------

  [C][x] (E) Create a class Rectangle with width and height.
             Add methods: area(), perimeter(), isSquare().
             Create 3 objects and call all methods.
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Create a class Counter with increment(), decrement(), reset(), getValue().
             Use private member. Demonstrate encapsulation.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Create a class Circle with radius.
             Methods: area(), circumference(), isLargerThan(Circle other).
             Asked at: TCS, Wipro, Capgemini

  [C][ ] (E) Create a Student class with name, rollNo, marks[5].
             Methods: calculateAverage(), getGrade(), display().
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][ ] (E) Create a class with a static member that counts total objects created.
             Increment in constructor, decrement in destructor.
             Asked at: Zoho, TCS, Wipro

  [C][ ] (E) Overload the == operator for a Point class (x, y coordinates).
             Two points are equal if x and y match.
             Asked at: Zoho, TCS, Wipro

  [C][ ] (E) Create a base class Shape with virtual method draw().
             Derive Circle and Square, override draw() in each.
             Create array of Shape* and call draw() — demonstrate polymorphism.
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Create a class Vehicle -> ElectricVehicle -> Tesla hierarchy.
             Show constructor and destructor call order with virtual destructors.
             Asked at: TCS, Wipro, L&T Infotech

  [C][ ] (E) Design a class Matrix with operator+ and operator* (matrix multiply).
             Add operator<< for printing.
             Asked at: Zoho, Persistent, Adobe, Samsung

  [C][ ] (E) Design a Fraction class with +, -, *, / operators that auto-simplifies.
             Use GCD to reduce after each operation. Overload <<.
             Asked at: Zoho, Amazon campus, Adobe

  [C][ ] (E) Design a Complex number class with operator+, -, *, /, ==, and <<.
             Asked at: Zoho, Samsung, L&T Infotech

  [C][ ] (E) Implement the Singleton pattern:
             - Private constructor
             - Static getInstance() method
             - Make it thread-safe using local static (Meyers Singleton)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Create a class with a copy constructor that does DEEP copy.
             Use a class with a char* data member (like a mini String class).
             Demonstrate that changing original does NOT affect copy.
             Asked at: Zoho, Persistent, Adobe

  [C][ ] (E) Create a class that demonstrates method chaining.
             Builder-style: obj.setName("A").setAge(20).setCity("B").print();
             Return *this as reference from each setter.
             Asked at: Amazon, Persistent, Nagarro

  [C][ ] (E) Demonstrate object slicing:
             - Create Base and Derived objects
             - Assign derived to base (slicing occurs)
             - Show that base's version of function is called
             - Fix it using base pointer/reference
             Asked at: Amazon, Zoho, Persistent

  [C][ ] (E) Create a class with:
             - Default constructor (prints message)
             - Parameterized constructor
             - Copy constructor (prints message)
             - Destructor (prints message)
             Create objects in different ways and observe call order.
             Asked at: TCS, Wipro, Zoho, Persistent

  [C][ ] (E) Implement a BankAccount class:
             Private: balance, accountNumber, ownerName
             Public: deposit(amount), withdraw(amount), getBalance(), display()
             Validate: no negative balance, no negative deposit
             Asked at: TCS, Zoho, Wipro, Infosys

  [C][ ] (E) Demonstrate const member function:
             Create class with both const and non-const versions of a method.
             Create a const object and show which version gets called.
             Asked at: Amazon, Persistent, Nagarro

  [C][ ] (E) Demonstrate the explicit keyword:
             Create class MyInt with constructor MyInt(int val).
             Show implicit conversion bug, then fix with explicit.
             Asked at: Zoho, Persistent, Nagarro

  [C][ ] (E) Overload prefix ++ and postfix ++ for a Counter class.
             Show the difference in return value (ref vs value copy).
             Asked at: Zoho, Persistent, Samsung

  [C][ ] (E) Create a class Temperature with:
             - Data in Celsius
             - Method toCelsius(), toFahrenheit(), toKelvin()
             - Overload < and > for comparison
             - Overload << for printing
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Implement a Stack class using an array:
             push(), pop(), top(), isEmpty(), isFull()
             Handle overflow and underflow with exceptions.
             Asked at: Amazon, Microsoft, Zoho

  [C][ ] (E) Create an abstract Shape class with pure virtual area() and perimeter().
             Implement for Circle, Rectangle, Triangle.
             Use a vector<Shape*> and call area() polymorphically.
             Asked at: TCS, Wipro, Zoho, Amazon

--------------------------------------------------------------------------------
2B. MEDIUM CODING
--------------------------------------------------------------------------------

  [C][ ] (M) Design a BankAccount class hierarchy:
             BankAccount (base) -> SavingsAccount, CurrentAccount (derived).
             SavingsAccount: adds interest calculation.
             CurrentAccount: adds overdraft facility.
             Use virtual calculateInterest().
             Asked at: TCS, Zoho, Wipro, Infosys

  [C][ ] (M) Design a Student class, create array of students, sort by marks,
             find topper, find average.
             Overload < for sorting. Use std::sort with custom comparator.
             Asked at: TCS, Wipro

  [C][ ] (M) Implement a Stack<T> class template:
             push(), pop(), top(), isEmpty(), size().
             Handle underflow with std::exception.
             Asked at: Amazon, Microsoft, Zoho, Persistent

  [C][ ] (M) Design an Animal hierarchy:
             Animal (abstract, virtual speak()) -> Dog, Cat, Cow (concrete).
             Dog says "Woof", Cat says "Meow", Cow says "Moo".
             Store in vector<Animal*>, call speak() on each.
             Asked at: Zoho, TCS, Infosys

  [C][ ] (M) Implement a Complex number class with:
             - operator+ (member)
             - operator- (member)
             - operator* (member)
             - operator== (friend)
             - operator<< (friend, for cout)
             - operator>> (friend, for cin)
             Asked at: Samsung, Adobe, Zoho

  [C][ ] (M) Design a Singleton class (thread-safe):
             - Private constructor
             - Deleted copy constructor and assignment
             - Thread-safe getInstance() using std::call_once or local static
             - Demonstrate it works with two threads
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Implement LRU Cache using class (HashMap + Doubly Linked List):
             get(key) -> value or -1
             put(key, value) -> evicts LRU if capacity exceeded
             Both O(1).
             Asked at: Amazon, Microsoft, Google, Flipkart, Paytm

  [C][ ] (M) Implement the Observer pattern:
             EventSource (Subject): attach(IObserver*), detach(), notify()
             IObserver (interface): pure virtual update()
             ConcreteObserver: implements update()
             Asked at: Adobe, Persistent, Nagarro, Amazon

  [C][ ] (M) Implement the Factory pattern:
             ShapeFactory::createShape(string type) -> Shape*
             Creates Circle, Rectangle, Triangle based on string.
             Client code knows nothing about concrete classes.
             Asked at: Amazon, Flipkart, Adobe

  [C][ ] (M) Implement the Builder pattern for a complex Pizza order:
             Pizza class with: size, crust, sauce, toppings (vector<string>)
             PizzaBuilder: setPizzaSize(), addTopping(), setBase(), build() -> Pizza
             Asked at: Persistent, Nagarro, Amazon

  [C][ ] (M) Implement an Iterator pattern for a custom linked list class:
             Support range-based for loop: for (auto x : myList) { ... }
             Requires: begin(), end(), operator++, operator*, operator!=
             Asked at: Adobe, Atlassian, Persistent

  [C][ ] (M) Design a publish-subscribe (Observer) system:
             EventBus: subscribe(eventType, callback), publish(eventType, data)
             Multiple subscribers for same event type.
             Asked at: Adobe, Persistent, Nagarro

  [C][ ] (M) Implement copy-on-write string class:
             Deep copy only when write (mutation) happens — shared until then.
             Asked at: Dolat Capital, Adobe, advanced C++ roles

  [C][ ] (M) Design an immutable class in C++:
             All members set in constructor, no setters, all methods const.
             Show how to use it safely.
             Asked at: Persistent, Nagarro, Google

  [C][ ] (M) Implement CRTP (Curiously Recurring Template Pattern) for static polymorphism:
             template<class Derived> class Base {
               void interface() { static_cast<Derived*>(this)->implementation(); }
             };
             Show it avoids vtable overhead.
             Asked at: Dolat Capital, HFT firms, advanced C++ roles

  [C][ ] (M) Design a generic Stack class using templates:
             push(), pop(), top(), isEmpty(), size()
             Exception on pop/top when empty.
             Also implement copy constructor and copy assignment.
             Asked at: Zoho, Amazon, Adobe

  [C][ ] (M) Design and implement a simple expression parser using OOP:
             Expression (base, virtual eval()) -> Literal, Variable,
             BinaryExpression (left, op, right).
             Visitor pattern for evaluation.
             Asked at: Atlassian, Adobe, Google

  [C][ ] (M) Implement a Parking Lot system (OOP design + code):
             Classes: ParkingLot, ParkingSpot, Vehicle, Ticket
             Operations: parkVehicle(), exitVehicle(), calculateFee()
             Handle different vehicle types (bike, car, truck).
             Asked at: Amazon, Microsoft, Adobe, Flipkart, Zoho

  [C][ ] (M) Implement a Library Management System:
             Classes: Library, Book, Member, Transaction
             Operations: addBook(), issueBook(), returnBook(), searchBook()
             Asked at: Zoho, TCS, Infosys

  [C][ ] (M) Implement an ATM machine (OOP design + code):
             Classes: ATM, BankAccount, Card, Transaction
             Operations: insertCard(), enterPIN(), withdraw(), checkBalance()
             Asked at: Zoho, TCS, Wipro, Infosys

  [C][ ] (M) Design a Chess game (class hierarchy):
             Classes: Board, Piece (abstract), King, Queen, Rook, Bishop, Knight, Pawn
             Piece has virtual isValidMove(Position from, Position to).
             Asked at: Amazon, Microsoft, Google, Atlassian

  [C][ ] (M) Implement a thread-safe LRU Cache class:
             Doubly linked list + unordered_map for O(1) get and put.
             Add mutex for thread safety.
             Asked at: Amazon, Google, Microsoft, Flipkart

  [C][ ] (M) Implement a Decorator pattern:
             Coffee (interface) -> SimpleCoffee (concrete)
             CoffeeDecorator -> MilkDecorator, SugarDecorator, WhipDecorator
             Each decorator adds cost and description.
             Asked at: Persistent, Nagarro, Adobe

  [C][ ] (M) Implement an elevator system (OOP design + basic code):
             Classes: Elevator, ElevatorController, Floor, Request
             Scheduling: process requests in order.
             Asked at: Amazon, Microsoft, Zoho

  [C][ ] (M) Implement a generic event-driven state machine:
             addState(name), addTransition(from, event, to),
             trigger(event), currentState()
             Asked at: Adobe, Persistent, Nagarro

  [C][ ] (M) Implement a copy-on-write (COW) vector:
             Multiple readers share the same array; deep copy on write only.
             Asked at: Dolat Capital, Adobe, Persistent

  [C][ ] (M) Design a notification system:
             subscribe(userId, eventType), unsubscribe(userId, eventType),
             publish(eventType, message) — notify all subscribers.
             Asked at: Amazon, Adobe, Persistent

  [C][ ] (M) Design a simple in-memory database supporting:
             set(key, value), get(key), delete(key),
             begin(), commit(), rollback() (transactions).
             Hint: use stack of transaction snapshots.
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (M) Implement a plugin system using the Factory pattern:
             Plugins register themselves with the factory.
             Client requests plugin by name; factory creates and returns it.
             Asked at: Amazon, Flipkart, Adobe

  [C][ ] (M) Implement a Strategy pattern for sorting:
             Sorter class takes a SortStrategy interface.
             BubbleSort, MergeSort, QuickSort implement SortStrategy.
             Can swap strategy at runtime.
             Asked at: Persistent, Nagarro, Amazon

  [C][ ] (M) Implement a Command pattern for a text editor:
             Command interface with execute() and undo().
             TypeCommand, DeleteCommand, PasteCommand.
             CommandHistory with undo/redo stack.
             Asked at: Adobe, Atlassian, Microsoft

  [C][ ] (M) Design a Price Alert System:
             setAlert(stock, targetPrice)
             updatePrice(stock, currentPrice) — notify if threshold crossed.
             Support multiple alerts per stock.
             Asked at: Dolat Capital, Goldman Sachs, ICICI Securities

  [C][ ] (M) Implement a Task Manager:
             addTask(name, priority, deadline),
             getNextTask() — returns highest priority task respecting deadlines.
             Asked at: Amazon, Microsoft, Dolat Capital

--------------------------------------------------------------------------------
2C. HARD CODING
--------------------------------------------------------------------------------

  [C][ ] (H) Implement a type-safe variant class (like std::variant) from scratch:
             Stores one of several types.
             Supports get<T>() and visit(visitor).
             Asked at: Google, advanced C++ roles

  [C][ ] (H) Implement a thread-safe object pool with acquire() and release():
             Objects are reused — not re-allocated.
             Support templated type. Use mutex + condition_variable.
             Asked at: Dolat Capital, HFT firms, Persistent

  [C][ ] (H) Design a real-time leaderboard system:
             updateScore(playerId, score)
             getTopK(K) — top K players
             getRank(playerId) — rank of a specific player
             All operations O(log N).
             Hint: std::set with custom struct or order-statistics tree.
             Asked at: Amazon, Google, Goldman Sachs, Dolat Capital

  [C][ ] (H) Implement a concurrent hash map:
             Stripe-level locking for parallel writes (N stripes, each with mutex).
             Parallel reads allowed. Templated key and value.
             Asked at: Dolat Capital, Amazon, Google, Persistent

  [C][ ] (H) Design a high-performance Order Book class:
             addOrder(id, side, price, qty)
             cancelOrder(id)
             getTopOfBook() — best bid and best ask
             matchOrders() — match when buy price >= sell price
             Data structures: sorted map + hashmap by id.
             Asked at: Dolat Capital, HFT firms, ICICI Securities

  [C][ ] (H) Implement a smart pointer (shared_ptr) from scratch with:
             - Reference counting (control block on heap)
             - Constructor, copy constructor, copy assignment (inc refcount)
             - Destructor (dec refcount, delete if 0)
             - operator*, operator->
             - get(), use_count(), reset()
             - Thread-safe ref counting using std::atomic
             Asked at: Google, Microsoft, advanced C++ roles

  [C][ ] (H) Implement a type-erased function wrapper (like std::function<R(Args...)>)
             from scratch using template + virtual dispatch inside.
             Asked at: Google, advanced C++ roles

  [C][ ] (H) Implement a plugin system where plugins are .so files loaded at runtime:
             Plugins implement a common interface (pure virtual class).
             Use dlopen/dlsym for discovery.
             Asked at: L&T Infotech, Sasken, advanced roles

  [C][ ] (H) Design a distributed key-value store class (conceptual + data structures):
             Consistent hashing for key partitioning across N nodes.
             Replication factor R, read/write quorum.
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Implement a generic observer with type-safe event dispatch:
             EventSystem<EventType> where handlers are std::function<void(EventType)>.
             No dynamic_cast. Template-based dispatch.
             Asked at: Adobe, Google, advanced C++ roles

--------------------------------------------------------------------------------
2D. OUTPUT / TRICKY QUESTIONS (asked as "What is the output?")
--------------------------------------------------------------------------------

  [C][ ] (E) What is the output?
             class A {
             public:
               A() { cout << "A ctor\n"; }
               ~A() { cout << "A dtor\n"; }
             };
             class B : public A {
             public:
               B() { cout << "B ctor\n"; }
               ~B() { cout << "B dtor\n"; }
             };
             int main() { B obj; }
             // Output: A ctor -> B ctor -> B dtor -> A dtor
             Asked at: TCS, Wipro, Zoho, Persistent

  [C][ ] (E) What is the output? (virtual destructor trap)
             class Base { public: ~Base() { cout << "Base dtor\n"; } };
             class Derived : public Base { public: ~Derived() { cout << "Derived dtor\n"; } };
             Base* p = new Derived();
             delete p;
             // Output: ONLY "Base dtor" — Derived dtor NEVER called! (UB)
             // Fix: make Base destructor virtual.
             Asked at: Amazon, Microsoft, Zoho, Persistent

  [C][ ] (E) What is the output? (static member)
             class Counter {
               static int count;
             public:
               Counter() { count++; }
               static int getCount() { return count; }
             };
             int Counter::count = 0;
             Counter a, b, c;
             cout << Counter::getCount();  // Output: 3
             Asked at: TCS, Wipro, Zoho

  [C][ ] (M) What is the output? (virtual function in constructor trap)
             class Base {
             public:
               Base() { display(); }
               virtual void display() { cout << "Base\n"; }
             };
             class Derived : public Base {
             public:
               Derived() { display(); }
               void display() override { cout << "Derived\n"; }
             };
             Derived d;
             // Output: Base (from Base ctor) -> Derived (from Derived ctor)
             // Base ctor calls Base::display, NOT Derived::display!
             Asked at: Amazon, Microsoft, Adobe, Persistent

  [C][ ] (M) What is the output? (object slicing trap)
             class Animal {
             public:
               virtual string sound() { return "..."; }
             };
             class Dog : public Animal {
             public:
               string sound() override { return "Woof"; }
             };
             Dog d;
             Animal a = d;   // SLICING — a is Animal, not Dog
             cout << a.sound();  // Output: "..."  (Animal version!)
             Asked at: Amazon, Zoho, Persistent

  [C][ ] (M) What is the output? (copy constructor call count)
             MyClass obj1;
             MyClass obj2 = obj1;      // copy ctor
             MyClass obj3(obj1);       // copy ctor
             MyClass obj4;
             obj4 = obj1;              // assignment operator (NOT copy ctor)
             // How many times is copy ctor called? Answer: 2
             Asked at: Zoho, Persistent, L&T Infotech

  [C][ ] (M) What is the output? (diamond problem)
             class A { public: void hello() { cout << "A\n"; } };
             class B : public A {};
             class C : public A {};
             class D : public B, public C {};
             D obj;
             obj.hello();  // COMPILE ERROR — ambiguous!
             // Fix: virtual inheritance in B and C
             Asked at: TCS, Wipro, L&T Infotech, Persistent

================================================================================
SECTION 3 — DESIGN PATTERNS SUMMARY (quick reference)
================================================================================

  Creational Patterns:
    Singleton     — one instance; static getInstance(); private constructor
    Factory       — createObject(type) -> Base*; hides concrete type from client
    Builder       — step-by-step construction: set().set().build()
    Prototype     — virtual clone() method; copies without knowing concrete type
    Abstract Factory — family of related objects; create related products together

  Structural Patterns:
    Adapter       — makes incompatible interfaces work together
    Decorator     — add behavior wrapping an object: component->decorator->client
    Proxy         — placeholder/wrapper with same interface as real object
    Facade        — simple interface to complex subsystem
    Composite     — tree structure for part-whole hierarchies (File/Folder)

  Behavioral Patterns:
    Observer      — notify all subscribers when state changes (Event system)
    Strategy      — swap algorithm at runtime; same interface, different behavior
    Command       — encapsulate request as object; supports undo/redo
    Iterator      — sequential access without exposing internal structure
    Template Method — skeleton of algorithm; subclasses fill in steps
    State         — object changes behavior based on internal state

================================================================================
SECTION 4 — SUMMARY COUNT
================================================================================

  Category                              |  E  |  M  |  H  | Total
  --------------------------------------|-----|-----|-----|-------
  Theory — Basics                       |  12 |   0 |   0 |    12
  Theory — Constructors & Destructors   |  18 |   0 |   0 |    18
  Theory — this pointer                 |   5 |   0 |   0 |     5
  Theory — Static members               |   6 |   0 |   0 |     6
  Theory — Friend functions             |   4 |   0 |   0 |     4
  Theory — const & mutable              |   5 |   0 |   0 |     5
  Theory — Operator overloading         |  10 |   0 |   0 |    10
  Theory — Inheritance & Polymorphism   |  17 |   0 |   0 |    17
  Theory — OOP Design Principles        |   5 |   0 |   0 |     5
  Coding — Easy                         |  23 |   0 |   0 |    23
  Coding — Medium                       |   0 |  32 |   0 |    32
  Coding — Hard                         |   0 |   0 |  10 |    10
  Coding — Output / Traps               |   3 |   4 |   0 |     7
  Design Patterns (reference)           |   — |   — |   — |    13
  --------------------------------------|-----|-----|-----|-------
  TOTAL                                 |  82 |  36 |  10 | 155+

================================================================================
SECTION 5 — COMPANY FOCUS GUIDE
================================================================================

  AMAZON / MICROSOFT / FLIPKART (SDE 1 & 2):
    Must know: All OOP pillars, virtual functions, vtable, virtual destructor,
    abstract classes, Singleton, Factory, LRU Cache design, Observer pattern.
    High frequency: LRU Cache, Singleton, Factory, Stack class, BankAccount.
    Focus: All medium coding + inheritance/polymorphism theory.

  GOOGLE / ATLASSIAN:
    Must know: SOLID principles, CRTP, type erasure, advanced templates,
    design patterns (all), Rule of Three/Five/Zero, const correctness.
    Focus: Hard coding + CRTP + type-erased wrappers + design pattern questions.

  ZOHO:
    Must know: All OOP basics deeply, all operator overloading, constructors,
    destructors, this pointer, copy constructor, virtual functions.
    Design: Library, ATM, Parking Lot, BankAccount.
    Focus: All theory + easy coding + medium OOP designs.

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    Must know: 4 pillars, class vs struct, constructors (all types), destructors,
    access specifiers, inheritance types, virtual functions, output traps.
    Focus: Theory sections + easy coding + output questions.

  SAMSUNG / SASKEN / EMBEDDED ROLES:
    Must know: vtable/vptr mechanism, overhead of virtual calls, CRTP for
    zero-overhead polymorphism, static member, const correctness.
    Focus: Inheritance theory (vtable, vptr) + CRTP + output traps.

  DOLAT CAPITAL / HFT FIRMS:
    Must know: CRTP (no vtable overhead), Rule of Zero, move semantics in classes,
    thread-safe Singleton, object pools, lock-free design, copy-on-write.
    Focus: CRTP + thread-safe patterns + hard coding (order book, thread-safe pool).

  PERSISTENT / NAGARRO / L&T INFOTECH (Mid-tier C++ roles):
    Must know: Full OOP theory, all design patterns, SOLID principles,
    Rule of Three/Five, operator overloading, const correctness, PIMPL.
    Focus: All theory + medium coding (design patterns) + OOP design systems.

================================================================================
END
================================================================================
