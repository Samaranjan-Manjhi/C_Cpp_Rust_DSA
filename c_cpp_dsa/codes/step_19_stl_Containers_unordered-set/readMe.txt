================================================================================
        UNORDERED_SET — COMPLETE QUESTION BANK
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

  [T][ ] What is unordered_set? How is it different from set?
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] What is the internal data structure used by unordered_set?
         (Hash table with chaining or open addressing)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What is the average and worst-case time complexity of insert,
         find, and erase in unordered_set?
         (Avg O(1), Worst O(N) due to hash collisions)
         Asked at: Amazon, Microsoft, Goldman Sachs, Paytm

  [T][ ] What is a hash collision? How does unordered_set handle it?
         (Chaining — each bucket is a linked list)
         Asked at: Amazon, Flipkart, Paytm, TCS

  [T][ ] What is load factor in unordered_set? What happens when it
         exceeds the threshold?
         (Default max_load_factor = 1.0; triggers rehashing)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is rehashing? What is its time complexity?
         (O(N) — all elements re-inserted into new bucket array)
         Asked at: Google, Goldman Sachs, Atlassian

  [T][ ] What is the difference between set and unordered_set?
         (set = BST O(log N) sorted; unordered_set = hash O(1) avg unsorted)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] Can unordered_set store custom objects? What do you need to provide?
         (Custom hash function + equality operator)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the difference between count() and find() in unordered_set?
         (count returns 0 or 1; find returns iterator or end())
         Asked at: TCS, Wipro, Amazon

  [T][ ] Can unordered_set store duplicate elements?
         (No — use unordered_multiset for duplicates)
         Asked at: TCS, Wipro

  [T][ ] What is the bucket_count() and how do you iterate over buckets?
         Asked at: Google, advanced C++ roles

  [T][ ] What is reserve() in unordered_set and why should you use it?
         (Pre-allocates buckets to avoid rehashing — improves performance)
         Asked at: Goldman Sachs, Dolat Capital, HFT roles

--------------------------------------------------------------------------------
1B. ADVANCED / INTERVIEW DEPTH
--------------------------------------------------------------------------------

  ★[T][ ] What is the anti-hash-collision attack? Why is unordered_set
           vulnerable and how do you defend against it in competitive programming?
           (Custom hash with splitmix64 or random seed)
           Asked at: Google, Codeforces rounds, competitive programming interviews

  ★[T][ ] What is the difference between unordered_set and unordered_multiset?
           When would you use each?
           Asked at: Amazon, Flipkart, Adobe

  ★[T][ ] Explain why iterators of unordered_set are invalidated after
           rehashing. How do you prevent this?
           Asked at: Microsoft, Google, advanced C++ roles

  ★[T][ ] What is emplace() vs insert() in unordered_set? Which is more
           efficient and why?
           (emplace constructs in-place, avoiding copy/move overhead)
           Asked at: Amazon, Microsoft, Adobe

  ★[T][ ] What happens if you erase an element while iterating over
           unordered_set? How do you safely erase during iteration?
           (Use it = s.erase(it) pattern)
           Asked at: Amazon, Adobe, Qualcomm

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Check if two arrays have common elements using unordered_set
             Insert first array into set, iterate second and check
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Find all elements that appear exactly twice in an array
             Use unordered_map for frequency, then collect those with count == 2
             Asked at: Amazon, TCS

  [C][ ] (E) Given two strings, find characters present in first but not in second
             Use unordered_set on first string, check second
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Check if all characters of one string appear in another string
             Asked at: TCS, Amazon, Zoho

  [C][ ] (E) Find the intersection of two arrays allowing duplicate counts
             e.g. [1,2,2,1] ∩ [2,2] = [2,2]
             Asked at: Amazon, Microsoft

  [C][ ] (E) Given array of integers, find if there are two elements with sum = 0
             Use unordered_set
             Asked at: TCS, Wipro, Zoho

  [C][ ] (E) Find all pairs in array with given difference K
             Use set: for each element x, check if (x+K) or (x-K) in set
             Asked at: Amazon, Zoho, TCS

  ★[C][ ] (E) Remove duplicates from an array using unordered_set and preserve
              insertion order
              Asked at: Amazon, TCS, Wipro

  ★[C][ ] (E) Given an array, check if it is a subset of another array
              using unordered_set
              Asked at: TCS, Infosys, Zoho

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Longest consecutive sequence in unsorted array — O(N)
             Use unordered_set; for each n, start counting only if n-1 not in set
             Asked at: Amazon, Google, Facebook/Meta, Atlassian

  [C][ ] (M) Find the element that makes the array a non-permutation of [1, N]
             (exactly one element is missing, one is extra — find both)
             Asked at: Amazon, Microsoft, TCS

  [C][ ] (M) Find the minimum window in array A containing all elements of array B
             (Minimum window subarray — array version)
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (M) Word frequency counter: given paragraph, count word frequencies,
             return K most frequent words
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Check if a given Sudoku board is valid
             Use sets for rows, cols, and 3x3 boxes
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find the longest subarray where no element repeats
             Sliding window + unordered_set
             Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Given a list of words, find all words that are anagrams of each other
              Group them using sorted-character signature as key in unordered_set
              Asked at: Amazon, Microsoft, Google, Adobe

  ★[C][ ] (M) Count distinct elements in every window of size K
              Sliding window with unordered_map tracking frequency
              Asked at: Amazon, Goldman Sachs, Flipkart

  ★[C][ ] (M) Find if there exists a subarray of length K with all distinct elements
              Asked at: Amazon, Flipkart, Paytm

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Design a data structure that supports:
             insert(key), delete(key), search(key), getRandom() — all O(1)
             Using unordered_map + vector (swap with last for O(1) delete)
             Asked at: Amazon, Microsoft, Google, Facebook

  [C][ ] (H) Implement a custom hash map from scratch with:
             separate chaining, load factor tracking, automatic rehashing
             Templated for key and value types
             Asked at: Google, Amazon, Microsoft

  ★[C][ ] (H) Implement unordered_set for a custom struct (e.g., Point{x, y})
              Define custom hash using XOR/polynomial hashing and operator==
              Asked at: Google, Adobe, Qualcomm

  ★[C][ ] (H) Given a large stream of integers, find the first integer that
              appears more than once. Handle memory constraints.
              Use unordered_set with O(1) average lookup
              Asked at: Amazon, Goldman Sachs, Facebook/Meta

================================================================================
QUICK REFERENCE — unordered_set CHEATSHEET
================================================================================

  #include <unordered_set>

  unordered_set<int> s;

  s.insert(x);              // O(1) avg
  s.erase(x);               // O(1) avg
  s.find(x) != s.end();     // O(1) avg — check existence
  s.count(x);               // returns 0 or 1
  s.size();
  s.empty();
  s.clear();

  // Reserve to avoid rehashing
  s.reserve(1000);          // pre-allocate for ~1000 elements

  // Iterate
  for (auto& val : s) { ... }

  // Safe erase during iteration
  for (auto it = s.begin(); it != s.end(); ) {
      if (*it % 2 == 0) it = s.erase(it);
      else ++it;
  }

  // Custom hash for struct
  struct MyHash {
      size_t operator()(const pair<int,int>& p) const {
          return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
      }
  };
  unordered_set<pair<int,int>, MyHash> ps;

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 12 |  0 |  0 |    12
  Theory (★ added)           |  5 |  0 |  0 |     5
  Coding Easy (from files)   |  7 |  0 |  0 |     7
  Coding Easy (★ added)      |  2 |  0 |  0 |     2
  Coding Medium (from files) |  0 |  6 |  0 |     6
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 |  2 |     2
  Coding Hard (★ added)      |  0 |  0 |  2 |     2
  ---------------------------|----|----|----|---------
  TOTAL                      | 26 |  9 |  4 |    39

================================================================================
END
================================================================================
