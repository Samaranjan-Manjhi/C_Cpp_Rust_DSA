================================================================================
        STL — LIST (std::list & std::forward_list) COMPLETE QUESTION BANK
        Covers: std::list internals + classic linked list algorithms
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

NOTE: This file covers TWO layers:
  Layer 1 — std::list / std::forward_list (STL container theory + usage)
  Layer 2 — Classic Linked List algorithm problems (asked using custom Node structs)
  Both are tested in real C++ interviews — you need both.

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. std::list INTERNALS & MEMORY
--------------------------------------------------------------------------------

  [T][ ] What is std::list in C++? What is its underlying data structure?
         (Doubly linked list — each node has prev, next pointers + data)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What is the difference between std::list and std::vector?
         (list: O(1) insert/delete anywhere, no random access, non-contiguous;
          vector: O(1) access, O(N) insert/delete in middle, contiguous)
         Asked at: TCS, Wipro, Infosys, Amazon, Microsoft

  [T][ ] What is the difference between std::list and std::forward_list?
         (list: doubly linked, can traverse both ways, more memory;
          forward_list: singly linked, only forward traversal, less memory)
         Asked at: Amazon, Microsoft, C++ developer roles

  [T][ ] What is the time complexity of the following operations on std::list?
         push_front, push_back, pop_front, pop_back, insert(iterator), erase(iterator)
         (All O(1) given an iterator — no shifting needed)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What is the time complexity of accessing the Nth element of std::list?
         How is it different from vector?
         (O(N) — must traverse from head; vector: O(1) random access)
         Asked at: TCS, Wipro, Amazon, Flipkart

  [T][ ] Does std::list support random access iterators?
         What type of iterator does it provide?
         (No random access — provides bidirectional iterator only)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] When would you prefer std::list over std::vector?
         When would you prefer std::vector over std::list?
         (list: frequent insert/delete in middle with iterator in hand;
          vector: frequent access by index, cache performance matters)
         Asked at: Amazon, Microsoft, Flipkart, Zoho

  [T][ ] What is the difference between std::list and std::deque?
         (deque: O(1) at both ends + near-random access, contiguous chunks;
          list: O(1) insert/delete anywhere with iterator, fully linked)
         Asked at: Amazon, Persistent, Nagarro

  ★[T][ ] Are iterators of std::list invalidated on insert or erase?
          (Only the erased element's iterator is invalidated — all other iterators
           remain valid. This is a key advantage over vector!)
          Asked at: Amazon, Adobe, Persistent, Google

  ★[T][ ] How much extra memory does each node in std::list consume
          compared to the stored data?
          (Two pointers — prev and next — typically 16 bytes extra on 64-bit systems)
          Asked at: Dolat Capital, HFT firms, Samsung

  ★[T][ ] What is the internal node structure of std::list?
          (struct __list_node { T data; __list_node* prev; __list_node* next; })
          Asked at: Samsung, Sasken, advanced C++ roles

  ★[T][ ] Why is std::list cache-unfriendly compared to std::vector?
          (Nodes scattered in heap — no spatial locality; frequent cache misses)
          Asked at: Dolat Capital, HFT firms, Google

--------------------------------------------------------------------------------
1B. std::list OPERATIONS & STL USAGE
--------------------------------------------------------------------------------

  [T][ ] How do you insert an element at the beginning, end, and middle of std::list?
         (push_front, push_back, insert(iterator, value))
         Asked at: TCS, Wipro, Zoho

  [T][ ] How does std::list::splice() work? What is its time complexity?
         (Moves elements from one list to another in O(1) — no copy, just pointer rewiring)
         Asked at: Amazon, Adobe, Persistent, Google

  [T][ ] What is std::list::merge()? When can you use it?
         (Merges two sorted lists into one sorted list in O(N) — both must be sorted)
         Asked at: Amazon, Adobe, Persistent

  [T][ ] What is std::list::unique()? What does it do?
         (Removes consecutive duplicate elements — list must be sorted for full dedup)
         Asked at: TCS, Wipro, Persistent, Nagarro

  [T][ ] What is std::list::sort()? How is it different from std::sort()?
         (list.sort() uses merge sort internally — O(N log N);
          std::sort() requires random access iterators, so it CANNOT be used on list)
          Asked at: Amazon, Microsoft, Persistent, Nagarro

  [T][ ] What is std::list::reverse()? What is its complexity?
         (Reverses the list in-place in O(N) by relinking all nodes)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is std::list::remove() vs std::list::erase()?
         (remove(val): removes ALL elements == val by value, O(N);
          erase(iter): removes element at iterator position, O(1))
         Asked at: Amazon, Persistent, Nagarro

  ★[T][ ] Why can't you use std::sort() on std::list? What should you use instead?
          (std::sort requires RandomAccessIterator; list only has BidirectionalIterator;
           use list.sort() instead — it's a member function using merge sort)
          Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] What is std::list::emplace_front() and emplace_back()?
          How are they better than push_front/push_back?
          (Construct element in-place — avoids copy/move overhead)
          Asked at: Amazon, Persistent, Nagarro, Adobe

  ★[T][ ] How do you get the size of std::list in O(1)?
          (list.size() is O(1) in C++11 and later — implementation required to track size)
          Asked at: TCS, Wipro, Persistent

--------------------------------------------------------------------------------
1C. CLASSIC LINKED LIST — NODE STRUCTURE & CONCEPTS
--------------------------------------------------------------------------------

  [T][ ] What is a linked list? How is it different from an array?
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is a singly linked list vs doubly linked list vs circular linked list?
         Compare: memory per node, traversal, insert/delete operations.
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] What is the time complexity of insertion and deletion at:
         beginning, end, and middle of a singly and doubly linked list?
         Asked at: TCS, Wipro, Amazon, Infosys

  [T][ ] What are the advantages and disadvantages of linked list over array?
         Asked at: TCS, Wipro, Infosys, Amazon, Zoho

  [T][ ] When would you prefer linked list over array? When array over linked list?
         (Insert/delete O(1) vs cache locality and random access O(1))
         Asked at: Amazon, Microsoft, Flipkart, Zoho

  [T][ ] What is Floyd's Cycle Detection Algorithm? How does it work?
         (Slow + fast pointer; if they meet → cycle exists)
         Asked at: Amazon, Microsoft, Google, Flipkart, Paytm

  [T][ ] What is an XOR linked list? What problem does it solve?
         (Each node stores prev XOR next — halves pointer storage to one pointer)
         Asked at: Advanced C++, Samsung, competitive programming

  [T][ ] What is an unrolled linked list? What are its advantages?
         (Array of elements per node — better cache performance than plain linked list)
         Asked at: Google, Dolat Capital, cache-optimized systems

  ★[T][ ] What is the difference between a circular singly linked list
          and a circular doubly linked list?
          Asked at: TCS, Wipro, Infosys, Zoho

  ★[T][ ] How do you detect the end of a singly linked list during traversal?
          (When node->next == nullptr for linear; when back to head for circular)
          Asked at: TCS, Wipro, Infosys

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. std::list BASIC USAGE
--------------------------------------------------------------------------------

  ★[C][ ] (E) Create a std::list<int>, insert elements using push_front, push_back,
              and insert at a specific iterator position.
              Print the list forward and backward (using reverse iterator).
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Given std::list<int>, remove all elements equal to X using:
              (a) list.remove(X)         — removes all occurrences
              (b) list.erase(iterator)   — removes one at a time
              Show the difference.
              Asked at: TCS, Wipro, Amazon, Persistent

  ★[C][ ] (E) Given a std::list<int>, sort it using list.sort().
              Show why std::sort() does NOT work on std::list.
              Asked at: Amazon, Persistent, Nagarro

  ★[C][ ] (E) Demonstrate std::list::splice():
              Move elements from one list to another at a given position in O(1).
              Asked at: Amazon, Adobe, Persistent

  ★[C][ ] (E) Given two sorted std::lists, merge them into one sorted list
              using list.merge(). Verify the result.
              Asked at: Amazon, Adobe, Persistent

  ★[C][ ] (E) Demonstrate std::list::unique() — remove consecutive duplicates.
              First sort the list, then apply unique. Show before/after.
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Demonstrate iterator stability of std::list:
              Store an iterator, insert 100 elements, check if iterator is still valid.
              Compare with vector (which would be invalidated).
              Asked at: Amazon, Adobe, Persistent, Google

--------------------------------------------------------------------------------
2B. CLASSIC LINKED LIST — EASY ALGORITHMS
--------------------------------------------------------------------------------

  [C][ ] (E) Insert a node at the beginning of a singly linked list.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Insert a node at the end of a singly linked list.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Insert a node at position K in a singly linked list.
             Asked at: TCS, Wipro

  [C][ ] (E) Delete the first node of a singly linked list.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Delete the last node of a singly linked list.
             Asked at: TCS, Wipro

  [C][ ] (E) Count the number of nodes in a linked list.
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Search for an element in a linked list — return position (1-indexed).
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Print linked list in reverse without reversing it.
             Hint: recursion or stack — O(N) space.
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Concatenate two linked lists (append second to end of first).
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Reverse a singly linked list — both iterative and recursive.
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe, Paytm, Goldman Sachs
             (Most frequently asked linked list question!)

  [C][ ] (E) Find the middle element of a linked list in a single pass.
             (Slow/fast pointer — fast moves 2 steps, slow moves 1)
             Asked at: Amazon, Microsoft, Flipkart, Zoho

  [C][ ] (E) Delete Nth node from the end of a linked list in a single pass.
             (Two pointers N nodes apart)
             Asked at: Amazon, Microsoft, Google, Adobe, Zoho

  [C][ ] (E) Merge two sorted linked lists into one sorted linked list.
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (E) Remove duplicates from a sorted linked list.
             (Each element appears exactly once in output)
             Asked at: Amazon, Microsoft, TCS, Wipro

  [C][ ] (E) Check if a linked list is a palindrome.
             (Find middle, reverse second half, compare — O(1) extra space)
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (E) Delete all occurrences of a given value from a linked list.
             Handle head, middle, consecutive duplicates.
             Asked at: Amazon, Flipkart, Zoho, TCS

  [C][ ] (E) Given head pointer, delete a node given only that node's pointer (not head).
             (Classic trick: copy next node's data → delete next)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Swap nodes pairwise without swapping data.
             1->2->3->4->5 → 2->1->4->3->5
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (E) Given sorted linked list, remove ALL duplicates leaving only distinct numbers.
             e.g. 1->2->2->3->3->4 → 1->4 (both 2s and both 3s removed)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (E) Segregate even and odd positioned nodes.
             1->2->3->4->5 → 1->3->5->2->4
             Asked at: Amazon, Flipkart, Microsoft

  [C][ ] (E) Convert a linked list to an array (vector) and back.
             Asked at: TCS, Wipro

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. CYCLE & INTERSECTION
--------------------------------------------------------------------------------

  [C][ ] (M) Detect cycle in a linked list using Floyd's algorithm.
             Return true if cycle exists.
             Asked at: Amazon, Microsoft, Google, Flipkart, Paytm

  [C][ ] (M) Find the starting point (entry node) of a cycle in a linked list.
             (Floyd's + math: after meeting point, reset one pointer to head)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find the intersection point of two linked lists.
             (Two pointer technique: advance longer list by difference in lengths)
             Asked at: Amazon, Microsoft, Adobe, Flipkart, Goldman Sachs

  ★[C][ ] (M) Given a linked list with a cycle, find the length of the cycle.
              Asked at: Amazon, Microsoft, Paytm

--------------------------------------------------------------------------------
3B. REVERSAL & REORDERING
--------------------------------------------------------------------------------

  [C][ ] (M) Reverse a linked list in groups of K.
             1->2->3->4->5, K=2 → 2->1->4->3->5
             Asked at: Amazon, Microsoft, Google, Flipkart, Zoho

  [C][ ] (M) Reverse linked list from position M to N in a single pass.
             (Iterative — careful pointer rewiring)
             Asked at: Amazon, Microsoft

  [C][ ] (M) Reverse every alternate group of K nodes in a linked list.
             (Reverse K, skip K, reverse K, ...)
             Asked at: Amazon, Flipkart

  [C][ ] (M) Reorder linked list: L0->L1->...->Ln-1
             becomes: L0->Ln-1->L1->Ln-2->...
             (Find middle, reverse second half, merge two halves)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Rearrange linked list: odd-indexed nodes first, then even-indexed.
             (Odd-Even Linked List — LeetCode 328)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Remove all nodes from a linked list that have a greater value
             to their right. e.g. 5->2->13->3->8 → 13->8
             Asked at: Amazon, Flipkart, Paytm

--------------------------------------------------------------------------------
3C. SORTING & PARTITIONING
--------------------------------------------------------------------------------

  [C][ ] (M) Sort a linked list in O(N log N) time and O(1) space.
             Use merge sort — split list, sort halves, merge.
             Asked at: Amazon, Microsoft, Adobe, Flipkart, Google

  [C][ ] (M) Partition a linked list around value X:
             All nodes < X come before all nodes >= X.
             Maintain relative order (stable partition).
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given a sorted linked list and value X, split into two lists:
             one with elements < X, one with elements >= X.
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given a linked list, rearrange so values <= X come first,
             then values == X, then values > X (3-way partition).
             Maintain relative order within each group.
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given linked list with values in range [1, N], sort it in O(N).
             (Counting sort on linked list — then re-link by frequency order)
             Asked at: Competitive programming, Samsung

--------------------------------------------------------------------------------
3D. ADDITION, MULTIPLICATION, CONVERSION
--------------------------------------------------------------------------------

  [C][ ] (M) Add two numbers represented as linked lists (digits in reverse order).
             e.g. 2->4->3 + 5->6->4 = 7->0->8 (342 + 465 = 807)
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Add two numbers represented as linked lists where digits are in
             FORWARD order (not reversed). No extra space for reversal.
             Use recursion to add from the end.
             Asked at: Amazon, Microsoft

  [C][ ] (M) Convert binary number represented as linked list to decimal integer.
             e.g. 1->0->1 = 5
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given two linked lists representing polynomials (coeff + exponent per node),
             add them and return result as a new linked list.
             Asked at: Goldman Sachs, Zoho

  ★[C][ ] (M) Subtract two numbers represented as linked lists.
              Handle borrow carefully.
              Asked at: Goldman Sachs, competitive programming

--------------------------------------------------------------------------------
3E. CLONING, ROTATION, SPLITTING
--------------------------------------------------------------------------------

  [C][ ] (M) Clone a linked list with both 'next' and 'random' pointers.
             O(N) time O(N) space using hashmap,
             then O(N) time O(1) space using interweaving trick.
             Asked at: Amazon, Microsoft, Google, Adobe, Facebook/Meta

  [C][ ] (M) Rotate linked list to the right by K places.
             1->2->3->4->5, K=2 → 4->5->1->2->3
             (Find new tail, rewire)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Rotate linked list to the left by K positions.
             Asked at: Amazon, Flipkart

  [C][ ] (M) Split linked list into K parts as evenly as possible.
             Longer parts come first.
             Asked at: Amazon, Google

  [C][ ] (M) Given sorted linked list, convert to a height-balanced BST.
             O(N) time — mid of list becomes root.
             Asked at: Amazon, Microsoft, Google

--------------------------------------------------------------------------------
3F. FLATTENING
--------------------------------------------------------------------------------

  [C][ ] (M) Flatten a multilevel doubly linked list.
             Each node has next, prev AND a child pointer to another list.
             Flatten into one single-level doubly linked list.
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Flatten a linked list that has a 'down' pointer in addition to 'next'.
             Each node can have a vertical list hanging below it.
             Merge all into one sorted list.
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Given linked list where each node has a next pointer AND a child pointer
             pointing to another linked list, flatten into one sorted list.
             Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Flatten a linked list of linked lists
              (each node's value is itself a linked list).
              Merge all sub-lists into one sorted flat list.
              Asked at: Amazon, Flipkart, Adobe

--------------------------------------------------------------------------------
3G. std::list ADVANCED USAGE
--------------------------------------------------------------------------------

  [C][ ] (M) Implement LRU Cache using std::list + std::unordered_map<key, list::iterator>.
             get(key): O(1) — find in map, move node to front of list.
             put(key, val): O(1) — insert at front, evict from back if full.
             Asked at: Amazon, Microsoft, Google, Flipkart (VERY common!)

  ★[C][ ] (M) Implement LFU Cache using std::list + std::unordered_map.
              get and put both O(1).
              Hint: map from frequency → list of keys; map from key → (val, freq, iter)
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Use std::list::splice() to implement a move-to-front cache:
              On access, splice that node to the front of the list in O(1).
              Asked at: Amazon, Adobe, Persistent

  ★[C][ ] (M) Implement a Least Recently Used (LRU) page replacement algorithm
              using std::list to track page order.
              Simulate N page accesses with a cache of capacity C.
              Count the number of page faults.
              Asked at: Zoho, TCS, Infosys, OS interview rounds

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
4A. MERGE & ADVANCED MANIPULATION
--------------------------------------------------------------------------------

  [C][ ] (H) Merge K sorted linked lists using min-heap (priority_queue). O(N log K).
             Asked at: Amazon, Google, Microsoft, Goldman Sachs, Flipkart

  [C][ ] (H) Merge K sorted linked lists using divide and conquer. O(N log K).
             (NOT just priority queue — implement the D&C version)
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Given two linked lists where each represents a number (digits in order),
             multiply them and return result as a linked list.
             Asked at: Goldman Sachs, competitive programming

  [C][ ] (H) Reverse nodes in K-groups. K-group reversal.
             e.g. 1->2->3->4->5, K=3 → 3->2->1->4->5
             Asked at: Amazon, Google, Microsoft

  ★[C][ ] (H) Given a linked list, find the longest palindrome sublist.
              (Not just checking if whole list is palindrome — find longest sub-sequence)
              Asked at: Google, Amazon

  ★[C][ ] (H) Given a circular doubly linked list, sort it in-place.
              (Merge sort adapted for circular DLL — tricky pointer management)
              Asked at: Adobe, Persistent, advanced roles

--------------------------------------------------------------------------------
4B. IMPLEMENT FROM SCRATCH
--------------------------------------------------------------------------------

  [C][ ] (H) Implement a doubly linked list from scratch supporting:
             insert(iterator, value) — O(1) given iterator
             erase(iterator) — O(1) given iterator
             push_front, push_back, pop_front, pop_back — all O(1)
             operator[] — O(N) (clearly document this)
             begin(), end(), rbegin(), rend() iterators
             sort() using merge sort — O(N log N)
             Asked at: Dolat Capital, Persistent, Adobe, Google

  [C][ ] (H) Implement skip list from scratch:
             Multi-level linked list for O(log N) average search.
             insert(val), search(val), delete(val) with probabilistic balancing.
             Asked at: Google, Dolat Capital, advanced data structure roles

  ★[C][ ] (H) Implement a sorted doubly linked list with:
              insert(val) — maintains sorted order, O(N)
              remove(val) — O(N)
              findKthSmallest(K) — O(K)
              merge(other) — merges another sorted DLL in O(N+M)
              Asked at: Goldman Sachs, Persistent, Adobe

  ★[C][ ] (H) Implement XOR linked list from scratch:
              Each node stores only ONE pointer = prev_addr XOR next_addr.
              Support: insert, delete, forward traversal, backward traversal.
              (Uses XOR trick to halve memory for pointers)
              Asked at: Samsung, advanced C++ roles, competitive programming

--------------------------------------------------------------------------------
4C. TREES ↔ LINKED LIST CONVERSIONS (Trees + Linked List combined)
--------------------------------------------------------------------------------

  ★[C][ ] (H) Flatten a binary tree to a linked list in-place (preorder order).
              No extra node allocation.
              Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (H) Convert a binary search tree to a sorted circular doubly linked list
              in-place (in-order traversal → DLL). No extra space.
              Asked at: Amazon, Microsoft, Google, Facebook/Meta

  ★[C][ ] (H) Given a sorted singly linked list, convert it to a height-balanced BST.
              O(N) time — find mid of list as root without converting to array.
              Asked at: Amazon, Microsoft, Google

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output and why?
          std::list<int> l = {1, 2, 3, 4, 5};
          auto it = l.begin();
          advance(it, 2);
          l.insert(it, 99);
          // Is 'it' still valid? What does *it print?
          (Yes — list iterators are NOT invalidated by insert. *it == 3)
          Asked at: Amazon, Adobe, Persistent

  ★[T][ ] What is wrong with this code?
          std::list<int> l = {1, 2, 3, 4};
          for (auto it = l.begin(); it != l.end(); ++it)
              if (*it % 2 == 0)
                  l.erase(it);  // BUG: it is now dangling
          // Fix: it = l.erase(it); else ++it;
          Asked at: Amazon, Microsoft, Adobe, Persistent

  ★[T][ ] Why can't you do this with std::list?
          std::list<int> l = {5, 3, 1, 4, 2};
          std::sort(l.begin(), l.end());   // COMPILE ERROR
          // Fix: l.sort();
          Asked at: Amazon, Persistent, Nagarro, TCS

  ★[T][ ] std::list::size() — is it O(1) or O(N) in C++11 and later?
          (O(1) — C++11 standard mandates constant-time size())
          Asked at: Persistent, Nagarro, L&T Infotech

  ★[T][ ] What is the difference between list::remove() and list::erase()?
          list<int> l = {1,2,2,3};
          l.remove(2);        // removes ALL 2s — O(N)
          l.erase(l.begin()); // removes element at iterator — O(1)
          Asked at: TCS, Wipro, Persistent, Amazon

  ★[T][ ] What happens to all iterators when you call std::list::sort()?
          (All iterators remain valid — sort relinks nodes, does not copy them)
          Asked at: Persistent, Nagarro, Adobe

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — std::list Internals & Memory         | 12 |  0 |  0 |    12
  Theory — std::list Operations & STL           | 10 |  0 |  0 |    10
  Theory — Classic Linked List Concepts         | 10 |  0 |  0 |    10
  Coding Easy — std::list Basic Usage           |  7 |  0 |  0 |     7
  Coding Easy — Classic LL Algorithms           | 14 |  0 |  0 |    14
  Coding Medium — Cycle & Intersection          |  0 |  4 |  0 |     4
  Coding Medium — Reversal & Reordering         |  0 |  6 |  0 |     6
  Coding Medium — Sorting & Partitioning        |  0 |  5 |  0 |     5
  Coding Medium — Addition, Multiply, Convert   |  0 |  5 |  0 |     5
  Coding Medium — Clone, Rotate, Split          |  0 |  5 |  0 |     5
  Coding Medium — Flattening                    |  0 |  4 |  0 |     4
  Coding Medium — std::list Advanced Usage      |  0 |  4 |  0 |     4
  Coding Hard — Merge & Advanced Manipulation   |  0 |  0 |  6 |     6
  Coding Hard — Implement from Scratch          |  0 |  0 |  4 |     4
  Coding Hard — Trees ↔ Linked List             |  0 |  0 |  3 |     3
  Tricky Output / Concept Questions             |  6 |  0 |  0 |     6
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 59 | 33 | 13 |   105

  ★ = 48 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    → What is linked list, types, insert/delete at head/tail/middle,
      reverse list, count nodes, search, merge two sorted lists,
      why std::sort doesn't work on std::list, list.sort()

  ZOHO:
    → Palindrome check, cycle detection, LRU page replacement,
      add two numbers as linked list, polynomial addition

  AMAZON / FLIPKART / PAYTM:
    → Reverse in K groups, detect cycle + start node, intersection,
      clone with random pointer, odd-even reorder, rotate, flatten,
      merge K sorted lists, LRU cache (list + unordered_map)

  MICROSOFT / ADOBE:
    → Reorder list (L0→Ln-1→L1→Ln-2), reverse M to N, sort linked list,
      flatten multilevel DLL, BST ↔ DLL conversion, erase-in-loop bug

  GOOGLE / ATLASSIAN:
    → Skip list, longest palindrome sublist, D&C merge K lists,
      sorted LL to balanced BST, iterator stability of std::list

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Multiply two linked lists, polynomial add, XOR linked list,
      custom doubly linked list from scratch, sorted DLL + merge,
      cache unfriendliness of std::list, iterator invalidation rules

================================================================================
END
================================================================================
