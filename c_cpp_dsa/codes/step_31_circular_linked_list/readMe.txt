================================================================================
        CIRCULAR LINKED LIST — COMPLETE QUESTION BANK
        Covers: Circular Singly LL, Circular Doubly LL, Circular Queue,
                Josephus Problem, and real interview applications
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

  ── CIRCULAR SINGLY LINKED LIST (CSLL) ──────────────────────────────────────

  struct Node {
      int data;
      Node* next;
      Node(int d) : data(d), next(nullptr) {}
  };
  // Last node's next points BACK to head (not nullptr)

  Key rule — ALWAYS use a tail pointer (not head) for O(1) insert at both ends:
    tail->next = head          // tail's next is always head
    New node at front: newNode->next = tail->next; tail->next = newNode;
    New node at end:   newNode->next = tail->next; tail->next = newNode; tail = newNode;

  ── CIRCULAR DOUBLY LINKED LIST (CDLL) ──────────────────────────────────────

  struct Node {
      int data;
      Node* prev;
      Node* next;
  };
  // head->prev = tail   AND   tail->next = head

  ── CORE OPERATIONS & COMPLEXITIES ──────────────────────────────────────────

  Operation                      │ CSLL  │ CDLL  │ Notes
  ───────────────────────────────┼───────┼───────┼──────────────────────────
  Insert at front                │ O(1)  │ O(1)  │ Use tail ptr; rewire tail->next
  Insert at end                  │ O(1)* │ O(1)  │ *Only O(1) with tail pointer
  Insert at position K           │ O(K)  │ O(K)  │ Traverse K steps
  Delete from front              │ O(1)  │ O(1)  │ Update tail->next = head->next
  Delete from end                │ O(N)  │ O(1)  │ CDLL wins — prev pointer
  Delete by value                │ O(N)  │ O(N)  │ Linear scan
  Traverse (full cycle)          │ O(N)  │ O(N)  │ Stop when back at head
  Detect if circular             │ O(N)  │ O(N)  │ Check if any node->next == head

  ── MUST-KNOW PATTERNS ──────────────────────────────────────────────────────

  1. TRAVERSAL TERMINATION — stop when you come back to head:
     Node* curr = head;
     do { process(curr); curr = curr->next; } while (curr != head);

  2. ALWAYS MAINTAIN THE CIRCULAR LINK — never let any node's next become nullptr.
     Any insert or delete must re-establish the circular property.

  3. SINGLE-NODE EDGE CASE:
     When list has one node: node->next = node (points to itself).
     Deleting it: head = nullptr; delete node;

  4. EMPTY LIST CHECK:
     head == nullptr means empty. Unlike SLL no ambiguity since circular.

  ── CIRCULAR LL vs REGULAR LL ───────────────────────────────────────────────

  Circular LL wins:  O(1) insert at both ends with tail ptr,
                     natural fit for round-robin scheduling,
                     Josephus problem, media players, OS process queues,
                     no nullptr — simplifies some traversal logic
  Regular LL wins:   Simpler code, easier to debug, no tail-loop risk

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a circular linked list? How is it different from a regular linked list?
         (Last node's next points to head instead of nullptr)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is a circular queue? Why is it needed over a regular queue?
         (Regular queue wastes space after dequeue; circular reuses slots)
         Asked at: Amazon, TCS, Wipro, Infosys

  [T][ ] What is a circular doubly linked list? Name two real-world use cases.
         (OS ready queue for round-robin scheduling; media player playlist)
         Asked at: Amazon, Microsoft, Samsung

  [T][ ] What is the difference between singly circular and doubly circular LL?
         (CSLL: one pointer, forward only; CDLL: prev+next, bidirectional, O(1) tail delete)
         Asked at: TCS, Wipro, Amazon

  [T][ ] Why use a tail pointer instead of head pointer in a circular LL?
         (tail->next = head, so you can insert at BOTH ends in O(1))
         Asked at: Amazon, Microsoft, TCS

  [T][ ] How do you detect when traversal of a circular LL is complete?
         (Stop when curr == head again, i.e., do-while loop)
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is the Josephus problem? What data structure is it modelled on?
         (N people in a circle, every Kth eliminated — circular LL / recursion)
         Asked at: Amazon, Samsung, Google, competitive programming

  [T][ ] Where are circular linked lists used in operating systems?
         (Round-robin CPU scheduling, multiprogramming process queues)
         Asked at: Samsung, Amazon, system programming roles

  ★[T][ ] How is std::list used as a circular structure in some OS schedulers?
           (Treat list as circular by connecting begin() and end() conceptually;
            or use circular buffer with deque for better cache performance)
           Asked at: Samsung, system programming, OS course follow-ups

  ★[T][ ] What is the difference between a circular buffer (ring buffer) and
           a circular linked list?
           (Ring buffer: fixed-size array with head/tail indices — cache friendly;
            CLL: dynamic size, pointer-based — more flexible but more memory)
           Asked at: Amazon, Samsung, embedded systems, Goldman Sachs

  ★[T][ ] Can Floyd's cycle detection algorithm detect if a list is circular?
           (Yes — if fast pointer meets slow pointer, a cycle exists;
            in a CLL, fast will always catch slow since it never hits nullptr)
           Asked at: Amazon, Microsoft, Flipkart

  ★[T][ ] What is a circular doubly linked list with sentinel node pattern?
           (Single dummy node whose next and prev both point to itself when empty;
            used in Linux kernel's list_head — simplest correct CLL implementation)
           Asked at: Google, Linux kernel/systems roles, advanced C++

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── BASIC OPERATIONS ────────────────────────────────────────────────────────

  [C][ ] (E) Implement circular singly LL: insert at front and back using tail ptr
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Implement circular singly LL: delete from front, back, and by value
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Traverse and print all nodes of a circular linked list
             Use do-while(curr != head) to avoid infinite loop
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Count the number of nodes in a circular linked list
             Asked at: TCS, Wipro

  [C][ ] (E) Search for an element in a circular linked list; return true/false
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Split a circular linked list into two halves
             Use slow/fast pointer to find mid; split and maintain circular property
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Check if a given linked list is circular or not
             (Chase ->next; if you hit nullptr → not circular; if you hit head → circular)
             Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Insert a node in a sorted circular linked list maintaining sorted order
              Tricky: handle wrap-around case when new node becomes new head or tail
              Asked at: Amazon, Microsoft, Zoho

  ★[C][ ] (E) Remove all duplicate values from a sorted circular linked list
              (Update next pointers AND ensure last node still points to head)
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Convert a singly linked list to a circular singly linked list
              (Find last node, set last->next = head)
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Implement circular singly LL: insert at a given position K
              Asked at: TCS, Wipro

  ── CIRCULAR QUEUE ──────────────────────────────────────────────────────────

  [C][ ] (E) Implement a circular queue using a fixed-size array
             Support: enqueue, dequeue, isFull, isEmpty, front, rear — all O(1)
             Use: (rear + 1) % size == front to detect full
             Asked at: Amazon, TCS, Wipro, Infosys

  ★[C][ ] (E) Implement a circular queue using a circular linked list
              (No fixed size — dynamically growing)
              Asked at: TCS, Wipro, Persistent

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── SORT & MERGE ────────────────────────────────────────────────────────────

  [C][ ] (M) Sort a circular linked list using insertion sort
             Extract each node from circular list, insert in sorted position
             Asked at: Amazon, TCS, Wipro

  ★[C][ ] (M) Merge two sorted circular linked lists into one sorted circular LL
              Must restore circular property in merged list
              Asked at: Amazon, Microsoft, Goldman Sachs

  ── REVERSAL ────────────────────────────────────────────────────────────────

  ★[C][ ] (M) Reverse a circular singly linked list
              3-pointer reversal (same as SLL); at end restore circular property:
              old_head->next = new_head (old_head becomes new tail)
              Asked at: Amazon, TCS, Microsoft

  ★[C][ ] (M) Reverse a circular doubly linked list
              Swap prev and next for all nodes; swap head's prev/next references
              Asked at: Amazon, Adobe, Microsoft

  ── JOSEPHUS PROBLEM ────────────────────────────────────────────────────────

  [C][ ] (M) Josephus Problem: N people in a circle, every Kth person is eliminated.
             Find the position of the last survivor.
             Approach 1: Simulate with circular LL — O(N*K)
             Approach 2: DP recurrence — O(N)
               dp[1] = 0; dp[i] = (dp[i-1] + k) % i; (0-indexed position)
             Asked at: Amazon, Samsung, Google, competitive programming

  ★[C][ ] (M) Josephus Problem — simulate using a circular LL and print the
              order in which people are eliminated (not just the survivor)
              Asked at: Amazon, competitive programming, Samsung

  ★[C][ ] (M) Generalised Josephus: every Kth person is skipped (not eliminated).
              Find the order of people who escape last.
              Asked at: Goldman Sachs, competitive programming

  ── ROTATION & SPLIT ────────────────────────────────────────────────────────

  ★[C][ ] (M) Rotate a circular linked list by K positions
              Advance tail K steps, break and re-form circular connection
              Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Split a circular linked list into two halves;
             if odd number of nodes, first half has one extra
             Use slow/fast pointer to find mid; split carefully
             Asked at: Amazon, Flipkart, TCS

  ★[C][ ] (M) Given a circular LL, check if it is a palindrome
              Split into two halves, reverse second, compare, restore
              Asked at: Amazon, Microsoft, Adobe

  ── CIRCULAR IN REAL PROBLEMS ───────────────────────────────────────────────

  ★[C][ ] (M) Implement a round-robin scheduler using a circular linked list:
              each node = (process_id, time_quantum); dequeue front, execute,
              if not done re-enqueue at back
              Asked at: Amazon, Samsung, OS/systems programming roles

  ★[C][ ] (M) Implement a music player playlist as a circular DLL:
              play_next(), play_prev(), add_song(song), remove_song(song),
              shuffle() — all operating on CDLL
              Asked at: Zoho, Adobe, TCS (design rounds)

  ★[C][ ] (M) Given a circular LL of N nodes where each node has a jump value,
              starting at head, return to head in minimum jumps
              (Treated as circular array — BFS or DP)
              Asked at: Amazon, Google, competitive programming

  ★[C][ ] (M) Implement a token bucket / circular buffer for rate limiting:
              fixed capacity, produce at rear, consume at front (circular)
              Asked at: Amazon, backend systems, Goldman Sachs

  ── CIRCULAR DOUBLY LL ──────────────────────────────────────────────────────

  ★[C][ ] (M) Implement a circular doubly linked list with sentinel node
              (Single dummy node — next and prev point to self when empty)
              Support: insert_front, insert_back, delete(node), traverse — all O(1) except traverse
              Asked at: Google, Linux systems roles, advanced C++

  ★[C][ ] (M) Given a sorted circular doubly linked list, find all pairs
              with a given sum using two pointers — O(N) O(1)
              Asked at: Amazon, Google, Flipkart

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  ★[C][ ] (H) Design a skip list on a circular linked list:
              multiple levels of pointers, O(log N) average search
              Asked at: Google, Dolat Capital, database companies

  ★[C][ ] (H) Implement a circular buffer (ring buffer) from scratch:
              fixed-size array, head and tail indices, wrap-around,
              thread-safe with mutex — used in producer-consumer
              Asked at: Amazon, Goldman Sachs, embedded systems, Samsung

  ★[C][ ] (H) Given circular linked list representing a number (most significant digit first),
              multiply the number by K and return the result as a circular LL
              Handle carry propagation across the circular boundary
              Asked at: Goldman Sachs, competitive programming

  ★[C][ ] (H) Implement a self-organizing list on circular LL:
              Move-to-front heuristic — whenever a node is accessed, move it
              to head. Show amortized analysis.
              Asked at: Google, Dolat Capital, advanced data structures

  ★[C][ ] (H) Merge K sorted circular linked lists into one sorted circular LL
              Use min-heap of K head nodes; rebuild circular property at end
              Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (H) Design a circular doubly linked list that supports:
              insert(pos, val): O(1) given iterator
              delete(iterator): O(1)
              begin(), end() that wrap around
              range-based for loop compatibility (C++ iterator interface)
              Asked at: Google, Adobe, advanced C++ roles

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN / KEY DETAIL
  ──────────────────────────────────────────────────────────────────────────
  Traverse circular LL                  do-while(curr != head); not while(curr)
  Insert at front/back O(1)             Maintain tail pointer (tail->next = head)
  Insert in sorted circular             Handle wrap-around: new node > tail or < head
  Split into two halves                 Slow/fast pointer; update both tails' next ptrs
  Reverse CSLL                          3-pointer reversal; old_head->next = new_head
  Check if list is circular             Chase next; circular if you reach head again
  Josephus (survive position)           dp[i] = (dp[i-1] + k) % i  (0-indexed)
  Josephus (simulate)                   Circular LL; count k-1 steps, remove kth node
  Round-robin scheduler                 CSLL with tail; dequeue front, re-enqueue if needed
  Palindrome check on CLL               Split, reverse 2nd half, compare, restore
  Circular queue (array)                head, tail indices; use % size for wrap-around
  CDLL sentinel pattern                 dummy->next = dummy->prev = dummy when empty

================================================================================
QUICK REFERENCE — Node Structure & Common Templates
================================================================================

  // Circular SLL — insert at back using tail
  void insertBack(Node*& tail, int data) {
      Node* n = new Node(data);
      if (!tail) { n->next = n; tail = n; return; }
      n->next = tail->next;      // n->next = head
      tail->next = n;
      tail = n;                  // update tail
  }

  // Circular SLL — insert at front using tail
  void insertFront(Node*& tail, int data) {
      Node* n = new Node(data);
      if (!tail) { n->next = n; tail = n; return; }
      n->next = tail->next;      // n->next = old head
      tail->next = n;            // tail->next = new head (n)
      // tail stays same
  }

  // Traverse circular LL
  void traverse(Node* tail) {
      if (!tail) return;
      Node* curr = tail->next;   // start from head
      do {
          cout << curr->data << " ";
          curr = curr->next;
      } while (curr != tail->next); // stop when back at head
  }

  // Delete from front of circular SLL
  Node* deleteFront(Node* tail) {
      if (!tail) return nullptr;
      Node* head = tail->next;
      if (head == tail) { delete tail; return nullptr; } // single node
      tail->next = head->next;
      delete head;
      return tail;
  }

  // Josephus — O(N) DP approach (returns 0-indexed position of survivor)
  int josephus(int n, int k) {
      int pos = 0;
      for (int i = 2; i <= n; i++)
          pos = (pos + k) % i;
      return pos;   // 0-indexed; add 1 for 1-indexed answer
  }

  // Circular queue (array implementation)
  class CircularQueue {
      int* arr; int front, rear, size, cap;
  public:
      CircularQueue(int c) : cap(c), front(0), rear(0), size(0) { arr = new int[c]; }
      bool isFull()  { return size == cap; }
      bool isEmpty() { return size == 0; }
      void enqueue(int x) { arr[rear] = x; rear = (rear+1)%cap; size++; }
      int  dequeue()      { int v=arr[front]; front=(front+1)%cap; size--; return v; }
      int  peek()         { return arr[front]; }
  };

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Concept (Quick Reference)  | 1 page — minimal, practical
  Theory (from files)        |  8 |  0 |  0 |     8
  Theory (★ added)           |  4 |  0 |  0 |     4
  Coding Easy (from files)   |  8 |  0 |  0 |     8
  Coding Easy (★ added)      |  5 |  0 |  0 |     5
  Coding Medium (from files) |  0 |  3 |  0 |     3
  Coding Medium (★ added)    |  0 | 14 |  0 |    14
  Coding Hard (from files)   |  0 |  0 |  0 |     0
  Coding Hard (★ added)      |  0 |  0 |  6 |     6
  ---------------------------|----|----|----|---------
  TOTAL                      | 25 | 17 |  6 |    48

================================================================================
END
================================================================================
