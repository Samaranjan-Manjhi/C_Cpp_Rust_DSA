================================================================================
        UNORDERED_MAP — COMPLETE QUESTION BANK
        Compiled from all_in_one + all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        ★ = Extra question added (real company interview, not in source files)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. CORE CONCEPTS
--------------------------------------------------------------------------------

  [T][ ] What is the internal implementation of unordered_map?
         (Hash table — array of buckets; each bucket is a linked list for chaining)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What is the difference between map and unordered_map?
         (map = sorted keys O(log N) BST; unordered_map = unsorted O(1) avg hash)
         Asked at: Amazon, Microsoft, Google, Flipkart, TCS, Wipro

  [T][ ] What is the time complexity of unordered_map operations?
         (Average O(1) for insert/find/erase; worst case O(N) due to collisions)
         Asked at: Amazon, TCS, Wipro, Goldman Sachs

  [T][ ] What is the worst-case time complexity of unordered_map lookup?
         (O(N) — when all keys hash to the same bucket)
         Asked at: Amazon, Microsoft, Goldman Sachs

  [T][ ] When would you use map vs unordered_map?
         (Use map when: sorted order needed, range queries needed, key type has no
          good hash. Use unordered_map when: O(1) lookup, no ordering needed)
         Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [T][ ] What is a hash function? What makes a good hash function?
         (Deterministic, uniform distribution, fast, minimal collisions)
         Asked at: Amazon, Google, Microsoft, Goldman Sachs

  [T][ ] What is a hash collision? How is it handled in unordered_map?
         (Chaining: each bucket is a linked list of (key, value) pairs)
         Asked at: Amazon, Flipkart, Paytm, TCS

  [T][ ] What is chaining vs open addressing in hash tables?
         (Chaining: external list per bucket; open addressing: probe for next slot)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is load factor? What happens when it exceeds a threshold?
         (load_factor = size / bucket_count; triggers rehashing at > max_load_factor)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is rehashing? What is its time complexity and when is it triggered?
         (O(N) — inserts all elements into a new larger bucket array)
         Asked at: Google, Goldman Sachs, Atlassian

  [T][ ] What is the difference between unordered_map and unordered_multimap?
         Asked at: TCS, Wipro, Amazon

  [T][ ] What happens when you access a key that doesn't exist via operator[] in
         unordered_map?
         (Default value is inserted — use find() or count() for safe access)
         Asked at: Amazon, Microsoft, Adobe, Google

  [T][ ] Can unordered_map store custom struct as key? What do you need?
         (Custom hash functor + operator== for the key type)
         Asked at: Google, Microsoft, Adobe

  [T][ ] What does reserve() do for unordered_map? Why use it?
         (Pre-allocates buckets — avoids mid-operation rehashing; improves perf)
         Asked at: Goldman Sachs, Dolat Capital, HFT roles

--------------------------------------------------------------------------------
1B. ADVANCED / INTERVIEW DEPTH
--------------------------------------------------------------------------------

  ★[T][ ] What is the anti-hash attack? Why is unordered_map vulnerable in
           competitive programming? How do you fix it?
           (Adversarial inputs cause worst-case O(N) per op; fix with custom hash
            using splitmix64 or random seed)
           Asked at: Google, Codeforces competitive programming interviews

  ★[T][ ] What is emplace() vs insert() in unordered_map? Which is preferred?
           (emplace constructs in-place in the bucket; insert requires a pair object)
           Asked at: Amazon, Microsoft, Google, Adobe

  ★[T][ ] Are iterators of unordered_map stable? When are they invalidated?
           (Invalidated only by rehashing; safe after individual insert if no rehash)
           Asked at: Google, Microsoft, Qualcomm

  ★[T][ ] What is the difference between at() and operator[] in unordered_map?
           (at() throws std::out_of_range if key absent; [] inserts default value)
           Asked at: Amazon, Microsoft, TCS

  ★[T][ ] What is unordered_map's average memory usage compared to map?
           (unordered_map uses more contiguous memory for buckets but less per-node
            overhead; map has pointer overhead per node + color bit)
           Asked at: Goldman Sachs, HFT firms, Dolat Capital

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Count frequency of each element in array using unordered_map
             Asked at: TCS, Wipro, Infosys, Amazon

  [C][ ] (E) Check if two arrays are equal (same elements, any order)
             Use frequency map from first, decrement with second
             Asked at: TCS, Wipro

  [C][ ] (E) Check if two strings are isomorphic
             'egg' and 'add' are (e→a, g→d). 'foo' and 'bar' are not.
             Use two hashmaps for bidirectional mapping
             Asked at: Amazon, Microsoft, Zoho

  [C][ ] (E) Print all elements that appear more than once in array
             Use unordered_map for frequency count
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Word frequency counter: given paragraph, count word frequencies,
             return K most frequent words
             Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (E) Given a string, find the first non-repeating character
              Use unordered_map to count frequency, then scan again
              Asked at: Amazon, Microsoft, Adobe, Zoho

  ★[C][ ] (E) Check if two strings are anagrams using frequency map
              Asked at: Amazon, TCS, Wipro, Infosys

  ★[C][ ] (E) Find the element that appears maximum times in an array
              Using unordered_map<int, int>
              Asked at: TCS, Wipro, Amazon, Infosys

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Two Sum using hashmap — O(N)
             For each element, check if (target - element) is in map
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) Subarray with zero sum — check if exists
             Use prefix sum + hashmap; if prefix_sum seen before, subarray exists
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Longest consecutive sequence in unsorted array — O(N)
             Asked at: Google, Amazon, Microsoft, Atlassian

  [C][ ] (M) Group anagrams together
             Sort each string as key in hashmap, group originals
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Pair with given sum in unsorted array — count pairs
             For each element, check if (target - element) is in map
             Asked at: Amazon, Flipkart

  [C][ ] (M) Longest subarray with equal number of 0s and 1s
             Convert 0→-1, find longest subarray with sum 0 using prefix + hashmap
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Subarray sum equals K — count subarrays
             Prefix sum + hashmap — count how many times (prefix - K) appeared
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find if any permutation of string can form palindrome
             Count frequencies; at most one character can have odd count
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Find top K frequent elements using unordered_map + priority_queue
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Find the number of subarrays with sum divisible by K
             Use prefix sum modulo K + frequency map
             Asked at: Amazon, Google, Goldman Sachs, Flipkart

  [C][ ] (M) Count pairs in array with XOR equal to K
             Use hashmap: for each element x, check if (x XOR K) in map
             Asked at: Amazon, Samsung, competitive programming

  [C][ ] (M) Minimum window substring containing all characters of pattern
             Sliding window + frequency hashmap
             Asked at: Amazon, Google, Microsoft, Adobe (very common!)

  [C][ ] (M) Given array and K, find length of longest subarray with sum = K
             Prefix sum + hashmap
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Find all duplicates in array where elements are in range [1, N]
             Frequency map approach (or negative-marking trick O(1) space)
             Asked at: Amazon, Adobe, Flipkart

  [C][ ] (M) 4Sum — find all unique quadruplets that sum to target
             Sort + two pointer inside nested loop — O(N^3)
             Asked at: Amazon, Microsoft

  [C][ ] (M) Count number of subarrays with XOR equal to K
             Prefix XOR + hashmap (same idea as prefix sum for sum=K)
             Asked at: Flipkart, Swiggy, competitive programming

  [C][ ] (M) Find first non-repeating character in a stream
             Queue to track order + hashmap for frequency
             Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Given array of strings, find all pairs that are isomorphic
              (same character mapping pattern)
              Asked at: Amazon, Microsoft

  ★[C][ ] (M) Find the maximum length of a subarray with equal frequency of
              two given elements (e.g., equal 0s and 1s, extended version)
              Asked at: Google, Goldman Sachs

  ★[C][ ] (M) Given an array, find the number of subarrays whose sum lies
              in range [lower, upper] — O(N) using prefix sum + hashmap
              Asked at: Google, Amazon, Goldman Sachs

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement LRU Cache using HashMap + Doubly Linked List
             O(1) get and put using unordered_map<key, list::iterator>
             Asked at: Amazon, Microsoft, Google, Flipkart, Paytm

  [C][ ] (H) Implement a custom hash map from scratch with:
             separate chaining, load factor tracking, automatic rehashing
             Templated for key and value types
             Asked at: Google, Amazon, Microsoft

  [C][ ] (H) Design a data structure that supports:
             insert(key), delete(key), search(key), getRandom() — all O(1)
             Using unordered_map + vector (swap with last for O(1) delete)
             Asked at: Amazon, Microsoft, Google, Facebook

  [C][ ] (H) Design a concurrent hash map supporting parallel reads and
             writes using reader-writer locks
             Asked at: Google, Amazon, Microsoft (system design coding)

  ★[C][ ] (H) Implement LFU (Least Frequently Used) Cache
              Two hashmaps + min frequency tracker + doubly linked lists per freq
              Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (H) Given a very large file of words (doesn't fit in RAM),
              find the top K frequent words
              Use external hashing + min-heap
              Asked at: Google, Amazon, Goldman Sachs

================================================================================
QUICK REFERENCE — unordered_map CHEATSHEET
================================================================================

  #include <unordered_map>

  unordered_map<string, int> um;

  um["key"] = value;            // insert or update (inserts default if missing!)
  um.insert({"key", val});      // insert only (pair) — no update if exists
  um.emplace("key", val);       // in-place construction
  um.erase("key");              // O(1) avg
  um.find("key");               // returns iterator or um.end()
  um.count("key");              // returns 0 or 1
  um.at("key");                 // throws out_of_range if key absent
  um.size();
  um.empty();
  um.clear();

  // Safe access
  if (um.count("key")) { int v = um["key"]; }
  auto it = um.find("key");
  if (it != um.end()) { auto v = it->second; }

  // Reserve to avoid rehashing
  um.reserve(1000);

  // Iterate (order NOT guaranteed)
  for (auto& [key, val] : um) { ... }          // C++17

  // Custom hash for pair<int,int>
  struct PairHash {
      size_t operator()(const pair<int,int>& p) const {
          return hash<long long>()(((long long)p.first << 32) | p.second);
      }
  };
  unordered_map<pair<int,int>, int, PairHash> pmap;

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 14 |  0 |  0 |    14
  Theory (★ added)           |  5 |  0 |  0 |     5
  Coding Easy (from files)   |  5 |  0 |  0 |     5
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 17 |  0 |    17
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 |  4 |     4
  Coding Hard (★ added)      |  0 |  0 |  2 |     2
  ---------------------------|----|----|----|---------
  TOTAL                      | 27 | 20 |  6 |    53

================================================================================
END
================================================================================
