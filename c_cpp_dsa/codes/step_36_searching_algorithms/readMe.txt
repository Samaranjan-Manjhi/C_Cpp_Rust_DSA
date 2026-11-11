================================================================================
        SEARCHING ALGORITHMS — COMPLETE QUESTION BANK
        Covers: Linear Search, Binary Search, Binary Search on Answer,
                Search in 2D Matrix, Ternary Search, Exponential Search,
                Jump Search, Interpolation Search, STL Search Functions
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

  ── ALL SEARCH ALGORITHMS AT A GLANCE ──────────────────────────────────────

  Algorithm              │ Time       │ Space  │ Prerequisite    │ Use Case
  ───────────────────────┼────────────┼────────┼─────────────────┼────────────────────
  Linear Search          │ O(N)       │ O(1)   │ None            │ Unsorted / small data
  Binary Search          │ O(log N)   │ O(1)   │ Sorted          │ Classic search
  Jump Search            │ O(√N)      │ O(1)   │ Sorted          │ When back-tracking costly
  Interpolation Search   │ O(log log N)│ O(1)  │ Sorted+uniform  │ Uniformly distributed
  Exponential Search     │ O(log N)   │ O(1)   │ Sorted (unbounded)│ Infinite/unknown-size arrays
  Fibonacci Search       │ O(log N)   │ O(1)   │ Sorted          │ Minimize comparisons
  Ternary Search         │ O(log₃ N)  │ O(1)   │ Unimodal fn     │ Find min/max of unimodal fn
  Binary Search on Answer│ O(N log V) │ O(1)   │ Monotonic pred  │ Minimize/maximize answer

  ── BINARY SEARCH — EXACT TEMPLATE ─────────────────────────────────────────

  // Classic — find exact value
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;   // NEVER (lo+hi)/2 — overflow risk!
      if (arr[mid] == target) return mid;
      if (arr[mid] < target)  lo = mid + 1;
      else                    hi = mid - 1;
  }
  return -1;

  // lower_bound — first index where arr[i] >= target
  int lo = 0, hi = n;
  while (lo < hi) { int mid = lo+(hi-lo)/2; if(arr[mid] < target) lo=mid+1; else hi=mid; }
  return lo;   // lo == n means not found

  // upper_bound — first index where arr[i] > target
  int lo = 0, hi = n;
  while (lo < hi) { int mid = lo+(hi-lo)/2; if(arr[mid] <= target) lo=mid+1; else hi=mid; }
  return lo;

  ── BINARY SEARCH ON ANSWER — KEY PATTERN ───────────────────────────────────

  When to use: The answer lies in a range [lo, hi] and you can write a
               predicate check(mid) that is monotonically true/false.
               "Find minimum X such that check(X) is true."

  int lo = min_possible, hi = max_possible, ans = hi;
  while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (check(mid)) { ans = mid; hi = mid - 1; }   // try smaller
      else             lo = mid + 1;
  }
  return ans;

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is binary search? What is the prerequisite for using it?
         (Array must be sorted; finds element in O(log N))
         Asked at: TCS, Wipro, Infosys, Amazon, Microsoft

  [T][ ] Why use lo + (hi - lo) / 2 instead of (lo + hi) / 2?
         (Prevents integer overflow when lo and hi are both large)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is the difference between lower_bound and upper_bound?
         (lower_bound: first element >= x; upper_bound: first element > x)
         Asked at: Amazon, Flipkart, Google, Goldman Sachs

  [T][ ] What is the difference between find() and binary_search() in STL?
         (find: O(N) linear, works unsorted, returns iterator;
          binary_search: O(log N), requires sorted, returns bool only)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] When should you use lower_bound vs upper_bound?
         (lower_bound: find insertion point or first occurrence;
          upper_bound: count occurrences, find range end)
         Asked at: Amazon, competitive programming

  [T][ ] What is the "binary search on the answer" technique? When is it applicable?
         (Binary search on answer value when feasibility is monotonic;
          applicable when: "find minimum X such that condition holds")
         Asked at: Amazon, Flipkart, Google

  [T][ ] What is exponential search? When is it useful over binary search?
         (Find range [2^k, 2^(k+1)] then binary search within it;
          useful when array is unbounded/infinite — finds element in O(log N))
         Asked at: Competitive programming, Google

  [T][ ] What is interpolation search? When does it outperform binary search?
         (Estimates position using value: pos = lo + (hi-lo)*(target-arr[lo])/(arr[hi]-arr[lo]);
          O(log log N) for uniformly distributed data; degrades to O(N) worst case)
         Asked at: Google, Goldman Sachs, competitive programming

  [T][ ] What is ternary search? What type of function does it work on?
         (Divides into 3 parts; works on unimodal functions — find min/max;
          does NOT work for sorted array search — use binary search there)
         Asked at: Competitive programming, Google

  [T][ ] What is jump search? What is the optimal block size?
         (Jump √N steps at a time, then linear scan backward;
          optimal block size = √N; O(√N) time)
         Asked at: TCS, Wipro, competitive programming

  ★[T][ ] How does binary search apply to "find the first/last occurrence" problems?
           (Modify the condition to not stop at first match —
            continue searching left half for first, right half for last)
           Asked at: Amazon, Microsoft, Flipkart

  ★[T][ ] What is the condition for binary search to work correctly on rotated arrays?
           (At least one half is always sorted; determine which half, check if
            target falls in sorted half, else search the other)
           Asked at: Amazon, Microsoft, Google, Flipkart

  ★[T][ ] What happens if binary search is applied on an unsorted array?
           (Undefined behavior — may return wrong answer or not find element
            even if it exists)
           Asked at: TCS, Wipro, Amazon

  ★[T][ ] What is Fibonacci search and how does it differ from binary search?
           (Uses Fibonacci numbers to divide array; eliminates division operation;
            useful when division is expensive e.g. magnetic disk/tape)
           Asked at: Competitive programming, advanced algorithm roles

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── LINEAR SEARCH ───────────────────────────────────────────────────────────

  ★[C][ ] (E) Implement linear search — find first and last occurrence
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Find the minimum and maximum element in unsorted array (linear scan)
              Asked at: TCS, Wipro, Infosys, Capgemini

  ── BINARY SEARCH FUNDAMENTALS ──────────────────────────────────────────────

  [C][ ] (E) Binary search — find index of target in sorted array
             Implement from scratch (no STL)
             Asked at: TCS, Amazon, Microsoft, Google

  [C][ ] (E) Find the number of occurrences of target in a sorted array
             upper_bound - lower_bound
             Asked at: Amazon, Flipkart, TCS

  [C][ ] (E) Find the position to insert a new element in a sorted array
             (same as lower_bound concept)
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Find the floor (largest element <= x) in a sorted array
             Binary search variant — track last valid lo
             Asked at: Amazon, Flipkart

  [C][ ] (E) Find the ceiling (smallest element >= x) in a sorted array
             Binary search variant — track last valid hi
             Asked at: Amazon, Adobe, Zoho

  [C][ ] (E) Find first occurrence of 1 in a binary array (0s then 1s)
             Binary search — go left when arr[mid] == 1
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Given sorted array rotated at unknown pivot, find if target exists
             Modified binary search — determine which half is sorted first
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (E) Find the peak element of a mountain array (increases then decreases)
             Binary search: if arr[mid] < arr[mid+1] go right, else go left
             Asked at: Amazon, Microsoft, Google

  ★[C][ ] (E) Implement binary search recursively and count number of recursive calls
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Find the only element appearing once in a sorted array where every
              other element appears exactly twice (binary search on even/odd indices)
              Asked at: Amazon, Adobe, Samsung

  ★[C][ ] (E) Implement jump search on a sorted array
              Asked at: TCS, Wipro, competitive programming

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── CLASSIC BINARY SEARCH VARIANTS ─────────────────────────────────────────

  [C][ ] (M) Search in rotated sorted array — return index
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [C][ ] (M) Find first and last position of element in sorted array
             Two binary searches: one for first, one for last
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find peak element in array (O(log N) — not just mountain array)
             Any local peak; if arr[mid] < arr[mid+1], peak is on right
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find minimum in rotated sorted array (no duplicates)
             Binary search — pivot is the minimum
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find minimum in rotated sorted array (with duplicates)
             Modified — must handle arr[lo] == arr[mid] == arr[hi] case
             Asked at: Amazon, Microsoft

  [C][ ] (M) Sqrt(x) — compute integer floor of square root using binary search
             Binary search on [0, x]; find largest mid where mid*mid <= x
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find the Kth missing positive integer in a sorted array
             Binary search on count of missing numbers before each position
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find the pivot (smallest element index) in rotated sorted array
             with duplicates allowed
             Asked at: Amazon, Microsoft

  ── BINARY SEARCH ON ANSWER ─────────────────────────────────────────────────

  [C][ ] (M) Koko eating bananas: minimum speed to eat all in H hours
             Binary search on speed [1, max(piles)]; check feasibility in O(N)
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (M) Capacity to ship packages within D days (minimize max weight)
             Binary search on capacity [max_weight, sum]; check O(N)
             Asked at: Amazon, Google, LeetCode classics

  [C][ ] (M) Minimum time to finish all jobs given M workers
             Binary search on time; check feasibility with greedy
             Asked at: Amazon, Google, Flipkart

  [C][ ] (M) Split array largest sum: split array into K parts to minimize
             the maximum subarray sum (binary search on answer)
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (M) Find minimum speed to arrive on time (LeetCode 1870)
             Binary search on speed; check if all trips fit in time
             Asked at: Amazon, Google

  ── BINARY SEARCH ON 2D STRUCTURES ─────────────────────────────────────────

  [C][ ] (M) Search a 2D matrix (each row sorted; first of row > last of prev row)
             Treat as 1D sorted array — O(log(M×N))
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Search in a 2D matrix where each row AND column is sorted
             Start from top-right corner: go left if too big, down if too small
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Find the row with maximum number of 1s in binary matrix
             (each row sorted: all 0s then all 1s)
             Binary search each row for first 1; O(M log N)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) K-th smallest element in a sorted matrix (rows and cols sorted)
             Binary search on value range + count elements <= mid
             Asked at: Amazon, Google, Microsoft

  ── OTHER VARIANTS ──────────────────────────────────────────────────────────

  [C][ ] (M) Implement recursive binary search; count number of recursive calls
             Asked at: TCS, Wipro, Amazon

  [C][ ] (M) Given K sorted arrays each of size N, find the median
             Binary search on answer range; count elements <= mid across all arrays
             Asked at: Amazon, Microsoft, competitive programming

  [C][ ] (M) Find the median in a stream of integers efficiently
             Two heaps (max + min); binary search concept for balancing
             Asked at: Amazon, Google, Microsoft, Flipkart

  [C][ ] (M) Two elements in sorted array whose sum is closest to target
             Two-pointer (binary search variant)
             Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Binary search on a sorted linked list — O(N) (show why O(log N)
              is impossible without random access; explain skip list as solution)
              Asked at: Amazon, Google, Atlassian

  ★[C][ ] (M) Implement interpolation search and show when it beats binary search
              Test on a uniformly distributed array and on a non-uniform array
              Asked at: Goldman Sachs, competitive programming, advanced roles

  ★[C][ ] (M) Find the minimum number of days to make M bouquets from a garden
              (Binary search on answer — days; feasibility check in O(N))
              Asked at: Amazon, Google, Flipkart

  ★[C][ ] (M) Aggressive cows — place K cows in N stalls to maximize minimum distance
              Binary search on minimum distance; check feasibility in O(N)
              Asked at: Amazon, competitive programming (very common!)

  ★[C][ ] (M) Painters partition problem: minimize maximum time among K painters
              Binary search on answer; check feasibility in O(N)
              Asked at: Amazon, Flipkart, Goldman Sachs

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Median of two sorted arrays — O(log(min(m, n)))
             Binary search on smaller array; find correct partition
             Asked at: Google, Amazon, Microsoft, Facebook/Meta

  [C][ ] (H) Split array largest sum (hard version with constraints)
             Binary search on max sum; DP or greedy for feasibility
             Asked at: Google, Amazon, Facebook/Meta

  [C][ ] (H) Find the K-th smallest element in a multiplication table N × N
             Binary search on answer; count elements <= mid
             Asked at: Google, Amazon

  [C][ ] (H) Find the K-th smallest pair distance in an array
             Sort; binary search on distance + two-pointer count
             Asked at: Google, Amazon, Goldman Sachs

  ★[C][ ] (H) Find the K-th smallest number in a sorted matrix using binary search
              (Not heap approach — pure binary search on value range)
              Asked at: Google, Amazon, Goldman Sachs

  ★[C][ ] (H) Given N ropes, cut them to get K pieces of maximum equal length
              Binary search on length; feasibility = sum of floor(rope/mid) >= K
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (H) Book allocation: N books with pages[], M students — minimize maximum
              pages assigned to a student
              Binary search on answer; greedy check in O(N)
              Asked at: Amazon, Flipkart, Goldman Sachs (classic!)

  ★[C][ ] (H) Find the smallest divisor given a threshold
              Binary search on divisor; check sum of ceil(arr[i]/d) <= threshold
              Asked at: Amazon, Google, LeetCode

  ★[C][ ] (H) Minimum number of days to make M bouquets
              Binary search on days; greedy consecutive bloom check
              Asked at: Amazon, Google

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ─────────────────────────────────────────────────────────────────────────
  Find element in sorted array          Classic binary search
  First / last occurrence               Binary search; don't stop at match
  Count occurrences                     upper_bound - lower_bound
  Floor / Ceiling                       Binary search; track last valid answer
  Search rotated sorted array           Identify sorted half; check if target in it
  Search 2D matrix (row>prev last)      Treat as 1D array — index math
  Search 2D matrix (row+col sorted)     Start top-right; move left or down
  Peak element                          If arr[mid]<arr[mid+1], go right
  Kth missing integer                   Binary search on count of missing
  Minimize maximum (partition problems) Binary search on answer; greedy check
  Maximize minimum (aggressive cows)    Binary search on answer; greedy check
  Unknown-size sorted array             Exponential search to find range first
  Unimodal function min/max             Ternary search
  Uniformly distributed data            Interpolation search

================================================================================
QUICK REFERENCE — Common Templates
================================================================================

  // First occurrence
  int firstOccurrence(vector<int>& a, int t) {
      int lo=0, hi=a.size()-1, res=-1;
      while(lo<=hi){ int mid=lo+(hi-lo)/2;
          if(a[mid]==t){ res=mid; hi=mid-1; }
          else if(a[mid]<t) lo=mid+1; else hi=mid-1; }
      return res;
  }

  // Binary search on answer (minimize)
  int solve(vector<int>& a, int k) {
      int lo=1, hi=*max_element(a.begin(),a.end()), ans=hi;
      while(lo<=hi){ int mid=lo+(hi-lo)/2;
          if(check(a, mid, k)){ ans=mid; hi=mid-1; } else lo=mid+1; }
      return ans;
  }

  // Search rotated sorted array
  int searchRotated(vector<int>& a, int t) {
      int lo=0, hi=a.size()-1;
      while(lo<=hi){ int mid=lo+(hi-lo)/2;
          if(a[mid]==t) return mid;
          if(a[lo]<=a[mid]){  // left half sorted
              if(a[lo]<=t && t<a[mid]) hi=mid-1; else lo=mid+1;
          } else {            // right half sorted
              if(a[mid]<t && t<=a[hi]) lo=mid+1; else hi=mid-1; }
      }
      return -1;
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 10 |  0 |  0 |    10
  Theory (★ added)           |  4 |  0 |  0 |     4
  Coding Easy (from files)   | 10 |  0 |  0 |    10
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 18 |  0 |    18
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  4 |     4
  Coding Hard (★ added)      |  0 |  0 |  5 |     5
  ---------------------------|----|----|----|---------
  TOTAL                      | 27 | 23 |  9 |    59

================================================================================
END
================================================================================
