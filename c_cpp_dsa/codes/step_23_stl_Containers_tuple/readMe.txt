================================================================================
        TUPLE — COMPLETE QUESTION BANK
        Compiled from all_in_one + all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        ★ = Extra question added (real company interview, not in source files)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. CORE CONCEPTS
--------------------------------------------------------------------------------

  [T][ ] What is std::tuple? How is it different from std::pair?
         (tuple holds N heterogeneous elements; pair is fixed at exactly 2)
         Header: <tuple>
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] How do you access elements of a tuple?
         (get<0>(t), get<1>(t), get<2>(t) — index must be compile-time constant)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is std::make_tuple()? When do you use it?
         (Convenience function to deduce types: auto t = make_tuple(1, "hi", 3.14))
         Asked at: Amazon, TCS, Wipro

  [T][ ] Can you use structured bindings (C++17) with tuple?
         (Yes: auto [a, b, c] = t; — binds each element to a variable)
         Asked at: Amazon, Google, Microsoft, Adobe

  [T][ ] What is std::tie() and how is it used with tuple?
         (tie(a, b, c) = t; — unpacks tuple into existing variables;
          use std::ignore to skip elements: tie(a, ignore, c) = t)
         Asked at: Amazon, Google, Microsoft

  [T][ ] Can you compare two tuples with < or ==?
         (Yes — lexicographic comparison, element by element)
         Asked at: Amazon, Flipkart, Microsoft

  [T][ ] What is std::tuple_size<T>::value?
         (Compile-time constant giving the number of elements in a tuple type)
         Asked at: Google, advanced C++ roles

  [T][ ] What is std::tuple_element<I, T>::type?
         (Gives the type of the I-th element in tuple type T)
         Asked at: Google, advanced C++ roles

  [T][ ] What is std::get<> used for? Can you use a type instead of index?
         (Yes in C++14+: get<int>(t) if int appears exactly once in the tuple)
         Asked at: Google, Microsoft, Adobe

  [T][ ] How would you convert a pair to a tuple and vice versa?
         (make_tuple(p.first, p.second); or
          make_pair(get<0>(t), get<1>(t)))
         Asked at: Amazon, Microsoft

  [T][ ] What is std::forward_as_tuple()? When is it useful?
         (Creates a tuple of lvalue/rvalue references without copying;
          useful for perfect forwarding in template code)
         Asked at: Google, advanced C++ roles

  [T][ ] Can you store tuples in a vector, map, or unordered_map?
         (vector: yes. map: yes if tuple has < operator.
          unordered_map as key: needs custom hash)
         Asked at: Amazon, Microsoft, Adobe

--------------------------------------------------------------------------------
1B. ADVANCED / INTERVIEW DEPTH
--------------------------------------------------------------------------------

  ★[T][ ] What is std::tuple_cat()? Give a use case.
           (Concatenates multiple tuples into one:
            auto t3 = tuple_cat(t1, t2); — useful in variadic template programming)
           Asked at: Google, advanced C++ roles

  ★[T][ ] How do you iterate over a tuple at runtime (since indices must be
           compile-time constants)?
           (Use std::apply + lambda, or recursive template with index_sequence)
           Asked at: Google, Microsoft, advanced C++ roles

  ★[T][ ] What is std::apply()? How does it work with tuple?
           (std::apply(func, tuple) calls func with tuple elements as arguments;
            std::apply([](auto... args){ ... }, t))
           Asked at: Google, Amazon, advanced C++ roles

  ★[T][ ] What are variadic templates and how do they relate to tuple's implementation?
           (tuple<Ts...> is implemented using variadic template parameter pack;
            each type stored via recursive inheritance or EBO)
           Asked at: Google, Amazon, advanced C++ roles

  ★[T][ ] What is Empty Base Optimization (EBO) and how does it affect tuple size?
           (Compiler avoids allocating space for empty base classes;
            tuple<> of only empty types may have size 0 or 1)
           Asked at: Google, advanced C++ roles

  ★[T][ ] When would you prefer tuple over a custom struct? When would you prefer struct?
           (tuple: quick ad-hoc grouping, template metaprogramming, returning multiple values.
            struct: named fields for readability, better self-documenting code,
            when the group has clear semantic meaning)
           Asked at: Amazon, Microsoft, Google, Adobe

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

  ★[C][ ] (E) Create a tuple<int, string, double> and access all 3 elements
              using get<> and structured bindings
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Write a function that returns multiple values using tuple
              e.g., tuple<int, int, int> minMaxSum(vector<int>& v)
              Asked at: Amazon, TCS, Wipro, Infosys

  ★[C][ ] (E) Given a vector of tuple<string, int, double> (name, age, gpa),
              print all entries sorted by gpa descending
              Asked at: Amazon, Flipkart, TCS

  ★[C][ ] (E) Use std::tie() to compare two tuples element by element
              and demonstrate ignore for skipping fields
              Asked at: Amazon, TCS, Microsoft

  ★[C][ ] (E) Use tuple to implement a function returning (quotient, remainder)
              from integer division
              Asked at: TCS, Wipro, Zoho, Infosys

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

  [C][ ] (M) Implement a generic tuple using variadic templates
             get<0>(t), get<1>(t) access — from scratch
             Asked at: Advanced C++ roles, Google

  [C][ ] (M) 4Sum II: given 4 arrays A,B,C,D count tuples (i,j,k,l) where
             A[i]+B[j]+C[k]+D[l] == 0
             Hint: hashmap of pairwise sums from A+B, then search C+D
             Asked at: Amazon, Google

  ★[C][ ] (M) Sort a vector of tuple<int, string, int> by the third element
              descending, then by the first element ascending for ties
              Asked at: Amazon, Flipkart, Goldman Sachs

  ★[C][ ] (M) Given a list of employees as tuple<string, int, double>
              (name, id, salary), find the top 3 highest paid employees
              Use min-heap of size 3
              Asked at: Amazon, Microsoft, Flipkart

  ★[C][ ] (M) Write a generic zip function that takes two vectors and returns
              vector<tuple<T1, T2>> pairing elements at same index
              Asked at: Google, Adobe, advanced C++ roles

  ★[C][ ] (M) Use std::apply to write a variadic sum function that works on
              any tuple of numeric types
              Asked at: Google, advanced C++ roles

  ★[C][ ] (M) Implement a function that prints all elements of a tuple of
              any size and any types using index_sequence
              Asked at: Google, Microsoft, advanced C++ roles

  ★[C][ ] (M) Given a vector of tuple<int, int, int> representing (profit, weight, id)
              for items, find the item with best profit-to-weight ratio
              Asked at: Amazon, Goldman Sachs

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

  ★[C][ ] (H) Implement tuple_cat from scratch: concatenate two tuples of
              arbitrary types into a single tuple
              Uses index_sequence + parameter pack expansion
              Asked at: Google, advanced C++ roles

  ★[C][ ] (H) Implement a type-safe heterogeneous container using tuple
              that supports runtime indexing via visitor pattern
              Asked at: Google, advanced C++ roles

  ★[C][ ] (H) Implement a generic memoization wrapper using tuple as the
              key to cache function arguments and results
              (unordered_map with custom tuple hash)
              Asked at: Google, Amazon, Facebook/Meta

  ★[C][ ] (H) Design a pipeline of transformations where each stage takes a
              tuple as input and returns a transformed tuple
              Using std::apply and variadic templates
              Asked at: Google, advanced C++ roles, Adobe

================================================================================
QUICK REFERENCE — tuple CHEATSHEET
================================================================================

  #include <tuple>

  // Declaration and construction
  tuple<int, string, double> t = {1, "hi", 3.14};
  auto t2 = make_tuple(1, "hi", 3.14);   // type deduction

  // Access by index (compile-time constant only)
  get<0>(t);       // 1
  get<1>(t);       // "hi"
  get<2>(t);       // 3.14

  // Access by type (C++14, only if type is unique in tuple)
  get<string>(t);  // "hi"

  // C++17 structured binding
  auto [a, b, c] = t;

  // Unpack into existing variables (std::tie)
  int x; string s; double d;
  tie(x, s, d) = t;

  // Skip elements with std::ignore
  tie(x, ignore, d) = t;

  // Size and element type at compile time
  tuple_size<decltype(t)>::value;             // 3
  tuple_element<0, decltype(t)>::type;        // int

  // Concatenate tuples
  auto t3 = tuple_cat(make_tuple(1, 2), make_tuple("a", "b"));
  // t3 is tuple<int, int, const char*, const char*>

  // Call function with tuple as arguments (C++17)
  auto result = apply([](int a, string b, double c) {
      return a + c;
  }, t);

  // Comparison (lexicographic)
  t1 < t2;    // compares element by element
  t1 == t2;   // all elements must match

  // Vector of tuples
  vector<tuple<int, string, double>> v;
  v.emplace_back(1, "Alice", 9.5);
  v.emplace_back(2, "Bob",   8.7);

  // Sort by 3rd element descending
  sort(v.begin(), v.end(), [](const auto& a, const auto& b){
      return get<2>(a) > get<2>(b);
  });

  // Iterate over tuple at compile time (C++17 fold expression)
  template<typename Tuple, size_t... I>
  void printTupleImpl(const Tuple& t, index_sequence<I...>) {
      ((cout << get<I>(t) << " "), ...);
  }
  template<typename... Ts>
  void printTuple(const tuple<Ts...>& t) {
      printTupleImpl(t, make_index_sequence<sizeof...(Ts)>{});
  }

  // Custom hash for tuple<int,int,int> (for unordered_map key)
  struct TupleHash {
      size_t operator()(const tuple<int,int,int>& t) const {
          size_t h = 0;
          h ^= hash<int>()(get<0>(t)) + 0x9e3779b9 + (h<<6) + (h>>2);
          h ^= hash<int>()(get<1>(t)) + 0x9e3779b9 + (h<<6) + (h>>2);
          h ^= hash<int>()(get<2>(t)) + 0x9e3779b9 + (h<<6) + (h>>2);
          return h;
      }
  };
  unordered_map<tuple<int,int,int>, int, TupleHash> um;

================================================================================
COMMON PATTERNS WHERE TUPLE SHINES
================================================================================

  1. RETURNING MULTIPLE VALUES FROM FUNCTION
     tuple<bool, int, string> parse(const string& s);
     auto [ok, val, err] = parse(input);

  2. MULTI-KEY SORTING (sort by (priority, timestamp, id))
     sort(events.begin(), events.end()); // tuple comparison is lexicographic

  3. GRAPH EDGES WITH WEIGHT
     vector<tuple<int,int,int>> edges; // (weight, u, v) — sort for Kruskal

  4. DIJKSTRA PRIORITY QUEUE
     priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<>> pq;
     pq.push({dist, node});

  5. MEMOIZATION KEY
     map<tuple<int,int,int>, long long> memo; // dp[i][j][k]

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        | 12 |  0 |  0 |    12
  Theory (★ added)           |  6 |  0 |  0 |     6
  Coding Easy (from files)   |  0 |  0 |  0 |     0
  Coding Easy (★ added)      |  5 |  0 |  0 |     5
  Coding Medium (from files) |  0 |  2 |  0 |     2
  Coding Medium (★ added)    |  0 |  6 |  0 |     6
  Coding Hard (from files)   |  0 |  0 |  0 |     0
  Coding Hard (★ added)      |  0 |  0 |  4 |     4
  ---------------------------|----|----|----|---------
  TOTAL                      | 23 |  8 |  4 |    35

  NOTE: tuple has very few questions in the source files because it is a
  less commonly asked topic individually. The ★ questions cover real
  interview questions from Google, Amazon, Microsoft, and Adobe where tuple
  usage came up in C++ roles and advanced coding rounds.

================================================================================
END
================================================================================
