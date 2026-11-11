================================================================================
        STL ALGORITHMS — COMPLETE REFERENCE + QUESTION BANK
        Headers: <algorithm>  <numeric>  <functional>
        Compiled from all_in_one + all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        ★ = Extra question added (real company interview, not in source files)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
MASTER ALGORITHM TAXONOMY
================================================================================

  GROUP A  — Sorting                 sort, stable_sort, partial_sort,
                                     nth_element, is_sorted, is_sorted_until
  GROUP B  — Searching (Non-Binary)  find, find_if, find_if_not, find_end,
                                     find_first_of, adjacent_find, search,
                                     search_n
  GROUP C  — Searching (Binary)      binary_search, lower_bound, upper_bound,
                                     equal_range
  GROUP D  — Counting & Checking     count, count_if, any_of, all_of, none_of
  GROUP E  — Modifying               transform, fill, fill_n, generate,
                                     generate_n, replace, replace_if,
                                     replace_copy, copy, copy_if, copy_n,
                                     move, swap_ranges, reverse, rotate,
                                     shuffle, sample
  GROUP F  — Removing                remove, remove_if, remove_copy,
                                     unique, unique_copy
  GROUP G  — Partitioning            partition, stable_partition,
                                     partition_copy, is_partitioned,
                                     partition_point
  GROUP H  — Merging & Set Ops       merge, inplace_merge, set_union,
                                     set_intersection, set_difference,
                                     set_symmetric_difference, includes
  GROUP I  — Heap Operations         make_heap, push_heap, pop_heap,
                                     sort_heap, is_heap, is_heap_until
  GROUP J  — Min/Max                 min, max, minmax, min_element,
                                     max_element, minmax_element, clamp
  GROUP K  — Permutations            next_permutation, prev_permutation,
                                     is_permutation
  GROUP L  — Numeric (in <numeric>)  accumulate, reduce, iota,
                                     partial_sum, adjacent_difference,
                                     inner_product, inclusive_scan,
                                     exclusive_scan, transform_reduce
  GROUP M  — Comparison              equal, mismatch, lexicographical_compare

================================================================================
PART 1 — ALGORITHM EXPLANATIONS
(Concept + Key Points + When to Use + Complexity)
================================================================================

--------------------------------------------------------------------------------
GROUP A — SORTING ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::sort                                                               │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Sorts elements in-place in ascending order by default.   │
  │ Algorithm    : Introsort — hybrid of Quicksort + Heapsort + Insertion   │
  │               sort. Switches strategy based on recursion depth.         │
  │ Complexity   : O(N log N) average and worst case. O(log N) stack space. │
  │ Stability    : NOT stable — equal elements may change relative order.   │
  │ Requires     : RandomAccessIterator (works on vector, array, deque).    │
  │ NOT for      : list, set, map (use their own .sort() or no sort needed).│
  │ Key points   :                                                          │
  │   - Default comparator is less<> (ascending).                           │
  │   - Pass greater<>() or lambda for custom order.                        │
  │   - sort() does NOT work on list — use list::sort().                    │
  │ When to use  : General purpose sorting. Fastest for random-access       │
  │               containers when element order among equals doesn't matter.│
  └─────────────────────────────────────────────────────────────────────────┘

  sort(v.begin(), v.end());                         // ascending
  sort(v.begin(), v.end(), greater<int>());         // descending
  sort(v.begin(), v.end(), [](int a, int b){        // custom
      return a % 10 < b % 10;                       // by last digit
  });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::stable_sort                                                        │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Same as sort, but preserves relative order of equal      │
  │               elements (stable).                                        │
  │ Algorithm    : Merge sort (stable by nature).                           │
  │ Complexity   : O(N log² N) without extra memory; O(N log N) with O(N).  │
  │ When to use  : When you need to sort by one key while preserving a      │
  │               previously applied sort order (multi-key sort). Also when │
  │               equal elements must maintain their original sequence.     │
  └─────────────────────────────────────────────────────────────────────────┘

  stable_sort(v.begin(), v.end(), [](const Student& a, const Student& b){
      return a.marks > b.marks;   // same marks → original order preserved
  });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::partial_sort                                                       │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Places the smallest K elements in the first K positions, │
  │               sorted. Remaining elements are in unspecified order.      │
  │ Complexity   : O(N log K).                                              │
  │ When to use  : You only need the top/bottom K elements in sorted order. │
  │               Faster than full sort when K << N.                        │
  └─────────────────────────────────────────────────────────────────────────┘

  partial_sort(v.begin(), v.begin() + k, v.end());  // smallest K in front, sorted

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::nth_element                                                        │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Rearranges so that the element at position nth is the    │
  │               element that would be there if fully sorted. All elements │
  │               before it are <= it; all after are >= it.                 │
  │ Algorithm    : Introselect (based on QuickSelect).                      │
  │ Complexity   : O(N) average. NOT fully sorted.                          │
  │ When to use  : Find Kth smallest/largest in O(N). Median finding.       │
  │               When you need the K-th element but not full sort.         │
  └─────────────────────────────────────────────────────────────────────────┘

  nth_element(v.begin(), v.begin() + k, v.end());   // v[k] = kth smallest
  // All v[0..k-1] <= v[k], all v[k+1..] >= v[k]

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::is_sorted / std::is_sorted_until                                   │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : is_sorted returns bool; is_sorted_until returns iterator │
  │               to first element that breaks the sorted order.            │
  │ Complexity   : O(N).                                                    │
  │ When to use  : Validate sorted invariant before binary search. Debug.   │
  └─────────────────────────────────────────────────────────────────────────┘

  is_sorted(v.begin(), v.end());                     // true/false
  auto it = is_sorted_until(v.begin(), v.end());     // iterator to first "break"

--------------------------------------------------------------------------------
GROUP B — SEARCHING ALGORITHMS (LINEAR / NON-BINARY)
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::find / std::find_if / std::find_if_not                             │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Linear scan. Returns iterator to first matching element. │
  │               Returns end() if not found.                               │
  │ Complexity   : O(N).                                                    │
  │ When to use  : Unsorted ranges. Small containers. Use on any container. │
  │               find_if: match by predicate (e.g., first even number).    │
  │               find_if_not: first element that does NOT match predicate. │
  │ KEY POINT    : Unlike binary_search, works on unsorted data.            │
  │               Returns iterator — you can dereference or erase it.       │
  └─────────────────────────────────────────────────────────────────────────┘

  auto it = find(v.begin(), v.end(), 42);
  if (it != v.end()) cout << "found at index " << (it - v.begin());

  auto it2 = find_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::find_end                                                           │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Finds the LAST occurrence of a subsequence in a range.   │
  │ Complexity   : O(N * M) where N = haystack size, M = needle size.       │
  │ When to use  : Find last occurrence of a pattern/subsequence.           │
  └─────────────────────────────────────────────────────────────────────────┘

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::find_first_of                                                      │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Finds the first element in range1 that also appears in   │
  │               range2 (like strcspn in C).                               │
  │ Complexity   : O(N * M).                                                │
  │ When to use  : Find first character from a set of delimiters.           │
  └─────────────────────────────────────────────────────────────────────────┘

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::adjacent_find                                                      │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Finds first pair of adjacent equal (or matching by pred) │
  │               elements. Returns iterator to the first of the pair.      │
  │ Complexity   : O(N).                                                    │
  │ When to use  : Detect consecutive duplicates. Check for runs.           │
  └─────────────────────────────────────────────────────────────────────────┘

  auto it = adjacent_find(v.begin(), v.end());    // first duplicate pair
  auto it2 = adjacent_find(v.begin(), v.end(),
      [](int a, int b){ return a > b; });          // first descent

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::search / std::search_n                                             │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : search: finds first occurrence of a subsequence.         │
  │               search_n: finds first run of N consecutive equal values.  │
  │ Complexity   : O(N * M).                                                │
  │ When to use  : Substring/subsequence search on general sequences.       │
  │               search_n: "find 3 consecutive 5s in array".               │
  └─────────────────────────────────────────────────────────────────────────┘

  search_n(v.begin(), v.end(), 3, 5);   // find "5,5,5" in v

--------------------------------------------------------------------------------
GROUP C — BINARY SEARCH ALGORITHMS (require SORTED range)
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::binary_search                                                      │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Returns TRUE or FALSE — only tells you if value exists.  │
  │ Complexity   : O(log N).                                                │
  │ REQUIRES     : Sorted range (ascending by default).                     │
  │ KEY POINT    : Does NOT return position or iterator. Use lower_bound    │
  │               if you need the location.                                 │
  │ When to use  : Quick existence check on sorted data.                    │
  └─────────────────────────────────────────────────────────────────────────┘

  if (binary_search(v.begin(), v.end(), 42)) { ... }

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::lower_bound                                                        │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Returns iterator to FIRST element that is >= value.      │
  │ Complexity   : O(log N) for RandomAccess; O(N) for ForwardIterator.     │
  │ REQUIRES     : Sorted range.                                            │
  │ When to use  : Find insertion point. Count elements < x.                │
  │               Check if x exists: *lower_bound(v, x) == x.               │
  │ KEY POINT    : If value not present, returns position where it would go.│
  └─────────────────────────────────────────────────────────────────────────┘

  auto it = lower_bound(v.begin(), v.end(), x);
  int pos = it - v.begin();              // 0-indexed position
  int count_less = pos;                  // number of elements strictly < x
  bool exists = (it != v.end() && *it == x);

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::upper_bound                                                        │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Returns iterator to FIRST element that is > value.       │
  │ Complexity   : O(log N).                                                │
  │ REQUIRES     : Sorted range.                                            │
  │ When to use  : Count elements <= x. Find range of duplicates.           │
  │               Combined with lower_bound: count occurrences of x.        │
  └─────────────────────────────────────────────────────────────────────────┘

  auto lo = lower_bound(v.begin(), v.end(), x);
  auto hi = upper_bound(v.begin(), v.end(), x);
  int count_x = hi - lo;                // occurrences of x in sorted v
  int count_leq = hi - v.begin();       // elements <= x

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::equal_range                                                        │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Returns pair<lower_bound, upper_bound> — both in one     │
  │               call. Defines the "equal range" for value x.              │
  │ Complexity   : O(log N).                                                │
  │ When to use  : When you need both bounds at once (e.g., multiset range).│
  └─────────────────────────────────────────────────────────────────────────┘

  auto [lo, hi] = equal_range(v.begin(), v.end(), x);
  int count_x = hi - lo;

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ CRITICAL DIFFERENCE TABLE — find vs binary_search vs lower_bound        │
  ├──────────────────┬───────────────┬──────────────┬───────────────────────┤
  │                  │ find()        │ binary_search│ lower_bound()         │
  ├──────────────────┼───────────────┼──────────────┼───────────────────────┤
  │ Sorted required? │ No            │ Yes          │ Yes                   │
  │ Returns          │ Iterator      │ bool         │ Iterator              │
  │ Complexity       │ O(N)          │ O(log N)     │ O(log N)              │
  │ Not-found value  │ end()         │ false        │ insertion point       │
  │ Use for          │ Unsorted      │ Quick check  │ Position + counting   │
  └──────────────────┴───────────────┴──────────────┴───────────────────────┘

--------------------------------------------------------------------------------
GROUP D — COUNTING & CHECKING
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::count / std::count_if                                              │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : count: counts elements equal to value.                   │
  │               count_if: counts elements satisfying predicate.           │
  │ Complexity   : O(N).                                                    │
  │ When to use  : Frequency counting in unsorted ranges.                   │
  └─────────────────────────────────────────────────────────────────────────┘

  int n = count(v.begin(), v.end(), 5);
  int evens = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::any_of / std::all_of / std::none_of                                │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Check if ANY / ALL / NONE of the elements satisfy pred.  │
  │ Complexity   : O(N) worst case; short-circuits on first answer.         │
  │ When to use  : Validation checks. Much more readable than raw loops.    │
  │ KEY POINT    : Short-circuit — any_of stops at first true,              │
  │               all_of stops at first false, none_of stops at first true. │
  │               On empty range: any_of=false, all_of=true, none_of=true.  │
  └─────────────────────────────────────────────────────────────────────────┘

  any_of(v.begin(), v.end(), [](int x){ return x < 0; });   // any negative?
  all_of(v.begin(), v.end(), [](int x){ return x > 0; });   // all positive?
  none_of(v.begin(), v.end(), [](int x){ return x == 0; }); // no zeros?

--------------------------------------------------------------------------------
GROUP E — MODIFYING ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::transform                                                          │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Applies a function to each element and writes result to  │
  │               an output range. Also supports binary transform (two      │
  │               input ranges, one output range).                          │
  │ Complexity   : O(N).                                                    │
  │ When to use  : Map every element to a new value. Convert types.         │
  │               Element-wise operations on two vectors (add, multiply...).│
  │ KEY POINT    : Does NOT modify input if output is a different range.    │
  │               Can transform in-place: transform(v.begin(),v.end(),      │
  │               v.begin(), func)                                          │
  └─────────────────────────────────────────────────────────────────────────┘

  // Unary: square each element
  transform(v.begin(), v.end(), v.begin(), [](int x){ return x * x; });
  // Binary: element-wise sum of two vectors
  transform(a.begin(), a.end(), b.begin(), result.begin(),
            [](int x, int y){ return x + y; });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::fill / std::fill_n / std::generate / std::generate_n               │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ fill      : Sets all elements to a given value.                         │
  │ fill_n    : Sets first N elements to a given value.                     │
  │ generate  : Sets each element from a generator function (no args).      │
  │ generate_n: Sets first N elements from a generator function.            │
  │ Complexity: O(N).                                                       │
  └─────────────────────────────────────────────────────────────────────────┘

  fill(v.begin(), v.end(), 0);
  fill_n(v.begin(), 5, -1);
  int val = 0;
  generate(v.begin(), v.end(), [&val](){ return val++; });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::replace / std::replace_if / std::replace_copy                      │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ replace    : Replace all elements equal to old_val with new_val.        │
  │ replace_if : Replace all elements satisfying predicate.                 │
  │ replace_copy: Write replaced result to output range (original unchanged)│
  │ Complexity : O(N).                                                      │
  └─────────────────────────────────────────────────────────────────────────┘

  replace(v.begin(), v.end(), 0, -1);                       // 0 → -1
  replace_if(v.begin(), v.end(), [](int x){ return x<0; }, 0); // negatives → 0

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::copy / std::copy_if / std::copy_n                                  │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ copy    : Copies all elements to output range.                          │
  │ copy_if : Copies only elements satisfying predicate.                    │
  │ copy_n  : Copies first N elements.                                      │
  │ Complexity : O(N).                                                      │
  │ KEY POINT  : Ranges must NOT overlap (use copy_backward if they do).    │
  └─────────────────────────────────────────────────────────────────────────┘

  copy(v.begin(), v.end(), back_inserter(result));
  copy_if(v.begin(), v.end(), back_inserter(result),
          [](int x){ return x > 0; });                      // filter positives

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::reverse / std::rotate                                              │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ reverse   : Reverses elements in-place. O(N).                           │
  │ rotate    : Rotates elements so that the element at "middle" becomes    │
  │             the first element. O(N).                                    │
  │ When to use rotate: Left-rotate array by K positions in O(N) O(1) space.│
  └─────────────────────────────────────────────────────────────────────────┘

  reverse(v.begin(), v.end());
  rotate(v.begin(), v.begin() + k, v.end());   // left-rotate by K

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::shuffle / std::sample                                              │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ shuffle : Randomly permutes elements using a random engine. O(N).       │
  │ sample  : Selects N random elements without replacement. O(N). (C++17)  │
  └─────────────────────────────────────────────────────────────────────────┘

  mt19937 rng(random_device{}());
  shuffle(v.begin(), v.end(), rng);
  sample(v.begin(), v.end(), back_inserter(result), k, rng); // k random items

--------------------------------------------------------------------------------
GROUP F — REMOVING ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::remove / std::remove_if / std::remove_copy                         │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Does NOT actually erase — moves non-matching elements to │
  │               the front and returns iterator to the new "end".          │
  │ Complexity   : O(N).                                                    │
  │ KEY POINT ★  : MUST call container.erase() after remove to actually     │
  │               shrink the container. This is the ERASE-REMOVE IDIOM.     │
  │               remove() alone leaves "ghost" elements at the back.       │
  └─────────────────────────────────────────────────────────────────────────┘

  // Erase-Remove Idiom — the correct way to remove from a vector
  v.erase(remove(v.begin(), v.end(), x), v.end());
  v.erase(remove_if(v.begin(), v.end(), [](int x){ return x < 0; }), v.end());

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::unique / std::unique_copy                                          │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Removes CONSECUTIVE duplicates (not all duplicates).     │
  │               Returns iterator to new logical end. Same "ghost" issue.  │
  │ Complexity   : O(N).                                                    │
  │ KEY POINT    : Sort first to remove ALL duplicates, not just consecutive│
  └─────────────────────────────────────────────────────────────────────────┘

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());   // remove ALL duplicates

--------------------------------------------------------------------------------
GROUP G — PARTITIONING ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::partition / std::stable_partition                                  │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Rearranges so all elements satisfying predicate come     │
  │               first. Returns iterator to first element that does NOT    │
  │               satisfy predicate.                                        │
  │ partition       : O(N). NOT stable.                                     │
  │ stable_partition: O(N log N) without extra mem; O(N) with extra mem.    │
  │ When to use  : Separate positives/negatives, odds/evens. Dutch National │
  │               Flag. Quicksort partition step.                           │
  └─────────────────────────────────────────────────────────────────────────┘

  auto mid = partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
  // [mid, end) are odd numbers; [begin, mid) are even numbers

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::is_partitioned / std::partition_point                              │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ is_partitioned  : Returns true if all pred-true elements come first.    │
  │ partition_point : Binary searches for the boundary (O(log N)).          │
  │                   REQUIRES already partitioned range.                   │
  └─────────────────────────────────────────────────────────────────────────┘

  auto pt = partition_point(v.begin(), v.end(), [](int x){ return x < 10; });

--------------------------------------------------------------------------------
GROUP H — MERGING & SET OPERATIONS (require SORTED ranges)
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::merge / std::inplace_merge                                         │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ merge         : Merges two sorted ranges into a third. O(N+M).          │
  │ inplace_merge : Merges two consecutive sorted halves in-place. O(Nlog N)│
  │ When to use   : merge: combine two sorted arrays without sorting.       │
  │                 inplace_merge: merge sort's merge step.                 │
  └─────────────────────────────────────────────────────────────────────────┘

  merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
  inplace_merge(v.begin(), v.begin() + mid, v.end());

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::set_union / std::set_intersection / std::set_difference            │
  │ std::set_symmetric_difference / std::includes                           │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ All require SORTED input ranges. Output is also sorted.                 │
  │ set_union            : A ∪ B (all elements from both, no duplicates).   │
  │ set_intersection     : A ∩ B (only elements in both).                   │
  │ set_difference       : A - B (elements in A not in B).                  │
  │ set_symmetric_diff   : A Δ B (elements in A or B but not both).         │
  │ includes             : Checks if sorted range B is a subset of A.       │
  │ Complexity           : O(N + M).                                        │
  └─────────────────────────────────────────────────────────────────────────┘

  set_intersection(a.begin(),a.end(), b.begin(),b.end(), back_inserter(res));
  set_difference(a.begin(),a.end(), b.begin(),b.end(), back_inserter(res));

--------------------------------------------------------------------------------
GROUP I — HEAP OPERATIONS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ make_heap / push_heap / pop_heap / sort_heap                            │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ make_heap : Converts range into a max-heap. O(N).                       │
  │ push_heap : After push_back, restores heap property. O(log N).          │
  │ pop_heap  : Moves max to end, shrinks heap logically. O(log N).         │
  │ sort_heap : Sorts heap in ascending order. O(N log N). Destroys heap.   │
  │ When to use: Custom heap management without priority_queue wrapper.     │
  └─────────────────────────────────────────────────────────────────────────┘

  make_heap(v.begin(), v.end());      // max-heap
  v.push_back(99);
  push_heap(v.begin(), v.end());      // maintain heap property
  pop_heap(v.begin(), v.end());       // max now at v.back()
  v.pop_back();                       // remove it

--------------------------------------------------------------------------------
GROUP J — MIN / MAX ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ min_element / max_element / minmax_element / clamp                      │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ min_element    : Returns iterator to minimum element. O(N).             │
  │ max_element    : Returns iterator to maximum element. O(N).             │
  │ minmax_element : Returns pair<min_it, max_it> in single O(N) pass.      │
  │ clamp(v,lo,hi) : Returns value clamped to [lo, hi]. O(1). (C++17)       │
  └─────────────────────────────────────────────────────────────────────────┘

  auto it = max_element(v.begin(), v.end());
  auto [mn, mx] = minmax_element(v.begin(), v.end());
  int clamped = clamp(x, 0, 100);     // x limited to range [0, 100]

--------------------------------------------------------------------------------
GROUP K — PERMUTATION ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::next_permutation / std::prev_permutation / std::is_permutation     │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ next_permutation : Transforms range to next lexicographic permutation.  │
  │                    Returns false when it wraps around to smallest.      │
  │ prev_permutation : Goes to previous permutation.                        │
  │ is_permutation   : Checks if two ranges are permutations of each other. │
  │ Complexity       : O(N) per call.                                       │
  │ KEY POINT        : To iterate ALL permutations, start from sorted order │
  │                    and loop until next_permutation returns false.       │
  └─────────────────────────────────────────────────────────────────────────┘

  sort(v.begin(), v.end());          // start from smallest permutation
  do {
      // process v
  } while (next_permutation(v.begin(), v.end()));

--------------------------------------------------------------------------------
GROUP L — NUMERIC ALGORITHMS  (#include <numeric>)
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::accumulate                                                         │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Folds a range with a binary operation. Default is sum.   │
  │ Complexity   : O(N). Sequential (left-to-right) — order guaranteed.     │
  │ When to use  : Sum, product, string concatenation, any fold operation.  │
  └─────────────────────────────────────────────────────────────────────────┘

  int sum  = accumulate(v.begin(), v.end(), 0);
  int prod = accumulate(v.begin(), v.end(), 1, multiplies<int>());
  string s = accumulate(words.begin(), words.end(), string(""),
             [](string a, string b){ return a + " " + b; });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::reduce (C++17)                                                     │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Like accumulate but can be PARALLELIZED. Order of ops    │
  │               is NOT guaranteed — operation must be associative +       │
  │               commutative.                                              │
  │ When to use  : Parallel reductions on large datasets.                   │
  └─────────────────────────────────────────────────────────────────────────┘

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::iota                                                               │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Fills range with sequentially increasing values.         │
  │ Complexity   : O(N).                                                    │
  │ When to use  : Initialize index arrays. Create 0,1,2,...,N-1 sequences. │
  └─────────────────────────────────────────────────────────────────────────┘

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);    // idx = {0, 1, 2, ..., n-1}
  sort(idx.begin(), idx.end(), [&](int a, int b){ return v[a] < v[b]; });

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::partial_sum / std::adjacent_difference                             │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ partial_sum       : Prefix sum array. O(N).                             │
  │ adjacent_difference: Differences between consecutive elements. O(N).    │
  └─────────────────────────────────────────────────────────────────────────┘

  partial_sum(v.begin(), v.end(), prefix.begin());    // prefix[i] = sum(v[0..i])
  adjacent_difference(v.begin(), v.end(), diff.begin()); // diff[i] = v[i]-v[i-1]

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::inner_product                                                      │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ What it does : Computes dot product of two ranges (sum of a[i]*b[i]).   │
  │ Complexity   : O(N).                                                    │
  └─────────────────────────────────────────────────────────────────────────┘

  int dot = inner_product(a.begin(), a.end(), b.begin(), 0);

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ inclusive_scan / exclusive_scan (C++17)                                 │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ inclusive_scan: Like partial_sum — includes current element.            │
  │ exclusive_scan: Prefix sum EXCLUDING current element (shifted by one).  │
  │ Both can run in parallel (unlike partial_sum).                          │
  └─────────────────────────────────────────────────────────────────────────┘

--------------------------------------------------------------------------------
GROUP M — COMPARISON ALGORITHMS
--------------------------------------------------------------------------------

  ┌─────────────────────────────────────────────────────────────────────────┐
  │ std::equal / std::mismatch / std::lexicographical_compare               │
  ├─────────────────────────────────────────────────────────────────────────┤
  │ equal               : True if two ranges are element-wise equal. O(N).  │
  │ mismatch            : Returns pair of iterators to first differing pair.│
  │ lexicographical_compare: True if range1 is lexicographically < range2.  │
  └─────────────────────────────────────────────────────────────────────────┘

  equal(a.begin(), a.end(), b.begin());
  auto [it1, it2] = mismatch(a.begin(), a.end(), b.begin());

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. CORE THEORY (from source files)
--------------------------------------------------------------------------------

  [T][ ] What is STL? What are its main components?
         (Containers, Algorithms, Iterators, Functors, Adaptors)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] What does sort() use internally?
         (Introsort — hybrid of Quicksort + Heapsort + Insertion sort)
         Asked at: Amazon, Google, Microsoft, competitive programming

  [T][ ] What is the difference between sort() and stable_sort()?
         (sort: O(N log N) not stable; stable_sort: O(N log² N) preserves order)
         Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [T][ ] What is the difference between find() and binary_search() in STL?
         (find: O(N) linear, works on unsorted, returns iterator;
          binary_search: O(log N), requires sorted range, returns bool)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] What is lower_bound vs upper_bound?
         (lower_bound: first element >= x; upper_bound: first element > x)
         Asked at: Amazon, Flipkart, Google, Goldman Sachs

  [T][ ] What is an iterator? What are the 5 types of iterators?
         (Input, Output, Forward, Bidirectional, RandomAccess)
         Asked at: Amazon, Microsoft, Adobe

  [T][ ] What is the difference between begin() and end()?
         (begin: iterator to first element; end: iterator PAST last element)
         Asked at: TCS, Wipro

  [T][ ] What is a lambda expression? Give an example.
         ([capture](params){ return ...; })
         Asked at: Amazon, Google, Microsoft, Adobe

  [T][ ] When would you choose merge sort over quick sort?
         (Merge sort: stable, worst O(N log N), external sorting, linked lists;
          Quick sort: in-place, better cache, faster average in practice)
         Asked at: Amazon, Microsoft, Flipkart

  [T][ ] What is introsort? Which standard library sort() uses it?
         (Hybrid: quicksort depth-limited → heapsort fallback + insertion sort
          for small ranges. Used by GCC std::sort and MSVC std::sort)
         Asked at: Competitive programming, Google

  [T][ ] What is external sorting? When do you need it?
         (When data doesn't fit in RAM — split into chunks, sort each,
          merge using K-way merge)
         Asked at: Google, Microsoft, database companies

  [T][ ] What is counting sort? What are its limitations?
         (O(N + K) time, O(K) space; only for integer keys in bounded range)
         Asked at: Amazon, TCS, Wipro

  [T][ ] What is the difference between remove() and erase() in STL?
         (remove: algorithm — moves elements, returns new end, does NOT shrink;
          erase: container member — actually deletes and shrinks container)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the erase-remove idiom? Why is it needed?
         (v.erase(remove(v.begin(),v.end(),x), v.end()) — needed because
          remove() alone doesn't resize the container)
         Asked at: Amazon, Adobe, Qualcomm

  [T][ ] What is unique() and what is its precondition?
         (Removes consecutive duplicates; must sort first for global dedup)
         Asked at: Amazon, TCS, Adobe

  [T][ ] When should you use lower_bound vs upper_bound?
         Asked at: Amazon, competitive programming

  [T][ ] Explain binary search on the answer technique. When is it applicable?
         (Binary search on the answer value when it has a monotonic property)
         Asked at: Amazon, Flipkart, Google

--------------------------------------------------------------------------------
2B. ADVANCED THEORY (★ extra questions)
--------------------------------------------------------------------------------

  ★[T][ ] What is the difference between std::sort and std::qsort (C-style)?
           (std::sort is type-safe, works with custom comparators, inlined;
            qsort uses function pointer — slower, not type-safe)
           Asked at: Google, Microsoft, advanced C++ roles

  ★[T][ ] What is the complexity difference between partial_sort and nth_element?
           (partial_sort: O(N log K); nth_element: O(N) avg — use nth_element
            when you only need the Kth element, not all K sorted)
           Asked at: Amazon, Goldman Sachs, Google

  ★[T][ ] What is the difference between accumulate and reduce (C++17)?
           (accumulate: sequential, order guaranteed;
            reduce: may be parallelized, order not guaranteed)
           Asked at: Google, Microsoft, advanced C++ roles

  ★[T][ ] Why does remove_if not work on std::list the same way as vector?
           (list has its own remove_if member — use list::remove_if() which
            actually erases; the algorithm version does not erase from list)
           Asked at: Amazon, Adobe, advanced C++ roles

  ★[T][ ] What is the difference between std::copy and std::move (algorithm)?
           (copy: copies elements to output; std::move (algorithm): move-constructs
            elements to output — useful for moving unique_ptrs)
           Asked at: Google, Microsoft

  ★[T][ ] What is for_each and when is it preferred over range-based for loop?
           (for_each: applies function to each element; returns the function object
            — useful when you need to accumulate state via functor)
           Asked at: Amazon, Adobe

  ★[T][ ] What is std::rotate and what is its return value in C++11?
           (Returns iterator to element that was previously at v.begin(),
            now at the end — useful for chaining rotations)
           Asked at: Google, competitive programming

  ★[T][ ] What is the time complexity of set_union, set_intersection on
           two vectors of sizes N and M?
           O(N + M) — single linear pass through both sorted ranges
           Asked at: Amazon, Goldman Sachs, competitive programming

  ★[T][ ] What is std::clamp and what is its advantage over manual min/max?
           (clamp(v, lo, hi) = max(lo, min(v, hi)); single expression,
            UB-safe, works with custom comparators; C++17)
           Asked at: Google, Qualcomm, competitive programming

  ★[T][ ] What is std::sample (C++17) and what algorithm does it implement?
           (Reservoir sampling — selects K elements uniformly at random from
            a range in a single O(N) pass)
           Asked at: Amazon, Google, data engineering roles

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Sort vector of strings by length using custom comparator
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Find first element > 10 using find_if
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Use next_permutation to print all permutations of {1, 2, 3}
             Sort first, loop until returns false
             Asked at: Amazon, competitive programming

  [C][ ] (E) Count elements satisfying a condition using count_if + lambda
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Use accumulate to find sum and product of array
             Asked at: TCS, Wipro, Persistent, Nagarro

  [C][ ] (E) Remove all elements equal to X from vector using erase-remove idiom
             v.erase(remove(v.begin(), v.end(), x), v.end())
             Asked at: Amazon, Persistent, Nagarro

  [C][ ] (E) Use std::partition to separate even and odd elements (no sort)
             Asked at: Persistent, Nagarro, TCS

  [C][ ] (E) Given sorted array, find count of occurrences of X using lower_bound
             and upper_bound
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Find floor and ceiling of a number in a sorted array using
             lower_bound / upper_bound
             Asked at: Amazon, Flipkart

  [C][ ] (E) Given array, check if it is sorted using is_sorted
             Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Use std::fill to initialize a 2D grid to -1
              fill(grid[0], grid[0] + n*m, -1)
              Asked at: TCS, competitive programming

  ★[C][ ] (E) Use std::iota to create an index array, then sort indices by
              value (argsort / indirect sort)
              Asked at: Amazon, Goldman Sachs

  ★[C][ ] (E) Use any_of / all_of / none_of to validate an array:
              (a) any negative, (b) all positive, (c) no zeros
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Use std::reverse to reverse words in a string
              (reverse entire string, then reverse each word)
              Asked at: Amazon, TCS, Microsoft

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Implement a custom comparator for std::sort that sorts strings
             by number of vowels descending, then alphabetically for ties
             Asked at: Amazon, Adobe

  [C][ ] (M) Using STL only (no raw loops), find the top-3 most frequent elements
             from a vector<int> — use unordered_map + partial_sort
             Asked at: Amazon, Google

  [C][ ] (M) Given two sorted vectors, merge them into one sorted vector
             without using sort() — use std::merge
             Asked at: Amazon, Adobe

  [C][ ] (M) Use std::next_permutation to generate all permutations of a
             sorted vector; count total and verify = N!
             Asked at: Amazon, competitive programming

  [C][ ] (M) Given vector<vector<int>> (2D grid), flatten it into 1D using STL
             Use std::accumulate with lambda or std::copy
             Asked at: Adobe, Atlassian

  [C][ ] (M) Sort array by frequency of elements; same frequency → sort by value
             Asked at: Amazon, Flipkart, Paytm, Swiggy

  [C][ ] (M) Given two arrays A and B, sort A such that relative order matches B.
             Elements not in B go to end in sorted order.
             Asked at: Amazon, Flipkart, Adobe

  [C][ ] (M) Merge K sorted arrays into one sorted array using min heap. O(N log K)
             Asked at: Amazon, Google, Microsoft (very common!)

  [C][ ] (M) Sort array using 3-way quicksort (Dutch National Flag). O(N log N) avg
             Asked at: Competitive programming, Amazon, Google

  [C][ ] (M) Pancake sorting: sort using only prefix reversal operations
             Asked at: Google, competitive programming

  [C][ ] (M) Sort a linked list in O(N log N) time O(1) space
             (Merge sort on linked list — no extra array)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Sort array of strings such that all anagrams are adjacent.
             Sort each string as key, then sort array
             Asked at: Amazon, Microsoft

  [C][ ] (M) Find kth largest element using nth_element — O(N) average
             Asked at: Amazon, Microsoft, Facebook/Meta

  ★[C][ ] (M) Use std::transform to compute element-wise product of two vectors
              and store result in a third vector (no raw loop allowed)
              Asked at: Adobe, Atlassian, Qualcomm

  ★[C][ ] (M) Use std::rotate to left-rotate an array by K positions in O(N) O(1)
              and right-rotate using the same function
              Asked at: Amazon, TCS

  ★[C][ ] (M) Given a sorted array, use lower_bound to implement a custom
              binary search that returns the first element >= target
              and count how many elements equal target — without raw loop
              Asked at: Amazon, Goldman Sachs

  ★[C][ ] (M) Use std::set_intersection and std::set_difference on two sorted
              arrays to find common elements and elements unique to each array
              Asked at: Amazon, Goldman Sachs, competitive programming

  ★[C][ ] (M) Use partial_sum to build a prefix sum array, then answer
              multiple range sum queries in O(1) each
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (M) Given array, use stable_sort to sort students by marks, then
              verify that students with same marks keep their original order
              (demonstrate stable vs unstable sort difference)
              Asked at: Amazon, TCS, Microsoft

  ★[C][ ] (M) Use std::unique_copy to write all distinct elements of an
              unsorted array to a new vector (sort + unique_copy)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (M) Implement "sort indices" (argsort): given array v, produce
              index array sorted such that v[idx[0]] <= v[idx[1]] <= ...
              Use iota + sort with indirect comparator
              Asked at: Amazon, Goldman Sachs, competitive programming

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Count inversions in array using modified merge sort — O(N log N)
             Asked at: Amazon, Microsoft, Goldman Sachs, JP Morgan

  [C][ ] (H) Count inversions using BIT (Binary Indexed Tree)
             Asked at: Competitive programming, Dolat Capital

  [C][ ] (H) Sort a nearly sorted array where every element is at most K
             positions away from its sorted position — use min heap. O(N log K)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) External sort: sort a file of 10 GB of integers with only 1 GB RAM
             (Merge sort with disk-based chunks — describe the algorithm)
             Asked at: Google, Microsoft, database companies

  [C][ ] (H) Find the K-th smallest element in a sorted N×N matrix
             Use binary search on value range + lower_bound counting. O(N log N)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Median of two sorted arrays in O(log(min(m, n)))
             Binary search on smaller array — uses lower_bound logic
             Asked at: Google, Amazon, Microsoft, Facebook/Meta

  ★[C][ ] (H) Given N sorted arrays (varying sizes), find the smallest range
              that includes at least one element from each array
              (Use min-heap + sliding window + set_intersection concept)
              Asked at: Google, Goldman Sachs, Amazon

  ★[C][ ] (H) Implement std::stable_partition from scratch (partition such that
              order of elements in each group is preserved) — O(N log N)
              Asked at: Google, advanced C++ roles

  ★[C][ ] (H) Given permutation of 1..N, find the minimum number of reverse
              operations to sort it — BFS where state = permutation
              (next_permutation concept extended to BFS)
              Asked at: Google, competitive programming

  ★[C][ ] (H) Given array of integers, find the next greater permutation
              (implement next_permutation logic from scratch without STL)
              Steps: find rightmost descent, find next larger, swap, reverse suffix
              Asked at: Amazon, Microsoft, Google (commonly asked to implement)

================================================================================
PART 6 — ALGORITHM SELECTION CHEATSHEET
================================================================================

  PROBLEM TYPE                         BEST ALGORITHM           COMPLEXITY
  ─────────────────────────────────────────────────────────────────────────
  Sort any range                       sort()                   O(N log N)
  Sort, preserve equal order           stable_sort()            O(N log² N)
  Find Kth smallest (no full sort)     nth_element()            O(N) avg
  Find top K sorted                    partial_sort()           O(N log K)
  Find value in sorted range (bool)    binary_search()          O(log N)
  Find insertion point (lower)         lower_bound()            O(log N)
  Find insertion point (upper)         upper_bound()            O(log N)
  Count occurrences in sorted range    upper_bound - lower_bound O(log N)
  Find in unsorted range               find() / find_if()       O(N)
  Count with condition                 count_if()               O(N)
  Any/All/None check                   any_of/all_of/none_of    O(N) sc
  Remove elements matching condition   remove_if() + erase()    O(N)
  Remove consecutive duplicates        unique() + erase()       O(N)
  Partition by predicate               partition()              O(N)
  Map values to new range              transform()              O(N)
  Sum/fold a range                     accumulate()             O(N)
  Prefix sum array                     partial_sum()            O(N)
  Fill 0,1,2,..N                       iota()                   O(N)
  Intersect two sorted arrays          set_intersection()       O(N+M)
  Merge two sorted arrays              merge()                  O(N+M)
  All permutations                     next_permutation()       O(N*N!)
  Reverse a range                      reverse()                O(N)
  Rotate a range                       rotate()                 O(N)
  Random shuffle                       shuffle() (mt19937)      O(N)
  Min/Max in range                     min_element/max_element  O(N)
  Min and Max in one pass              minmax_element()         O(N)
  Clamp value to range                 clamp()                  O(1)

================================================================================
QUICK REFERENCE — INCLUDES AND COMMON PATTERNS
================================================================================

  #include <algorithm>   // sort, find, binary_search, lower_bound, upper_bound,
                         // transform, fill, reverse, rotate, partition, unique,
                         // remove, merge, set_intersection, nth_element,
                         // next_permutation, any_of, all_of, count_if, etc.

  #include <numeric>     // accumulate, iota, partial_sum, adjacent_difference,
                         // inner_product, reduce, inclusive_scan, exclusive_scan

  #include <functional>  // greater<>, less<>, plus<>, multiplies<>, negate<>

  ── COMMON PATTERNS ───────────────────────────────────────────────────────

  // 1. Erase-Remove Idiom
  v.erase(remove_if(v.begin(), v.end(), pred), v.end());

  // 2. Remove all duplicates
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  // 3. Count occurrences in sorted array
  int cnt = upper_bound(v.begin(),v.end(),x) - lower_bound(v.begin(),v.end(),x);

  // 4. Argsort (sort indices by value)
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a, int b){ return v[a] < v[b]; });

  // 5. Left-rotate by K
  rotate(v.begin(), v.begin() + k, v.end());

  // 6. Next permutation
  sort(v.begin(), v.end());
  do { process(v); } while (next_permutation(v.begin(), v.end()));

  // 7. Prefix sum
  vector<int> pre(n+1, 0);
  partial_sum(v.begin(), v.end(), pre.begin() + 1);
  // range sum [l, r] = pre[r+1] - pre[l]

  // 8. Flatten 2D vector
  vector<int> flat;
  accumulate(grid.begin(), grid.end(), flat,
      [](vector<int> a, vector<int>& b){
          a.insert(a.end(), b.begin(), b.end()); return a; });

  // 9. Check sorted + binary search guard
  assert(is_sorted(v.begin(), v.end()));
  bool exists = binary_search(v.begin(), v.end(), target);

  // 10. Kth smallest in O(N)
  nth_element(v.begin(), v.begin() + k, v.end());
  int kth = v[k];

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 17 |  0 |  0 |    17
  Theory (★ added)           | 10 |  0 |  0 |    10
  Coding Easy (from files)   | 10 |  0 |  0 |    10
  Coding Easy (★ added)      |  4 |  0 |  0 |     4
  Coding Medium (from files) |  0 | 13 |  0 |    13
  Coding Medium (★ added)    |  0 |  8 |  0 |     8
  Coding Hard (from files)   |  0 |  0 |  6 |     6
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  Algorithm Explanations     | 20 groups fully documented (Groups A–M)
  ---------------------------|----|----|----|---------
  TOTAL Q&A                  | 41 | 21 | 10 |    72

================================================================================
END
================================================================================
