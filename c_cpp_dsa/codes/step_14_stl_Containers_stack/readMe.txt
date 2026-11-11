================================================================================
        STL — STACK (std::stack) COMPLETE QUESTION BANK
        Covers: std::stack internals + classic stack algorithm problems
        Compiled from all_in_one, all_in_one_question_1/2/3/4
        + Real interview questions from Google, Amazon, Microsoft,
          Flipkart, Adobe, Goldman Sachs, Zoho, TCS, Wipro & more
        No duplicates | Theory + Coding | All difficulties
        ★ = Added from real interviews not in source files
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding
  ★  = Added question (real interview, not in source files)

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. std::stack INTERNALS & DESIGN
--------------------------------------------------------------------------------

  [T][ ] What is a stack? What are its defining operations?
         (LIFO — Last In First Out; push, pop, top, empty, size)
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is std::stack in C++? Is it a container or a container adaptor?
         (Container adaptor — wraps another container, default is std::deque)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What is the default underlying container of std::stack?
         What other containers can be used as the underlying container?
         (Default: std::deque; alternatives: std::vector, std::list)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] What is the time complexity of push, pop, top, empty on std::stack?
         (All O(1))
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is the difference between stack and queue?
         (Stack: LIFO — top is last inserted;
          Queue: FIFO — front is first inserted)
         Asked at: TCS, Wipro, Infosys, Zoho, Amazon

  [T][ ] What is the call stack? How is it related to function calls and recursion?
         (Each function call pushes a stack frame: return address, local vars, params;
          recursion = deep call stack; stack overflow = call stack exhausted)
         Asked at: Amazon, TCS, Wipro, L&T Infotech

  [T][ ] What is the difference between stack (data structure) and call stack?
         (Data structure: explicit, programmer-controlled;
          Call stack: implicit, managed by OS/runtime for function calls)
         Asked at: TCS, Wipro, L&T Infotech

  [T][ ] How would you implement a stack using two queues?
         (Method 1: push O(N) — enqueue to q2, transfer q1 to q2, swap;
          Method 2: pop O(N) — transfer all to q2 except last, swap)
         Asked at: Amazon, Microsoft, Google

  [T][ ] When would you choose to use an explicit stack instead of recursion?
         (When recursion depth is too large → stack overflow risk;
          or when you need more control over the traversal order)
         Asked at: Amazon, Microsoft

  [T][ ] What is a monotonic stack? What types of problems does it solve?
         (Stack where elements are always in increasing or decreasing order;
          solves: next greater/smaller element, histogram area, span problems)
         Asked at: Amazon, Google, Flipkart, competitive programming

  ★[T][ ] Can std::stack be iterated? Why or why not?
          (No — stack does not expose iterators; only top() is accessible)
          Asked at: TCS, Wipro, Persistent

  ★[T][ ] What is the difference between std::stack<int, std::vector<int>>
          and std::stack<int>?
          (First uses vector as underlying container; second uses deque by default;
           vector-backed stack: more cache-friendly, no push_front needed)
          Asked at: Persistent, Nagarro, advanced C++ roles

  ★[T][ ] Why is a vector-backed stack (std::stack<T, vector<T>>) often faster
          than the default deque-backed stack in practice?
          (Vector is contiguous — better cache locality; deque has extra indirection)
          Asked at: Dolat Capital, HFT firms, Google

--------------------------------------------------------------------------------
1B. MONOTONIC STACK — THEORY
--------------------------------------------------------------------------------

  ★[T][ ] What is an increasing monotonic stack vs a decreasing monotonic stack?
          When do you use each?
          (Increasing: useful for next smaller element;
           Decreasing: useful for next greater element)
          Asked at: Amazon, Google, Flipkart, Goldman Sachs

  ★[T][ ] How does the "contribution technique" with monotonic stack work?
          (For each element, find its span as the minimum/maximum in some subarray;
           multiply by count of subarrays where it contributes — used in sum of
           subarray minimums/maximums)
          Asked at: Amazon, Google, Goldman Sachs

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. BASIC STACK OPERATIONS & IMPLEMENTATION
--------------------------------------------------------------------------------

  [C][ ] (E) Implement a stack using a singly linked list (no array).
             push, pop, top, isEmpty — all O(1).
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Implement a stack using an array with overflow/underflow handling.
             Asked at: TCS, Wipro, Infosys, Zoho

  [C][ ] (E) Reverse a string using a stack.
             Push all characters, then pop to get reversed string.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Valid parentheses — check if (){}[] are balanced.
             Push opening brackets; pop and match on closing.
             Asked at: Amazon, Microsoft, Google, Adobe, Zoho, Flipkart
             (Most commonly asked stack question!)

  [C][ ] (E) Evaluate a postfix (Reverse Polish Notation) expression.
             "2 3 1 * + 9 -" => -4
             Push numbers; on operator, pop two, compute, push result.
             Asked at: Amazon, Zoho, TCS, Wipro

  [C][ ] (E) Convert an infix expression to postfix using stack.
             Handle operator precedence and parentheses.
             Asked at: TCS, Wipro, Zoho, Amazon

  [C][ ] (E) Design a stack that returns minimum in O(1).
             Use auxiliary min-stack or store (value, current_min) pairs.
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (E) Find the celebrity in a party of N people using a stack.
             Celebrity: everyone knows them, they know no one.
             Stack-based elimination — O(N) time O(1) extra space.
             Asked at: Amazon, Microsoft, Adobe, Zoho

  [C][ ] (E) Given a string with nested parentheses, find the maximum depth of nesting.
             e.g. "(()((())))" → depth 4
             Asked at: TCS, Wipro, Zoho, Amazon

  [C][ ] (E) Check if a given sequence of push and pop operations on a stack is valid.
             e.g. pushed=[1,2,3,4,5], popped=[4,5,3,2,1] — valid?
             (Simulate: push until top == next pop, then pop)
             Asked at: Amazon, Microsoft — LeetCode 946

  [C][ ] (E) Given a string of digits, find the maximum number by removing exactly 1 digit.
             (Try removing each digit, pick the one that gives max number)
             Asked at: Amazon

  [C][ ] (E) Implement a stack that supports push(), pop(), top(), and size(),
             with all operations printed in a log.
             Asked at: TCS, Wipro

  ★[C][ ] (E) Implement a stack using two queues.
              Method A: make push O(N). Method B: make pop O(N).
              Code both.
              Asked at: Amazon, Microsoft

  ★[C][ ] (E) Sort a stack in ascending order using only one extra stack.
              (Use a temp stack; pop from main, push to temp in sorted order)
              Asked at: Amazon, Zoho, TCS

  ★[C][ ] (E) Reverse a stack without using any other data structure.
              (Use recursion — pop, recurse, then insert at bottom recursively)
              Asked at: Amazon, Zoho, Wipro

  ★[C][ ] (E) Insert an element at the bottom of a stack without using extra space.
              (Recursion: pop all, insert, push all back)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Given a stack, find its middle element without popping.
              (Use recursion to reach middle, return value, re-push back)
              Asked at: Amazon, Zoho

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. NEXT GREATER / SMALLER ELEMENT (MONOTONIC STACK)
--------------------------------------------------------------------------------

  [C][ ] (M) Next Greater Element for each element in an array.
             For each arr[i], find the nearest arr[j] where j > i and arr[j] > arr[i].
             Use monotonic decreasing stack — O(N).
             Asked at: Amazon, Flipkart, Adobe, Paytm

  [C][ ] (M) Previous Greater Element for each element.
             (Process left to right, maintain decreasing stack)
             Asked at: Amazon, Flipkart

  [C][ ] (M) Next Smaller Element to the right for each element.
             (Monotonic increasing stack — pop when current < top)
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (M) Previous Smaller Element to the left for each element.
             Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Next Greater Element II — circular array.
              Array wraps around. e.g. [1,2,1] → [2,-1,2]
              (Traverse array twice with monotonic stack using index % N)
              Asked at: Amazon, Google — LeetCode 503

  ★[C][ ] (M) Daily Temperatures — next warmer day.
              For each day, how many days until a warmer temperature?
              Monotonic stack of indices — O(N).
              Asked at: Amazon, Microsoft, Google — LeetCode 739

  [C][ ] (M) Stock Span Problem — for each day, count consecutive days before it
             where price was less than or equal to today's price.
             Monotonic stack — O(N).
             Asked at: Amazon, Microsoft, Goldman Sachs

  [C][ ] (M) Online Stock Span — extend daily stock span to an online stream.
             Each call to next(price) returns the span for that day.
             Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (M) Number of visible people in a queue.
              Person i can see person j if all people between them are shorter than both.
              Monotonic stack — O(N).
              Asked at: Amazon, Google — LeetCode 1944

--------------------------------------------------------------------------------
3B. EXPRESSIONS & CALCULATORS
--------------------------------------------------------------------------------

  [C][ ] (M) Evaluate an infix expression directly (without converting to postfix).
             Handle +, -, *, / and parentheses using two stacks (values + operators).
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Basic Calculator I — evaluate string with +, -, (, ).
             No * or /. Handle unary minus.
             Asked at: Amazon, Google, Microsoft — LeetCode 224

  [C][ ] (M) Basic Calculator II — evaluate string with +, -, *, /.
             No parentheses. Handle operator precedence.
             (Push +/- terms to stack; compute * and / immediately)
             Asked at: Amazon, Google, Microsoft — LeetCode 227

  [C][ ] (M) Decode string: "3[a2[bc]]" → "abcbcabcbcabcbc"
             Use two stacks: one for repeat counts, one for strings.
             Asked at: Amazon, Google, Flipkart — LeetCode 394

  ★[C][ ] (M) Basic Calculator III — evaluate with +, -, *, /, and parentheses.
              Full recursive descent or stack-based evaluation.
              Asked at: Amazon, Google — LeetCode 772

  ★[C][ ] (M) Check if a given postfix expression is valid.
              (Operand count must always be exactly one more than operator count at each step)
              Asked at: TCS, Zoho, Wipro

  ★[C][ ] (M) Given expression with +, -, *, /, (, ) and variables, evaluate it
              with a variable map lookup. Implement full expression evaluator.
              Asked at: Google, Atlassian, Adobe

--------------------------------------------------------------------------------
3C. HISTOGRAM & GEOMETRY
--------------------------------------------------------------------------------

  [C][ ] (M) Largest Rectangle in Histogram — find max area rectangle in bar chart.
             Use monotonic stack — O(N).
             Asked at: Amazon, Google, Microsoft, Adobe, Goldman Sachs
             (Very frequently asked hard-medium problem!)

  [C][ ] (M) Trapping Rain Water — using a stack (alternate to two-pointer).
             Process each bar; pop when taller bar found, compute trapped water.
             O(N) time O(N) space.
             Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Find the maximum width ramp in an array.
              (Find max j - i where arr[j] >= arr[i]; monotonic stack + reverse scan)
              Asked at: Google, Amazon — LeetCode 962

--------------------------------------------------------------------------------
3D. DESIGN & SPECIAL STACKS
--------------------------------------------------------------------------------

  [C][ ] (M) Min Stack — push, pop, top, getMin() all in O(1).
             Asked at: Amazon, Microsoft, Google, Adobe — LeetCode 155
             (Classic must-know problem!)

  [C][ ] (M) Implement a stack that supports push(x), pop(), and getMax() in O(1).
             (Auxiliary max-stack, same as Min Stack but for maximum)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Implement browser back/forward navigation using two stacks.
             visit(url), back(), forward() — fully functional.
             Asked at: Amazon, Flipkart, Zoho, Adobe

  [C][ ] (M) Implement a generic Stack<T> class template with push(), pop(), top(),
             isEmpty(), size() and exception on pop/top when empty.
             Asked at: Amazon, Microsoft, Zoho, Persistent

  ★[C][ ] (M) Asteroid Collision — simulate collisions between asteroids moving left/right.
              Positive = moving right, negative = moving left.
              Stack simulation — O(N).
              Asked at: Amazon, Google, Microsoft — LeetCode 735

  ★[C][ ] (M) Remove Duplicate Letters — return smallest result with no duplicates,
              maintaining original relative order.
              Monotonic stack + last occurrence map.
              Asked at: Amazon, Google — LeetCode 316

  ★[C][ ] (M) Validate Stack Sequences — given push and pop sequences,
              is this a valid sequence of operations on an initially empty stack?
              Greedy simulation — O(N).
              Asked at: Amazon, Microsoft — LeetCode 946

  ★[C][ ] (M) Score of Parentheses:
              () = 1, AB = A+B (side by side), (A) = 2*A (nesting).
              "(()(()))" = 6. Use stack of scores.
              Asked at: Google, Amazon — LeetCode 856

--------------------------------------------------------------------------------
3E. SUBARRAY PROBLEMS (MONOTONIC STACK)
--------------------------------------------------------------------------------

  [C][ ] (M) Sum of Subarray Minimums — find sum of min(subarray) for all subarrays.
             Use monotonic stack to find left and right boundaries.
             Contribution technique — O(N).
             Asked at: Amazon, Google, Goldman Sachs — LeetCode 907

  ★[C][ ] (M) Sum of Subarray Maximums — find sum of max(subarray) for all subarrays.
              (Mirror of sum of subarray minimums, use decreasing monotonic stack)
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Maximum of minimum for every window size.
              For each window size K from 1 to N, find the max of all window minimums.
              Monotonic stack + sparse table — O(N log N).
              Asked at: Amazon, Google, competitive programming

  ★[C][ ] (M) Remove K Digits — remove K digits to make the number as small as possible.
              Monotonic increasing stack — O(N).
              Asked at: Amazon, Google, Flipkart — LeetCode 402

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Maximum Rectangle of 1s in a Binary Matrix.
             Build histogram row by row, apply largest rectangle in histogram.
             O(M * N).
             Asked at: Amazon, Google, Microsoft — LeetCode 85

  [C][ ] (H) Implement a stack with O(1) push, pop, top, getMin AND getMax.
             (Use two auxiliary stacks — one for min, one for max tracking)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (H) Implement a queue using a SINGLE stack and recursion only.
             (Use call stack as implicit second stack)
             Asked at: Amazon, Microsoft

  [C][ ] (H) Design a stack that supports all standard operations AND
             getMedian() in O(log N).
             (Maintain two heaps: max-heap for lower half, min-heap for upper half)
             Asked at: Goldman Sachs, Dolat Capital

  [C][ ] (H) Given N buildings with heights, find all buildings that can see the sunset.
             (Buildings to the west; only those not blocked by any taller building)
             Monotonic decreasing stack — O(N).
             Asked at: Amazon, Goldman Sachs

  [C][ ] (H) Histogram — extend to multiple queries: for each query (l, r),
             find the largest rectangle in the sub-histogram from index l to r.
             Precompute with monotonic stack + sparse table.
             Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Maximal Rectangle — given a 2D binary matrix, find the area of the
              largest rectangle containing only 1s (without using histogram trick).
              Use monotonic stack directly on flattened prefix height array.
              Asked at: Google, Amazon, Microsoft

  ★[C][ ] (H) Trapping Rain Water II — 3D version.
              Given a matrix of heights, find total water trapped.
              Use min-heap (priority queue) BFS from borders.
              Asked at: Google, Amazon, hard interview rounds

  ★[C][ ] (H) Count of subarrays with product less than K.
              For each right pointer, use stack to find valid left boundaries.
              O(N log N) or O(N) with two-pointer.
              Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (H) Implement a persistent stack (functional stack):
              Each push/pop creates a new version; previous versions remain accessible.
              Use path-copying on a linked structure.
              Asked at: Google, advanced data structure roles, Dolat Capital

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output?
          stack<int> s;
          s.push(1); s.push(2); s.push(3);
          while (!s.empty()) { cout << s.top() << " "; s.pop(); }
          (Output: 3 2 1 — LIFO order)
          Asked at: TCS, Wipro, Capgemini

  ★[T][ ] Why does this NOT compile?
          stack<int> s = {1, 2, 3};
          for (auto x : s) cout << x;
          (stack has no iterators and no initializer-list constructor)
          Asked at: TCS, Wipro, Persistent

  ★[T][ ] What happens when you pop() an empty std::stack?
          (Undefined behavior — no exception thrown; use empty() before pop())
          Asked at: TCS, Amazon, Wipro, Persistent

  ★[T][ ] What is the output?
          stack<int> s;
          s.push(5); s.push(3); s.push(7); s.push(1);
          // Min stack question: what is the min at this point?
          // Without auxiliary tracking you CANNOT know in O(1)
          (This is why Min Stack design is a classic interview question)
          Asked at: Amazon, Microsoft, Adobe

  ★[T][ ] How can you change the underlying container of std::stack to vector?
          stack<int, vector<int>> s;
          When would you do this and why?
          (vector: contiguous memory, better cache performance;
           deque: default, allows push_front which stack doesn't need anyway)
          Asked at: Persistent, Nagarro, Dolat Capital

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — std::stack Internals & Design        | 13 |  0 |  0 |    13
  Theory — Monotonic Stack Concepts             |  2 |  0 |  0 |     2
  Coding Easy — Basic Stack Operations          | 17 |  0 |  0 |    17
  Coding Medium — Next Greater/Smaller          |  0 |  9 |  0 |     9
  Coding Medium — Expressions & Calculators     |  0 |  7 |  0 |     7
  Coding Medium — Histogram & Geometry          |  0 |  3 |  0 |     3
  Coding Medium — Design & Special Stacks       |  0 |  8 |  0 |     8
  Coding Medium — Subarray Problems             |  0 |  4 |  0 |     4
  Coding Hard                                   |  0 |  0 | 10 |    10
  Tricky Output / Concept Questions             |  5 |  0 |  0 |     5
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 37 | 31 | 10 |    78

  ★ = 38 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    → LIFO definition, implement stack with array/linked list, valid parentheses,
      reverse string with stack, postfix evaluation, infix to postfix,
      stack overflow in recursion, call stack explanation

  ZOHO:
    → Min stack, browser history with two stacks, sort a stack,
      celebrity problem, valid parentheses, insert at bottom of stack

  AMAZON / FLIPKART / PAYTM:
    → Valid parentheses, next greater element, daily temperatures,
      stock span, min stack, decode string, remove K digits,
      asteroid collision, validate stack sequences, histogram area

  MICROSOFT / ADOBE:
    → Basic calculator I & II, min + max stack, largest rectangle,
      trapping rain water, browser history, expression evaluator

  GOOGLE / ATLASSIAN:
    → Basic calculator III, score of parentheses, sum of subarray mins,
      maximal rectangle, buildings seeing sunset, remove duplicate letters,
      next greater element II (circular), persistent stack

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Stack with getMedian(), vector-backed vs deque-backed stack performance,
      monotonic stack contribution technique, sum of subarray max/min,
      max of minimums for every window size, persistent stack

================================================================================
END
================================================================================
