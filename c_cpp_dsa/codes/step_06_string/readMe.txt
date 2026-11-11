===============================================================================
        STRINGS (C-STYLE & C++ std::string) — COMPLETE QUESTION BANK
        Compiled from all 5 files (roadmap + 4 question banks)
        No duplicates | Theory + Coding | All difficulties
================================================================================

FORMAT:
  [ ] = not attempted   [~] = need revision   [x] = done
  (E) Easy   (M) Medium   (H) Hard
  [T] = Theory/Verbal    [C] = Coding

================================================================================
SECTION 1 — THEORY QUESTIONS
================================================================================

--------------------------------------------------------------------------------
1A. C-STYLE STRINGS (char arrays)
--------------------------------------------------------------------------------

  [T][ ] What is a C-style string? How is it stored in memory?
         (Array of chars terminated by '\0' null character)
         Asked at: TCS, Wipro, Infosys, L&T Infotech

  [T][ ] What is the difference between char s[] = "hello" and char* s = "hello"?
         (Array: modifiable, stack. Pointer: points to string literal, read-only)
         Asked at: Samsung, Sasken, L&T Infotech, Persistent

  [T][ ] What happens if you forget the null terminator in a C string?
         (Undefined behavior — functions like strlen run off the end)
         Asked at: Sasken, Samsung, embedded roles, TCS

  [T][ ] What is the difference between strlen and sizeof for a char array?
         (strlen counts chars before '\0'; sizeof gives total array size including '\0')
         Asked at: TCS, Wipro, Infosys, L&T Infotech

  [T][ ] What do the following C string functions do? (from <cstring>)
         strlen, strcpy, strncpy, strcat, strncat, strcmp, strncmp, strchr, strstr
         Asked at: TCS, Wipro, Infosys, Capgemini, L&T Infotech

  [T][ ] What is the danger of strcpy? How does strncpy fix it?
         (strcpy has no bounds check — buffer overflow; strncpy limits copy length)
         Asked at: Samsung, Sasken, Persistent, embedded roles

  [T][ ] What is a buffer overflow? How can unsafe string functions cause it?
         Asked at: Samsung, Sasken, L&T Infotech, security-conscious roles

  [T][ ] What is the difference between strcmp returning 0, positive, and negative?
         (0 = equal, positive = s1 > s2 lexicographically, negative = s1 < s2)
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is strdup? Does it allocate memory? Who is responsible for freeing it?
         (strdup allocates on heap with malloc; caller must free)
         Asked at: Sasken, embedded roles, L&T Infotech

  [T][ ] What is strtok? How does it work? Is it thread-safe?
         (Splits string by delimiter using static internal state — NOT thread-safe)
         Asked at: Sasken, Samsung, embedded roles, L&T Infotech

  [T][ ] What is atoi? What does it do on invalid input?
         (Converts string to int; returns 0 on invalid — use strtol for robust version)
         Asked at: TCS, Wipro, Amazon, Zoho

  [T][ ] What are the safer replacements for atoi, atof, etc. in modern C?
         (strtol, strtod — they set errno and return endptr)
         Asked at: Persistent, Nagarro, Samsung, embedded roles

  [T][ ] What is sprintf? What is snprintf? Why is snprintf safer?
         (snprintf limits output size — prevents buffer overflow)
         Asked at: Sasken, Samsung, L&T Infotech, embedded roles

  [T][ ] Can you use pointer arithmetic on a char* string?
         Show how to iterate characters without using array indexing.
         Asked at: Sasken, Samsung, TCS

--------------------------------------------------------------------------------
1B. C++ std::string
--------------------------------------------------------------------------------

  [T][ ] What is the difference between C-style string and std::string?
         When would you choose each?
         Asked at: Amazon, Microsoft, TCS, Wipro, Zoho

  [T][ ] What is the time complexity of string concatenation using += in a loop?
         Why is stringstream or reserve() better?
         Asked at: Amazon, Microsoft, Adobe, Google

  [T][ ] How is std::string stored internally? What is small string optimization (SSO)?
         Asked at: Google, advanced C++ roles, Dolat Capital, Persistent

  [T][ ] What is std::string_view? Why is it more efficient than const string&?
         (Non-owning view into string data — no allocation, no copy)
         Asked at: Dolat Capital, Persistent, Nagarro, Google, Atlassian

  [T][ ] What is the difference between s.size() and s.length()?
         (They are identical — both return number of characters)
         Asked at: TCS, Wipro

  [T][ ] What does s.find() return when the substring is not found?
         (Returns std::string::npos — comparing with -1 is a bug since npos is size_t max)
         Asked at: Google, Amazon (common C++ trap question)

  [T][ ] What is the difference between s.substr(pos, len) and s.substr(pos)?
         (Second form takes from pos to end of string)
         Asked at: TCS, Wipro, Amazon

  [T][ ] How do you convert int to string and string to int in C++?
         (to_string(n), stoi(s), stol(s), stod(s), stringstream)
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is a string stream? When would you use stringstream?
         Asked at: Amazon, Microsoft, Zoho, L&T Infotech

  [T][ ] Is std::string null-terminated? Can you rely on s.c_str()?
         (Yes, std::string is guaranteed null-terminated; c_str() returns const char*)
         Asked at: Persistent, Nagarro, Samsung

  [T][ ] What is the time complexity of string comparison with ==?
         (O(N) where N is string length)
         Asked at: Amazon, Google, competitive programming

  [T][ ] What is copy-on-write (COW) optimization for std::string?
         Is it still used in modern C++? (Disallowed in C++11 due to threading)
         Asked at: Google, Dolat Capital, advanced C++ roles

  [T][ ] What is string immutability? Is std::string mutable or immutable?
         (std::string IS mutable unlike Java/Python strings)
         Asked at: Amazon, Zoho, Flipkart

  [T][ ] What are the key methods of std::string you must know?
         length/size, substr, find, rfind, replace, insert, erase,
         push_back, pop_back, append, compare, c_str, empty, clear,
         begin/end, at, operator[]
         Asked at: TCS, Wipro, Amazon, Infosys

  [T][ ] What is the difference between s[i] and s.at(i)?
         (s[i] has no bounds check; s.at(i) throws std::out_of_range)
         Asked at: Amazon, Persistent, Nagarro

  [T][ ] How do you reverse a string in C++?
         (std::reverse(s.begin(), s.end()) — std::string has no .reverse() method)
         Asked at: TCS, Wipro, Infosys, Amazon (common trap!)

  [T][ ] What is the difference between string::npos and -1?
         (npos = static const size_t(-1) = very large unsigned number; comparing
          find() result to -1 causes signed/unsigned comparison bug)
         Asked at: Google, Amazon, advanced C++ roles

--------------------------------------------------------------------------------
1C. ALGORITHMS ON STRINGS
--------------------------------------------------------------------------------

  [T][ ] What is a suffix array? How does it differ from a suffix tree?
         Asked at: Google, competitive programming roles

  [T][ ] What is the Z-function (Z-array)? When would you use it over KMP?
         (Z[i] = length of longest prefix of string that matches substring starting at i)
         Asked at: Competitive programming, Google

  [T][ ] What is the KMP algorithm? What is the failure function (lps array)?
         (Knuth-Morris-Pratt — pattern matching without backtracking, O(N+M))
         Asked at: Google, Microsoft, Amazon

  [T][ ] What is Rabin-Karp? What is a rolling hash?
         (Hash-based pattern matching — average O(N+M), uses sliding hash window)
         Asked at: Amazon, Google

  [T][ ] What is Manacher's algorithm? What does it compute?
         (All palindromic substrings in O(N) using symmetry of palindromes)
         Asked at: Google, Amazon, Adobe

  [T][ ] What is lexicographic ordering of strings?
         How does strcmp / operator< implement it?
         Asked at: TCS, Wipro, Amazon, Competitive Programming

  [T][ ] What is the difference between a substring and a subsequence?
         (Substring: contiguous; Subsequence: any subset maintaining order)
         Asked at: Amazon, Microsoft, TCS, Wipro, Zoho

  [T][ ] What is anagram? How do you check if two strings are anagrams?
         (Same characters, same frequency — sort both or use frequency array)
         Asked at: Amazon, Microsoft, Zoho, Flipkart

  [T][ ] What is a palindrome? What is the most efficient way to check?
         (Two pointers from both ends — O(N) time O(1) space)
         Asked at: TCS, Wipro, Amazon, Infosys

  [T][ ] What is string hashing? Why is polynomial rolling hash used?
         Asked at: Competitive programming, Google, HFT roles

  [T][ ] What is the longest common prefix (LCP) of two strings?
         How is LCP array used with suffix arrays?
         Asked at: Google, competitive programming

  [T][ ] What is the edit distance (Levenshtein distance)?
         What three operations are allowed? What is the DP recurrence?
         Asked at: Amazon, Microsoft, Google, Adobe, Goldman Sachs

  [T][ ] What is a trie? When would you use it over a hashmap for strings?
         (Prefix-based search, auto-complete — trie wins for prefix queries)
         Asked at: Amazon, Microsoft, Google, Adobe

  [T][ ] What is lexicographically smallest rotation of a string?
         Name the O(N) algorithm. (Booth's algorithm or suffix array)
         Asked at: Google, competitive programming

--------------------------------------------------------------------------------
1D. ADDITIONAL / TRICKY THEORY
--------------------------------------------------------------------------------

  [T][ ] What is the most vexing parse related to strings?
         string s(); // declares a function, not a string!
         Asked at: Google, advanced C++ roles

  [T][ ] What is the difference between find_first_of and find in std::string?
         (find_first_of finds first occurrence of ANY char in the argument set)
         Asked at: Persistent, Nagarro

  [T][ ] How does getline work? What is the difference between
         cin >> s and getline(cin, s)?
         (cin >> skips whitespace and stops at first space; getline reads full line)
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is cin.ignore() and when do you need it?
         (Clears the newline left in buffer after cin >> before getline)
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is the difference between s.empty() and s.size() == 0?
         (Equivalent — prefer s.empty() as it is O(1) and more expressive)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What are raw string literals in C++11? (R"(...)")
         (Avoids escape sequences — useful for regex, file paths)
         Asked at: Google, Atlassian, modern C++ roles

  [T][ ] What is std::string::reserve()? When should you use it?
         (Pre-allocates capacity to avoid repeated reallocations in a loop)
         Asked at: Amazon, Dolat Capital, Persistent

  [T][ ] What is isalpha, isdigit, isspace, isupper, islower, toupper, tolower?
         (From <cctype> — classify and transform individual characters)
         Asked at: TCS, Wipro, Zoho, Amazon

================================================================================
SECTION 2 — CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. EASY CODING
--------------------------------------------------------------------------------

  [C][x] (E) Reverse a string.
             Methods: two-pointer, using std::reverse, recursion.
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][x] (E) Check if a string is a palindrome.
             O(N) two-pointer approach. Also handle ignoring non-alphanumeric.
             Asked at: TCS, Wipro, Amazon, Zoho

  [C][x] (E) Count vowels and consonants in a string.
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Remove all spaces from a string.
             Asked at: TCS, Infosys

  [C][x] (E) Convert string to uppercase / lowercase manually.
             (Without using toupper/tolower — use ASCII arithmetic too)
             Asked at: TCS, Wipro

  [C][x] (E) Count words in a sentence.
             Handle multiple consecutive spaces.
             Asked at: Wipro, Capgemini, Zoho

  [C][x] (E) Check if two strings are anagrams.
             Method 1: sort both. Method 2: frequency array of 26. O(N).
             Asked at: Amazon, Microsoft, Zoho, Flipkart

  [C][x] (E) First non-repeating character in a string.
             (Frequency array + linear scan)
             Asked at: Amazon, Microsoft, Adobe, Zoho, Flipkart

  [C][x] (E) Find the ASCII value of each character in a string.
             Asked at: TCS, Wipro

  [C][x] (E) Check if a string is a valid identifier.
             (Starts with letter or _, followed by letters, digits, _)
             Asked at: TCS, Wipro, Zoho

  [C][x] (E) Print all characters at even index positions of a string.
             Asked at: TCS, Wipro

  [C][x] (E) Replace all spaces in a string with '%20' (URL encoding).
             Asked at: Amazon, Microsoft

  [C][x] (E) Count the number of uppercase and lowercase letters in a string.
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Find the longest word in a sentence.
             Asked at: TCS, Wipro, Zoho

  [C][x] (E) Remove duplicate characters from a string (keep first occurrence).
             Asked at: Amazon, Zoho

  [C][x] (E) Check if a string has all unique characters.
             Method 1: O(N^2) brute force.
             Method 2: O(N) with bitmask (only lowercase letters — 26-bit int).
             Asked at: Amazon, Microsoft, Adobe

  [C][x] (E) Convert a sentence to title case (first letter of each word uppercase).
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Find the most frequent character in a string.
             Asked at: TCS, Amazon, Zoho

  [C][x] (E) Find frequency of each character in a string.
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Remove consecutive duplicates from string.
             "aabbccdde" -> "abcde"
             Asked at: Zoho, Paytm, Swiggy

  [C][x] (E) Count occurrences of a word in a sentence (case-insensitive).
             Asked at: TCS, Wipro, Zoho

  [C][x] (E) Given string, print all characters in it that appear exactly once.
             Asked at: TCS, Wipro, Amazon

  [C][x] (E) Check if string contains only digits.
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Caesar cipher: shift characters by K positions in alphabet.
             Wrap around: 'z' + 1 = 'a'.
             Asked at: TCS, Capgemini, Zoho

  [C][x] (E) Given two strings, find the number of positions where
             they have the same character.
             Asked at: TCS, Wipro

  [C][x] (E) Find all starting indices of anagrams of pattern P in string S.
             Use sliding window + frequency array comparison.
             Asked at: Amazon, Microsoft, Flipkart

  [C][x] (E) Reverse only the words in a sentence, not the characters.
             "hello world" -> "world hello"
             Asked at: Amazon, Microsoft, TCS, Zoho

  [C][~] (E) Find the longest common prefix among an array of strings.
             Vertical scanning approach.
             Asked at: Amazon, Flipkart

  [C][x] (E) Count occurrences of a given character in a string.
             Asked at: TCS, Wipro

  [C][x] (E) Given a string of brackets, find the minimum insertions to make it valid.
             (Count unmatched '(' and ')' using a counter — not a stack)
             Asked at: Amazon, Microsoft

  [C][ ] (E) Check if string B is a scrambled version of string A (character rotation).
             "Shift all characters by same amount mod 26"
             Asked at: TCS, Capgemini

  [C][x] (E) Print all distinct substrings of a string using a set.
             Asked at: Amazon, Zoho

  [C][~] (E) Implement strlen, strcpy, strcat, strcmp from scratch
             (without using <cstring> library functions).
             Asked at: TCS, Wipro, Samsung, Sasken, embedded roles

  [C][x] (E) Check if a given string has balanced parentheses (only one type ()).
             Use a counter (not stack).
             Asked at: TCS, Wipro

  [C][x] (E) Find position (index) of first occurrence of a character in a string.
             Asked at: TCS, Wipro

  [C][x] (E) Read a full sentence using getline and print each word on a new line.
             Demonstrate cin vs getline difference.
             Asked at: TCS, Wipro, Infosys

--------------------------------------------------------------------------------
2B. MEDIUM CODING
--------------------------------------------------------------------------------

  [C][ ] (M) Find all substrings of a string and print them.
             (Generate all N*(N+1)/2 substrings — understand brute force O(N^2))
             Asked at: TCS, Wipro, Amazon

  [C][ ] (M) Longest substring without repeating characters.
             Sliding window + hashmap/set. O(N).
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart, Goldman Sachs

  [C][ ] (M) Longest common prefix among array of strings.
             Sort-based approach: compare only first and last string. O(N log N).
             Asked at: Amazon, Google

  [C][ ] (M) Check if one string is a rotation of another.
             Hint: check if s2 is a substring of s1 + s1.
             Asked at: Amazon, Microsoft, Flipkart

  [C][ ] (M) String compression (run-length encoding).
             "aabccc" -> "a2b1c3". Handle case where compressed >= original.
             Asked at: Amazon, Microsoft, Adobe, Goldman Sachs

  [C][ ] (M) Group anagrams from a list of strings.
             Sort each string as key for hashmap. O(N * L log L).
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Minimum window substring (containing all chars of pattern).
             Sliding window with two frequency maps.
             Asked at: Amazon, Google, Microsoft, Adobe, Flipkart

  [C][ ] (M) Longest palindromic substring.
             Expand around center approach O(N^2). Know Manacher's O(N) exists.
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart, Goldman Sachs

  [C][ ] (M) Count palindromic substrings.
             Expand around center — O(N^2).
             Asked at: Google, Amazon

  [C][ ] (M) Valid parentheses string check.
             Use stack for multiple bracket types: (){}[].
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Decode string: "3[a2[bc]]" -> "abcbcabcbcabcbc".
             Use two stacks (one for counts, one for strings).
             Asked at: Amazon, Google, Adobe, Atlassian, Flipkart

  [C][ ] (M) Reverse words in a string.
             Reverse word order, remove extra leading/trailing/multiple spaces.
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find all permutations of a string (unique, handle duplicates).
             Backtracking. Use a set or sort + skip duplicates.
             Asked at: Amazon, Microsoft, Adobe, Zoho

  [C][ ] (M) Implement atoi (string to integer) with full edge case handling.
             Handle: leading spaces, +/-, overflow (clamp to INT_MIN/INT_MAX),
             invalid characters (stop at first non-digit).
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Given a pattern and a string, check if string matches pattern.
             e.g. pattern "abba", string "dogcatcatdog" -> true.
             Use hashmap for char-to-word and word-to-char mapping.
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find the number of times a smaller string appears as a subsequence
             in a larger string (not substring — any positions).
             DP: dp[i][j] = count of pattern[0..j-1] in text[0..i-1].
             Asked at: Amazon, Google

  [C][ ] (M) Rearrange characters of a string so no two adjacent chars are same.
             Return empty string if not possible.
             Hint: use max-heap (greedy).
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Given a string of brackets, find the length of the longest valid
             parentheses substring.
             Hint: stack or DP.
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Check if string T can be formed by interleaving strings S1 and S2.
             2D DP. dp[i][j] = can first i chars of S1 and j chars of S2 interleave.
             Asked at: Amazon, Google (also in DP chapter)

  [C][ ] (M) Given a string, find the minimum number of characters to delete
             to make it an anagram of another string.
             (Count frequency difference)
             Asked at: Amazon, Microsoft

  [C][ ] (M) Zigzag conversion: write string in zigzag on N rows, then read row by row.
             "PAYPALISHIRING" with 3 rows -> "PAHNAPLSIIGYIR".
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Given string, find longest substring with at most 2 distinct characters.
             Sliding window with hashmap. O(N).
             Asked at: Amazon, Google, Adobe

  [C][ ] (M) Find the number of distinct palindromic substrings in a string.
             Expand around center with a set. O(N^2).
             Asked at: Amazon, Flipkart, Google

  [C][ ] (M) Given string, find the longest substring where each character
             appears an even number of times.
             Bitmask DP — XOR of character frequencies as prefix state.
             Asked at: Google, Facebook/Meta

  [C][ ] (M) Count the number of ways to decode a digit string to letters.
             '1'->A ... '26'->Z. "226" -> 3 ways.
             1D DP: dp[i] = ways to decode s[0..i-1].
             Asked at: Amazon, Microsoft, Facebook/Meta, Flipkart

  [C][ ] (M) Longest substring with exactly K distinct characters.
             Sliding window with hashmap.
             Asked at: Amazon, Google, Flipkart, Adobe

  [C][ ] (M) Wildcard matching (* matches any sequence, ? matches one char).
             DP: dp[i][j] = does pattern[0..j-1] match text[0..i-1].
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Minimum number of brackets to add to make string valid.
             Forward pass (count open), backward pass (count close). O(N).
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Count occurrences of pattern in text using Z-algorithm.
             Concatenate: pattern + '#' + text. Z values >= len(pattern) are matches.
             Asked at: Google, Amazon, competitive programming

  [C][ ] (M) Implement Rabin-Karp rolling hash for pattern matching.
             O(N+M) average case. Handle hash collisions.
             Asked at: Amazon, Google

  [C][ ] (M) Longest substring with at most K distinct characters.
             Sliding window. O(N).
             Asked at: Amazon, Google, Microsoft, Adobe

  [C][ ] (M) Minimum window in string containing all distinct characters.
             Sliding window variant.
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Print all anagrams together from a list of strings.
             Sort each string as key. Group in multimap or unordered_map<string,vector<string>>.
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Smallest window in string S containing all characters of pattern P
             (with their exact frequencies — duplicates matter).
             Sliding window with two frequency maps.
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) String to integer (implement stoi):
             Handle: leading spaces, +/- sign, overflow, invalid chars.
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Count distinct subsequences of string S in string T.
             dp[i][j] = number of ways T[0..j-1] appears as subsequence in S[0..i-1].
             Asked at: Amazon, Google

  [C][ ] (M) Longest repeating subsequence.
             LCS of string with itself, where s[i] != s[j] (different positions).
             Asked at: Amazon, Microsoft

  [C][ ] (M) Given string, find the score of balanced brackets:
             "()" = 1, AB = A+B, "(A)" = 2*A. e.g. "(()(()))" = 6.
             Stack of scores.
             Asked at: Google, Amazon

  [C][ ] (M) Pattern matching: implement wildcard matching where '.' matches
             any single character and '*' means zero or more of preceding char.
             (Regex matching — DP)
             Asked at: Google, Facebook/Meta, Amazon

  [C][ ] (M) Find the number of palindromic subsequences (not substrings) of length 3.
             For each character, count same chars before * same chars after.
             Asked at: Competitive programming, Amazon

  [C][ ] (M) Find all starting indices of anagrams of pattern P in string S.
             Sliding window + frequency array. O(N).
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Remove duplicate letters from string so result is smallest
             lexicographically and each letter appears once.
             Monotonic stack + last occurrence map.
             Asked at: Amazon, Google

  [C][ ] (M) Given N strings, find all pairs that are isomorphic.
             Two strings are isomorphic if same character mapping applies.
             Asked at: Amazon, Microsoft

--------------------------------------------------------------------------------
2C. HARD CODING
--------------------------------------------------------------------------------

  [C][ ] (H) KMP pattern matching: find all occurrences of pattern in text.
             Build lps (failure function) array in O(M), then search in O(N).
             Asked at: Google, Microsoft, Amazon, competitive programming

  [C][ ] (H) Minimum characters to add to front of string to make it a palindrome.
             Hint: KMP failure function on s + '#' + reverse(s).
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (H) Shortest palindrome by adding characters at front.
             Build shortest palindrome using KMP lps trick.
             Asked at: Google, Amazon

  [C][ ] (H) Implement the Z-algorithm for pattern matching.
             Z[i] = longest substring starting at i that is also a prefix.
             Use for all string matching without backtracking.
             Asked at: Google, competitive programming

  [C][ ] (H) Find the longest palindromic substring using Manacher's algorithm in O(N).
             Build P[] array using symmetry of previous palindromes.
             Asked at: Google, Amazon, Adobe

  [C][ ] (H) Count distinct palindromic substrings using Manacher's or DP.
             Asked at: Google, Amazon

  [C][ ] (H) Word Break II: given string and dictionary, return all sentences
             that can be formed by adding spaces (print all valid segmentations).
             Backtracking + memoization.
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (H) Find the lexicographically smallest rotation of a string.
             Booth's algorithm in O(N) — or suffix array based.
             Asked at: Google, Amazon, competitive programming

  [C][ ] (H) Minimum insertions to make string palindrome.
             dp[i][j] = min insertions for s[i..j].
             Equals: len - LPS (longest palindromic subsequence).
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (H) Find the shortest string that contains all given strings as substrings.
             (Shortest Common Superstring — DP + bitmask for small N)
             Asked at: Google, Goldman Sachs, competitive programming

  [C][ ] (H) Group anagrams in O(N * L) without sorting each string.
             Use character frequency tuple or XOR/prime-product hash as key.
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (H) Serialize and deserialize a list of strings with arbitrary content.
             Design the encoding format (e.g., length-prefixed) for perfect reconstruction.
             Asked at: Amazon, Facebook/Meta, Google

  [C][ ] (H) Find the lexicographically smallest string produced by removing K characters.
             Monotonic stack (greedy): pop larger char when next is smaller.
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (H) Given string with '?', replace '?' such that no two adjacent characters
             are same and result is lexicographically smallest.
             Greedy: assign smallest char that differs from neighbors.
             Asked at: Competitive programming, Amazon, Google

  [C][ ] (H) Implement regex matching with '.' and '*' (full regex, not just wildcards).
             DP: dp[i][j] = does pattern[0..j-1] match text[0..i-1].
             Asked at: Google, Facebook/Meta, Amazon

  [C][ ] (H) Find all duplicate substrings in a string (substrings that appear > once).
             Suffix array + LCP array approach. O(N log N).
             Asked at: Google, competitive programming

  [C][ ] (H) Find the longest common extension (LCE) of two positions in a string.
             Preprocess with suffix array + LCP array for O(1) per query.
             Asked at: Google, competitive programming

  [C][ ] (H) Count palindromic subsequences (distinct) in a string.
             dp[i][j] = count from i to j with 4 base cases.
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Given list of words, find all words in dictionary that can be formed
             by concatenating two or more shorter words from the same dictionary.
             (Concatenated words — Trie + DP or DFS with memoization)
             Asked at: Google, Amazon

  [C][ ] (H) Palindrome pairs: given list of words, find all pairs (i,j) where
             words[i] + words[j] is a palindrome.
             Trie of reversed words. O(N * L^2).
             Asked at: Google, Facebook/Meta, LeetCode hard

  [C][ ] (H) Find the minimum edit distance (Levenshtein) between two strings
             AND reconstruct the actual sequence of edits (not just the count).
             Trace back through DP table.
             Asked at: Amazon, Google, Goldman Sachs, Adobe

  [C][ ] (H) Implement KMP from scratch including the failure function construction.
             Then use it to find count of occurrences of pattern in text.
             Asked at: Google, Microsoft, competitive programming

  [C][ ] (H) Find shortest period of a string (smallest T such that s is T repeated k times).
             KMP failure function: period = N - lps[N-1].
             Asked at: Google, Amazon, competitive programming

--------------------------------------------------------------------------------
2D. C-STYLE STRING SPECIFIC CODING
--------------------------------------------------------------------------------

  [C][ ] (E) Implement strlen from scratch.
             char* p = str; while (*p != '\0') p++; return p - str;
             Asked at: TCS, Wipro, Samsung, Sasken, embedded roles

  [C][ ] (E) Implement strcpy from scratch.
             Copy char by char including '\0'.
             Asked at: TCS, Wipro, Samsung, Sasken

  [C][ ] (E) Implement strcmp from scratch.
             Return 0 if equal, positive if s1 > s2, negative if s1 < s2.
             Asked at: TCS, Wipro, Samsung, Sasken

  [C][ ] (E) Implement strcat from scratch.
             Find end of dest, copy src char by char.
             Asked at: TCS, Wipro, Sasken

  [C][ ] (E) Implement strrev (reverse a C string in-place).
             Two-pointer swap from both ends.
             Asked at: TCS, Wipro, Samsung, Sasken

  [C][ ] (E) Implement a safe version of strcpy (like strncpy) that always
             null-terminates the destination.
             Asked at: Samsung, Sasken, embedded roles, Persistent

  [C][ ] (M) Implement strtok from scratch (without using static state — make it reentrant).
             Use a pointer-to-pointer to track position.
             Asked at: Samsung, Sasken, advanced embedded roles

  [C][ ] (M) Implement atoi from scratch with full edge case handling.
             Handle: leading spaces, +/- sign, overflow, invalid chars (stop early).
             Asked at: Amazon, Google, Microsoft, Samsung

  [C][ ] (M) Given a C-style string, count the number of words (split by spaces).
             Handle multiple consecutive spaces, leading/trailing spaces.
             Asked at: TCS, Wipro, Zoho, Amazon

  [C][ ] (M) Reverse words in a C-style char array in-place.
             Reverse entire string, then reverse each word individually.
             Asked at: Amazon, Microsoft

  [C][ ] (M) Remove all occurrences of a character from a C-style string in-place.
             Use two-pointer (read and write positions).
             Asked at: TCS, Wipro, Amazon

  [C][ ] (M) Check if a C-style string is a palindrome.
             Two-pointer from both ends of the char array.
             Asked at: TCS, Wipro, Samsung

  [C][ ] (M) Convert a C-style string to an integer without using atoi.
             Handle sign, overflow, invalid characters.
             Asked at: TCS, Wipro, Samsung, Sasken

  [C][ ] (M) Count number of occurrences of one string inside another using
             naive O(N*M) approach first, then KMP O(N+M).
             Asked at: TCS, Wipro, Amazon, Samsung

--------------------------------------------------------------------------------
2E. COMMONLY ASKED INTERVIEW TRAPS / OUTPUT QUESTIONS
--------------------------------------------------------------------------------

  [C][ ] (E) What is the output?
             char s[] = "hello";
             cout << sizeof(s) << " " << strlen(s);
             // Output: 6 5  (sizeof includes '\0', strlen does not)
             Asked at: TCS, Wipro, Samsung, Sasken

  [C][ ] (E) What is the output?
             string s = "hello";
             s.reverse();   // COMPILE ERROR — no such method!
             cout << s;
             // Fix: std::reverse(s.begin(), s.end());
             Asked at: TCS, Wipro, Infosys (common trap)

  [C][ ] (E) What is the output?
             string s = "hello";
             auto pos = s.find("xyz");
             if (pos == -1) cout << "not found";  // BUG!
             // npos is size_t max, not -1. Use (pos == string::npos).
             Asked at: Google, Amazon (common signed/unsigned trap)

  [C][ ] (M) What is the output?
             string s = "abc";
             for (char c : s) { c = toupper(c); }
             cout << s;  // Output: "abc"  (c is a COPY — not a reference)
             // Fix: for (char& c : s) { c = toupper(c); }
             Asked at: Amazon, Google (very common auto/reference trap)

  [C][ ] (M) What is the output?
             char* p = "hello";
             p[0] = 'H';   // UNDEFINED BEHAVIOR — string literal is read-only
             // Fix: char p[] = "hello"; (stack copy, modifiable)
             Asked at: Samsung, Sasken, embedded roles

================================================================================
SECTION 3 — IMPORTANT PATTERNS & TECHNIQUES (theory + reference)
================================================================================

  Sliding Window technique — for substring problems with constraints:
    - Longest substring without repeating: unordered_set + two pointers
    - Minimum window substring: two frequency maps + match count
    - Longest with at most K distinct: hashmap size tracking

  Two Pointer technique — for palindrome, anagram checks:
    - Palindrome check: left and right pointers converging
    - Reverse in-place: swap from both ends

  Frequency Array technique — for anagram, permutation checks:
    - int freq[26] = {0};
    - Compare two freq arrays in O(26) = O(1)

  Hashing technique — for group anagrams, find duplicates:
    - Sort each string -> use as key in unordered_map
    - Or: character frequency tuple as key

  Stack technique — for balanced brackets, decode string, score:
    - Valid parentheses: stack of chars
    - Decode "3[a2[b]]": two stacks (count stack + string stack)

  DP techniques on strings:
    - LCS (Longest Common Subsequence): dp[i][j]
    - Edit Distance: dp[i][j] = min(insert, delete, replace)
    - Palindrome DP: dp[i][j] = is s[i..j] palindrome
    - Longest Palindromic Subsequence: dp[i][j]

  KMP technique — for pattern matching:
    - Build lps (failure function) array in O(M)
    - Search in O(N) without backtracking

  Z-algorithm technique — for pattern matching:
    - Concatenate: pattern + '#' + text
    - Z[i] >= len(pattern) means pattern found at position i - len(pattern) - 1

================================================================================
SECTION 4 — SUMMARY COUNT
================================================================================

  Category                                  |  E  |  M  |  H  | Total
  ------------------------------------------|-----|-----|-----|-------
  Theory — C-style strings                  |  14 |   0 |   0 |    14
  Theory — C++ std::string                  |  17 |   0 |   0 |    17
  Theory — String algorithms                |  14 |   0 |   0 |    14
  Theory — Additional/tricky                |   8 |   0 |   0 |     8
  Coding — Easy (general)                   |  36 |   0 |   0 |    36
  Coding — Medium                           |   0 |  41 |   0 |    41
  Coding — Hard                             |   0 |   0 |  23 |    23
  Coding — C-style specific                 |   6 |   8 |   0 |    14
  Coding — Output traps                     |   3 |   2 |   0 |     5
  Patterns & Techniques (reference)         |   — |   — |   — |     8
  ------------------------------------------|-----|-----|-----|-------
  TOTAL                                     |  98 |  51 |  23 | 172+

================================================================================
SECTION 5 — COMPANY FOCUS GUIDE
================================================================================

  AMAZON / MICROSOFT / FLIPKART (SDE 1 & 2):
    Must know: All medium problems especially — longest substring without repeat,
    minimum window substring, group anagrams, longest palindromic substring,
    decode string, valid parentheses, string compression, atoi.
    Focus: All medium coding + first 10 easy coding problems.

  GOOGLE:
    Must know: KMP, Z-algorithm, Manacher's, suffix array concepts,
    hard problems — palindrome pairs, lexicographically smallest rotation,
    regex matching, minimum edit distance with reconstruction.
    Focus: Hard coding + algorithm theory.

  ZOHO:
    Must know: OOP-style string manipulation, all easy coding problems,
    anagram detection, palindrome, reverse words, string parsing.
    Focus: Easy + medium coding. All C++ std::string methods.

  TCS / WIPRO / INFOSYS / CAPGEMINI (Campus):
    Must know: Basic string operations, reverse, palindrome, anagram,
    vowel/consonant count, word count, C-style string functions,
    implementing strlen/strcpy/strcmp from scratch.
    Focus: Easy coding section + C-style specific coding + C-style theory.

  SAMSUNG / SASKEN / EMBEDDED ROLES:
    Must know: C-style strings deeply — strcpy, strncpy dangers, buffer overflow,
    null terminator, strtok, sprintf/snprintf, pointer arithmetic on strings.
    Focus: C-style theory + C-style specific coding + output traps.

  DOLAT CAPITAL / HFT FIRMS:
    Must know: string_view, SSO, avoid dynamic allocation in hot paths,
    hashing for strings, efficient pattern matching, strstr alternatives.
    Focus: Theory (string_view, SSO, hashing) + hard KMP/Z/Rabin-Karp.

  GOLDMAN SACHS / JP MORGAN (Quant Dev):
    Must know: Edit distance, LCS, all DP on strings, KMP,
    palindrome problems, word break variants.
    Focus: Hard DP coding problems + medium string DP.

================================================================================
END
================================================================================
