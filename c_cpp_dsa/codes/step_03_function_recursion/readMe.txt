================================================================================
        FUNCTIONS & RECURSION — COMPLETE QUESTION BANK
        Compiled from all 4 files (roadmap + 3 question banks)
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
1A. CORE FUNCTIONS THEORY (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [T][ ] What is the difference between pass by value and pass by reference?
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is function overloading? Can you overload based on return type alone?
         Asked at: TCS, Wipro, Zoho, Amazon

  [T][ ] What is a default argument? Where must it appear in the parameter list?
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is an inline function? When does the compiler ignore the inline hint?
         Asked at: L&T Infotech, Persistent, Samsung

  [T][ ] What is recursion? What are its advantages and disadvantages vs iteration?
         Asked at: TCS, Wipro, Amazon, Infosys

  [T][ ] What is tail recursion? Why is it better? Does C++ optimize it?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is stack overflow in the context of recursion?
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is the difference between local and global variables?
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is a static local variable? How long does it live?
         Asked at: TCS, Wipro, L&T Infotech, Persistent

  [T][ ] Can a function return multiple values in C++? How?
         (via pair/tuple, out-parameters by reference, struct)
         Asked at: TCS, Wipro, Amazon, Zoho

--------------------------------------------------------------------------------
1B. ADVANCED FUNCTIONS THEORY (from all_in_one_question_1 — Part 2)
--------------------------------------------------------------------------------

  [T][ ] What is a function pointer? Show the syntax.
         (int (*fp)(int, int);)
         Asked at: L&T Infotech, Persistent, Sasken

  [T][ ] What is a callback function? Give a real-world example.
         Asked at: L&T Infotech, Persistent, Nagarro

  [T][ ] What is std::function? How is it different from a raw function pointer?
         Asked at: Persistent, Nagarro, Adobe

  [T][ ] What is std::bind? Give an example.
         Asked at: Persistent, Nagarro

  [T][ ] What is a functor (function object)? Why use it instead of a regular function?
         Asked at: L&T Infotech, Persistent, Sasken

  [T][ ] What is a lambda? How does the capture clause work?
         Explain [=], [&], [x], [&x], [this]
         Asked at: Persistent, Nagarro, Adobe, Amazon

  [T][ ] What is the difference between [=] and [&] in lambda capture?
         Asked at: Persistent, Nagarro

  [T][ ] Can a lambda be recursive? How do you achieve it?
         Asked at: Advanced C++ roles

  [T][ ] What is memoization using C++ lambdas?
         Asked at: Dolat Capital, Goldman Sachs

  [T][ ] What is the return type deduction for functions in C++14?
         (auto keyword for return type)
         Asked at: Persistent, Nagarro

  [T][ ] What is the difference between a macro and an inline function?
         Asked at: L&T Infotech, Persistent, Nagarro

  [T][ ] What is the difference between deep copy and shallow copy?
         (relevant when passing objects to functions — copy constructor behavior)
         Asked at: Zoho, TCS, Wipro, Persistent

--------------------------------------------------------------------------------
1C. FRESH RECURSION & FUNCTION THEORY (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [T][ ] Can you call a virtual function from a constructor? What happens?
         (It calls the base class version — vtable not yet pointing to derived)
         Asked at: Amazon, Microsoft, Adobe

  [T][ ] What is the difference between deep recursion and tail recursion?
         Does GCC/Clang optimize tail calls in C++?
         Asked at: Zoho, Persistent, Google

  [T][ ] What is memoization vs tabulation? When do you prefer each?
         Asked at: Amazon, Flipkart, Swiggy

  [T][ ] What is a pure function? What is a side effect? Why does this matter?
         Asked at: Google, Atlassian, functional-style interview rounds

  [T][ ] Explain the difference between call stack and call heap.
         Asked at: L&T Infotech, TCS, Persistent

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. EASY CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][x] (E) Fibonacci using recursion
             Asked at: TCS, Wipro, Amazon, Infosys

  [C][x] (E) Factorial using recursion
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Sum of digits of a number using recursion
             e.g. 1234 -> 1+2+3+4 = 10
             Asked at: Wipro, Cognizant

  [C][x] (E) Power(x, n) using recursion — x^n = x * pow(x, n-1)
             Asked at: Amazon, Microsoft

  [C][x] (E) Check if a string is palindrome using recursion
             Asked at: Amazon, Zoho

--------------------------------------------------------------------------------
2B. EASY CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][x] (E) Write a function that returns the Nth Fibonacci term using recursion
             Sequence: 1, 1, 2, 3, 5, 8, 13...
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Write a recursive function to compute sum of first N odd numbers
             Asked at: TCS, Wipro

  [C][ ] (E) Write a function that counts how many times digit d appears in number n
             e.g. countDigit(112233, 2) = 2
             Asked at: Wipro, Capgemini

  [C][ ] (E) Write a function that returns true if a number is a perfect number
             (sum of proper divisors equals the number)
             Asked at: Zoho, Wipro

  [C][ ] (E) Write a recursive function to find the maximum element in an array
             Asked at: TCS, Wipro, Infosys

--------------------------------------------------------------------------------
2C. EASY CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (E) Recursive function to print digits of a number from left to right
             (without reversing — use recursion order cleverly)
             Asked at: Wipro, Cognizant

  [C][ ] (E) Recursive: check if N is prime
             Asked at: Wipro, TCS

  [C][ ] (E) Recursive: find the minimum element of an array
             Asked at: Infosys, Capgemini

  [C][ ] (E) Recursive: count number of zeros in an integer
             e.g. 1001020 -> 3 zeros
             Asked at: Wipro, Cognizant

  [C][ ] (E) Recursive multiplication without * operator:
             multiply(a, b) = a + multiply(a, b-1)
             Asked at: TCS, Wipro

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. MEDIUM CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][ ] (M) Tower of Hanoi — print all the moves for N disks
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Print all permutations of a string using recursion
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Generate all subsets of a set {1, 2, ..., N} using recursion
             Asked at: Amazon, Google, Atlassian

  [C][ ] (M) Count ways to climb N stairs (1 or 2 steps at a time)
             Solve using recursion first, then convert to DP
             Asked at: Amazon, Microsoft, Google, Flipkart

--------------------------------------------------------------------------------
3B. MEDIUM CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][ ] (M) Write a function that computes nCr (binomial coefficient) using
             recursion with memoization to avoid recomputation
             nCr = nC(r-1) + (n-1)C(r-1), base: nC0 = nCn = 1
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Implement a function that flattens a nested vector<vector<int>>
             into a single vector<int> using recursion
             Asked at: Adobe, Atlassian

  [C][ ] (M) Write a recursive function to generate all binary strings of length N
             e.g. N=2: 00, 01, 10, 11
             Asked at: Amazon, Microsoft

  [C][ ] (M) Implement recursive binary search and count the number of recursive
             calls made during each search
             Asked at: TCS, Amazon

  [C][ ] (M) Write a function f(n) that returns number of ways to tile a 2×N board
             using 2×1 dominoes (same as Fibonacci recurrence)
             Asked at: Amazon, Microsoft, Goldman Sachs

  [C][ ] (M) Implement mutual recursion:
             isEven(n) calls isOdd(n-1), isOdd(n) calls isEven(n-1)
             Asked at: Zoho, Wipro

  [C][ ] (M) Given N, print all numbers from 1 to N using recursion, where
             numbers divisible by 3 print "Fizz", by 5 print "Buzz",
             by both print "FizzBuzz"
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Write a recursive function to check if an array is sorted in
             ascending order
             Asked at: Amazon, Infosys, Wipro

--------------------------------------------------------------------------------
3C. MEDIUM CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (M) Print all binary strings of length N that have no consecutive 1s.
             Use recursion. Also count them (answer is a Fibonacci number!)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Given N, find all ways to express N as an ordered sum of 1s and 2s
             (stair climbing counting variant — print actual paths, not just count)
             Asked at: Amazon, Flipkart, Zoho

  [C][ ] (M) Recursive function to sort an array using insertion sort style
             (sort first N-1 elements recursively, then insert the Nth element)
             Asked at: Amazon campus

  [C][ ] (M) Recursive: given a string, print all unique permutations
             (handle duplicate characters correctly)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Recursive: find the kth symbol in the grammar
             Row 1: "0"   Row 2: "01"   Row 3: "0110"   Row 4: "01101001"
             Rule: 0 -> 01, 1 -> 10 (LeetCode 779)
             Asked at: Google, Atlassian

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
4A. HARD CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][ ] (H) Flatten a nested recursive structure into a flat list
             Asked at: Atlassian, Adobe

--------------------------------------------------------------------------------
4B. HARD CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][ ] (H) Implement memoized recursion for computing number of ways to reach
             the Nth stair where you can climb 1, 2, or 3 steps.
             Count all distinct ways, then reduce space to O(1).
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (H) Josephus Problem: N people in a circle, every Kth person is eliminated.
             Find the position of the last survivor.
             Recurrence: josephus(n, k) = (josephus(n-1, k) + k) % n
             Asked at: Goldman Sachs, Google, Amazon

  [C][ ] (H) Write a function to compute all distinct ways to express N as
             an ordered sum of positive integers (compositions of N)
             e.g. 3: 1+1+1, 1+2, 2+1, 3
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Implement a recursive descent parser for arithmetic expressions
             with +, -, *, / and parentheses
             Asked at: Google, Microsoft, Adobe

  [C][ ] (H) Given a number N, find all expressions formed by inserting + or -
             between the digits of N that evaluate to 0
             e.g. 123: 1+2-3=0
             Asked at: Google, Amazon

--------------------------------------------------------------------------------
4C. HARD CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (H) Flood fill on a grid using recursion (DFS without explicit stack)
             Input: matrix, source (r, c), old color, new color
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (H) Expression evaluation using recursion:
             Parse a string like "2*(3+4)-1" and evaluate it
             (Implement recursive descent parser)
             Asked at: Google, Atlassian, Adobe

  [C][ ] (H) Recursive: given N, find all combinations that sum to N
             using integers 1 to 9, each used at most once
             Asked at: Amazon, Google

  [C][ ] (H) Count the number of structurally unique BSTs with N nodes
             (Catalan number — implement both recursive and DP solutions)
             Asked at: Microsoft, Amazon

  [C][ ] (H) Solve the cryptarithmetic puzzle SEND + MORE = MONEY
             using backtracking (recursive exhaustive search)
             Asked at: Google, Atlassian

================================================================================
SUMMARY COUNT
================================================================================

  Category                                | E  | M  | H  | Total
  ----------------------------------------|----|----|----|-------
  Theory — Core Functions (Part 1)        | 10 |  0 |  0 |   10
  Theory — Advanced Functions (Part 2)    | 12 |  0 |  0 |   12
  Theory — Fresh Recursion (Part 4)       |  5 |  0 |  0 |    5
  Coding Easy — Part 1 (q)                |  5 |  0 |  0 |    5
  Coding Easy — Part 3 (q_2)              |  5 |  0 |  0 |    5
  Coding Easy — Part 4 (q_3)              |  5 |  0 |  0 |    5
  Coding Medium — Part 1 (q)              |  0 |  4 |  0 |    4
  Coding Medium — Part 3 (q_2)            |  0 |  8 |  0 |    8
  Coding Medium — Part 4 (q_3)            |  0 |  5 |  0 |    5
  Coding Hard — Part 1 (q)                |  0 |  0 |  1 |    1
  Coding Hard — Part 3 (q_2)              |  0 |  0 |  5 |    5
  Coding Hard — Part 4 (q_3)              |  0 |  0 |  5 |    5
  ----------------------------------------|----|----|----|-------
  TOTAL                                   | 42 | 17 | 11 |   70

================================================================================
END
================================================================================
