================================================================================
        STL — QUEUE (std::queue) COMPLETE QUESTION BANK
        Covers: std::queue internals + classic queue algorithm problems
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

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. std::queue INTERNALS & DESIGN
--------------------------------------------------------------------------------

  [T][ ] What is a queue? What is its core property?
         (FIFO — First In First Out; elements leave in the order they entered)
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is std::queue in C++? Is it a container or a container adaptor?
         (Container adaptor — wraps std::deque by default)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What is the default underlying container of std::queue?
         What other containers can be used?
         (Default: std::deque; can also use std::list — NOT vector, lacks pop_front)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] What is the time complexity of push, pop, front, back, empty on std::queue?
         (All O(1))
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is the difference between stack and queue?
         (Stack: LIFO — top is the last inserted element;
          Queue: FIFO — front is the first inserted element)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is a circular queue? Why is it needed over a simple array-based queue?
         (Simple array queue wastes space after dequeues; circular queue reuses space
          via modular arithmetic — front = (front+1) % capacity)
         Asked at: TCS, Wipro, Sasken, Dolat Capital

  [T][ ] How would you implement a queue using two stacks?
         (Push stack and pop stack; transfer all when pop stack is empty;
          amortized O(1) per operation)
         Asked at: Amazon, Microsoft, Google

  [T][ ] How would you implement a stack using two queues?
         (Push O(N): enqueue to q2, dequeue all of q1 to q2, swap q1 and q2;
          OR pop O(N): dequeue N-1 elements to q2, return last, swap)
         Asked at: Amazon, Microsoft

  [T][ ] What is BFS (Breadth-First Search)? Why does it use a queue?
         (Explores level by level; queue ensures FIFO — oldest nodes explored first,
          guaranteeing shortest path in unweighted graphs)
         Asked at: TCS, Wipro, Amazon, Microsoft, Google

  [T][ ] What is the difference between BFS and DFS?
         (BFS: queue, level-order, shortest path in unweighted graph;
          DFS: stack/recursion, depth-first, used for connectivity/cycle detection)
         Asked at: TCS, Wipro, Amazon, Flipkart

  [T][ ] What is the difference between BFS and Dijkstra's algorithm?
         When does BFS give the shortest path?
         (BFS: O(V+E), only correct for unweighted graphs;
          Dijkstra: O(E log V), correct for non-negative weighted graphs)
         Asked at: Amazon, Google, Microsoft

  ★[T][ ] Can std::queue be iterated? Why or why not?
          (No — queue doesn't expose iterators; only front() and back() accessible)
          Asked at: TCS, Wipro, Persistent

  ★[T][ ] What is the difference between std::queue and std::deque?
          (queue: restrictor adaptor — only push_back/pop_front/front/back;
           deque: full container — both ends + random access + iterators)
          Asked at: TCS, Wipro, Zoho, Persistent

  ★[T][ ] What is a priority queue? How is it different from a regular queue?
          (priority_queue: highest priority element is always at the front;
           queue: strictly FIFO — order of insertion preserved)
          Asked at: TCS, Wipro, Amazon, Zoho

  ★[T][ ] What is multi-source BFS? When would you use it?
          (BFS started simultaneously from multiple source nodes;
           used when multiple cells/nodes are sources: rotten oranges, walls & gates)
          Asked at: Amazon, Google, Microsoft, Flipkart

  ★[T][ ] What is 0-1 BFS? How is it different from regular BFS?
          (Edges have weight 0 or 1; use deque instead of queue:
           0-weight → push to front; 1-weight → push to back; O(V+E))
          Asked at: Google, competitive programming, advanced graph roles

--------------------------------------------------------------------------------
1B. QUEUE PATTERNS IN ALGORITHMS
--------------------------------------------------------------------------------

  ★[T][ ] Why is BFS guaranteed to find the shortest path in an unweighted graph?
          (Queue maintains FIFO order — nodes at distance d are all processed
           before nodes at distance d+1)
          Asked at: TCS, Wipro, Amazon, Microsoft, Google

  ★[T][ ] What is the difference between level-order traversal of a tree
          and BFS on a general graph?
          (Tree: no cycles, no visited array needed;
           Graph: cycles possible, need visited[] to avoid infinite loops)
          Asked at: Amazon, Microsoft, TCS

  ★[T][ ] What is Kahn's algorithm? What queue-based technique does it use?
          (Topological sort via BFS: enqueue all nodes with in-degree 0,
           process and reduce neighbors' in-degrees, enqueue when in-degree reaches 0)
          Asked at: Amazon, Microsoft, Google, Flipkart

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. BASIC QUEUE OPERATIONS & IMPLEMENTATION
--------------------------------------------------------------------------------

  [C][ ] (E) Implement a queue using a singly linked list.
             enqueue at rear, dequeue from front — both O(1).
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Implement a circular queue using a fixed-size array.
             Handle wrap-around with modular arithmetic.
             isFull(), isEmpty(), enqueue(), dequeue(), front().
             Asked at: TCS, Wipro, Sasken, Dolat Capital

  [C][ ] (E) Implement a queue using two stacks (amortized O(1) per operation).
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Implement a queue using a single stack and recursion only.
             (Call stack acts as implicit second stack)
             Asked at: Amazon, Microsoft

  [C][ ] (E) Reverse the first K elements of a queue.
             Push first K elements to a stack, pop back into queue, then
             move remaining elements to the back.
             Asked at: Amazon, Flipkart

  [C][ ] (E) Given a queue of integers, rearrange so all even numbers come before odd.
             Maintain relative order within each group.
             Asked at: Amazon, TCS

  [C][ ] (E) Implement a queue that rejects duplicate values.
             Use an unordered_set + queue combo.
             Asked at: Amazon, Zoho

  [C][ ] (E) Print all binary numbers from 1 to N using a queue.
             Enqueue "1"; each step: dequeue front, print it,
             enqueue front+"0" and front+"1".
             Asked at: Amazon, TCS, Zoho

  [C][ ] (E) Interleave the first and second halves of a queue.
             Input: 1 2 3 4 5 6 → Output: 1 4 2 5 3 6
             Use stack for second half.
             Asked at: Amazon, Zoho

  [C][ ] (E) Reverse a queue without using any extra data structure.
             (Use recursion — dequeue, recurse, enqueue)
             Asked at: Amazon, TCS, Zoho

  [C][ ] (E) Circular Tour problem — find the starting gas station from which
             a truck can complete the circular route without running empty.
             Greedy + queue simulation — O(N).
             Asked at: Amazon, Flipkart — LeetCode 134

  ★[C][ ] (E) Implement a queue that supports enqueue, dequeue, and peek (front)
              using std::queue. Then write the same using std::deque directly.
              Compare what extra operations deque provides.
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Given a queue, move all elements greater than X to a second queue.
              Preserve relative order in both queues.
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Implement a thread-safe wrapper around std::queue with
              enqueue and dequeue protected by a mutex.
              Asked at: Zoho, Persistent, entry-level system roles

--------------------------------------------------------------------------------
2B. LEVEL-ORDER TRAVERSAL (TREE + QUEUE)
--------------------------------------------------------------------------------

  [C][ ] (E) Level order traversal of binary tree — print all nodes level by level.
             Use a queue. BFS on tree.
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe

  ★[C][ ] (E) Level order traversal — print each level on a SEPARATE LINE.
              (Use null marker or size-based level tracking)
              Asked at: Amazon, Microsoft, Flipkart, Zoho

  ★[C][ ] (E) Find the maximum value at each level of a binary tree using BFS.
              Asked at: Amazon, Microsoft, Flipkart

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. BFS ON GRAPHS & GRIDS
--------------------------------------------------------------------------------

  [C][ ] (M) BFS shortest path in an unweighted graph.
             Return the minimum number of edges from source to destination.
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Rotten Oranges — find minimum minutes to rot all oranges.
             Multi-source BFS from all rotten oranges simultaneously.
             Return -1 if any fresh orange cannot be reached.
             Asked at: Amazon, Microsoft, Flipkart, Swiggy — LeetCode 994

  [C][ ] (M) Number of Islands — count connected components of 1s in a grid.
             BFS from each unvisited 1, mark visited. O(M*N).
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][ ] (M) Jump Game — minimum number of jumps to reach end of array.
             BFS on implicit graph: each index is a node, edges to reachable indices.
             Asked at: Amazon, Google, Microsoft — LeetCode 45

  [C][ ] (M) Shortest path in a binary matrix (0 = passable, 1 = blocked).
             8-directional BFS from top-left to bottom-right.
             Asked at: Amazon, Google, Microsoft — LeetCode 1091

  [C][ ] (M) Word Ladder — minimum transformations to reach target word,
             changing one letter at a time, using a word dictionary.
             BFS where each word is a node. O(N * L²).
             Asked at: Amazon, Microsoft, Google, Flipkart — LeetCode 127

  ★[C][ ] (M) Walls and Gates — fill each empty room with distance to nearest gate.
              Multi-source BFS from all gates simultaneously.
              Asked at: Amazon, Microsoft, Google — LeetCode 286

  ★[C][ ] (M) Pacific Atlantic Water Flow — find cells that can flow to both oceans.
              Multi-source BFS from both coasts inward (reverse flow direction).
              Asked at: Amazon, Google — LeetCode 417

  ★[C][ ] (M) 01 Matrix — for each cell, find distance to nearest 0.
              Multi-source BFS from all 0s simultaneously — O(M*N).
              Asked at: Amazon, Flipkart, Microsoft — LeetCode 542

  ★[C][ ] (M) Flood Fill — change all connected cells of the same original color
              to the new color. BFS from source cell.
              Asked at: Amazon, Microsoft, Adobe — LeetCode 733

  ★[C][ ] (M) Minimum Knight Moves on a chessboard from (0,0) to (x,y).
              BFS with 8 possible knight moves — O(|x| * |y|).
              Asked at: Amazon, Microsoft, Google

  ★[C][ ] (M) Snakes and Ladders — minimum dice rolls to reach square N*N.
              BFS on board positions — O(N²).
              Asked at: Amazon, Google — LeetCode 909

--------------------------------------------------------------------------------
3B. BFS ON TREES
--------------------------------------------------------------------------------

  [C][ ] (M) Zigzag level order traversal of binary tree.
             Alternate between left-to-right and right-to-left per level.
             Asked at: Amazon, Microsoft, Flipkart — LeetCode 103

  [C][ ] (M) Connect nodes at the same level (next right pointer).
             Use BFS — O(N) time O(N) space.
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find the right view of a binary tree (last node at each level).
             BFS: record the last node processed at each level.
             Asked at: Amazon, Flipkart, Adobe

  ★[C][ ] (M) Find the left view of a binary tree (first node at each level).
              Asked at: Amazon, TCS, Flipkart, Adobe

  ★[C][ ] (M) Find the vertical order traversal of a binary tree.
              BFS + map<col, vector> by horizontal distance.
              Asked at: Amazon, Microsoft, Google — LeetCode 987

  ★[C][ ] (M) Binary tree level order traversal II — bottom-up level order.
              BFS then reverse the result vector.
              Asked at: Amazon, Flipkart — LeetCode 107

  ★[C][ ] (M) Find the minimum depth of a binary tree (nearest leaf to root).
              BFS — stops at the first leaf found.
              Asked at: Amazon, Microsoft, TCS

  ★[C][ ] (M) Check if a binary tree is complete using BFS.
              (Once a null node is found in BFS, no non-null should follow)
              Asked at: Amazon, Microsoft, TCS

  ★[C][ ] (M) All nodes at distance K from a target node in a binary tree.
              BFS with parent pointers (build parent map first).
              Asked at: Amazon, Microsoft, Google — LeetCode 863

--------------------------------------------------------------------------------
3C. TOPOLOGICAL SORT & SCHEDULING
--------------------------------------------------------------------------------

  [C][ ] (M) Topological sort using Kahn's algorithm (BFS with in-degrees).
             Detect cycle: if output size < number of nodes → cycle exists.
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Course Schedule I — can you finish all N courses given prerequisites?
             Cycle detection using Kahn's BFS topological sort.
             Asked at: Amazon, Microsoft, Google, Flipkart — LeetCode 207

  ★[C][ ] (M) Course Schedule II — return a valid order to take all courses.
              Kahn's BFS topological sort — return order of processing.
              Asked at: Amazon, Microsoft, Google — LeetCode 210

  ★[C][ ] (M) Parallel Courses — minimum number of semesters to finish all courses
              if you can take all prerequisites-satisfied courses simultaneously.
              BFS level count = number of semesters — O(V+E).
              Asked at: Amazon, Google, Microsoft

  ★[C][ ] (M) Alien Dictionary — given words in sorted order from an alien language,
              find the order of characters. BFS topological sort on character graph.
              Asked at: Amazon, Google, Flipkart, Microsoft

--------------------------------------------------------------------------------
3D. STREAM & DESIGN PROBLEMS
--------------------------------------------------------------------------------

  [C][ ] (M) First non-repeating character in a stream of characters.
             Use queue to maintain candidates + map for counts.
             Output the first non-repeating after each character arrives.
             Asked at: Amazon, Flipkart, Paytm, Swiggy

  [C][ ] (M) Moving average from a data stream — given window size K,
             compute the average of the last K elements after each insertion.
             Use queue: enqueue new, dequeue oldest when size exceeds K.
             Asked at: Amazon, Goldman Sachs, Facebook/Meta

  [C][ ] (M) Implement a task scheduler with priority: tasks arrive with priority,
             execute highest priority first; FIFO within same priority.
             Use priority_queue with custom comparator.
             Asked at: Amazon, Microsoft, Dolat Capital

  [C][ ] (M) Number of visible people in a queue.
             Person i can see person j if all people between them are shorter.
             Monotonic stack (adjacent taller person blocks view) — O(N).
             Asked at: Amazon, Google — LeetCode 1944

  [C][ ] (M) Reconstruct queue by height:
             People with (height h, k people in front taller than them).
             Sort by height desc, insert at position k in result.
             Asked at: Amazon, Google — LeetCode 406

  ★[C][ ] (M) Given N numbers in a queue, generate numbers with digits 1 and 3 only,
              in sorted order, using BFS on a queue.
              Asked at: Amazon, Zoho, competitive programming

  ★[C][ ] (M) Implement a print queue with priority override:
              Normal tasks enqueue; urgent tasks jump to the front.
              Use deque underneath — push_back for normal, push_front for urgent.
              Asked at: Zoho, Adobe, Persistent

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Implement a blocking queue in C++ with multiple producers and consumers.
             Use mutex + condition_variable.
             Producers block when full; consumers block when empty.
             Asked at: Dolat Capital, Amazon, Microsoft, Persistent

  [C][ ] (H) Design a message queue system:
             publish(topic, message), subscribe(topic), consume(topic) → message.
             Support multiple topics.
             Asked at: Dolat Capital, Amazon, Adobe

  [C][ ] (H) Given a sequence of enqueue and dequeue operations with timestamps,
             find the maximum queue size at any point in time.
             Event-based sweep / difference array approach.
             Asked at: Goldman Sachs, Dolat Capital

  [C][ ] (H) Word Ladder II — find ALL shortest transformation sequences.
             BFS to find shortest length + backtracking on the BFS graph.
             O(N * L² * branching_factor).
             Asked at: Amazon, Google, Microsoft — LeetCode 126

  ★[C][ ] (H) Implement a thread-safe bounded blocking queue (producer-consumer):
              Fixed capacity C; enqueue blocks if full; dequeue blocks if empty.
              Use mutex + two condition_variables (not_full, not_empty).
              Asked at: Dolat Capital, Amazon, Microsoft, Persistent
              (Classic multithreading problem!)

  ★[C][ ] (H) Shortest path visiting all nodes in an undirected graph.
              BFS with bitmask state (node, visited_mask) — O(N² * 2^N).
              Asked at: Google, Amazon — LeetCode 847

  ★[C][ ] (H) Bus Routes — find minimum number of buses to reach target stop.
              Model each bus route as a node; BFS on bus graph.
              Asked at: Amazon, Google — LeetCode 815

  ★[C][ ] (H) Open the Lock — minimum number of turns to reach target combination
              from "0000", avoiding deadends. BFS on 4-digit string states.
              Asked at: Amazon, Google — LeetCode 752

  ★[C][ ] (H) Sliding Puzzle — minimum moves to solve a 2×3 sliding puzzle.
              BFS on board states encoded as strings.
              Asked at: Google, Amazon — LeetCode 773

  ★[C][ ] (H) Design a task queue that supports:
              submit(task, priority, deadline),
              getNext() — returns highest priority task respecting deadlines,
              cancel(taskId).
              Use priority_queue with lazy deletion.
              Asked at: Amazon, Microsoft, Dolat Capital

================================================================================
SECTION 5 — TRICKY OUTPUT / CONCEPT QUESTIONS
================================================================================

  ★[T][ ] What is the output?
          queue<int> q;
          q.push(1); q.push(2); q.push(3);
          while (!q.empty()) { cout << q.front() << " "; q.pop(); }
          (Output: 1 2 3 — FIFO order)
          Asked at: TCS, Wipro, Capgemini

  ★[T][ ] What is wrong with this code?
          queue<int> q;
          q.push(5);
          cout << q.back();
          q.pop();
          cout << q.front(); // BUG: queue is now empty!
          (Calling front() on empty queue is undefined behavior)
          Asked at: TCS, Wipro, Amazon, Persistent

  ★[T][ ] Why can't you use std::list as the underlying container for std::queue?
          Wait — you CAN. What containers CANNOT be used?
          (Cannot use vector — lacks pop_front; cannot use set/map — not sequences;
           CAN use deque or list)
          Asked at: Persistent, Nagarro, advanced C++ roles

  ★[T][ ] Why does BFS give the shortest path in an unweighted graph
          but NOT in a weighted graph?
          (BFS explores in FIFO order — level by level;
           in weighted graphs, a path with more edges may have less total cost)
          Asked at: TCS, Amazon, Microsoft, Google

  ★[T][ ] What is the difference between a blocking queue and a regular queue?
          When would you use each?
          (Blocking: thread waits when empty/full — used in producer-consumer;
           Regular: returns immediately — used in single-threaded algorithms)
          Asked at: Amazon, Microsoft, Dolat Capital, Persistent

  ★[T][ ] In BFS on a graph, what happens if you do NOT mark nodes as visited
          before enqueuing them (only mark when dequeuing)?
          (Nodes can be enqueued multiple times → O(V + E) becomes O(V * E)
           and infinite loop for graphs with cycles)
          Asked at: Amazon, Microsoft, Google

================================================================================
SUMMARY COUNT
================================================================================

  Category                                      | E  | M  | H  | Total
  ----------------------------------------------|----|----|----|---------
  Theory — std::queue Internals & Design        | 16 |  0 |  0 |    16
  Theory — Queue Patterns in Algorithms         |  3 |  0 |  0 |     3
  Coding Easy — Basic Queue Operations          | 14 |  0 |  0 |    14
  Coding Easy — Level Order Traversal           |  3 |  0 |  0 |     3
  Coding Medium — BFS on Graphs & Grids         |  0 | 12 |  0 |    12
  Coding Medium — BFS on Trees                  |  0 |  9 |  0 |     9
  Coding Medium — Topological Sort              |  0 |  5 |  0 |     5
  Coding Medium — Stream & Design               |  0 |  7 |  0 |     7
  Coding Hard                                   |  0 |  0 | 10 |    10
  Tricky Output / Concept Questions             |  6 |  0 |  0 |     6
  ----------------------------------------------|----|----|----|---------
  TOTAL                                         | 42 | 33 | 10 |    85

  ★ = 46 questions added from real interviews not in source files

================================================================================
QUICK REFERENCE — MOST ASKED BY COMPANY
================================================================================

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    → FIFO definition, implement queue with array/linked list, circular queue,
      queue vs stack, BFS concept, level order traversal, print binary numbers

  ZOHO:
    → Queue from two stacks, reverse first K elements, rearrange even/odd,
      duplicate-rejecting queue, circular tour problem, first non-repeating char

  AMAZON / FLIPKART / PAYTM:
    → BFS shortest path, rotten oranges, number of islands, word ladder,
      zigzag level order, course schedule, first non-repeating in stream,
      moving average, jump game, reconstruct queue by height

  MICROSOFT / ADOBE:
    → Connect nodes at same level, right view, left view, complete tree check,
      walls & gates, topological sort, alien dictionary, BFS vs DFS

  GOOGLE / ATLASSIAN:
    → Word ladder II, all nodes at distance K, shortest path visiting all nodes,
      open the lock, sliding puzzle, bus routes, Kahn's algorithm, 0-1 BFS

  GOLDMAN SACHS / DOLAT CAPITAL / HFT FIRMS:
    → Blocking queue (producer-consumer), thread-safe queue, message queue design,
      max queue size from timestamps, Dijkstra vs BFS, bounded blocking queue,
      task queue with priority + deadline + cancel

================================================================================
END
================================================================================
