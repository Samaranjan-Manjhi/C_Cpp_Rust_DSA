#!/bin/bash
# Run from the repo root (C_Cpp_Rust_DSA):  bash setup_rust_dsa.sh
# Creates rust_dsa step folders (same numbering as c_cpp_dsa), the
# online_coding_platform layout, dates.txt, and README files.
set -e

ROOT="${1:-$(pwd)}"
R="$ROOT/rust_dsa"
[ -d "$R" ] || { echo "rust_dsa/ not found in $ROOT. Run from the repo root."; exit 1; }

# ---------- 1. step folders: "folder_name|Display topic" ----------
STEPS=(
"step_01_variables_data-types_operators|Variables, data types, operators, shadowing"
"step_02_control_flow|Control flow: if, loop, while, for, match"
"step_03_function_recursion|Functions and recursion"
"step_04_array_slice|Arrays and slices"
"step_05_ownership_borrowing_lifetimes|Ownership, borrowing, lifetimes"
"step_06_string|String and &str"
"step_07_struct_impl|Structs and impl blocks"
"step_08_traits|Traits (replaces inheritance)"
"step_09_trait_objects_polymorphism|Trait objects and dyn Trait (polymorphism)"
"step_10_modules_encapsulation|Modules, visibility, encapsulation (abstraction)"
"step_11_collections_vec|Vec"
"step_12_collections_linkedlist|LinkedList"
"step_13_collections_vecdeque|VecDeque"
"step_14_collections_stack|Stack using Vec"
"step_15_collections_queue|Queue using VecDeque"
"step_16_collections_binaryheap|BinaryHeap (priority queue)"
"step_17_collections_btreeset|BTreeSet (ordered set)"
"step_18_collections_multiset|Multiset using BTreeMap counts"
"step_19_collections_hashset|HashSet"
"step_20_collections_btreemap|BTreeMap (ordered map)"
"step_21_collections_hashmap|HashMap"
"step_22_tuples_pairs|Tuples and pairs"
"step_23_tuple_structs_enums|Tuple structs and enums"
"step_24_iterators_algorithms|Iterators and iterator adaptors"
"step_25_generics_trait_bounds|Generics and trait bounds"
"step_26_error_handling|Result, Option, ? operator"
"step_27_smart_pointers|Box, Rc, Arc, RefCell"
"step_28_file_handling|File handling (std::fs, std::io)"
"step_29_single_linked_list|Singly linked list (Option<Box<Node>>)"
"step_30_doubly_linked_list|Doubly linked list (Rc, RefCell, Weak)"
"step_31_circular_linked_list|Circular linked list"
"step_32_stack|Stack"
"step_33_queue|Queue"
"step_34_hash_maps|Hash maps"
"step_35_hash_sets|Hash sets"
"step_36_searching_algorithms|Searching algorithms"
"step_37_sorting_algorithms|Sorting algorithms"
"step_38_array_technique_2_ptr|Two pointer technique"
"step_39_array_technique_sliding_window|Sliding window"
"step_40_array_technique_kadane_algo|Kadane's algorithm"
"step_41_binary_tree|Binary tree"
"step_42_binary_search_tree|Binary search tree"
"step_43_heaps_priority_queue|Heaps and priority queue"
"step_44_advanced_trees_AVL|AVL tree"
"step_45_advanced_trees_segment-fenwick|Segment tree and Fenwick tree"
"step_46_advanced_trees_trie|Trie"
"step_47_graph_basics|Graph basics: BFS, DFS"
"step_48_design_patterns|Design patterns in Rust"
"step_49_multithreading|std::thread, mpsc, Mutex, Arc"
)

mkdir -p "$R/codes"
: > "$R/codes/dates.txt"
for entry in "${STEPS[@]}"; do
  dir="${entry%%|*}"; topic="${entry#*|}"
  mkdir -p "$R/codes/$dir"
  f="$R/codes/$dir/${dir#step_??_}_1.rs"
  if [ ! -f "$f" ]; then
    cat > "$f" << EOF
// $topic
// Build and run:  rustc $(basename "$f") && ./$(basename "$f" .rs)

fn main() {
    println!("$topic");
}
EOF
  fi
  printf "Starting Date: 00/00/0000 Ending Date: 00/00/0000        --> %s\n" "$dir" >> "$R/codes/dates.txt"
done
rm -f "$R/codes/.gitkeep"

# ---------- 2. online_coding_platform layout (mirrors c_cpp_dsa) ----------
OCP="$R/online_coding_platform"
for d in leetcode/dsa_prac leetcode/leetcode_75 tuf/pattern codeforces atcoder \
         gfg/dsa_prac gfg/office_work gfg/home_work \
         coding_ninjas/dsa_prac coding_ninjas/office_work coding_ninjas/home_work; do
  mkdir -p "$OCP/$d"
  touch "$OCP/$d/.gitkeep"
done
rm -f "$OCP/.gitkeep"

# ---------- 3. other rust_dsa folders ----------
mkdir -p "$R/theory" "$R/practice"

# ---------- 4. READMEs ----------
cat > "$R/README.md" << 'EOF'
# Rust DSA

Rust learning and data structures and algorithms practice. The layout mirrors
`../c_cpp_dsa`, so a topic in one language is easy to compare with the other.

## Structure

- `codes/` : 49 topic modules (`step_01` to `step_49`), one folder per topic
  with standalone `.rs` files. `dates.txt` tracks start and end dates.
- `online_coding_platform/` : solved problems from LeetCode, GFG, Coding Ninjas,
  TUF, AtCoder and Codeforces.
- `theory/` : notes and interview questions.
- `practice/` : scratch files and experiments.

## Build and run

Single file (same idea as `g++ file.cpp`):

```bash
rustc file.rs && ./file
```

Optimised build, or a full project when a topic needs crates:

```bash
rustc -O file.rs
cargo new project_name
```

## C++ to Rust mapping

| C++ | Rust |
|---|---|
| pointers and references | ownership, borrowing, lifetimes |
| classes, inheritance, polymorphism | `struct` + `impl`, traits, `dyn Trait` |
| STL containers | `Vec`, `VecDeque`, `HashMap`, `HashSet`, `BTreeMap`, `BinaryHeap` |
| templates | generics and trait bounds |
| exceptions | `Result`, `Option`, `?` |
| smart pointers | `Box`, `Rc`, `Arc`, `RefCell` |
| multithreading | `std::thread`, `mpsc`, `Mutex` |
EOF

cat > "$ROOT/c_cpp_dsa/README.md" << 'EOF'
# C / C++ DSA

Step-wise C/C++ learning and data structures and algorithms practice.

## Structure

- `codes/` : 49 topic modules (`step_01` to `step_49`): fundamentals, OOP,
  STL containers and algorithms, templates, smart pointers, linked lists,
  stacks and queues, hashing, searching and sorting, array techniques, trees,
  graphs, design patterns, multithreading.
- `online_coding_platform/` : solved problems from LeetCode, GFG, Coding Ninjas,
  TUF, AtCoder and Codeforces.
- `theory/` : consolidated theory questions and answers.
- `interview_questions/` : topic-wise question banks for revision.
- `practice/` : scratch snippets and small solutions.
- `notes/` : study notes for C and C++.
- `scripts/` : helper scripts (`check_cpp.sh` lists `.cpp` files with no binary).

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra file.cpp -o file && ./file
```
EOF

cat > "$ROOT/README.md" << 'EOF'
# C_Cpp_Rust_DSA

Data structures and algorithms practice in C/C++ and Rust, with the same
step-wise structure in both languages.

- [`c_cpp_dsa/`](c_cpp_dsa) : C and C++ modules, solved problems, theory and interview questions
- [`rust_dsa/`](rust_dsa) : the same topics in Rust (in progress)
EOF

echo "Done. Created $(ls "$R/codes" | grep -c '^step_') step folders in rust_dsa/codes."
