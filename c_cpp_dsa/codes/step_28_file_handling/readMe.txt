================================================================================
        FILE HANDLING — COMPLETE REFERENCE + QUESTION BANK
        Topics: C-style (stdio.h), C++ Streams (fstream),
                Binary Files, Random Access, Error Handling,
                Performance, Modern C++ Patterns
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
1.1  C-STYLE FILE HANDLING  (#include <stdio.h> / <cstdio>)
────────────────────────────────────────────────────────────────────────────────

  Core Functions:
  ┌───────────────────┬────────────────────────────────────────────────────┐
  │ Function          │ Description                                        │
  ├───────────────────┼────────────────────────────────────────────────────┤
  │ fopen(path, mode) │ Opens file; returns FILE* or NULL on failure       │
  │ fclose(fp)        │ Closes file; flushes buffers                       │
  │ fread(buf,sz,n,fp)│ Reads n items of size sz into buf (binary)         │
  │ fwrite(buf,sz,n,f)│ Writes n items of size sz from buf (binary)        │
  │ fprintf(fp,fmt,..)│ Formatted write to file (like printf)              │
  │ fscanf(fp,fmt,..) │ Formatted read from file (like scanf)              │
  │ fgets(buf,n,fp)   │ Read a line (safe — limits to n-1 chars)           │
  │ fputs(str,fp)     │ Write a string to file                             │
  │ fgetc(fp)         │ Read one character                                 │
  │ fputc(c,fp)       │ Write one character                                │
  │ fseek(fp,off,orig)│ Move file position pointer                         │
  │ ftell(fp)         │ Return current file position                       │
  │ rewind(fp)        │ Reset position to beginning                        │
  │ feof(fp)          │ Returns non-zero if end-of-file reached            │
  │ ferror(fp)        │ Returns non-zero if error occurred                 │
  │ clearerr(fp)      │ Clears EOF and error flags                         │
  │ fflush(fp)        │ Flush write buffer to OS                           │
  │ rename(old, new)  │ Rename/move a file                                 │
  │ remove(path)      │ Delete a file                                      │
  └───────────────────┴────────────────────────────────────────────────────┘

  File Open Modes:
  ┌────────┬──────────────────────────────────────────────────────────────┐
  │ Mode   │ Meaning                                                      │
  ├────────┼──────────────────────────────────────────────────────────────┤
  │ "r"    │ Read only. File must exist.                                  │
  │ "w"    │ Write only. Creates/truncates file.                          │
  │ "a"    │ Append. Creates if not exist; writes at end only.            │
  │ "r+"   │ Read + Write. File must exist. Position at start.            │
  │ "w+"   │ Read + Write. Creates/truncates.                             │
  │ "a+"   │ Read + Append. Creates if not exist. Read anywhere, write end│
  │ "rb"   │ Read binary.                                                 │
  │ "wb"   │ Write binary.                                                │
  │ "ab"   │ Append binary.                                               │
  └────────┴──────────────────────────────────────────────────────────────┘

  Basic Text I/O Pattern:
    FILE* fp = fopen("data.txt", "r");
    if (!fp) {
        perror("fopen");           // prints system error message
        return -1;
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);

  fseek / ftell for Random Access:
    // SEEK_SET = from beginning, SEEK_CUR = from current, SEEK_END = from end
    fseek(fp, 0, SEEK_END);        // go to end
    long size = ftell(fp);         // get file size
    rewind(fp);                    // back to beginning

    fseek(fp, 100, SEEK_SET);      // jump to byte 100
    fseek(fp, -10, SEEK_CUR);      // go back 10 bytes from current

  Binary Read/Write:
    struct Student { char name[50]; int age; float gpa; };
    Student s = {"Alice", 21, 3.8f};

    FILE* fp = fopen("students.bin", "wb");
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    fp = fopen("students.bin", "rb");
    Student loaded;
    fread(&loaded, sizeof(Student), 1, fp);
    fclose(fp);

  Key Points — C File Handling:
    • ALWAYS check return value of fopen — NULL means failure.
    • ALWAYS call fclose — C does not close files automatically.
    • Use feof() only AFTER a read fails — not as a loop condition (classic bug).
    • fgets is safer than gets (gets has no bounds checking — never use it).
    • Binary mode ("rb"/"wb") is critical on Windows (prevents \n ↔ \r\n translation).
    • perror() prints a human-readable error string using errno.

────────────────────────────────────────────────────────────────────────────────
1.2  C++ STREAM FILE HANDLING  (#include <fstream>)
────────────────────────────────────────────────────────────────────────────────

  Three Stream Classes:
  ┌─────────────┬────────────────────────────────────────────────────────┐
  │ Class       │ Purpose                                                │
  ├─────────────┼────────────────────────────────────────────────────────┤
  │ ofstream    │ Output (write) to file                                 │
  │ ifstream    │ Input (read) from file                                 │
  │ fstream     │ Input + Output (read and write)                        │
  └─────────────┴────────────────────────────────────────────────────────┘

  Open Modes (bitflags, combinable with |):
  ┌────────────────┬─────────────────────────────────────────────────────┐
  │ ios::in        │ Read                                                │
  │ ios::out       │ Write (overwrites)                                  │
  │ ios::app       │ Append (all writes go to end)                       │
  │ ios::ate       │ Open and seek to end immediately                    │
  │ ios::trunc     │ Truncate file to zero length on open                │
  │ ios::binary    │ Binary mode (no newline translation)                │
  └────────────────┴─────────────────────────────────────────────────────┘

  Writing to a File:
    ofstream out("output.txt");          // creates/overwrites
    if (!out.is_open()) throw runtime_error("Cannot open file");
    out << "Hello\n";
    out << 42 << " " << 3.14 << "\n";
    // file auto-closed when out goes out of scope (RAII)

  Reading Line by Line:
    ifstream in("input.txt");
    string line;
    while (getline(in, line)) {
        cout << line << "\n";
    }

  Reading Word by Word:
    ifstream in("words.txt");
    string word;
    while (in >> word) {
        cout << word << "\n";
    }

  Reading Numbers:
    ifstream in("nums.txt");
    int x;
    vector<int> nums;
    while (in >> x) nums.push_back(x);

  Append Mode:
    ofstream log("app.log", ios::app);
    log << "New entry\n";

  Read + Write with fstream:
    fstream f("data.txt", ios::in | ios::out);
    f.seekg(0, ios::end);              // g = get pointer (read)
    long size = f.tellg();
    f.seekp(0, ios::beg);              // p = put pointer (write)

  Binary Mode with C++ streams:
    struct Record { int id; float val; };
    Record r = {1, 9.5f};

    ofstream out("data.bin", ios::binary);
    out.write(reinterpret_cast<char*>(&r), sizeof(r));

    ifstream in("data.bin", ios::binary);
    Record loaded;
    in.read(reinterpret_cast<char*>(&loaded), sizeof(loaded));

  Error Checking:
    if (!in.is_open()) { /* file not found */ }
    if (in.fail())     { /* parse/format error */ }
    if (in.bad())      { /* unrecoverable stream error */ }
    if (in.eof())      { /* reached end of file */ }
    in.clear();        // clear error flags to continue using stream

  Key Points — C++ File Handling:
    • fstream objects are RAII — file auto-closed on destruction.
    • Use is_open() or operator bool() to check if file opened successfully.
    • getline handles empty lines correctly; >> skips whitespace.
    • seekg() moves read pointer; seekp() moves write pointer.
    • Binary mode requires reinterpret_cast<char*> — be careful with padding.
    • Prefer C++ streams over C-style in new code — type-safe and RAII.

────────────────────────────────────────────────────────────────────────────────
1.3  COMPARISON — C vs C++ FILE HANDLING
────────────────────────────────────────────────────────────────────────────────

  ┌─────────────────────┬──────────────────────┬──────────────────────────┐
  │ Feature             │ C (stdio.h)           │ C++ (fstream)            │
  ├─────────────────────┼──────────────────────┼──────────────────────────┤
  │ Open                │ fopen()               │ constructor / open()     │
  │ Close               │ fclose() — manual     │ destructor — automatic   │
  │ Type safety         │ None (void* / format) │ Full — operator<</>>     │
  │ Error handling      │ NULL + errno          │ is_open(), fail(), bad() │
  │ RAII                │ No                    │ Yes                      │
  │ Formatted I/O       │ fprintf/fscanf        │ << / >> operators        │
  │ Binary I/O          │ fread/fwrite          │ read()/write() + cast    │
  │ Seek/Tell           │ fseek/ftell           │ seekg/seekp/tellg/tellp  │
  │ Performance         │ Slightly faster       │ Slightly slower by default│
  │ Custom types        │ Not supported         │ Overload << / >>         │
  │ C compatibility     │ Native                │ sync_with_stdio(false)   │
  └─────────────────────┴──────────────────────┴──────────────────────────┘

────────────────────────────────────────────────────────────────────────────────
1.4  COMMON BUGS AND PITFALLS
────────────────────────────────────────────────────────────────────────────────

  ✗ BUG 1 — Using feof() as loop condition:
      while (!feof(fp)) { fgets(buf, sizeof(buf), fp); process(buf); }
      // Reads last line TWICE — feof() becomes true AFTER a failed read.

    ✓ CORRECT:
      while (fgets(buf, sizeof(buf), fp)) { process(buf); }

  ✗ BUG 2 — Not checking fopen return value:
      FILE* fp = fopen("missing.txt", "r");
      fscanf(fp, "%d", &x);   // CRASH — fp is NULL

  ✗ BUG 3 — Forgetting fclose() (resource leak):
      FILE* fp = fopen("file.txt", "w");
      // ... exception thrown here → fclose never called
    ✓ CORRECT: Use RAII wrapper (see coding questions).

  ✗ BUG 4 — Reading beyond EOF with getc() loop:
      int c;
      while ((c = getchar()) != EOF) { ... }  // correct
      while ((c = getchar()) != '\0') { ... } // wrong — '\0' is not EOF

  ✗ BUG 5 — Text/binary mode mismatch on Windows:
      FILE* fp = fopen("image.png", "r");  // should be "rb"

  ✗ BUG 6 — Structure padding in binary I/O:
      Writing struct with fwrite and reading on a different architecture
      may break due to different alignment/padding. Use #pragma pack or
      serialize field by field.

────────────────────────────────────────────────────────────────────────────────
1.5  PERFORMANCE TIPS
────────────────────────────────────────────────────────────────────────────────

  • Disable C/C++ sync for faster C++ streams:
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

  • Read entire file into string at once (fastest for small files):
      ifstream in("file.txt");
      string content((istreambuf_iterator<char>(in)),
                      istreambuf_iterator<char>());

  • Use setvbuf for custom buffering in C:
      char buf[65536];
      setvbuf(fp, buf, _IOFBF, sizeof(buf));  // full buffering

  • Memory-mapped files (advanced — OS-level):
      mmap() on Linux / MapViewOfFile on Windows — zero-copy, fastest I/O.
      Used for databases and large log processing.

================================================================================
PART 2 — THEORY QUESTIONS
================================================================================

────────────────────────────────────────────────────────────────────────────────
2A. CORE THEORY (from source files)
────────────────────────────────────────────────────────────────────────────────

  [T][ ] What is a file? What are the different file open modes in C?
         Asked at: TCS, Wipro, Infosys, Capgemini

  [T][ ] What is the difference between text mode and binary mode in file handling?
         (Text: newline translation on Windows \n↔\r\n; Binary: raw bytes)
         Asked at: TCS, Wipro, Amazon

  [T][ ] What is the difference between fread/fwrite and fscanf/fprintf?
         (fread/fwrite: raw binary block I/O; fscanf/fprintf: formatted text I/O)
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is the difference between fgets and gets? Why is gets dangerous?
         (gets has no size limit — buffer overflow vulnerability; never use it)
         Asked at: TCS, Wipro, Samsung, security-focused roles

  [T][ ] What is a file descriptor? What are stdin, stdout, stderr?
         (Integer handle to OS file table; stdin=0, stdout=1, stderr=2)
         Asked at: Amazon, L&T Infotech, system programming roles

  [T][ ] What is the difference between ifstream, ofstream, and fstream?
         Asked at: TCS, Wipro, Amazon

  [T][ ] What are the C++ file open modes? What is ios::app vs ios::ate?
         (app: all writes go to end; ate: initial position is end, can seek)
         Asked at: Amazon, TCS, Wipro

  [T][ ] How do you check if a file opened successfully in C and in C++?
         (C: check if fopen returned NULL; C++: is_open() or operator bool)
         Asked at: TCS, Wipro, Infosys

  [T][ ] What is fseek? What are SEEK_SET, SEEK_CUR, SEEK_END?
         Asked at: TCS, Wipro, Samsung

  [T][ ] What is the classic bug with feof() used as loop condition?
         Asked at: TCS, Wipro, Amazon

────────────────────────────────────────────────────────────────────────────────
2B. ADVANCED THEORY (★ extra questions)
────────────────────────────────────────────────────────────────────────────────

  ★[T][ ] What is buffered vs unbuffered I/O? What are the three buffer types
           in stdio (_IOFBF, _IOLBF, _IONBF)?
           (Full-buffered, line-buffered, unbuffered; set with setvbuf())
           Asked at: Samsung, L&T Infotech, system programming roles

  ★[T][ ] What is the difference between fflush() and fsync()?
           (fflush: flushes C library buffer to OS; fsync: forces OS to write
            to physical disk — guarantees durability)
           Asked at: Database roles, Goldman Sachs, system programming

  ★[T][ ] How would you find the size of a file without opening it?
           (C: stat()/fstat(); C++: filesystem::file_size(); or fseek+ftell)
           Asked at: Amazon, TCS, L&T Infotech

  ★[T][ ] What is memory-mapped I/O (mmap)? When would you use it?
           (Maps file contents into process address space — zero-copy, OS manages
            paging; used in databases, large file processing)
           Asked at: Google, Goldman Sachs, database engineering roles

  ★[T][ ] What is the difference between seekg() and seekp() in fstream?
           (seekg: moves get/read pointer; seekp: moves put/write pointer;
            fstream has two independent pointers)
           Asked at: TCS, Wipro, Amazon

  ★[T][ ] What is std::filesystem (C++17)? Name 5 operations it supports.
           (directory_iterator, exists, file_size, create_directory, copy,
            remove, rename, path — cross-platform filesystem operations)
           Asked at: Amazon, Microsoft, Google

  ★[T][ ] How do you handle large files (GB-scale) that don't fit in memory?
           (Read in chunks/blocks; mmap; streaming parsers; external sort)
           Asked at: Amazon, Google, Goldman Sachs, data engineering roles

  ★[T][ ] What is structure padding and why does it matter for binary file I/O?
           (Compiler adds padding between struct members for alignment — binary
            dumps are not portable across compilers/architectures unless packed)
           Asked at: Samsung, Qualcomm, embedded systems, Sasken

  ★[T][ ] Why is ios::sync_with_stdio(false) used? What is its side effect?
           (Unlocks C++ streams from C stdio — much faster for competitive
            programming; side effect: you can no longer mix cin/cout with scanf/printf)
           Asked at: Amazon, competitive programming, TCS

================================================================================
PART 3 — CODING QUESTIONS
================================================================================

EASY
─────
  [C][ ] (E) Write numbers 1–100 to a file; read back and print their sum
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) Copy contents of one file to another (text mode, C++)
             Asked at: TCS, Wipro, Capgemini

  [C][ ] (E) Count words, lines, and characters in a text file
             Asked at: TCS, Wipro, Capgemini

  [C][ ] (E) Store student records in file (C-style: name, age, marks);
             read back and display all records
             Asked at: TCS, Wipro, Infosys

  [C][ ] (E) File reading with exception handling (C++ streams)
             Open file; if not found, throw runtime_error; read line by line
             Asked at: TCS, Wipro, Persistent

  ★[C][ ] (E) Write a C program to count occurrences of a given word in
              a text file using fscanf/fgets
              Asked at: TCS, Wipro, Infosys, Capgemini

  ★[C][ ] (E) Read integers from a file into a vector and print max, min, average
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (E) Append a new student record to an existing file without
              overwriting old records (C++ ios::app mode)
              Asked at: TCS, Wipro, Infosys

  ★[C][ ] (E) Use C-style fopen to read a file, check for NULL, use perror()
              for error reporting — demonstrate proper error handling
              Asked at: TCS, L&T Infotech, Sasken

MEDIUM
───────
  [C][ ] (M) Implement a word frequency counter: read a text file,
             count frequency of each word, print top 10 most frequent
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Binary file I/O: write a vector of Student structs to binary file,
             read them back, verify data integrity
             Asked at: Samsung, TCS, Wipro, Persistent

  ★[C][ ] (M) Implement a simple CSV parser: read a CSV file, parse each row
              into a vector<vector<string>>, handle quoted fields
              Asked at: Amazon, Flipkart, data engineering roles

  ★[C][ ] (M) Find the size of a file using fseek/ftell (C) and
              filesystem::file_size (C++17); compare results
              Asked at: Amazon, TCS, L&T Infotech

  ★[C][ ] (M) Implement a log rotation system: write to "app.log"; when it
              exceeds 1 MB, rename to "app.log.1" and start fresh
              Asked at: Amazon, backend dev roles

  ★[C][ ] (M) Read a binary file of integers, sort them, and write sorted
              integers back to a new binary file
              Asked at: TCS, Wipro, Amazon

  ★[C][ ] (M) Implement a simple key-value store backed by a text file:
              set(key, value) writes to file; get(key) reads from file
              Asked at: Amazon, Paytm, backend dev roles

  ★[C][ ] (M) Write a RAII C-style file wrapper class (similar to FILE guard)
              that wraps FILE*, closes on destruction, throws on open failure,
              and provides read/write methods
              Asked at: Google, Persistent, L&T Infotech

HARD
─────
  [C][ ] (H) External sort: describe and partially implement sorting a 10 GB
             file of integers with only 1 GB RAM
             (Split → sort chunks → K-way merge using min-heap)
             Asked at: Google, Microsoft, Goldman Sachs, database companies

  ★[C][ ] (H) Implement a simple binary search on a sorted binary file WITHOUT
              loading it fully into memory
              (Use fseek + fread to access arbitrary records by index)
              Asked at: Amazon, Goldman Sachs, database roles

  ★[C][ ] (H) Implement a file-based LRU cache: cache entries stored in a
              binary file; recently accessed entries moved to a fast in-memory
              map; dirty entries flushed to file on eviction
              Asked at: Amazon, database roles, advanced backend

  ★[C][ ] (H) Given a directory of log files, use std::filesystem to find all
              .log files, merge them sorted by timestamp into one output file
              Asked at: Google, Amazon, backend dev roles

================================================================================
QUICK REFERENCE CHEATSHEET
================================================================================

  ── C-STYLE ───────────────────────────────────────────────────────────────

  FILE* fp = fopen("file.txt", "r");
  if (!fp) { perror("fopen"); return -1; }

  char buf[256];
  while (fgets(buf, sizeof(buf), fp)) { /* process buf */ }

  fseek(fp, 0, SEEK_END);  long sz = ftell(fp);  rewind(fp);

  fread(&data, sizeof(data), 1, fp);    // binary read
  fwrite(&data, sizeof(data), 1, fp);   // binary write

  fclose(fp);

  ── C++ STREAMS ───────────────────────────────────────────────────────────

  #include <fstream>

  // Write
  ofstream out("file.txt");
  if (!out) throw runtime_error("Cannot open");
  out << "line\n";
  // auto-closed (RAII)

  // Read line by line
  ifstream in("file.txt");
  string line;
  while (getline(in, line)) { /* process line */ }

  // Binary
  ofstream bout("data.bin", ios::binary);
  bout.write(reinterpret_cast<char*>(&obj), sizeof(obj));
  ifstream bin("data.bin", ios::binary);
  bin.read(reinterpret_cast<char*>(&obj), sizeof(obj));

  // Seek
  in.seekg(100, ios::beg);     // move read pointer to byte 100
  streampos pos = in.tellg();  // current read position

  ── std::filesystem (C++17) ───────────────────────────────────────────────

  #include <filesystem>
  namespace fs = std::filesystem;

  fs::exists("file.txt")
  fs::file_size("file.txt")
  fs::create_directory("mydir")
  fs::copy("src.txt", "dst.txt")
  fs::remove("file.txt")
  for (auto& entry : fs::directory_iterator(".")) {
      cout << entry.path() << "\n";
  }

================================================================================
SUMMARY COUNT
================================================================================

  Category                   | E  | M  | H  | Total
  ---------------------------|----|----|----|---------
  Concept Explanations       | 5 sections fully documented
  Theory (from files)        | 10 |  0 |  0 |    10
  Theory (★ added)           |  9 |  0 |  0 |     9
  Coding Easy (from files)   |  5 |  0 |  0 |     5
  Coding Easy (★ added)      |  4 |  0 |  0 |     4
  Coding Medium (from files) |  0 |  2 |  0 |     2
  Coding Medium (★ added)    |  0 |  6 |  0 |     6
  Coding Hard (from files)   |  0 |  0 |  1 |     1
  Coding Hard (★ added)      |  0 |  0 |  3 |     3
  ---------------------------|----|----|----|---------
  TOTAL Q&A                  | 28 |  8 |  4 |    40

================================================================================
END
================================================================================
