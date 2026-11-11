/*

   Binary Search

   Given an array arr[], sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

Examples:

Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.

Input: arr[] = [1, 2, 4, 5, 6], k = 3
Output: false
Exlpanation: Since, 3 is not present in the array, output is false.

Input: arr[] = [2, 3, 5, 6], k = 1
Output: false

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ k ≤ 10^6
1 ≤ arr[i] ≤ 10^6

 */

#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& arr, int k)
{
     // code here
     int l = 0, h = arr.size()-1;
     while(l <= h)
     {
          int mid = l + (h-l)/2;
          if(arr[mid] == k)
          {
               return true;
          }
          else if(arr[mid] < k)
          {
               l = mid + 1;
          }
          else
          {
               h = mid - 1;
          }
     }
     return false;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int k;
     cout << "Enter k Value: ";
     cin >> k;

     bool res = binarySearch(v, k);
     if(res)
          cout << "    Found\n";
     else
          cout << "    Not Found\n";

     return 0;
}
