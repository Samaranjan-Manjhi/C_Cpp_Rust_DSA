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
