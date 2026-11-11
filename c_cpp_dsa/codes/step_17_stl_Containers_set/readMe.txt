================================================================================
        STL — SET (std::set) COMPLETE QUESTION BANK
        Covers: std::set internals + classic set algorithm problems
        Compiled from all_in_one, all_in_one_question_1/2/3/4
        + Real interview questions from Google, Amazon, Microsoft,
          Flipkart, Adobe, Goldman Sachs, Zoho, TCS, Wipro & more
        No duplicates | Theory + Coding | All difficulties
        ★ = Added from real interviews not in source files
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding
  ★  = Added question (real interview, not in source files)

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. std::set INTERNALS & MEMORY
--------------------------------------------------------------------------------

  [T][ ] What is std::set in C++? What are its key guarantees?
         (Ordered, unique elements; implemented as a self-balancing BST — Red-Black Tree)
         Asked at: TCS, Wipro, Amazon, Zoho, Infosys

  [T][ ] What is the underlying data structure of std::set?
         (Red-Black Tree — self-balancing BST;
          guarantees O(log N) insert, delete, find)
         Asked at: Amazon, Microsoft, Google, Persistent

  [T][ ] What is the difference between std::set and std::unordered_set?
         (set: ordered, O(log N) all ops, Red-Black Tree;
          unordered_set: unordered, O(1) avg ops, hash table;
          set: supports lower_bound/upper_bound; unordered_set: does not)
         Asked at: TCS, Wipro, Amazon, Microsoft, Google

  [T][ ] What is the time complexity of insert, find, erase, and iteration in std::set?
         (All O(log N); iteration over entire set: O(N) in sorted order)
         Asked at: TCS, Wipro, Amazon, Google

  [T][ ] What does std::set guarantee about element ordering?
         (Elements always stored in ascending sorted order by default;
          custom ordering via comparator template parameter)
         Asked at: TCS, Wipro, Zoho, Amazon

  [T][ ] How do you create a std::set in descending order?
         (set<int, greater<int>> s;)
         Asked at: TCS, Amazon, Zoho

  [T][ ] What is the difference between set::find() and std::find() on a set?
         (set::find(): O(log N) — uses BST structure;
          std::find(): O(N) — linear scan, ignores BST property;
          ALWAYS use set::find() for sets)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] What is lower_bound and upper_bound on std::set? What do they return?
         (lower_bound(x): iterator to first element >= x, O(log N);
          upper_bound(x): iterator to first element > x, O(log N))
         Asked at: Amazon, Microsoft, Google, Flipkart, Goldman Sachs

  [T][ ] What is equal_range on std::set? What does it return?
         (Returns pair of iterators: (lower_bound, upper_bound);
          for set, both point to same element or end — since no duplicates)
         Asked at: Persistent, Nagarro, Amazon

  [T][ ] Are iterators of std::set invalidated on insert or erase?
         (Only the erased element's iterator is invalidated;
          all other iterators remain valid — BST doesn't move other nodes)
         Asked at: Amazon, Adobe, Persistent

  [T][ ] When would you prefer std::set over std::unordered_set?
         (When sorted order is needed; when lower_bound/upper_bound needed;
          when worst-case O(log N) guarantee is required over O(N) worst-case hash)
         Asked at: Amazon, Microsoft, Google

  ★[T][ ] What type of iterator does std::set provide?
          (Bidirectional iterator — can go forward and backward with ++ and --;
           NOT random access — cannot do it + 3)
          Asked at: Persistent, Nagarro, Amazon

  ★[T][ ] What happens when you try to insert a duplicate into std::set?
          (Insert is silently ignored — set only stores unique elements;
           insert returns pair<iterator, bool> — bool is false for duplicate)
          Asked at: TCS, Wipro, Amazon, Zoho

  ★[T][ ] How do you check if an element exists in std::set efficiently?
          (s.count(x) — returns 0 or 1; or s.find(x) != s.end(); both O(log N))
          Asked at: TCS, Wipro, Amazon

  ★[T][ ] How much memory does each node in std::set consume?
          (Each node: data + left ptr + right ptr + parent ptr + color bit;
           ~40–48 bytes per node on 64-bit — much more than array/vector per element)
          Asked at: Dolat Capital, HFT firms, advanced C++ roles

  ★[T][ ] What is a policy-based ordered set (order statistics tree) in C++?
          How does it differ from std::set?
          (Using __gnu_pbds::tree — supports find_by_order(k) and order_of_key(x)
           in O(log N); std::set doesn't support these)
          Asked at: Google, Goldman Sachs, competitive programming

--------------------------------------------------------------------------------
1B. std::set OPERATIONS — PRACTICAL KNOWLEDGE
--------------------------------------------------------------------------------

  [T][ ] What is the difference between set::erase(value) and set::erase(iterator)?
         (erase(value): removes all elements with that value — O(log N + count);
          erase(iterator): removes element at that position — O(1) amortized)
         Asked at: Amazon, Persistent, Nagarro

  ★[T][ ] How do you use std::set with custom objects (user-defined types)?
          (Define bool operator<(const T& other) const inside the class,
           OR provide a custom comparator struct with bool operator()(T a, T b))
          Asked at: Amazon, Adobe, Persistent, Nagarro

  ★[T][ ] What is the use of set::merge() introduced in C++17?
          (Moves elements from another set into current set without reallocation;
           O(N log N); nodes are spliced, not copied)
          Asked at: Persistent, Nagarro, advanced C++ roles

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. std::set BASIC USAGE
--------------------------------------------------------------------------------

  ★[C][ ] (E) Demonstrate insert, find, erase, count, size, and iteration on std::set.
              Show that duplicates are silently ignored.
              Asked at: TCS, Wipro, Infosys, Zoho

  ★[C][ ] (E) Given a vector<int> with duplicates, remove all duplicates and keep
              elements in sorted order using std::set.
              (insert all into set, iterate to get sorted unique elements)
              Asked at: TCS, Wipro, Amazon, Zoho

  ★[C][ ] (E) Create a std::set<int> in descending order using greater<int>.
              Insert elements and show iteration is in descending order.
              Asked at: TCS, Wipro, Zoho

  ★[C][ ] (E) Use lower_bound and upper_bound on a set to find:
              (a) First element >= x
              (b) First element > x
              (c) All elements in range [L, R]
              Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (E) Given std::set<int>, find the floor (largest element <= x)
              and ceiling (smallest element >= x) of a given value.
              (Use lower_bound and upper_bound, handle edge cases)
              Asked at: Amazon, Microsoft, Flipkart, Zoho

  ★[C][ ] (E) Given a set, find the Kth smallest element.
              (Advance iterator K times from begin() — O(K))
              Asked at: Amazon, Zoho, Goldman Sachs

  ★[C][ ] (E) Find the union and intersection of two sets using std::set.
              (Union: insert all from both; Intersection: iterate smaller, find in larger)
              Asked at: TCS, Wipro, Infosys, Amazon

  ★[C][ ] (E) Demonstrate iterator stability of std::set:
              Store iterator to element, insert 1000 other elements,
              verify the original iterator is still valid.
              Compare with vector where iterators are invalidated.
              Asked at: Amazon, Adobe, Persistent

--------------------------------------------------------------------------------
2B. CLASSIC EASY PROBLEMS USING SET
--------------------------------------------------------------------------------

  ★[C][ ] (E) Given array of integers, find all elements that appear exactly once.
              Use std::set to collect unique, compare with original count.
              Asked at: TCS, Wipro, Amazon, Zoho

  ★[C][ ] (E) Given two arrays, find their common elements (intersection).
              Sort + std::set_intersection or use set find.
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Check if an array contains any duplicates.
              Insert into set; if any insert returns false → duplicate found.
              O(N log N). Compare with unordered_set O(N) approach.
              Asked at: TCS, Wipro, Amazon, Zoho

  ★[C][ ] (E) Given a sorted array, count distinct elements using std::set.
              Asked at: TCS, Wipro, Infosys

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. RANGE QUERIES & FLOOR/CEILING
--------------------------------------------------------------------------------

  ★[C][ ] (M) Design a data structure that supports:
              insert(x), delete(x), findFloor(x), findCeil(x) — all O(log N).
              Use std::set with lower_bound/upper_bound.
              Asked at: Amazon, Microsoft, Flipkart, Goldman Sachs

  ★[C][ ] (M) Count elements in a set that fall in range [L, R].
              Use lower_bound(L) and upper_bound(R), then std::distance.
              Note: std::distance on set iterator is O(N) — discuss trade-off.
              Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (M) Given an array, for each element find the nearest element
              already inserted that is smaller and the nearest that is larger.
              Process elements left to right, maintain a set — O(N log N).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Contains Duplicate III — check if any two elements in array are at
              most K indices apart and their values differ by at most T.
              Use a sorted set (sliding window of size K) + lower_bound — O(N log K).
              Asked at: Amazon, Google — LeetCode 220

  ★[C][ ] (M) Sliding window: maintain a sorted set of the last K elements.
              For each new element, find its rank in the current window.
              Asked at: Amazon, Goldman Sachs

--------------------------------------------------------------------------------
3B. INTERVAL & SCHEDULING WITH SET
--------------------------------------------------------------------------------

  ★[C][ ] (M) Insert interval into a set of non-overlapping intervals.
              Merge overlapping intervals using lower_bound to find neighbors.
              O(log N) per operation.
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Find the minimum number of platforms (rooms) needed for meetings
              where arrivals and departures are given.
              Use sorted set of departure times — O(N log N).
              Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (M) Given a stream of reservation requests and cancellations,
              always return the smallest available seat number.
              Use std::set of available seats — O(log N) per operation.
              Asked at: Amazon, Google — LeetCode 1845

  ★[C][ ] (M) Design a calendar system that adds events and checks for conflicts.
              Store events as (start, end) in a set ordered by start;
              check overlap with neighbors using lower_bound.
              Asked at: Amazon, Google — LeetCode 729

--------------------------------------------------------------------------------
3C. SORTED STRUCTURE PROBLEMS
--------------------------------------------------------------------------------

  ★[C][ ] (M) Implement a sorted container supporting:
              insert(x), deleteMin(), deleteMax(), findMin(), findMax() — all O(log N).
              Use std::set, maintain begin() and prev(end()) iterators.
              Asked at: Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Implement a sorted container supporting O(log N) insert, O(log N) delete,
              and O(1) findMin and findMax simultaneously.
              Use std::set, track min (begin()) and max (prev(end())).
              Asked at: Dolat Capital, Goldman Sachs, competitive programming

  ★[C][ ] (M) Given N points on a number line, find the maximum number of points
              that can be covered by a single window of length L.
              Sort with set + sliding window — O(N log N).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Longest consecutive sequence — find length of longest consecutive run.
              Insert all into set; for each sequence start (x where x-1 not in set),
              count consecutive elements — O(N log N).
              (Compare with unordered_set O(N) solution)
              Asked at: Amazon, Microsoft, Google — LeetCode 128

  ★[C][ ] (M) Find if any two numbers in array have absolute difference exactly K.
              For each x, check if (x+K) or (x-K) in set — O(N log N).
              Asked at: Amazon, Microsoft — LeetCode 532

  ★[C][ ] (M) Given a stream of integers, at any point output the sorted list.
              Use std::set for O(log N) insert and O(N) iteration.
              Asked at: Amazon, Goldman Sachs, Dolat Capital

--------------------------------------------------------------------------------
3D. SET-BASED SIMULATION & DESIGN
--------------------------------------------------------------------------------

  ★[C][ ] (M) Design an exam ranking system:
              addScore(studentId, score), getTopK(K), getRank(studentId).
              Use std::set<pair<int,int>> (score, id) for auto-sorting.
              Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Design a real-time leaderboard:
              updateScore(playerId, score), getTopK(K), getRank(playerId).
              Use set<pair<int,int>> (score, playerId) — O(log N) per update.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Implement a "sliding window distinct elements" counter:
              Given array and window size K, count distinct elements in each window.
              Use std::map for frequency + set for distinct tracking — O(N log N).
              Asked at: Amazon, Flipkart

  ★[C][ ] (M) Given a set of characters and a string, check if the string
              contains only characters from the set (set membership queries).
              Asked at: TCS, Wipro, Zoho

--------------------------------------------------------------------------------
3E. CUSTOM COMPARATOR & ADVANCED SET USAGE
--------------------------------------------------------------------------------

  ★[C][ ] (M) Create a set of custom structs (Point with x, y).
              Order by x first, then y for ties.
              Implement operator< or a custom comparator.
              Asked at: Amazon, Adobe, Persistent

  ★[C][ ] (M) Use a set to implement a duplicate-free priority queue:
              Each element unique; operations: insert, getMin, getMax, deleteMin.
              Asked at: Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Implement a time-ordered event log using std::set<pair<time,event>>.
              Events at same time stored by event name.
              Support: addEvent, getNextEvent, removeEvent — all O(log N).
              Asked at: Adobe, Persistent, Dolat Capital

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  ★[C][ ] (H) Implement an order statistics tree using GNU policy-based data structure:
              find_by_order(k): Kth smallest element — O(log N)
              order_of_key(x): rank of x — O(log N)
              Use __gnu_pbds::tree with tree_order_statistics_node_update.
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Design a data structure that supports:
              insert(x), delete(x), findKthSmallest(k), countLess(x) — all O(log N).
              Use policy-based tree or augmented BST.
              Asked at: Google, Goldman Sachs, Dolat Capital

  ★[C][ ] (H) Count inversions in an array using std::set.
              For each element, count how many already-inserted elements are greater.
              Use order_of_key from policy-based tree — O(N log N).
              (Compare with merge sort approach)
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Given a sorted set, implement a persistence operation:
              After each insert/delete, keep old version accessible.
              Discuss trade-offs with immutable/functional red-black tree.
              Asked at: Google, advanced data structure roles

  ★[C][ ] (H) Count the number of range sum subarrays falling in [lower, upper].
              Use sorted set of prefix sums + lower_bound/upper_bound — O(N log N).
              Asked at: Google, Goldman Sachs — LeetCode 327

  ★[C][ ] (H) Given N intervals, find all pairs of intervals that overlap.
              Use sorted set of active intervals ordered by end time — O(N log N).
              Asked at: Google, Amazon, Goldman Sachs

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output?
          set<int> s = {3, 1, 4, 1, 5, 9, 2, 6};
          for (auto x : s) cout << x << " ";
          (Output: 1 2 3 4 5 6 9 — sorted, duplicates removed)
          Asked at: TCS, Wipro, Zoho, Amazon

  ★[T][ ] What is the output and why?
          set<int> s = {1, 2, 3, 4, 5};
          auto it = s.find(3);
          s.erase(1);
          s.insert(10);
          cout << *it;
          (Output: 3 — set iterators are not invalidated by insert/erase of other elements)
          Asked at: Amazon, Adobe, Persistent

  ★[T][ ] What is the difference between these two?
          set<int> s;
          s.insert(5);
          auto [it, success] = s.insert(5);  // C++17 structured binding
          cout << success;
          (Output: 0 — false, because 5 already exists; set ignores duplicates)
          Asked at: Amazon, Persistent, Nagarro

  ★[T][ ] What is the output?
          set<int> s = {1, 3, 5, 7, 9};
          auto it = s.lower_bound(4);
          cout << *it;
          it = s.upper_bound(5);
          cout << " " << *it;
          (Output: 5 7 — lower_bound(4) = first >= 4 = 5; upper_bound(5) = first > 5 = 7)
          Asked at: Amazon, Microsoft, Flipkart, Goldman Sachs

  ★[T][ ] Why is this inefficient and how would you fix it?
          set<int> s = {1, 2, 3, 4, 5};
          auto it = std::find(s.begin(), s.end(), 3);  // O(N)!
          // Fix: use s.find(3) which is O(log N)
          Asked at: Amazon, Persistent, Nagarro, TCS

  ★[T][ ] What is the output?
          set<int> s = {10, 20, 30};
          auto it = s.end();
          --it;
          cout << *it;
          (Output: 30 — prev(end()) = last element = largest)
          Asked at: Goldman Sachs, Dolat Capital, Persistent

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — std::set Internals & Memory          | 16 |  0 |  0 |    16
  Theory — Operations & Practical Knowledge     |  3 |  0 |  0 |     3
  Coding Easy — std::set Basic Usage            |  8 |  0 |  0 |     8
  Coding Easy — Classic Problems with Set       |  4 |  0 |  0 |     4
  Coding Medium — Range Queries & Floor/Ceil    |  0 |  5 |  0 |     5
  Coding Medium — Interval & Scheduling         |  0 |  4 |  0 |     4
  Coding Medium — Sorted Structure Problems     |  0 |  6 |  0 |     6
  Coding Medium — Simulation & Design           |  0 |  4 |  0 |     4
  Coding Medium — Custom Comparator & Advanced  |  0 |  3 |  0 |     3
  Coding Hard                                   |  0 |  0 |  6 |     6
  Tricky Output / Concept Questions             |  6 |  0 |  0 |     6
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 37 | 22 |  6 |    65

  ★ = 59 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI:
    → What is std::set, insert/find/erase, duplicates silently ignored,
      iteration in sorted order, set vs unordered_set, union & intersection

  ZOHO:
    → Set in descending order, floor and ceiling queries,
      sliding window distinct elements, membership check

  AMAZON / FLIPKART:
    → lower_bound/upper_bound, contains duplicate III (sliding window + set),
      find floor/ceiling, Kth smallest, calendar with conflict check,
      find pair with difference K, smallest available seat

  MICROSOFT / ADOBE:
    → Iterator stability, custom comparator for structs, insert interval with merge,
      erase(value) vs erase(iterator), sorted container design

  GOOGLE / ATLASSIAN:
    → Count range sum subarrays, order statistics tree (GNU pbds),
      longest consecutive sequence, persistent set, overlapping intervals count

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Policy-based tree (order_of_key, find_by_order), count inversions,
      O(1) findMin+findMax with set, duplicate-free priority queue,
      time-ordered event log, rank queries, memory per node comparison

================================================================================
END
================================================================================
