/*

   Sum Array Puzzle

   Given an array arr[] of integers, modify the array such that each element at index i becomes the sum of all elements of the array except the element present at index i.

   That is, update each element as:
   arr[i] = arr[0] + arr[1] + ... + arr[i-1] + arr[i+1] + ... + arr[n-1]

Examples:

Input: arr[] = [3, 6, 4, 8, 9]
Output: [27, 24, 26, 22, 21]
Explanation: For each index, replace the current element with the sum of all remaining elements in the array.
At index 0, sum = 6 + 4 + 8 + 9 = 27
At index 1, sum = 3 + 4 + 8 + 9 = 24
At index 2, sum = 3 + 6 + 8 + 9 = 26
At index 3, sum = 3 + 6 + 4 + 9 = 22
At index 4, sum = 3 + 6 + 4 + 8 = 21
Thus, the modified array becomes [27, 24, 26, 22, 21].

Input: arr[] = [0, 0, 1]
Output: [1, 1, 0]
Explantion: Each element is replaced with the sum of all other elements in the array.
At index 0, sum = 0 + 1 = 1
At index 1, sum = 0 + 1 = 1
At index 2, sum = 0 + 0 = 0
Thus, the modified array becomes [1, 1, 0].

Constraint :
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^4

 */

#include <iostream>
#include <vector>

using namespace std;

void sumArray(vector<int> &arr) 
{
     // code here
     int sum = 0;
     for(int s : arr)
          sum += s;

     for(int i=0;i<arr.size();i++)
     {
          arr[i] = sum - arr[i];
     }
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "Elements Before sumArray Operation:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;
     sumArray(v);
     cout << "Elements After sumArray Operation:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;     

     return 0;
}
