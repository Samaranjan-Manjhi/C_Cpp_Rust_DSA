================================================================================
        STL — VECTOR COMPLETE QUESTION BANK
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
1A. VECTOR INTERNALS & MEMORY
--------------------------------------------------------------------------------

  [T][ ] What is a vector in C++? How is it different from a raw array?
         (Dynamic size, heap-allocated, contiguous memory, automatic resize)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] How does vector<int> work internally?
         What happens when it resizes (push_back beyond capacity)?
         (Allocates new block ~2x size, copies/moves elements, frees old block)
         Asked at: Amazon, Microsoft, Flipkart, Swiggy

  [T][ ] What is amortized O(1) for vector push_back? Explain the resizing strategy.
         (Doubling strategy makes total work O(N) across N insertions → O(1) amortized)
         Asked at: Amazon, Microsoft, Flipkart, Swiggy

  [T][ ] What is the difference between vector size() and capacity()?
         (size: current elements; capacity: allocated memory slots)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What does reserve() do? How is it different from resize()?
         (reserve: pre-allocates capacity, no new elements;
          resize: changes size, initializes new elements with default value)
         Asked at: Amazon, Microsoft, Persistent, Adobe

  [T][ ] What does shrink_to_fit() do? Is it guaranteed to reduce capacity?
         (Requests capacity == size; not guaranteed by standard — implementation-defined)
         Asked at: Persistent, Nagarro, advanced C++ roles

  [T][ ] What is the complexity of inserting at the beginning of a vector?
         How would you make this faster?
         (O(N) — all elements must shift; use deque for O(1) front insert)
         Asked at: Amazon, Flipkart

  [T][ ] Why is cache performance better for vector than linked list?
         Explain spatial locality.
         (Contiguous memory → CPU cache lines loaded efficiently;
          linked list: scattered nodes → cache misses)
         Asked at: Dolat Capital, HFT firms, Samsung

  ★[T][ ] What happens to iterators, pointers, and references after push_back?
          (They may be INVALIDATED if reallocation happens)
          Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] What is iterator invalidation in vector? Which operations cause it?
          (push_back/insert: may invalidate all if reallocation;
           erase: invalidates from erased position onwards)
          Asked at: Amazon, Google, Adobe

  ★[T][ ] What is the difference between vector<bool> and vector<char>?
          Why is vector<bool> considered a special case / a mistake?
          (vector<bool> is space-optimized bitset — operator[] returns proxy, not real bool&)
          Asked at: Google, Microsoft, advanced C++ roles

  ★[T][ ] When would you use vector::emplace_back() over push_back()?
          (emplace_back: constructs in-place, avoids copy/move;
           push_back: requires constructed object — extra copy/move)
          Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] What is the difference between vector::at() and vector::operator[]?
          (at() does bounds checking and throws std::out_of_range;
           operator[] is unchecked — undefined behavior if out of bounds)
          Asked at: TCS, Wipro, Zoho, Amazon

  ★[T][ ] What is the erase-remove idiom? Why is erase() alone not enough?
          (erase() at position is O(N); remove() moves unwanted elements to end O(N);
           combine: v.erase(remove(v.begin(), v.end(), x), v.end()))
          Asked at: Amazon, Persistent, Nagarro

--------------------------------------------------------------------------------
1B. VECTOR OPERATIONS & STL ALGORITHMS
--------------------------------------------------------------------------------

  [T][ ] What is the time complexity of push_back, pop_back, insert, erase, access in vector?
         (push_back: O(1) amortized; pop_back: O(1); access: O(1);
          insert/erase at middle: O(N))
         Asked at: TCS, Wipro, Amazon, Microsoft

  [T][ ] What is the difference between vector::clear() and assigning an empty vector?
         (clear(): sets size to 0, capacity unchanged;
          v = {}: may or may not release memory — use shrink_to_fit after)
         Asked at: Persistent, Nagarro

  [T][ ] What is the difference between find() and binary_search() for vectors?
         (find(): linear O(N), works on unsorted;
          binary_search(): O(log N), requires sorted vector)
         Asked at: TCS, Amazon, Zoho

  [T][ ] What is lower_bound vs upper_bound on a sorted vector?
         (lower_bound: first element >= x;
          upper_bound: first element > x;
          Both return iterators, O(log N))
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What does std::sort use internally on vectors? What is its complexity?
         (Introsort: hybrid of quicksort + heapsort + insertion sort; O(N log N))
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is stable_sort? When would you use it over sort?
         (stable_sort: preserves relative order of equal elements; O(N log² N) typically)
         Asked at: Amazon, Flipkart, Adobe

  [T][ ] What is the difference between vector::assign() and the = operator?
         Asked at: TCS, Wipro, Persistent

  ★[T][ ] What is std::move for vectors? What happens to the source vector after move?
          (Source vector is left in a valid but unspecified state — usually empty)
          Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] How would you copy a vector efficiently? What are the different ways?
          (Copy constructor, assignment, std::copy, range constructor — all O(N))
          Asked at: TCS, Wipro, Amazon

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. BASIC VECTOR OPERATIONS
--------------------------------------------------------------------------------

  [C][ ] (E) Read N integers into a vector and print them in reverse order.
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][ ] (E) Find the maximum and minimum element in a vector<int>.
             Do it in a single pass (one loop).
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][ ] (E) Find the sum and average of elements in a vector<int>.
             Use std::accumulate.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Given vector<int>, remove all elements equal to X in-place.
             Use the erase-remove idiom: v.erase(remove(v.begin(), v.end(), x), v.end())
             Asked at: Amazon, Persistent, Nagarro

  [C][ ] (E) Find the second smallest element in vector<int> without sorting.
             Handle duplicates correctly.
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Use std::accumulate to compute product of all elements in a vector.
             Asked at: Persistent, Nagarro

  [C][ ] (E) Given vector<int>, use std::partition to separate even and odd elements.
             Show the result — do NOT sort.
             Asked at: Persistent, Nagarro

  [C][ ] (E) Sort a vector<int> in ascending, then descending order.
             Use std::sort with default and greater<int>() comparator.
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Check if a vector is sorted in ascending order.
             Use std::is_sorted.
             Asked at: Amazon, Wipro, Infosys

  [C][ ] (E) Remove duplicate elements from a vector<int>.
             Sort first, then use std::unique + erase.
             Asked at: TCS, Wipro, Amazon, Zoho

  ★[C][ ] (E) Given vector<int>, count elements greater than a given value K.
              Use std::count_if with a lambda.
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Reverse a vector in-place without using std::reverse.
              Write the logic manually using two pointers.
              Asked at: TCS, Wipro, Infosys, Zoho

  ★[C][ ] (E) Given vector<int>, find all elements that appear more than once.
              Print each duplicate exactly once.
              Asked at: TCS, Wipro, Capgemini, Zoho

  ★[C][ ] (E) Copy a vector into another using: copy constructor, assign(), std::copy.
              Show all three methods and their outputs.
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Given vector<int>, move all zeros to the end without disturbing
              the relative order of non-zero elements. Do it in O(N) in-place.
              Asked at: Amazon, Microsoft, Google

--------------------------------------------------------------------------------
2B. SEARCHING & SORTING ON VECTORS
--------------------------------------------------------------------------------

  [C][ ] (E) Given a sorted vector<int>, use lower_bound and upper_bound to
             find the first and last occurrence of a target value.
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Given vector<pair<string,int>>, sort by string length ascending,
             then alphabetically for equal lengths.
             Use a custom lambda comparator.
             Asked at: Amazon, Flipkart

  ★[C][ ] (E) Given a sorted vector<int> with one element missing in range [1, N],
              find the missing number using lower_bound.
              Asked at: TCS, Amazon, Microsoft

  ★[C][ ] (E) Given a vector<int>, find the index of the maximum element.
              Use std::max_element and std::distance.
              Asked at: TCS, Wipro, Infosys

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. TWO POINTERS & SLIDING WINDOW ON VECTOR
--------------------------------------------------------------------------------

  [C][ ] (M) Given sorted vector<int> and target T,
             find all pairs that sum to T. Return indices.
             Use two-pointer approach — O(N).
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) Given vector<int>, find the maximum sum subarray (Kadane's Algorithm).
             Return the sum and the subarray itself.
             Asked at: Amazon, Microsoft, Google, Adobe, Goldman Sachs

  [C][ ] (M) Given vector<int>, find the longest subarray with sum equal to K.
             Use prefix sum + hashmap — O(N).
             Asked at: Amazon, Flipkart, Paytm, Swiggy

  [C][ ] (M) Given vector<int>, find the maximum element in every window of size K.
             Use std::deque as a monotonic queue — O(N).
             Asked at: Amazon, Goldman Sachs, Microsoft

  [C][ ] (M) Given vector<int>, find minimum size subarray whose sum >= S.
             Use sliding window — O(N).
             Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Given vector<int>, find the longest subarray with equal number of
              0s and 1s. Use prefix sum + hashmap.
              Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Given vector<int>, find two numbers that sum to target (Two Sum).
              Return indices. Use unordered_map — O(N).
              Asked at: Amazon, Google, Microsoft, Adobe, Flipkart (VERY common!)

  ★[C][ ] (M) Given vector<int>, find all unique triplets that sum to zero (3Sum).
              Sort + two pointer. Handle duplicates carefully.
              Asked at: Amazon, Microsoft, Google, Adobe

--------------------------------------------------------------------------------
3B. REARRANGING & TRANSFORMING VECTOR
--------------------------------------------------------------------------------

  [C][ ] (M) Implement a custom comparator for std::sort that sorts strings
             by number of vowels descending, then alphabetically for ties.
             Asked at: Amazon, Adobe

  [C][ ] (M) Given vector<vector<int>> (2D grid), flatten into 1D vector using STL.
             Use std::accumulate with lambda or std::copy.
             Asked at: Adobe, Atlassian

  [C][ ] (M) Given two sorted vectors, merge them into one sorted vector
             without using sort(). Use std::merge.
             Asked at: Amazon, Adobe

  [C][ ] (M) Use std::next_permutation to generate ALL permutations of a sorted vector.
             Count total permutations and verify = N!
             Asked at: Amazon, Competitive Programming

  [C][ ] (M) Given vector<int>, rotate it right by K positions in O(N) O(1).
             Hint: reverse entire → reverse first K → reverse last N-K.
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Given vector<int>, rearrange into: [min, max, 2nd_min, 2nd_max, ...]
             without using extra space.
             Asked at: Amazon, Flipkart, Adobe

  ★[C][ ] (M) Given vector<int>, find the product of all elements except itself
              without using division. O(N) time O(1) extra space.
              Asked at: Amazon, Microsoft, Google, Adobe (very common!)

  ★[C][ ] (M) Given vector<int> of heights, find maximum water trapped between bars
              (Trapping Rain Water). Use two-pointer O(N) O(1).
              Asked at: Amazon, Microsoft, Google, Goldman Sachs

  ★[C][ ] (M) Given vector<int> of stock prices, find max profit from one buy-sell.
              Also solve the variant: unlimited buy-sell transactions.
              Asked at: Amazon, Microsoft, Google, Flipkart (very common!)

  ★[C][ ] (M) Given vector<int>, find the smallest positive integer not present.
              O(N) time O(1) space using index marking.
              Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Given vector<int>, sort it using Dutch National Flag algorithm
              (sort 0s, 1s, 2s in single pass O(N) O(1)).
              Asked at: Amazon, Microsoft, Adobe, Flipkart

--------------------------------------------------------------------------------
3C. STL ALGORITHMS ON VECTOR
--------------------------------------------------------------------------------

  [C][ ] (M) Using STL only (no raw loops), find the top-3 most frequent elements
             from vector<int>. Use unordered_map + partial_sort.
             Asked at: Amazon, Google

  [C][ ] (M) Given vector<int> and a predicate (e.g. even), use std::partition
             to separate elements satisfying the predicate from those that don't.
             Then use std::stable_partition — show the difference.
             Asked at: Amazon, Adobe, Persistent

  [C][ ] (M) Use std::transform to apply a function (e.g. square each element)
             to a vector and store result in another vector.
             Then use in-place transform on the same vector.
             Asked at: Amazon, Persistent, Nagarro

  ★[C][ ] (M) Given vector<int>, use std::partial_sort to find the K smallest elements
              in sorted order without fully sorting the vector.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Given vector<int>, find the Kth largest element using:
              (a) nth_element — O(N) average
              (b) partial_sort — O(N log K)
              (c) priority_queue — O(N log K)
              Compare all three approaches.
              Asked at: Amazon, Microsoft, Google, Goldman Sachs (very common!)

  ★[C][ ] (M) Implement copy-on-write (COW) vector:
              Multiple handles share same internal vector;
              perform deep copy only when write happens.
              Asked at: Dolat Capital, Adobe, Persistent

--------------------------------------------------------------------------------
3D. VECTOR OF VECTORS & MATRIX PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) Given vector<vector<int>> matrix, print it in spiral order.
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Given vector<vector<int>> matrix, rotate it 90 degrees clockwise in-place.
             (Transpose + reverse each row)
             Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Given vector<vector<int>> where each row is sorted,
              find the median of the entire matrix.
              Asked at: Amazon, Google, Flipkart

  ★[C][ ] (M) Given vector<vector<int>>, find the number of islands (connected 1s).
              Use DFS/BFS on the 2D vector. O(M*N).
              Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  ★[C][ ] (M) Implement Pascal's Triangle as vector<vector<int>>.
              Generate N rows.
              Asked at: TCS, Amazon, Microsoft

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
4A. ADVANCED VECTOR PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (H) Implement a generic priority queue that supports:
             push(), pop(), top(), update_priority(element, new_priority)
             (decrease-key operation — needed for Dijkstra's algorithm)
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Implement a copy-on-write vector from scratch:
             Shared pointer to internal buffer;
             copy triggered on any non-const access.
             Asked at: Dolat Capital, Adobe, Persistent

  ★[C][ ] (H) Given vector<int>, find the largest rectangle area in a histogram.
              Use monotonic stack — O(N).
              Asked at: Amazon, Google, Microsoft, Adobe, Goldman Sachs

  ★[C][ ] (H) Given vector<int>, find the number of inversions.
              (i < j but arr[i] > arr[j]) — use modified merge sort O(N log N).
              Asked at: Amazon, Google, Goldman Sachs, Microsoft

  ★[C][ ] (H) Given vector<int>, find length of Longest Increasing Subsequence (LIS).
              O(N log N) using binary search + patience sorting.
              Asked at: Amazon, Microsoft, Google, Goldman Sachs

  ★[C][ ] (H) Given vector<int> prices for N days, find max profit with
              at most K transactions (buy-sell K times). DP solution.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Given vector<int>, find the subarray with maximum product.
              Handle negatives and zeros carefully. O(N).
              Asked at: Amazon, Microsoft, Google, Adobe

  ★[C][ ] (H) Given vector<int> of arrival and departure times of trains,
              find the minimum number of platforms required at a station.
              Sort + two-pointer approach.
              Asked at: Amazon, Flipkart, Paytm, Goldman Sachs

  ★[C][ ] (H) Merge K sorted vectors into one sorted vector.
              Use min-heap (priority_queue) — O(N log K).
              Asked at: Amazon, Google, Microsoft, Goldman Sachs

  ★[C][ ] (H) Given vector<int>, find all subarrays with sum divisible by K.
              Use prefix sum + modulo + hashmap — O(N).
              Asked at: Amazon, Google, Goldman Sachs

--------------------------------------------------------------------------------
4B. IMPLEMENT VECTOR FROM SCRATCH
--------------------------------------------------------------------------------

  ★[C][ ] (H) Implement a simplified version of std::vector<T> from scratch:
              Support: push_back, pop_back, operator[], size(), capacity(),
              resize(), reserve(), begin(), end(), clear()
              Handle reallocation with 2x growth strategy.
              Use templates.
              Asked at: Google, Microsoft, Amazon, Adobe (classic interview!)

================================================================================
SECTION 5 — DESIGN / SYSTEM QUESTIONS USING VECTOR
================================================================================

  ★[C][ ] (M) Design a circular buffer (ring buffer) using a vector<T>:
              push(x), pop(), front(), isFull(), isEmpty()
              Fixed capacity. Overwrite oldest when full.
              Asked at: Dolat Capital, HFT firms, Sasken, Samsung

  ★[C][ ] (M) Design a dynamic leaderboard using vector<pair<string,int>>:
              addScore(name, score), getTopK(K), getRank(name)
              Keep sorted at all times using insertion into sorted position or re-sort.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Implement a sparse matrix using vector<vector<pair<int,int>>>:
              Each row is a vector of (col, value) pairs for non-zero entries.
              Support: set(r, c, v), get(r, c), multiply(other matrix).
              Asked at: Google, Atlassian, Adobe

================================================================================
SECTION 6 — QUICK-FIRE VECTOR TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output?
          vector<int> v = {1, 2, 3};
          auto it = v.begin();
          v.push_back(4);
          cout << *it;
          (Undefined behavior — iterator invalidated by push_back if reallocation)
          Asked at: Amazon, Microsoft, Adobe

  ★[T][ ] What is the output?
          vector<int> v(5, 0);
          v.resize(3);
          cout << v.size() << " " << v.capacity();
          (size = 3, capacity = 5 — resize down doesn't free memory)
          Asked at: Persistent, Nagarro, L&T Infotech

  ★[T][ ] What is the output?
          vector<int> v;
          v.reserve(100);
          cout << v.size() << " " << v.capacity();
          (size = 0, capacity = 100)
          Asked at: TCS, Wipro, Zoho, Amazon

  ★[T][ ] Why does this cause undefined behavior?
          vector<int> v = {1, 2, 3};
          for (auto it = v.begin(); it != v.end(); ++it)
              if (*it == 2) v.erase(it);
          (Erasing invalidates iterator — use: it = v.erase(it) and skip ++it)
          Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] What is the difference between these two?
          vector<int> v1(10);       // 10 default-initialized (0) elements
          vector<int> v2;
          v2.reserve(10);           // 0 elements, capacity 10
          Asked at: TCS, Wipro, Amazon, Zoho

================================================================================
SUMMARY COUNT
================================================================================

  Category                                     | E  | M  | H  | Total
  ---------------------------------------------|----|----|----|---------
  Theory — Vector Internals & Memory           | 14 |  0 |  0 |    14
  Theory — Operations & STL Algorithms         |  9 |  0 |  0 |     9
  Coding Easy — Basic Operations               | 15 |  0 |  0 |    15
  Coding Easy — Searching & Sorting            |  4 |  0 |  0 |     4
  Coding Medium — Two Pointers / Window        |  0 |  8 |  0 |     8
  Coding Medium — Rearranging & Transform      |  0 | 11 |  0 |    11
  Coding Medium — STL Algorithms               |  0 |  6 |  0 |     6
  Coding Medium — 2D Vector / Matrix           |  0 |  5 |  0 |     5
  Coding Hard — Advanced Problems              |  0 |  0 | 11 |    11
  Coding Hard — Implement Vector from Scratch  |  0 |  0 |  1 |     1
  Design / System using Vector                 |  0 |  3 |  0 |     3
  Tricky Output / Concept Questions            |  5 |  0 |  0 |     5
  ---------------------------------------------|----|----|----|---------
  TOTAL                                        | 47 | 33 | 13 |    93

  ★ = 52 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    → Basic vector ops (max/min/sum/reverse/sort), size vs capacity,
      at() vs [], erase-remove idiom, remove duplicates

  ZOHO:
    → lower_bound/upper_bound, sort with custom comparator,
      two sum, iterator invalidation traps

  AMAZON / FLIPKART / PAYTM:
    → Kadane's, sliding window max, two sum, rotate array,
      product except self, trapping rain water, stock buy-sell,
      merge sorted vectors, Kth largest

  MICROSOFT / ADOBE:
    → Dutch national flag, matrix rotation/spiral, flatten 2D,
      next permutation, stable_sort, transform, partial_sort

  GOOGLE / ATLASSIAN:
    → LIS, inversions, largest rectangle in histogram,
      number of islands, merge K sorted, implement vector from scratch

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Max product subarray, K transactions profit, circular buffer,
      copy-on-write vector, update_priority heap, inversions count,
      iterator invalidation traps, emplace_back vs push_back

================================================================================
END
================================================================================
