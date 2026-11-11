================================================================================
        HASH MAPS (unordered_map / map) — COMPLETE QUESTION BANK
        Covers: Frequency counting, Prefix sum + map, Sliding window + map,
                Group problems, Design problems, All hash map coding patterns
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

  #include <unordered_map>   // O(1) avg — hash table
  #include <map>             // O(log N) — Red-Black Tree (sorted keys)

  unordered_map<string, int> um;
  um["key"]++;               // insert or update
  um.count("key");           // 0 or 1 — safe existence check
  um.find("key");            // iterator or um.end()
  um.at("key");              // throws out_of_range if absent
  um.erase("key");
  for (auto& [k, v] : um) { }   // C++17 structured binding

  ── WHEN TO USE WHICH ───────────────────────────────────────────────────────

  Use unordered_map when:  O(1) lookup needed, order irrelevant,
                           frequency counting, prefix sum lookups
  Use map when:            Sorted order needed, lower/upper_bound queries,
                           range queries, keys comparable but not hashable

  ── CORE PATTERNS ───────────────────────────────────────────────────────────

  1. FREQUENCY COUNT:
     for (int x : arr) freq[x]++;

  2. PREFIX SUM + MAP (subarray sum = K):
     map stores {prefix_sum → first_index_seen}
     if (prefix - K) is in map → subarray found

  3. SLIDING WINDOW + FREQUENCY MAP:
     Expand right: freq[arr[r]]++
     Shrink left when condition violated: freq[arr[l]]--; if zero, erase

  4. BIDIRECTIONAL MAP (isomorphic strings):
     Two maps: s→t and t→s; both must be consistent

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a hash function? What makes a good hash function?
         (Deterministic, uniform distribution, fast, minimal collisions)
         Asked at: Amazon, Google, Microsoft, Goldman Sachs

  [T][ ] What is a hash collision? How is it handled in unordered_map?
         (Chaining: each bucket is a linked list of (key, value) pairs)
         Asked at: Amazon, Flipkart, Paytm, TCS

  [T][ ] What is chaining vs open addressing?
         (Chaining: external linked list per bucket; open addressing: probe for next slot)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is load factor? What happens when it exceeds the threshold?
         (load_factor = size/bucket_count; triggers rehashing at > max_load_factor = 1.0)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is rehashing? What is its time complexity?
         (O(N) — all elements re-inserted into a new larger bucket array)
         Asked at: Google, Goldman Sachs, Atlassian

  [T][ ] What is the time complexity of unordered_map operations?
         (Average O(1); worst case O(N) due to all keys hashing to same bucket)
         Asked at: Amazon, TCS, Wipro, Goldman Sachs

  [T][ ] When would you use map vs unordered_map?
         (map: sorted order, range queries, lower/upper_bound;
          unordered_map: O(1) lookup, no ordering needed)
         Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [T][ ] What is the worst-case time complexity of unordered_map lookup?
         (O(N) — adversarial inputs can cause all keys to collide)
         Asked at: Amazon, Microsoft, Goldman Sachs

  [T][ ] What happens when you access a key that doesn't exist via operator[]?
         (Default value is inserted — use count() or find() for safe access)
         Asked at: Amazon, Microsoft, Adobe, Google

  [T][ ] Can unordered_map store a custom struct as key? What do you need?
         (Custom hash functor + operator== for the key type)
         Asked at: Google, Microsoft, Adobe

  ★[T][ ] What is the anti-hash attack and how do you defend against it in
           competitive programming?
           (Adversarial inputs cause O(N) per op; use splitmix64 custom hash)
           Asked at: Google, Codeforces competitive programming interviews

  ★[T][ ] What is the difference between map::operator[] and map::at()?
           ([] inserts default value if absent; at() throws std::out_of_range)
           Asked at: Amazon, TCS, Microsoft

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Count frequency of each element in array
             Asked at: TCS, Wipro, Infosys, Amazon

  [C][ ] (E) Count word frequencies in a sentence using map
             Asked at: Amazon, Microsoft, Zoho, TCS

  [C][ ] (E) Check if two arrays are equal (same elements, any order)
             Use frequency map from first, decrement with second
             Asked at: TCS, Wipro

  [C][ ] (E) Check if two strings are anagrams using frequency map
             Asked at: Amazon, TCS, Wipro, Infosys

  [C][ ] (E) Check if two strings are isomorphic
             'egg' and 'add' → isomorphic; 'foo' and 'bar' → not
             Two hashmaps for bidirectional mapping
             Asked at: Amazon, Microsoft, Zoho

  [C][ ] (E) Find all pairs in array with given difference K
             For each x, check if (x+K) or (x-K) in hashmap
             Asked at: Amazon, Zoho, TCS

  [C][ ] (E) Find if two elements in array sum to 0 (use unordered_set)
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Given array, print all elements that appear more than once
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Word frequency counter: count frequencies, return K most frequent words
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Find characters present in first string but not in second
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Find the intersection of two arrays allowing duplicate counts
             e.g. [1,2,2,1] ∩ [2,2] = [2,2]
             Asked at: Amazon, Microsoft

  [C][ ] (E) Find all elements that appear exactly twice in an array
             Asked at: Amazon, TCS

  ★[C][ ] (E) Find the element that appears maximum number of times in an array
              Asked at: TCS, Wipro, Amazon, Infosys

  ★[C][ ] (E) Given a paragraph, find the most frequent word (ignore common words)
              Asked at: Amazon, Microsoft, Facebook/Meta

  ★[C][ ] (E) Find the first non-repeating character in a string using map
              Asked at: Amazon, Microsoft, Adobe, Zoho

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── PREFIX SUM + MAP ────────────────────────────────────────────────────────

  [C][ ] (M) Two Sum using hashmap — O(N)
             For each element check if (target - element) is in map
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) Subarray with zero sum — check if exists
             Prefix sum in hashmap; if prefix_sum seen before, subarray exists
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Subarray sum equals K — count subarrays
             Prefix sum + freq map; count[prefix - K] gives valid subarrays
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Longest subarray with equal number of 0s and 1s
             Convert 0→-1; find longest subarray with sum 0 using prefix + map
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Find the number of subarrays with sum divisible by K
             Prefix sum mod K + frequency map
             Asked at: Amazon, Google, Goldman Sachs, Flipkart

  [C][ ] (M) Given array and K, find length of longest subarray with sum = K
             Prefix sum + hashmap; store first occurrence of each prefix sum
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Find maximum length subarray with equal number of 0s, 1s, and 2s
             Reduce to 2 prefix-sum equations; hashmap of pairs
             Asked at: Google, Goldman Sachs

  ── GROUPING ────────────────────────────────────────────────────────────────

  [C][ ] (M) Group anagrams together
             Sort each string → use as key; group originals in map
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Given list of words, group by sorted character signature;
             return group with most words
             Asked at: Amazon, Adobe

  [C][ ] (M) Find all pairs that are isomorphic strings
             (same character mapping pattern)
             Asked at: Amazon, Microsoft

  [C][ ] (M) Find if any permutation of string can form palindrome
             At most one character can have odd frequency
             Asked at: Amazon, Microsoft, Adobe

  ── SLIDING WINDOW + MAP ────────────────────────────────────────────────────

  [C][ ] (M) Minimum window substring containing all characters of pattern
             Sliding window + two frequency maps; O(N)
             Asked at: Amazon, Google, Microsoft, Adobe (very common!)

  [C][ ] (M) Longest subarray where absolute difference between max and min <= K
             Sliding window with two monotonic deques + map
             Asked at: Google, Amazon

  ── ADVANCED HASHING ────────────────────────────────────────────────────────

  [C][ ] (M) Longest consecutive sequence in unsorted array — O(N)
             unordered_set; for each n start count only if n-1 not in set
             Asked at: Amazon, Google, Facebook/Meta, Atlassian

  [C][ ] (M) Pair with given sum in unsorted array — count all pairs
             For each x, count[target-x] gives pairs ending at x
             Asked at: Amazon, Flipkart

  [C][ ] (M) 4Sum — find all unique quadruplets summing to target
             Sort + two pointer inside nested loop. O(N³)
             Asked at: Amazon, Microsoft

  [C][ ] (M) 4Sum II: 4 arrays, count tuples (i,j,k,l) where sum = 0
             Hashmap of pairwise sums from A+B; search in C+D
             Asked at: Amazon, Google

  [C][ ] (M) Find the number of subarrays with XOR equal to K
             Prefix XOR + hashmap (same idea as prefix sum for sum=K)
             Asked at: Flipkart, Swiggy, competitive programming

  [C][ ] (M) Count pairs in array with XOR equal to K
             For each x, check if (x XOR K) in hashmap
             Asked at: Amazon, Samsung, competitive programming

  [C][ ] (M) Count number of nice pairs: arr[i] + rev(arr[j]) == arr[j] + rev(arr[i])
             Simplify: arr[i] - rev(arr[i]) == arr[j] - rev(arr[j]); group by diff
             Asked at: Amazon, Google

  [C][ ] (M) Find all duplicates in array where elements are in range [1, N]
             Negative marking: O(N) time O(1) space (no hashmap)
             Asked at: Amazon, Adobe, Flipkart

  [C][ ] (M) Implement multimap<int,string> frequency tracker:
             count words, iterate from highest to lowest frequency
             Asked at: Amazon, Microsoft

  [C][ ] (M) Map sum pairs: insert (key, val) and sum all values whose keys
             have a given prefix
             Asked at: Amazon, LeetCode Medium

  [C][ ] (M) Check if a given Sudoku board is valid
             Use sets for rows, cols, and 3x3 boxes
             Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Time-based key-value store: get(key, timestamp) returns value
              with largest timestamp <= given timestamp
              Use map<string, map<int,string>> with upper_bound
              Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (M) Given two strings, find all starting indices of anagram substrings
              of pattern in text — sliding window + frequency map; O(N)
              Asked at: Amazon, Microsoft, Google, Adobe

  ★[C][ ] (M) Find the minimum number of distinct elements after removing K elements
              Greedy: remove lowest-frequency elements first (sort by freq)
              Asked at: Amazon, Google

  ★[C][ ] (M) Given array, find the length of the longest sub-array containing
              at most K distinct integers — sliding window + map
              Asked at: Amazon, Microsoft, Google, Flipkart

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement LRU Cache using HashMap + Doubly Linked List
             get(key): O(1) lookup + move to front
             put(key,val): O(1) insert at front; evict tail if at capacity
             Asked at: Amazon, Google, Microsoft, Flipkart (VERY common!)

  [C][ ] (H) Design a data structure with insert, delete, search, getRandom — all O(1)
             unordered_map + vector; swap-with-last for O(1) delete
             Asked at: Amazon, Microsoft, Google, Facebook/Meta

  [C][ ] (H) Implement a custom hash map from scratch:
             separate chaining, load factor tracking, automatic rehashing, templated
             Asked at: Google, Amazon, Microsoft

  [C][ ] (H) Implement LFU Cache — O(1) get and put
             Two hashmaps + min-frequency tracker + doubly linked list per frequency
             Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (H) Design a leaderboard: addScore(player, score), top(K), reset(player)
              Use map<int, set<string>> sorted by score descending
              Asked at: Amazon, Flipkart, Paytm

  ★[C][ ] (H) Palindrome pairs: given list of words, find all pairs (i,j)
              where words[i] + words[j] is a palindrome
              O(N × L²) using hashmap
              Asked at: Amazon, Microsoft, Google

  ★[C][ ] (H) Given a stream of URLs, find the top K most visited at any point —
              hashmap of frequencies + min-heap of size K; O(N log K)
              Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (H) Design a database index (inverted index): for each word,
              store a sorted list of document IDs; support intersection queries
              hashmap of word → sorted list; merge with two pointers
              Asked at: Google, Amazon, database engineering roles

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ─────────────────────────────────────────────────────────────────────────
  Frequency counting                    map[x]++ ; one pass
  Two Sum / Pair sum                    For each x: check (target-x) in map
  Subarray sum = K                      Prefix sum + map; check (prefix-K) count
  Subarray XOR = K                      Prefix XOR + map; same idea
  Longest subarray sum = K              Prefix sum + map; store first occurrence
  Subarray sum divisible by K           Prefix sum % K + frequency map
  Group anagrams                        sorted(word) as key
  Isomorphic / character mapping        Two maps (bidirectional)
  Minimum window substring              Sliding window + two freq maps
  Longest substring K distinct          Sliding window + freq map; shrink when > K
  Palindrome permutation                All freq even (or exactly one odd)
  Consecutive sequence O(N)            unordered_set; only count from sequence start
  LRU Cache                             unordered_map + doubly linked list
  LFU Cache                             Two maps + min-freq + DLL per freq

================================================================================
QUICK REFERENCE — Common Templates
================================================================================

  // Subarray sum = K (prefix sum + map)
  int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> cnt; cnt[0] = 1;
      int prefix = 0, res = 0;
      for (int x : nums) {
          prefix += x;
          res += cnt[prefix - k];
          cnt[prefix]++;
      }
      return res;
  }

  // Minimum window substring
  string minWindow(string s, string t) {
      unordered_map<char,int> need, window;
      for (char c : t) need[c]++;
      int have = 0, total = need.size(), l = 0, minLen = INT_MAX, start = 0;
      for (int r = 0; r < s.size(); r++) {
          window[s[r]]++;
          if (need.count(s[r]) && window[s[r]] == need[s[r]]) have++;
          while (have == total) {
              if (r-l+1 < minLen) { minLen = r-l+1; start = l; }
              window[s[l]]--;
              if (need.count(s[l]) && window[s[l]] < need[s[l]]) have--;
              l++;
          }
      }
      return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 10 |  0 |  0 |    10
  Theory (★ added)           |  2 |  0 |  0 |     2
  Coding Easy (from files)   | 12 |  0 |  0 |    12
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 21 |  0 |    21
  Coding Medium (★ added)    |  0 |  4 |  0 |     4
  Coding Hard (from files)   |  0 |  0 |  4 |     4
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 27 | 25 |  8 |    60

================================================================================
END
================================================================================
