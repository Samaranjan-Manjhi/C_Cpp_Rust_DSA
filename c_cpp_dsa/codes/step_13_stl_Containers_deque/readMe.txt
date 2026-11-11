================================================================================
        STL — DEQUE (std::deque) COMPLETE QUESTION BANK
        Covers: std::deque internals + classic deque algorithm problems
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
1A. std::deque INTERNALS & MEMORY
--------------------------------------------------------------------------------

  [T][ ] What is std::deque in C++? What does it stand for?
         (Double-Ended Queue — supports O(1) push/pop at both front and back)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] How is std::deque implemented internally?
         (Segmented array — fixed-size chunks/pages; a map array of pointers to chunks;
          not a single contiguous block like vector)
         Asked at: Amazon, Microsoft, Persistent, Nagarro

  [T][ ] What is the difference between std::deque and std::vector?
         (deque: O(1) push_front & push_back, no reallocation, non-contiguous memory;
          vector: O(N) push_front, O(1) amortized push_back, contiguous memory)
         Asked at: TCS, Wipro, Amazon, Zoho, Flipkart

  [T][ ] What is the difference between std::deque and std::list?
         (deque: near-random access O(1), contiguous chunks, better cache;
          list: O(1) insert/delete at any iterator, fully non-contiguous,
          no random access)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] What is the time complexity of the following on std::deque?
         push_front, push_back, pop_front, pop_back, operator[], insert at middle
         (push/pop both ends: O(1); operator[]: O(1); insert at middle: O(N))
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] Does std::deque support random access? What type of iterator does it provide?
         (Yes — random access iterator, O(1) index access via operator[])
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] What is the difference between std::deque and std::queue?
         (std::queue is an adaptor built on top of deque by default;
          std::deque is the full container with both-end access + random access)
         Asked at: TCS, Wipro, Zoho

  [T][ ] When would you prefer std::deque over std::vector?
         When would you prefer std::vector over std::deque?
         (deque: frequent insertions at front;
          vector: contiguous memory needed, better cache locality, pointer arithmetic)
         Asked at: Amazon, Microsoft, Flipkart

  ★[T][ ] Does std::deque invalidate iterators on push_front or push_back?
          (push_front/push_back: all iterators invalidated but references to elements
           remain valid — unlike vector which invalidates references too on realloc)
          Asked at: Amazon, Adobe, Persistent

  ★[T][ ] Why is std::deque slower than std::vector for random access even though
          both are O(1)?
          (deque needs a double indirection: index into chunk map, then offset within chunk;
           vector is a single pointer dereference — deque has higher constant factor)
          Asked at: Dolat Capital, HFT firms, Google

  ★[T][ ] What is a monotonic deque? What type of problems does it solve?
          (Deque where elements are maintained in monotonically increasing or decreasing
           order; used for sliding window min/max in O(N))
          Asked at: Amazon, Google, Flipkart, Goldman Sachs

  ★[T][ ] What is 0-1 BFS? Why does it use a deque instead of a regular queue?
          (Edge weights are 0 or 1; 0-weight: push to front; 1-weight: push to back;
           gives shortest path in O(V + E) instead of Dijkstra's O(E log V))
          Asked at: Competitive programming, Google, advanced graph roles

--------------------------------------------------------------------------------
1B. std::deque OPERATIONS & USE CASES
--------------------------------------------------------------------------------

  [T][ ] What are the main operations of std::deque?
         (push_front, push_back, pop_front, pop_back, front, back,
          operator[], at, size, empty, insert, erase, clear)
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is std::deque commonly used as the underlying container for?
         (std::stack and std::queue are both adaptors — deque is their default container)
         Asked at: TCS, Wipro, Amazon

  ★[T][ ] Can you use std::sort on std::deque? Why or why not?
          (Yes — std::deque has random access iterators, so std::sort works on it)
          Asked at: Persistent, Nagarro, TCS

  ★[T][ ] How would you implement a sliding window maximum using std::deque?
          Explain the invariant maintained in the deque.
          (Store indices; maintain decreasing order of values;
           pop front if out of window, pop back if current > back)
          Asked at: Amazon, Google, Microsoft, Goldman Sachs

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. std::deque BASIC USAGE
--------------------------------------------------------------------------------

  ★[C][ ] (E) Create a std::deque<int> and demonstrate push_front, push_back,
              pop_front, pop_back, and random access via operator[].
              Print after each operation.
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Use std::deque as a sliding window:
              Add elements to back, remove from front when window exceeds size K.
              Print the window sum at each step.
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Implement a palindrome checker using std::deque:
              Push characters to deque, then compare front and back alternately.
              Asked at: TCS, Zoho, Amazon

  ★[C][ ] (E) Given std::deque<int>, rotate it left by K positions using
              pop_front + push_back in a loop.
              Then rotate right by K using pop_back + push_front.
              Asked at: TCS, Wipro, Zoho

  ★[C][ ] (E) Use std::deque to implement a history tracker:
              Push new states to back. Undo pops from back. Redo pushes from a redo stack.
              (Simplified text editor undo/redo)
              Asked at: Amazon, Zoho, Adobe

--------------------------------------------------------------------------------
2B. IMPLEMENT DEQUE FROM SCRATCH
--------------------------------------------------------------------------------

  [C][ ] (M) Implement a double-ended queue (deque) from scratch using a doubly linked list.
             Support: pushFront, pushBack, popFront, popBack, front, back — all O(1).
             Asked at: Amazon, Persistent

  ★[C][ ] (E) Implement a fixed-capacity deque using a circular array.
              Handle wrap-around with modular arithmetic.
              Support push_front, push_back, pop_front, pop_back.
              Asked at: TCS, Wipro, Sasken, Dolat Capital

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. MONOTONIC DEQUE — SLIDING WINDOW PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) Sliding window maximum — find the maximum in every window of size K.
             Use monotonic deque of indices — O(N).
             Asked at: Amazon, Google, Microsoft, Goldman Sachs

  [C][ ] (M) Maximum of all subarrays of size K (same as above — sliding window + deque).
             Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Sliding window minimum — find the minimum in every window of size K.
              Use monotonic deque maintaining increasing order — O(N).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Given array and integer K, find the maximum sum of any subarray of size K.
              Use deque-based sliding window to also track which element to remove.
              Asked at: Amazon, Flipkart, Paytm

  ★[C][ ] (M) Count of subarrays where max - min <= K.
              Use two monotonic deques (one for max, one for min) — O(N).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Longest subarray where max - min <= 1.
              Use two deques for running max and min — O(N).
              Asked at: Google, Atlassian

  ★[C][ ] (M) Shortest subarray with sum at least K (array can have negatives).
              Use monotonic deque on prefix sums — O(N).
              Asked at: Google, Amazon, LeetCode 862

--------------------------------------------------------------------------------
3B. DEQUE AS SIMULATION / IMPLEMENTATION
--------------------------------------------------------------------------------

  ★[C][ ] (M) Implement a browser back/forward history system using deque:
              visit(url): add to back. back(): move backward. forward(): move forward.
              Current page is always tracked.
              Asked at: Amazon, Adobe, Zoho, Flipkart

  ★[C][ ] (M) Implement a sliding window average calculator:
              Given stream of integers and window size K, output the running average
              after each insertion using std::deque.
              Asked at: Amazon, Goldman Sachs, Facebook/Meta

  ★[C][ ] (M) Implement a job scheduler with undo/redo using two deques:
              execute(job): add to done deque. undo(): move from done to redo deque.
              redo(): move from redo back to done deque.
              Asked at: Adobe, Atlassian, Zoho

  ★[C][ ] (M) Given a deque of tasks with deadlines, implement a scheduler that
              always picks the task with the nearest deadline from the front.
              Demonstrate why deque is better than vector for this use case.
              Asked at: Amazon, Dolat Capital

--------------------------------------------------------------------------------
3C. 0-1 BFS USING DEQUE
--------------------------------------------------------------------------------

  ★[C][ ] (M) Shortest path in a grid where moving right costs 0 and moving down costs 1
              (or vice versa). Use 0-1 BFS with deque.
              Asked at: Google, Codeforces, competitive programming

  ★[C][ ] (M) Minimum cost to reach destination in a graph where edges have weight 0 or 1.
              Use 0-1 BFS: push 0-weight edges to front, 1-weight to back.
              O(V + E) time.
              Asked at: Google, advanced competitive programming

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  ★[C][ ] (H) Maximum of sliding window — follow-up: also find the second maximum
              in every window of size K. Use two monotonic deques.
              Asked at: Google, Goldman Sachs

  ★[C][ ] (H) Given an array, for each index i find the nearest index j > i
              such that arr[j] > arr[i]. Then find the nearest j < i such that
              arr[j] > arr[i]. Use two monotonic deques. O(N).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Implement a thread-safe deque with push_front, push_back,
              pop_front, pop_back, all protected by a mutex.
              Template it for any type T.
              Asked at: Dolat Capital, Persistent, advanced C++ roles

  ★[C][ ] (H) Design a data structure using std::deque that supports:
              push(x): add to back in O(1)
              pop(): remove from front in O(1)
              getMax(): returns current maximum in O(1)
              (Monotonic deque for max tracking alongside the data deque)
              Asked at: Amazon, Microsoft, Goldman Sachs

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output and why?
          std::deque<int> dq = {1, 2, 3};
          dq.push_front(0);
          dq.push_back(4);
          cout << dq[0] << " " << dq[4];
          (Output: 0 4 — deque supports O(1) random access after push_front)
          Asked at: TCS, Wipro, Persistent

  ★[T][ ] Why is this true about deque but NOT about vector?
          std::deque<int> dq = {1, 2, 3};
          int& ref = dq[1];
          dq.push_front(0);
          cout << ref;   // ref is still valid!
          (deque: push_front doesn't move existing elements — references stable;
           vector: push_back may reallocate — reference becomes dangling)
          Asked at: Amazon, Adobe, Persistent

  ★[T][ ] What is the difference between std::deque and std::queue in terms of
          what you can do with them?
          (deque: full container, both ends + random access;
           queue: restrictor adaptor — only push_back, pop_front, front, back)
          Asked at: TCS, Wipro, Zoho

  ★[T][ ] Can you iterate over std::queue directly? What about std::deque?
          (queue: NO — no iterators exposed; deque: YES — full random access iterators)
          Asked at: TCS, Wipro, Persistent

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — std::deque Internals & Memory        | 12 |  0 |  0 |    12
  Theory — Operations & Use Cases               |  4 |  0 |  0 |     4
  Coding Easy — std::deque Basic Usage          |  5 |  0 |  0 |     5
  Coding Easy/Medium — Implement from Scratch   |  1 |  1 |  0 |     2
  Coding Medium — Monotonic Deque / Window      |  0 |  7 |  0 |     7
  Coding Medium — Simulation / Implementation   |  0 |  4 |  0 |     4
  Coding Medium — 0-1 BFS                       |  0 |  2 |  0 |     2
  Coding Hard                                   |  0 |  0 |  4 |     4
  Tricky Output / Concept Questions             |  4 |  0 |  0 |     4
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 26 | 14 |  4 |    44

  ★ = 36 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI:
    → What is deque, deque vs vector vs list, basic push/pop both ends,
      random access, circular deque from array, palindrome with deque

  ZOHO:
    → Deque vs queue, browser history with deque, rotate deque,
      undo/redo system using deque

  AMAZON / FLIPKART / PAYTM:
    → Sliding window maximum (monotonic deque), sliding window minimum,
      sliding window sum, shortest subarray with sum >= K

  MICROSOFT / ADOBE:
    → Deque iterator invalidation rules, reference stability vs vector,
      0-1 BFS with deque, browser/job scheduler simulation

  GOOGLE / ATLASSIAN:
    → 0-1 BFS, shortest subarray with negatives (deque on prefix sums),
      longest subarray max-min <= 1, count subarrays max-min <= K

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Why deque is slower than vector for random access (constant factor),
      thread-safe deque, deque + getMax in O(1), monotonic deque internals

================================================================================
END
================================================================================
