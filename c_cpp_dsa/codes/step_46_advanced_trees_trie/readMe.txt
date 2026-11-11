================================================================================
        TRIE (PREFIX TREE) — COMPLETE QUESTION BANK
        Covers: Insert/Search/Delete, startsWith, XOR Trie, Compressed Trie,
                Autocomplete, Word Problems, All Trie Patterns
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

  ── WHAT IS A TRIE ───────────────────────────────────────────────────────────
  A tree where each node represents a CHARACTER, and each root-to-node path
  represents a PREFIX. Words are stored by marking the terminal node with isEnd=true.
  • Also called: Prefix Tree, Radix Tree (compressed version)
  • Each node has up to 26 children (for lowercase a-z)

  ── NODE STRUCTURE ───────────────────────────────────────────────────────────
  struct TrieNode {
      TrieNode* children[26];
      bool isEnd;
      int count;        // optional: words sharing this prefix
      TrieNode() : isEnd(false), count(0) { fill(children, children+26, nullptr); }
  };

  ── COMPLEXITIES ─────────────────────────────────────────────────────────────

  Operation     │ Time    │ Space  │ Note
  ──────────────┼─────────┼────────┼──────────────────────────────────────────
  Insert        │ O(L)    │ O(L)   │ L = length of word
  Search        │ O(L)    │ O(1)   │
  startsWith    │ O(L)    │ O(1)   │
  Delete        │ O(L)    │ O(1)   │ only delete nodes not shared with other words
  Space total   │ —       │O(N×Σ×L)│ N words, Σ=alphabet size, L=avg length
  vs HashMap    │ O(L)    │ O(N×L) │ Trie better for prefix queries; HashMap better for exact

  ── TRIE vs HASHMAP ──────────────────────────────────────────────────────────
  Use Trie when:  prefix search needed (autocomplete, startsWith, spell check),
                  common prefixes save memory, lexicographic order needed
  Use HashMap when: only exact-match lookup, large alphabet size, simpler code

  ── BINARY TRIE (XOR TRIE) ───────────────────────────────────────────────────
  Each node has children[0] and children[1] (bits instead of characters).
  Insert numbers bit-by-bit from MSB to LSB (usually 30 or 31 bits).
  Used for: Maximum XOR of any two numbers in O(N × 30)
  For each number: greedily try to take the complementary bit at each level.

  ── MUST-KNOW PATTERNS ───────────────────────────────────────────────────────
  1. INSERT + SEARCH + STARTSWITH: standard 3-operation Trie
  2. PREFIX COUNT: store count field; increment on insert
  3. AUTOCOMPLETE: collect all words under a prefix node (DFS)
  4. XOR MAXIMUM: binary trie; for each number greedily pick complement bit
  5. DELETE: only delete nodes that are not shared; backtrack from leaf to root

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

  [T][ ] What is a Trie? When would you use it over a HashMap?
         (Trie: O(L) prefix search, autocomplete; HashMap: O(L) exact match only;
          Trie shares prefixes saving memory when words have common prefixes)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is the time complexity of Trie insert and search?
         (Both O(L) where L = length of word — independent of N words in trie)
         Asked at: Amazon, TCS, Wipro, Microsoft

  [T][ ] What is a compressed Trie (Radix Tree / Patricia Trie)?
         (Merges nodes with single children; saves memory; used in Linux kernel routing)
         Asked at: Google, Amazon, system programming roles

  [T][ ] How does a binary Trie enable finding maximum XOR in O(N × 32)?
         (Insert each number bit by bit; for each number greedily take complement
          bit at each level — if complement child exists, XOR bit is 1)
         Asked at: Amazon, Google, Goldman Sachs, competitive programming

  [T][ ] How do you delete a word from a Trie correctly?
         (Delete leaf-to-root; only delete node if it has no other children and is
          not an end of another word — must not break shared prefixes)
         Asked at: Amazon, Microsoft, TCS

  [T][ ] What is the space complexity of a Trie vs storing words in a HashSet?
         (Trie: O(N × Σ × L) worst case; but common prefixes share nodes — better
          when many words share prefixes. HashSet: O(N × L) but no prefix sharing)
         Asked at: Amazon, Google, Adobe

  ★[T][ ] What is a suffix trie vs a trie? When is a suffix tree used?
           (Trie: stores whole words; Suffix trie/tree: stores all suffixes of a string;
            used for substring search O(M), LCS, pattern matching)
           Asked at: Google, advanced string algorithms roles

  ★[T][ ] What is the difference between Trie and Aho-Corasick automaton?
           (Aho-Corasick: Trie + failure links for multi-pattern matching in O(N+M+Z);
            used for finding all occurrences of K patterns in text simultaneously)
           Asked at: Google, Goldman Sachs, advanced algorithm roles

================================================================================
PART 3 — EASY CODING QUESTIONS
================================================================================

  [C][ ] (E) Implement Trie with insert, search, and startsWith operations
             Standard 26-child trie node; isEnd flag
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (E) Count the total number of words stored in a Trie
             Add a word count; increment on each isEnd set
             Asked at: Amazon, Microsoft, Google, TCS

  [C][ ] (E) Count words in a Trie that have a given prefix
             Store count field at each node; increment during insert;
             traverse to prefix end and return count
             Asked at: Amazon, Microsoft, Google

  [C][ ] (E) Delete a word from a Trie
             (Tricky — only delete nodes not shared with other words)
             Asked at: Amazon, Microsoft, TCS

  [C][ ] (E) Insert and search words in a Trie (standard implementation)
             Asked at: TCS, Wipro, Amazon, Adobe

  ★[C][ ] (E) Check if any word in a Trie starts with a given prefix
              (startsWith operation — return bool)
              Asked at: Amazon, TCS, Wipro

  ★[C][ ] (E) Count the number of distinct prefixes among all words in a list
              Build trie; count nodes that are first-seen (count == 1)
              Asked at: TCS, Wipro, Amazon

================================================================================
PART 4 — MEDIUM CODING QUESTIONS
================================================================================

  ── AUTOCOMPLETE & SEARCH ────────────────────────────────────────────────────

  [C][ ] (M) Implement Trie insert, search, startsWith — full implementation
             with proper node memory management
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Design Search Autocomplete System
             Trie + frequency tracking per word; return top 3 for each prefix
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Implement a phone directory: for each prefix of a search string,
             return top 3 lexicographically smallest matching contacts
             Build trie of contacts; at each prefix node collect first 3 words via DFS
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Implement autocomplete system using Trie
             Retrieve all words with a given prefix — DFS on subtree
             Asked at: Amazon, Microsoft, Google, TCS

  [C][ ] (M) Find the word with longest prefix match in Trie
             Traverse trie following the query string; return deepest match
             Asked at: Amazon, Microsoft, TCS

  ── WORD PROBLEMS ────────────────────────────────────────────────────────────

  [C][ ] (M) Word Search II — find all words from dictionary that exist in grid
             Build trie from dictionary; DFS on grid following trie nodes
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Replace words — replace words in sentence with their shortest root
             from dictionary trie; O(total sentence length)
             Asked at: Amazon, Google

  [C][ ] (M) Word Break — check if string can be segmented into dictionary words
             (Trie approach — DFS + memoization; or BFS; O(N²))
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Map sum pairs: insert (key, val) and sum all values whose keys
             start with given prefix — store value at each node with running sum
             Asked at: Amazon, Google

  [C][ ] (M) Design a spell checker: for query word, return all dictionary words
             within edit distance 1
             Trie traversal with error budget; DFS exploring skip/replace/insert
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Given list of words, find the longest compound word
             (can be formed by concatenating two or more other words in list)
             Trie + DFS with word-break check
             Asked at: Amazon, Google, Microsoft

  ── XOR TRIE ─────────────────────────────────────────────────────────────────

  [C][ ] (M) Maximum XOR of any two numbers in array using binary Trie
             Insert all numbers; for each number greedily take complement bit
             O(N × 32)
             Asked at: Amazon, Google, Goldman Sachs, competitive programming

  [C][ ] (M) Maximum XOR of two numbers from two arrays
             Insert first array into binary trie; query each number from second array
             Asked at: Amazon, Goldman Sachs

  [C][ ] (M) Given N binary strings, find the maximum XOR of any two
             Bit-by-bit trie insertion of binary representations
             Asked at: Amazon, Google, Goldman Sachs

  ★[C][ ] (M) Implement a Trie that supports wildcard search: '.' matches any character
              e.g. search("b.g") matches "bag", "big", "bug"
              DFS exploring all children on '.' ; O(L × Σ) per query
              Asked at: Amazon, Microsoft, Google, LeetCode

  ★[C][ ] (M) Find all words from a dictionary that can be formed by characters
              in a given 2D board (each cell used at most once) — Word Search II
              Trie pruning makes it much faster than pure backtracking
              Asked at: Amazon, Google, Microsoft, Facebook/Meta

================================================================================
PART 5 — HARD CODING QUESTIONS
================================================================================

  [C][ ] (H) Longest word in dictionary where all prefixes are present in dictionary
             Build trie; DFS — only extend path if current node is isEnd
             Asked at: Google, Amazon, Microsoft

  [C][ ] (H) Concatenated words: find all words that can be formed by concatenating
             two or more shorter words from the same dictionary
             Trie + DP/DFS with memoization for each word
             Asked at: Google, Amazon

  [C][ ] (H) Stream of characters: implement search(letter) returning true if any
             suffix of the current stream matches a word in dictionary
             Reverse-insert words into Trie; reverse-feed stream characters
             Asked at: Google, Amazon, Facebook/Meta

  [C][ ] (H) Design a system for top-K frequent searches with autocomplete
             Trie with min-heap of size K at each node storing top-K words
             Asked at: Google, Amazon, Goldman Sachs

  ★[C][ ] (H) Count subarrays with XOR less than K using binary Trie
              Build prefix XOR trie; for each prefix XOR query, count
              valid combinations by traversing trie
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Given array of strings, find the shortest superstring
              (string containing all given strings as substrings)
              Build trie for prefix overlap detection; then DP on bitmask
              Asked at: Google, Goldman Sachs, competitive programming

  ★[C][ ] (H) Implement Aho-Corasick automaton: multi-pattern string matching
              Build Trie + compute failure links with BFS;
              match all K patterns in text in O(N + M + Z) where Z = total matches
              Asked at: Google, Goldman Sachs, advanced algorithm roles

================================================================================
QUICK REFERENCE — Core Templates
================================================================================

  // Standard Trie
  struct Trie {
      struct Node {
          Node* ch[26] = {};
          bool end = false;
          int cnt = 0;   // words with this prefix
      };
      Node* root = new Node();

      void insert(string& w) {
          auto cur = root;
          for (char c : w) {
              if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
              cur = cur->ch[c-'a'];
              cur->cnt++;
          }
          cur->end = true;
      }
      bool search(string& w) {
          auto cur = root;
          for (char c : w) {
              if (!cur->ch[c-'a']) return false;
              cur = cur->ch[c-'a'];
          }
          return cur->end;
      }
      bool startsWith(string& p) {
          auto cur = root;
          for (char c : p) { if (!cur->ch[c-'a']) return false; cur=cur->ch[c-'a']; }
          return true;
      }
  };

  // Binary Trie — Maximum XOR
  struct BitTrie {
      struct Node { Node* ch[2] = {}; };
      Node* root = new Node();
      void insert(int x) {
          auto cur = root;
          for (int i=31; i>=0; i--) {
              int b = (x>>i)&1;
              if (!cur->ch[b]) cur->ch[b] = new Node();
              cur = cur->ch[b];
          }
      }
      int maxXOR(int x) {
          auto cur = root; int res = 0;
          for (int i=31; i>=0; i--) {
              int b = (x>>i)&1, want = 1-b;
              if (cur->ch[want]) { res |= (1<<i); cur = cur->ch[want]; }
              else if (cur->ch[b]) cur = cur->ch[b];
          }
          return res;
      }
  };

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Theory (from files)        |  6 |  0 |  0 |     6
  Theory (★ added)           |  2 |  0 |  0 |     2
  Coding Easy (from files)   |  5 |  0 |  0 |     5
  Coding Easy (★ added)      |  2 |  0 |  0 |     2
  Coding Medium (from files) |  0 | 14 |  0 |    14
  Coding Medium (★ added)    |  0 |  2 |  0 |     2
  Coding Hard (from files)   |  0 |  0 |  4 |     4
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL                      | 15 | 16 |  7 |    38

================================================================================
END
================================================================================
