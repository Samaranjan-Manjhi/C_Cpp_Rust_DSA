================================================================================
        SLIDING WINDOW TECHNIQUE — COMPLETE QUESTION BANK
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

  ── WHAT IS SLIDING WINDOW ──────────────────────────────────────────────────
  A contiguous subarray / substring "window" slides across the data.
  Instead of recomputing from scratch for every window, we ADD the new right
  element and REMOVE the old left element — amortized O(N) total.

  ── 2 TYPES ─────────────────────────────────────────────────────────────────

  TYPE 1 — FIXED SIZE WINDOW (size = K):
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];  // first window
    int maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];              // slide: add right, remove left
        maxSum = max(maxSum, windowSum);
    }
    Used for: max/min/average of all K-size subarrays, exactly-K problems

  TYPE 2 — VARIABLE SIZE WINDOW (shrink when condition violated):
    int lo = 0, windowState = 0;
    for (int hi = 0; hi < n; hi++) {
        // expand: include arr[hi]
        windowState = update(windowState, arr[hi]);
        while (violated(windowState)) {
            // shrink: exclude arr[lo]
            windowState = undo(windowState, arr[lo]);
            lo++;
        }
        // [lo..hi] is a valid window — record answer
        ans = max(ans, hi - lo + 1);
    }
    Used for: longest substring with K distinct chars, minimum window substring,
              longest subarray with sum <= K, at-most-K problems

  ── KEY INSIGHT — "EXACTLY K" TRICK ────────────────────────────────────────
  Count subarrays with EXACTLY K of something:
    exactly(K)  =  atMost(K)  −  atMost(K−1)
  Write atMost() with variable window, call twice. O(N) each.

  ── SLIDING WINDOW vs TWO POINTER ───────────────────────────────────────────
  Sliding Window  → contiguous subarray/substring; about what's INSIDE the window
  Two Pointer     → about the ENDPOINTS themselves (pair sum, container water)
  Both are O(N) but the framing differs.

  ── MONOTONIC DEQUE FOR WINDOW MAX/MIN ──────────────────────────────────────
  When you need max/min INSIDE every window of size K:
    deque<int> dq;  // stores INDICES in decreasing value order
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() < i-k+1) dq.pop_front(); // remove stale
        while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back(); // maintain order
        dq.push_back(i);
        if (i >= k-1) result.push_back(arr[dq.front()]); // front = max
    }

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is the sliding window technique? When do you use it?
         (Contiguous subarray processing in O(N); use when problem involves
          a contiguous subarray/substring with a size or constraint)
         Asked at: Amazon, Microsoft, Google, TCS

  [T][ ] What is the difference between fixed and variable sliding window?
         (Fixed: window size K is constant; Variable: window grows/shrinks
          based on a constraint — use lo pointer to shrink)
         Asked at: Amazon, Microsoft, Flipkart

  [T][ ] How is sliding window different from two pointer technique?
         (Sliding window focuses on what's INSIDE the window — state tracking;
          two pointer focuses on the endpoint relationship — sum, distance)
         Asked at: Amazon, Google, Flipkart

  [T][ ] What is the "exactly K = atMost(K) - atMost(K-1)" trick?
         (Counting subarrays with exactly K occurrences by subtracting
          two "at most" window calls — avoids complex state tracking)
         Asked at: Google, Amazon, competitive programming

  [T][ ] How does a monotonic deque help in sliding window maximum?
         (Deque stores indices in decreasing value order; front = current max;
          each element pushed/popped at most once → O(N) amortized)
         Asked at: Amazon, Google, Goldman Sachs, Flipkart

  ★[T][ ] Why can't we use a sliding window directly for "exactly K distinct"
           without the atMost trick?
           (Shrinking the window when distinct count > K loses valid windows
            where count < K; atMost approach handles all cases cleanly)
           Asked at: Google, Amazon, competitive programming

  ★[T][ ] What is the time and space complexity of the sliding window maximum
           using a deque? Justify that it is O(N).
           (Each element is pushed once and popped once → O(N) total;
            deque stores at most K indices → O(K) space)
           Asked at: Amazon, Goldman Sachs, Google

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── FIXED WINDOW ────────────────────────────────────────────────────────────

  [C][ ] (E) Find maximum sum subarray of exactly size K
             Build first window; slide by adding right, subtracting left
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Find minimum sum subarray of exactly size K
             Asked at: TCS, Amazon

  [C][ ] (E) Find the average of all subarrays of size K; return array of averages
             Asked at: TCS, Amazon

  [C][ ] (E) Given binary array, find the maximum number of consecutive 1s
             No window needed — just track current streak; reset on 0
             Asked at: Amazon, Microsoft, LeetCode Easy

  [C][ ] (E) Check if any subarray of size K has all distinct elements
             Sliding window + unordered_set; shrink when collision
             Asked at: Amazon, Flipkart

  [C][ ] (E) Find all anagrams of pattern p in string s; return starting indices
             Fixed window of size |p|; compare frequency arrays
             Asked at: Amazon, Microsoft, Adobe, Google

  ★[C][ ] (E) First negative number in every window of size K
              Sliding window; maintain a queue of negative indices
              Asked at: Amazon, TCS, Wipro, Zoho

  ★[C][ ] (E) Count occurrences of anagram of a pattern in text
              Fixed window frequency comparison
              Asked at: Amazon, TCS, Flipkart

  ★[C][ ] (E) Maximum sum of K consecutive elements; then find WHICH K elements
              Return the starting index of the maximum window
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Given string, check if any window of size K contains all vowels
              Fixed window + vowel set tracking
              Asked at: TCS, Wipro, Amazon

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── VARIABLE WINDOW — LONGEST ───────────────────────────────────────────────

  [C][ ] (M) Longest substring without repeating characters
             Variable window + unordered_set; shrink lo until no duplicate
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) Longest substring with at most 2 distinct characters
             Variable window + freq map; shrink when distinct > 2
             Asked at: Amazon, Google, Adobe

  [C][ ] (M) Longest substring with exactly K distinct characters
             Variable window + freq map; shrink when distinct > K
             Asked at: Amazon, Google, Flipkart, Adobe

  [C][ ] (M) Longest subarray with at most K zeros (can flip K zeros to ones)
             Window tracks zero count; shrink when zeros > K
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Longest repeating character replacement (can change at most K chars)
             Window tracks max frequency char count; shrink when (size - maxFreq) > K
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Subarray with given sum (positive numbers only — sliding window)
             Variable window; shrink lo when sum exceeds target; O(N)
             Asked at: Amazon, Flipkart, Paytm, TCS

  [C][ ] (M) Longest subarray with sum <= K (positive integers)
             Variable window; shrink lo when sum > K
             Asked at: Amazon, Flipkart

  [C][ ] (M) Longest subarray with ones after replacement (flip at most K zeros)
             Same as "at most K zeros" window
             Asked at: Amazon, Microsoft, Google

  ── VARIABLE WINDOW — MINIMUM / COUNT ───────────────────────────────────────

  [C][ ] (M) Minimum size subarray sum >= S
             Expand right; when sum >= S, shrink left while still valid; O(N)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Minimum window substring — smallest window in S containing all chars of T
             Two frequency maps; expand right until all covered, shrink left; O(N)
             Asked at: Amazon, Google, Microsoft, Goldman Sachs (very common!)

  [C][ ] (M) Smallest window in string containing all distinct characters
             Variant of minimum window substring
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Longest substring with at most K distinct characters (return length)
             Asked at: Amazon, Flipkart, Google

  [C][ ] (M) Count subarrays with product less than K
             Variable window; shrink lo when product >= K; add (hi - lo + 1) for count
             Asked at: Amazon, Flipkart

  [C][ ] (M) Count number of substrings with exactly K distinct characters
             atMostK(K) - atMostK(K-1) trick
             Asked at: Google, Flipkart, competitive programming

  [C][ ] (M) Number of subarrays with exactly K odd numbers
             exactly(K) = atMost(K) - atMost(K-1)
             Asked at: Amazon, Google

  [C][ ] (M) Binary subarrays with sum exactly S
             exactly(S) = atMost(S) - atMost(S-1)
             Asked at: Amazon, Google, LeetCode

  ── SLIDING WINDOW MAXIMUM / MINIMUM ────────────────────────────────────────

  [C][ ] (M) Sliding window maximum — max in every window of size K; O(N)
             Monotonic deque (decreasing); front always = max of current window
             Asked at: Amazon, Google, Microsoft, Flipkart, Goldman Sachs

  [C][ ] (M) Sliding window minimum — min in every window of size K; O(N)
             Monotonic deque (increasing); front = min of current window
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (M) Moving average of last K elements from a data stream
             Queue of size K + running sum; O(1) per new element
             Asked at: Amazon, Goldman Sachs, Facebook/Meta, Dolat Capital

  ── FIXED WINDOW — ADVANCED ─────────────────────────────────────────────────

  [C][ ] (M) Maximum sum of non-overlapping subarrays each of length K
             Pick M non-overlapping windows to maximize total sum
             Prefix sum + DP on window sums
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Maximum points from cards: pick K cards from either end; maximize sum
             Total sum - minimum sum of middle window of size (n - K)
             Asked at: Amazon, Google

  [C][ ] (M) Count subarrays where sum lies in range [lower, upper]
             Merge sort on prefix sums; or monotonic deque DP
             Asked at: Google, Goldman Sachs

  [C][ ] (M) Given string, find minimum window size such that all characters
             appear at least K times in the window
             Variable window; shrink when ALL chars have freq >= K
             Asked at: Google, Amazon

  [C][ ] (M) Find the minimum number of adjacent swaps to group all 1s together
             Sliding window of size count(1s); minimize cost = swaps needed
             Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Given array, find maximum sum of exactly K non-adjacent elements
              DP + sliding window over valid selections
              Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Implement sliding window VWAP (Volume Weighted Average Price)
              Rolling window of size K: sum(price×volume) / sum(volume)
              Asked at: Dolat Capital, Goldman Sachs, trading firms

  ★[C][ ] (M) Minimum window subsequence: find shortest window in S where T
              appears as a subsequence (not substring)
              Two pointer forward + backward; O(S × T)
              Asked at: Google, Goldman Sachs, Amazon

  ★[C][ ] (M) Permutation in string: check if any permutation of pattern p
              exists as substring of s — fixed window frequency comparison
              Asked at: Amazon, Microsoft, Google, LeetCode

  ★[C][ ] (M) Given array of integers, find length of longest subarray where
              max - min <= K (variable window with two monotonic deques)
              Asked at: Amazon, Google

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Sliding window maximum using deque — also implement O(N log K) heap approach
             Show both; compare tradeoffs
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Find median of sliding window of size K
             Two heaps (max-heap lower half, min-heap upper half); rebalance on slide
             O(N log K)
             Asked at: Amazon, Flipkart, Google, Goldman Sachs

  [C][ ] (H) Maximum of all subarrays of size K — deque O(N)
             Also solve with segment tree O(N log N) for comparison
             Asked at: Amazon, Goldman Sachs, competitive programming

  [C][ ] (H) Find the substring with concatenation of all words
             Given string s and list of words (all same length), find all start
             indices where substring is a concatenation of all words
             Fixed window of size (word_len × num_words); slide by 1
             Asked at: Google, Amazon

  [C][ ] (H) Minimum number of K consecutive bit flips
             No zeros allowed; greedy + sliding window tracks flipped positions
             Asked at: Google, Amazon

  [C][ ] (H) Subarrays with bounded maximum: count subarrays where max ∈ [L, R]
             Contribution counting: atMost(R) - atMost(L-1); O(N)
             Asked at: Google, Amazon, Goldman Sachs

  [C][ ] (H) Maximum sum of K non-overlapping subarrays each of length L
             Sliding window DP: dp[i] = max sum using i non-overlapping windows
             Asked at: Amazon, Google

  ★[C][ ] (H) Longest subarray with sum divisible by K (can be negative)
              Variable window doesn't work for negatives; use prefix sum + map
              But demonstrate why sliding window fails on negatives
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (H) Find the maximum number of consecutive distinct windows
              of size K across all positions (complex constraint tracking)
              Asked at: Google, competitive programming

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          WINDOW TYPE & KEY TRICK
  ─────────────────────────────────────────────────────────────────────────
  Max/Min/Avg of all K-size windows     Fixed window; slide by +right -left
  All anagrams of pattern in text       Fixed window; compare freq arrays
  First negative in every K window      Fixed window; maintain index queue
  Longest with no repeat chars          Variable; shrink on duplicate
  Longest with at most K distinct       Variable; shrink when distinct > K
  Longest with at most K zeros/ones     Variable; track zero/one count
  Min size subarray with sum >= S       Variable; shrink when sum >= S
  Minimum window substring              Variable; need all T chars covered
  Count with exactly K (distinct/odd)   atMost(K) - atMost(K-1) trick
  Binary subarrays with sum = S         atMost(S) - atMost(S-1) trick
  Product < K count                     Variable; add (hi-lo+1) per step
  Max in every window (O(N))            Monotonic decreasing deque
  Min in every window (O(N))            Monotonic increasing deque
  Median of sliding window              Two heaps; rebalance on slide
  Max - min <= K window                 Two monotonic deques simultaneously
  K cards from ends                     Fixed window on MIDDLE; minimize it

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Fixed window — max sum of size K
  int sum = 0, maxSum;
  for (int i = 0; i < k; i++) sum += arr[i];
  maxSum = sum;
  for (int i = k; i < n; i++) {
      sum += arr[i] - arr[i-k];
      maxSum = max(maxSum, sum);
  }

  // Variable window — longest with at most K distinct chars
  int lo = 0, res = 0;
  unordered_map<char,int> freq;
  for (int hi = 0; hi < n; hi++) {
      freq[s[hi]]++;
      while ((int)freq.size() > k) {
          if (--freq[s[lo]] == 0) freq.erase(s[lo]);
          lo++;
      }
      res = max(res, hi - lo + 1);
  }

  // Minimum window substring
  string minWindow(string s, string t) {
      unordered_map<char,int> need, window;
      for (char c : t) need[c]++;
      int have = 0, total = need.size(), l = 0, minLen = INT_MAX, start = 0;
      for (int r = 0; r < (int)s.size(); r++) {
          window[s[r]]++;
          if (need.count(s[r]) && window[s[r]] == need[s[r]]) have++;
          while (have == total) {
              if (r-l+1 < minLen) { minLen = r-l+1; start = l; }
              if (need.count(s[l]) && --window[s[l]] < need[s[l]]) have--;
              else window[s[l]]--;
              l++;
          }
      }
      return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }

  // Sliding window maximum — monotonic deque
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
      deque<int> dq; vector<int> res;
      for (int i = 0; i < (int)a.size(); i++) {
          if (!dq.empty() && dq.front() < i-k+1) dq.pop_front();
          while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
          dq.push_back(i);
          if (i >= k-1) res.push_back(a[dq.front()]);
      }
      return res;
  }

  // Exactly K trick — count subarrays with exactly K distinct
  auto atMost = [&](int k) {
      int lo = 0, res = 0;
      unordered_map<int,int> freq;
      for (int hi = 0; hi < n; hi++) {
          freq[arr[hi]]++;
          while ((int)freq.size() > k) { if (--freq[arr[lo]] == 0) freq.erase(arr[lo]); lo++; }
          res += hi - lo + 1;
      }
      return res;
  };
  int exactlyK = atMost(k) - atMost(k-1);

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  5 |  0 |  0 |     5
  Theory (★ added)           |  2 |  0 |  0 |     2
  Coding Easy (from files)   |  6 |  0 |  0 |     6
  Coding Easy (★ added)      |  4 |  0 |  0 |     4
  Coding Medium (from files) |  0 | 22 |  0 |    22
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  7 |     7
  Coding Hard (★ added)      |  0 |  0 |  2 |     2
  ---------------------------|----|----|----|---------
  TOTAL                      | 17 | 27 |  9 |    53

================================================================================
END
================================================================================
