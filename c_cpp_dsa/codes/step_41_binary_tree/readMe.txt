================================================================================
        BINARY TREE — BASICS & TRAVERSALS COMPLETE QUESTION BANK
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

  ── TREE TYPES ───────────────────────────────────────────────────────────────

  Full Binary Tree    : Every node has 0 or 2 children
  Complete BT         : All levels full except possibly last; last fills left to right
  Perfect BT          : All internal nodes have 2 children; all leaves at same level
  Balanced BT         : Height of left and right subtree differ by at most 1 for every node
  Degenerate/Skewed   : Every node has only 1 child → degenerates to linked list

  ── TRAVERSALS ───────────────────────────────────────────────────────────────

  Inorder   (L → Root → R) : gives SORTED order for BST
  Preorder  (Root → L → R) : used to SERIALIZE / COPY a tree; root always first
  Postorder (L → R → Root) : used to DELETE a tree; root always last
  Level-order (BFS)         : processes nodes level by level using a queue

  ── COMPLEXITY TABLE ─────────────────────────────────────────────────────────

  Operation          │ Time   │ Space
  ───────────────────┼────────┼──────────────────────────────────────────────
  Any traversal      │ O(N)   │ O(H) recursion stack; O(N) worst if skewed
  BFS (level-order)  │ O(N)   │ O(W) where W = max width (up to N/2)
  Height / Depth     │ O(N)   │ O(H)
  Morris Traversal   │ O(N)   │ O(1) — modifies tree temporarily, restores

  ── MUST-KNOW PATTERNS ───────────────────────────────────────────────────────

  1. RECURSIVE DFS SKELETON:
     int solve(TreeNode* root) {
         if (!root) return BASE_CASE;
         int left  = solve(root->left);
         int right = solve(root->right);
         return COMBINE(left, right, root->val);
     }

  2. ITERATIVE INORDER (stack):
     stack<TreeNode*> st; auto curr = root;
     while (curr || !st.empty()) {
         while (curr) { st.push(curr); curr = curr->left; }
         curr = st.top(); st.pop(); visit(curr);
         curr = curr->right;
     }

  3. BFS / LEVEL-ORDER:
     queue<TreeNode*> q; q.push(root);
     while (!q.empty()) {
         int sz = q.size();              // process one level
         while (sz--) {
             auto node = q.front(); q.pop(); visit(node);
             if (node->left)  q.push(node->left);
             if (node->right) q.push(node->right);
         }
     }

  4. GLOBAL ANSWER PATTERN (diameter, max path sum):
     int ans = 0;  // or INT_MIN
     int dfs(TreeNode* root) {
         if (!root) return 0;
         int L = dfs(root->left), R = dfs(root->right);
         ans = max(ans, L + R + root->val);   // update global answer
         return max(L, R) + root->val;         // return best single path upward
     }

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a binary tree? What are its properties?
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is the difference between full, complete, perfect, and balanced binary tree?
         Asked at: Amazon, Microsoft, TCS, Wipro, Google

  [T][ ] Explain all 4 traversals (inorder, preorder, postorder, level-order) with examples.
         Asked at: Amazon, TCS, Wipro, Microsoft, Infosys

  [T][ ] What is the time and space complexity of each traversal?
         (Time O(N) for all; Space O(H) for DFS; O(W) for BFS where W=max width)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] What is the difference between BFS and DFS on trees? When to use which?
         (BFS: level-order, shortest path, complete tree property;
          DFS: path problems, subtree problems, serialization)
         Asked at: Amazon, Microsoft, Flipkart, Zoho

  [T][ ] What is LCA (Lowest Common Ancestor)? How do you find it?
         (Deepest node that is ancestor of both given nodes;
          DFS: if both nodes are in different subtrees of a node, that node is LCA)
         Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [T][ ] What is the height vs depth of a binary tree?
         (Height: edges from node to deepest leaf; Depth: edges from root to node)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is Morris traversal? What is its advantage?
         (Uses threading — modifies tree temporarily then restores; O(1) space O(N) time)
         Asked at: Google, Amazon, Microsoft, advanced algorithm roles

  [T][ ] What is the diameter of a binary tree?
         (Longest path between any two nodes — may not pass through root)
         Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [T][ ] How do you serialize and deserialize a binary tree?
         (Preorder DFS with null markers, or BFS level-order with null markers)
         Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [T][ ] How is building a binary tree from traversals possible? Which combinations work?
         (inorder+preorder, inorder+postorder, inorder+level-order — any pair with inorder)
         (preorder+postorder only works for FULL binary trees)
         Asked at: Amazon, Microsoft, TCS

  ★[T][ ] What is the maximum number of nodes in a binary tree of height H?
           (2^(H+1) - 1 for perfect BT; H+1 for skewed BT)
           Asked at: TCS, Wipro, Amazon

  ★[T][ ] What is the minimum height of a binary tree with N nodes?
           (floor(log₂N) — achieved by complete binary tree)
           Asked at: TCS, Wipro, Amazon, Goldman Sachs

  ★[T][ ] What is the time complexity of building a binary tree from inorder + preorder?
           (Naive O(N²); with hashmap for inorder indices O(N))
           Asked at: Amazon, Microsoft

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── BASIC PROPERTIES ─────────────────────────────────────────────────────────

  [C][ ] (E) Find the maximum depth (height) of a binary tree
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (E) Find the minimum depth of a binary tree (depth of nearest leaf)
             (BFS finds it faster than DFS — first leaf encountered is answer)
             Asked at: Amazon, Microsoft

  [C][ ] (E) Count total number of nodes in a binary tree
             Asked at: TCS, Amazon

  [C][ ] (E) Count the number of leaf nodes in a binary tree
             Asked at: TCS, Amazon

  [C][ ] (E) Find the sum of all leaf nodes in a binary tree
             Asked at: TCS, Amazon

  [C][ ] (E) Find the sum of nodes at a given level K (root is level 0)
             Asked at: Amazon, TCS, Paytm

  [C][ ] (E) Find the maximum width of a binary tree (max nodes at any level)
             Asked at: Amazon, Microsoft, Flipkart, TCS

  [C][ ] (E) Check if two binary trees are identical
             Asked at: Amazon, Microsoft

  [C][ ] (E) Check if a binary tree is symmetric (mirror of itself)
             Asked at: Amazon, Microsoft

  [C][ ] (E) Mirror (invert) a binary tree — swap left and right at every node
             (famously asked to Max Howell, creator of Homebrew)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Check if a binary tree is a complete binary tree
             (BFS: once null node found, no more non-null should follow)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Check if two binary trees are mirror images of each other
             (two separate trees as input — not symmetric check)
             Asked at: Amazon, Microsoft

  [C][ ] (E) Count number of nodes at maximum depth in a binary tree
             Asked at: Amazon, TCS

  [C][ ] (E) Print all leaf nodes of a binary tree from left to right
             Asked at: TCS, Wipro, Zoho

  ── TRAVERSALS ───────────────────────────────────────────────────────────────

  [C][ ] (E) Implement inorder, preorder, postorder traversal — RECURSIVE
             Asked at: TCS, Wipro, Infosys, Amazon

  [C][ ] (E) Implement preorder, inorder, postorder traversal — ITERATIVE (stack)
             (Most beginners only know recursive — iterative version asked heavily)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Level order traversal (BFS) — print level by level
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (E) Left view of binary tree — first node at each level
             Asked at: Amazon, Flipkart, Paytm, Adobe

  [C][ ] (E) Right view of binary tree — last node at each level
             (Also: find rightmost node at each level iteratively)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Find the boundary traversal of a binary tree
             (left boundary + leaves + right boundary in order)
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (E) Convert a binary tree to its mirror image in-place
             Asked at: Amazon, TCS, Wipro, Zoho

  ── RECONSTRUCTION ───────────────────────────────────────────────────────────

  [C][ ] (E) Construct binary tree from preorder and inorder traversal
             (root = preorder[0]; find root in inorder; split)
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (E) Construct binary tree from postorder and inorder traversal
             Asked at: Amazon, Microsoft

  [C][ ] (E) Find distance between two nodes in a binary tree
             (dist = depth(u) + depth(v) - 2 × depth(LCA))
             Asked at: Amazon, Microsoft

  [C][ ] (E) Print nodes at distance K from a given node
             (Mark parent pointers with BFS; then BFS from target node)
             Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (E) Check if a given node exists as a subtree in a larger tree
              Asked at: Amazon, Microsoft, TCS

  ★[C][ ] (E) Find all nodes at depth D using BFS level counter
              Asked at: Amazon, TCS, Zoho

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── PATH & SUM PROBLEMS ──────────────────────────────────────────────────────

  [C][ ] (M) Diameter of binary tree (longest path between any two nodes)
             Global answer pattern; return height; update ans = L + R
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [C][ ] (M) Maximum path sum in binary tree (any node to any node)
             Global ans = INT_MIN; at each node: ans = max(ans, L+R+val)
             Asked at: Amazon, Microsoft, Google, Adobe, Goldman Sachs

  [C][ ] (M) All root-to-leaf paths; return as list of strings
             Asked at: Amazon, Microsoft

  [C][ ] (M) Path from root to a given node — return path as vector
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Count all paths (not just root-to-leaf) summing to given value
             (paths must go downward; use prefix sum hashmap + DFS)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Root-to-leaf paths where path sum equals target — return all paths
             Asked at: Amazon, Microsoft, Adobe, TCS

  [C][ ] (M) Sum of longest root-to-leaf path; if tie, return max sum
             Asked at: Amazon, Flipkart

  [C][ ] (M) Find path with maximum average from root to any leaf
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Maximum level sum in a binary tree (level with maximum sum of values)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Convert binary tree to sum tree (each node = sum of its subtree)
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Check if binary tree is a sum tree
             (each node = left subtree sum + right subtree sum)
             Asked at: Amazon, Flipkart, Paytm

  ── VIEWS & ORDER ────────────────────────────────────────────────────────────

  [C][ ] (M) Zigzag level order traversal (alternate left-right and right-left)
             BFS + deque; reverse direction alternately per level
             Asked at: Amazon, Microsoft, Flipkart, Adobe

  [C][ ] (M) Vertical order traversal — nodes in same column grouped together
             BFS + map<int, vector> by horizontal distance
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Top view of binary tree (first node visible from top per column)
             BFS with horizontal distance; first per column
             Asked at: Amazon, Flipkart, Paytm, Adobe

  [C][ ] (M) Bottom view of binary tree (last node visible from bottom per column)
             BFS with horizontal distance; last per column
             Asked at: Amazon, Flipkart, Adobe

  [C][ ] (M) Vertical sum of binary tree nodes per column
             Asked at: Amazon, Flipkart, Adobe

  [C][ ] (M) Find the deepest left leaf node in a binary tree
             Asked at: Amazon, Microsoft

  ── STRUCTURAL CHECKS ────────────────────────────────────────────────────────

  [C][ ] (M) Check if binary tree is height-balanced — O(N) single pass
             Return height from bottom; return -1 if subtree is unbalanced
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Count nodes in a complete binary tree — O(log² N)
             (Not O(N) — use left-height and right-height to skip subtrees)
             Asked at: Google, Amazon

  [C][ ] (M) Connect all nodes at the same level via next right pointer
             BFS level-order; or O(1) space using already-set next pointers
             Asked at: Amazon, Microsoft

  [C][ ] (M) Populate next right pointers in perfect binary tree — O(1) space
             Asked at: Amazon, Microsoft, Google

  ── RESTRUCTURING ────────────────────────────────────────────────────────────

  [C][ ] (M) Flatten binary tree to linked list in-place (preorder order)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Serialize and deserialize binary tree
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [C][ ] (M) Lowest Common Ancestor (LCA) of two nodes in binary tree
             If both found in different subtrees of curr → curr is LCA
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [C][ ] (M) Morris Inorder traversal — O(N) time O(1) space
             Thread rightmost of left subtree back to current node
             Asked at: Google, Amazon, Microsoft

  [C][ ] (M) Find inorder successor of a node (with parent pointers) — general BT
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find the maximum sum of nodes such that no two selected are
             parent and child — House Robber on tree
             At each node: take = val + grandchildren; skip = max(children)
             Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Find the smallest value in each row of a binary tree
              Level order BFS; track min per level
              Asked at: Amazon, Flipkart

  ★[C][ ] (M) Binary tree to DLL (doubly linked list) in-place
              Left = prev, Right = next; inorder traversal with prev pointer
              Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Print all nodes that do NOT have a sibling
              (nodes whose parent has only one child)
              Asked at: Amazon, Flipkart

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Binary tree maximum path sum (already in medium — hard constraints version)
             Any node to any node; handle all-negative trees
             Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [C][ ] (H) Binary tree cameras — minimum cameras to monitor all nodes
             Greedy DFS: leaf's parent gets camera; propagate up states
             Asked at: Google, Amazon

  [C][ ] (H) Reconstruct binary tree from level-order and inorder traversals
             Asked at: Amazon, Microsoft, Google

  [C][ ] (H) Given binary tree, find the largest subtree that is also a BST
             Return root and size; post-order DFS returning (isBST, min, max, size)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (H) Prune binary tree: remove all subtrees that contain no target node
             Asked at: Amazon, Google

  [C][ ] (H) Max path sum from leaf to leaf (both endpoints must be leaves)
             Different from any-node-to-any-node version
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Serialize and deserialize N-ary tree (each node has arbitrary children)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (H) Minimum operations to make binary tree into BST
             (Can change node values — find inorder, sort, reassign; count changes)
             Asked at: Google, Goldman Sachs

  ★[C][ ] (H) Find all duplicate subtrees in a binary tree
              Serialize each subtree; use hashmap to find duplicates; O(N)
              Asked at: Amazon, Google, Facebook/Meta

  ★[C][ ] (H) Binary tree to maximum sum BST (find subtree that is BST with max sum)
              Post-order DFS returning (isBST, min, max, sum); O(N)
              Asked at: Amazon, Google

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          PATTERN
  ─────────────────────────────────────────────────────────────────────────
  Height / depth                        Recursive: return max(L,R)+1
  Diameter / any-to-any path            Global ans; return max single path upward
  Max path sum (any to any)             Global ans=INT_MIN; combine L+R+val
  Count paths summing to K              Prefix sum hashmap + DFS
  Level-by-level processing             BFS with inner while(sz--)
  Left/Right view                       BFS: first/last per level; or DFS+depth
  Vertical/Top/Bottom view              BFS + horizontal distance map
  Zigzag traversal                      BFS + deque; alternate direction
  LCA (general BT)                      Return node if found; LCA when both non-null
  Is Balanced                           Return -1 if unbalanced; height otherwise
  Reconstruct from traversals           Preorder[0]=root; split inorder at root
  Flatten to linked list                Preorder DFS; thread right pointer
  Serialize / Deserialize               BFS or preorder with null markers
  House Robber on tree                  DP: take(node) vs skip(node)
  Subtree checks                        Hash subtree serializations

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Recursive DFS — height
  int height(TreeNode* r) {
      if (!r) return 0;
      return 1 + max(height(r->left), height(r->right));
  }

  // Iterative Inorder
  void inorder(TreeNode* root) {
      stack<TreeNode*> st; auto curr = root;
      while (curr || !st.empty()) {
          while (curr) { st.push(curr); curr = curr->left; }
          curr = st.top(); st.pop();
          cout << curr->val << " ";
          curr = curr->right;
      }
  }

  // LCA — general binary tree
  TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root || root == p || root == q) return root;
      auto L = lca(root->left, p, q), R = lca(root->right, p, q);
      return (L && R) ? root : (L ? L : R);
  }

  // Diameter — global answer pattern
  int ans = 0;
  int diam(TreeNode* r) {
      if (!r) return 0;
      int L = diam(r->left), R = diam(r->right);
      ans = max(ans, L + R);
      return 1 + max(L, R);
  }

  // Level order — level by level
  void bfs(TreeNode* root) {
      queue<TreeNode*> q; q.push(root);
      while (!q.empty()) {
          int sz = q.size();
          while (sz--) {
              auto n = q.front(); q.pop();
              cout << n->val << " ";
              if (n->left)  q.push(n->left);
              if (n->right) q.push(n->right);
          }
          cout << "\n"; // new level
      }
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 11 |  0 |  0 |    11
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   | 26 |  0 |  0 |    26
  Coding Easy (★ added)      |  2 |  0 |  0 |     2
  Coding Medium (from files) |  0 | 26 |  0 |    26
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 |  8 |     8
  Coding Hard (★ added)      |  0 |  0 |  2 |     2
  ---------------------------|----|----|----|---------
  TOTAL                      | 42 | 29 | 10 |    81

================================================================================
END
================================================================================
