================================================================================
        TWO POINTER TECHNIQUE — COMPLETE QUESTION BANK
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

  ── WHAT IS TWO POINTER ─────────────────────────────────────────────────────
  Two pointers are index variables that move through a data structure.
  Instead of a nested O(N²) loop, two pointers reduce the problem to O(N).

  ── 4 CLASSIC SETUPS ────────────────────────────────────────────────────────

  1. OPPOSITE ENDS (converging) — used on SORTED arrays:
     int lo = 0, hi = n - 1;
     while (lo < hi) {
         if (condition_met)    { /* record result */ lo++; hi--; }
         else if (need_larger)   lo++;
         else                    hi--;
     }
     Used for: Pair sum, Container with most water, Trapping rain water,
               3Sum, 4Sum, Valid palindrome, Reverse array

  2. SAME DIRECTION (fast / slow) — no sort required:
     int slow = 0;
     for (int fast = 0; fast < n; fast++) {
         if (keep(arr[fast])) arr[slow++] = arr[fast];
     }
     Used for: Remove duplicates in-place, Remove element, Move zeros,
               Nth from end of linked list, Detect cycle (Floyd's)

  3. RUNNER TECHNIQUE (gap of K) — one pointer K steps ahead:
     int p1 = 0, p2 = k;
     while (p2 < n) { p1++; p2++; }
     // p1 now at n-k
     Used for: Kth from end, Minimum platforms, Sliding window (fixed size)

  4. TWO ARRAYS / MERGE STYLE:
     int i = 0, j = 0;
     while (i < m && j < n) {
         if (a[i] <= b[j]) process(a[i++]);
         else               process(b[j++]);
     }
     Used for: Merge sorted arrays, Intersection, Union of sorted arrays

  ── KEY DECISION ────────────────────────────────────────────────────────────
  • Array must be SORTED for sum/difference based two-pointer to work.
  • For opposite-ends: move the pointer toward the other to increase/decrease sum.
  • For fast/slow: fast advances unconditionally; slow advances only when condition met.

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is the two pointer technique? When do you use it over brute force?
         (Use when array is sorted or when elements can be processed from both ends;
          reduces O(N²) to O(N))
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] What is the prerequisite for using two pointers for sum problems?
         (Array must be sorted — otherwise sort first in O(N log N))
         Asked at: Amazon, Microsoft, Flipkart, TCS

  [T][ ] How is the two pointer technique different from a sliding window?
         (Two pointer: both pointers move independently based on condition;
          sliding window: window size is fixed OR shrinks/grows from the right)
         Asked at: Amazon, Google, Flipkart

  [T][ ] What is the fast-slow pointer pattern? What problems does it solve?
         (Floyd's cycle detection, find middle of linked list, Nth from end)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] How do you find a pair with a given sum in a sorted array — time & space?
         (Two pointers: O(N) time O(1) space — optimal)
         Asked at: TCS, Wipro, Amazon, Zoho

  ★[T][ ] Why does the opposite-ends two pointer approach work for pair sum?
           (For sorted array: if sum < target move lo right (increase sum);
            if sum > target move hi left (decrease sum); can't miss the answer)
           Asked at: Amazon, Google, Goldman Sachs

  ★[T][ ] What is the time complexity of 3Sum using two pointers? Justify it.
           (Fix one element O(N), apply two pointer O(N) → O(N²) total;
            sorting is O(N log N) which is dominated)
           Asked at: Amazon, Microsoft, Google

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── OPPOSITE ENDS ───────────────────────────────────────────────────────────

  [C][ ] (E) Check if array has a pair summing to 0 (sorted array, two pointers)
             Asked at: Amazon, TCS

  [C][ ] (E) Find if sorted array has pair with given sum — O(N) O(1)
             lo=0, hi=n-1; move lo right if sum<target, hi left if sum>target
             Asked at: Amazon, TCS, Wipro, Zoho

  [C][ ] (E) Find all pairs in sorted array with given difference D
             Asked at: Amazon, Flipkart

  [C][ ] (E) Find if sorted array can be divided into consecutive pairs
             Asked at: Amazon, Wipro

  [C][ ] (E) Squares of sorted array in sorted order — O(N) O(N)
             Two pointers from both ends (handle negatives whose squares can be large)
             Input: [-4,-1,0,3,10] → [0,1,9,16,100]
             Asked at: Amazon, Microsoft

  [C][ ] (E) Check if string is a palindrome ignoring non-alphanumeric characters
             lo=0, hi=n-1; skip non-alnum; compare chars
             "A man, a plan, a canal: Panama" → true
             Asked at: Amazon, Microsoft, Google

  ── FAST / SLOW (SAME DIRECTION) ────────────────────────────────────────────

  [C][ ] (E) Remove all occurrences of value val from array in-place; return new length
             slow = write ptr; fast scans all; copy only if arr[fast] != val
             Asked at: Amazon, TCS, Microsoft

  [C][ ] (E) Remove duplicates from sorted array in-place; return new length
             slow = last unique written; advance only when arr[fast] != arr[slow]
             Asked at: Amazon, TCS, Microsoft, Adobe

  [C][ ] (E) Move all zeros to end maintaining relative order of non-zeros
             slow tracks next non-zero position; swap arr[fast] and arr[slow]
             Asked at: Amazon, Microsoft, Flipkart, Adobe

  [C][ ] (E) Move all negative numbers to beginning, positives to end
             Two-pointer partition (like quicksort partition step)
             Asked at: TCS, Wipro, Zoho

  ★[C][ ] (E) Given sorted array, remove duplicates allowing each element at most twice
              slow pointer; allow duplicate if arr[fast] != arr[slow-2]
              Asked at: Amazon, Microsoft

  ★[C][ ] (E) Given array of 0s and 1s, move all 0s to left and 1s to right in-place
              Fast/slow two pointer — O(N) O(1)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Check if string is a subsequence of another string
              Two pointers: one on s, one on t; advance s-ptr on match
              Asked at: Amazon, Google, TCS

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── SUM PROBLEMS ────────────────────────────────────────────────────────────

  [C][ ] (M) 3Sum — find all unique triplets in array summing to zero
             Sort; fix one element; two pointer on rest; skip duplicates carefully
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) 3Sum closest — find triplet with sum closest to target (not exact)
             Sort + two pointer; track minimum absolute difference
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find count of triplets with sum less than K in sorted array
             Fix one; two pointer; when sum < K: all pairs from lo to hi-1 work
             Add (hi - lo) to count; move lo right
             Asked at: Amazon, Google

  [C][ ] (M) 4Sum — find all unique quadruplets summing to target
             Sort; fix two; two pointer on rest; O(N³)
             Asked at: Amazon, Microsoft

  [C][ ] (M) Count pairs in two sorted arrays with sum equal to target
             One pointer at start of first array; one at end of second; merge-style
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Two Sum II — sorted array, return 1-indexed pair
             Asked at: Amazon, Microsoft, LeetCode classic

  ── CONTAINER / RAIN WATER ──────────────────────────────────────────────────

  [C][ ] (M) Container with most water — find max area formed by two lines
             lo=0, hi=n-1; area = min(h[lo],h[hi])*(hi-lo); move shorter side
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Trapping rain water — O(N) O(1) using two pointers
             Track leftMax and rightMax; process the smaller side
             Asked at: Amazon, Google, Microsoft, Flipkart (very common!)

  ── SUBARRAYS & PARTITIONING ────────────────────────────────────────────────

  [C][ ] (M) Minimum size subarray sum >= S — sliding window two pointer
             Expand right; shrink left while sum >= S; track min length; O(N)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Boats to save people: each boat holds 2 people max weight W
             Sort; if heaviest + lightest fit → take both; else heaviest alone
             Asked at: Amazon, LeetCode

  [C][ ] (M) Sort colors — Dutch National Flag (sort 0s, 1s, 2s in one pass)
             Three pointers: lo, mid, hi; O(N) O(1)
             Asked at: Amazon, Microsoft, Flipkart, Paytm, Adobe

  [C][ ] (M) Subarray product less than K — count subarrays; O(N)
             Sliding window: product = product of [lo..hi]; shrink lo when >= K
             Asked at: Amazon, Flipkart

  [C][ ] (M) Minimum number of platforms at railway station
             Sort arrival and departure; two pointer simulation
             When arrival[i] < departure[j]: platform needed; else free one
             Asked at: Amazon, Microsoft, Flipkart, Paytm

  ── LINKED LIST TWO POINTER ─────────────────────────────────────────────────

  [C][ ] (M) Find the middle of a linked list in one pass — slow/fast pointer
             Asked at: Amazon, Microsoft, Flipkart, Zoho

  [C][ ] (M) Detect cycle in linked list — Floyd's algorithm
             slow × 1, fast × 2; if they meet → cycle exists
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Find starting node of cycle in linked list
             After Floyd detection: reset one pointer to head; both move 1 step
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find Nth node from end of linked list in single pass
             Gap-of-N runner technique: advance first pointer N steps, then move both
             Asked at: Amazon, Microsoft, Adobe, Zoho

  [C][ ] (M) Find intersection point of two linked lists
             Equalize lengths or end-to-start pointer swap trick
             Asked at: Amazon, Microsoft, Adobe, Flipkart, Goldman Sachs

  ── LONGEST / MOUNTAIN ──────────────────────────────────────────────────────

  [C][ ] (M) Find the longest mountain in array
             For each peak, expand left and right with two pointers
             Asked at: Amazon, Google

  [C][ ] (M) Two elements in sorted array whose sum is closest to target
             Opposite-ends two pointer; track min difference
             Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Given array of positive and negative numbers, rearrange so they
              alternate in sign maintaining relative order within each group
              Collect positives and negatives; interleave
              Asked at: Amazon, Adobe, Zoho

  ★[C][ ] (M) Find two numbers in sorted array such that their sum is closest
              to zero (can be negative)
              Opposite-ends; track minimum |sum|
              Asked at: Amazon, Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Given sorted array and target, find three elements a, b, c such that
              a² + b² = c² — find all Pythagorean triplets
              For each c, fix c² and use two pointer on remaining sorted array
              Asked at: Amazon, TCS, Zoho

  ★[C][ ] (M) Given array, find number of pairs (i, j) where i < j such that
              arr[j] - arr[i] = K (positive K)
              Sort; two pointer approach counting all valid pairs
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (M) Merge two sorted arrays into first array (in-place, first has space)
              Merge style two pointer from the END to avoid overwriting
              Asked at: Amazon, Microsoft, TCS

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Trapping rain water — 3D version (elevation map)
             Use min-heap with BFS from borders; 2D two-pointer concept
             Asked at: Google, Amazon

  [C][ ] (H) Find all unique quadruplets (a,b,c,d) from array summing to 0
             AND no two quadruplets share same element positions
             Asked at: Amazon, Microsoft

  ★[C][ ] (H) Minimum number of operations to make two strings equal using
              two pointer + greedy (matching characters in order)
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Given N jobs with start[i], end[i], profit[i], find max profit
              subset of non-overlapping jobs (weighted job scheduling)
              Sort by end; two pointer binary search for last compatible job
              Asked at: Amazon, Goldman Sachs, Flipkart

  ★[C][ ] (H) Find the max sum of subsequence such that no two adjacent elements
              are taken AND the array is circular — House Robber II variant
              Two passes: exclude first element OR exclude last; max of both
              Asked at: Amazon, Goldman Sachs

  ★[C][ ] (H) Count all subarrays with exactly K distinct elements
              Use two pointer "at most K" minus "at most K-1" trick
              Asked at: Amazon, Google, Goldman Sachs

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          TWO POINTER SETUP
  ─────────────────────────────────────────────────────────────────────────
  Pair sum in sorted array              lo=0, hi=n-1; converging
  Pair difference in sorted array       lo=0, hi=1; same direction
  3Sum / 4Sum                           Fix outer; two pointer on rest
  Container with most water             lo=0, hi=n-1; move shorter side
  Trapping rain water                   lo=0, hi=n-1; process smaller side
  Remove element / duplicates in-place  slow=write ptr, fast=read ptr
  Move zeros                            slow=next non-zero, swap with fast
  Sort 0s 1s 2s (Dutch NF)             lo, mid, hi three-way partition
  Palindrome check                      lo=0, hi=n-1; skip non-alnum
  Squares of sorted array               lo=0, hi=n-1; compare squares
  Merge two sorted arrays               i=0, j=0; pick smaller each step
  Linked list middle                    slow×1, fast×2
  Linked list cycle                     Floyd's: slow×1, fast×2
  Nth from end                          Gap-of-N: advance p1 by N first
  Minimum platforms                     Sort; simulate with two pointers
  Boats to save people                  Sort; greedy lo+hi or hi alone

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Opposite ends — pair sum in sorted array
  int lo = 0, hi = n - 1;
  while (lo < hi) {
      int s = arr[lo] + arr[hi];
      if (s == target) { /* found */ lo++; hi--; }
      else if (s < target) lo++;
      else hi--;
  }

  // Fast/slow — remove element in-place
  int slow = 0;
  for (int fast = 0; fast < n; fast++)
      if (arr[fast] != val) arr[slow++] = arr[fast];
  // new length = slow

  // 3Sum
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 2; i++) {
      if (i > 0 && arr[i] == arr[i-1]) continue;  // skip duplicates
      int lo = i+1, hi = n-1;
      while (lo < hi) {
          int s = arr[i] + arr[lo] + arr[hi];
          if (s == 0) { /* store */; lo++; hi--; skip dup lo/hi }
          else if (s < 0) lo++;
          else hi--;
      }
  }

  // Trapping rain water — two pointer O(N) O(1)
  int lo=0, hi=n-1, leftMax=0, rightMax=0, water=0;
  while (lo < hi) {
      if (arr[lo] <= arr[hi]) {
          leftMax = max(leftMax, arr[lo]);
          water += leftMax - arr[lo++];
      } else {
          rightMax = max(rightMax, arr[hi]);
          water += rightMax - arr[hi--];
      }
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  5 |  0 |  0 |     5
  Theory (★ added)           |  2 |  0 |  0 |     2
  Coding Easy (from files)   | 10 |  0 |  0 |    10
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 18 |  0 |    18
  Coding Medium (★ added)    |  0 |  6 |  0 |     6
  Coding Hard (from files)   |  0 |  0 |  2 |     2
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 20 | 24 |  6 |    50

================================================================================
END
================================================================================
