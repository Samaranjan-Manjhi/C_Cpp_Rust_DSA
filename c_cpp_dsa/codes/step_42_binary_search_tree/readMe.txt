================================================================================
        BINARY SEARCH TREE (BST) — COMPLETE QUESTION BANK
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

  struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  };

  ── BST PROPERTY ─────────────────────────────────────────────────────────────
  For every node N:
    • All values in LEFT subtree  < N.val
    • All values in RIGHT subtree > N.val
    • Both subtrees are also valid BSTs
    KEY: Inorder traversal of BST gives elements in SORTED (ascending) order.

  ── CORE OPERATIONS & COMPLEXITIES ──────────────────────────────────────────

  Operation        │ Average    │ Worst (skewed) │ Trick
  ─────────────────┼────────────┼────────────────┼─────────────────────────────
  Search           │ O(log N)   │ O(N)           │ Go left if val<node, right if >
  Insert           │ O(log N)   │ O(N)           │ Same as search; attach at null
  Delete           │ O(log N)   │ O(N)           │ 3 cases below
  Inorder (sorted) │ O(N)       │ O(N)           │ L → Root → R
  Min / Max        │ O(log N)   │ O(N)           │ Go leftmost / rightmost
  Floor / Ceil     │ O(log N)   │ O(N)           │ Track last valid node while searching
  Kth smallest     │ O(H + K)   │ O(N)           │ Inorder, stop at Kth
  LCA in BST       │ O(log N)   │ O(N)           │ No need for general LCA algorithm

  ── DELETE — 3 CASES ─────────────────────────────────────────────────────────
  Case 1: Node is a leaf           → simply delete it
  Case 2: Node has one child       → replace node with its child
  Case 3: Node has two children    → replace with INORDER SUCCESSOR (leftmost
          node in right subtree), then delete the successor from right subtree

  ── BALANCED BSTs ────────────────────────────────────────────────────────────
  AVL Tree      : |height(left) - height(right)| ≤ 1 at every node; strict balance
  Red-Black Tree: guarantees height ≤ 2 log(N+1); used by std::map, std::set
  Treap         : BST + heap property on random priorities; probabilistically balanced
  Splay Tree    : self-adjusting; recently accessed elements near root

  ── KEY BST IDENTITIES ───────────────────────────────────────────────────────
  • Inorder Predecessor of node N = rightmost node in left subtree of N
  • Inorder Successor   of node N = leftmost  node in right subtree of N
  • LCA in BST: if both p, q < root → go left; both > root → go right; else root is LCA
  • Validate BST: pass (min, max) bounds; left subtree gets max=node.val, right gets min=node.val

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a BST? What is its inorder property?
         (BST: left < node < right for all nodes; inorder gives sorted order)
         Asked at: TCS, Wipro, Infosys, Amazon, Microsoft

  [T][ ] What is the time complexity of BST operations? What is the worst case?
         (Average O(log N); worst case O(N) for skewed tree — sorted input)
         Asked at: Amazon, Microsoft, Google, TCS

  [T][ ] What is a balanced BST? Name examples.
         (AVL tree: strict |Δheight| ≤ 1; Red-Black: looser but O(log N) guaranteed)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is an AVL tree? What is a balance factor?
         (Balance factor = height(left) − height(right); must be −1, 0, or +1;
          rotations restore balance on insert/delete)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is a Red-Black tree? What properties does it maintain?
         (1. Nodes are red or black; 2. Root is black; 3. No two red nodes adjacent;
          4. Every path from root to null has same number of black nodes)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What does std::map use internally? What does std::set use?
         (Both use Red-Black tree — O(log N) for all operations; sorted keys)
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] What is the difference between BST and a heap?
         (BST: sorted L < root < R, efficient search; Heap: root is min/max,
          NOT searchable, only extract-min/max efficiently)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is the inorder predecessor and successor in a BST?
         (Predecessor: rightmost of left subtree; Successor: leftmost of right subtree)
         Asked at: Amazon, Microsoft, TCS, Wipro

  [T][ ] How do you validate a BST? What is the common mistake?
         (Wrong: only check if left < root < right for each node;
          Correct: pass (min, max) bounds down — left subtree max=root.val, right subtree min=root.val)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] How do you delete a node with two children from a BST?
         (Replace with inorder successor; delete successor from right subtree)
         Asked at: Amazon, Microsoft, Google, TCS

  [T][ ] What is the number of possible BSTs with N distinct keys?
         (Catalan number: C(N) = C(2N,N)/(N+1))
         Asked at: Amazon, Google, Goldman Sachs, competitive programming

  ★[T][ ] Why does inserting sorted data into a BST degrade performance?
           (Creates a skewed tree of height N — all operations become O(N);
            solution: use self-balancing BST like AVL or Red-Black)
           Asked at: Amazon, Microsoft, TCS, Wipro

  ★[T][ ] What is the difference between AVL tree and Red-Black tree?
           (AVL: strictly balanced, faster lookup; Red-Black: less strict,
            faster insert/delete; std::map uses Red-Black)
           Asked at: Google, Goldman Sachs, advanced roles

  ★[T][ ] How does the LCA algorithm differ between a general binary tree and a BST?
           (BST: O(H) — use BST property to navigate without storing visited nodes;
            General BT: O(N) — must explore both subtrees)
           Asked at: Amazon, Google, Microsoft

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Search for a value in a BST — iterative
             Go left if val < node.val, right if val > node.val
             Asked at: TCS, Wipro, Infosys, Amazon

  [C][ ] (E) Insert a new node into a BST — iterative (not recursive)
             Asked at: TCS, Amazon, Microsoft

  [C][ ] (E) Delete a node from a BST (handle all 3 cases)
             Asked at: TCS, Amazon, Microsoft

  [C][ ] (E) Find the minimum and maximum element in a BST
             (Min: go leftmost; Max: go rightmost)
             Asked at: TCS, Wipro, Amazon

  [C][ ] (E) Find the inorder predecessor of a given node in BST
             (Rightmost node of left subtree)
             Asked at: Amazon, Microsoft

  [C][ ] (E) Find the inorder successor of a given node in BST
             (Leftmost node of right subtree)
             Asked at: Amazon, Microsoft, TCS

  [C][ ] (E) Find the Kth largest element in a BST
             Reverse inorder (right → root → left); stop at Kth
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Count nodes in BST that lie in range [L, R] inclusive
             Asked at: Amazon, TCS

  [C][ ] (E) Find the LCA (Lowest Common Ancestor) in a BST
             If both < root → go left; both > root → go right; else root
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (E) Check if a binary tree can be a valid BST
             Pass (min, max) bounds recursively
             Asked at: Amazon, Microsoft, Zoho, TCS

  [C][ ] (E) Print all elements of BST in range [L, R] — inorder with pruning
             Asked at: Amazon, Adobe, Zoho

  [C][ ] (E) Convert a sorted array to a height-balanced BST
             (Mid of array is root; recurse on left and right halves)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Find the difference between sum of nodes at odd vs even level in BST
             Level order BFS with level counter
             Asked at: TCS, Wipro

  ★[C][ ] (E) Find the floor and ceil of a given key in a BST
              (Floor: largest value ≤ key; Ceil: smallest value ≥ key)
              Asked at: Amazon, Flipkart, TCS

  ★[C][ ] (E) Count the total number of nodes in a BST that are less than a given key
              Asked at: TCS, Amazon, Zoho

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── VALIDATE & REPAIR ────────────────────────────────────────────────────────

  [C][ ] (M) Validate Binary Search Tree
             Pass (long min, long max) bounds; avoid INT_MIN/MAX edge cases
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Recover BST — two nodes are swapped by mistake, fix the BST
             Inorder traversal; find two nodes that break sorted order
             (Adjacent violation: 1 pair; non-adjacent: 2 pairs)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Recover BST with O(1) space using Morris Inorder traversal
             Asked at: Google, Amazon

  ── SEARCH & RANGE ───────────────────────────────────────────────────────────

  [C][ ] (M) Kth smallest element in BST
             Inorder traversal — Kth node visited is the answer
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Find if two nodes in BST sum to K
             BFS/DFS + hash set; OR inorder array + two pointer; O(N) O(N)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Count pairs from two BSTs whose sum equals K
             Inorder of BST1 + reverse inorder of BST2 + two pointer
             Asked at: Amazon, Adobe, Flipkart

  [C][ ] (M) Return all values of BST in range [L, R] in sorted order
             Recursive DFS with pruning — skip left subtree if root > R; skip right if < L
             Asked at: Amazon, Microsoft

  [C][ ] (M) Find median of BST
             Count total nodes N; find ⌈N/2⌉th element via inorder traversal
             Asked at: Amazon, Adobe, Flipkart

  ── CONVERSION & CONSTRUCTION ────────────────────────────────────────────────

  [C][ ] (M) BST to sorted doubly linked list (in-place)
             Inorder traversal; left=prev, right=next; no extra space
             Asked at: Amazon, Microsoft

  [C][ ] (M) Convert BST to Greater Sum Tree
             Each node's value becomes sum of all nodes ≥ it
             Reverse inorder (right → root → left) with running sum
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Construct BST from preorder traversal — O(N)
             Upper bound trick: maintain valid range for each node
             Asked at: Amazon, Flipkart

  [C][ ] (M) Convert sorted linked list to height-balanced BST — O(N)
             Find middle of list as root; recurse on halves
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Given two BSTs, merge them into one balanced BST
             Inorder both → two sorted arrays → merge → build balanced BST
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Flatten BST to sorted linked list using only right pointers
             (Left pointer of every node set to null)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Trim a BST: remove all nodes with values outside [L, R]
             Recursive: if val < L prune left; if val > R prune right
             Asked at: Amazon, Microsoft

  ★[C][ ] (M) Given a BST, print all nodes that have no sibling
              (nodes whose parent has only one child)
              Asked at: Amazon, Flipkart

  ★[C][ ] (M) Find the largest BST subtree in a binary tree
              Post-order DFS returning (isBST, min, max, size); O(N)
              Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (M) Build a BST from level-order traversal
              For each value, find correct position using BST property
              Asked at: Amazon, Microsoft, TCS

  ★[C][ ] (M) Find the vertical sum of a BST
              BFS with horizontal distance tracking
              Asked at: Amazon, Flipkart, Adobe

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Design a data structure with insert, delete, getMedian in O(log N)
             Two BSTs (or order-statistics tree augmented with subtree sizes)
             Asked at: Google, Goldman Sachs, Amazon

  [C][ ] (H) Count number of structurally unique BSTs possible with N keys
             Catalan number via DP: dp[n] = Σ dp[i-1] × dp[n-i] for i=1..n
             dp[0]=1, dp[1]=1; answer = dp[N]
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Given BST, find maximum difference between any two nodes in an
             ancestor-descendant relationship
             DFS; track max and min seen on path from root
             Asked at: Amazon, Google

  [C][ ] (H) Serialize and deserialize a BST (more compact than general BT)
             Only preorder needed (BST property allows reconstruction without inorder)
             Asked at: Amazon, Google, Microsoft

  ★[C][ ] (H) Implement an Order-Statistics Tree supporting:
              insert(x), delete(x), kthSmallest(k), countLessThan(x) — all O(log N)
              Augment BST with subtree sizes
              Asked at: Google, Goldman Sachs, Dolat Capital

  ★[C][ ] (H) Given a BST with N nodes, find two nodes such that swapping their
              values makes the tree invalid with minimum disruption — verify with
              re-validation
              Asked at: Google, Goldman Sachs

  ★[C][ ] (H) Implement a balanced BST (AVL tree) from scratch:
              insert with rotations (LL, LR, RL, RR), delete with rebalancing
              Asked at: Google, Goldman Sachs, competitive programming

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN
  ─────────────────────────────────────────────────────────────────────────
  Search / Insert / Delete              Navigate left (<) or right (>)
  Validate BST                          Pass (min, max) bounds recursively
  Inorder = sorted output               L → Root → R traversal
  Kth smallest                          Inorder; count down to K
  Kth largest                           Reverse inorder; count down to K
  LCA in BST                            Both < root → left; both > → right; else root
  Floor / Ceil                          Track last valid answer while navigating
  Range query [L, R]                    DFS with pruning on BST property
  Recover BST (2 swapped nodes)         Inorder; find 1 or 2 violations
  Convert sorted array/list to BST      Mid as root; recurse halves
  Merge two BSTs                        Inorder both → merge sorted → build
  Greater Sum Tree                      Reverse inorder with running sum
  Count unique BSTs with N keys         Catalan number DP

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Insert into BST (iterative)
  TreeNode* insert(TreeNode* root, int val) {
      TreeNode* node = new TreeNode(val);
      if (!root) return node;
      TreeNode* curr = root, *par = nullptr;
      while (curr) { par = curr; curr = (val < curr->val) ? curr->left : curr->right; }
      if (val < par->val) par->left = node; else par->right = node;
      return root;
  }

  // Validate BST
  bool isValid(TreeNode* r, long lo = LONG_MIN, long hi = LONG_MAX) {
      if (!r) return true;
      if (r->val <= lo || r->val >= hi) return false;
      return isValid(r->left, lo, r->val) && isValid(r->right, r->val, hi);
  }

  // Kth smallest (inorder count)
  int kth = k, ans;
  void kthSmallest(TreeNode* r) {
      if (!r) return;
      kthSmallest(r->left);
      if (--kth == 0) { ans = r->val; return; }
      kthSmallest(r->right);
  }

  // LCA in BST
  TreeNode* lcaBST(TreeNode* root, int p, int q) {
      while (root) {
          if (p < root->val && q < root->val) root = root->left;
          else if (p > root->val && q > root->val) root = root->right;
          else return root;
      }
      return nullptr;
  }

  // Sorted array to balanced BST
  TreeNode* sortedArrayToBST(vector<int>& a, int lo, int hi) {
      if (lo > hi) return nullptr;
      int mid = lo + (hi - lo) / 2;
      auto root = new TreeNode(a[mid]);
      root->left  = sortedArrayToBST(a, lo, mid - 1);
      root->right = sortedArrayToBST(a, mid + 1, hi);
      return root;
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 11 |  0 |  0 |    11
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   | 13 |  0 |  0 |    13
  Coding Easy (★ added)      |  2 |  0 |  0 |     2
  Coding Medium (from files) |  0 | 14 |  0 |    14
  Coding Medium (★ added)    |  0 |  4 |  0 |     4
  Coding Hard (from files)   |  0 |  0 |  4 |     4
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 29 | 18 |  7 |    54

================================================================================
END
================================================================================
