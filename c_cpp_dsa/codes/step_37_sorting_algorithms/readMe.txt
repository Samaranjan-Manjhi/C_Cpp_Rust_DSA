i================================================================================
        SORTING ALGORITHMS — COMPLETE QUESTION BANK
        Covers: Bubble, Selection, Insertion, Merge, Quick, Heap, Counting,
                Radix, Bucket, Shell, Tim Sort, Dutch National Flag,
                Comparison Table, Stability, Real Interview Problems
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

  ── MASTER COMPARISON TABLE ─────────────────────────────────────────────────

  Algorithm        │ Best      │ Average   │ Worst     │ Space  │ Stable │ Notes
  ─────────────────┼───────────┼───────────┼───────────┼────────┼────────┼─────────────────
  Bubble Sort      │ O(N)      │ O(N²)     │ O(N²)     │ O(1)   │ YES    │ Best if nearly sorted
  Selection Sort   │ O(N²)     │ O(N²)     │ O(N²)     │ O(1)   │ NO     │ Min swaps = N-1
  Insertion Sort   │ O(N)      │ O(N²)     │ O(N²)     │ O(1)   │ YES    │ Best for nearly sorted
  Merge Sort       │ O(N log N)│ O(N log N)│ O(N log N)│ O(N)   │ YES    │ Best for linked lists
  Quick Sort       │ O(N log N)│ O(N log N)│ O(N²)     │ O(log N)│ NO   │ Best in practice (cache)
  Heap Sort        │ O(N log N)│ O(N log N)│ O(N log N)│ O(1)   │ NO    │ O(1) space + O(N log N)
  Counting Sort    │ O(N+K)    │ O(N+K)    │ O(N+K)    │ O(K)   │ YES    │ Only integers in [0,K]
  Radix Sort       │ O(d(N+K)) │ O(d(N+K)) │ O(d(N+K)) │ O(N+K) │ YES    │ d=digits, K=base (10)
  Bucket Sort      │ O(N+K)    │ O(N+K)    │ O(N²)     │ O(N+K) │ YES*   │ Uniform distribution
  Shell Sort       │ O(N log N)│ O(N log²N)│ O(N²)     │ O(1)   │ NO     │ Improved insertion sort
  Tim Sort         │ O(N)      │ O(N log N)│ O(N log N)│ O(N)   │ YES    │ Python default; Java objects
  Introsort        │ O(N log N)│ O(N log N)│ O(N log N)│ O(log N)│ NO   │ C++ std::sort — hybrid

  ── KEY DECISION GUIDE ──────────────────────────────────────────────────────

  When to use what:
    Nearly sorted data      → Insertion Sort or Bubble Sort (O(N) best case)
    Stability required      → Merge Sort or Tim Sort
    O(1) extra space needed → Heap Sort or Insertion Sort
    Linked list             → Merge Sort (no random access needed)
    Integers in small range → Counting Sort or Radix Sort
    General purpose (best)  → Quick Sort (avg) / Introsort (std::sort)
    External sorting        → Merge Sort (disk-friendly)
    K-sorted array          → Min-heap of size K+1 → O(N log K)

  ── STABILITY MATTERS WHEN ──────────────────────────────────────────────────

  You sort by key A, then sort by key B — elements with equal key B should
  maintain their relative order from the A-sort. Only stable sorts guarantee this.
  Example: sort students by name, then by grade — need stability.

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] Compare all sorting algorithms: time, space, stability, use case
         Asked at: Amazon, Microsoft, Google, TCS, Wipro, Goldman Sachs

  [T][ ] When would you use insertion sort over merge sort?
         (Nearly sorted data — O(N) best case; small arrays where O(N²) is acceptable)
         Asked at: Amazon, TCS, Wipro

  [T][ ] What is the best sorting algorithm for nearly-sorted data?
         (Insertion Sort — O(N) best case; also Timsort exploits existing runs)
         Asked at: Amazon, Google, Goldman Sachs

  [T][ ] Why is quick sort preferred in practice despite O(N²) worst case?
         (Better cache locality, in-place, small constants, random pivot avoids worst case)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is introsort? What does std::sort use internally?
         (Hybrid: quicksort → heapsort when depth exceeds 2log₂N → insertion sort for small N)
         Asked at: Competitive programming, Google, advanced C++ roles

  [T][ ] What is the difference between comparison and non-comparison sorts?
         (Comparison: use < or > — lower bound Ω(N log N);
          Non-comparison: counting, radix, bucket — can achieve O(N))
         Asked at: Amazon, Microsoft, Google

  [T][ ] When would you use counting sort over merge sort?
         (Integer keys in bounded small range; O(N+K) beats O(N log N) when K is small)
         Asked at: Amazon, TCS, Wipro

  [T][ ] What is external sorting? When do you need it?
         (Data doesn't fit in RAM; split into sorted chunks, K-way merge)
         Asked at: Google, Microsoft, Goldman Sachs, database companies

  [T][ ] What is a stable sort? Why does stability matter?
         (Equal elements maintain original relative order; needed for multi-key sorts)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] Is quick sort stable? Is heap sort stable?
         (Both are NOT stable — equal elements may swap during partition/heapify)
         Asked at: Amazon, TCS, Wipro

  [T][ ] What is the worst case for quick sort? How do you avoid it?
         (Already sorted array with naive pivot — O(N²); fix: random pivot or median-of-3)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] When would you choose merge sort over quick sort? And vice versa?
         (Merge: stable, O(N log N) guaranteed, linked lists, external sort;
          Quick: in-place, better cache, faster avg in practice)
         Asked at: Amazon, Microsoft, Flipkart

  [T][ ] What is counting sort? What are its limitations?
         (Only for integers; requires O(K) space; fails for large K or negative keys)
         Asked at: Amazon, TCS, Wipro

  [T][ ] What is radix sort? How does it handle multi-digit numbers?
         (Sort digit by digit from least significant to most significant;
          must use stable sort for each digit pass — counting sort used per digit)
         Asked at: Amazon, Google, Goldman Sachs

  ★[T][ ] What is the theoretical lower bound for comparison-based sorting? Prove it.
           (Ω(N log N) — decision tree has N! leaves; height >= log₂(N!) ~ N log N)
           Asked at: Google, Goldman Sachs, algorithm-heavy roles

  ★[T][ ] What is Timsort? Why is it used in Python and Java?
           (Hybrid merge + insertion sort; exploits natural runs in real-world data;
            O(N) on already sorted; O(N log N) worst; stable)
           Asked at: Google, competitive programming, Python interviews

  ★[T][ ] What is the difference between in-place sort and out-of-place sort?
           (In-place: O(1) extra space e.g. bubble, heap, quick;
            Out-of-place: O(N) extra e.g. merge sort)
           Asked at: Amazon, TCS, Wipro, Google

  ★[T][ ] How many swaps does selection sort perform?
           (Exactly N-1 swaps — minimum possible for comparison-based sort)
           Asked at: TCS, Wipro, Amazon

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── IMPLEMENT FROM SCRATCH ──────────────────────────────────────────────────

  [C][ ] (E) Implement Bubble Sort and count the number of swaps made
             Early exit optimization: if no swap in a pass, array is sorted
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Implement Selection Sort — show it is NOT stable with an example
             Find minimum in unsorted part; swap with first unsorted
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Implement Insertion Sort — show it works well on nearly-sorted arrays
             Shift elements right until correct position found
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Sort an array of strings by their lengths using std::sort + lambda
             Asked at: Amazon, Microsoft

  [C][ ] (E) Given array of 0s and 1s, sort it in O(N) using counting sort
             (Simpler version of Dutch National Flag — only 2 values)
             Asked at: TCS, Amazon, Wipro

  ★[C][ ] (E) Implement Bubble Sort with the optimisation to stop early if
              no swaps were made in a complete pass — show it's O(N) on sorted input
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Given array of strings, sort them alphabetically using insertion sort
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Sort array of integers using selection sort; count number of comparisons made
              Asked at: TCS, Wipro

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── IMPLEMENT ADVANCED SORTS ────────────────────────────────────────────────

  [C][ ] (M) Merge Sort implementation from scratch — O(N log N) O(N) space
             Divide at mid, sort halves, merge with auxiliary array
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Quick Sort implementation from scratch — random pivot version
             Partition around pivot; recurse on both halves
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Implement counting sort for array with values in range [0, K]
             Must be stable — maintain relative order of equal elements
             Asked at: Amazon, Microsoft

  [C][ ] (M) Sort array using 3-way quicksort (Dutch National Flag partitioning)
             Handles equal elements efficiently — 3 pointers: lo, mid, hi
             Asked at: Competitive programming, Amazon, Google

  ★[C][ ] (M) Implement Heap Sort from scratch
              Build max-heap (heapify); repeatedly extract max to end
              Asked at: Amazon, Microsoft, TCS, Goldman Sachs

  ★[C][ ] (M) Implement Radix Sort for array of non-negative integers
              Sort by each digit (LSD first) using stable counting sort per pass
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Implement Shell Sort with gap sequence [N/2, N/4, ..., 1]
              Show improvement over insertion sort on large arrays
              Asked at: TCS, Wipro, competitive programming

  ── APPLICATION PROBLEMS ────────────────────────────────────────────────────

  [C][ ] (M) Sort colors — Dutch National Flag (sort array of 0s, 1s, 2s)
             One pass, O(1) space — 3 pointers: lo, mid, hi
             Asked at: Amazon, Microsoft, Flipkart, Paytm, Adobe

  [C][ ] (M) Merge intervals — sort by start time, merge overlapping
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart, Goldman Sachs

  [C][ ] (M) Largest number — arrange array elements to form the largest number
             Custom comparator: compare ab vs ba as strings
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Kth largest element in array — use heap or QuickSelect O(N) avg
             Asked at: Amazon, Microsoft, Google, Flipkart, Goldman Sachs

  [C][ ] (M) Count inversions in array — modified merge sort O(N log N)
             During merge: when right element placed before left ones, count left remaining
             Asked at: Amazon, Google, Flipkart, Goldman Sachs

  [C][ ] (M) Meeting rooms II — minimum meeting rooms needed
             Sort by start; use min-heap of end times
             Asked at: Amazon, Microsoft, Google, Atlassian

  [C][ ] (M) Sort a linked list using merge sort — O(N log N) O(1) space
             Find middle (slow/fast), split, sort halves, merge
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (M) Given array of intervals, sort by start time and merge overlapping ones
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Sort array of strings such that all anagrams are adjacent
             Sort each string as key, then sort the array of (key, original) pairs
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given array, sort it by frequency of elements; tie-break by value
             Frequency map + custom comparator
             Asked at: Amazon, Flipkart, Paytm, Swiggy

  [C][ ] (M) Given two arrays A and B, sort A so relative order matches B
             Elements not in B go to end in sorted order
             Asked at: Amazon, Flipkart, Adobe

  [C][ ] (M) Merge K sorted arrays into one sorted array — O(N log K)
             Min-heap of (value, arrayIndex, elementIndex)
             Asked at: Amazon, Google, Microsoft (very common!)

  [C][ ] (M) Pancake sorting: sort using only prefix reversal operations
             Repeatedly find max in remaining, flip to front, flip to position
             Asked at: Google, competitive programming

  [C][ ] (M) Find minimum number of swaps to sort an array
             Cycle detection in permutation graph — each cycle of length k needs k-1 swaps
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (M) Sort a linked list of 0s, 1s, and 2s without changing node data
             Three dummy-head technique; re-link all 0s, then 1s, then 2s
             Asked at: Amazon, Flipkart, Paytm

  ★[C][ ] (M) Wiggle sort: rearrange array so arr[0] <= arr[1] >= arr[2] <= arr[3]...
              One-pass O(N) — swap adjacent pairs when order is violated
              Asked at: Amazon, Flipkart, Paytm

  ★[C][ ] (M) Sort array by absolute difference from a given target value K
              Custom comparator: sort by |arr[i] - K| ascending
              Asked at: TCS, Amazon, Goldman Sachs

  ★[C][ ] (M) Given array of strings, sort by number of vowels descending;
              alphabetically for ties — custom comparator
              Asked at: Amazon, Adobe

  ★[C][ ] (M) Given timestamps and events, sort by timestamp; tie-break by event type
              Stable sort ensures same-timestamp events preserve insertion order
              Asked at: Amazon, Goldman Sachs, backend roles

  ★[C][ ] (M) Find minimum swaps to make two arrays strictly increasing
              DP with state (swap at i, no swap at i)
              Asked at: Amazon, Google

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Sort a nearly sorted (K-sorted) array where each element is at most
             K positions from its sorted position — O(N log K) using min-heap
             Asked at: Amazon, Goldman Sachs

  [C][ ] (H) Sort array such that positive and negative numbers alternate
             Starting with positive, maintaining relative order — O(N) O(1) space
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (H) External sort: describe and partially implement sorting 10 GB of integers
             with only 1 GB RAM — split → sort chunks → K-way merge
             Asked at: Google, Goldman Sachs, Amazon, database companies

  [C][ ] (H) Count inversions using Binary Indexed Tree (Fenwick Tree)
             More efficient than merge sort for some competitive problems
             Asked at: Competitive programming, Dolat Capital

  [C][ ] (H) Merge K sorted linked lists — O(N log K)
             Min-heap of (value, node pointer); extract min, push next
             Asked at: Amazon, Google, Microsoft, Goldman Sachs

  ★[C][ ] (H) Implement Tim Sort: find natural runs, extend short ones with insertion sort,
              then merge runs using a stack-based merge strategy
              Asked at: Google, advanced algorithm roles

  ★[C][ ] (H) Given large array that doesn't fit in memory, describe how you would
              sort it using external merge sort — implement the merge phase
              Asked at: Google, Goldman Sachs, database engineering roles

  ★[C][ ] (H) Sort a 2D matrix row-wise and then find the Kth smallest element
              (Sort entire matrix; also discuss O(N log N) approach with heap)
              Asked at: Amazon, Microsoft, Google

  ★[C][ ] (H) Patience sorting — find the length of the Longest Increasing Subsequence
              using the patience sorting game on cards; O(N log N)
              Asked at: Amazon, Google, competitive programming

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          ALGORITHM / PATTERN
  ─────────────────────────────────────────────────────────────────────────
  General purpose                       Quick Sort / std::sort (Introsort)
  Stable required                       Merge Sort / Stable Sort / Tim Sort
  O(1) space + O(N log N)              Heap Sort
  Nearly sorted                         Insertion Sort (O(N) best case)
  Integers in bounded range             Counting Sort → Radix Sort
  Linked list sorting                   Merge Sort (no random access needed)
  Sort 0s, 1s, 2s in one pass          Dutch National Flag (3-pointer)
  K-sorted array                        Min-heap of size K+1
  External sorting                      Merge Sort with disk chunks
  Custom sort (pairs, intervals)        std::sort with lambda comparator
  Count inversions                      Modified Merge Sort or BIT
  Kth largest without full sort        QuickSelect O(N) avg / heap O(N log K)
  Merge K sorted arrays/lists           Min-heap of K elements
  Form largest number                   Custom comparator: compare ab vs ba

================================================================================
QUICK REFERENCE — Common Templates
================================================================================

  // Merge Sort
  void mergeSort(vector<int>& a, int l, int r) {
      if (l >= r) return;
      int mid = l + (r - l) / 2;
      mergeSort(a, l, mid); mergeSort(a, mid+1, r);
      vector<int> tmp;
      int i = l, j = mid + 1;
      while (i <= mid && j <= r) tmp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
      while (i <= mid) tmp.push_back(a[i++]);
      while (j <= r)   tmp.push_back(a[j++]);
      for (int k = l; k <= r; k++) a[k] = tmp[k - l];
  }

  // Quick Sort (random pivot)
  void quickSort(vector<int>& a, int l, int r) {
      if (l >= r) return;
      swap(a[l + rand() % (r - l + 1)], a[r]);   // random pivot
      int pivot = a[r], p = l;
      for (int i = l; i < r; i++) if (a[i] <= pivot) swap(a[i], a[p++]);
      swap(a[p], a[r]);
      quickSort(a, l, p - 1); quickSort(a, p + 1, r);
  }

  // Dutch National Flag
  void sortColors(vector<int>& a) {
      int lo = 0, mid = 0, hi = a.size() - 1;
      while (mid <= hi) {
          if      (a[mid] == 0) swap(a[lo++], a[mid++]);
          else if (a[mid] == 1) mid++;
          else                  swap(a[mid], a[hi--]);
      }
  }

  // Custom comparator — Largest Number
  sort(nums.begin(), nums.end(), [](int a, int b){
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
  });

  // Counting Sort (stable)
  void countingSort(vector<int>& a, int K) {
      vector<int> cnt(K+1, 0), out(a.size());
      for (int x : a) cnt[x]++;
      for (int i = 1; i <= K; i++) cnt[i] += cnt[i-1];  // prefix sum
      for (int i = a.size()-1; i >= 0; i--) out[--cnt[a[i]]] = a[i]; // right to left for stability
      a = out;
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 14 |  0 |  0 |    14
  Theory (★ added)           |  4 |  0 |  0 |     4
  Coding Easy (from files)   |  5 |  0 |  0 |     5
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 17 |  0 |    17
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  5 |     5
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 26 | 22 |  9 |    57

================================================================================
END
================================================================================
