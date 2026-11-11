================================================================================
        STACK — COMPLETE QUESTION BANK
        Compiled from all_in_one + all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        ★ = Extra question added (real company interview, not in source files)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
PART 1 — CONCEPT QUICK REFERENCE
================================================================================

  // Array-based Stack (fixed size)
  int stk[1000]; int top = -1;
  void push(int x)  { stk[++top] = x; }
  int  pop()        { return stk[top--]; }
  int  peek()       { return stk[top]; }
  bool isEmpty()    { return top == -1; }

  // STL Stack
  #include <stack>
  stack<int> s;
  s.push(x);   s.pop();   s.top();   s.empty();   s.size();

  ── CORE PROPERTIES ─────────────────────────────────────────────────────────

  Property        │ Value
  ────────────────┼──────────────────────────────────────────────────────────
  Order           │ LIFO — Last In First Out
  push / pop      │ O(1)
  peek / top      │ O(1)
  Search          │ O(N) — no random access
  Implementations │ Array, Linked List, std::stack (deque-backed by default)

  ── MUST-KNOW PATTERNS ──────────────────────────────────────────────────────

  1. MONOTONIC STACK — maintain increasing or decreasing order in stack:
     Used for: Next Greater Element, Previous Smaller, Largest Histogram Rectangle,
               Sum of Subarray Minimums, Stock Span, Trapping Rain Water
     Pattern (Next Greater Element — monotonic decreasing stack):
       for each element:
           while stack not empty AND stack.top() < current: pop and record answer
           push current

  2. TWO STACKS FOR SPECIAL OPERATIONS:
     Min Stack: main stack + auxiliary min-tracker stack
     Queue using stacks: input stack + output stack (lazy transfer)
     Expression evaluation: operand stack + operator stack

  3. STACK FOR EXPRESSION PROBLEMS:
     Balanced parentheses, infix→postfix conversion, postfix evaluation,
     infix evaluation, decode string — all use stack for tracking state.

  4. STACK AS DFS SUBSTITUTE:
     Any recursion can be converted to explicit stack iteration.
     Avoids stack overflow for deep recursion on large inputs.

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a stack? What operations does it support?
         (LIFO structure; push, pop, peek/top, isEmpty — all O(1))
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is the difference between stack (data structure) and call stack?
         (Call stack: OS-managed memory for function frames;
          data structure stack: programmer-managed LIFO container)
         Asked at: TCS, L&T Infotech, Wipro

  [T][ ] How does a function call stack work? Explain with a recursive call.
         (Each call pushes a stack frame: return address, params, local vars)
         Asked at: Amazon, TCS, Wipro, L&T Infotech

  [T][ ] What is stack overflow? What causes it in recursion?
         (Exceeding the call stack limit due to too many nested frames)
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] What is a monotonic stack? What problems does it solve?
         (Stack that maintains elements in increasing/decreasing order;
          used for next/previous greater/smaller element problems)
         Asked at: Amazon, Google, Flipkart, competitive programming

  [T][ ] When would you use a stack over recursion?
         (When recursion depth is very large — avoids stack overflow;
          iterative DFS, explicit state management)
         Asked at: Amazon, Microsoft

  [T][ ] How would you implement a queue using two stacks?
         (Input stack + output stack; transfer all on dequeue when output empty)
         Asked at: Amazon, Microsoft, Google

  [T][ ] How would you implement a stack using two queues?
         Asked at: Amazon, Microsoft

  ★[T][ ] What is the amortized time complexity of queue using two stacks?
           (Each element is pushed once and transferred once → O(1) amortized)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] What is the difference between stack implemented with array vs linked list?
           (Array: fixed size, cache-friendly; Linked list: dynamic, pointer overhead)
           Asked at: TCS, Wipro, Amazon

  ★[T][ ] What is a deque? How does std::stack use it internally?
           (std::stack uses std::deque as its underlying container by default)
           Asked at: Amazon, Microsoft, TCS

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── IMPLEMENTATION ──────────────────────────────────────────────────────────

  [C][ ] (E) Implement a stack using a singly linked list (no array)
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Implement a stack that supports push(), pop(), top(), size()
             with all operations logged (print each operation)
             Asked at: TCS, Wipro

  [C][ ] (E) Implement a stack class using array with overflow/underflow handling
             Asked at: TCS, Wipro, Amazon, Persistent

  ── CLASSIC APPLICATIONS ────────────────────────────────────────────────────

  [C][ ] (E) Valid parentheses — check if (){}[] are balanced
             Push opening; on closing check top matches
             Asked at: Amazon, Microsoft, Google, Adobe, Zoho, Flipkart

  [C][ ] (E) Evaluate a postfix expression: "2 3 1 * + 9 -" => -4
             Push numbers; on operator pop two, compute, push result
             Asked at: Amazon, Zoho, TCS, Wipro

  [C][ ] (E) Convert infix expression to postfix using stack
             Handle operator precedence (+,-,*,/) and parentheses
             Asked at: TCS, Wipro, Zoho, Amazon

  [C][ ] (E) Reverse a string using a stack
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Check if given sequence of push/pop operations is valid
             e.g. push:[1,2,3,4,5], pop:[4,5,3,2,1] — valid?
             Asked at: Amazon, Microsoft

  [C][ ] (E) Design a Min Stack — getMin() in O(1)
             Two-stack approach OR store (val, current_min) pairs
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (E) Design a stack that returns minimum in O(1) without extra space
             (Lazy difference trick: push val - current_min when val < min)
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (E) Find the depth of nested parentheses in a string
             Track max depth by counting open brackets
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Find the celebrity in a party of N people using stack
             Celebrity: everyone knows them, they know no one. O(N) elimination
             Asked at: Amazon, Microsoft, Adobe, Zoho

  ★[C][ ] (E) Reverse a number using a stack (push digits, pop to form new number)
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Check if a string is a palindrome using a stack
              Push first half, compare with second half
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Sort a stack using only another stack (no extra array)
              Pop, insert in correct position in second stack by shuttling
              Asked at: Amazon, TCS, Wipro, Zoho

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── MONOTONIC STACK ─────────────────────────────────────────────────────────

  [C][ ] (M) Next greater element for each element in array
             Monotonic decreasing stack — O(N)
             Asked at: Amazon, Flipkart, Adobe, Paytm

  [C][ ] (M) Previous greater element for each element in array
             Asked at: Amazon, Flipkart

  [C][ ] (M) Next smaller element to the right for each element
             Monotonic increasing stack — O(N)
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (M) Daily temperatures — next warmer day for each day
             Same as next greater element on temperatures array
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Stock span problem — count consecutive days price <= today's price
             For each day, use stack of indices to find previous greater price day
             Asked at: Amazon, Microsoft, Goldman Sachs

  [C][ ] (M) Sum of subarray minimums
             Contribution technique: for each element, find left and right boundaries
             where it is the minimum; multiply count × value
             Hint: monotonic stack for previous smaller and next smaller
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (M) Largest rectangle in histogram — monotonic stack O(N)
             For each bar, find left/right boundary where bar is the smallest
             Asked at: Amazon, Google, Microsoft, Adobe, Goldman Sachs

  [C][ ] (M) Remove K digits to make the smallest number
             Monotonic stack: pop larger digit when next digit is smaller
             Asked at: Amazon, Google, Flipkart

  [C][ ] (M) Remove duplicate letters (smallest lexicographic result, no duplicates)
             Monotonic stack with frequency count and visited set
             Asked at: Amazon, Google

  ── EXPRESSIONS & SIMULATION ────────────────────────────────────────────────

  [C][ ] (M) Evaluate reverse polish notation (postfix expression)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Decode string: "3[a2[bc]]" → "abcbcabcbcabcbc"
             Two stacks: one for counts, one for strings
             Asked at: Amazon, Google, Flipkart

  [C][ ] (M) Basic calculator — evaluate string with +, -, (, )
             Stack for values + handle sign changes at each parenthesis level
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Evaluate infix expression directly (without converting to postfix)
             Operand stack + operator stack; handle precedence during evaluation
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Asteroid collision simulation
             Stack stores surviving asteroids; handle collision on push
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Online stock span — extend the classic stock span to a class
             that processes one price at a time
             Asked at: Amazon, Microsoft, Goldman Sachs

  [C][ ] (M) Number of people visible in a queue
             (Each taller person blocks all shorter persons behind them)
             Monotonic stack — O(N)
             Asked at: Amazon, Google

  [C][ ] (M) Implement a browser back-forward navigation system using two stacks
             visit(url), back(), forward() — full implementation
             Asked at: Amazon, Flipkart, Zoho, Adobe

  [C][ ] (M) Minimum number of brackets to add to make string valid
             One pass: track open count; unmatched ')' need one '(' each
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find the score of balanced parentheses string
             () = 1, AB = A+B, (A) = 2×A
             Hint: stack of scores
             Asked at: Google, Amazon

  [C][ ] (M) Check if valid stack push/pop sequence (Validate Stack Sequences)
             Simulate: push from pushed[], pop when top matches popped[]
             Asked at: Amazon, Microsoft

  [C][ ] (M) Implement queue using two stacks (amortized O(1))
             Input stack + output stack; transfer all on dequeue when output empty
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Implement stack using two queues
             Asked at: Amazon, Microsoft

  [C][ ] (M) Implement a Max Stack — getMax() in O(1) alongside push/pop
             Auxiliary max-tracker stack alongside main stack
             Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Find the next greater element in a circular array
              Extend standard NGE: iterate array twice using modulo
              Asked at: Amazon, Google, Flipkart

  ★[C][ ] (M) Trapping rain water using monotonic stack (alternate approach)
              Stack stores indices; on each bar wider than top, compute trapped water
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Find the largest area rectangle in a sorted-rows binary matrix
              Build histogram row by row, apply largest rectangle in histogram
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Given a string, remove all adjacent duplicate characters repeatedly
              until no adjacent duplicates remain — stack-based O(N)
              Asked at: Amazon, Google, Flipkart

  ★[C][ ] (M) Implement a Generic Stack<T> class template with:
              exception on empty pop/top, iterator, copy constructor
              Asked at: Amazon, TCS, Adobe, Google

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Maximum rectangle of 1s in binary matrix (using histogram per row)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (H) Implement a stack with O(1) push, pop, top, getMin, getMax
             Use two auxiliary stacks for min and max tracking
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (H) Full expression evaluator: +, -, *, /, (, ) and variables
             Implement with variable map lookup using two stacks
             Asked at: Google, Atlassian, Adobe

  [C][ ] (H) Basic calculator II — evaluate string with +, -, *, /
             No parentheses but must handle precedence
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Implement a queue using a single stack and recursion (no second stack variable)
             Use call stack as implicit second stack
             Asked at: Amazon, Microsoft

  [C][ ] (H) Design a stack that supports getMedian() in O(log N)
             Maintain two heaps: max-heap (lower half), min-heap (upper half)
             Asked at: Goldman Sachs, Dolat Capital

  [C][ ] (H) Given N buildings, find buildings that can see the sunset
             (all buildings to their right are shorter)
             Monotonic stack stores indices of visible buildings
             Asked at: Amazon, Goldman Sachs

  [C][ ] (H) Remove invalid parentheses — remove minimum to make valid
             BFS over all possible removals OR two-pass stack approach
             Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (H) Implement a persistent stack where you can access the stack
              at any past version (after any push/pop operation)
              Using path-copying (functional data structure)
              Asked at: Google, competitive programming, advanced DS roles

  ★[C][ ] (H) Maximum of all subarrays of size K (sliding window + deque/monotonic)
              O(N) with deque; also show O(N log K) with heap for comparison
              Asked at: Amazon, Google, Goldman Sachs

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ─────────────────────────────────────────────────────────────────────────
  Balanced parentheses                  Push '('; on ')' check top == '('
  Next/Previous Greater/Smaller         Monotonic stack (dec for greater, inc for smaller)
  Stock span / Daily temperatures       Monotonic stack of indices
  Largest histogram rectangle           Monotonic stack; left/right boundary arrays
  Sum of subarray minimums/maximums     Monotonic stack + contribution technique
  Postfix evaluation                    Operand stack; on operator pop 2, push result
  Infix → Postfix                       Operator stack + precedence table
  Infix evaluation (direct)            Two stacks: operands + operators
  Decode string "3[a2[b]]"             Two stacks: count stack + string stack
  Min/Max Stack                         Auxiliary tracker stack or lazy-diff trick
  Queue using stacks                    Input stack + lazy-transfer output stack
  Browser history                       Back stack + forward stack
  Remove K digits (smallest)           Monotonic increasing stack
  Asteroid collision                    Stack; negative eats smaller positives

================================================================================
QUICK REFERENCE — Common Templates
================================================================================

  // Next Greater Element — monotonic decreasing stack
  vector<int> nextGreater(vector<int>& arr) {
      int n = arr.size();
      vector<int> res(n, -1);
      stack<int> st;              // stores indices
      for (int i = 0; i < n; i++) {
          while (!st.empty() && arr[st.top()] < arr[i]) {
              res[st.top()] = arr[i];
              st.pop();
          }
          st.push(i);
      }
      return res;
  }

  // Min Stack
  class MinStack {
      stack<int> s, minS;
  public:
      void push(int x) { s.push(x); minS.push(min(x, minS.empty() ? x : minS.top())); }
      void pop()       { s.pop(); minS.pop(); }
      int top()        { return s.top(); }
      int getMin()     { return minS.top(); }
  };

  // Largest Rectangle in Histogram
  int largestRect(vector<int>& h) {
      stack<int> st; int res = 0;
      h.push_back(0);
      for (int i = 0; i < h.size(); i++) {
          while (!st.empty() && h[st.top()] > h[i]) {
              int height = h[st.top()]; st.pop();
              int width  = st.empty() ? i : i - st.top() - 1;
              res = max(res, height * width);
          }
          st.push(i);
      }
      return res;
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  8 |  0 |  0 |     8
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   | 12 |  0 |  0 |    12
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 20 |  0 |    20
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  8 |     8
  Coding Hard (★ added)      |  0 |  0 |  2 |     2
  ---------------------------|----|----|----|---------
  TOTAL                      | 26 | 25 | 10 |    61

================================================================================
END
================================================================================
