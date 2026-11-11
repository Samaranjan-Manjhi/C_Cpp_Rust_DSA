================================================================================
        STL — MULTISET (std::multiset) COMPLETE QUESTION BANK
        Covers: std::multiset internals + classic multiset algorithm problems
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
1A. std::multiset INTERNALS & MEMORY
--------------------------------------------------------------------------------

  [T][ ] What is std::multiset in C++? How does it differ from std::set?
         (multiset: sorted, allows duplicate elements;
          set: sorted, unique elements only)
         Asked at: TCS, Wipro, Amazon, Zoho, Infosys

  [T][ ] What is the underlying data structure of std::multiset?
         (Red-Black Tree — same as std::set, but duplicates are stored as
          separate nodes rather than ignored)
         Asked at: Amazon, Microsoft, Persistent, Nagarro

  [T][ ] What is the time complexity of insert, find, erase, and count in std::multiset?
         (insert: O(log N); find: O(log N); count: O(log N + count);
          erase(val): O(log N + count); erase(iter): O(1) amortized)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What does std::multiset::count(x) return?
         (Number of elements equal to x — can be 0 or more)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What is the difference between multiset::erase(value) and multiset::erase(iterator)?
         (erase(value): removes ALL occurrences of value — O(log N + k) where k = count;
          erase(iterator): removes ONLY that single element — O(log N);
          THIS IS A CRITICAL DISTINCTION — very common interview trap!)
         Asked at: Amazon, Microsoft, Adobe, Persistent, Flipkart
         (Most tricky multiset question — know this cold!)

  [T][ ] What is equal_range on std::multiset?
         (Returns pair<iterator, iterator> = (lower_bound, upper_bound);
          iterates over all elements equal to x — O(log N + count))
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] Are iterators of std::multiset invalidated on insert or erase?
         (Only the erased element's iterator is invalidated;
          all other iterators remain valid)
         Asked at: Amazon, Adobe, Persistent

  [T][ ] What is the difference between std::multiset and std::priority_queue?
         (multiset: ordered, supports both ends (min + max), O(log N) all ops,
          allows erase by value/iter, iterable;
          priority_queue: only top accessible, O(log N) push/pop, not iterable,
          simpler interface but faster in practice due to cache-friendly vector)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] When would you use std::multiset over std::priority_queue?
         (When you need: both min AND max simultaneously, erase arbitrary element,
          iterate over all elements, lower_bound/upper_bound queries)
         Asked at: Amazon, Microsoft, Goldman Sachs

  [T][ ] What is the difference between std::multiset and std::multimap?
         (multiset: stores only keys sorted;
          multimap: stores key-value pairs sorted by key, allows duplicate keys)
         Asked at: TCS, Wipro, Persistent, Nagarro

  ★[T][ ] What is the difference between std::multiset and std::vector + std::sort?
          (multiset: maintains sorted order dynamically on every insert/erase O(log N);
           vector+sort: O(N log N) to resort after each insert — inefficient for streams)
          Asked at: Amazon, Zoho, Goldman Sachs

  ★[T][ ] How does std::multiset handle the comparator for duplicate elements?
          (Default: strict weak ordering with <;
           elements a and b are equivalent if !(a<b) && !(b<a))
          Asked at: Persistent, Nagarro, advanced C++ roles

  ★[T][ ] Can you use std::multiset as a sorted sliding window? What is the time complexity?
          (Yes — insert O(log N), erase by iterator O(log N), min = *begin(), max = *rbegin();
           total: O(N log K) for a window of size K over N elements)
          Asked at: Amazon, Microsoft, Goldman Sachs

  ★[T][ ] What is the difference between multiset::find() and multiset::lower_bound()?
          (find(x): returns iterator to ANY element equal to x — O(log N);
           lower_bound(x): returns iterator to FIRST element >= x — O(log N);
           for multisets: find() may return any one of the duplicates)
          Asked at: Amazon, Persistent, Nagarro

--------------------------------------------------------------------------------
1B. CRITICAL PITFALLS & COMMON BUGS
--------------------------------------------------------------------------------

  ★[T][ ] What is the most common bug when using multiset::erase()?
          multiset<int> ms = {1, 2, 2, 3};
          ms.erase(2);  // BUG: removes ALL 2s, not just one!
          // Fix: ms.erase(ms.find(2));  // removes only one 2
          Asked at: Amazon, Microsoft, Adobe, Flipkart, Persistent
          (Most important multiset interview trap — asked everywhere!)

  ★[T][ ] How do you safely remove only ONE occurrence of a value from multiset?
          (Use: ms.erase(ms.find(val)); — finds one iterator, erases only that node)
          Asked at: Amazon, Microsoft, Adobe, Flipkart

  ★[T][ ] Why does multiset::count(x) take O(log N + k) time?
          (First: binary search to find first x — O(log N);
           then: traverse all k copies — O(k))
          Asked at: Persistent, Nagarro, Goldman Sachs

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. std::multiset BASIC USAGE
--------------------------------------------------------------------------------

  ★[C][ ] (E) Demonstrate insert, find, count, erase(value), erase(iterator)
              on std::multiset<int>. Show the critical difference between the two erases.
              Asked at: TCS, Wipro, Amazon, Persistent

  ★[C][ ] (E) Insert a sequence of integers (with duplicates) into a multiset.
              Iterate forward and backward. Show sorted order is always maintained.
              Asked at: TCS, Wipro, Zoho, Infosys

  ★[C][ ] (E) Given multiset<int>, safely remove exactly ONE occurrence of value X.
              Handle the case where X does not exist.
              (Use find first, check != end(), then erase iterator)
              Asked at: Amazon, Flipkart, TCS, Wipro

  ★[C][ ] (E) Use equal_range on multiset to find all occurrences of value X.
              Print all of them and count using std::distance.
              Asked at: Amazon, Persistent, Nagarro

  ★[C][ ] (E) Find the minimum and maximum elements in a multiset in O(1).
              (*ms.begin() and *ms.rbegin())
              Asked at: TCS, Wipro, Amazon, Goldman Sachs

  ★[C][ ] (E) Use lower_bound and upper_bound on a multiset to count elements
              in range [L, R]. Use std::distance (note: O(N) for multiset).
              Discuss how to make it O(log N) using order statistics tree.
              Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (E) Demonstrate that multiset allows duplicate elements while set does not.
              Insert same element 5 times into both; show size difference.
              Asked at: TCS, Wipro, Infosys, Zoho

  ★[C][ ] (E) Convert a multiset<int> to a vector<int> (preserves sorted + duplicates).
              Then convert back.
              Asked at: TCS, Wipro, Persistent

--------------------------------------------------------------------------------
2B. CLASSIC EASY PROBLEMS USING MULTISET
--------------------------------------------------------------------------------

  ★[C][ ] (E) Given array of integers, find the frequency of each element.
              Use multiset: iterate with equal_range, count, and move to next group.
              Asked at: TCS, Wipro, Amazon, Zoho

  ★[C][ ] (E) Sort an array (with duplicates) using std::multiset.
              Insert all elements; iterate multiset to get sorted output.
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Find the median of an unsorted array using multiset.
              Insert all elements; use iterator to reach middle position.
              (O(N log N) insert + O(N) to find median — discuss better approach)
              Asked at: TCS, Amazon, Goldman Sachs

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. SLIDING WINDOW WITH MULTISET (Most Asked Pattern!)
--------------------------------------------------------------------------------

  ★[C][ ] (M) Sliding window maximum and minimum simultaneously:
              For each window of size K, find both max (*rbegin()) and min (*begin()).
              Use multiset as sorted window — O(N log K).
              Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (M) Sliding window median — find median of every window of size K.
              Use multiset as sorted window; find middle iterator.
              (Two multiset approach: lower half max-multiset, upper half min-multiset)
              O(N log K).
              Asked at: Amazon, Google, Microsoft — LeetCode 480
              (Very commonly asked!)

  ★[C][ ] (M) Find all windows of size K where max - min <= T.
              Use multiset: max = *rbegin(), min = *begin() — O(N log K).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Minimum absolute difference between any two elements in a sliding window.
              Maintain sorted window with multiset;
              for each new element, check its neighbors in multiset.
              O(N log K).
              Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Given array, for each index i find the nearest previously seen element
              smaller than arr[i] and the nearest larger.
              Use multiset: lower_bound gives first >= x; decrement for < x.
              O(N log N).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Longest subarray with max - min <= K.
              Expand right, add to multiset; if max-min > K, shrink left, erase from multiset.
              O(N log N).
              Asked at: Amazon, Google, Goldman Sachs — LeetCode 2401 variant

  ★[C][ ] (M) Count number of subarrays of length K with at least one duplicate.
              Sliding window with multiset — check if any count >= 2.
              O(N log K).
              Asked at: Amazon, Microsoft

--------------------------------------------------------------------------------
3B. TWO-MULTISET / HEAP SIMULATION PROBLEMS
--------------------------------------------------------------------------------

  ★[C][ ] (M) Find running median from a data stream using TWO multisets
              (instead of two priority_queues).
              Lower half: maxMultiset; upper half: minMultiset.
              Advantage over two heaps: can erase arbitrary elements — O(log N) per op.
              Asked at: Amazon, Google, Microsoft, Goldman Sachs

  ★[C][ ] (M) Design a sliding window median with DELETIONS.
              Unlike priority_queue, multiset supports O(log N) erase by iterator.
              Insert new element, erase outgoing element, rebalance two multisets.
              O(N log K) — strictly better than heap + lazy deletion.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Maintain K largest elements with O(log N) insert and O(log N) delete.
              Use min-multiset of size K: if new element > min, insert and erase min.
              (Unlike priority_queue, deletion of specific element is O(log N))
              Asked at: Amazon, Microsoft, Goldman Sachs

  ★[C][ ] (M) Given a sequence of insert and delete operations on a number stream,
              after each operation output the current median.
              Use two multisets for lower/upper halves — O(log N) per operation.
              Asked at: Goldman Sachs, Dolat Capital

--------------------------------------------------------------------------------
3C. SORTING & COUNTING PROBLEMS
--------------------------------------------------------------------------------

  ★[C][ ] (M) Count inversions using multiset:
              For each element x, count elements already inserted that are > x.
              Use multiset::distance from upper_bound to end — but this is O(N) per query.
              Discuss: use policy-based tree for O(log N) rank queries.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Check if array B is a subsequence (by value) of array A:
              Insert all of A into multiset; for each element of B,
              find it in multiset and erase one occurrence — O(N log N).
              Asked at: Amazon, Flipkart

  ★[C][ ] (M) Find the K-th smallest sum of pairs (arr1[i] + arr2[j]).
              Use multiset with BFS-like expansion — O(K log K).
              Asked at: Google, Goldman Sachs

  ★[C][ ] (M) Given list of tasks with processing times, find the minimum time
              to finish all tasks if you can run K tasks at a time.
              Use multiset to always schedule K shortest tasks.
              Asked at: Amazon, Goldman Sachs

--------------------------------------------------------------------------------
3D. DESIGN PROBLEMS USING MULTISET
--------------------------------------------------------------------------------

  ★[C][ ] (M) Design a data structure for a stock exchange order book:
              buyOrders: max-multiset of buy prices;
              sellOrders: min-multiset of sell prices.
              match(): execute if max buy >= min sell.
              Asked at: Goldman Sachs, Dolat Capital, ICICI Securities

  ★[C][ ] (M) Design a leaderboard with duplicate scores:
              addScore(playerId, score), getTopK(K), removePlayer(playerId).
              Use multiset<pair<int,int>> (score, playerId) with rbegin() for top scores.
              O(log N) per operation.
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Design a scheduler that always executes the job with minimum remaining time.
              Jobs can be added dynamically.
              Use multiset<pair<int,int>> (remainingTime, jobId).
              Asked at: Amazon, Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Implement a priority-based waiting queue where multiple customers
              can have the same priority (FIFO within same priority).
              Use multiset<pair<int,int>> (priority, arrivalTime).
              Asked at: Amazon, Zoho, Adobe

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  ★[C][ ] (H) Sliding window median — full implementation with two multisets:
              Lower half: descending multiset (max at rbegin);
              Upper half: ascending multiset (min at begin).
              Keep sizes balanced within 1. Handle even and odd K.
              O(N log K).
              Asked at: Amazon, Google, Goldman Sachs — LeetCode 480

  ★[C][ ] (H) Given N tasks with arrival time and processing time (preemptive scheduling),
              simulate Shortest Remaining Time First (SRTF) using multiset.
              On each arrival, add to multiset; on completion remove.
              O(N log N).
              Asked at: Goldman Sachs, Dolat Capital, OS interview rounds

  ★[C][ ] (H) Given an array, for each element find the count of elements
              smaller than it and count of elements greater than it
              among all previously seen elements — O(N log N).
              Use multiset + std::distance (discuss why pbds is better).
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Design an online stock trading system:
              Prices arrive in a stream. At any time support:
              getMedianPrice() — O(log N)
              addPrice(x) — O(log N)
              removePrice(x) — O(log N)  [this is why multiset beats heap!]
              Use two multisets for median tracking.
              Asked at: Goldman Sachs, Dolat Capital, ICICI Securities

  ★[C][ ] (H) Minimum number of arrows to burst all balloons (sorted intervals).
              Sort by end; use multiset to track current coverage — O(N log N).
              Asked at: Amazon, Google — LeetCode 452

  ★[C][ ] (H) Given K lists of sorted integers, find the minimum range [L, R]
              such that there is at least one integer from each list.
              Use multiset of (current_element, list_index) + track global max.
              O(N log K).
              Asked at: Google, Goldman Sachs — LeetCode 632

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output?
          multiset<int> ms = {3, 1, 4, 1, 5, 9, 2, 6, 5};
          for (auto x : ms) cout << x << " ";
          (Output: 1 1 2 3 4 5 5 6 9 — sorted order, duplicates preserved)
          Asked at: TCS, Wipro, Zoho, Amazon

  ★[T][ ] What is the output and why? (Classic interview trap!)
          multiset<int> ms = {2, 2, 2, 3};
          ms.erase(2);   // removes ALL 2s!
          cout << ms.size();
          (Output: 1 — only {3} remains; erase(value) removes all occurrences)
          // Correct fix: ms.erase(ms.find(2));
          Asked at: Amazon, Microsoft, Adobe, Flipkart, Persistent

  ★[T][ ] What is the output?
          multiset<int> ms = {1, 2, 2, 3, 4};
          auto range = ms.equal_range(2);
          cout << std::distance(range.first, range.second);
          (Output: 2 — there are two 2s; equal_range gives both bounds)
          Asked at: Amazon, Persistent, Nagarro

  ★[T][ ] What is the difference in output?
          multiset<int> ms = {5, 3, 1, 4, 2};
          cout << *ms.begin() << " " << *ms.rbegin();
          (Output: 1 5 — multiset auto-sorts; begin() = min, rbegin() = max)
          Asked at: TCS, Wipro, Amazon, Goldman Sachs

  ★[T][ ] What is wrong with this sliding window code?
          multiset<int> window;
          for (int i = 0; i < n; i++) {
              window.insert(arr[i]);
              if (i >= k) window.erase(arr[i-k]);  // BUG if duplicates!
              // Fix: window.erase(window.find(arr[i-k]));
          }
          (erase(value) removes ALL occurrences of arr[i-k], not just one!)
          Asked at: Amazon, Google, Goldman Sachs — very common sliding window bug!

  ★[T][ ] Multiset vs priority_queue — when to use which?
          multiset:  need erase by value ✓ | need min AND max ✓ | need iteration ✓
          pq:        faster in practice ✓  | simpler push/pop ✓ | only top access ✓
          Asked at: Amazon, Microsoft, Goldman Sachs, Dolat Capital

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — std::multiset Internals & Memory     | 14 |  0 |  0 |    14
  Theory — Critical Pitfalls & Bugs             |  3 |  0 |  0 |     3
  Coding Easy — std::multiset Basic Usage       |  8 |  0 |  0 |     8
  Coding Easy — Classic Problems                |  3 |  0 |  0 |     3
  Coding Medium — Sliding Window                |  0 |  7 |  0 |     7
  Coding Medium — Two-Multiset / Heap Sim       |  0 |  4 |  0 |     4
  Coding Medium — Sorting & Counting            |  0 |  4 |  0 |     4
  Coding Medium — Design Problems               |  0 |  4 |  0 |     4
  Coding Hard                                   |  0 |  0 |  6 |     6
  Tricky Output / Concept Questions             |  6 |  0 |  0 |     6
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 34 | 19 |  6 |    59

  ★ = 59 questions added from real interviews not in source files
  (All questions are ★ — multiset was not covered in source files)

================================================================================
GOLDEN RULE — MUST MEMORISE FOR INTERVIEWS
================================================================================

  ALWAYS use:    ms.erase(ms.find(val))   → removes ONE occurrence   ✓
  NEVER use:     ms.erase(val)            → removes ALL occurrences  ✗ (unless intended)

  MULTISET vs PRIORITY_QUEUE — decision table:
  ┌─────────────────────────────┬──────────┬───────────────┐
  │ Operation                   │ multiset │ priority_queue│
  ├─────────────────────────────┼──────────┼───────────────┤
  │ Insert                      │ O(log N) │ O(log N)      │
  │ Get min / max               │ O(1)     │ O(1)          │
  │ Get BOTH min AND max        │ O(1) ✓   │ Need 2 PQs    │
  │ Erase specific element      │ O(log N) │ Not supported │
  │ Iterate all elements        │ O(N) ✓   │ Not supported │
  │ lower_bound / upper_bound   │ O(log N) │ Not supported │
  │ Cache performance           │ Poor     │ Good (vector) │
  └─────────────────────────────┴──────────┴───────────────┘

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI:
    → multiset vs set, allow duplicates, sorted order, count(x),
      erase pitfall (all vs one), iteration, frequency counting

  ZOHO:
    → Median of array using multiset, priority queue with duplicates,
      FIFO within same priority using multiset<pair<int,int>>

  AMAZON / FLIPKART:
    → Sliding window median (two multisets), erase by iterator bug,
      sliding window min+max, K largest with deletions, longest subarray max-min <= K

  MICROSOFT / ADOBE:
    → Sliding window with deletions (why multiset beats heap),
      find nearest smaller/larger with multiset, count subarrays with duplicate

  GOOGLE / ATLASSIAN:
    → Minimum range from K lists, K-th smallest pair sum,
      inversions counting (multiset + pbds), sliding window median hard variant

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Order book design (buy/sell multisets), running median with deletions,
      SRTF scheduling, online trading system, multiset vs pq decision matrix,
      memory overhead of Red-Black Tree nodes

================================================================================
END
================================================================================
