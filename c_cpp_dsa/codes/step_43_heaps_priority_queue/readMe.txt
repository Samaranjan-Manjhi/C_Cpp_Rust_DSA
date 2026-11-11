================================================================================
        HEAPS (PRIORITY QUEUE) — COMPLETE QUESTION BANK
        Covers: Min/Max Heap, Heap operations, priority_queue STL,
                Heap Sort, Two-Heap pattern, K-way merge, All applications
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

  ── HEAP PROPERTIES ──────────────────────────────────────────────────────────
  • Complete Binary Tree stored as an array (no pointers needed)
  • Max-Heap: parent ≥ children for every node  (root = maximum)
  • Min-Heap: parent ≤ children for every node  (root = minimum)
  • Heap does NOT guarantee full sorted order — only root is min/max

  ── ARRAY INDEXING (1-indexed) ───────────────────────────────────────────────
  Parent of i     = i / 2
  Left child of i = 2 * i
  Right child of i= 2 * i + 1

  ── ARRAY INDEXING (0-indexed) ───────────────────────────────────────────────
  Parent of i     = (i - 1) / 2
  Left child of i = 2 * i + 1
  Right child of i= 2 * i + 2

  ── CORE OPERATIONS & COMPLEXITIES ──────────────────────────────────────────

  Operation        │ Time      │ Notes
  ─────────────────┼───────────┼────────────────────────────────────────────
  insert (push)    │ O(log N)  │ Add at end; heapify-up (sift up)
  extract min/max  │ O(log N)  │ Remove root; move last to root; heapify-down
  peek (top)       │ O(1)      │ Root element
  build heap       │ O(N)      │ NOT O(N log N) — heapify from N/2 to 0
  heap sort        │ O(N log N)│ Build max-heap + N extractions; IN-PLACE
  decrease-key     │ O(log N)  │ Update value; heapify-up
  delete arbitrary │ O(log N)  │ decrease-key to -∞; extract-min

  ── WHY BUILD-HEAP IS O(N) NOT O(N log N) ───────────────────────────────────
  Heapify starts from the LAST non-leaf (index N/2) downward to root.
  Nodes near the bottom (majority) have very short sift-down paths.
  Mathematical sum: Σ h × N/2^(h+1) for h=1..log N = O(N).

  ── STL USAGE ────────────────────────────────────────────────────────────────
  #include <queue>

  priority_queue<int> maxpq;                                // max-heap (default)
  priority_queue<int, vector<int>, greater<int>> minpq;     // min-heap

  maxpq.push(x);   maxpq.top();   maxpq.pop();   maxpq.size();   maxpq.empty();

  // Custom comparator — max-heap by second element of pair
  auto cmp = [](pair<int,int>& a, pair<int,int>& b){ return a.second < b.second; };
  priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

  ── MUST-KNOW PATTERNS ───────────────────────────────────────────────────────

  1. TOP-K LARGEST   → Min-heap of size K; pop when size > K; answer = heap
  2. TOP-K SMALLEST  → Max-heap of size K; pop when size > K; answer = heap
  3. K-TH LARGEST    → Min-heap of size K; top() is Kth largest
  4. RUNNING MEDIAN  → Two heaps: max-heap (lower half) + min-heap (upper half)
     Invariant: lo.size() >= hi.size(), |lo.size()-hi.size()| ≤ 1
     Median = lo.top() if odd total, else (lo.top()+hi.top())/2.0
  5. K-WAY MERGE     → Min-heap of (value, list_index, element_index)
     Extract min; push next from same list

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a heap? What are its properties?
         (Complete binary tree; max-heap: parent ≥ children; min-heap: parent ≤ children)
         Asked at: TCS, Wipro, Amazon, Microsoft

  [T][ ] What is the difference between min-heap and max-heap?
         (min-heap: root = minimum; max-heap: root = maximum)
         Asked at: TCS, Wipro, Amazon

  [T][ ] How is a heap represented as an array? Give the index formulas.
         (0-indexed: left=2i+1, right=2i+2, parent=(i-1)/2)
         Asked at: TCS, Amazon, Microsoft, Goldman Sachs

  [T][ ] What is the time complexity of insert and extract in a heap?
         (Both O(log N) — sift-up / sift-down traverses at most height of tree)
         Asked at: Amazon, TCS, Wipro, Google

  [T][ ] What is heapify? What is its time complexity?
         (Sift-down operation to restore heap property; O(log N) single call)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] Why is build-heap O(N) and not O(N log N)?
         (Start heapify from last non-leaf N/2; leaf nodes do no work;
          mathematical series converges to O(N))
         Asked at: Amazon, Google, Goldman Sachs, competitive programming

  [T][ ] How do you implement a min-heap using C++ STL?
         (priority_queue<int, vector<int>, greater<int>> pq;)
         Asked at: TCS, Wipro, Amazon, Microsoft

  [T][ ] What is heap sort? Is it stable? What are its properties?
         (Build max-heap O(N); extract max N times O(N log N); IN-PLACE O(1) space;
          NOT stable — equal elements may swap during heapify)
         Asked at: Amazon, Microsoft, TCS, Goldman Sachs

  [T][ ] What is the difference between a heap and a BST?
         (Heap: only root is min/max, O(1) peek, no search; O(log N) insert/extract;
          BST: full sorted access, O(log N) search, inorder=sorted)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is the time complexity of finding the Kth largest element using a heap?
         (Min-heap of size K: O(N log K); every element pushes once, pops at most once)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  ★[T][ ] What is a Fibonacci heap? When is it used?
           (Amortized O(1) for insert and decrease-key; O(log N) extract-min;
            used in Dijkstra for dense graphs to achieve O(E + V log V))
           Asked at: Google, Goldman Sachs, competitive programming, advanced DS

  ★[T][ ] What is the difference between priority_queue and multiset for top-K problems?
           (priority_queue: O(log N) push/pop, no iteration;
            multiset: O(log N) insert/erase, supports iteration + begin()/end();
            use multiset when you need to erase a specific element e.g. sliding window median)
           Asked at: Google, Goldman Sachs, Amazon

  ★[T][ ] How do you efficiently delete an arbitrary element from a heap?
           (Decrease-key to −∞; extract-min; requires index map for O(log N);
            STL priority_queue does NOT support this directly)
           Asked at: Google, Goldman Sachs, Dolat Capital

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Build a max-heap from unsorted array — show heapify process step by step
             Start from index N/2-1 down to 0; sift-down each
             Asked at: TCS, Amazon, Samsung

  [C][ ] (E) Implement heapify-up and heapify-down from scratch
             Then implement full extract-min
             Asked at: Amazon, Google, competitive programming

  [C][ ] (E) Given max-heap array, verify it satisfies heap property
             Check arr[(i-1)/2] >= arr[i] for all i > 0
             Asked at: TCS, Amazon

  [C][ ] (E) Find the Kth smallest element in a max-heap
             Extract max K times — O(K log N)
             Asked at: Amazon, Flipkart

  [C][ ] (E) Given N ropes, connect them with minimum total cost
             Always connect two shortest ropes; min-heap; O(N log N)
             Asked at: Amazon, Flipkart, Paytm, Goldman Sachs

  [C][ ] (E) Sort a nearly-sorted array where each element is at most K positions
             away from its sorted position — min-heap of size K+1; O(N log K)
             Asked at: Amazon, Microsoft

  ★[C][ ] (E) Find the maximum element in a min-heap without extra space
              (Scan only the leaf nodes — they occupy indices N/2 to N-1)
              Asked at: TCS, Amazon

  ★[C][ ] (E) Check if a given array is a valid max-heap
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Implement heap sort from scratch on an integer array
              Build max-heap; repeatedly swap root with last; heapify-down
              Asked at: TCS, Amazon, Goldman Sachs

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── TOP-K PROBLEMS ───────────────────────────────────────────────────────────

  [C][ ] (M) Kth largest element in array (min-heap of size K)
             Asked at: Amazon, Microsoft, Google, Flipkart, Goldman Sachs

  [C][ ] (M) Top K frequent elements (frequency map + min-heap of size K)
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) K closest points to origin (max-heap of size K by distance)
             Asked at: Amazon, Google, Microsoft, Facebook/Meta

  [C][ ] (M) Find Kth largest element in a stream
             Maintain min-heap of size K; top() is Kth largest on each insert
             Asked at: Amazon, Microsoft, Flipkart, Paytm

  [C][ ] (M) Given N sorted arrays each of size K, find element at overall Kth position
             Min-heap of (element, array_index, element_index); extract K times
             Asked at: Amazon, Google, Goldman Sachs

  ── RUNNING MEDIAN ───────────────────────────────────────────────────────────

  [C][ ] (M) Find median from a data stream — two heaps
             Max-heap (lower half) + min-heap (upper half); rebalance on each insert
             Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [C][ ] (M) Sliding window median — find median of every window of size K
             Two heaps with lazy deletion (mark removed; clean when they reach top)
             O(N log K)
             Asked at: Amazon, Google, competitive programming

  ── SCHEDULING ───────────────────────────────────────────────────────────────

  [C][ ] (M) Task scheduler — minimum total intervals to finish all tasks with cooldown N
             Max-heap of task frequencies; greedily pick most frequent available task
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Reorganize string — rearrange so no two adjacent characters are same
             Max-heap of (frequency, char); greedily pick most frequent not used last
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Meeting rooms II — minimum number of meeting rooms needed
             Sort by start; min-heap of end times; pop when room frees up; O(N log N)
             Asked at: Amazon, Microsoft, Google, Atlassian, Goldman Sachs

  [C][ ] (M) Schedule tasks to minimize total waiting time
             Sort ascending by duration; weight by remaining tasks count
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Frequency sort using max-heap
             Count frequencies; max-heap keyed by frequency; extract and append
             Asked at: Amazon, Flipkart, Swiggy

  ── MERGE & K-WAY ────────────────────────────────────────────────────────────

  [C][ ] (M) Merge K sorted linked lists — min-heap; O(N log K)
             Push head of each list; extract min; push next from same list
             Asked at: Amazon, Google, Microsoft, Goldman Sachs

  [C][ ] (M) Merge K sorted arrays of different sizes into one sorted array
             Min-heap with (value, array_idx, element_idx); O(N log K)
             Asked at: Amazon, Google, Goldman Sachs

  ── OPTIMIZATION / GREEDY WITH HEAP ─────────────────────────────────────────

  [C][ ] (M) Minimum cost to hire K workers
             Sort by wage/quality ratio; max-heap of quality; sliding window
             O(N log N + N log K)
             Asked at: Google, Facebook/Meta

  [C][ ] (M) IPO problem — maximize capital by completing at most K projects
             Min-heap by capital requirement; max-heap by profit for available projects
             Asked at: Amazon, Google, Goldman Sachs, LeetCode

  [C][ ] (M) Minimum cost to connect all points (Prim's MST with min-heap)
             Asked at: Amazon, Google, Flipkart

  [C][ ] (M) Find the maximum sum of K non-overlapping pairs from array
             Precompute max pair sum from left and right using heaps; combine
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Given list of jobs with start, end, profit — find max profit
             with no two overlapping jobs (sort by end; min-heap + binary search)
             Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Kth smallest element in a sorted matrix
              (binary search approach OR min-heap approach; compare both)
              Min-heap: push first column; pop and push right neighbor; extract K times
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Minimum number of refueling stops (max-heap greedy)
              For each station passed, add its fuel to max-heap; when car stops,
              greedily use largest available fuel
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Maximum performance of a team: pick at most K engineers to maximize
              min_speed × sum_efficiency
              Sort by efficiency desc; min-heap of size K for speeds
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Find the K pairs with smallest sums from two sorted arrays
              Min-heap of (a[i]+b[j], i, j); push (i, j+1) after each pop
              Asked at: Amazon, Google, Goldman Sachs

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Find the median of a matrix where each row and column is sorted
             Binary search + count elements ≤ mid; O(32 × N log N)
             Asked at: Google, Goldman Sachs, Amazon

  [C][ ] (H) Find the smallest range covering at least one element from each of K sorted lists
             Min-heap of current K elements + track global maximum; slide max upward
             Asked at: Google, Goldman Sachs, Amazon

  [C][ ] (H) For each window of size K, find both min and max simultaneously — O(N)
             Two monotonic deques (one increasing, one decreasing)
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Implement Dijkstra's shortest path using a custom min-heap
             Show decrease-key operation explicitly (index map + min-heap)
             Asked at: Google, Goldman Sachs, Dolat Capital

  [C][ ] (H) Merge K sorted linked lists — also implement with divide-and-conquer
             Compare heap O(N log K) vs divide-and-conquer O(N log K) — same complexity
             Asked at: Amazon, Google, Microsoft, Facebook/Meta

  ★[C][ ] (H) Implement a min-heap class from scratch with:
              insert, extractMin, decreaseKey, buildHeap — all from array
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Design a data structure with O(1) insert, O(log N) extractMax, and
              O(1) getMax — augmented heap with lazy operations
              Asked at: Goldman Sachs, Dolat Capital, HFT roles

  ★[C][ ] (H) Given array, find the maximum XOR of any two elements
              Trie + greedy; or convert to heap problem with bit-masking
              Asked at: Amazon, Google

  ★[C][ ] (H) Rearrange string K distance apart: no same characters within K positions
              Max-heap + queue of size K for cooldown; greedy character placement
              Asked at: Amazon, Google, Airbnb

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          HEAP TYPE & PATTERN
  ─────────────────────────────────────────────────────────────────────────
  Top-K largest                         Min-heap of size K; pop when > K
  Top-K smallest                        Max-heap of size K; pop when > K
  Kth largest element                   Min-heap size K; return top()
  Kth smallest element                  Max-heap size K; return top()
  Kth largest in stream                 Min-heap size K; update on each insert
  Running median                        Max-heap (lo) + Min-heap (hi); balance
  Sliding window median                 Two heaps with lazy deletion
  Merge K sorted lists/arrays           Min-heap with (val, list_idx, elem_idx)
  Connect K ropes (min cost)            Min-heap; always merge two smallest
  Task scheduler with cooldown          Max-heap + cooldown queue
  Reorganize string                     Max-heap + last-used tracking
  Meeting rooms (min count)             Sort by start; min-heap of end times
  Sort nearly-sorted (K positions)      Min-heap of size K+1
  IPO / Capital projects                Min-heap by cost + Max-heap by profit
  Dijkstra / Prim's MST                 Min-heap of (dist, node)
  Smallest range from K lists           Min-heap + global max tracking

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Heapify-down (max-heap, 0-indexed)
  void heapifyDown(vector<int>& h, int i, int n) {
      int largest = i, l = 2*i+1, r = 2*i+2;
      if (l < n && h[l] > h[largest]) largest = l;
      if (r < n && h[r] > h[largest]) largest = r;
      if (largest != i) { swap(h[i], h[largest]); heapifyDown(h, largest, n); }
  }
  // Build max-heap: for(int i=n/2-1; i>=0; i--) heapifyDown(h,i,n);

  // Top-K largest using min-heap
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int x : arr) {
      pq.push(x);
      if ((int)pq.size() > k) pq.pop();
  }
  // pq contains K largest; pq.top() = Kth largest

  // Running median — two heaps
  priority_queue<int> lo;                              // max-heap (lower half)
  priority_queue<int,vector<int>,greater<int>> hi;     // min-heap (upper half)
  void addNum(int num) {
      lo.push(num);
      hi.push(lo.top()); lo.pop();             // balance: push best of lo to hi
      if (lo.size() < hi.size()) { lo.push(hi.top()); hi.pop(); } // lo >= hi
  }
  double getMedian() {
      return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) / 2.0;
  }

  // K-way merge — min-heap
  vector<int> mergeKArrays(vector<vector<int>>& arrs) {
      using T = tuple<int,int,int>;  // (value, arr_idx, elem_idx)
      priority_queue<T, vector<T>, greater<T>> pq;
      for (int i = 0; i < arrs.size(); i++)
          if (!arrs[i].empty()) pq.push({arrs[i][0], i, 0});
      vector<int> res;
      while (!pq.empty()) {
          auto [val, i, j] = pq.top(); pq.pop();
          res.push_back(val);
          if (j+1 < arrs[i].size()) pq.push({arrs[i][j+1], i, j+1});
      }
      return res;
  }

  // Meeting rooms II — min-heap of end times
  int minMeetingRooms(vector<pair<int,int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      priority_queue<int, vector<int>, greater<int>> pq; // min-heap of end times
      for (auto& [s, e] : intervals) {
          if (!pq.empty() && pq.top() <= s) pq.pop(); // room freed
          pq.push(e);
      }
      return pq.size();
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 10 |  0 |  0 |    10
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   |  6 |  0 |  0 |     6
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 17 |  0 |    17
  Coding Medium (★ added)    |  0 |  4 |  0 |     4
  Coding Hard (from files)   |  0 |  0 |  5 |     5
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 22 | 21 |  9 |    52

================================================================================
END
================================================================================
