================================================================================
        INHERITANCE — COMPLETE QUESTION BANK
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
1A. CORE INHERITANCE THEORY
--------------------------------------------------------------------------------

  [T][ ] What is inheritance? What are the benefits of using it?
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What are the types of inheritance in C++? Explain each with an example.
         (Single, Multiple, Multilevel, Hierarchical, Hybrid)
         Asked at: TCS, Wipro, Infosys, L&T Infotech

  [T][ ] What is the difference between public, protected, and private inheritance?
         How does each affect the access of base class members in the derived class?
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What is the order of constructor and destructor calls in inheritance?
         (Base constructor first, Derived destructor first — reverse of construction)
         Asked at: Amazon, Microsoft, TCS, Zoho

  [T][ ] What members are NOT inherited from a base class?
         (Constructors, destructor, copy assignment operator, friend functions)
         Asked at: TCS, Wipro, Infosys, Zoho

  [T][ ] Can a derived class call a base class constructor explicitly? How?
         (Yes — using initializer list: Derived() : Base(args) { })
         Asked at: TCS, Wipro, Zoho

  [T][ ] What is constructor chaining in inheritance?
         Asked at: TCS, Wipro, Infosys

--------------------------------------------------------------------------------
1B. MULTIPLE INHERITANCE & DIAMOND PROBLEM
--------------------------------------------------------------------------------

  [T][ ] What is multiple inheritance? What are its pros and cons?
         Asked at: TCS, Wipro, Amazon, Infosys

  [T][ ] What is the diamond problem in multiple inheritance? How does C++ solve it?
         (Virtual base class: class B : virtual public A { })
         Asked at: TCS, Wipro, L&T Infotech, Persistent

  [T][ ] What is a virtual base class? When should you use it?
         Asked at: L&T Infotech, Persistent, Samsung

--------------------------------------------------------------------------------
1C. RELATIONSHIPS & DESIGN
--------------------------------------------------------------------------------

  [T][ ] What is the difference between aggregation and composition?
         (Composition: owned object cannot exist without owner;
          Aggregation: can exist independently)
         Asked at: TCS, Infosys, L&T Infotech

  [T][ ] What is the difference between aggregation, composition, and association?
         Asked at: TCS, Infosys, L&T Infotech, Persistent

  ★[T][ ] What is the difference between IS-A and HAS-A relationships?
          Give examples.
          (IS-A → inheritance; HAS-A → composition/aggregation)
          Asked at: TCS, Zoho, Infosys, Amazon

  ★[T][ ] What is the Liskov Substitution Principle (LSP)? Why is it important?
          (Derived objects must be safely substitutable for base objects)
          Asked at: Amazon, Microsoft, Google, Atlassian

  ★[T][ ] What is the difference between shallow copy and deep copy in inheritance?
          When can it cause problems?
          Asked at: TCS, Wipro, Zoho, Persistent

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Create a base class Animal and derived classes Dog and Cat.
             Each has its own speak() method (non-virtual first, then virtual).
             Show the difference in output between both approaches.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Design a class hierarchy: Vehicle -> ElectricVehicle -> Tesla.
             Show constructor/destructor call order with virtual destructors.
             Print a message in each constructor and destructor.
             Asked at: TCS, Wipro, L&T Infotech

  [C][ ] (E) Implement a multilevel inheritance: Person -> Employee -> Manager.
             Each class adds its own data members.
             Call base class constructor using initializer list.
             Asked at: TCS, Wipro, Infosys, Zoho

  ★[C][ ] (E) Demonstrate the diamond problem:
              Classes A, B, C, D where B and C inherit from A,
              and D inherits from both B and C.
              First show the problem (ambiguity), then fix with virtual inheritance.
              Asked at: TCS, Wipro, L&T Infotech, Persistent

  ★[C][ ] (E) Show how private, protected, and public inheritance differ.
              Create a base class with members of all three access types.
              Show what is accessible in derived class for each mode.
              Asked at: TCS, Wipro, Infosys

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Design an Employee hierarchy:
             Base: Employee with name, baseSalary, virtual calculateSalary()
             Derived: Manager (base + bonus), Developer (base + stockOptions)
             Demonstrate virtual dispatch via base pointer.
             Asked at: TCS, Wipro, Infosys, Zoho

  [C][ ] (M) Design a Shape base class -> Circle, Rectangle, Triangle derived.
             Each has area() and perimeter().
             Store in vector<Shape*>, compute total area of all shapes.
             Asked at: Amazon, TCS, Zoho, Wipro, Infosys

  [C][ ] (M) Design a BankAccount base class with deposit(), withdraw(), getBalance().
             Derive SavingsAccount (adds interest calculation),
             CurrentAccount (allows overdraft limit).
             Use virtual methods where appropriate.
             Asked at: TCS, Zoho, Wipro, Infosys

  [C][ ] (M) Implement a hierarchical inheritance:
             Shape -> 2DShape, 3DShape
             2DShape -> Circle, Square
             3DShape -> Sphere, Cube
             Each class has a virtual volume() or area() method.
             Asked at: Amazon, Adobe, Zoho

  ★[C][ ] (M) Demonstrate constructor and destructor call order for
              a 3-level hierarchy with base class pointer.
              Output should clearly show: which constructor/destructor runs and when.
              Show what happens when base destructor is NOT virtual (undefined behavior).
              Asked at: Amazon, Microsoft, TCS, Zoho

  ★[C][ ] (M) Implement a simple school system:
              Base: Person (name, age)
              Derived: Student (rollNo, marks[]), Teacher (subject, salary)
              Further derived: HeadBoy from Student (extra duties)
              Demonstrate multilevel + hierarchical inheritance together.
              Asked at: TCS, Wipro, Infosys, Zoho

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Design a Parking Lot system using OOP and inheritance:
             Abstract: Vehicle -> Bike, Car, Truck
             Abstract: ParkingSlot -> BikeSlot, CarSlot, TruckSlot
             ParkingFloor, ParkingLot, Ticket classes.
             Use polymorphism to assign correct slot type to vehicle type.
             Asked at: Amazon, Microsoft, Flipkart, Zoho

  ★[C][ ] (H) Design a Library Management System using inheritance:
              Abstract: LibraryItem -> Book, Magazine, DVD
              Member, Librarian, BorrowTransaction classes.
              Use virtual methods for checkout rules per item type.
              Asked at: Zoho, TCS, Infosys, Amazon

  ★[C][ ] (H) Design a Chess game using OOP and inheritance:
              Abstract: Piece -> King, Queen, Rook, Bishop, Knight, Pawn
              Each piece overrides virtual isValidMove(int fromRow, int fromCol,
                                                       int toRow, int toCol)
              Board class stores Piece* grid. Game class manages turns.
              Asked at: Amazon, Microsoft, Google, Atlassian

================================================================================
SUMMARY COUNT
================================================================================

  Category                              | E  | M  | H  | Total
  --------------------------------------|----|----|----|---------
  Theory — Core Inheritance             |  7 |  0 |  0 |     7
  Theory — Multiple Inheritance         |  3 |  0 |  0 |     3
  Theory — Relationships & Design       |  5 |  0 |  0 |     5
  Coding Easy                           |  5 |  0 |  0 |     5
  Coding Medium                         |  0 |  6 |  0 |     6
  Coding Hard                           |  0 |  0 |  3 |     3
  --------------------------------------|----|----|----|---------
  TOTAL                                 | 20 |  6 |  3 |    29

  ★ = 8 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI:
    → Types of inheritance, constructor/destructor order, access specifiers,
      multilevel hierarchy programs, diamond problem basics

  ZOHO:
    → IS-A vs HAS-A, BankAccount hierarchy, Employee hierarchy design,
      virtual base class

  AMAZON / MICROSOFT:
    → Liskov Substitution Principle, virtual destructor importance,
      Parking Lot design, Chess game design, deep vs shallow copy in inheritance

  GOOGLE / ATLASSIAN:
    → LSP in depth, Chess game OOP, complex hierarchy design with patterns

================================================================================
END
================================================================================
