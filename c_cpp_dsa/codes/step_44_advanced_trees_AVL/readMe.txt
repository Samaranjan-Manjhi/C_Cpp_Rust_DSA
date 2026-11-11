================================================================================
        AVL TREE — COMPLETE QUESTION BANK
        Covers: Rotations, Balance Factor, Insert/Delete with Rebalancing,
                AVL vs Red-Black, Applications
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

  ── WHAT IS AN AVL TREE ──────────────────────────────────────────────────────
  A self-balancing BST where for every node:
    Balance Factor (BF) = height(left subtree) − height(right subtree)
    BF must be −1, 0, or +1 at all times.
  If any insertion or deletion causes |BF| > 1, one or more ROTATIONS restore balance.

  ── HEIGHT & BALANCE FACTOR ──────────────────────────────────────────────────
  height(null) = -1  (or 0 depending on convention — be consistent!)
  height(node) = 1 + max(height(left), height(right))
  BF(node)     = height(left) − height(right)
  BF > 0  → left-heavy;   BF < 0  → right-heavy

  ── 4 ROTATION CASES ─────────────────────────────────────────────────────────

  Case           │ Condition              │ Fix
  ───────────────┼────────────────────────┼─────────────────────────────
  LL (Left-Left) │ BF > 1 AND BF(left)≥0 │ Single Right Rotation at node
  RR (Right-Right│ BF <-1 AND BF(right)≤0│ Single Left Rotation at node
  LR (Left-Right)│ BF > 1 AND BF(left)< 0│ Left Rotate left child, then Right Rotate node
  RL (Right-Left)│ BF <-1 AND BF(right)>0│ Right Rotate right child, then Left Rotate node

  ── RIGHT ROTATION (fixes LL imbalance) ──────────────────────────────────────
      y                x
     / \              / \
    x   T3   →      T1   y
   / \                   / \
  T1  T2               T2  T3

  Node* rightRotate(Node* y) {
      Node* x  = y->left;
      Node* T2 = x->right;
      x->right = y;
      y->left  = T2;
      y->height = 1 + max(height(y->left), height(y->right));
      x->height = 1 + max(height(x->left), height(x->right));
      return x;  // x is new root
  }

  ── LEFT ROTATION (fixes RR imbalance) ───────────────────────────────────────
      x                y
     / \              / \
    T1   y    →      x   T3
        / \         / \
       T2  T3      T1  T2

  ── COMPLEXITIES ─────────────────────────────────────────────────────────────

  Operation    │ AVL Tree    │ Plain BST  │ Red-Black
  ─────────────┼─────────────┼────────────┼────────────────────────
  Search       │ O(log N)    │ O(N) worst │ O(log N)
  Insert       │ O(log N)    │ O(N) worst │ O(log N)
  Delete       │ O(log N)    │ O(N) worst │ O(log N)
  Height       │ ≤ 1.44 log N│ Up to N    │ ≤ 2 log(N+1)
  Rotations    │ ≤ 2 per op  │ N/A        │ ≤ 3 per insert
  Memory       │ Extra height│ None       │ Extra color bit

  ── AVL vs RED-BLACK ─────────────────────────────────────────────────────────
  AVL:         Stricter balance → faster SEARCH; more rotations on insert/delete
  Red-Black:   Looser balance → faster INSERT/DELETE; used in std::map, std::set
  Use AVL when: read-heavy workloads, database indexes
  Use Red-Black when: write-heavy workloads, language standard libraries

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is an AVL tree? What is a balance factor?
         (Self-balancing BST; BF = height(left)−height(right); must be −1, 0, or +1)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What are the 4 rotation cases in an AVL tree? When does each occur?
         (LL→right rotate; RR→left rotate; LR→left then right; RL→right then left)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is the time complexity of AVL tree operations?
         (O(log N) for search, insert, delete — height ≤ 1.44 log₂N)
         Asked at: Amazon, Microsoft, TCS, Goldman Sachs

  [T][ ] What is the difference between AVL tree and Red-Black tree?
         (AVL: strict balance, faster search; Red-Black: looser balance,
          faster insert/delete; std::map uses Red-Black)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] Why does AVL tree guarantee O(log N) while plain BST degrades to O(N)?
         (AVL enforces height ≤ 1.44 log N via rotations; plain BST with sorted
          input becomes a linked list of height N)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] What is a rotation in an AVL tree? Does it change the BST property?
         (Local restructuring of 3 nodes; BST inorder property is preserved)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] How many rotations are needed for insertion vs deletion in AVL tree?
         (Insert: at most 1 rotation (single or double); Delete: O(log N) rotations
          — may propagate all the way to root)
         Asked at: Google, Goldman Sachs, advanced algorithm roles

  ★[T][ ] What is the minimum number of nodes in an AVL tree of height H?
           (N(H) = N(H-1) + N(H-2) + 1 — same Fibonacci-like recurrence;
            N(H) ≈ 1.44 log(N+2) − 1)
           Asked at: Goldman Sachs, competitive programming, advanced roles

  ★[T][ ] When would you prefer a Treap over AVL tree?
           (Treap: BST + random heap priority — probabilistically balanced,
            simpler implementation, no rotations case analysis needed)
           Asked at: Google, Goldman Sachs, competitive programming

  ★[T][ ] What is a Splay tree? How does it differ from AVL?
           (Self-adjusting BST: recently accessed node moved to root via splaying;
            O(log N) amortized; better cache locality for skewed access patterns)
           Asked at: Google, advanced data structures roles

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Implement right rotation and left rotation for an AVL node
             Return new root after rotation; update heights
             Asked at: TCS, Amazon, Goldman Sachs

  [C][ ] (E) Compute the balance factor of each node in a given binary tree
             BF(node) = height(left) − height(right); use post-order DFS
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Check if a given binary tree is a valid AVL tree
             For every node verify |BF| ≤ 1; single DFS returning height
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Find the height of an AVL tree iteratively (BFS approach)
             Asked at: TCS, Wipro

  ★[C][ ] (E) Identify the type of rotation needed (LL/RR/LR/RL) for a given
              imbalanced 3-node subtree without implementing full AVL
              Asked at: TCS, Wipro, Samsung

  ★[C][ ] (E) Simulate a sequence of insertions into AVL tree step by step;
              show balance factors after each insertion and which rotation fires
              e.g. Insert 30, 20, 10 → LL → Right Rotate
              Asked at: TCS, Wipro, University exams

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Implement AVL tree insert with all 4 rotation cases
             After insert, update heights and check balance; apply rotation
             Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [C][ ] (M) Implement AVL tree delete with rebalancing
             Delete like BST (3 cases); then fix balance going back to root
             Asked at: Google, Goldman Sachs, advanced roles

  [C][ ] (M) Implement AVL tree search, inorder traversal, and height query
             Asked at: Amazon, TCS, Goldman Sachs

  ★[C][ ] (M) Implement an AVL tree that also supports floor() and ceil() queries
              in O(log N) (same as BST but guaranteed O(log N) height)
              Asked at: Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Implement an order-statistics AVL tree:
              each node stores subtree size; support kthSmallest(k) and rank(x) in O(log N)
              Asked at: Google, Goldman Sachs, Dolat Capital

  ★[C][ ] (M) Given a sequence of AVL insertions and deletions, output the tree
              after each operation (level-order BFS output for verification)
              Asked at: Samsung, Goldman Sachs, competitive programming

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  ★[C][ ] (H) Implement a complete AVL tree class with:
              insert, delete, search, kthSmallest, rank, floor, ceil
              All O(log N); Rule-of-Five compliant C++ class
              Asked at: Google, Goldman Sachs, Dolat Capital, HFT firms

  ★[C][ ] (H) Implement a Treap from scratch (BST + heap property on random priority)
              insert, delete — no rotation case analysis needed
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Merge two AVL trees of sizes M and N into one balanced AVL tree
              Approach: inorder both → merge sorted → build balanced AVL; O(M+N)
              Asked at: Google, Goldman Sachs

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  struct Node {
      int val, height;
      Node *left, *right;
      Node(int v) : val(v), height(1), left(nullptr), right(nullptr) {}
  };
  int h(Node* n) { return n ? n->height : 0; }
  int bf(Node* n) { return n ? h(n->left) - h(n->right) : 0; }
  void upd(Node* n) { if(n) n->height = 1 + max(h(n->left), h(n->right)); }

  Node* rightRotate(Node* y) {
      Node* x=y->left, *T2=x->right;
      x->right=y; y->left=T2;
      upd(y); upd(x); return x;
  }
  Node* leftRotate(Node* x) {
      Node* y=x->right, *T2=y->left;
      y->left=x; x->right=T2;
      upd(x); upd(y); return y;
  }
  Node* balance(Node* n) {
      upd(n);
      if(bf(n) > 1) {
          if(bf(n->left) < 0) n->left = leftRotate(n->left);   // LR
          return rightRotate(n);                                  // LL
      }
      if(bf(n) < -1) {
          if(bf(n->right) > 0) n->right = rightRotate(n->right); // RL
          return leftRotate(n);                                    // RR
      }
      return n;
  }
  Node* insert(Node* n, int val) {
      if(!n) return new Node(val);
      if(val < n->val) n->left  = insert(n->left,  val);
      else             n->right = insert(n->right, val);
      return balance(n);
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  7 |  0 |  0 |     7
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   |  4 |  0 |  0 |     4
  Coding Easy (★ added)      |  2 |  0 |  0 |     2
  Coding Medium (from files) |  0 |  3 |  0 |     3
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 |  0 |     0
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 16 |  6 |  3 |    25

================================================================================
END
================================================================================
