================================================================================
        STL — PRIORITY QUEUE / HEAP COMPLETE QUESTION BANK
        Covers: std::priority_queue internals + classic heap algorithm problems
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
1A. HEAP DATA STRUCTURE — INTERNALS
--------------------------------------------------------------------------------

  [T][ ] What is a heap? What are its two key properties?
         (Shape property: complete binary tree;
          Heap property: max-heap → parent >= children; min-heap → parent <= children)
         Asked at: TCS, Wipro, Amazon, Microsoft, Google

  [T][ ] What is the difference between a min-heap and a max-heap?
         (min-heap: root is the minimum; max-heap: root is the maximum)
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] How is a heap represented as an array?
         (Root at index 0; parent of i → (i-1)/2;
          left child → 2i+1; right child → 2i+2)
         Asked at: TCS, Wipro, Amazon, Samsung

  [T][ ] What is the time complexity of insert and extract-min/max in a heap?
         (Insert: O(log N) — heapify-up; Extract: O(log N) — heapify-down;
          Peek min/max: O(1))
         Asked at: TCS, Wipro, Amazon, Google

  [T][ ] What is heapify? What is its time complexity?
         (heapify-down: O(log N); heapify-up: O(log N))
         Asked at: TCS, Wipro, Amazon, Google

  [T][ ] Why is build-heap O(N) and NOT O(N log N)?
         (Bottom-up heapify: most nodes near the bottom do very little work;
          mathematical sum of levels gives O(N))
         Asked at: Amazon, Google, Microsoft, Goldman Sachs

  [T][ ] What is heap sort? What is its time and space complexity? Is it stable?
         (Time: O(N log N); Space: O(1) in-place; NOT stable — equal elements
          can be reordered due to heap structure)
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] What is the difference between a heap and a BST?
         (Heap: shape + heap property, O(1) min/max, O(N) search;
          BST: ordered structure, O(log N) search, no shape guarantee)
         Asked at: Amazon, Microsoft, Google, TCS

--------------------------------------------------------------------------------
1B. std::priority_queue — STL INTERNALS
--------------------------------------------------------------------------------

  [T][ ] What is std::priority_queue in C++? Is it a container or adaptor?
         (Container adaptor — wraps a container, uses max-heap by default)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What is the default order of std::priority_queue?
         (Max-heap — largest element is at top)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] How do you create a min-heap using std::priority_queue in C++?
         (priority_queue<int, vector<int>, greater<int>> pq;)
         Asked at: Amazon, Microsoft, Google, Flipkart, Goldman Sachs
         (VERY commonly asked — know this cold!)

  [T][ ] What is the default underlying container of std::priority_queue?
         (std::vector — heap operations applied on the vector)
         Asked at: Persistent, Nagarro, TCS

  [T][ ] What is the time complexity of push, pop, and top on std::priority_queue?
         (push: O(log N); pop: O(log N); top: O(1))
         Asked at: TCS, Wipro, Amazon

  [T][ ] Can you iterate over std::priority_queue? Why or why not?
         (No — does not expose iterators; only top() is accessible)
         Asked at: Persistent, Nagarro, TCS

  [T][ ] How do you use a custom comparator with std::priority_queue?
         (Define struct with bool operator()(T a, T b);
          or use lambda wrapped in std::function)
         Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] What is lazy deletion in a priority queue? When do you use it?
          (Mark elements as deleted instead of removing them;
           skip deleted elements on pop; used when decrease-key is needed)
          Asked at: Amazon, Google, Goldman Sachs

  ★[T][ ] What is the decrease-key operation in a heap?
          Why doesn't std::priority_queue support it?
          (Decrease-key: reduce a key and bubble it up; O(log N);
           STL pq doesn't support because it hides the heap structure;
           workaround: lazy deletion or use indexed priority queue)
          Asked at: Google, Goldman Sachs, Dolat Capital

  ★[T][ ] What is an indexed priority queue? When is it used?
          (Priority queue that allows O(log N) update/decrease-key by maintaining
           an index map from element → heap position;
           used in Dijkstra, Prim's with efficient updates)
          Asked at: Google, Goldman Sachs, competitive programming

  ★[T][ ] What are the STL functions: make_heap, push_heap, pop_heap, sort_heap?
          How do they differ from std::priority_queue?
          (These operate directly on a vector with heap semantics;
           make_heap: O(N); push_heap/pop_heap: O(log N))
          Asked at: Persistent, Nagarro, advanced C++ roles

  ★[T][ ] What is a d-ary heap? How does it compare to a binary heap?
          (Each node has d children; better cache performance for large d;
           decrease-key faster O(log_d N), extract-min slower O(d * log_d N))
          Asked at: Google, Goldman Sachs, Dolat Capital

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. HEAP IMPLEMENTATION FROM SCRATCH
--------------------------------------------------------------------------------

  [C][ ] (E) Build a max-heap from an unsorted array.
             Show the heapify process step by step.
             Asked at: TCS, Amazon, Samsung

  [C][ ] (E) Given a max-heap array, verify that it satisfies the heap property.
             Asked at: TCS, Amazon

  [C][ ] (E) Implement heapify-up and heapify-down from scratch.
             Then implement insert and extract-min on a min-heap array.
             Asked at: Amazon, Google, competitive programming

  ★[C][ ] (E) Implement a max-heap class from scratch using a vector:
              insert(val), extractMax(), getMax(), heapifyUp(), heapifyDown().
              Asked at: Amazon, Google, Microsoft, Samsung

  ★[C][ ] (E) Given an array, use std::make_heap to turn it into a max-heap.
              Then use push_heap and pop_heap to demonstrate operations.
              Compare with std::priority_queue.
              Asked at: Persistent, Nagarro, TCS

--------------------------------------------------------------------------------
2B. CLASSIC EASY HEAP PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (E) Given N ropes, connect them with minimum total cost.
             Always connect the two shortest ropes first.
             Use min-heap — O(N log N).
             Asked at: Amazon, Flipkart, Paytm, Goldman Sachs

  [C][ ] (E) Sort a nearly sorted array where each element is at most K positions
             away from its correct position.
             Use min-heap of size K+1 — O(N log K).
             Asked at: Amazon, Microsoft

  [C][ ] (E) Find the Kth smallest element in a max-heap.
             (Extract K times or convert to sorted array)
             Asked at: Amazon, Flipkart

  ★[C][ ] (E) Given an array, find the K largest elements (not necessarily sorted).
              Use a min-heap of size K — O(N log K).
              Asked at: Amazon, Microsoft, TCS, Goldman Sachs

  ★[C][ ] (E) Implement heap sort on an array from scratch.
              Use build-heap O(N) then repeated extract-max O(N log N).
              Asked at: TCS, Wipro, Amazon, Samsung

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. K-th ELEMENT PROBLEMS (Most Asked!)
--------------------------------------------------------------------------------

  [C][ ] (M) Kth largest element in an array.
             Method 1: min-heap of size K — O(N log K).
             Method 2: quickselect — O(N) average.
             Asked at: Amazon, Microsoft, Google, Flipkart, Goldman Sachs
             (One of the most frequently asked heap questions!)

  [C][ ] (M) Kth largest element in a stream.
             Maintain min-heap of size K; on new element replace min if larger.
             Asked at: Amazon, Microsoft, Flipkart, Paytm — LeetCode 703

  [C][ ] (M) Find the Kth smallest element in a sorted matrix.
             Use min-heap of (value, row, col) starting with first column.
             O(K log K).
             Asked at: Amazon, Microsoft, Google — LeetCode 378

  [C][ ] (M) Given N sorted arrays each of size K, find element at overall Kth position.
             Use min-heap of (element, array_index, element_index).
             Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Kth smallest prime fraction from sorted array.
              Use min-heap of fractions (arr[i]/arr[j]) — O(K log N).
              Asked at: Google, Goldman Sachs — LeetCode 786

  ★[C][ ] (M) Find K pairs with smallest sums from two sorted arrays.
              Use min-heap of (a[i]+b[j], i, j). Start with (a[i]+b[0]).
              O(K log K).
              Asked at: Amazon, Google — LeetCode 373

  ★[C][ ] (M) Kth smallest number in multiplication table (N×N).
              Binary search on value + min-heap verification.
              Asked at: Google — LeetCode 668

--------------------------------------------------------------------------------
3B. TOP-K FREQUENCY PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) Top K frequent elements in an array.
             Count with map + min-heap of size K keyed by frequency.
             O(N log K).
             Asked at: Amazon, Microsoft, Google, Flipkart — LeetCode 347

  [C][ ] (M) Top K frequent words — return K most frequent words sorted by
             frequency desc, then lexicographically asc for ties.
             Use min-heap with custom comparator.
             Asked at: Amazon, Microsoft, Google — LeetCode 692

  [C][ ] (M) Frequency sort — sort array elements by frequency descending.
             Elements with same frequency maintain original relative order.
             Use max-heap keyed by frequency.
             Asked at: Amazon, Flipkart, Swiggy

  ★[C][ ] (M) Sort characters in a string by frequency descending.
              "tree" → "eert" or "eetr".
              Use max-heap keyed by frequency.
              Asked at: Amazon, Google — LeetCode 451

  ★[C][ ] (M) Given array of tasks, find if you can finish them with max K parallel workers.
              Use max-heap of task durations — greedily assign largest remaining.
              Asked at: Amazon, Flipkart, Swiggy

--------------------------------------------------------------------------------
3C. MERGE K SORTED STRUCTURES
--------------------------------------------------------------------------------

  [C][ ] (M) Merge K sorted linked lists into one sorted linked list.
             Use min-heap of size K, one node per list.
             O(N log K) where N = total nodes.
             Asked at: Amazon, Microsoft, Google, Goldman Sachs, Flipkart
             (Classic must-know heap problem!)

  [C][ ] (H) Merge K sorted arrays of different sizes into one sorted array
             without using STL sort.
             Use min-heap with (value, array_idx, element_idx).
             Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Merge K sorted arrays where each is individually sorted.
              All values are distinct. Return merged sorted array.
              Min-heap of size K — O(N log K).
              Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (M) Given K sorted streams (generators), merge them in sorted order.
              Use min-heap — lazy evaluation, pull next element on demand.
              Asked at: Google, Goldman Sachs, Dolat Capital

--------------------------------------------------------------------------------
3D. STRING / TASK SCHEDULING PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) Reorganize String — rearrange so no two adjacent characters are the same.
             Use max-heap; greedily pick most frequent available char.
             Return "" if impossible.
             Asked at: Amazon, Google, Microsoft — LeetCode 767

  [C][ ] (M) Task Scheduler — minimum time to finish all tasks with cooldown N.
             Same task must wait N slots. Greedily schedule most frequent first.
             Use max-heap of task frequencies.
             Asked at: Amazon, Google, Microsoft — LeetCode 621

  [C][ ] (M) Rearrange string K distance apart — no same character within K positions.
             Max-heap + queue of cooldown — O(N log C).
             Asked at: Google, Amazon — LeetCode 358

  ★[C][ ] (M) Minimum number of CPU intervals needed to execute all tasks.
              (Same as task scheduler — model with heap + idle slots)
              Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Given a list of words, rearrange them such that no two adjacent
              words start with the same letter. Use max-heap.
              Asked at: Amazon, Zoho

--------------------------------------------------------------------------------
3E. INTERVAL / MEETING / SCHEDULING PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) Meeting Rooms II — minimum number of meeting rooms required.
             Sort by start time; use min-heap of end times (size = rooms in use).
             O(N log N).
             Asked at: Amazon, Microsoft, Google, Goldman Sachs — LeetCode 253

  [C][ ] (M) Given list of jobs with start, end, profit, find maximum profit
             such that no two jobs overlap.
             Sort by end time; min-heap to track latest non-overlapping job.
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) IPO Problem — maximize capital by completing at most K projects.
             Sort by capital requirement (min-heap);
             use max-heap by profit for available projects.
             Asked at: Amazon, Google — LeetCode 502

  [C][ ] (M) Schedule tasks to minimize total weighted waiting time.
             Each task has duration; sort ascending, weight by remaining tasks.
             Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Single-server job scheduling — minimize average completion time.
              Sort by shortest job first (SJF) using min-heap.
              Asked at: Goldman Sachs, Dolat Capital, OS interview rounds

  ★[C][ ] (M) Given tasks with deadlines and profits, select tasks to maximize profit.
              Sort by deadline; use min-heap of profits (drop smallest when over capacity).
              Asked at: Amazon, Goldman Sachs, TCS

--------------------------------------------------------------------------------
3F. TWO-HEAP PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) Find median from a data stream.
             Use two heaps: max-heap for lower half, min-heap for upper half.
             Rebalance after each insertion. O(log N) insert, O(1) median.
             Asked at: Amazon, Microsoft, Google, Goldman Sachs — LeetCode 295
             (Classic must-know two-heap problem!)

  [C][ ] (M) Sliding window median — find median of every window of size K.
             Two heaps with lazy deletion.
             O(N log K).
             Asked at: Amazon, Google, competitive programming — LeetCode 480

  ★[C][ ] (M) Find running median: after each insertion to a stream,
              output the current median. Two heaps — O(log N) per insertion.
              Asked at: Amazon, Microsoft, Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Balance two heaps dynamically: given a sequence of insert
              and delete operations, always maintain lower and upper halves
              in two heaps and return median after each step.
              Asked at: Goldman Sachs, Dolat Capital

--------------------------------------------------------------------------------
3G. SHORTEST PATH & GRAPH PROBLEMS (Heap-based)
--------------------------------------------------------------------------------

  [C][ ] (M) Dijkstra's algorithm using std::priority_queue.
             Single-source shortest path on non-negative weighted graph.
             O((V + E) log V).
             Asked at: Amazon, Microsoft, Google, Goldman Sachs

  ★[C][ ] (M) Prim's algorithm for Minimum Spanning Tree using min-heap.
              Start from any node; always add cheapest edge to MST.
              O((V + E) log V).
              Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Network Delay Time — find max time for signal to reach all nodes.
              Dijkstra from source node.
              Asked at: Amazon, Google, Microsoft — LeetCode 743

  ★[C][ ] (M) Swim in Rising Water — find minimum time to swim from (0,0) to (N-1,N-1).
              Dijkstra / min-heap BFS — O(N² log N).
              Asked at: Google — LeetCode 778

  ★[C][ ] (M) Cheapest Flights Within K Stops.
              Modified Dijkstra / Bellman-Ford with K constraint.
              Asked at: Amazon, Google, Microsoft — LeetCode 787

--------------------------------------------------------------------------------
3H. MISCELLANEOUS HEAP PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) K closest points to origin from a list of 2D points.
             Use max-heap of size K keyed by distance.
             O(N log K).
             Asked at: Amazon, Google, Microsoft, Facebook/Meta — LeetCode 973

  [C][ ] (M) Find maximum sum of K non-overlapping pairs from array.
             Precompute max pair sum from left and right using two heaps.
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Minimum cost to hire K workers.
             Sort by quality/wage ratio; use max-heap of qualities, slide the ratio.
             O(N log N).
             Asked at: Google, Facebook/Meta — LeetCode 857

  [C][ ] (M) Implement a task scheduler with priority:
             tasks arrive with priority, execute highest priority first.
             If same priority, execute in arrival order (FIFO).
             Use max-heap with custom comparator.
             Asked at: Amazon, Microsoft, Dolat Capital

  ★[C][ ] (M) Find the smallest range that includes at least one number
              from each of K sorted lists.
              Min-heap of current front elements + track global max.
              O(N log K).
              Asked at: Google, Goldman Sachs — LeetCode 632

  ★[C][ ] (M) Given arrival and departure times, find peak simultaneous events.
              Event sweep with min-heap of end times.
              Asked at: Amazon, Goldman Sachs

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement Dijkstra's algorithm from scratch using a custom min-heap
             (without using STL priority_queue — show decrease-key operation).
             Asked at: Google, Goldman Sachs, Dolat Capital

  [C][ ] (H) Find the median of a matrix where each row and column is sorted.
             Binary search on value + count elements <= mid — O(N log(max-min)).
             Asked at: Google, Goldman Sachs, Amazon

  [C][ ] (H) Find the smallest range covering at least one element from each of K sorted lists.
             Min-heap of current elements + track global max — O(N log K).
             Asked at: Google, Goldman Sachs, Amazon — LeetCode 632

  [C][ ] (H) Merge K sorted arrays of different sizes — no STL sort allowed.
             Min-heap with (value, array_idx, element_idx) — O(N log K).
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Merge K sorted linked lists using min-heap.
             O(N log K) where N = total nodes.
             Asked at: Amazon, Google, Microsoft, Facebook/Meta

  [C][ ] (H) Implement a generic priority queue that supports:
             push(), pop(), top(), AND update_priority(element, new_priority).
             (decrease-key operation — needed for Dijkstra with dense graphs)
             Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Implement a min-heap that supports:
              insert, extractMin, decreaseKey(index, newVal), delete(index).
              All operations O(log N). Use position map for O(1) index lookup.
              Asked at: Google, Goldman Sachs, Dolat Capital

  ★[C][ ] (H) Find the Kth smallest element across N sorted arrays.
              Binary search + heap combination — O(N log(max * K)).
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Given a stream of integers and queries for Kth largest,
              handle both inserts and deletes efficiently.
              Use an order-statistics tree or two heaps.
              Asked at: Goldman Sachs, Dolat Capital

  ★[C][ ] (H) Maximum CPU load: given list of jobs with start, end, load,
              find the maximum CPU load at any point in time.
              Sort + min-heap of end times — O(N log N).
              Asked at: Goldman Sachs, Amazon, Dolat Capital

  ★[C][ ] (H) Trapping Rain Water II (3D grid):
              Use min-heap BFS from borders; trap water at each interior cell.
              O(M*N log(M*N)).
              Asked at: Google, Amazon — LeetCode 407

  ★[C][ ] (H) Given N projects with capital requirements and profits,
              maximize capital after completing at most K projects starting with W capital.
              Two heaps: min-heap by capital, max-heap by profit (IPO variant).
              Asked at: Amazon, Goldman Sachs, Google

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output?
          priority_queue<int> pq;
          pq.push(3); pq.push(1); pq.push(4); pq.push(1); pq.push(5);
          while (!pq.empty()) { cout << pq.top() << " "; pq.pop(); }
          (Output: 5 4 3 1 1 — max-heap order, allows duplicates)
          Asked at: TCS, Wipro, Amazon

  ★[T][ ] How do you make a min-heap that stores pairs, ordered by second element?
          priority_queue<pair<int,int>, vector<pair<int,int>>,
                         greater<pair<int,int>>> pq;
          (Pairs compared lexicographically — first by .first, then .second)
          Asked at: Amazon, Google, Flipkart

  ★[T][ ] Why is this wrong?
          priority_queue<int> pq = {5, 3, 1};  // COMPILE ERROR
          (priority_queue has no initializer-list constructor;
           use: for (auto x : {5,3,1}) pq.push(x);)
          Asked at: TCS, Wipro, Persistent

  ★[T][ ] What is the time complexity of building a heap from N elements
          by pushing them one by one vs using make_heap?
          (push N times: O(N log N); make_heap: O(N) — bottom-up is more efficient)
          Asked at: Amazon, Google, Goldman Sachs

  ★[T][ ] Given a max-heap stored as array: [10, 5, 8, 2, 3, 6, 7]
          What is the index of the parent of element at index 4?
          What is the left child of index 2?
          (Parent of 4: (4-1)/2 = 1; left child of 2: 2*2+1 = 5)
          Asked at: TCS, Wipro, Samsung, Amazon

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — Heap Internals                       |  8 |  0 |  0 |     8
  Theory — std::priority_queue STL              | 12 |  0 |  0 |    12
  Coding Easy — Heap from Scratch               |  5 |  0 |  0 |     5
  Coding Easy — Classic Problems                |  5 |  0 |  0 |     5
  Coding Medium — Kth Element                   |  0 |  7 |  0 |     7
  Coding Medium — Top-K Frequency               |  0 |  5 |  0 |     5
  Coding Medium — Merge K Sorted                |  0 |  4 |  0 |     4
  Coding Medium — String / Task Scheduling      |  0 |  5 |  0 |     5
  Coding Medium — Interval / Meeting            |  0 |  6 |  0 |     6
  Coding Medium — Two-Heap                      |  0 |  4 |  0 |     4
  Coding Medium — Graph (Heap-based)            |  0 |  5 |  0 |     5
  Coding Medium — Miscellaneous                 |  0 |  6 |  0 |     6
  Coding Hard                                   |  0 |  0 | 12 |    12
  Tricky Output / Concept                       |  5 |  0 |  0 |     5
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 35 | 42 | 12 |    89

  ★ = 45 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / SAMSUNG:
    → Heap definition, min vs max heap, array representation, heapify,
      build-heap O(N) explanation, heap sort, implement max-heap from scratch

  ZOHO / PAYTM:
    → Min-heap syntax, Kth largest, connect ropes, sort nearly sorted array,
      task scheduler simulation

  AMAZON / FLIPKART / SWIGGY:
    → Kth largest element (min-heap of size K), top K frequent, merge K sorted,
      meeting rooms II, reorganize string, task scheduler, K closest points,
      median from stream, find median in sliding window

  MICROSOFT / ADOBE:
    → Kth largest in stream, sliding window median, frequency sort,
      rearrange string K apart, merge K sorted lists, Dijkstra with heap

  GOOGLE / ATLASSIAN:
    → Kth smallest in matrix, K pairs with smallest sums, smallest range from K lists,
      swim in rising water, Prim's MST, minimum cost hire K workers,
      IPO problem, Kth smallest prime fraction

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Two-heap median, decrease-key / indexed priority queue, Dijkstra from scratch,
      maximum CPU load, Kth smallest across N arrays, stream insert+delete with Kth,
      lazy deletion, d-ary heap trade-offs, IPO with two heaps

================================================================================
END
================================================================================
