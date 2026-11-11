================================================================================
        HASH SETS (unordered_set / set / multiset) — COMPLETE QUESTION BANK
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

  #include <unordered_set>   // O(1) avg — hash table, unordered, unique
  #include <set>             // O(log N) — Red-Black Tree, sorted, unique
  #include <set>             // multiset — sorted, allows duplicates

  unordered_set<int> us;
  us.insert(x);             // O(1) avg
  us.erase(x);              // O(1) avg
  us.count(x);              // 0 or 1 (existence check)
  us.find(x) != us.end();   // iterator-based check
  us.size();   us.empty();  us.clear();
  us.reserve(n);            // pre-allocate to avoid rehashing

  set<int> s;
  s.insert(x);              // O(log N)
  s.erase(x);               // O(log N)
  s.lower_bound(x);         // first element >= x
  s.upper_bound(x);         // first element > x
  *s.begin();  *s.rbegin(); // min and max in O(1)

  multiset<int> ms;         // like set but allows duplicates
  ms.insert(x);
  ms.erase(ms.find(x));     // erase ONE occurrence (not all!)

  ── WHEN TO USE WHICH ───────────────────────────────────────────────────────

  unordered_set : Fast O(1) existence check, no order needed, no duplicates
  set           : Sorted unique elements, range queries, min/max in O(1)
  multiset      : Sorted with duplicates, running median, frequency tracking
  unordered_multiset: Fast insert/lookup with duplicates allowed

  ── CORE PATTERNS ───────────────────────────────────────────────────────────

  1. DEDUPLICATION:         set<T> s(arr.begin(), arr.end());
  2. EXISTENCE IN O(1):     if (us.count(x)) { ... }
  3. VISITED TRACKING:      unordered_set<int> visited; (BFS/DFS)
  4. CONSECUTIVE SEQUENCE:  for each x, check if (x-1) NOT in set → start of sequence
  5. SLIDING WINDOW UNIQUE: multiset to track window elements with duplicates

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is the difference between set and unordered_set?
         (set: sorted, O(log N), BST; unordered_set: unsorted, O(1) avg, hash table)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] What is the internal data structure used by unordered_set?
         (Hash table with chaining — array of buckets, each bucket a linked list)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What is the average and worst-case time complexity of unordered_set operations?
         (Average O(1); worst O(N) due to all elements colliding in one bucket)
         Asked at: Amazon, Microsoft, Goldman Sachs

  [T][ ] What is a hash collision? How does unordered_set handle it?
         (Chaining: each bucket holds a linked list of colliding elements)
         Asked at: Amazon, Flipkart, Paytm, TCS

  [T][ ] What is load factor? What happens when it exceeds the threshold?
         (Default max_load_factor = 1.0; triggers rehashing — O(N) rebuild)
         Asked at: Amazon, Microsoft, Google

  [T][ ] Can unordered_set store duplicate elements?
         (No — use unordered_multiset for duplicates)
         Asked at: TCS, Wipro

  [T][ ] What is the difference between count() and find() in unordered_set?
         (count returns 0 or 1; find returns iterator — find preferred for
          checking + using the value together)
         Asked at: TCS, Wipro, Amazon

  [T][ ] Can unordered_set store custom objects? What do you need to provide?
         (Custom hash functor + operator== for the key type)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is reserve() in unordered_set and why should you use it?
         (Pre-allocates buckets to avoid rehashing — big performance win
          when final size is known in advance)
         Asked at: Goldman Sachs, Dolat Capital, HFT roles

  [T][ ] What is multiset? How do you erase only ONE occurrence in multiset?
         (ms.erase(ms.find(x)) — erases single; ms.erase(x) erases ALL)
         Asked at: Amazon, TCS, Adobe

  [T][ ] What is lower_bound and upper_bound in set?
         (lower_bound(x): first element >= x; upper_bound(x): first element > x)
         Asked at: Amazon, Goldman Sachs, Flipkart

  ★[T][ ] What is the anti-hash attack? How do you defend against it?
           (Adversarial inputs cause O(N) per op; use splitmix64 or gp_hash_table)
           Asked at: Google, competitive programming interviews

  ★[T][ ] When are iterators of unordered_set invalidated?
           (After rehashing — any insert that triggers rehash invalidates ALL iterators)
           Asked at: Google, Microsoft, advanced C++ roles

  ★[T][ ] What is emplace() vs insert() in unordered_set? Which is preferred?
           (emplace constructs in-place — avoids copy/move overhead for complex types)
           Asked at: Amazon, Microsoft, Adobe

  ★[T][ ] How do you safely erase elements while iterating over an unordered_set?
           (Use it = s.erase(it) pattern; do NOT erase by value during range-for)
           Asked at: Amazon, Adobe, Qualcomm

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Check if two arrays have common elements using unordered_set
             Insert first array into set, iterate second and check count()
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Find all elements that appear exactly twice in an array
             Frequency map; collect those with count == 2
             Asked at: Amazon, TCS

  [C][ ] (E) Given two strings, find characters present in first but not in second
             unordered_set from first string; check each char of second
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Check if all characters of one string appear in another
             Asked at: TCS, Amazon, Zoho

  [C][ ] (E) Find if there are two elements in array with sum = 0
             For each x, check if -x in unordered_set
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Find all pairs in array with given difference K
             For each x, check if (x+K) or (x-K) in set
             Asked at: Amazon, Zoho, TCS

  [C][ ] (E) Find the intersection of two arrays allowing duplicate counts
             e.g. [1,2,2,1] ∩ [2,2] = [2,2] — use multiset
             Asked at: Amazon, Microsoft

  [C][ ] (E) Remove duplicates from an array using unordered_set (preserve order)
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Check if an array is a subset of another array using unordered_set
             Asked at: TCS, Infosys, Zoho

  [C][ ] (E) Check if a given Sudoku board is valid
             Use sets for each row, column, and 3×3 box
             Asked at: Amazon, Microsoft, Google

  ★[C][ ] (E) Find the first element that is repeated in an array using unordered_set
              (First element we see for the SECOND time)
              Asked at: Amazon, Flipkart, Paytm

  ★[C][ ] (E) Given array of integers, find all elements that appear exactly once
              (unique elements — frequency == 1)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Given a sorted array, deduplicate it using std::set and print result
              Asked at: TCS, Wipro

  ★[C][ ] (E) Find the union of two arrays (all unique elements) using unordered_set
              Asked at: Amazon, TCS, Wipro

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── CORE HASH SET PATTERNS ──────────────────────────────────────────────────

  [C][ ] (M) Longest consecutive sequence in unsorted array — O(N)
             unordered_set; for each n, count only if n-1 NOT in set
             e.g. [100,4,200,1,3,2] → 4 (sequence 1,2,3,4)
             Asked at: Amazon, Google, Facebook/Meta, Atlassian

  [C][ ] (M) Find the element that makes array a non-permutation of [1,N]
             (one element missing, one extra — find both using set)
             Asked at: Amazon, Microsoft, TCS

  [C][ ] (M) Count distinct elements in every window of size K
             Sliding window with unordered_map tracking frequency; distinct count
             Asked at: Amazon, Goldman Sachs, Flipkart

  [C][ ] (M) Find if there exists a subarray of length K with all distinct elements
             Sliding window + unordered_set; shrink when duplicate found
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Find all words in a text that appear in a given dictionary
             Insert dictionary words into unordered_set; scan text words
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Given list of words, find all anagram groups using set of sorted strings
             Asked at: Amazon, Microsoft, Google, Adobe

  ── SET FOR RANGE QUERIES ───────────────────────────────────────────────────

  [C][ ] (M) Implement a sorted container supporting O(log N) insert, O(log N) delete,
             and O(1) findMin and findMax simultaneously
             Use std::set; maintain min/max via begin() and rbegin()
             Asked at: Dolat Capital, Goldman Sachs

  [C][ ] (M) Given stream of integers, at each step find the median
             Two multisets: lower half and upper half (balance on each insert)
             Asked at: Amazon, Google, Goldman Sachs, Flipkart

  [C][ ] (M) Given array, for each element find count of elements strictly
             smaller than it — O(N log N) using ordered set
             Asked at: Amazon, Flipkart, Goldman Sachs

  ── MULTISET PATTERNS ───────────────────────────────────────────────────────

  [C][ ] (M) Sliding window median: for each window of size K, return the median
             Two multisets (lower and upper halves); rebalance on slide
             Asked at: Amazon, Goldman Sachs, Google

  [C][ ] (M) Find the K-th smallest element in a stream using multiset
             Insert each element; return *next(ms.begin(), k-1)
             Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (M) Given list of words, find all pairs that are isomorphic using set
              (store canonical form of each word; group by pattern)
              Asked at: Amazon, Microsoft

  ★[C][ ] (M) Find the minimum window in string S containing all characters of T
              Use unordered_set of required chars + sliding window with freq map
              Asked at: Amazon, Google, Microsoft, Adobe

  ★[C][ ] (M) Given N intervals, find if any two intervals overlap
              Sort by start; use set of active endpoints to detect overlap
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Given an array, find the length of the longest sub-array with
              all distinct elements — sliding window + unordered_set
              Asked at: Amazon, Microsoft, Google, Flipkart

  ★[C][ ] (M) Check if a given Sudoku board is solvable (valid so far)
              Use unordered_set per row, col, box for constraint checking
              Asked at: Amazon, Microsoft, Google

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Design a data structure: insert(key), delete(key), search(key),
             getRandom() — all O(1)
             unordered_map + vector; swap-with-last trick for O(1) delete
             Asked at: Amazon, Microsoft, Google, Facebook/Meta

  [C][ ] (H) Implement custom hash map from scratch with separate chaining,
             load factor tracking, automatic rehashing — templated for key/value
             Asked at: Google, Amazon, Microsoft

  ★[C][ ] (H) Implement unordered_set for a custom struct Point{int x, y}
              Define custom hash (XOR/polynomial) + operator== from scratch
              Asked at: Google, Adobe, Qualcomm

  ★[C][ ] (H) Given a large stream of integers (billions), find the first integer
              that appears more than once with O(1) average lookup
              Use unordered_set; handle memory constraints with Bloom filter discussion
              Asked at: Amazon, Goldman Sachs, Facebook/Meta

  ★[C][ ] (H) Find the maximum XOR of any two elements in an array
              Build prefix-trie (or use sorted set + bit manipulation)
              Asked at: Amazon, Google

  ★[C][ ] (H) Given N cities connected by roads, find the smallest set of cities
              from which all other cities are reachable (Minimum Dominating Set approx.)
              Use set-based BFS with greedy city selection
              Asked at: Google, Amazon, Goldman Sachs

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          USE THIS / PATTERN
  ─────────────────────────────────────────────────────────────────────────
  Fast existence check (no order)       unordered_set::count() or find()
  Deduplicate while preserving order    Iterate + insert to unordered_set
  Dedup + sorted output                 std::set (inserts in sorted order)
  Sorted unique + range queries         std::set + lower_bound/upper_bound
  Allow duplicates + sorted             std::multiset
  Erase ONE from multiset               ms.erase(ms.find(x))  NOT ms.erase(x)
  Consecutive sequence O(N)             unordered_set; start count only if x-1 absent
  Sliding window all distinct           unordered_set; shrink when collision
  Sliding window distinct count         unordered_map freq; distinct = map.size()
  Running median in stream              Two multisets (lower + upper halves)
  Custom struct as key                  Define hash + operator== ; use unordered_set
  Pre-allocate to avoid rehash          us.reserve(expected_size)
  Safe iteration + erasure              it = s.erase(it)  pattern

================================================================================
QUICK REFERENCE — Common Templates
================================================================================

  // Consecutive sequence — O(N)
  int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(), nums.end());
      int best = 0;
      for (int n : s) {
          if (!s.count(n - 1)) {          // start of sequence
              int len = 1;
              while (s.count(n + len)) len++;
              best = max(best, len);
          }
      }
      return best;
  }

  // Sliding window longest with all distinct — O(N)
  int lengthOfLongestSubstring(string s) {
      unordered_set<char> window;
      int l = 0, res = 0;
      for (int r = 0; r < s.size(); r++) {
          while (window.count(s[r])) { window.erase(s[l]); l++; }
          window.insert(s[r]);
          res = max(res, r - l + 1);
      }
      return res;
  }

  // Running median with two multisets
  multiset<int> lo, hi;  // lo = lower half (max at lo.rbegin()), hi = upper half
  void addNum(int num) {
      lo.insert(num);
      hi.insert(*lo.rbegin()); lo.erase(lo.find(*lo.rbegin()));
      if (lo.size() < hi.size()) { lo.insert(*hi.begin()); hi.erase(hi.begin()); }
  }
  double getMedian() {
      return lo.size() > hi.size() ? *lo.rbegin() : (*lo.rbegin() + *hi.begin()) / 2.0;
  }

  // Custom hash for pair — use in unordered_set
  struct PairHash {
      size_t operator()(const pair<int,int>& p) const {
          return hash<long long>()(((long long)p.first << 32) | p.second);
      }
  };
  unordered_set<pair<int,int>, PairHash> ps;

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 11 |  0 |  0 |    11
  Theory (★ added)           |  4 |  0 |  0 |     4
  Coding Easy (from files)   | 10 |  0 |  0 |    10
  Coding Easy (★ added)      |  4 |  0 |  0 |     4
  Coding Medium (from files) |  0 | 11 |  0 |    11
  Coding Medium (★ added)    |  0 |  6 |  0 |     6
  Coding Hard (from files)   |  0 |  0 |  2 |     2
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 29 | 17 |  6 |    52

================================================================================
END
================================================================================
