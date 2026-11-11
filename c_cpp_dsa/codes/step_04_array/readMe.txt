================================================================================
        ARRAYS — COMPLETE QUESTION BANK
        Compiled from all 4 files (roadmap + 3 question banks)
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
1A. CORE ARRAY THEORY (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [T][ ] What is the time complexity of accessing, inserting, and deleting in an array?
         Asked at: TCS, Wipro, Infosys, Amazon

  [T][ ] What is the difference between static and dynamic arrays?
         Asked at: TCS, Wipro, Amazon, Flipkart

  [T][ ] How does vector<int> work internally? What happens when it resizes?
         Asked at: Amazon, Microsoft, Google, Flipkart

  [T][ ] What is cache locality? Why are arrays cache-friendly?
         Asked at: Dolat Capital, HFT firms, Samsung, Google

  [T][ ] What is the difference between array and pointer in C++?
         (Arrays decay to pointers when passed to functions)
         Asked at: TCS, Wipro, L&T Infotech, Sasken

  [T][ ] What is a 2D array? How is it stored in memory (row-major order)?
         Asked at: Samsung, Sasken, TCS, Wipro

--------------------------------------------------------------------------------
1B. FRESH ARRAY THEORY (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [T][ ] What is amortized O(1) for vector push_back? Explain the resizing strategy.
         Asked at: Amazon, Microsoft, Flipkart, Swiggy

  [T][ ] Why is cache performance better for arrays than linked lists?
         Explain spatial locality.
         Asked at: Dolat Capital, HFT firms, Samsung

  [T][ ] What is the difference between row-major and column-major order?
         Which does C++ use?
         Asked at: Samsung, Sasken, numerical computing roles

  [T][ ] What is the complexity of inserting at the beginning of a vector?
         How would you make this faster?
         Asked at: Amazon, Flipkart

  [T][ ] What is a sparse array and how would you implement one efficiently?
         Asked at: Google, Atlassian, Adobe

================================================================================
SECTION 2 — EASY CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
2A. EASY CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][x] (E) Find maximum and minimum element in an array
             Asked at: TCS, Wipro, Infosys, Capgemini

  [C][x] (E) Reverse an array in-place
             Asked at: TCS, Wipro, Infosys, Zoho

  [C][x] (E) Check if an array is sorted in ascending order
             Asked at: Wipro, Capgemini

  [C][x] (E) Find the second largest element in an array
             Asked at: Amazon, Flipkart, TCS, Zoho

  [C][x] (E) Move all zeros to end while maintaining order of non-zero elements
             Asked at: Amazon, Microsoft, Google

  [C][x] (E) Find if an array contains any duplicate element
             Asked at: Amazon, Microsoft, Adobe

  [C][~] (E) Left rotate an array by K positions
             Asked at: Amazon, Flipkart, TCS

  [C][x] (E) Find the missing number in an array of 1 to N
             Hint: use XOR or sum formula N*(N+1)/2 - actual_sum
             Asked at: Amazon, Microsoft, Google, Flipkart, TCS

  [C][x] (E) Two Sum — find pair with given target sum (brute force then hashmap)
             Asked at: Amazon, Microsoft, Google, Adobe, Flipkart

  [C][x] (E) Find all pairs in an array with a given difference
             Asked at: Amazon, Zoho

--------------------------------------------------------------------------------
2B. EASY CODING (from all_in_one_question_1 — Part 2, Section C)
--------------------------------------------------------------------------------

  [C][~] (E) Check if an array is a permutation of 1 to N
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Find the element that appears an odd number of times (XOR trick)
             Asked at: TCS, Wipro, Amazon

  [C][x] (E) Build the running maximum (prefix max array)
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Count elements smaller than the current element to its right
             (brute force O(N^2) first)
             Asked at: Flipkart, Amazon

--------------------------------------------------------------------------------
2C. EASY CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][x] (E) Find the sum of all elements in an array
             Asked at: TCS, Wipro, Infosys

  [C][x] (E) Count elements greater than a given value X in an array
             Asked at: TCS, Wipro, Capgemini

  [C][x] (E) Replace each element with the greatest element on its right side
             e.g. [17,18,5,4,6,1] -> [18,6,6,6,1,-1]
             Asked at: Amazon, LeetCode Easy

  [C][x] (E) Find the index of the first occurrence of the minimum element
             Asked at: TCS, Wipro

  [C][x] (E) Separate odd and even numbers — odds first, evens after (any order within groups)
             Asked at: TCS, Wipro, Zoho

  [C][x] (E) Check if two arrays have the same elements (not necessarily same order)
             without sorting — use frequency map
             Asked at: TCS, Wipro

  [C][x] (E) Find the intersection of two unsorted arrays (common elements)
             Asked at: Amazon, TCS

  [C][x] (E) Find the union of two unsorted arrays (all unique elements)
             Asked at: Amazon, TCS, Wipro

  [C][x] (E) Right rotate an array by 1 position
             Asked at: TCS, Wipro

  [C][x] (E) Count occurrences of each element and print only those appearing once
             Asked at: TCS, Wipro, Amazon

  [C][x] (E) Find the sum of elements at even indices vs odd indices
             Asked at: TCS, Capgemini

  [C][x] (E) Find the first repeating element in an array
             Asked at: Amazon, Flipkart, Paytm

  [C][x] (E) Find the first non-repeating element in an array
             Asked at: Amazon, Flipkart, Adobe

  [C][x] (E) Print all elements that appear exactly K times in an array
             Asked at: Amazon, Flipkart

  [C][x] (E) Check if an array can be divided into pairs with equal sum
             Asked at: TCS, Amazon

--------------------------------------------------------------------------------
2D. EASY CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][x] (E) Find the missing number using XOR only (no arithmetic sum)
             Array of size N containing elements 1 to N+1 with one missing
             Asked at: Amazon, Microsoft, TCS

  [C][x] (E) Find the element that appears more than N/2 times (majority element)
             Use Boyer-Moore Voting Algorithm — O(N) time O(1) space
             Asked at: Amazon, Adobe, Flipkart

  [C][x] (E) Rotate array right by K positions in O(N) time O(1) space
             Hint: reverse entire, reverse first K, reverse last N-K
             Asked at: Amazon, Microsoft, Adobe

  [C][x] (E) Check if an array is a permutation of 1 to N
             (all elements unique and in range [1, N])
             Asked at: TCS, Wipro, Zoho

  [C][~] (E) Find the product of all elements except itself without using division
             Input: [1,2,3,4] -> Output: [24,12,8,6]
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][x] (E) Segregate even and odd numbers — evens first, odds second
             Maintain relative order. O(N) time O(1) space.
             Asked at: Amazon, Zoho, TCS

  [C][x] (E) Given sorted array, remove duplicates in-place and return new length
             Do NOT use extra space
             Asked at: Amazon, TCS, Wipro, Adobe

  [C][x] (E) Find the only element that appears once when every other appears thrice
             Hint: count bits at each position mod 3
             Asked at: Amazon, Adobe, Samsung

  [C][ ] (E) Given two sorted arrays, merge them in-place (no extra space)
             First array has extra space for second array's elements
             Asked at: Amazon, Microsoft

  [C][x] (E) Count elements smaller than current element for each position
             Input: [8,5,2,6] -> Output: [3,1,0,2]
             Asked at: Amazon, Flipkart

  [C][~] (E) Find the equilibrium index: index where sum of left = sum of right
             Asked at: Amazon, Adobe, Zoho

  [C][ ] (E) Find the minimum number of jumps to reach end of array (greedy)
             Each element = max steps you can jump from that position
             Asked at: Amazon, Google, Flipkart

  [C][ ] (E) Given array of intervals sorted by start time, merge overlapping ones
             Input: [[1,3],[2,6],[8,10],[15,18]] -> Output: [[1,6],[8,10],[15,18]]
             Asked at: Amazon, Google, Microsoft

  [C][ ] (E) Rearrange array such that arr[i] = i if possible, else arr[i] = -1
             Asked at: Zoho, Paytm

================================================================================
SECTION 3 — MEDIUM CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
3A. MEDIUM CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][ ] (M) Best time to buy and sell stock — single transaction, maximum profit
             Asked at: Amazon, Microsoft, Google, Goldman Sachs

  [C][ ] (M) Maximum subarray sum using Kadane's Algorithm
             Asked at: Amazon, Microsoft, Google, Flipkart, Adobe, Samsung

  [C][ ] (M) Sort an array of 0s, 1s, and 2s in single pass (Dutch National Flag)
             Asked at: Amazon, Microsoft, Flipkart, Paytm, Zoho

  [C][ ] (M) 3Sum — find all unique triplets that sum to zero
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Find majority element (appears more than N/2 times)
             Hint: Boyer-Moore Voting Algorithm
             Asked at: Amazon, Microsoft, Adobe, Swiggy

  [C][ ] (M) Container with most water (two pointer approach)
             Asked at: Amazon, Google, Microsoft, Adobe

  [C][ ] (M) Trapping Rain Water
             Asked at: Amazon, Google, Microsoft, Adobe, Flipkart, Goldman Sachs

  [C][ ] (M) Product of array except self — no division, O(N) time, O(1) extra space
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find duplicate in array of N+1 integers with values in range [1, N]
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Merge two sorted arrays in-place
             Asked at: Amazon, Microsoft, Adobe

  [C][ ] (M) Rotate matrix (image) 90 degrees clockwise in-place
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Spiral order traversal of a matrix
             Asked at: Amazon, Microsoft, Flipkart, Adobe

  [C][ ] (M) Set matrix zeroes — if element is 0, set entire row and column to 0
             Asked at: Amazon, Microsoft

  [C][ ] (M) Search in rotated sorted array
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Find minimum in rotated sorted array
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Count inversions in array (pairs where arr[i] > arr[j], i < j)
             Asked at: Amazon, Google, Flipkart, Goldman Sachs

  [C][ ] (M) Subarray with given sum (positive numbers — sliding window)
             Asked at: Amazon, Flipkart, Paytm, Zoho

  [C][ ] (M) Longest consecutive sequence — O(N) using unordered_set
             Asked at: Google, Amazon, Microsoft, Atlassian

  [C][ ] (M) Maximum product subarray
             Asked at: Amazon, Microsoft, Google

--------------------------------------------------------------------------------
3B. MEDIUM CODING (from all_in_one_question_1 — Part 2, Section C)
--------------------------------------------------------------------------------

  [C][ ] (M) Chocolate Distribution Problem
             Given N students and M packets, minimize difference between max and min
             Asked at: Flipkart, Paytm, Zoho

  [C][ ] (M) Rearrange array so that arr[i] = arr[arr[i]] without extra space
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find the maximum circular subarray sum
             Asked at: Amazon, Google

  [C][ ] (M) Maximum sum of non-adjacent elements (House Robber)
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Find smallest positive missing integer in O(N) time, O(1) space
             Asked at: Amazon, Microsoft, Google, Flipkart

  [C][ ] (M) Find all elements that appear more than N/3 times
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Median of a sliding window of size K
             Asked at: Amazon, Goldman Sachs, Google

  [C][ ] (M) Maximum sum rectangle in a 2D matrix
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Minimum cost to make all array elements equal
             (sort + prefix sum approach)
             Asked at: Amazon, Google

--------------------------------------------------------------------------------
3C. MEDIUM CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][ ] (M) Find the length of the longest subarray with equal number of 0s and 1s
             Hint: convert 0->-1, use prefix sum + hashmap
             Asked at: Amazon, Flipkart, Paytm, Goldman Sachs

  [C][ ] (M) Find the minimum number of swaps required to sort an array
             Hint: cycle detection in permutation graph
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (M) Find the maximum difference between two elements where larger appears
             after smaller — must be O(N), not O(N^2)
             Asked at: Amazon, Microsoft, Goldman Sachs

  [C][ ] (M) Find smallest positive integer that cannot be represented as
             sum of any subset of a given sorted positive array
             Asked at: Google, Amazon, Goldman Sachs

  [C][ ] (M) Given array where every element appears twice except two elements,
             find those two in O(N) time O(1) space
             Hint: XOR all, split by differing bit
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Find maximum sum of exactly K consecutive elements (fixed window)
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Find number of subarrays whose sum equals T (allow negative numbers)
             Hint: prefix sum + hashmap
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find the minimum length subarray with sum >= target (sliding window)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (M) Given sorted array rotated K times, find K (number of rotations)
             Asked at: Amazon, Flipkart

  [C][ ] (M) Given array of intervals, insert a new interval and merge if needed
             Asked at: Amazon, Microsoft, Google, Adobe

  [C][ ] (M) Find number of subarrays with product less than K
             Asked at: Amazon, Google

  [C][ ] (M) Minimum operations to make all elements equal
             (find median — minimum absolute deviation is at median)
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (M) Given N ranges [l, r], find the point covered by maximum ranges
             Hint: difference array technique
             Asked at: Amazon, Flipkart, Goldman Sachs

--------------------------------------------------------------------------------
3D. MEDIUM CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (M) Find the longest subarray with equal number of 0s and 1s
             Hint: replace 0s with -1, find longest subarray with sum 0
             (Prefix sum + hashmap — different phrasing from Part 3 version)
             Asked at: Amazon, Microsoft, Flipkart, Paytm

  [C][ ] (M) Find count of inversions in array using modified merge sort — O(N log N)
             Asked at: Amazon, Microsoft, Goldman Sachs, JP Morgan

  [C][ ] (M) Rearrange array into alternating high-low (wave form):
             arr[0] >= arr[1] <= arr[2] >= arr[3] ... O(N) one-pass
             Asked at: Amazon, Flipkart, Paytm

  [C][ ] (M) Rearrange positive and negative numbers alternately
             Maintain relative order within each sign group
             Asked at: Amazon, Adobe, Zoho

  [C][ ] (M) Find all triplets in array that form an arithmetic progression
             a[j] - a[i] == a[k] - a[j] where i < j < k
             Asked at: Samsung, competitive programming

  [C][ ] (M) Given array of meeting times [start, end], find minimum conference rooms
             required — use sorting + min heap of end times
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Find the kth largest element in an unsorted array in O(N) average
             Use QuickSelect algorithm (partition without fully sorting)
             Asked at: Amazon, Microsoft, Facebook/Meta

  [C][ ] (M) Trapping rain water using two pointers — O(N) time O(1) space
             (Different approach from prefix-array solution)
             Asked at: Amazon, Google, Microsoft, Flipkart

  [C][ ] (M) Given sorted matrix (rows and columns sorted), find kth smallest
             Use min heap of size K or binary search on value range
             Asked at: Amazon, Google, Microsoft

  [C][ ] (M) Count all subarrays with product less than K — sliding window O(N)
             Asked at: Amazon, Flipkart

  [C][ ] (M) Given array of length 2N with first N as sequence and next N as pairs,
             interleave them as p1,q1,p2,q2,... in O(1) extra space
             Asked at: Google, Adobe

================================================================================
SECTION 4 — HARD CODING QUESTIONS
================================================================================

--------------------------------------------------------------------------------
4A. HARD CODING (from all_in_one_question — Part 1)
--------------------------------------------------------------------------------

  [C][ ] (H) Largest rectangle in histogram
             Asked at: Amazon, Google, Microsoft, Adobe, Goldman Sachs

  [C][ ] (H) Maximum size rectangle of 1s in a binary matrix
             Asked at: Amazon, Microsoft, Google

  [C][ ] (H) Median of two sorted arrays in O(log(min(m, n)))
             Asked at: Google, Amazon, Microsoft

--------------------------------------------------------------------------------
4B. HARD CODING (from all_in_one_question_1 — Part 2, Section C)
--------------------------------------------------------------------------------

  [C][ ] (H) Minimum number of platforms required at a railway station
             Sort arrival and departure arrays, simulate with two pointers
             Asked at: Amazon, Goldman Sachs, Flipkart, Paytm

  [C][ ] (H) Count smaller elements after self using merge sort or BIT
             Asked at: Google, Amazon, Goldman Sachs

  [C][ ] (H) Maximum sum of K non-overlapping subarrays
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Find the K-th smallest element in a sorted matrix
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Maximum gap between sorted elements using bucket sort
             Asked at: Google, Amazon

--------------------------------------------------------------------------------
4C. HARD CODING (from all_in_one_question_2 — Part 3)
--------------------------------------------------------------------------------

  [C][ ] (H) Find the maximum XOR of any two elements in an array
             Hint: Trie-based approach O(N log max_val)
             Asked at: Amazon, Google

  [C][ ] (H) Count subarrays with XOR equal to K
             Hint: prefix XOR + hashmap
             Asked at: Amazon, Flipkart, Goldman Sachs

  [C][ ] (H) Find the K-th smallest element in unsorted array in O(N) average
             Using QuickSelect
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Find the maximum circular subarray sum
             Hint: total_sum - min_subarray_sum (handle all-negative case)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Find minimum number of elements to remove so that max - min < K
             Hint: sort, use sliding window
             Asked at: Amazon, Google

  [C][ ] (H) Find all triplets (i, j, k) where i<j<k and arr[i]<arr[j]>arr[k]
             (peak triplets) — count them
             Asked at: Google, Goldman Sachs

  [C][ ] (H) Maximum sum of two non-overlapping subarrays of lengths L and M
             Hint: prefix max arrays from left and right
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Partition array into two subsets with minimum absolute difference
             Hint: DP — subset sum variant
             Asked at: Amazon, Google, Goldman Sachs

  [C][ ] (H) Number of subarrays with exactly K distinct integers
             Hint: exactly K = atMost(K) - atMost(K-1)
             Asked at: Google, Amazon

  [C][ ] (H) Maximum width ramp: find max (j - i) such that arr[i] <= arr[j]
             Hint: monotonic stack + traverse from right
             Asked at: Google, Amazon, Goldman Sachs

--------------------------------------------------------------------------------
4D. HARD CODING (from all_in_one_question_3 — Part 4)
--------------------------------------------------------------------------------

  [C][ ] (H) Find the longest consecutive sequence in unsorted array in O(N)
             Use unordered_set; only start counting from sequence beginnings
             Asked at: Amazon, Google, Facebook/Meta

  [C][ ] (H) Find maximum sum rectangle in a 2D matrix
             Extend Kadane's to 2D — O(N^2 * M)
             Asked at: Amazon, Microsoft, Google

  [C][ ] (H) Minimum number of platforms required at a railway station
             Given arrival[] and departure[], sort both and use two pointers
             Asked at: Amazon, Microsoft, Flipkart, Paytm

  [C][ ] (H) Max sum of non-adjacent elements, then solve circular version
             (first and last elements are also adjacent in the circular variant)
             Asked at: Amazon, Microsoft, Adobe, Flipkart

  [C][ ] (H) Given array where each element is a jump distance (±), find minimum
             jumps to reach position with value 0 — BFS approach O(N^2)
             Asked at: Google, Microsoft

  [C][ ] (H) Median of two sorted arrays in O(log(min(m,n)))
             Binary search on the smaller array
             Asked at: Google, Amazon, Microsoft, Facebook/Meta

  [C][ ] (H) Weighted job scheduling — given jobs with start, end, profit,
             find max profit from non-overlapping jobs (DP + binary search)
             Asked at: Amazon, Goldman Sachs, Flipkart

  [C][ ] (H) Largest rectangle in a histogram using monotonic stack — O(N)
             Asked at: Amazon, Google, Microsoft

  [C][ ] (H) Maximum sum of K non-overlapping subarrays each of length L
             (Sliding window with DP)
             Asked at: Amazon, Google

  [C][ ] (H) Minimum number of elements to remove so that no element is exactly
             double of another — greedy with frequency counting
             Asked at: Amazon, Razorpay

================================================================================
SUMMARY COUNT
================================================================================

  Category                                  | E  | M  | H  | Total
  ------------------------------------------|----|----|----|---------
  Theory — Core Arrays (Part 1)             |  6 |  0 |  0 |     6
  Theory — Fresh Arrays (Part 4)            |  5 |  0 |  0 |     5
  Coding Easy — Part 1 (q)                  | 10 |  0 |  0 |    10
  Coding Easy — Part 2 Section C (q_1)      |  4 |  0 |  0 |     4
  Coding Easy — Part 3 (q_2)                | 15 |  0 |  0 |    15
  Coding Easy — Part 4 (q_3)                | 14 |  0 |  0 |    14
  Coding Medium — Part 1 (q)                |  0 | 19 |  0 |    19
  Coding Medium — Part 2 Section C (q_1)    |  0 |  9 |  0 |     9
  Coding Medium — Part 3 (q_2)              |  0 | 13 |  0 |    13
  Coding Medium — Part 4 (q_3)              |  0 | 11 |  0 |    11
  Coding Hard — Part 1 (q)                  |  0 |  0 |  3 |     3
  Coding Hard — Part 2 Section C (q_1)      |  0 |  0 |  5 |     5
  Coding Hard — Part 3 (q_2)                |  0 |  0 | 10 |    10
  Coding Hard — Part 4 (q_3)                |  0 |  0 | 10 |    10
  ------------------------------------------|----|----|----|---------
  TOTAL                                     | 54 | 52 | 28 |   134

================================================================================
END
================================================================================
