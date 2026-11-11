================================================================================
        GRAPH REPRESENTATION & BASICS — COMPLETE QUESTION BANK
        Covers: Representations, BFS, DFS, Cycle Detection, Topological Sort,
                Bipartite, Connected Components, Union-Find, Shortest Paths,
                MST, Bridges, Articulation Points, SCC, Max Flow
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

  ── GRAPH TERMINOLOGY ────────────────────────────────────────────────────────
  Vertex (Node), Edge, Degree (in-degree, out-degree)
  Directed (Digraph) vs Undirected
  Weighted vs Unweighted
  Connected vs Disconnected (undirected)
  Strongly Connected (directed — every node reachable from every other)
  DAG — Directed Acyclic Graph (no directed cycles)
  Sparse (E ≈ V) vs Dense (E ≈ V²) — determines algorithm choice

  ── REPRESENTATIONS ──────────────────────────────────────────────────────────

  1. ADJACENCY LIST  — vector<vector<int>> adj(V);
     Add edge (u,v): adj[u].push_back(v);
     Space: O(V + E)   — preferred for SPARSE graphs
     Iterate neighbours: O(degree)

  2. ADJACENCY MATRIX — int mat[V][V] = {0};
     Add edge (u,v): mat[u][v] = 1;
     Space: O(V²)      — preferred for DENSE graphs or when fast O(1) edge check needed
     Check edge (u,v): O(1)

  3. EDGE LIST — vector<tuple<int,int,int>> edges; // (weight, u, v)
     Used for: Kruskal's MST, Bellman-Ford
     Space: O(E)

  ── BFS TEMPLATE (unweighted shortest path) ──────────────────────────────────
  vector<int> dist(V, -1);
  queue<int> q;
  dist[src] = 0; q.push(src);
  while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) {
          if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
      }
  }

  ── DFS TEMPLATE (iterative) ─────────────────────────────────────────────────
  vector<bool> vis(V, false);
  stack<int> st; st.push(src); vis[src] = true;
  while (!st.empty()) {
      int u = st.top(); st.pop();
      for (int v : adj[u]) if (!vis[v]) { vis[v] = true; st.push(v); }
  }

  ── UNION-FIND (DSU) ─────────────────────────────────────────────────────────
  vector<int> par(V), rnk(V, 0);
  iota(par.begin(), par.end(), 0);              // each node is its own parent
  function<int(int)> find = [&](int x) {
      if (par[x] != x) par[x] = find(par[x]);  // path compression
      return par[x];
  };
  auto unite = [&](int x, int y) {
      x = find(x); y = find(y); if (x == y) return false;
      if (rnk[x] < rnk[y]) swap(x, y);         // union by rank
      par[y] = x; if (rnk[x] == rnk[y]) rnk[x]++;
      return true;
  };

  ── ALGORITHM SELECTION GUIDE ────────────────────────────────────────────────

  Problem Type                          Algorithm              Complexity
  ──────────────────────────────────────────────────────────────────────────
  Shortest path (unweighted)            BFS                    O(V+E)
  Shortest path (weighted, no neg)      Dijkstra (min-heap)    O((V+E)log V)
  Shortest path (negative weights)      Bellman-Ford           O(VE)
  Shortest path (all pairs)             Floyd-Warshall         O(V³)
  Shortest path (0-1 weights)           0-1 BFS (deque)        O(V+E)
  Shortest path in DAG                  Topo sort + relax      O(V+E)
  Cycle detection (undirected)          DFS / Union-Find       O(V+E)
  Cycle detection (directed)            DFS 3-color            O(V+E)
  Topological sort                      DFS / Kahn's BFS       O(V+E)
  MST                                   Kruskal / Prim         O(E log E)
  Connected components                  DFS / BFS / DSU        O(V+E)
  Strongly Connected Components         Kosaraju / Tarjan      O(V+E)
  Bridges & Articulation Points         Tarjan                 O(V+E)
  Bipartite check                       BFS 2-coloring         O(V+E)
  Max flow / Min cut                    Edmonds-Karp           O(VE²)

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  ── REPRESENTATION & BASICS ──────────────────────────────────────────────────

  [T][ ] What are the different ways to represent a graph? Pros and cons of each?
         (Adjacency list: O(V+E) space, good for sparse; Matrix: O(V²), O(1) edge query;
          Edge list: O(E), good for Kruskal/Bellman-Ford)
         Asked at: Amazon, Microsoft, TCS, Wipro, Google

  [T][ ] What is the difference between directed and undirected graph?
         (Directed: edges have direction (u→v); Undirected: edge goes both ways)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is in-degree and out-degree of a vertex in a directed graph?
         (In-degree: number of edges coming in; Out-degree: edges going out)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is a DAG? Give a real-world example.
         (Directed Acyclic Graph; examples: dependency resolution, course scheduling,
          build systems like Make/CMake, task scheduling)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is BFS? What data structure does it use? What is it used for?
         (Queue; unweighted shortest path, level-order traversal, bipartite check)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] What is DFS? What data structure does it use? What is it used for?
         (Stack/recursion; cycle detection, topological sort, SCC, path existence)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] What is the difference between BFS and DFS? When do you prefer each?
         (BFS: shortest path in unweighted graph, level-order, bipartite;
          DFS: cycle detection, topo sort, SCC, path finding in mazes)
         Asked at: Amazon, Microsoft, Flipkart, Google

  [T][ ] When does BFS give shortest path? When doesn't it work for shortest path?
         (BFS gives shortest path ONLY in unweighted graphs; fails with weights —
          use Dijkstra for positive weights, Bellman-Ford for negative)
         Asked at: Amazon, Microsoft, Flipkart, Google

  [T][ ] What is topological sort? Can it exist for undirected or cyclic graphs?
         (Linear ordering of vertices such that for every directed edge u→v, u comes before v;
          impossible for undirected graphs and for directed graphs with cycles)
         Asked at: Amazon, Microsoft, Flipkart

  [T][ ] What is the difference between Kahn's algorithm and DFS-based topological sort?
         (Kahn's: BFS + in-degree array; detects cycle if not all nodes processed;
          DFS: push to stack on finish; cycle detected by back-edge check)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is a bipartite graph? How do you check if a graph is bipartite?
         (Can be 2-coloured such that no two adjacent nodes share same colour;
          BFS 2-colouring: if any edge connects same-colour nodes → not bipartite)
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What is Union-Find (DSU)? What optimisations make it nearly O(1)?
         (Path compression + union by rank — combined gives amortized O(α(N)) ≈ O(1))
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is a Minimum Spanning Tree (MST)? What algorithms find it?
         (Tree of V-1 edges with minimum total weight connecting all nodes;
          Kruskal's: sort edges, add if no cycle (DSU); Prim's: grow from source with min-heap)
         Asked at: Amazon, Microsoft, Goldman Sachs

  [T][ ] What is the difference between Prim's and Kruskal's for MST?
         (Prim's: vertex-based, works with adjacency list, O((V+E)log V); better for dense;
          Kruskal's: edge-based, sorts edges, O(E log E); better for sparse)
         Asked at: Amazon, Microsoft, Goldman Sachs, competitive programming

  [T][ ] What is Dijkstra's algorithm? Why can't it handle negative weights?
         (Greedy: always extend shortest known path; fails with negative weights because
          a shorter path via negative edge may be found AFTER the node is finalised)
         Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [T][ ] What is Bellman-Ford? When do you use it over Dijkstra?
         (DP: relax all edges V-1 times; handles negative weights; detects negative cycles;
          O(VE) — use when negative weights present)
         Asked at: Amazon, Microsoft, Google

  [T][ ] What is Floyd-Warshall? When do you use it?
         (All-pairs shortest path; O(V³) DP; use for dense graphs where all pairs needed)
         Asked at: Amazon, Microsoft, Goldman Sachs

  [T][ ] What is a strongly connected component (SCC)?
         (Maximal subset of vertices where every vertex is reachable from every other)
         Asked at: Amazon, Google, Goldman Sachs, competitive programming

  [T][ ] What is a bridge in a graph? What is an articulation point?
         (Bridge: edge whose removal disconnects the graph;
          Articulation point: vertex whose removal disconnects the graph)
         Asked at: Amazon, Google, Facebook/Meta, Atlassian

  ★[T][ ] What is 0-1 BFS? When do you use it over Dijkstra?
           (BFS with deque: push to front for edge weight 0, back for weight 1;
            O(V+E) — faster than Dijkstra O((V+E)log V) when weights are only 0 or 1)
           Asked at: Google, Goldman Sachs, Dolat Capital, competitive programming

  ★[T][ ] What is the difference between Kosaraju's and Tarjan's algorithm for SCC?
           (Kosaraju: 2 DFS passes + transpose graph; Tarjan: single DFS + stack + low values;
            both O(V+E); Tarjan is more elegant but harder to implement)
           Asked at: Google, Goldman Sachs, competitive programming

  ★[T][ ] What is a negative cycle? How does Bellman-Ford detect it?
           (Cycle with total negative weight — shortest path becomes -∞;
            run V-th relaxation; if any distance still reduces → negative cycle exists)
           Asked at: Google, Goldman Sachs, competitive programming

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  ── REPRESENTATION ───────────────────────────────────────────────────────────

  [C][ ] (E) Build an adjacency list for a weighted directed graph from edge list input
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Build an adjacency matrix for an undirected graph
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Find in-degree and out-degree of every vertex in a directed graph
             Asked at: TCS, Amazon

  [C][ ] (E) Find all neighbours of a given vertex in adjacency list representation
             Asked at: TCS, Wipro

  ── BFS / DFS BASICS ─────────────────────────────────────────────────────────

  [C][ ] (E) BFS traversal of a graph from a given source
             Asked at: TCS, Amazon, Wipro, Infosys

  [C][ ] (E) DFS traversal of a graph from a given source — recursive and iterative
             Asked at: TCS, Amazon, Wipro, Infosys

  [C][ ] (E) Check if a path exists between two nodes using BFS
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Find the shortest path (hop count) in an unweighted undirected graph — BFS
             Asked at: Amazon, TCS, Wipro, Zoho

  [C][ ] (E) Check if an undirected graph is connected (single connected component)
             Asked at: TCS, Amazon, Wipro

  [C][ ] (E) Find number of connected components in undirected graph using BFS/DFS
             Asked at: Amazon, Microsoft, TCS

  [C][ ] (E) Print all paths from source to destination in a directed graph — DFS
             Asked at: Amazon, Flipkart, Zoho

  [C][ ] (E) Check if directed graph has a cycle — DFS with 3-colour marking
             (White=unvisited, Gray=in-stack, Black=done; back edge to gray = cycle)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Check if undirected graph is bipartite using BFS 2-colouring
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (E) Find the number of islands (connected components in 2D grid) — DFS/BFS
             Asked at: Amazon, Microsoft, Google, Flipkart (VERY common!)

  ★[C][ ] (E) Convert an adjacency matrix to an adjacency list and vice versa
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Find all vertices reachable from a given source in a directed graph
              BFS / DFS; collect all visited nodes
              Asked at: Amazon, Flipkart

  ★[C][ ] (E) Check if an undirected graph has a cycle using Union-Find only
              For each edge (u,v): if find(u)==find(v) → cycle; else unite(u,v)
              Asked at: Amazon, Microsoft, Goldman Sachs

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── CONNECTED COMPONENTS & UNION-FIND ────────────────────────────────────────

  [C][ ] (M) Number of provinces (connected components using DFS)
             Asked at: Amazon, Flipkart

  [C][ ] (M) Find number of connected components using Union-Find (not DFS)
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) Redundant connection — find the edge that creates a cycle; remove it
             Union-Find: the edge (u,v) where find(u)==find(v) is redundant
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Accounts merge — merge accounts with same email using Union-Find
             Asked at: Amazon, Google, Facebook/Meta

  ── BFS / GRID PROBLEMS ──────────────────────────────────────────────────────

  [C][ ] (M) Rotten oranges — minimum time to rot all oranges (multi-source BFS)
             Push all rotten oranges to queue first; BFS simultaneously
             Asked at: Amazon, Microsoft, Google, Paytm, Swiggy

  [C][ ] (M) 01 Matrix — shortest distance to nearest 0 for each cell
             Multi-source BFS from all 0s simultaneously
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Walls and gates — fill each empty room with distance to nearest gate
             Multi-source BFS from all gates
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (M) Flood fill — change colour of connected region
             DFS/BFS from starting cell; change colour; handle same-colour edge case
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Pacific Atlantic water flow — cells that can flow to both oceans
             Reverse BFS from each ocean border; intersection = answer
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (M) Surrounded regions — flip 'O's not connected to border
             DFS/BFS from border 'O's to mark safe; flip all others
             Asked at: Amazon, Microsoft

  [C][ ] (M) Number of distinct islands (same shape = same island)
             DFS + normalize path signature; store in set
             Asked at: Google, Amazon, Facebook/Meta

  [C][ ] (M) Find shortest path in grid with at most K obstacle eliminations
             BFS with state (row, col, k_remaining); O(V×K)
             Asked at: Google, Amazon, Goldman Sachs

  ── TOPOLOGICAL SORT ─────────────────────────────────────────────────────────

  [C][ ] (M) Topological sort using DFS (post-order push to stack)
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  [C][ ] (M) Topological sort using Kahn's algorithm (BFS + in-degree array)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Course Schedule I — can you finish all courses? (detect cycle in directed graph)
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Course Schedule II — find valid order to take courses (topo sort)
             Asked at: Amazon, Microsoft, Google, Facebook/Meta

  [C][ ] (M) Given directed graph, check if it is a DAG
             DFS 3-colour or Kahn's; if any node not processed → has cycle → not DAG
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Eventual safe states — find all nodes from which no cycle is reachable
             Reverse edges; find all nodes that can reach terminal nodes; topo sort
             Asked at: Google, Amazon

  [C][ ] (M) Find the longest path in a DAG — O(V+E)
             Topological sort + DP relaxation (like Bellman-Ford but on sorted order)
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Find the shortest path in a weighted DAG using topo sort + relaxation
             Faster than Dijkstra for DAGs; O(V+E)
             Asked at: Amazon, Goldman Sachs, competitive programming

  ── SHORTEST PATH ────────────────────────────────────────────────────────────

  [C][ ] (M) Dijkstra's algorithm — Network Delay Time
             Min-heap: (dist, node); relax all neighbours; O((V+E) log V)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Cheapest flights within K stops — Bellman-Ford limited to K+1 iterations
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find if path exists from source to destination (directed graph)
             BFS/DFS; check if destination is visited
             Asked at: Amazon, TCS, Flipkart

  [C][ ] (M) Find the shortest cycle in an undirected graph
             BFS from each vertex; track parent; first back edge gives cycle length
             Asked at: Google, Goldman Sachs

  ── MST & UNION-FIND ─────────────────────────────────────────────────────────

  [C][ ] (M) Minimum Spanning Tree using Kruskal's + Union-Find — O(E log E)
             Sort edges by weight; add if find(u) != find(v)
             Asked at: Amazon, Microsoft, Goldman Sachs, competitive programming

  [C][ ] (M) Minimum Spanning Tree using Prim's algorithm — O((V+E) log V)
             Min-heap of (weight, node); always extend cheapest reachable edge
             Asked at: Amazon, Microsoft, competitive programming

  [C][ ] (M) Connect all points with minimum cost (MST on 2D points)
             Edge weight = Manhattan distance; Kruskal's or Prim's
             Asked at: Amazon, Google, Flipkart

  ── SCC & ADVANCED ───────────────────────────────────────────────────────────

  [C][ ] (M) Find all strongly connected components using Kosaraju's algorithm
             Pass 1: DFS → push to stack by finish time; Pass 2: transpose + DFS from stack
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (M) Find the mother vertex in a directed graph
             Last finished vertex in DFS; verify by checking if it can reach all others
             Asked at: Amazon, Google

  [C][ ] (M) Find minimum number of edges to add to make directed graph strongly connected
             Count nodes with in-degree 0 and out-degree 0; answer = max(in0, out0)
             Asked at: Google, Goldman Sachs

  [C][ ] (M) Clone a directed graph — deep copy preserving shared node references
             BFS + hashmap: original node → cloned node; copy edges
             Asked at: Amazon, Microsoft, Facebook/Meta

  [C][ ] (M) Word Ladder — minimum transformation steps (each step changes one letter)
             BFS; each word = node; adjacent if differ by 1 letter
             Asked at: Amazon, Microsoft, Google, Flipkart, Goldman Sachs

  ★[C][ ] (M) Find the friend group (connected component) with maximum members
              BFS/DFS to find component sizes; return largest
              Asked at: Amazon, Flipkart, Paytm

  ★[C][ ] (M) Given grid of heights, find path minimising maximum height difference
              Binary search on answer + BFS/DFS feasibility check; O(V+E) log(max_diff)
              Asked at: Google, Amazon

  ★[C][ ] (M) Detect cycle in undirected graph using BOTH DFS and Union-Find approaches
              Show both; compare code clarity and efficiency
              Asked at: Amazon, Microsoft, Goldman Sachs

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Find all bridges in undirected graph — Tarjan's algorithm
             DFS with discovery[] and low[] arrays; edge (u,v) is bridge if low[v] > disc[u]
             Asked at: Amazon, Google, Facebook/Meta, Atlassian

  [C][ ] (H) Find all articulation points in undirected graph — Tarjan's algorithm
             DFS; node u is AP if: (1) root with 2+ children, OR
             (2) non-root with child v where low[v] >= disc[u]
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (H) Alien dictionary — infer character order from sorted word list
             Build DAG: for each adjacent word pair, find first differing char → add edge;
             topological sort gives character order
             Asked at: Amazon, Google, Microsoft, Facebook/Meta

  [C][ ] (H) Swim in rising water — minimum time to reach bottom-right in grid
             Dijkstra on grid; dist[i][j] = min max height on path to (i,j)
             Asked at: Google, LeetCode hard

  [C][ ] (H) Critical connections in a network — find all bridges
             Same as Tarjan's bridge algorithm (LeetCode rephrasing)
             Asked at: Amazon, Facebook/Meta, LeetCode

  [C][ ] (H) Find minimum weight cycle in directed graph
             Floyd-Warshall: initialize diagonal to ∞; cycle weight = dp[i][i]
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Maximum flow in network using Edmonds-Karp (BFS-based Ford-Fulkerson)
             Find augmenting paths with BFS; push min residual capacity; O(VE²)
             Asked at: Google, Goldman Sachs, competitive programming

  [C][ ] (H) Minimum time to complete all tasks given K parallel workers
             Topological sort + multi-source BFS with level = time step
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Count number of ways to reach destination in DAG with exactly K edges
             DP[k][v] = number of paths of length k ending at v; or matrix exponentiation
             Asked at: Google, Goldman Sachs, competitive programming

  [C][ ] (H) Find minimum cost to visit all cities exactly once and return to start
             Travelling Salesman Problem — DP + bitmask for small N (N ≤ 20)
             dp[mask][i] = min cost to have visited nodes in mask, ending at i
             Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Design a network routing system maximising minimum bandwidth on a path
              Modified Dijkstra with max-min (bottle-neck shortest path)
              Asked at: Google, Dolat Capital, Goldman Sachs

  ★[C][ ] (H) Find all nodes in a directed graph that lie on at least one cycle
              (Detect cycle + mark participating nodes via DFS backtracking)
              Asked at: Google, Amazon, Goldman Sachs

  ★[C][ ] (H) Given a dependency graph, find the minimum number of semesters to finish
              all courses if you can take any number per semester — topological sort BFS
              (Count levels = longest path in DAG)
              Asked at: Amazon, Google, Goldman Sachs

================================================================================
PART 6 — PATTERN QUICK SUMMARY
================================================================================

  PROBLEM TYPE                          ALGORITHM / PATTERN
  ─────────────────────────────────────────────────────────────────────────
  Shortest path (unweighted)            BFS; dist[] array
  Shortest path (weighted +ve)          Dijkstra; min-heap (dist, node)
  Shortest path (negative edges)        Bellman-Ford; V-1 relaxation passes
  Shortest path (all pairs)             Floyd-Warshall; dp[i][j][k]
  Shortest path (0-1 weights)           0-1 BFS; deque
  Shortest path (DAG)                   Topo sort + DP relaxation
  Cycle detection (undirected)          DFS parent-tracking OR Union-Find
  Cycle detection (directed)            DFS 3-colour (white/gray/black)
  Topological sort                      DFS (post-order) OR Kahn's BFS
  Connected components                  BFS/DFS loop over all nodes OR DSU
  Bipartite check                       BFS 2-coloring; fail if same color edge
  MST                                   Kruskal (sparse) / Prim (dense)
  SCC                                   Kosaraju (2 DFS) / Tarjan (1 DFS)
  Bridges                               Tarjan; low[v] > disc[u]
  Articulation points                   Tarjan; low[v] >= disc[u]
  Multi-source BFS                      Push ALL sources to queue initially
  Grid BFS                              Treat cells as nodes; 4 or 8 directions
  Union-Find cycle detect               For each edge: if find(u)==find(v) → cycle
  Max flow / Min cut                    Edmonds-Karp (BFS augmenting paths)
  TSP (small N)                         DP + bitmask; dp[mask][node]

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Dijkstra (min-heap)
  vector<int> dist(V, INT_MAX); dist[src] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.push({0, src});
  while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (d > dist[u]) continue;
      for (auto [v, w] : adj[u])
          if (dist[u] + w < dist[v]) { dist[v] = dist[u]+w; pq.push({dist[v],v}); }
  }

  // Kahn's topological sort (BFS)
  vector<int> indeg(V, 0);
  for (int u=0; u<V; u++) for (int v : adj[u]) indeg[v]++;
  queue<int> q;
  for (int i=0; i<V; i++) if (!indeg[i]) q.push(i);
  vector<int> order;
  while (!q.empty()) {
      int u = q.front(); q.pop(); order.push_back(u);
      for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
  }
  // if order.size() != V → graph has a cycle

  // DFS cycle detection (directed) — 3-colour
  // 0=white, 1=gray, 2=black
  vector<int> color(V, 0);
  bool hasCycle = false;
  function<void(int)> dfs = [&](int u) {
      color[u] = 1;  // gray — in current path
      for (int v : adj[u]) {
          if (color[v] == 1) { hasCycle = true; return; } // back edge
          if (color[v] == 0) dfs(v);
      }
      color[u] = 2;  // black — fully processed
  };
  for (int i=0; i<V; i++) if (!color[i]) dfs(i);

  // Tarjan's bridge finding
  int timer = 0;
  vector<int> disc(V,-1), low(V);
  vector<bool> vis(V,false);
  function<void(int,int)> bridge = [&](int u, int par) {
      vis[u]=true; disc[u]=low[u]=timer++;
      for (int v : adj[u]) {
          if (!vis[v]) { bridge(v,u); low[u]=min(low[u],low[v]);
              if (low[v]>disc[u]) cout<<u<<"-"<<v<<" is a bridge\n"; }
          else if (v!=par) low[u]=min(low[u],disc[v]);
      }
  };

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 19 |  0 |  0 |    19
  Theory (★ added)           |  3 |  0 |  0 |     3
  Coding Easy (from files)   | 14 |  0 |  0 |    14
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 | 28 |  0 |    28
  Coding Medium (★ added)    |  0 |  3 |  0 |     3
  Coding Hard (from files)   |  0 |  0 | 10 |    10
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 39 | 31 | 13 |    83

================================================================================
END
================================================================================
