================================================================================
        MAP — COMPLETE QUESTION BANK
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

  [T][ ] What is std::map? What internal data structure does it use?
         (Red-Black Tree — a self-balancing BST)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What is a Red-Black tree? What properties does it maintain?
         (Balanced BST with color properties — height = O(log N))
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is the time complexity of insert, find, erase, and iteration in map?
         (All operations O(log N); iteration is O(N) total in sorted order)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] What is the difference between map and unordered_map?
         (map = sorted keys, O(log N), Red-Black tree;
          unordered_map = unsorted, O(1) avg, hash table)
         Asked at: Amazon, Microsoft, Google, Flipkart, TCS

  [T][ ] What happens when you access a key that doesn't exist using map[key]?
         (Default-constructs the value and inserts it — dangerous!)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the difference between map::find() and map::operator[]?
         (find() doesn't insert; [] inserts default value if key missing)
         Asked at: Amazon, Flipkart, Adobe

  [T][ ] What is lower_bound and upper_bound in map? Give an example.
         (lower_bound(k) = first key >= k; upper_bound(k) = first key > k)
         Asked at: Amazon, Goldman Sachs, Google, Flipkart

  [T][ ] What is std::multimap? How is it different from map?
         (multimap allows duplicate keys; map requires unique keys)
         Asked at: Amazon, TCS, Adobe

  [T][ ] How do you iterate a map in reverse order?
         (Use rbegin() and rend() iterators)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is map::count()? What does it return?
         (Returns 0 or 1 for map; can be > 1 for multimap)
         Asked at: TCS, Wipro

  [T][ ] What is map::emplace() and how is it more efficient than insert()?
         (emplace constructs value in-place, avoiding temporaries)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is the difference between map::insert() and map::emplace()?
         Asked at: Amazon, Microsoft

--------------------------------------------------------------------------------
1B. ADVANCED / INTERVIEW DEPTH
--------------------------------------------------------------------------------

  [T][ ] What does std::map use internally? (Introsort — no. Red-Black tree)
         Asked at: Amazon, Microsoft, Goldman Sachs

  ★[T][ ] What is the difference between map and set? When would you use map
           over set?
           (map stores key-value pairs; set stores only keys)
           Asked at: TCS, Amazon, Microsoft, Wipro

  ★[T][ ] How is std::map ordered? Can you change the comparator?
           (Default less<Key>; pass custom comparator as 3rd template arg)
           Asked at: Amazon, Flipkart, Adobe, Goldman Sachs

  ★[T][ ] What is std::map::merge() (C++17)? What does it do?
           (Transfers elements from another map without copying — O(N log N))
           Asked at: Google, Microsoft, advanced C++ roles

  ★[T][ ] Are iterators of map stable across insertions and deletions?
           (Yes — unlike vector, map iterators are NOT invalidated by insert/erase
            of other nodes; only the erased node's iterator is invalidated)
           Asked at: Google, Microsoft, Qualcomm

  ★[T][ ] What is the space overhead of std::map vs unordered_map?
           (map has higher overhead per node — pointer + color; unordered_map
            has overhead from hash table buckets + load factor space)
           Asked at: Goldman Sachs, Dolat Capital, HFT roles

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Count word frequencies in a sentence using map
             Iterate over words, use map[word]++ pattern
             Asked at: Amazon, Microsoft, Zoho, TCS

  [C][ ] (E) Count frequency of each element in array using map
             Asked at: TCS, Wipro, Infosys, Amazon

  ★[C][ ] (E) Given a string, find the first non-repeating character
              using map to store frequency + order
              Asked at: Amazon, Microsoft, Adobe, Zoho

  ★[C][ ] (E) Sort characters of a string by frequency (descending)
              Use map<char, int> then sort
              Asked at: Amazon, Adobe, Flipkart

  ★[C][ ] (E) Find the character(s) that appear maximum number of times in a string
              Using map<char, int>
              Asked at: TCS, Wipro, Infosys, Zoho

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Find top K frequent elements using map + priority_queue
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Sort vector of pairs by second element using lambda comparator
             vector<pair<int,int>>, sort using custom lambda
             Asked at: Amazon, Flipkart

  [C][ ] (M) Implement a multimap<int, string> frequency tracker:
             count words, then iterate from highest to lowest frequency
             Asked at: Amazon, Microsoft

  [C][ ] (M) Group anagrams together
             Use sorted string as key in map, group original strings
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Given N ranges [l, r], find the point covered by maximum ranges
             Hint: difference array / event-based approach with map
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (M) Map sum pairs: insert (key, val) and sum all values whose keys
             have a given prefix
             Asked at: Amazon, LeetCode Medium

  ★[C][ ] (M) Find the K most frequent words in a document
              Use map<string, int> for frequency, then min-heap for top K
              Asked at: Amazon, Microsoft, Flipkart, Paytm

  ★[C][ ] (M) Given a list of students and scores, use map to find the
              rank of each student (sorted by score descending)
              Asked at: Wipro, TCS, Zoho, Capgemini

  ★[C][ ] (M) Implement a phone book using map — supports insert, delete,
              lookup, and print all contacts in alphabetical order
              Asked at: TCS, Wipro, Infosys, Zoho

  ★[C][ ] (M) Given a stream of integers, maintain the running median using
              two maps (or two multisets)
              Asked at: Amazon, Goldman Sachs, Microsoft

  ★[C][ ] (M) Given an array, for each element find the count of elements
              strictly smaller than it — O(N log N) using map + prefix count
              Asked at: Amazon, Flipkart, Goldman Sachs

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement LRU Cache using class (HashMap + Doubly Linked List)
             map/unordered_map of key → list iterator; list stores (key, val)
             Asked at: Amazon, Microsoft, Google, Flipkart, Paytm

  ★[C][ ] (H) Find the smallest range covering elements from K sorted lists
              Use map<value, listIndex> to track window minimum, shrink from left
              Asked at: Google, Amazon, Goldman Sachs

  ★[C][ ] (H) Implement a time-based key-value store where get(key, timestamp)
              returns the value with the largest timestamp <= given timestamp
              Use map<string, map<int, string>> with upper_bound
              Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (H) Design a leaderboard that supports: addScore(player, score),
              top(K) — returns top K scores, reset(player)
              Use map<int, set<string>> sorted by score descending
              Asked at: Amazon, Flipkart, Paytm

================================================================================
QUICK REFERENCE — map CHEATSHEET
================================================================================

  #include <map>

  map<string, int> m;

  m["key"] = value;             // insert or update
  m.insert({"key", val});       // insert only (no update if exists)
  m.emplace("key", val);        // in-place construction
  m.erase("key");               // O(log N)
  m.find("key");                // returns iterator or m.end()
  m.count("key");               // returns 0 or 1
  m.size();
  m.empty();
  m.clear();

  // Safe access (no accidental insertion)
  if (m.count("key")) { int v = m["key"]; }
  auto it = m.find("key");
  if (it != m.end()) { int v = it->second; }

  // Range queries
  m.lower_bound(k);             // iterator to first key >= k
  m.upper_bound(k);             // iterator to first key > k
  m.equal_range(k);             // pair of (lower_bound, upper_bound)

  // Iterate in sorted key order
  for (auto& [key, val] : m) { ... }          // C++17 structured binding
  for (auto it = m.rbegin(); it != m.rend(); ++it) { ... }  // reverse

  // Multimap
  multimap<int, string> mm;
  mm.insert({1, "a"});
  mm.insert({1, "b"});

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 12 |  0 |  0 |    12
  Theory (★ added)           |  6 |  0 |  0 |     6
  Coding Easy (from files)   |  2 |  0 |  0 |     2
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 |  6 |  0 |     6
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  1 |     1
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 23 | 11 |  4 |    38

================================================================================
END
================================================================================
