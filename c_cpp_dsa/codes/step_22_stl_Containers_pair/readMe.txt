================================================================================
        PAIR — COMPLETE QUESTION BANK
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

  [T][ ] What is std::pair? What header is it in?
         (Template struct with .first and .second; in <utility>)
         Asked at: TCS, Wipro, Amazon, Microsoft

  [T][ ] What is make_pair()? When do you use it vs brace initialization?
         (make_pair(a, b) pre-C++11 style; {a, b} works in C++11 onwards)
         Asked at: Amazon, TCS, Microsoft

  [T][ ] How are pairs compared? What is the default comparison order?
         (Lexicographic: first compare .first, then .second if equal)
         Asked at: Amazon, Flipkart, Goldman Sachs

  [T][ ] How do you sort a vector of pairs? What is the default sort order?
         (Sorted by .first ascending; ties broken by .second ascending)
         Asked at: Amazon, Flipkart, Microsoft

  [T][ ] What is a structured binding (C++17) and how does it work with pair?
         (auto [x, y] = p; — binds x to p.first and y to p.second)
         Asked at: Amazon, Google, Microsoft, Adobe

  [T][ ] Can you use pair as a key in map or unordered_map?
         (Yes in map — has default < comparison;
          In unordered_map you need a custom hash)
         Asked at: Amazon, Google, Microsoft

  [T][ ] What is the difference between pair<int, int> and struct with two ints?
         (pair has built-in comparison operators and works with STL containers)
         Asked at: TCS, Amazon, Adobe

  [T][ ] Can pair be used in a set? What ordering does set use for pairs?
         (Yes — lexicographic ordering via operator<)
         Asked at: Amazon, Microsoft, Flipkart

--------------------------------------------------------------------------------
1B. ADVANCED / INTERVIEW DEPTH
--------------------------------------------------------------------------------

  ★[T][ ] What is std::tie() and how is it used with pairs?
           (auto [a, b] = p; or tie(a, b) = p; — unpacks pair into variables)
           Asked at: Google, Microsoft, Adobe

  ★[T][ ] What is std::swap() for pairs? Is it a deep or shallow swap?
           (swap(p1, p2) swaps both .first and .second — O(1))
           Asked at: Amazon, TCS, Wipro

  ★[T][ ] What is the difference between pair<int&, int&> and pair<int, int>&?
           (pair of references vs reference to pair — different semantics)
           Asked at: Google, advanced C++ roles

  ★[T][ ] How would you implement a custom pair that also stores metadata
           (e.g., index of origin)? When would you use this pattern?
           (Augmented pair struct — common in Dijkstra/scheduling)
           Asked at: Goldman Sachs, Amazon, Flipkart

  ★[T][ ] What happens if you modify .first of a pair that is used as a key in map?
           (Undefined behavior / corrupts the BST order — never modify map key in place)
           Asked at: Google, Microsoft, advanced C++ roles

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Given vector<pair<string, int>>, sort by string length ascending,
             then alphabetically for equal lengths
             Asked at: Amazon, Flipkart

  [C][ ] (E) Find all pairs in an array with a given sum (return as vector of pairs)
             Asked at: Amazon, Zoho

  [C][ ] (E) Find all pairs in array with given difference K
             Asked at: Amazon, Zoho, TCS

  [C][ ] (E) Check if array has a pair summing to 0 (sorted array, two pointers)
             Asked at: Amazon, TCS

  [C][ ] (E) Find all pairs in sorted array with given difference D
             Asked at: Amazon, Flipkart

  [C][ ] (E) Find if sorted array can be divided into consecutive pairs
             Asked at: Amazon, Wipro

  ★[C][ ] (E) Given an array of pairs, find the pair with the maximum sum of
              first + second element
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Sort an array of (name, score) pairs first by score descending,
              then alphabetically for ties
              Asked at: Amazon, TCS, Wipro, Zoho

  ★[C][ ] (E) Given a vector of (x, y) coordinate pairs, find the one closest
              to the origin
              Asked at: Amazon, Microsoft, Google

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Sort vector of pairs by second element using lambda comparator
             sort(v.begin(), v.end(), [](auto& a, auto& b){ return a.second < b.second; })
             Asked at: Amazon, Flipkart

  [C][ ] (M) Given two sorted arrays, find K pairs with smallest sums (one from each)
             Hint: min-heap of size K
             Asked at: Amazon, Google

  [C][ ] (M) Find the maximum sum of K non-overlapping pairs from array
             Precompute max pair sum from left and right using heaps
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Palindrome pairs: given list of words, find all pairs (i, j) where
             words[i] + words[j] is a palindrome — O(N * L²) using hashmap
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) 4Sum II: given 4 arrays, count tuples (i,j,k,l) where
             A[i]+B[j]+C[k]+D[l] == 0
             Hint: hashmap of pairwise sums from A+B, then search C+D
             Asked at: Amazon, Google

  [C][ ] (M) Given array of meeting times [start, end], find minimum conference
             rooms required — sort by start, use min-heap of end times
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Minimum difference pair from two sorted arrays
             Merge-like two pointer approach
             Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Given N jobs each with a deadline and profit (as pairs), find
              maximum profit by selecting at most one job per time slot
              (Job Sequencing — sort by profit desc, greedy with DSU)
              Asked at: Amazon, Goldman Sachs, Flipkart

  ★[C][ ] (M) Given list of intervals as pairs [start, end], merge all overlapping
              intervals and return the merged list
              Asked at: Amazon, Microsoft, Google, Adobe

  ★[C][ ] (M) K closest points to origin — given vector<pair<int,int>>,
              return K closest using max-heap of size K
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Count the number of pairs (i, j) such that |arr[i] - arr[j]| <= K
              Sorting + sliding window or binary search
              Asked at: Amazon, Flipkart, Goldman Sachs

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Minimum XOR value pair: find pair with minimum XOR value in array
             Sort + compare adjacent pairs (XOR of close values is smallest)
             Asked at: Amazon, Goldman Sachs

  [C][ ] (H) Find the K-th smallest pair distance in an array
             Sort + binary search on distance + two-pointer count
             Asked at: Google, Amazon, Goldman Sachs

  ★[C][ ] (H) Given array of pairs (a, b), find a subset such that
              no two pairs (a1,b1) and (a2,b2) satisfy a1 < a2 AND b1 < b2
              (Maximum anti-chain — LIS variant)
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Given N pairs of (start, end) intervals, find the maximum number
              of non-overlapping intervals that can be selected
              (Greedy interval scheduling — sort by end time)
              Asked at: Amazon, Google, Microsoft, Goldman Sachs

  ★[C][ ] (H) Closest pair of points in 2D plane — O(N log N) using divide and conquer
              Asked at: Google, Amazon, Goldman Sachs, competitive programming

================================================================================
QUICK REFERENCE — pair CHEATSHEET
================================================================================

  #include <utility>   // pair, make_pair
  #include <vector>    // for vector<pair<>>

  // Declaration
  pair<int, string> p = {1, "hello"};
  pair<int, string> p2 = make_pair(1, "hello");

  // Access
  p.first;          // 1
  p.second;         // "hello"

  // C++17 structured binding
  auto [a, b] = p;  // a = 1, b = "hello"

  // Comparison (lexicographic)
  p1 < p2;          // compare first, then second
  p1 == p2;         // both first and second must match

  // Vector of pairs
  vector<pair<int,int>> v = {{1,3}, {2,1}, {0,5}};

  // Sort by first (default)
  sort(v.begin(), v.end());

  // Sort by second ascending
  sort(v.begin(), v.end(), [](const auto& a, const auto& b){
      return a.second < b.second;
  });

  // Sort by second descending, first ascending for ties
  sort(v.begin(), v.end(), [](const auto& a, const auto& b){
      if (a.second != b.second) return a.second > b.second;
      return a.first < b.first;
  });

  // Swap two pairs
  swap(p1, p2);

  // pair as map key (works directly)
  map<pair<int,int>, int> m;
  m[{1,2}] = 10;

  // pair as unordered_map key (needs custom hash)
  struct PairHash {
      size_t operator()(const pair<int,int>& p) const {
          return hash<long long>()(((long long)p.first << 32) | p.second);
      }
  };
  unordered_map<pair<int,int>, int, PairHash> um;

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  8 |  0 |  0 |     8
  Theory (★ added)           |  5 |  0 |  0 |     5
  Coding Easy (from files)   |  6 |  0 |  0 |     6
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 |  7 |  0 |     7
  Coding Medium (★ added)    |  0 |  4 |  0 |     4
  Coding Hard (from files)   |  0 |  0 |  2 |     2
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 22 | 11 |  5 |    38

================================================================================
END
================================================================================
