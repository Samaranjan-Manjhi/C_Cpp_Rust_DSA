/*

   Given an array arr[] consisting of n distinct integers, find the maximum count of integers that are binary searchable in the given array. Binary searchable elements are determined using the standard Binary Search implementation described below.

   Initially l is 0 and r is size of array - 1 
   while(l <= r), compute mid as floor of (l + r)/2 and compare with mid.
   If the target element is same as mid, return true. Else if mid is smaller, change l = mid + 1, else change r = mid - 1.

   For example:
   In arr[] = [2, 1, 3, 4, 6, 5], the element 5 is not binary searchable. During Binary Search, the search eventually reaches the subarray containing 6, and since 6 > 5, the search moves left (r = mid - 1), causing the element 5 to be skipped.
   In arr[] = [2, 1, 3, 4, 5, 6], the element 5 is binary searchable because the standard Binary Search process eventually reaches and finds 5.

Examples:

Input: arr[] = [1, 3, 2]
Output: 2
Explanation: arr[0], arr[1] can be found.

Input: arr[] = [2, 1, 3, 5, 4, 6]
Output: 4
Explanation: arr[0], arr[2], arr[4], arr[5] can be found.

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105

An element is binary-searchable if it is larger than everything to its left and smaller than everything to its right.

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isbinarySearchable(vector<int>& v, int x)
{
     int l = 0, r = v.size()-1;
     while(l <= r)
     {
          int mid = l+(r-l)/2;
          if(v[mid] == x)
               return true;
          else if(v[mid] < x)
               l = mid+1;
          else
               r = mid-1;
     }
     return false;
}

int binarySearchable(vector<int>& arr) 
{
     // code here
     int cnt = 0;
     for(int x : arr)
     {
          if(isbinarySearchable(arr, x))
               cnt++;
     }
     return cnt;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = binarySearchable(v);
     cout << "Result:-  " << res << endl;


     return 0;
}
