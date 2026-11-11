/*

   Length of longest subarray

   Given an array arr[], return the length of the longest subarray of non-negative integers.

Examples:

Input: arr[] = [2, 3, 4, -1, -2, 1, 5, 6, 3]
Output: 4
Explanation: The subarray [ 1, 5, 6, 3] has longest length 4 and contains no negative integers.

Input: arr[] = [1, 0, 0, 1, -1, -1, 0, 0, 1, 0]
Output: 4
Explanation: The subarrays [1, 0, 0, 1] and [0, 0, 1, 0] both have the maximum length 4 and contain no negative integers. Hence, the answer is 4.

Constraints:
1 ≤ arr.size() ≤ 10^6
-106 ≤ arr[i] ≤ 10^6

 */


#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& arr) 
{
     // code here
     int maxi = 0;
     int len = 0;
     for(int i=0;i<arr.size();i++)
     {
          //int len = 0;
          if(arr[i] >= 0)
          {
               len++;
          }
          else
          {
               len = 0;
          }

          maxi = max(maxi, len);
     }

     return maxi;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = longestSubarray(v);
     cout << "   Result:- " << res << endl;

     return 0;
}
