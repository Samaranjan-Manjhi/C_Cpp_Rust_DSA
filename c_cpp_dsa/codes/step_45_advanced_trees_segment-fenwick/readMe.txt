================================================================================
        SEGMENT TREE & FENWICK TREE — COMPLETE QUESTION BANK
        Covers: Segment Tree build/query/update, Lazy Propagation,
                Fenwick Tree (BIT), Merge Sort Tree, Persistent Segment Tree
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

  ── SEGMENT TREE ─────────────────────────────────────────────────────────────
  A full binary tree where each node stores aggregate info (sum/min/max/GCD)
  for a range of the original array.
  • Node i covers array[l..r]; left child covers [l,mid]; right covers [mid+1,r]
  • Built bottom-up; queried and updated top-down
  • Array size: 4 × N (safe upper bound)

  Build — O(N):
    void build(int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid);  build(2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];   // merge
    }

  Point Update — O(log N):
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else            update(2*node+1, mid+1, r, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

  Range Query — O(log N):
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;               // outside
        if (ql <= l && r <= qr) return tree[node];     // fully inside
        int mid = (l + r) / 2;
        return query(2*node, l, mid, ql, qr) +
               query(2*node+1, mid+1, r, ql, qr);
    }

  ── LAZY PROPAGATION ─────────────────────────────────────────────────────────
  For RANGE UPDATES (add V to all elements in [L, R]):
  Instead of updating every element, store the pending update in a "lazy" array.
  Push down the lazy value to children only when those children are accessed.
  Achieves O(log N) for both range updates and range queries.

  Key operations: pushDown(node) before accessing children.

  ── FENWICK TREE (Binary Indexed Tree / BIT) ─────────────────────────────────
  Simpler structure for PREFIX SUM with POINT UPDATES. Uses clever bit trick.
  • Store partial sums indexed by lowest set bit of index
  • 1-indexed; tree[i] stores sum of elements in range [i - lowbit(i) + 1, i]
  • lowbit(i) = i & (-i)   (isolates the lowest set bit)

  Update — O(log N):
    void update(int i, int delta) {
        for (; i <= n; i += i & (-i))  tree[i] += delta;
    }

  Prefix Sum [1..i] — O(log N):
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i))  sum += tree[i];
        return sum;
    }

  Range Sum [l..r] = query(r) - query(l-1)

  ── COMPARISON TABLE ─────────────────────────────────────────────────────────

  Feature                  │ Segment Tree   │ Fenwick Tree
  ─────────────────────────┼────────────────┼──────────────────────────────
  Build                    │ O(N)           │ O(N log N) or O(N)
  Point update             │ O(log N)       │ O(log N)
  Range query              │ O(log N)       │ O(log N)
  Range update             │ O(log N) lazy  │ O(log N) with diff array trick
  Memory                   │ 4N             │ N+1
  Code complexity          │ Higher         │ Much simpler
  Supports min/max query   │ YES            │ NO (sum/XOR only)
  Lazy propagation         │ YES            │ NO
  General merge function   │ Any associative│ Sum, XOR, product only

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a segment tree? What problems does it solve?
         (Range queries + point/range updates in O(log N); sum, min, max, GCD)
         Asked at: Amazon, Google, Goldman Sachs, competitive programming

  [T][ ] What is lazy propagation? When do you need it?
         (Defers range updates; only pushes down when that node's children are accessed;
          needed for range-update + range-query in O(log N))
         Asked at: Google, Goldman Sachs, competitive programming

  [T][ ] What is a Fenwick Tree (BIT)? How does it differ from a segment tree?
         (BIT: simpler, less memory, only prefix-based queries, no range-update-range-query;
          Segment tree: supports any associative function including min/max)
         Asked at: Amazon, Google, Goldman Sachs, competitive programming

  [T][ ] What is the time complexity of segment tree build, query, and update?
         (Build: O(N); each query: O(log N); each update: O(log N))
         Asked at: Amazon, TCS, Google, competitive programming

  [T][ ] How is a segment tree stored in an array? What size array do you need?
         (Array of size 4N; node 1 is root; left child of i = 2i; right = 2i+1)
         Asked at: TCS, Wipro, Amazon, competitive programming

  [T][ ] What is lowbit(i) = i & (-i) in a Fenwick tree and why does it work?
         (Isolates the lowest set bit of i using two's complement; determines the range
          each BIT node covers)
         Asked at: Google, Goldman Sachs, competitive programming

  [T][ ] When would you use a Fenwick tree over a segment tree?
         (When only prefix sums and point updates are needed — BIT is simpler,
          uses less memory, has smaller constant factors)
         Asked at: Amazon, Google, Goldman Sachs

  ★[T][ ] What is a merge sort tree? When is it used?
           (Segment tree where each node stores a SORTED array of its range;
            supports "count of elements in [L,R] greater than K" in O(log² N);
            build: O(N log N); query: O(log² N))
           Asked at: Google, Goldman Sachs, competitive programming

  ★[T][ ] What is a persistent segment tree? When is it needed?
           (Each update creates a new version by copying only O(log N) nodes;
            supports queries on historical versions; used in K-th smallest in range)
           Asked at: Google, Goldman Sachs, Codeforces-level competitive programming

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Implement segment tree for range sum queries and point updates
             Build O(N); query O(log N); update O(log N)
             Asked at: Amazon, competitive programming, Dolat Capital

  [C][ ] (E) Implement Fenwick Tree (BIT) for prefix sum queries and point updates
             Simpler than segment tree for this specific task
             Asked at: Amazon, Goldman Sachs, competitive programming, Dolat Capital

  [C][ ] (E) Count inversions using Fenwick Tree — O(N log N)
             Process elements right to left; query how many already inserted are smaller
             Asked at: Amazon, Goldman Sachs, competitive programming, Dolat Capital

  [C][ ] (E) Build segment tree for range MINIMUM query (RMQ); answer Q queries
             Asked at: Amazon, Google, competitive programming

  ★[C][ ] (E) Using a BIT, find the prefix sum up to index i and update single element
              Implement both operations; test with array of 10 elements
              Asked at: Amazon, Goldman Sachs, competitive programming

  ★[C][ ] (E) Given array, answer Q queries of type: how many elements in [L, R] equal X?
              Offline approach: coordinate compress + BIT
              Asked at: Amazon, competitive programming

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── SEGMENT TREE ─────────────────────────────────────────────────────────────

  [C][ ] (M) Range sum query with point updates (Segment Tree)
             Asked at: Amazon, Google, competitive programming

  [C][ ] (M) Range minimum query (Segment Tree) — answer Q queries after build
             Asked at: Amazon, Google, competitive programming

  [C][ ] (M) Segment tree with lazy propagation for range add + range sum query
             Range add: add V to all arr[L..R]; range query: sum of arr[L..R]
             Asked at: Google, Goldman Sachs, competitive programming, Dolat Capital

  [C][ ] (M) Range GCD query with point updates using segment tree
             Merge function = gcd(left, right)
             Asked at: Google, competitive programming

  [C][ ] (M) Segment tree for range maximum query; support both point update
             and range max query — answer Q queries online
             Asked at: Amazon, Goldman Sachs, competitive programming

  [C][ ] (M) Count of range sum: count subarrays with sum in [lower, upper]
             Merge sort on prefix sums; or BIT-based; O(N log N)
             Asked at: Google, LeetCode hard, competitive programming

  [C][ ] (M) Count of elements in range [L, R] that are greater than K
             Merge sort tree (segment tree of sorted vectors); O(log² N) per query
             Asked at: Google, Goldman Sachs, competitive programming

  ── FENWICK TREE ─────────────────────────────────────────────────────────────

  [C][ ] (M) Prefix sum with point updates using Fenwick Tree — online Q queries
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (M) Count inversions in array using BIT — O(N log N)
             Coordinate compress; process left to right; for each element,
             count already-inserted elements greater than it
             Asked at: Amazon, Google, Flipkart, Goldman Sachs

  [C][ ] (M) Given stream of integers, for each new element find its rank
             (number of elements ≤ it seen so far) using BIT
             Asked at: Amazon, Goldman Sachs, competitive programming

  ★[C][ ] (M) 2D Fenwick Tree: support point update and 2D prefix sum query
              update(x, y, delta); query(x1, y1, x2, y2) returns rectangle sum
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (M) Find the K-th smallest element in a range [L, R] using merge sort tree
              Segment tree of sorted arrays; binary search on answer; O(log³ N)
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (M) Implement BIT for range update + point query
              (Reverse trick: update diff array BIT; query = prefix sum at point)
              Asked at: Goldman Sachs, competitive programming

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Range update (add V to [L, R]) + range query (sum of [L, R])
             using segment tree with lazy propagation
             Asked at: Google, Goldman Sachs, competitive programming

  [C][ ] (H) Given array, for each query (L, R, K) count elements divisible by K
             Offline approach with BIT
             Asked at: Google, competitive programming

  [C][ ] (H) Find number of inversions in each range [L, R] of array
             Merge sort tree or persistent segment tree
             Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Implement persistent segment tree to answer:
              "K-th smallest element in subarray arr[L..R]"
              Build N+1 versions of prefix segment tree; binary search O(log N) per query
              Asked at: Google, Goldman Sachs, Codeforces competitive programming

  ★[C][ ] (H) Segment tree beats (Chtholly tree variant) — range assignment:
              assign all elements in [L, R] = min(arr[i], V) efficiently
              Asked at: Competitive programming, Goldman Sachs

  ★[C][ ] (H) Find the length of the longest subarray with maximum XOR
              using XOR segment tree + persistent approach
              Asked at: Google, Goldman Sachs, competitive programming

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Segment Tree — Sum + Point Update
  int tree[4*MAXN];
  void build(int* a, int nd, int l, int r) {
      if (l==r) { tree[nd]=a[l]; return; }
      int m=(l+r)/2;
      build(a,2*nd,l,m); build(a,2*nd+1,m+1,r);
      tree[nd]=tree[2*nd]+tree[2*nd+1];
  }
  void update(int nd, int l, int r, int i, int v) {
      if (l==r) { tree[nd]=v; return; }
      int m=(l+r)/2;
      if (i<=m) update(2*nd,l,m,i,v); else update(2*nd+1,m+1,r,i,v);
      tree[nd]=tree[2*nd]+tree[2*nd+1];
  }
  int query(int nd, int l, int r, int ql, int qr) {
      if (qr<l||r<ql) return 0;
      if (ql<=l&&r<=qr) return tree[nd];
      int m=(l+r)/2;
      return query(2*nd,l,m,ql,qr)+query(2*nd+1,m+1,r,ql,qr);
  }

  // Fenwick Tree (BIT) — 1-indexed
  int bit[MAXN]; int N;
  void update(int i, int d) { for(;i<=N;i+=i&-i) bit[i]+=d; }
  int query(int i) { int s=0; for(;i>0;i-=i&-i) s+=bit[i]; return s; }
  int rangeQuery(int l, int r) { return query(r)-query(l-1); }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  7 |  0 |  0 |     7
  Theory (★ added)           |  2 |  0 |  0 |     2
  Coding Easy (from files)   |  4 |  0 |  0 |     4
  Coding Easy (★ added)      |  2 |  0 |  0 |     2
  Coding Medium (from files) |  0 | 10 |  0 |    10
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 |  3 |     3
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 15 | 13 |  6 |    34

================================================================================
END
================================================================================
