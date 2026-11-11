================================================================================
     CONTROL FLOW — CONDITIONALS & LOOPS — COMPLETE QUESTION BANK
     Compiled from all 5 files (roadmap + 4 question banks)
     No duplicates | Theory + Coding | All difficulties
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
SECTION 1 — CONCEPTS TO LEARN (from all_in_one — Roadmap)
================================================================================

--------------------------------------------------------------------------------
1A. CONTROL FLOW — CONDITIONALS
--------------------------------------------------------------------------------

  SYNTAX:
    if (condition) { ... }
    if (...) { ... } else { ... }
    if (...) { ... } else if (...) { ... } else { ... }

    switch (variable) {
      case val1: ...; break;
      case val2: ...; break;
      default:   ...;
    }

  KEY RULES:
    - switch works with int, char — NOT with float or string
    - Always use break; in switch cases unless you want fall-through
    - Nested if-else for complex conditions

--------------------------------------------------------------------------------
1B. CONTROL FLOW — LOOPS
--------------------------------------------------------------------------------

  FOR LOOP:
    for (init; condition; update) { ... }
    for (int i = 0; i < n; i++) { ... }

  WHILE LOOP:
    while (condition) { ... }

  DO-WHILE LOOP:
    do { ... } while (condition);
    Executes body at least once even if condition is false.

  RANGE-BASED FOR (Modern C++):
    for (int x : arr) { ... }

  CONTROL KEYWORDS:
    break    — exits loop immediately
    continue — skips current iteration, goes to next

  NESTED LOOPS:
    Loop inside loop — used in matrix traversal, pattern printing.

================================================================================
SECTION 2 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. CONDITIONALS THEORY (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [T][ ] What is the difference between if-else and switch statement?
         When would you prefer switch over if-else?
         Asked at: TCS, Wipro, Zoho, Infosys

  [T][ ] What is fall-through in switch? How do you prevent it?
         Asked at: TCS, Wipro, Infosys

  [T][ ] Can switch work with strings in C++? Why or why not?
         Asked at: TCS, Wipro, Zoho

  [T][ ] What is a ternary operator? How is it different from if-else?
         Asked at: TCS, Wipro, Capgemini

  [T][ ] What is short-circuit evaluation? How does it affect conditionals?
         (&&: if left is false, right not evaluated; ||: if left is true, right not evaluated)
         Asked at: Amazon, Microsoft, Zoho

  [T][ ] What is the difference between = and == in a conditional?
         Why is if (x = 5) a bug?
         Asked at: TCS, Wipro, Infosys

  [T][ ] Can you use a float or double in a switch statement? Why?
         Asked at: TCS, Wipro

  [T][ ] What happens if you forget break in a switch case?
         What is intentional fall-through and when is it useful?
         Asked at: TCS, Zoho, Amazon

  [T][ ] What is a dangling else problem? How does C++ resolve it?
         (else always binds to nearest if)
         Asked at: Amazon, Microsoft, Adobe

--------------------------------------------------------------------------------
2B. LOOPS THEORY (from all_in_one_question — Part 1 & Part 2 Advanced)
--------------------------------------------------------------------------------

  [T][ ] What is the difference between for, while, and do-while loops?
         When would you use each?
         Asked at: TCS, Wipro, Infosys, Zoho

  [T][ ] What is the difference between break and continue?
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is an infinite loop? How do you create one intentionally?
         How do you exit it?
         Asked at: TCS, Wipro, Amazon

  [T][ ] Why does do-while execute at least once?
         Give a real use-case where do-while is the right choice.
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is the range-based for loop? How does it work internally?
         (Requires begin() and end() iterators)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the time complexity of a single loop? A nested loop?
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is loop invariant? How does it help prove loop correctness?
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the difference between pre-increment (++i) and post-increment (i++)
         in a loop condition? Does it matter for performance?
         Asked at: TCS, Wipro, Amazon, Adobe

  [T][ ] Can you modify the loop variable inside a for loop body?
         What are the risks?
         Asked at: TCS, Wipro

  [T][ ] What is an off-by-one error? Give an example in a loop.
         Asked at: Amazon, Microsoft, Adobe

--------------------------------------------------------------------------------
2C. ADVANCED LOOPS THEORY (from all_in_one_question_1 — Part 2)
--------------------------------------------------------------------------------

  [T][ ] What is branch prediction? How can unpredictable branches (if/else)
         hurt performance in tight loops?
         Asked at: Dolat Capital, HFT firms, Samsung, Sasken

  [T][ ] What is the likely/unlikely hint in GCC? (__builtin_expect)
         When would you use it?
         Asked at: Dolat Capital, HFT firms

  [T][ ] What is loop unrolling? When does the compiler do it automatically?
         Asked at: Dolat Capital, Sasken, Samsung

================================================================================
SECTION 3 — CODING QUESTIONS — CONDITIONALS
================================================================================

--------------------------------------------------------------------------------
3A. EASY — CONDITIONALS (from all_in_one — Roadmap)
--------------------------------------------------------------------------------

  [C][x] (E) Grade calculator — read marks and print grade
             (90+ = A, 80+ = B, 70+ = C, 60+ = D, below = F)
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][x] (E) Calculator: read two numbers and an operator (+, -, *, /)
             using switch statement
             Asked at: TCS, Wipro, Zoho

  [C][x] (E) Check if a triangle is valid given 3 sides
             (sum of any two sides must be greater than the third)
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Check if a character is vowel or consonant using switch
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Find the largest of three numbers using if-else
             Asked at: TCS, Wipro, Infosys, Capgemini

================================================================================
SECTION 4 — CODING QUESTIONS — LOOPS & PATTERNS
================================================================================

--------------------------------------------------------------------------------
4A. EASY — LOOPS & PATTERNS (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][x] (E) Print Fibonacci series up to N terms
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][x] (E) Check if a number is prime
             Asked at: TCS, Zoho, Capgemini, Wipro

  [C][x] (E) Find all prime numbers up to N using nested loops (brute force first)
             Asked at: TCS, Wipro, Infosys

  [C][~] (E) Find all prime numbers up to N — Sieve of Eratosthenes
             Asked at: Amazon, Microsoft, Google

  [C][x] (E) Find factorial of N using a loop (iterative)
             Asked at: TCS, Infosys, Cognizant

  [C][x] (E) Print the following pattern for N=4:
             *
             **
             ***
             ****
             Asked at: TCS, Wipro, Capgemini, Zoho

  [C][x] (E) Print the inverted triangle pattern for N=4:
             ****
             ***
             **
             *
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Print the right-aligned triangle pattern for N=4:
                *
               **
              ***
             ****
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Print diamond pattern (combination of two triangles)
             Asked at: Wipro, Capgemini, Infosys

  [C][x] (E) Print hollow square pattern of size N using *
             Asked at: TCS, Wipro

  [C][ ] (E) Print Pascal's triangle for N rows
             Asked at: Amazon, Microsoft, TCS

  [C][x] (E) Check Armstrong number (e.g. 153 = 1^3 + 5^3 + 3^3)
             Asked at: TCS, Capgemini

  [C][x] (E) Find GCD of two numbers using Euclidean algorithm (loop version)
             Asked at: Amazon, Microsoft, Zoho

  [C][x] (E) Find LCM of two numbers
             Asked at: TCS, Wipro

  [C][x] (E) Print 1 to N
             Asked at: TCS, Wipro

  [C][x] (E) Print multiplication table of a given number
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Sum of digits of a number (e.g. 1234 -> 1+2+3+4 = 10)
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Reverse a number (e.g. 1234 -> 4321)
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Check if a number is palindrome using loop
             Asked at: TCS, Wipro, Zoho

  [C][x] (E) Find factorial of N using a loop
             Asked at: TCS, Infosys, Cognizant

--------------------------------------------------------------------------------
4B. MEDIUM — LOOPS & PATTERNS (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][x] (M) Print all prime factors of a number
             Asked at: Amazon, Flipkart

  [C][x] (M) Find sum of series: 1 + 1/2 + 1/3 + ... + 1/N
             Asked at: Capgemini, Wipro

--------------------------------------------------------------------------------
4C. EASY — LOOPS & PATTERNS (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][x] (E) Print the following right-aligned number pattern for N=4:
                1
               12
              123
             1234
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Print alternating 0 and 1 in a single row for N elements
             e.g. N=6 output: 0 1 0 1 0 1
             Asked at: TCS, Wipro

  [C][x] (E) Print Floyd's triangle:
             1
             2 3
             4 5 6
             7 8 9 10
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Find the sum of all even numbers between 1 and N (inclusive)
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Find the smallest divisor of N greater than 1
             (can be used as the basis of a prime check)
             Asked at: TCS, Infosys

--------------------------------------------------------------------------------
4D. MEDIUM — LOOPS & PATTERNS (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][x] (M) Print all perfect numbers between 1 and N
             A perfect number = sum of its proper divisors (e.g. 6 = 1+2+3)
             Asked at: Wipro, Zoho, Capgemini

  [C][x] (M) Find all numbers between 1 and N that are both prime AND palindrome
             Asked at: Wipro, Infosys

  [C][x] (M) Print the multiplication table of numbers 1 to N in matrix form
             (N rows and N columns)
             Asked at: Capgemini, TCS

  [C][x] (M) Find all pairs (i, j) where i < j and arr[i] > arr[j] — brute force O(N^2)
             (Count inversions — brute force version before learning merge sort)
             Asked at: TCS, Infosys, Wipro

  [C][x] (M) Check if N is a perfect square without using sqrt() — use loop only
             Asked at: Amazon, TCS, Wipro

--------------------------------------------------------------------------------
4E. EASY — LOOPS & PATTERNS (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (E) Print a hollow diamond pattern for N=4
             Asked at: TCS, Infosys, Capgemini

  [C][x] (E) Find sum of all numbers from 1 to N divisible by 3 OR 5
             (Classic FizzBuzz sum variant)
             Asked at: Google, Amazon campus

  [C][~] (E) Print the number spiral matrix for N=4 clockwise starting from 1
             Asked at: Amazon, Zoho

--------------------------------------------------------------------------------
4F. MEDIUM — LOOPS & PATTERNS (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][x] (M) Print all numbers from 1 to N that are perfect squares
             Without using sqrt() — use only loops
             Asked at: TCS, Wipro, Capgemini

  [C][x (M) Find the Nth term in series: 1, 3, 6, 10, 15, 21 (triangular numbers)
             In O(1). Hint: N*(N+1)/2
             Asked at: Capgemini, Wipro

  [C][x] (M) FizzBuzz with a twist: print "Fizz" for multiples of 3, "Buzz" for 5,
             "FizzBuzz" for both, and "Jazz" for multiples of 7 too
             Asked at: Amazon, Flipkart (common warm-up)

  [C][ ] (M) Print all lucky numbers up to N
             (Start with natural numbers; repeatedly delete every kth number
             where k is the value at the kth position — sieve-like process)
             Asked at: Competitive programming, Samsung

  [C][x] (M) Without math.h, compute floor(log2(N)) for a positive integer N
             Hint: count how many times you can right-shift before reaching 0
             Asked at: Dolat Capital, Samsung

================================================================================
SECTION 5 — COMPLETE PROBLEM LIST (from all_in_one — Roadmap)
================================================================================

  These are the programs the roadmap says you MUST write before moving on:

  CONDITIONALS:
  [C][x] Grade calculator (90+=A, 80+=B, 70+=C, 60+=D, else F)
  [C][x] Calculator using switch (+, -, *, /)
  [C][x] Check if triangle is valid given 3 sides
  [C][x] Check if character is vowel or consonant using switch
  [C][x] Find the largest of three numbers

  LOOPS:
  [C][x] Print 1 to N
  [C][x] Print multiplication table of a number
  [C][x] Sum of digits of a number (1234 -> 10)
  [C][x] Reverse a number (1234 -> 4321)
  [C][x] Check if a number is palindrome
  [C][x] Print all primes up to N (nested loops, then optimize)
  [C][x] Print left-aligned, right-aligned, and inverted star patterns
  [C][x] Fibonacci series up to N terms
  [C][x] Find factorial of N using a loop

================================================================================
SUMMARY COUNT
================================================================================

  Category                          |  E  |  M  |  H  | Total
  ----------------------------------|-----|-----|-----|-------
  Theory — Conditionals             |  9  |  0  |  0  |   9
  Theory — Loops (basic)            | 10  |  0  |  0  |  10
  Theory — Loops (advanced perf)    |  3  |  0  |  0  |   3
  Coding — Conditionals (roadmap)   |  5  |  0  |  0  |   5
  Coding — Loops (Part 1)           | 20  |  2  |  0  |  22
  Coding — Loops (Part 3)           |  5  |  5  |  0  |  10
  Coding — Loops (Part 4)           |  3  |  5  |  0  |   8
  ----------------------------------|-----|-----|-----|-------
  TOTAL                             | 55  | 12  |  0  |  67

================================================================================
END
================================================================================
