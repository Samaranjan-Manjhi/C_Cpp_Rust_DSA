================================================================================
        PREFIX SUM & KADANE'S ALGORITHM — COMPLETE QUESTION BANK
        Covers: 1D Prefix Sum, 2D Prefix Sum, Prefix XOR, Prefix Sum + HashMap,
                Kadane's Algorithm, Kadane's 2D, Circular Subarray, Extensions
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

  ── PREFIX SUM ──────────────────────────────────────────────────────────────

  Build — O(N):
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

  Range sum query [l, r] — O(1):
    sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);

  Safer with a 1-indexed prefix array:
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + arr[i-1];
    sum[l..r] = prefix[r+1] - prefix[l];   // l and r are 0-indexed

  ── 2D PREFIX SUM ───────────────────────────────────────────────────────────

  Build — O(M×N):
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        P[i][j] = mat[i-1][j-1] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];

  Rectangle sum (r1,c1) to (r2,c2) — O(1):
    sum = P[r2+1][c2+1] - P[r1][c2+1] - P[r2+1][c1] + P[r1][c1];

  ── PREFIX SUM + HASHMAP ────────────────────────────────────────────────────

  KEY PATTERN — Subarray sum equals K:
    "If prefix[j] - prefix[i] = K  →  subarray arr[i+1..j] has sum K"
    Store first occurrence of each prefix sum; for each new prefix check if
    (prefix - K) was seen before.

    unordered_map<int,int> cnt; cnt[0] = 1;  // empty prefix has sum 0
    int prefix = 0, ans = 0;
    for (int x : arr) {
        prefix += x;
        ans += cnt[prefix - K];   // count how many times (prefix-K) seen
        cnt[prefix]++;
    }

  Variations:
    • Count subarrays with sum = 0      → K = 0
    • Longest subarray with sum = K     → store first index (not count)
    • Sum divisible by K                → use prefix % K as the key
    • Equal 0s and 1s (replace 0→-1)   → find longest subarray with sum = 0
    • Prefix XOR                        → swap + with XOR; same pattern

  ── KADANE'S ALGORITHM ──────────────────────────────────────────────────────

  Maximum subarray sum — O(N) O(1):
    int curr = arr[0], best = arr[0];
    for (int i = 1; i < n; i++) {
        curr = max(arr[i], curr + arr[i]);  // extend or restart
        best = max(best, curr);
    }

  Key insight: At each element, decide — "should I extend the previous subarray
  or start fresh from this element?"  Start fresh if curr < 0.

  Track start and end indices (if needed):
    if (arr[i] > curr + arr[i]) { curr = arr[i]; start = i; }
    else curr += arr[i];
    if (curr > best) { best = curr; end = i; resultStart = start; }

  Important edge cases:
    • All negatives → answer is the maximum single element (do NOT return 0)
    • All zeros     → answer is 0
    • Single element → return that element

  Extensions:
    • Minimum subarray sum → flip signs, run Kadane's, negate result
    • Maximum subarray product → track curr_max AND curr_min (negative × negative)
    • Circular array max sum → max(Kadane's, total_sum - min_subarray_sum)
    • Kadane's in 2D → fix top and bottom rows; compress column sums; run Kadane's

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a prefix sum array? How do you build it and use it?
         (prefix[i] = sum of arr[0..i]; range sum [l,r] = prefix[r]-prefix[l-1])
         Asked at: TCS, Wipro, Amazon, Microsoft, Google

  [T][ ] What is the time complexity of prefix sum build and range query?
         (Build: O(N); each query: O(1); total for Q queries: O(N + Q))
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is Kadane's algorithm? What does it solve?
         (Maximum sum contiguous subarray in O(N) O(1))
         Asked at: Amazon, Microsoft, Google, Flipkart, Adobe, Goldman Sachs

  [T][ ] How does Kadane's algorithm handle all-negative arrays?
         (Must initialize curr and best to arr[0], not 0; otherwise returns 0
          which is wrong when all elements are negative)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the "prefix sum + hashmap" pattern? What does it solve?
         (Stores seen prefix sums; if (prefix - K) seen before → subarray with sum K exists)
         Asked at: Amazon, Microsoft, Flipkart, Paytm, Goldman Sachs

  [T][ ] How does a 2D prefix sum work? How do you compute a rectangle sum in O(1)?
         (Inclusion-exclusion: P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1])
         Asked at: Amazon, Google, Goldman Sachs

  [T][ ] How do you extend Kadane's algorithm to find the circular maximum subarray sum?
         (max(Kadane's on array, total_sum - min_subarray_sum)
          Edge case: if all elements negative, return max element)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is prefix XOR? What problems does it solve?
         (XOR of all elements up to index i; used for subarray XOR = K problems
          same pattern as prefix sum but with XOR instead of +)
         Asked at: Amazon, Flipkart, Goldman Sachs, competitive programming

  ★[T][ ] What is the "difference array" technique? How is it related to prefix sum?
           (Apply range updates to a difference array in O(1); prefix sum gives final values;
            used for: paint fences, range increment, O(1) per update + O(N) to reconstruct)
           Asked at: Amazon, Google, Goldman Sachs

  ★[T][ ] Why do we initialize the prefix hashmap with {0: 1} (or {0: 0} for length)?
           (Handles subarrays starting from index 0; prefix[j] - K = 0 means
            the subarray arr[0..j] has sum K — this must be counted)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] How do you find the longest subarray with sum equal to K using prefix sum?
           (Store first occurrence index of each prefix sum; ans = i - firstIndex[prefix-K];
            vs counting: store frequency — two different uses of same pattern)
           Asked at: Amazon, Flipkart, Paytm

  ★[T][ ] What is the maximum subarray product problem? How is it different from Kadane's?
           (Must track curr_max AND curr_min because negative × negative = positive;
            swap them when current element is negative)
           Asked at: Amazon, Microsoft, Google, Flipkart

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── PREFIX SUM BASICS ───────────────────────────────────────────────────────

  [C][ ] (E) Build prefix sum array; answer Q range sum queries in O(1) each
             Asked at: TCS, Amazon, competitive programming

  [C][ ] (E) Find the number of subarrays with sum equal to 0
             Prefix sum + hashmap: count[prefix] gives number of valid subarrays
             Asked at: Amazon, Flipkart

  [C][ ] (E) Find the equilibrium index: index where left sum equals right sum
             Precompute total sum; scan left to right tracking left sum
             Asked at: Amazon, Adobe, Zoho, TCS

  [C][ ] (E) Given array of 1s and -1s, find if any prefix sum equals K
             Asked at: TCS, Amazon

  [C][ ] (E) 2D prefix sum: given matrix, answer rectangle sum queries in O(1)
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (E) Find the product of all elements except itself — no division, O(N)
             Left product array × right product array; combine in-place
             Asked at: Amazon, Microsoft, Google, Adobe

  ★[C][ ] (E) Given array, find the count of subarrays where the sum is even
              Prefix sum parity tracking (even/odd count)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Given binary array, count subarrays with more 1s than 0s
              Replace 0→-1; count subarrays with sum > 0 using prefix sum
              Asked at: Amazon, Flipkart

  ★[C][ ] (E) Difference array: apply M range increment operations [l, r, +val]
              then print the final array — O(M + N)
              Asked at: Amazon, Google, TCS

  ── KADANE'S BASICS ─────────────────────────────────────────────────────────

  [C][ ] (E) Maximum subarray sum — Kadane's Algorithm
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe (must know!)

  [C][ ] (E) Find the actual subarray (start and end indices) with maximum sum
             Track start index; update resultStart when best is updated
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Minimum subarray sum using Kadane's variant
             Track curr_min = min(arr[i], curr_min + arr[i])
             Asked at: Amazon, Flipkart, TCS

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── PREFIX SUM + HASHMAP ────────────────────────────────────────────────────

  [C][ ] (M) Subarray sum equals K — count all such subarrays; O(N)
             prefix + hashmap; ans += cnt[prefix - K]; cnt[prefix]++
             Asked at: Amazon, Microsoft, Google, Flipkart (very common!)

  [C][ ] (M) Find the maximum length subarray with sum equal to K
             (allows negative numbers — sliding window won't work)
             Store first occurrence of prefix sum; ans = max(ans, i - firstIdx[prefix-K])
             Asked at: Amazon, Flipkart, Paytm, Google

  [C][ ] (M) Find the longest subarray with equal number of 0s and 1s
             Replace 0→-1; find longest subarray with sum = 0 using prefix + hashmap
             Asked at: Amazon, Microsoft, Flipkart, Paytm

  [C][ ] (M) Count subarrays with sum divisible by K
             prefix % K; negative mod fix: ((prefix % K) + K) % K
             cnt[0] = 1; ans += cnt[mod]; cnt[mod]++
             Asked at: Amazon, Google, Goldman Sachs, Flipkart

  [C][ ] (M) Count subarrays with XOR equal to K
             Prefix XOR + hashmap; same structure as prefix sum version
             Asked at: Flipkart, Swiggy, Goldman Sachs, competitive programming

  [C][ ] (M) Given array, find number of subarrays with average >= K
             Subtract K from each element; find count of subarrays with sum >= 0
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Find maximum length subarray having equal 0s, 1s, and 2s
             Prefix(count1 - count0) and prefix(count2 - count0) as a pair key in hashmap
             Asked at: Google, Goldman Sachs

  [C][ ] (M) Count subarrays where sum lies in range [lower, upper]
             Merge sort on prefix sums; count pairs where lower <= pre[j]-pre[i] <= upper
             Asked at: Google, Goldman Sachs

  ── KADANE'S EXTENSIONS ─────────────────────────────────────────────────────

  [C][ ] (M) Maximum product of any subarray
             Track curr_max AND curr_min; swap on negative element
             Asked at: Amazon, Microsoft, Flipkart, Google

  [C][ ] (M) Maximum circular subarray sum
             max(Kadane's, total - min_subarray_sum)
             Edge case: if total == min_subarray (all negatives), return Kadane's result
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Maximum subarray sum with at most one deletion
             At each index track: bestEndingHere and bestStartingHere (from right)
             Answer = max over all delete points
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (M) Maximum alternating subarray sum (alternating signs on odd/even positions)
             DP variant of Kadane's tracking alternating sign state
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Maximum sum increasing subsequence — find subsequence (not subarray)
             that is strictly increasing and has maximum sum
             DP O(N²); not Kadane's — but related
             Asked at: Amazon, TCS, Wipro

  ── 2D PREFIX SUM & KADANE'S 2D ─────────────────────────────────────────────

  [C][ ] (M) Find the maximum sum rectangle in 2D matrix — O(N²×M)
             Fix top row and bottom row; collapse to 1D column sums; run Kadane's
             Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [C][ ] (M) Count number of rectangles in binary matrix filled with all 1s
             For each (i,j) compute height of consecutive 1s above; prefix sum on heights
             Asked at: Google, Amazon

  [C][ ] (M) Maximum sum submatrix no larger than K — 2D prefix + sorted set
             For each pair of rows, use 1D prefix; binary search for closest prefix <= (curr-K)
             Asked at: Google, Goldman Sachs

  [C][ ] (M) Number of submatrices that sum to target
             For each pair of rows, apply prefix sum + hashmap on column sums; O(M²×N)
             Asked at: Amazon, Google

  ★[C][ ] (M) Given matrix, find the number of magic squares of size K×K
              (sum of every row, col, diagonal = same) using 2D prefix sum
              Asked at: Amazon, competitive programming

  ★[C][ ] (M) Find the contiguous subarray of length >= 2 with maximum average
              Binary search on average + prefix sum to check feasibility; O(N log(max-min))
              Asked at: Google, Amazon

  ★[C][ ] (M) Minimum cost to make array equal using prefix sum
              Sort and use prefix sum to compute cost of aligning all to each candidate
              Asked at: Amazon, Goldman Sachs

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Maximum sum of submatrix no larger than K
             2D: fix rows, 1D prefix + balanced BST (std::set) for O(N log N) per row pair
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Count subarrays where XOR of all elements is less than K
             Prefix XOR array + trie for fast counting; O(N × 32)
             Asked at: Google, Goldman Sachs, competitive programming

  [C][ ] (H) Given 2D grid, find number of paths from top-left to bottom-right
             where path sum equals exactly K (only right and down moves)
             2D DP with prefix sum hashmap per anti-diagonal
             Asked at: Google, Amazon

  [C][ ] (H) Prefix sum with updates — Fenwick Tree (BIT)
             Point update O(log N) + prefix sum query O(log N)
             Asked at: Amazon, Google, competitive programming

  ★[C][ ] (H) Count of range sum: given array, count subarrays with sum in [lower, upper]
              Merge sort on prefix sum array; O(N log N)
              Asked at: Google, Goldman Sachs, LeetCode Hard

  ★[C][ ] (H) Maximum sum rectangle in 2D matrix with constraint: no more than
              K elements in the rectangle — combine 2D prefix with optimization
              Asked at: Google, Goldman Sachs

  ★[C][ ] (H) Find the maximum subarray sum after performing at most one operation:
              multiply one element by -1. Extend Kadane's with state tracking.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Given array of N integers, find the maximum sum of any non-empty
              subarray modulo M — prefix sum + sorted set + O(N log N)
              Asked at: Google, competitive programming, Goldman Sachs

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ─────────────────────────────────────────────────────────────────────────
  Range sum query (static)              Build O(N) prefix; query O(1)
  Rectangle sum query (static)          2D prefix; inclusion-exclusion formula
  Range updates then query              Difference array + prefix sum
  Subarray sum = K (count)              prefix + hashmap; init {0:1}
  Subarray sum = K (longest)            prefix + hashmap; store first index
  Subarray sum divisible by K           prefix % K + hashmap; fix negatives
  Subarray XOR = K                      prefix XOR + hashmap; same structure
  Equal 0s and 1s (longest)            Replace 0→-1; find sum=0 longest
  Three equal groups of 0s/1s/2s       Pair of prefix differences as hashmap key
  Max subarray sum                      Kadane's: curr=max(arr[i], curr+arr[i])
  Min subarray sum                      Kadane's variant: curr=min(arr[i], curr+arr[i])
  Max subarray (find indices too)       Track start; update resultStart when best updates
  Max product subarray                  Kadane's: track both curr_max and curr_min
  Circular max subarray                 max(Kadane's, total - min_subarray_sum)
  Max sum rectangle in matrix           Fix rows; Kadane's on column sums; O(N²M)
  Max sum with <= K deletion            DP: bestFromLeft + bestFromRight at delete point
  Prefix sum with point updates         Fenwick Tree (BIT); O(log N) each op

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // 1D prefix sum (1-indexed)
  vector<int> pre(n+1, 0);
  for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + arr[i-1];
  auto query = [&](int l, int r) { return pre[r+1] - pre[l]; }; // 0-indexed l,r

  // 2D prefix sum (1-indexed)
  vector<vector<int>> P(m+1, vector<int>(n+1, 0));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      P[i][j] = mat[i-1][j-1] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
  // rect sum (r1,c1) to (r2,c2) 0-indexed:
  // P[r2+1][c2+1] - P[r1][c2+1] - P[r2+1][c1] + P[r1][c1]

  // Subarray sum = K (count)
  int subarraySum(vector<int>& a, int k) {
      unordered_map<int,int> cnt; cnt[0] = 1;
      int pre = 0, ans = 0;
      for (int x : a) { pre += x; ans += cnt[pre - k]; cnt[pre]++; }
      return ans;
  }

  // Kadane's Algorithm
  int maxSubarray(vector<int>& a) {
      int curr = a[0], best = a[0];
      for (int i = 1; i < (int)a.size(); i++) {
          curr = max(a[i], curr + a[i]);
          best = max(best, curr);
      }
      return best;
  }

  // Max product subarray
  int maxProduct(vector<int>& a) {
      int cMax = a[0], cMin = a[0], best = a[0];
      for (int i = 1; i < (int)a.size(); i++) {
          if (a[i] < 0) swap(cMax, cMin);
          cMax = max(a[i], cMax * a[i]);
          cMin = min(a[i], cMin * a[i]);
          best = max(best, cMax);
      }
      return best;
  }

  // Circular max subarray
  int maxCircularSubarray(vector<int>& a) {
      int total = accumulate(a.begin(), a.end(), 0);
      // Min subarray: negate, run Kadane's, negate result
      vector<int> neg(a.size());
      transform(a.begin(), a.end(), neg.begin(), negate<int>());
      int maxKadane = maxSubarray(a);
      int minSubarray = -maxSubarray(neg);
      if (total == minSubarray) return maxKadane; // all negatives edge case
      return max(maxKadane, total - minSubarray);
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  8 |  0 |  0 |     8
  Theory (★ added)           |  4 |  0 |  0 |     4
  Coding Easy (from files)   |  9 |  0 |  0 |     9
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 19 |  0 |    19
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 |  4 |     4
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 24 | 22 |  8 |    54

================================================================================
END
================================================================================
