================================================================================
        VARIABLES, DATA TYPES & OPERATORS — COMPLETE QUESTION BANK
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
1A. C++ BASICS & SYNTAX (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [T][ ] What is the difference between compiler and interpreter?
         Asked at: TCS, Wipro, Infosys

  [T][ ] What happens during compilation of a C++ program step by step?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the difference between #include <file> and #include "file"?
         Asked at: TCS, Wipro, L&T Infotech

  [T][ ] What is a header guard? Why is it needed?
         Asked at: L&T Infotech, Persistent

  [T][ ] What is the difference between declaration and definition?
         Asked at: TCS, Wipro, Infosys

  [T][ ] What does return 0 mean in main()?
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is undefined behavior in C++? Give an example.
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the difference between i++ and ++i? Which is preferred and why?
         Asked at: TCS, Wipro, Zoho, Amazon

  [T][ ] What is short-circuit evaluation in logical operators?
         Asked at: Amazon, Microsoft

  [T][ ] What is the difference between = and == ? (Most common bug for beginners)
         Asked at: TCS, Wipro, Infosys

  [T][ ] Explain operator precedence with an example.
         Asked at: TCS, Wipro, Zoho

  [T][ ] What is the difference between / and % operators?
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is integer overflow? How do you prevent it?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the difference between int, long, long long?
         Asked at: TCS, Wipro, Amazon

  [T][ ] When would you use unsigned int over int?
         Asked at: Dolat Capital, Samsung, Sasken

  [T][ ] What is the size of int on a 32-bit vs 64-bit system?
         Asked at: TCS, Wipro, Samsung, Sasken

  [T][ ] What is auto keyword in C++? When should you use it?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the difference between const int x and int const x?
         Asked at: Amazon, Microsoft, Persistent

  [T][ ] What is constexpr? How is it different from const?
         Asked at: Amazon, Microsoft, Google, Atlassian

  [T][ ] What is a magic number? Why should you avoid it?
         Asked at: TCS, Wipro

--------------------------------------------------------------------------------
1B. TYPE SYSTEM & CONVERSIONS (from all_in_one_question_1 — Part 2)
--------------------------------------------------------------------------------

  [T][ ] What are the storage classes in C/C++? Explain each.
         (auto, register, static, extern, mutable)
         Asked at: TCS, Wipro, Infosys, L&T Infotech, Mphasis

  [T][ ] What does static mean for a local variable?
         (retains value between calls, lives in data segment)
         Asked at: TCS, Wipro, L&T Infotech, Persistent

  [T][ ] What does static mean for a global variable?
         (limits visibility to that translation unit)
         Asked at: L&T Infotech, Sasken

  [T][ ] What is variable shadowing? Give an example.
         Asked at: Zoho, Persistent

  [T][ ] What is a namespace? How does it help avoid name collisions?
         Asked at: L&T Infotech, Persistent, Nagarro

  [T][ ] What is an anonymous namespace? How is it different from static?
         Asked at: Advanced C++ roles, Sasken

  [T][ ] What are the 4 types of casts in C++?
         (static_cast, dynamic_cast, const_cast, reinterpret_cast)
         Asked at: L&T Infotech, Persistent, Nagarro, Zoho

  [T][ ] When would you use static_cast vs reinterpret_cast?
         Asked at: Persistent, Nagarro, Samsung

  [T][ ] What is dynamic_cast? What is RTTI? What is its cost?
         Asked at: Persistent, Nagarro, advanced C++ roles

  [T][ ] What is const_cast? When is it safe to use?
         Asked at: Persistent, Nagarro

  [T][ ] What is implicit type conversion? What is explicit?
         Asked at: TCS, Wipro, L&T Infotech

  [T][ ] What is integer promotion in C?
         Asked at: Sasken, embedded roles

  [T][ ] What is the difference between signed and unsigned arithmetic?
         Asked at: Dolat Capital, Samsung, Sasken

  [T][ ] What happens when you compare signed and unsigned integers?
         (Dangerous implicit conversion — signed becomes unsigned)
         Asked at: Dolat Capital, Sasken, HFT firms

  [T][ ] What is narrowing conversion? How does C++11 handle it?
         Asked at: Persistent, Nagarro, Google, Atlassian

  [T][ ] What is std::numeric_limits? When would you use it?
         Asked at: Dolat Capital, Goldman Sachs, Quant roles

  [T][ ] What is NaN and Inf in floating point? How do you check for them?
         (std::isnan, std::isinf from <cmath>)
         Asked at: Dolat Capital, ICICI Securities, Quant roles

  [T][ ] What is the difference between float and double precision?
         How many decimal digits each can represent?
         Asked at: Dolat Capital, Edelweiss, Quant roles

  [T][ ] What is epsilon comparison for floats? Why not use == for floats?
         Asked at: Dolat Capital, Goldman Sachs, Quant roles

  [T][ ] What is endianness? What is little-endian vs big-endian?
         Asked at: Sasken, Samsung, Networking roles

  [T][ ] How do you check endianness of a machine in C?
         Asked at: Sasken, Samsung

--------------------------------------------------------------------------------
1C. ADDITIONAL THEORY (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [T][ ] What is the difference between signed and unsigned right shift?
         (C++ >> on signed int is implementation-defined; on unsigned it is logical)
         Asked at: Samsung, Dolat Capital, Sasken

  [T][ ] What is type promotion in C++? What happens when you add char + int?
         Asked at: TCS, L&T Infotech, Wipro

  [T][ ] Why is float comparison with == dangerous? How do you fix it?
         (floating-point representation error — use epsilon comparison)
         Asked at: Dolat Capital, Zoho, Amazon

  [T][ ] What is the difference between NaN and Infinity in floating point?
         How do you check for them in C++?
         Asked at: Dolat Capital, HFT firms

  [T][ ] What does the comma operator do in C++? Give a tricky example.
         Asked at: Google, Zoho

  [T][ ] What is integral promotion? What is the "usual arithmetic conversion"?
         Asked at: Sasken, Samsung

  [T][ ] What is the difference between char, signed char, and unsigned char?
         Are they all distinct types?
         Asked at: Samsung, Sasken, embedded roles

  [T][ ] Can you have a reference to a reference in C++? What about pointer to reference?
         Asked at: Advanced C++ roles, Google

  [T][ ] What is std::numeric_limits<int>::max() and when would you use it?
         Asked at: Amazon, Microsoft, competitive programming roles

  [T][ ] What is the difference between {}-initialization and ()-initialization?
         What is narrowing conversion?
         Asked at: Google, Atlassian, modern C++ roles

================================================================================
SECTION 2 — CONCEPTS TO LEARN (from all_in_one — Roadmap)
================================================================================

  PRIMITIVE TYPES:
    int       — whole numbers (-2B to 2B), 4 bytes
    float     — decimal, 4 bytes, ~7 digits precision
    double    — decimal, 8 bytes, ~15 digits precision
    char      — single character, 1 byte, uses ASCII
    bool      — true or false, 1 byte
    void      — no type (used in functions)

  TYPE MODIFIERS:
    short int   — 2 bytes
    long int    — 8 bytes
    long long   — 8 bytes (use for large numbers in DSA)
    unsigned    — no negative values, doubles positive range

  MODERN C++:
    auto x = 10;          — compiler infers type
    using ll = long long; — modern alias (preferred over typedef)

  CONSTANTS:
    const int MAX = 100;    — cannot be changed
    constexpr int SZ = 50;  — evaluated at compile time

  OPERATORS:
    Arithmetic:   +  -  *  /  %  ++  --
    Relational:   ==  !=  <  >  <=  >=
    Logical:      &&  ||  !
    Bitwise:      &  |  ^  ~  <<  >>
    Assignment:   =  +=  -=  *=  /=  %=
    Ternary:      condition ? value_if_true : value_if_false

  OPERATOR PRECEDENCE (high to low, simplified):
    ()  >  !  ~  ++  --  >  *  /  %  >  +  -  >  <<  >>
    >  <  <=  >=  >  ==  !=  >  &  >  ^  >  |  >  &&  >  ||  >  ?:  >  =

================================================================================
SECTION 3 — CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. EASY CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][x] (E) Check if a number is even or odd without using %
             Hint: use bitwise AND: n & 1
             Asked at: TCS, Wipro, Cognizant

  [C][x] (E) Swap two numbers without using a third variable
             Methods: arithmetic (a=a+b; b=a-b; a=a-b) and XOR (a^=b; b^=a; a^=b)
             Asked at: TCS, Infosys, Zoho

  [C][x] (E) Check if a number is a power of 2
             Hint: n > 0 && (n & (n-1)) == 0
             Asked at: Amazon, Adobe

  [C][x] (E) Count the number of set bits (1s) in an integer
             Methods: Brian Kernighan's (while n: count++, n &= n-1)
             Asked at: Microsoft, Samsung, Amazon

  [C][x] (E) Find the number of digits in an integer
             Asked at: TCS, Infosys

  [C][x] (E) Reverse the digits of a number (e.g. 1234 -> 4321)
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Check if a number is a palindrome (without converting to string)
             Asked at: Zoho, Infosys, Amazon

  [C][x] (E) Find the largest of three numbers without if-else
             Hint: use ternary operator
             Asked at: Capgemini, Cognizant

  [C][x] (E) Check if a number is even or odd using %
             Asked at: TCS, Wipro

  [C][x] (E) Find maximum of two numbers without using if (use ternary)
             Asked at: TCS, Wipro

  [C][x] (E) Check if a year is a leap year
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Swap two numbers without a third variable using XOR: a^=b; b^=a; a^=b
             Asked at: TCS, Infosys, Zoho

  [C][x] (E) Check if a number is a power of 2 using bitwise: n & (n-1) == 0
             Asked at: Amazon, Adobe, Samsung

  [C][x] (E) Count number of set bits (1s) in an integer using bit shifting
             Asked at: Microsoft, Samsung, Amazon

  [C][x] (E) Print size of all data types using sizeof()
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Temperature converter: Celsius to Fahrenheit
             Asked at: TCS, Wipro

  [C][x] (E) Simple interest calculator: SI = (P * R * T) / 100
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Area and perimeter of circle, rectangle, triangle
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Read name and age, print a greeting sentence
             (Practice: cin, cout, getline)
             Asked at: TCS, Wipro

  [C][x] (E) Read two numbers, print their sum, difference, product, quotient
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Read a full sentence using getline and print it reversed word by word
             Asked at: TCS, Wipro

--------------------------------------------------------------------------------
3B. MEDIUM CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][x] (M) Given an integer, find the highest power of 2 less than or equal to it
             Asked at: Samsung

  [C][x] (M) Without using multiplication, divide or mod, check if n is divisible by 4
             Hint: (n & 3) == 0
             Asked at: Google

--------------------------------------------------------------------------------
3C. EASY CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][x] (E) Given a = 5, b = 3, print a/b and (float)a/b. Explain the difference.
             Expected output: 1   1.666...
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Find the sum of all digits of a number without using strings
             e.g. 4567 -> 4+5+6+7 = 22
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Without using any variable, print numbers 1 to 5 using a for loop
             where loop variable i starts at 0 — no extra int declaration
             Asked at: Wipro, Infosys

  [C][x] (E) Given two integers, check if exactly one of them is negative
             Hint: use XOR on sign bits — (a < 0) ^ (b < 0)
             Asked at: Dolat Capital, Samsung

  [C][x] (E) Check if a number is divisible by both 3 and 7 simultaneously
             Asked at: TCS, Capgemini

--------------------------------------------------------------------------------
3D. MEDIUM CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][x] (M) Multiply a number by 7 using only bitwise operators and addition
             Hint: x*7 = (x << 3) - x
             Asked at: Samsung, Dolat Capital

  [C][ ] (M) Add 1 to a number without using + operator
             Hint: use two's complement: -(-x-1) or ~x and negate, or loop with XOR+carry
             Asked at: Amazon, Samsung

  [C][ ] (M) Find the two's complement of a number manually in code
             Asked at: Sasken, Samsung, Dolat Capital

  [C][ ] (M) Determine the sign of a product of two numbers without multiplying
             (check signs of both numbers using bit shift)
             Asked at: Dolat Capital, Samsung

  [C][ ] (M) Given integer x, check if x and x+1 differ only in the last two bits
             Asked at: Competitive Programming, Dolat Capital

--------------------------------------------------------------------------------
3E. EASY CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][x] (E) Without any if/else/ternary, print 1 if a > b, -1 if a < b, 0 if equal.
             Hint: (a > b) - (a < b)
             Asked at: Samsung, Dolat Capital

  [C][x] (E) Check if two floats are equal up to 6 decimal places.
             Use: fabs(a - b) < 1e-6
             Asked at: Zoho, Dolat Capital

  [C][x] (E) Without any loop, find the absolute value of an integer without abs().
             Use: (x < 0) ? -x : x  OR  (x ^ (x >> 31)) - (x >> 31)
             Asked at: Samsung, Sasken

  [C][x] (E) Read two integers a and b. Print their average WITHOUT overflow.
             Hint: a/2 + b/2 + (a%2 + b%2)/2
             Asked at: Amazon, Google

  [C][x] (E) Given 3 bits x, y, z, compute the majority bit (1 if at least 2 are 1).
             Hint: (x & y) | (y & z) | (x & z)
             Asked at: Dolat Capital, competitive programming

--------------------------------------------------------------------------------
3F. MEDIUM CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (M) Print the binary representation of a float using union hack.
             (Use union { float f; unsigned int i; } — observe bits)
             Asked at: Sasken, Samsung, HFT firms

  [C][ ] (M) Without using division or modulo, check if N is divisible by 8.
             Hint: (n & 7) == 0
             Asked at: Dolat Capital, Samsung

  [C][ ] (M) Compute x * 9 using only shift and addition.
             Hint: (x << 3) + x
             Asked at: Dolat Capital, Samsung, Sasken

  [C][ ] (M) Given an integer n, flip all bits below and including the highest set bit.
             Asked at: Competitive programming, Samsung

  [C][ ] (M) Implement a function that returns the sign of (a - b) without subtraction.
             Asked at: Dolat Capital, HFT firms

================================================================================
SUMMARY COUNT
================================================================================

  Category                       | E  | M  | H  | Total
  -------------------------------|----|----|----|---------
  Theory — C++ Basics & Syntax   | 20 |  0 |  0 |   20
  Theory — Type System           | 21 |  0 |  0 |   21
  Theory — Additional (Part 4)   | 10 |  0 |  0 |   10
  Coding — Part 1 (q)            | 21 |  2 |  0 |   23
  Coding — Part 3 (q_2)          |  5 |  5 |  0 |   10
  Coding — Part 4 (q_3)          |  5 |  5 |  0 |   10
  -------------------------------|----|----|----|---------
  TOTAL                          | 51 | 12 |  0 |   74

================================================================================
END
================================================================================
