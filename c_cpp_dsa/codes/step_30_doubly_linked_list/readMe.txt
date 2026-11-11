================================================================================
        DOUBLY LINKED LIST — COMPLETE QUESTION BANK
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

  struct Node {
      int data;
      Node* prev;
      Node* next;
      Node(int d) : data(d), prev(nullptr), next(nullptr) {}
  };

  ── CORE OPERATIONS & COMPLEXITIES ──────────────────────────────────────────

  Operation                    │ Time  │ Space │ Key Advantage over SLL
  ─────────────────────────────┼───────┼───────┼──────────────────────────────
  Insert at beginning          │ O(1)  │ O(1)  │ Same as SLL
  Insert at end                │ O(1)* │ O(1)  │ O(1) if tail pointer maintained
  Insert at position K         │ O(K)  │ O(1)  │ Can approach from either end
  Delete at beginning          │ O(1)  │ O(1)  │ No prev tracking needed
  Delete at end                │ O(1)* │ O(1)  │ Direct: tail=tail->prev
  Delete a given node          │ O(1)  │ O(1)  │ KEY WIN: no need to find prev
  Search                       │ O(N)  │ O(1)  │ Can search from either direction
  Reverse traversal            │ O(N)  │ O(1)  │ Impossible in SLL without stack
  Reverse the list             │ O(N)  │ O(1)  │ Swap prev/next for each node

  * O(1) only when tail pointer is maintained

  ── MUST-KNOW PATTERNS ──────────────────────────────────────────────────────

  1. ALWAYS UPDATE BOTH prev AND next:
     When inserting/deleting, set both directions or you corrupt the list.
     Insert between A and B:
       new->prev = A;  new->next = B;
       A->next = new;  B->prev = new;   // order matters!

  2. DUMMY HEAD + DUMMY TAIL (sentinel nodes):
     Eliminates all edge cases — no null checks for head/tail operations.
     Used in LRU Cache, deque implementations.

  3. DELETE A NODE IN O(1) (given only the node pointer):
     Unlike SLL where you need prev, DLL gives it for free:
       node->prev->next = node->next;
       if (node->next) node->next->prev = node->prev;
       delete node;

  4. REVERSE = SWAP prev AND next FOR EVERY NODE:
     while (curr) {
         swap(curr->prev, curr->next);
         curr = curr->prev;             // moved to what was "next"
     }
     head = last_node_visited;

  ── DLL vs SLL ──────────────────────────────────────────────────────────────

  DLL wins:  O(1) delete with node pointer, bidirectional traversal,
             O(1) insert/delete at tail with tail ptr, backward iteration
  SLL wins:  Half the memory (no prev pointer), simpler code, cache slightly better

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a doubly linked list? How is it different from a singly linked list?
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] What are the advantages and disadvantages of DLL over SLL?
         (Adv: O(1) delete with node ptr, bidirectional; Disadv: extra memory for prev)
         Asked at: Amazon, Microsoft, Flipkart

  [T][ ] What is the time complexity of deleting a node in DLL vs SLL when
         given only the node's pointer?
         (DLL: O(1) using prev pointer; SLL: O(N) to find previous node)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is std::list in C++? What is its internal implementation?
         (Doubly linked list; O(1) insert/erase at any iterator position)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is a sentinel/dummy node pattern? Why is it used in DLL?
         (Eliminates null checks for head/tail operations — simplifies code)
         Asked at: Amazon, Google, Adobe

  [T][ ] What is an XOR linked list? How does it save memory over DLL?
         (Store prev XOR next in one pointer field — half the pointer memory)
         Asked at: Samsung, advanced C++, competitive programming

  [T][ ] How would you implement an LRU Cache using DLL + HashMap?
         (HashMap for O(1) lookup; DLL for O(1) move-to-front and eviction)
         Asked at: Amazon, Microsoft, Google, Flipkart (VERY common!)

  [T][ ] How is DLL used internally by std::list::iterator?
         (Iterator wraps Node*; ++ calls next, -- calls prev — bidirectional)
         Asked at: Amazon, Microsoft, Google, C++ developer roles

  ★[T][ ] What is the Rule of Five for a DLL class with raw pointers?
           (Need: destructor, copy ctor, copy assign, move ctor, move assign)
           Asked at: Google, advanced C++ roles, Adobe

  ★[T][ ] What is the difference between std::list and std::deque in C++?
           (list: DLL, O(1) insert/delete anywhere, no random access;
            deque: chunked buffer, O(1) front/back, O(1) random access)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] In an LRU Cache with DLL + unordered_map, why do we store
           list::iterator (not Node*) in the map?
           (list::erase() requires an iterator; iterator IS the Node* under the hood
            but erasing is the clean interface — and iterators stay valid in DLL)
           Asked at: Amazon, Google, Microsoft

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── BASIC OPERATIONS ────────────────────────────────────────────────────────

  [C][ ] (E) Implement DLL: insert at front, end, and given position
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Implement DLL: delete from front, end, and by value
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Traverse a DLL forward and backward and print both
             Asked at: TCS, Wipro

  [C][ ] (E) Count the number of nodes in a DLL
             Asked at: TCS, Wipro

  [C][ ] (E) Search for an element in a DLL; return position from front
             AND position from back in a single traversal
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Delete a node given only its pointer in a DLL — O(1)
             (Use node->prev and node->next directly)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Find the middle of a DLL in one pass
             (Slow/fast pointer — same as SLL, just use ->next)
             Asked at: Amazon, TCS

  ★[C][ ] (E) Insert a node in a sorted DLL maintaining sorted order
              Asked at: TCS, Wipro, Infosys, Zoho

  ★[C][ ] (E) Remove all duplicate nodes from a sorted DLL
              (Keep one occurrence; update both prev and next links)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Check if a DLL is a palindrome
              (Use front and back pointers moving toward center)
              Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (E) Convert a given array into a DLL
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Find the maximum and minimum element in a DLL
              in a single traversal
              Asked at: TCS, Wipro, Capgemini

  ── REVERSAL ────────────────────────────────────────────────────────────────

  [C][ ] (E) Reverse a doubly linked list in-place
             For each node: swap prev and next pointers; update head
             Asked at: Amazon, Microsoft, TCS, Wipro

  ★[C][ ] (E) Print a DLL in reverse without actually reversing it
              (Use tail pointer and traverse backward via ->prev)
              Asked at: TCS, Wipro, Amazon

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── SORT & MERGE ────────────────────────────────────────────────────────────

  [C][ ] (M) Sort a DLL using merge sort — O(N log N) O(1) space
             Split at middle, sort halves, merge (must update prev pointers too)
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Merge two sorted DLLs into one sorted DLL
             Compare heads, link smaller (set both prev and next)
             Asked at: Amazon, Microsoft, TCS

  ★[C][ ] (M) Remove all nodes from DLL that have a greater node to their right
              (Same as SLL version but must also update prev pointers)
              Asked at: Amazon, Flipkart

  ── ROTATE & REARRANGE ──────────────────────────────────────────────────────

  ★[C][ ] (M) Rotate a DLL to the right by K positions
              Connect tail to head, find new tail, break at correct position
              Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (M) Swap adjacent nodes in a DLL (actual node swap, not value swap)
              1<->2<->3<->4 → 2<->1<->4<->3 (update 4 pointers per swap)
              Asked at: Amazon, Microsoft, Adobe

  ★[C][ ] (M) Rearrange a DLL so that all even-valued nodes come before odd-valued nodes
              (Maintain relative order; must update prev pointers)
              Asked at: Amazon, Flipkart, Zoho

  ── DEQUE USING DLL ─────────────────────────────────────────────────────────

  [C][ ] (M) Implement a double-ended queue (deque) from scratch using DLL
             pushFront, pushBack, popFront, popBack, front, back — all O(1)
             Asked at: Amazon, Persistent

  ★[C][ ] (M) Implement a stack using a DLL; then implement a queue using same DLL
              Both with O(1) push, pop, peek
              Asked at: TCS, Wipro, Amazon

  ── CACHE IMPLEMENTATIONS ───────────────────────────────────────────────────

  [C][ ] (M) Implement LRU Cache using DLL + unordered_map
             get(key): O(1) lookup + move accessed node to front
             put(key, val): O(1) insert at front; evict tail if capacity exceeded
             Asked at: Amazon, Google, Microsoft, Flipkart (VERY common!)

  [C][ ] (M) Implement LRU Cache — thread-safe version
             Use mutex for each get() and put() operation
             Asked at: Amazon, Google, Microsoft, Flipkart

  ★[C][ ] (M) Implement LFU (Least Frequently Used) Cache
              Two unordered_maps + DLL per frequency + min-frequency tracker
              get(key): O(1); put(key, val): O(1)
              Asked at: Amazon, Google, Facebook/Meta

  ── CONVERSION ──────────────────────────────────────────────────────────────

  [C][ ] (M) Flatten a multilevel doubly linked list
             Each node has next and child pointer; child leads to another DLL
             Flatten in-place: depth-first order, update all prev/next links
             Asked at: Amazon, Microsoft, Adobe, Facebook/Meta

  [C][ ] (M) Binary Tree to sorted DLL (in-place, no extra space)
             Left pointer = prev, right pointer = next
             Inorder traversal; maintain prev pointer across recursive calls
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Binary tree to doubly linked list (inorder)
             Asked at: Amazon, Microsoft, TCS

  ★[C][ ] (M) Convert a sorted DLL back into a height-balanced BST
              Find middle of DLL as root; recurse on left and right halves
              Asked at: Amazon, Microsoft

  ★[C][ ] (M) Given a DLL, partition it around value X:
              all nodes with data < X come before nodes with data >= X
              Maintain relative order; update all 4 pointers per moved node
              Asked at: Amazon, Microsoft

  ── MISCELLANEOUS ───────────────────────────────────────────────────────────

  ★[C][ ] (M) Given a sorted DLL and a target sum, find all pairs with the given sum
              Use front and back pointers; move inward like two-sum on sorted array
              Asked at: Amazon, Google, Flipkart

  ★[C][ ] (M) Given a sorted DLL, find all triplets with a given sum
              Fix one node, use two-pointer pair-sum on remaining DLL
              Asked at: Amazon, Google

  ★[C][ ] (M) Clone a DLL with a random pointer — O(N) time O(1) extra space
              (Interleaving trick extended to DLL — update prev pointers too)
              Asked at: Amazon, Microsoft, Google

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement a DLL that supports:
             O(1) insert at any iterator position, O(1) delete at any iterator,
             O(N) traversal, and operator[] with clear O(N) documentation
             Asked at: Dolat Capital, Persistent, Adobe

  ★[C][ ] (H) Implement a memory-efficient XOR doubly linked list
              Store only (prev XOR next) in each node
              Implement: insert_front, insert_back, traverse_forward, traverse_backward
              (Requires uintptr_t casting — show why it's unsafe in modern C++)
              Asked at: Samsung, advanced C++ roles, competitive programming

  ★[C][ ] (H) Implement a generic doubly linked list class in C++ with:
              templates, iterator support (begin/end, operator++, operator--),
              Rule-of-Five compliance, and exception safety
              Asked at: Google, Adobe, advanced C++ roles

  ★[C][ ] (H) Reverse a DLL in groups of K
              Reverse K nodes (updating both prev and next), recurse on rest
              e.g. 1<->2<->3<->4<->5, K=2 → 2<->1<->4<->3<->5
              Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (H) Find the length of the longest palindromic sublist in a DLL
              Use front and back pointers to compare from both ends
              Asked at: Google, competitive programming

  ★[C][ ] (H) Given a DLL where each node's data is a digit, add 1 to the number
              represented by the DLL (digits in order, most significant first)
              Handle carry propagation backward using prev pointers — O(N) O(1)
              Asked at: Amazon, Goldman Sachs, Paytm

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ──────────────────────────────────────────────────────────────────────────
  Delete given node                     node->prev->next = node->next; and back
  Reverse DLL                           Swap prev↔next for every node, update head
  Sort DLL                              Merge sort — update prev ptrs during merge
  Find middle                           Slow/fast pointer on ->next links
  Palindrome check                      Front and back pointers moving inward
  Two-sum on sorted DLL                 Front pointer from head, back from tail
  Insert into sorted DLL                Traverse until curr->data > val, rewire 4 ptrs
  LRU Cache                             DLL (order) + unordered_map (lookup)
  LFU Cache                             DLL per freq + min-freq tracker + map
  Flatten multilevel DLL                DFS: at each child, interleave child list
  Binary Tree → DLL                     Inorder traversal, track prev, link nodes
  Deque implementation                  DLL with dummy head + dummy tail sentinels

================================================================================
QUICK REFERENCE — Templates
================================================================================

  // Insert after a given node
  void insertAfter(Node* prev, int data) {
      Node* n = new Node(data);
      n->next = prev->next;
      n->prev = prev;
      if (prev->next) prev->next->prev = n;
      prev->next = n;
  }

  // Delete a given node (O(1) — DLL advantage)
  void deleteNode(Node*& head, Node* node) {
      if (!node) return;
      if (node == head) head = node->next;
      if (node->next) node->next->prev = node->prev;
      if (node->prev) node->prev->next = node->next;
      delete node;
  }

  // Reverse a DLL
  Node* reverseDLL(Node* head) {
      Node* curr = head, *temp = nullptr;
      while (curr) {
          swap(curr->prev, curr->next);
          temp = curr;
          curr = curr->prev;           // prev is what was next
      }
      return temp;                     // new head
  }

  // LRU Cache skeleton
  class LRUCache {
      int cap;
      list<pair<int,int>> dll;         // {key, val} — front = most recent
      unordered_map<int, list<pair<int,int>>::iterator> mp;
  public:
      LRUCache(int c) : cap(c) {}
      int get(int key) {
          if (!mp.count(key)) return -1;
          dll.splice(dll.begin(), dll, mp[key]);  // move to front O(1)
          return mp[key]->second;
      }
      void put(int key, int val) {
          if (mp.count(key)) dll.erase(mp[key]);
          dll.push_front({key, val});
          mp[key] = dll.begin();
          if ((int)dll.size() > cap) { mp.erase(dll.back().first); dll.pop_back(); }
      }
  };

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Concept (Quick Reference)  | 1 page — minimal, practical
  Theory (from files)        |  8 |  0 |  0 |     8
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   |  7 |  0 |  0 |     7
  Coding Easy (★ added)      |  7 |  0 |  0 |     7
  Coding Medium (from files) |  0 | 10 |  0 |    10
  Coding Medium (★ added)    |  0 | 11 |  0 |    11
  Coding Hard (from files)   |  0 |  0 |  1 |     1
  Coding Hard (★ added)      |  0 |  0 |  5 |     5
  ---------------------------|----|----|----|---------
  TOTAL                      | 25 | 21 |  6 |    52

================================================================================
END
================================================================================
