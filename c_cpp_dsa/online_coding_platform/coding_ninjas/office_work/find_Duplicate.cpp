/*

   Find Duplicate

   Problem statement

   You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3 and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.

Note :
Duplicate number is always present in the given array/list.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
Time Limit: 1 sec

Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7

Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3

 */


#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

/*

   int duplicateNumber(int *arr, int size)
   {
// Sum of numbers from 0 to size - 2
int expectedSum = ((size - 2) * (size - 1)) / 2;

int actualSum = 0;
for (int i = 0; i < size; i++)
{
actualSum += arr[i];
}

return actualSum - expectedSum;
}

int duplicateNumber(int *arr, int size)
{
int xorResult = 0;

// XOR all elements in the array
for (int i = 0; i < size; i++)
{
xorResult ^= arr[i];
}

// XOR numbers from 0 to size - 2
for (int i = 0; i <= size - 2; i++)
{
xorResult ^= i;
}

return xorResult;
}

int findDuplicate_BruteForce(int* arr, int size) {
for (int i = 0; i < size; i++) {
for (int j = i + 1; j < size; j++) {
if (arr[i] == arr[j]) return arr[i];
}
}
return -1;
}

int findDuplicate_Sorting(int* arr, int size) {
std::sort(arr, arr + size); // Modifies original array
for (int i = 0; i < size - 1; i++) {
if (arr[i] == arr[i + 1]) {
return arr[i];
}
}
return -1;
}

int findDuplicate_FrequencyArray(int* arr, int size) {
std::vector<int> freq(size, 0);
for (int i = 0; i < size; i++) {
if (freq[arr[i]] == 1) {
return arr[i];
}
freq[arr[i]]++;
}
return -1;
}

int findDuplicate_Negation(int* arr, int size) {
for (int i = 0; i < size; i++) {
int index = std::abs(arr[i]);
if (arr[index] < 0) {
return index; // Already marked negative -> duplicate found!
}
arr[index] = -arr[index]; // Mark as visited
}
return -1;
}

int findDuplicate_FloydCycle(int* arr, int size) {
     int slow = arr[0];
     int fast = arr[0];

     // Phase 1: Detect Cycle
     do {
          slow = arr[slow];
          fast = arr[arr[fast]];
     } while (slow != fast);

     // Phase 2: Find Entrance to Cycle (Duplicate)
     fast = arr[0];
     while (slow != fast) {
          slow = arr[slow];
          fast = arr[fast];
     }

     return slow;
}

int findDuplicate_BinarySearch(int* arr, int size) {
     int low = 1, high = size - 1;
     int duplicate = -1;

     while (low <= high) {
          int mid = low + (high - low) / 2;
          int count = 0;

          for (int i = 0; i < size; i++) {
               if (arr[i] <= mid) count++;
          }

          if (count > mid) {
               duplicate = mid; // Duplicate lies in left half
               high = mid - 1;
          } else {
               low = mid + 1; // Duplicate lies in right half
          }
     }
     return duplicate;
}

*/

int duplicateNumber(int *arr, int size)
{
     unordered_set<int> seen;
     for(int i = 0; i < size; i++)
     {
          if(seen.find(arr[i]) == seen.end())
          {
               seen.insert(arr[i]);
          }
          else
          {
               return arr[i]; // Found duplicate!
          }
     }

     return -1; // No duplicate found
}

int main()
{
     int size;

     cout << "Enter the size of the array: ";
     cin >> size;

     if (size <= 0) {
          cout << "Invalid array size." << endl;
          return 0;
     }

     int* arr = new int[size];

     cout << "Enter " << size << " space-separated integers: ";
     for(int i = 0; i < size; i++) {
          cin >> arr[i];
     }

     int result = duplicateNumber(arr, size);

     if (result != -1) {
          cout << "The first duplicate element is: " << result << endl;
     } else {
          cout << "No duplicate elements found." << endl;
     }

     // Clean up dynamically allocated memory
     delete[] arr;

     return 0;
}
