================================================================================
        QUEUE — COMPLETE QUESTION BANK
        Covers: Simple Queue, Circular Queue, Deque, Priority Queue,
                Monotonic Deque, BFS Applications
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

  // STL Queue
  #include <queue>
  queue<int> q;
  q.push(x);   q.pop();   q.front();   q.back();   q.empty();   q.size();

  // STL Deque (double-ended queue)
  #include <deque>
  deque<int> dq;
  dq.push_front(x);  dq.push_back(x);
  dq.pop_front();    dq.pop_back();
  dq.front();        dq.back();

  // STL Priority Queue
  priority_queue<int> maxpq;                          // max-heap (default)
  priority_queue<int,vector<int>,greater<int>> minpq; // min-heap

  ── CORE PROPERTIES ─────────────────────────────────────────────────────────

  Type              │ Order  │ Enqueue │ Dequeue │ Peek  │ Use Case
  ──────────────────┼────────┼─────────┼─────────┼───────┼────────────────────
  Simple Queue      │ FIFO   │ O(1)    │ O(1)    │ O(1)  │ BFS, scheduling
  Circular Queue    │ FIFO   │ O(1)    │ O(1)    │ O(1)  │ Fixed-size buffers
  Deque             │ Both   │ O(1)    │ O(1)    │ O(1)  │ Sliding window max
  Priority Queue    │ Priority│ O(log N)│ O(log N)│ O(1)  │ Dijkstra, top-K
  Monotonic Deque   │ FIFO   │ O(1)*   │ O(1)    │ O(1)  │ Sliding window max/min

  * Amortized O(1) — each element pushed and popped at most once total

  ── MUST-KNOW PATTERNS ──────────────────────────────────────────────────────

  1. BFS TEMPLATE — all shortest-path / level-order problems:
     queue<Node*> q; q.push(start); visited[start] = true;
     while (!q.empty()) {
         int sz = q.size();           // process level by level if needed
         while (sz--) {
             auto curr = q.front(); q.pop();
             for (auto& neighbor : adj[curr])
                 if (!visited[neighbor]) { visited[neighbor]=true; q.push(neighbor); }
         }
     }

  2. MONOTONIC DEQUE — sliding window max/min in O(N):
     Maintain deque of INDICES in decreasing (for max) or increasing (for min) order.
     On each element: remove from back if deque.back() breaks monotonicity.
     Remove from front if deque.front() is outside the window.
     deque.front() is always the max/min of the current window.

  3. PRIORITY QUEUE FOR TOP-K / K-TH SMALLEST:
     Top-K largest → min-heap of size K (pop when size > K)
     K-th smallest → max-heap of size K (pop when size > K)
     Dijkstra / Prim → min-heap of (distance, node) pairs

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a queue? What operations does it support? What is FIFO?
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is the difference between stack and queue?
         (Stack: LIFO; Queue: FIFO — different ends for insert and delete)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is a circular queue? Why is it needed over a regular queue?
         (Regular queue wastes dequeued space; circular reuses it with modular index)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is a deque? What problems does it solve?
         (Double-ended queue: O(1) insert/delete at both ends;
          used for sliding window max/min, palindrome check, work-stealing)
         Asked at: Amazon, Microsoft, Google, TCS

  [T][ ] What is a priority queue? How is it implemented internally?
         (Binary heap — max-heap by default in C++; O(log N) insert/delete)
         Asked at: Amazon, Microsoft, Google, TCS

  [T][ ] How would you implement a queue using two stacks?
         (Input stack + output stack; lazy transfer on dequeue when output is empty)
         Asked at: Amazon, Microsoft, Google

  [T][ ] How would you implement a stack using two queues?
         Asked at: Amazon, Microsoft

  [T][ ] How do you create a min-heap using priority_queue in C++?
         (priority_queue<int, vector<int>, greater<int>> pq;)
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] What is a monotonic deque? When do you use it?
         (Deque maintaining elements in sorted order — used for O(N) sliding window max/min)
         Asked at: Amazon, Google, Goldman Sachs

  [T][ ] What is the call stack? How is it different from queue?
         (Call stack: LIFO — last called function returns first; queue is FIFO)
         Asked at: TCS, Wipro, Amazon

  ★[T][ ] What is the difference between std::queue and std::deque in C++?
           (queue: restricted FIFO interface on top of deque; deque: full double-ended container)
           Asked at: Amazon, Microsoft, TCS

  ★[T][ ] What is a blocking queue? Where is it used?
           (Producers block when full, consumers block when empty — used in thread pools,
            producer-consumer pattern, message passing systems)
           Asked at: Amazon, Microsoft, Google, Dolat Capital

  ★[T][ ] What is the amortized complexity of queue-using-two-stacks?
           (Each element: pushed once O(1), transferred once O(1), popped once O(1) → O(1) amortized)
           Asked at: Amazon, Microsoft, Google

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── IMPLEMENTATION ──────────────────────────────────────────────────────────

  [C][ ] (E) Implement a queue using a singly linked list
             enqueue at rear, dequeue from front
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Implement a circular queue using a fixed-size array
             Handle wraparound with modular arithmetic; isFull, isEmpty
             Asked at: TCS, Wipro, Sasken, Dolat Capital

  [C][ ] (E) Implement queue using a single stack (amortized O(1))
             Push always to stack; pop: if helper stack empty, transfer all
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (E) Implement a queue that rejects duplicate elements (set + queue combo)
             Asked at: Amazon, Zoho

  ── CLASSIC APPLICATIONS ────────────────────────────────────────────────────

  [C][ ] (E) Print all binary numbers up to N using queue
             Enqueue "1"; dequeue front, print, enqueue front+"0" and front+"1"
             Asked at: Amazon, TCS, Zoho

  [C][ ] (E) Reverse a queue without extra data structure
             Use recursion — queue is FIFO, recursion provides the reversal
             Asked at: Amazon, TCS, Zoho

  [C][ ] (E) Reverse the first K elements of a queue (use a stack)
             Pop K elements to stack, push back, then rotate remaining to back
             Asked at: Amazon, Flipkart

  [C][ ] (E) Given a queue of integers, rearrange so all even numbers come before odd
             Maintain relative order within each group
             Asked at: Amazon, TCS

  [C][ ] (E) Interleave first and second halves of a queue
             Input: 1 2 3 4 5 6 → Output: 1 4 2 5 3 6
             Use stack for second half
             Asked at: Amazon, Zoho

  [C][ ] (E) Circular tour problem: find the starting gas station
             from which a truck can complete circular route without running out
             Greedy + queue simulation; O(N)
             Asked at: Amazon, Flipkart

  ★[C][ ] (E) Implement a queue using array (simple, non-circular) — show why
              space gets wasted; then explain why circular queue fixes it
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Given a queue, sort it using only one additional queue
              (Repeated selection of minimum — O(N²))
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Check if elements of a queue can form a palindrome
              Use frequency count OR deque approach
              Asked at: TCS, Amazon, Zoho

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── SLIDING WINDOW ──────────────────────────────────────────────────────────

  [C][ ] (M) Sliding window maximum using deque — O(N)
             Maintain deque of indices in decreasing value order
             deque.front() = max of current window; remove stale from front
             Asked at: Amazon, Google, Microsoft, Flipkart, Goldman Sachs

  [C][ ] (M) Moving average of last K elements from a data stream
             Queue of size K; maintain running sum
             Asked at: Amazon, Goldman Sachs, Dolat Capital, Facebook/Meta

  [C][ ] (M) First non-repeating character in a stream of characters
             Queue maintains candidates; hashmap tracks frequency
             Asked at: Amazon, Flipkart, Paytm, Swiggy

  ── BFS APPLICATIONS ────────────────────────────────────────────────────────

  [C][ ] (M) Level order traversal of binary tree — print each level separately
             BFS with level-size tracking (inner while loop)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Rotten oranges — grid problem, multi-source BFS
             Find minimum minutes for all oranges to rot; -1 if impossible
             Asked at: Amazon, Microsoft, Flipkart, Swiggy

  [C][ ] (M) Jump Game — minimum jumps (BFS on implicit graph)
             Each position i can reach [i+1, i+nums[i]]; BFS level = jumps count
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Shortest path in a binary maze (0 = open, 1 = blocked)
             4-directional BFS with visited tracking
             Asked at: Amazon, Google, Microsoft, Flipkart

  ── SCHEDULING & SIMULATION ─────────────────────────────────────────────────

  [C][ ] (M) Print all N-digit numbers starting with 1 in BFS order
             (Each number's digits range 0-9; enqueue child numbers)
             Asked at: Amazon, Paytm

  [C][ ] (M) Implement a scheduler: tasks with priority; highest priority first;
             same priority → FIFO. Use priority_queue with custom comparator
             Asked at: Amazon, Microsoft, Dolat Capital

  [C][ ] (M) Implement a double-ended queue (deque) from scratch using DLL
             pushFront, pushBack, popFront, popBack, front, back — all O(1)
             Asked at: Amazon, Persistent

  [C][ ] (M) Implement stack using two queues
             Asked at: Amazon, Microsoft

  ★[C][ ] (M) K closest points to origin — use max-heap of size K
              Return K points with smallest Euclidean distance
              Asked at: Amazon, Google, Microsoft, Facebook/Meta

  ★[C][ ] (M) Find top K frequent elements using min-heap of size K
              Frequency map + min-heap; pop when size > K
              Asked at: Amazon, Microsoft, Google, Flipkart

  ★[C][ ] (M) Merge K sorted arrays using min-heap
              Push one element per array; extract min, push next from same array
              Asked at: Amazon, Google, Microsoft (very common!)

  ★[C][ ] (M) Given a stream of integers, continuously find the median
              Max-heap (lower half) + min-heap (upper half); rebalance on each insert
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Implement a task scheduler (CPU scheduling simulation):
              given tasks with cooldown interval n, find minimum intervals needed
              Greedy + max-heap of task frequencies
              Asked at: Amazon, Microsoft, Facebook/Meta

  ★[C][ ] (M) BFS on word ladder: find minimum transformations from start word
              to end word changing one letter at a time (each intermediate is a valid word)
              BFS over word graph; O(N × L²)
              Asked at: Amazon, Microsoft, Google, Flipkart

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement a blocking queue in C++ with multiple producers/consumers
             mutex + condition_variable; producers block when full, consumers when empty
             Asked at: Dolat Capital, Amazon, Microsoft, Persistent

  [C][ ] (H) Design and implement a message queue system
             publish(topic, message), subscribe(topic), consume(topic) → message
             Support multiple topics with separate queues
             Asked at: Dolat Capital, Amazon, Adobe

  [C][ ] (H) Given a sequence of enqueue/dequeue operations with timestamps,
             find the maximum queue size at any point in time
             Event-based sweep with difference array
             Asked at: Goldman Sachs, Dolat Capital

  [C][ ] (H) Maximum of all subarrays of size K — deque O(N)
             Also solve with heap O(N log K); compare both
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Shortest path in binary matrix (8-directional BFS)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Design a moving average calculator for a data stream O(1) per update
             Asked at: Amazon, Facebook/Meta

  ★[C][ ] (H) Implement a thread-safe bounded blocking queue
              (Producer-consumer with capacity limit)
              unique_lock + condition_variable with proper spurious-wakeup handling
              Asked at: Amazon, Google, Microsoft, Goldman Sachs

  ★[C][ ] (H) Given N ropes of different lengths, connect all ropes with minimum cost
              (Always join two shortest ropes — min-heap greedy)
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (H) Shortest path in a weighted graph (Dijkstra's algorithm)
              min-heap of (distance, node); relax edges greedily
              Asked at: Amazon, Google, Microsoft, Goldman Sachs (must know!)

  ★[C][ ] (H) Find the maximum sum of K non-overlapping subarrays of length L
              Sliding window + deque DP optimization
              Asked at: Amazon, Google, Goldman Sachs

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ─────────────────────────────────────────────────────────────────────────
  BFS / Shortest path (unweighted)      Simple queue; visited array
  Level-order traversal                 BFS; inner while(sz--) for per-level
  Multi-source BFS (rotten oranges)     Push all sources initially, BFS together
  Sliding window max/min                Monotonic deque; front = answer
  Moving average stream                 Queue of size K + running sum
  Top-K elements                        Min-heap of size K (for K largest)
  K-th smallest/largest                 Max-heap of size K (for K smallest)
  Merge K sorted structures             Min-heap; push next from same list/array
  Running median                        Two heaps: max-heap + min-heap, balanced
  Priority scheduling                   priority_queue with custom comparator
  Queue using stacks                    Two stacks; lazy transfer on dequeue
  Circular queue (fixed size)           Array + head/tail % capacity
  Deque from scratch                    DLL with head and tail sentinels

================================================================================
QUICK REFERENCE — Common Templates
================================================================================

  // BFS template
  queue<int> q; vector<bool> vis(n, false);
  q.push(src); vis[src] = true;
  while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) if (!vis[v]) { vis[v] = true; q.push(v); }
  }

  // Sliding window maximum — monotonic deque
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
      deque<int> dq; vector<int> res;
      for (int i = 0; i < a.size(); i++) {
          while (!dq.empty() && dq.front() < i-k+1) dq.pop_front();
          while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
          dq.push_back(i);
          if (i >= k-1) res.push_back(a[dq.front()]);
      }
      return res;
  }

  // Min-heap (top-K largest)
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int x : arr) { pq.push(x); if (pq.size() > k) pq.pop(); }
  // pq now has K largest elements

  // Running median
  priority_queue<int> lo;                       // max-heap (lower half)
  priority_queue<int,vector<int>,greater<int>> hi; // min-heap (upper half)
  // Invariant: lo.size() >= hi.size(), |lo.size()-hi.size()| <= 1
  // median = lo.top() (odd total) or (lo.top()+hi.top())/2.0 (even total)

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 10 |  0 |  0 |    10
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   | 10 |  0 |  0 |    10
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 12 |  0 |    12
  Coding Medium (★ added)    |  0 |  6 |  0 |     6
  Coding Hard (from files)   |  0 |  0 |  6 |     6
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 26 | 18 | 10 |    54

================================================================================
END
================================================================================
