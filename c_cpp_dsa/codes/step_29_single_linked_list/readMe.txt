================================================================================
        SINGLY LINKED LIST — COMPLETE QUESTION BANK
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
      Node* next;
      Node(int d) : data(d), next(nullptr) {}
  };

  ── CORE OPERATIONS & COMPLEXITIES ──────────────────────────────────────────

  Operation                    │ Time    │ Space │ Key Trick
  ─────────────────────────────┼─────────┼───────┼──────────────────────────
  Insert at beginning          │ O(1)    │ O(1)  │ new->next = head; head = new
  Insert at end                │ O(N)    │ O(1)  │ traverse to last node
  Insert at position K         │ O(K)    │ O(1)  │ stop at K-1, rewire
  Delete from beginning        │ O(1)    │ O(1)  │ head = head->next; delete old
  Delete from end              │ O(N)    │ O(1)  │ stop at second-last
  Delete by value              │ O(N)    │ O(1)  │ prev->next = curr->next
  Search                       │ O(N)    │ O(1)  │ linear scan
  Access by index              │ O(N)    │ O(1)  │ no random access
  Reverse                      │ O(N)    │ O(1)  │ 3-pointer technique
  Find middle                  │ O(N)    │ O(1)  │ slow/fast pointer
  Detect cycle                 │ O(N)    │ O(1)  │ Floyd's algorithm

  ── MUST-KNOW PATTERNS ──────────────────────────────────────────────────────

  1. TWO POINTER (slow + fast):
     Used for: middle, Nth from end, cycle detection, palindrome check
     slow moves 1 step, fast moves 2 steps each iteration

  2. THREE POINTER (prev, curr, next):
     Used for: reversal, deletion, insertion at middle
     Always save next before breaking link: next = curr->next

  3. DUMMY HEAD NODE:
     Use a dummy/sentinel node to simplify edge cases (empty list, head deletion)
     Node* dummy = new Node(0); dummy->next = head;
     Return dummy->next as new head

  4. RUNNER TECHNIQUE:
     Advance one pointer N steps ahead; move both together
     When fast hits end, slow is at the target

  ── LINKED LIST vs ARRAY ────────────────────────────────────────────────────

  Linked List wins: O(1) insert/delete at head, dynamic size, no contiguous memory
  Array wins:       O(1) random access, cache-friendly, binary search possible

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a linked list? How is it different from an array?
         Asked at: Amazon, TCS, Wipro, Infosys, Zoho

  [T][ ] What are the advantages and disadvantages of linked list over array?
         Asked at: Amazon, Microsoft, Flipkart, TCS

  [T][ ] What is the time complexity of insertion/deletion at beginning, end, middle?
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] What is Floyd's cycle detection algorithm? How does it work?
         (Slow moves 1, fast moves 2; they meet if cycle exists)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] When would you prefer linked list over array? When array over linked list?
         Asked at: Amazon, Microsoft, Flipkart, Zoho

  [T][ ] What is XOR linked list? What problem does it solve?
         (Store prev XOR next — halves pointer storage to one pointer per node)
         Asked at: Samsung, advanced C++, competitive programming

  [T][ ] What is an unrolled linked list? What are its advantages?
         (Array of nodes in each list node — better cache performance than SLL)
         Asked at: Google, Dolat Capital, cache-optimized systems

  [T][ ] How does std::list differ from std::forward_list in C++?
         (list = doubly linked; forward_list = singly linked, less memory)
         Asked at: Amazon, Microsoft, C++ developer roles

  ★[T][ ] What is the difference between shallow copy and deep copy for a linked list?
           (Shallow: copy pointers only — shared nodes; Deep: copy every node)
           Asked at: Amazon, Adobe, Persistent

  ★[T][ ] Why is cache performance worse for linked lists compared to arrays?
           (Nodes scattered in memory — no spatial locality; pointer chasing causes
            cache misses at every step)
           Asked at: Google, Goldman Sachs, Dolat Capital, HFT roles

  ★[T][ ] How do you find the middle of a linked list in one pass without
           knowing its length?
           (Slow/fast pointer — when fast reaches end, slow is at middle)
           Asked at: Amazon, Microsoft, Flipkart, Zoho

  ★[T][ ] What happens when you delete the only node in a linked list?
           (Head becomes nullptr; must handle this edge case explicitly)
           Asked at: TCS, Wipro, Infosys

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── BASIC OPERATIONS ────────────────────────────────────────────────────────

  [C][ ] (E) Insert a node at the beginning of a singly linked list
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Insert a node at the end of a singly linked list
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Insert a node at position K in a linked list
             Asked at: TCS, Wipro

  [C][ ] (E) Delete the first node of a linked list
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Delete the last node of a linked list
             Asked at: TCS, Wipro

  [C][ ] (E) Delete a node given only that node's pointer (not head)
             Trick: copy next node's data into current, delete next node
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Count the number of nodes in a linked list
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Search for an element in linked list — return position (1-indexed)
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Print linked list in reverse WITHOUT reversing it
             Hint: recursion or stack
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Concatenate two linked lists (append second to end of first)
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Check if two linked lists are equal (same data and length)
             Asked at: TCS, Wipro, Cognizant

  [C][ ] (E) Given linked list, return it as a vector and vice versa
             Asked at: TCS, Wipro (warm-up)

  ── REVERSAL ────────────────────────────────────────────────────────────────

  [C][ ] (E) Reverse a singly linked list — ITERATIVE (3-pointer technique)
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe, Paytm, Goldman Sachs
             Pattern:
               prev=null, curr=head
               while curr: next=curr->next; curr->next=prev; prev=curr; curr=next
               head = prev

  [C][ ] (E) Reverse a singly linked list — RECURSIVE
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  ★[C][ ] (E) Reverse a linked list using a stack (extra space approach)
              Asked at: TCS, Wipro, Infosys

  ── SLOW/FAST POINTER ───────────────────────────────────────────────────────

  [C][ ] (E) Find the middle element of a linked list (single pass, no length)
             slow/fast pointer — when fast hits null, slow is at middle
             Asked at: Amazon, Microsoft, Flipkart, Zoho

  [C][ ] (E) Find Nth node from end of list in single pass (two pointers)
             Advance first pointer N steps, then move both until first hits null
             Asked at: Amazon, Microsoft, Adobe, Zoho

  ── MODIFICATION & CLEANUP ──────────────────────────────────────────────────

  [C][ ] (E) Remove duplicates from SORTED linked list (keep one)
             Asked at: Amazon, Microsoft, TCS, Wipro

  [C][ ] (E) Remove all occurrences of a given value X from linked list
             Handle: head nodes, middle nodes, consecutive duplicates
             Asked at: Amazon, Flipkart, Zoho, TCS

  [C][ ] (E) Delete all occurrences of a given value (handle head + multiple)
             Asked at: Amazon, Zoho, TCS

  [C][ ] (E) Check if a linked list is empty and return head value safely
             Asked at: TCS, Wipro

  ★[C][ ] (E) Find the maximum and minimum element in a linked list
              Asked at: TCS, Wipro, Infosys, Capgemini

  ★[C][ ] (E) Check if a linked list contains a cycle (just true/false)
              before learning Floyd's — use a HashSet of visited addresses
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Remove all duplicate values from an UNSORTED linked list
              using a HashSet to track seen values
              Asked at: Amazon, TCS, Wipro

  ★[C][ ] (E) Given a sorted linked list, insert a new value maintaining sorted order
              Asked at: TCS, Wipro, Infosys, Zoho

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── CYCLE DETECTION ─────────────────────────────────────────────────────────

  [C][ ] (M) Detect cycle in linked list — Floyd's algorithm
             slow moves 1, fast moves 2; if they meet, cycle exists
             Asked at: Amazon, Microsoft, Google, Flipkart, Paytm

  [C][ ] (M) Find the starting node of the cycle in a linked list
             After detection: reset one pointer to head, move both 1 step —
             they meet at cycle start (Floyd + math)
             Asked at: Amazon, Google, Microsoft

  ── MERGE & SORT ────────────────────────────────────────────────────────────

  [C][ ] (M) Merge two sorted linked lists into one sorted list
             Iterative + Recursive
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) Sort a linked list using merge sort — O(N log N) O(1) space
             Split at middle (slow/fast), sort halves, merge
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (M) Sort a linked list of 0s, 1s, and 2s without changing node data
             Three dummy heads technique; re-link at end
             Asked at: Amazon, Flipkart, Paytm

  ── REVERSAL VARIANTS ───────────────────────────────────────────────────────

  [C][ ] (M) Reverse linked list in groups of K
             Reverse K nodes, recurse on rest, connect
             e.g. 1->2->3->4->5, K=2 → 2->1->4->3->5
             Asked at: Amazon, Microsoft, Google, Flipkart, Zoho

  [C][ ] (M) Reverse every alternate K nodes in a linked list
             Reverse K, skip K, repeat
             Asked at: Amazon, Flipkart

  ── INTERSECTION & PALINDROME ───────────────────────────────────────────────

  [C][ ] (M) Find intersection point of two linked lists (Y-shaped)
             Approach: equalize lengths, move together; OR end-to-start pointer swap
             Asked at: Amazon, Microsoft, Adobe, Flipkart, Goldman Sachs

  [C][ ] (M) Check if a linked list is a palindrome
             Naive: use stack or array. Optimal: reverse second half, compare, restore
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (M) Find if linked list has a palindrome — O(1) extra space
             Reverse second half in-place, compare, reverse back to restore
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  ── ADDITION & MATH ─────────────────────────────────────────────────────────

  [C][ ] (M) Add two numbers represented as linked lists (digits in REVERSE order)
             Most significant digit at end. Simulate addition with carry.
             e.g. 2->4->3 + 5->6->4 = 7->0->8  (342 + 465 = 807)
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Add two numbers where digits are in FORWARD order (not reversed)
             Use recursion to reach end; add from last digit forward
             Asked at: Amazon, Microsoft

  ── REARRANGEMENT ───────────────────────────────────────────────────────────

  [C][ ] (M) Odd-Even Linked List: group all odd-indexed nodes first, then even
             (Odd/even refers to node position, not value)
             e.g. 1->2->3->4->5 → 1->3->5->2->4
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Segregate even and odd VALUED nodes — evens first, odds after
             Maintain relative order within each group
             Asked at: Amazon, Flipkart

  [C][ ] (M) Partition linked list around value X (all < X before >= X, maintain order)
             Two pointer / dummy head approach
             Asked at: Amazon, Microsoft

  [C][ ] (M) Reorder linked list: L0->Ln-1->L1->Ln-2->L2->Ln-3...
             Find middle, reverse second half, merge alternately
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Remove all nodes that have a greater node to their right
             e.g. 5->2->13->3->8 → 13->8
             Reverse, keep track of max, reverse back; or monotonic approach
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Rotate linked list to the right by K places
             Connect tail to head (make circular), find new tail, break
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Rotate linked list to the LEFT by K positions
             Asked at: Amazon, Flipkart

  ── CLONE & COPY ────────────────────────────────────────────────────────────

  [C][ ] (M) Clone linked list with random pointer (hashmap approach — O(N) space)
             Map original node → cloned node; set next and random from map
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Clone linked list with random pointer — O(1) extra space
             Interleaving trick: weave clones between originals, then separate
             Asked at: Amazon, Microsoft, Google, Facebook/Meta

  ── SPLIT & FLATTEN ─────────────────────────────────────────────────────────

  [C][ ] (M) Split linked list into K parts as evenly as possible
             Longer parts come first; extra nodes distributed to first (N%K) parts
             Asked at: Amazon, Google

  [C][ ] (M) Given sorted linked list and value X, split into two:
             one with elements < X, one with elements >= X
             Asked at: Amazon, Microsoft

  [C][ ] (M) Flatten a linked list with a 'down' pointer (each node has a vertical list)
             Recursively merge sorted down-lists level by level
             Asked at: Amazon, Flipkart, Paytm, Adobe

  [C][ ] (M) Convert binary number represented as linked list to decimal
             e.g. 1->0->1 = 5
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given two linked lists representing polynomials, add them
             Each node: (coefficient, exponent); match exponents, sum coefficients
             Asked at: Goldman Sachs, Zoho

  ★[C][ ] (M) Given a linked list, find the length of the longest palindrome
              subsequence in the list
              Asked at: Google, Amazon

  ★[C][ ] (M) Given linked list where each node stores a digit,
              multiply number by 2 and return result as linked list
              Asked at: Amazon, Adobe, Paytm

  ★[C][ ] (M) Check if a linked list is a subset of another linked list
              (all nodes of first appear in second in same relative order)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (M) Given linked list, move last node to front
              Asked at: TCS, Wipro, Zoho, Amazon

  ★[C][ ] (M) Swap two nodes (not values) at given positions i and j
              (Must swap actual nodes by rewiring pointers)
              Asked at: Amazon, Microsoft, Adobe

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Merge K sorted linked lists
             Approach 1: priority_queue/min-heap — O(N log K)
             Approach 2: Divide and conquer — pair-wise merge — O(N log K)
             Asked at: Amazon, Google, Microsoft, Goldman Sachs, Flipkart

  [C][ ] (H) Reverse nodes in K groups (K-group reversal)
             Reverse first K nodes, recurse on rest, connect tail to result
             Must handle last group (may have fewer than K nodes — leave as-is)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Reverse linked list from position M to N in single pass
             Count to M-1, reverse (N-M+1) nodes, reconnect
             Asked at: Amazon, Microsoft

  [C][ ] (H) Delete all nodes that have DUPLICATE values (keep NONE)
             e.g. 1->2->2->3->3->4 → 1->4
             Use dummy head; detect duplicate group, skip entire group
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Design a skip list from scratch
             Layered linked list — O(log N) avg search; show insert + search
             Asked at: Google, Dolat Capital, database companies, Atlassian

  [C][ ] (H) Implement LRU Cache using linked list + hashmap
             get(key) O(1), put(key, value) O(1)
             Doubly linked list + unordered_map<key, list::iterator>
             Asked at: Amazon, Google, Microsoft, Flipkart (VERY common!)

  [C][ ] (H) Rearrange linked list: all nodes with value <= X come first,
             then == X, then > X; maintain relative order (stable partition)
             Asked at: Amazon, Microsoft

  [C][ ] (H) Multiply two numbers represented as linked lists (digits in order)
             e.g. 9->4->6 × 8->0->7 → result as linked list
             Asked at: Goldman Sachs, competitive programming

  ★[C][ ] (H) Flatten a multilevel doubly linked list
              Each node may have a child pointer leading to another linked list
              Flatten into one level DLL in depth-first order
              Asked at: Amazon, Microsoft, Adobe, Facebook/Meta

  ★[C][ ] (H) Given linked list, reverse alternate K nodes while keeping
              the rest in original order
              e.g. K=2: 1->2->3->4->5->6 → 2->1->3->4->6->5
              Asked at: Amazon, Flipkart, competitive programming

  ★[C][ ] (H) Detect and REMOVE a cycle from a linked list
              After Floyd's detection: find start, then break the cycle
              Asked at: Amazon, Google, Microsoft, Paytm

  ★[C][ ] (H) Given two sorted linked lists, find their union and intersection
              as two separate linked lists (no extra space for data, only pointers)
              Asked at: Amazon, TCS, Microsoft

  ★[C][ ] (H) Given a linked list of N nodes, construct a new linked list
              where each node contains the NEXT GREATER element from the original list
              (like Next Greater Element but on a linked list)
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (H) Sort a linked list using in-place merge sort without any extra array —
              demonstrate that the algorithm truly uses O(1) extra space
              Asked at: Amazon, Microsoft, Flipkart (follow-up: prove O(1) space)

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / TECHNIQUE
  ──────────────────────────────────────────────────────────────────────────
  Find middle                           Slow/fast pointer
  Nth from end                          Two pointers N apart (runner technique)
  Detect cycle                          Floyd's: slow × 1, fast × 2
  Find cycle start                      Floyd's + reset one pointer to head
  Reverse list                          3 pointers: prev, curr, next
  Reverse in groups / K-group           Recursive reversal with reconnect
  Palindrome check                      Reverse 2nd half, compare, restore
  Merge two sorted lists                Compare heads, link smaller, recurse/iterate
  Merge K sorted lists                  Min-heap / divide & conquer
  Sort linked list                      Merge sort (O(N log N) O(1) space)
  Clone with random pointer             Interleaving trick (O(1) space)
  Intersection of two lists             Equalize lengths or end-to-start swap
  Add two numbers                       Simulate with carry; reverse if digits in order
  LRU Cache                             Doubly linked list + hash map
  Flatten nested list                   DFS-style: recurse into child pointer
  Cycle removal                         Floyd's + pointer-to-last-cycle-node
  Delete given only node pointer        Copy next data, delete next node
  Edge case: single node / empty list   Always use dummy head node

================================================================================
QUICK REFERENCE — Node Structure & Common Templates
================================================================================

  struct Node {
      int data;
      Node* next;
      Node(int d) : data(d), next(nullptr) {}
  };

  // Traverse
  void print(Node* head) {
      while (head) { cout << head->data << " "; head = head->next; }
  }

  // Iterative reverse
  Node* reverse(Node* head) {
      Node *prev = nullptr, *curr = head, *next = nullptr;
      while (curr) { next = curr->next; curr->next = prev; prev = curr; curr = next; }
      return prev;
  }

  // Find middle (slow/fast)
  Node* middle(Node* head) {
      Node *slow = head, *fast = head;
      while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
      return slow;
  }

  // Detect cycle (Floyd's)
  bool hasCycle(Node* head) {
      Node *slow = head, *fast = head;
      while (fast && fast->next) {
          slow = slow->next; fast = fast->next->next;
          if (slow == fast) return true;
      }
      return false;
  }

  // Merge two sorted lists
  Node* merge(Node* a, Node* b) {
      if (!a) return b;
      if (!b) return a;
      if (a->data <= b->data) { a->next = merge(a->next, b); return a; }
      else                    { b->next = merge(a, b->next); return b; }
  }

  // Dummy head — eliminates head-deletion edge case
  Node* removeVal(Node* head, int val) {
      Node dummy(0); dummy.next = head;
      Node* prev = &dummy;
      while (prev->next) {
          if (prev->next->data == val) {
              Node* del = prev->next;
              prev->next = del->next;
              delete del;
          } else prev = prev->next;
      }
      return dummy.next;
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  8 |  0 |  0 |     8
  Theory (★ added)           |  4 |  0 |  0 |     4
  Coding Easy (from files)   | 22 |  0 |  0 |    22
  Coding Easy (★ added)      |  6 |  0 |  0 |     6
  Coding Medium (from files) |  0 | 29 |  0 |    29
  Coding Medium (★ added)    |  0 |  5 |  0 |     5
  Coding Hard (from files)   |  0 |  0 |  8 |     8
  Coding Hard (★ added)      |  0 |  0 |  6 |     6
  ---------------------------|----|----|----|---------
  TOTAL                      | 40 | 34 | 14 |    88

================================================================================
END
================================================================================
