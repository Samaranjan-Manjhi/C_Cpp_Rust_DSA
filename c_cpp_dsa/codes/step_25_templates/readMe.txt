================================================================================
        TEMPLATES — COMPLETE REFERENCE + QUESTION BANK
        Topics: Function Templates, Class Templates, Specialization,
                Variadic Templates, SFINAE, Concepts, TMP, Modern C++
        Compiled from all_in_one + all_in_one_question_1/2/3/4
        No duplicates | Theory + Coding | All difficulties
        ★ = Extra question added (real company interview, not in source files)
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
PART 1 — CONCEPT EXPLANATIONS
================================================================================

────────────────────────────────────────────────────────────────────────────────
1.1  FUNCTION TEMPLATES
────────────────────────────────────────────────────────────────────────────────

  What it is:
    A blueprint that generates a function for each type it is called with.
    The compiler stamps out a concrete function at each call site.

  Syntax:
    template <typename T>
    T add(T a, T b) { return a + b; }

    add<int>(3, 4);       // explicit instantiation
    add(3, 4);            // implicit — compiler deduces T = int
    add(3.0, 4.0);        // compiler deduces T = double

  Key Points:
    • "typename" and "class" are interchangeable in template parameter list.
    • Template code lives in headers (not .cpp) because the compiler needs
      the full definition at instantiation time.
    • Each unique type produces a separate compiled function (code bloat).
    • Template argument deduction follows its own rules — can fail for
      mixed types (add(3, 4.0) fails because T can't be both int and double).
    • Use explicit template arguments or casts to resolve ambiguity.

  Multiple Type Parameters:
    template <typename T, typename U>
    auto add(T a, U b) -> decltype(a + b) { return a + b; }

────────────────────────────────────────────────────────────────────────────────
1.2  CLASS TEMPLATES
────────────────────────────────────────────────────────────────────────────────

  What it is:
    A blueprint for a class that works with any type.
    Every member function of a class template is itself a template.

  Syntax:
    template <typename T>
    class Stack {
        vector<T> data;
    public:
        void push(T x)  { data.push_back(x); }
        T    pop()       { T x = data.back(); data.pop_back(); return x; }
        T    top() const { return data.back(); }
        bool empty() const { return data.empty(); }
    };

    Stack<int>    intStack;
    Stack<string> strStack;

  Key Points:
    • Member function definitions outside the class need the template header:
        template <typename T>
        void Stack<T>::push(T x) { data.push_back(x); }
    • Non-type template parameters are allowed:
        template <typename T, int N>
        class FixedArray { T arr[N]; };      // size known at compile time
    • Class template argument deduction (CTAD) in C++17:
        Stack s;  // compiler deduces T if a deduction guide exists.

────────────────────────────────────────────────────────────────────────────────
1.3  TEMPLATE SPECIALIZATION
────────────────────────────────────────────────────────────────────────────────

  Full (Explicit) Specialization — override for a specific type:
    template <>
    class Stack<bool> {
        // custom space-efficient implementation using bitset
    };

    template <>
    int add<int>(int a, int b) { return a + b; }  // fully specialized function

  Partial Specialization — override for a category of types (class templates only):
    template <typename T>
    class Stack<T*> {
        // specialization for all pointer types
    };

  Key Points:
    • Full specialization: template<> prefix, all params fixed.
    • Partial specialization: some params still generic.
    • Functions cannot be partially specialized — use overloading instead.
    • Specializations must be declared before use to avoid ODR issues.

────────────────────────────────────────────────────────────────────────────────
1.4  VARIADIC TEMPLATES (C++11)
────────────────────────────────────────────────────────────────────────────────

  What it is:
    Templates that accept any number of type parameters.
    Used to implement std::tuple, std::function, printf-like functions.

  Syntax:
    template <typename... Args>
    void print(Args... args) { (cout << ... << args); }  // fold expression C++17

    // Recursive approach (pre-C++17):
    void print() {}                                   // base case
    template <typename T, typename... Rest>
    void print(T first, Rest... rest) {
        cout << first << " ";
        print(rest...);
    }

  sizeof... operator:
    template <typename... T>
    constexpr size_t count() { return sizeof...(T); }   // number of args

  Fold Expressions (C++17):
    (args + ...)           // right fold:  a+(b+(c+0))
    (... + args)           // left fold:   ((0+a)+b)+c
    (args + ... + init)    // right fold with initial value
    (init + ... + args)    // left fold with initial value

  Key Points:
    • Parameter pack must be expanded with "..." suffix.
    • Enables zero-overhead abstractions (vs C varargs).
    • Base case for recursion can be an overload, not just empty.

────────────────────────────────────────────────────────────────────────────────
1.5  SFINAE — Substitution Failure Is Not An Error
────────────────────────────────────────────────────────────────────────────────

  What it is:
    When the compiler tries to substitute a type into a template and fails,
    it does NOT raise a compile error — it simply removes that overload
    from the candidate set (silently discards it).

  Classic use — enable a function only for integral types:
    template <typename T>
    typename enable_if<is_integral<T>::value, T>::type
    only_for_ints(T x) { return x; }

  C++14 helper alias:
    template <typename T>
    enable_if_t<is_integral_v<T>, T>
    only_for_ints(T x) { return x; }

  Key Points:
    • Only applies to immediate context of template substitution.
    • The preferred modern alternative is Concepts (C++20).
    • std::void_t is used to detect the existence of a member type/function.
    • Detection idiom pattern: check if T has a .begin() method:
        template <typename T, typename = void>
        struct has_begin : false_type {};

        template <typename T>
        struct has_begin<T, void_t<decltype(declval<T>().begin())>>
            : true_type {};

────────────────────────────────────────────────────────────────────────────────
1.6  TYPE TRAITS  (#include <type_traits>)
────────────────────────────────────────────────────────────────────────────────

  Compile-time type queries:
    is_integral<T>::value         // true for int, long, char, bool, etc.
    is_floating_point<T>::value   // true for float, double, long double
    is_pointer<T>::value
    is_same<T, U>::value          // T and U are the same type
    is_base_of<Base, Derived>::value
    is_const<T>::value
    is_reference<T>::value
    is_trivially_copyable<T>::value
    is_default_constructible<T>::value

  Type transformations:
    remove_const<T>::type         // T without const
    remove_reference<T>::type     // T without & or &&
    decay<T>::type                // removes ref, const, array/func decay
    add_pointer<T>::type          // T*

  C++17 _v and _t helpers (shorter syntax):
    is_integral_v<T>              // same as is_integral<T>::value
    remove_const_t<T>             // same as remove_const<T>::type

────────────────────────────────────────────────────────────────────────────────
1.7  CONSTEXPR AND CONSTEVAL (C++20)
────────────────────────────────────────────────────────────────────────────────

  constexpr function — may be evaluated at compile time if args are constant:
    constexpr int factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }
    constexpr int f5 = factorial(5);   // computed at compile time

  constexpr if (C++17) — compile-time branching in templates:
    template <typename T>
    auto process(T x) {
        if constexpr (is_integral_v<T>)  return x * 2;
        else                             return x + 0.5;
    }

  consteval (C++20) — MUST be evaluated at compile time (error otherwise):
    consteval int square(int x) { return x * x; }

  Key Points:
    • constexpr is "possibly at compile time"; consteval is "always".
    • constexpr if eliminates dead branches entirely (no instantiation error).
    • Template Metaprogramming (TMP) historically used recursive templates;
      modern C++ prefers constexpr functions — same power, far more readable.

────────────────────────────────────────────────────────────────────────────────
1.8  CONCEPTS (C++20)
────────────────────────────────────────────────────────────────────────────────

  What it is:
    Named compile-time constraints on template parameters.
    Replaces SFINAE with readable, human-friendly error messages.

  Define a concept:
    template <typename T>
    concept Numeric = is_integral_v<T> || is_floating_point_v<T>;

  Use it:
    template <Numeric T>
    T square(T x) { return x * x; }

    // or with requires:
    template <typename T>
    requires Numeric<T>
    T cube(T x) { return x * x * x; }

  Built-in standard concepts (in <concepts>):
    std::integral, std::floating_point, std::same_as,
    std::derived_from, std::convertible_to, std::invocable,
    std::copyable, std::default_initializable

────────────────────────────────────────────────────────────────────────────────
1.9  CRTP — Curiously Recurring Template Pattern
────────────────────────────────────────────────────────────────────────────────

  What it is:
    A derived class passes itself as a template argument to the base class.
    Enables static polymorphism (no virtual call overhead).

    template <typename Derived>
    class Base {
    public:
        void interface() {
            static_cast<Derived*>(this)->implementation();
        }
    };

    class Derived : public Base<Derived> {
    public:
        void implementation() { cout << "Derived impl\n"; }
    };

  When to use:
    • Performance-critical code where virtual dispatch overhead matters.
    • Mixins — adding functionality to many classes without inheritance.
    • Counter of instances, operator chaining (builder pattern).

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

────────────────────────────────────────────────────────────────────────────────
2A. CORE THEORY (from source files)
────────────────────────────────────────────────────────────────────────────────

  [T][ ] What is a template? What problem does it solve?
         (Avoids code duplication — write once, works for many types)
         Asked at: Amazon, TCS, Wipro, Persistent

  [T][ ] What is the difference between function template and class template?
         Asked at: Amazon, TCS, Wipro

  [T][ ] What is template specialization? Full vs partial?
         Asked at: Google, Persistent, Nagarro

  [T][ ] What is template instantiation? When does it happen?
         (At compile time, when the template is first used with a given type)
         Asked at: Google, Atlassian

  [T][ ] What is SFINAE? What is std::enable_if?
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is a variadic template? Give a simple example.
         Asked at: Google, advanced C++ roles

  [T][ ] What is std::decltype? When would you use it over auto?
         (decltype queries the type of an expression without evaluating it)
         Asked at: Google, advanced C++ roles

  [T][ ] What is perfect forwarding? What problem does it solve?
         (Forwarding references + std::forward preserve value category — lvalue/rvalue)
         Asked at: Google, Atlassian, advanced C++ roles

  [T][ ] What is a fold expression in C++17? Give an example.
         Asked at: Advanced C++ roles, Google

  [T][ ] What is constexpr if (C++17)? How is it different from regular if?
         (Evaluated at compile time — dead branch is not instantiated at all)
         Asked at: Google, advanced C++ roles

  [T][ ] What is the Curiously Recurring Template Pattern (CRTP)?
         Asked at: Google, Dolat Capital, HFT roles

  [T][ ] What is std::optional? When would you use it over a pointer?
         (Nullable value without heap allocation; signals "value or nothing")
         Asked at: Google, advanced C++ roles

  [T][ ] What is std::variant? How is it different from union?
         (Type-safe tagged union; no undefined behavior accessing wrong type)
         Asked at: Google, advanced C++ roles

────────────────────────────────────────────────────────────────────────────────
2B. ADVANCED THEORY (★ extra questions)
────────────────────────────────────────────────────────────────────────────────

  ★[T][ ] Why must template definitions go in header files?
           (Compiler needs full definition at instantiation point — no separate
            compilation. Exception: explicit instantiation in .cpp.)
           Asked at: Amazon, Adobe, Persistent, Nagarro

  ★[T][ ] What is the difference between typename and class in a template
           parameter list? Is there any real difference?
           (None in most contexts; typename required when accessing dependent
            type names inside a template body: typename T::value_type)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] What is a dependent name? Why do you need "typename" or "template"
           when accessing dependent names?
           (Name depends on a template parameter — compiler can't know if it's
            a type or value without the hint)
           Asked at: Google, advanced C++ roles

  ★[T][ ] What is template argument deduction? What are its limits?
           (Compiler infers T from function arguments; fails for ambiguous types,
            non-deduced contexts, or when result type can't be deduced)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] What is std::void_t and the detection idiom?
           (void_t<expr> is void if expr is valid, SFINAE otherwise —
            used to detect presence of member functions/types at compile time)
           Asked at: Google, advanced C++ roles

  ★[T][ ] What is Two-Phase Name Lookup in templates?
           (Phase 1: non-dependent names resolved at template definition;
            Phase 2: dependent names resolved at instantiation)
           Asked at: Google, Atlassian, advanced C++ roles

  ★[T][ ] What is explicit template instantiation? Why use it?
           (Forces compiler to generate code in a specific .cpp — reduces
            compile times and binary size; avoids repeated instantiation)
           Asked at: Advanced C++ roles, embedded systems

  ★[T][ ] What is the difference between is_same<T,U> and is_convertible<T,U>?
           Asked at: Amazon, Adobe, advanced C++ roles

  ★[T][ ] What are Concepts (C++20)? How do they improve over SFINAE?
           (Named constraints on template params; much better error messages;
            shorter syntax; constraints propagate to overload resolution)
           Asked at: Google, Atlassian, modern C++ roles

  ★[T][ ] What is template metaprogramming (TMP)? Give a real-world use case.
           (Computation done at compile time using templates + specializations;
            used in Eigen, Boost.MPL, policy-based design)
           Asked at: Goldman Sachs, Dolat Capital, HFT roles

================================================================================
PART 3 — CODING QUESTIONS
================================================================================

EASY
─────
  [C][ ] (E) Generic swap function using templates (without using std::swap)
             Asked at: Amazon, Zoho, TCS

  [C][ ] (E) Generic max function for any comparable type
             Asked at: Amazon, TCS, Wipro

  [C][ ] (E) Generic Stack class using templates
             Asked at: Amazon, TCS, Google

  [C][ ] (E) Generic Pair class (own implementation)
             Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Write a template function findMin(T arr[], int n) that works
              for int, float, and string arrays
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Write a template function to print all elements of any STL container
              (works with vector, list, set, etc.)
              Asked at: TCS, Persistent, Nagarro

  ★[C][ ] (E) Implement a template function that checks if an array is sorted
              for any type with operator<
              Asked at: Amazon, TCS, Wipro

MEDIUM
───────
  [C][ ] (M) Generic Stack class with exception on empty pop/top
             Asked at: Amazon, Google, Atlassian

  [C][ ] (M) Implement a type-safe printf using variadic templates
             myprintf("%d %s", 42, "hello")
             Asked at: Google, advanced C++ roles

  [C][ ] (M) Implement compile-time Fibonacci using constexpr or TMP
             Asked at: Google, Atlassian, Samsung

  [C][ ] (M) Implement a generic tuple using variadic templates
             get<0>(t), get<1>(t) access
             Asked at: Advanced C++ roles, Google

  [C][ ] (M) Implement a generic tuple_size and tuple_element using TMP
             Asked at: Google, advanced C++ roles

  ★[C][ ] (M) Write a template class Matrix<T, Rows, Cols> with non-type
              template parameters for compile-time dimension checking
              Asked at: Samsung, Qualcomm, embedded systems roles

  ★[C][ ] (M) Implement a compile-time power function: Power<2,10>::value = 1024
              Using template metaprogramming (recursive specialization)
              Asked at: Goldman Sachs, HFT roles, competitive programming

  ★[C][ ] (M) Write an is_even<N> template that evaluates to true/false at compile time
              using partial specialization
              Asked at: TCS, Wipro, Persistent

  ★[C][ ] (M) Implement a type-safe variant that can hold int, double, or string
              using template + union concepts (simplified std::variant)
              Asked at: Google, advanced C++ roles

  ★[C][ ] (M) Write a template function that accepts only integral types using
              std::enable_if / concepts; show both approaches
              Asked at: Google, Atlassian, Amazon

  ★[C][ ] (M) Implement a CRTP-based shape hierarchy with area() computed
              without virtual functions
              Asked at: Goldman Sachs, Dolat Capital, Google

HARD
─────
  [C][ ] (H) Implement a type-erased function wrapper like std::function<>
             from scratch using template + virtual dispatch inside
             Asked at: Google, advanced C++ roles

  ★[C][ ] (H) Implement a compile-time type list (TypeList<T1, T2, T3>) that
              supports: Length, TypeAt<I>, Contains, IndexOf, Append
              Asked at: Boost/template-heavy codebases, advanced C++ roles

  ★[C][ ] (H) Write a template-based Observer pattern where the event type is
              a template parameter and callbacks are stored type-safely
              Asked at: Adobe, advanced C++ roles, game dev

  ★[C][ ] (H) Implement std::invoke from scratch — calls any callable with any args
              (function pointer, lambda, functor, member function pointer)
              Asked at: Google, advanced C++ roles

================================================================================
QUICK REFERENCE CHEATSHEET
================================================================================

  // Function template
  template <typename T> T add(T a, T b) { return a + b; }

  // Class template with non-type param
  template <typename T, int N> class FixedArray { T data[N]; };

  // Full specialization
  template <> int add<int>(int a, int b) { return a + b; }

  // Partial specialization (class only)
  template <typename T> class Wrapper<T*> { ... };

  // Variadic template + fold expression (C++17)
  template <typename... T>
  auto sum(T... args) { return (args + ...); }

  // SFINAE with enable_if
  template <typename T>
  enable_if_t<is_integral_v<T>, T> only_ints(T x) { return x; }

  // constexpr if
  template <typename T>
  void process(T x) {
      if constexpr (is_integral_v<T>) { /* int path */ }
      else { /* float path */ }
  }

  // Concept (C++20)
  template <typename T>
  concept Number = is_arithmetic_v<T>;
  template <Number T> T square(T x) { return x*x; }

  // CRTP
  template <typename D>
  struct Base { void run() { static_cast<D*>(this)->impl(); } };
  struct D : Base<D> { void impl() { cout << "D\n"; } };

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Concept Explanations       | 9 sections fully documented
  Theory (from files)        | 13 |  0 |  0 |    13
  Theory (★ added)           | 10 |  0 |  0 |    10
  Coding Easy (from files)   |  4 |  0 |  0 |     4
  Coding Easy (★ added)      |  3 |  0 |  0 |     3
  Coding Medium (from files) |  0 |  5 |  0 |     5
  Coding Medium (★ added)    |  0 |  6 |  0 |     6
  Coding Hard (from files)   |  0 |  0 |  1 |     1
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL Q&A                  | 30 | 11 |  4 |    45

================================================================================
END
================================================================================
