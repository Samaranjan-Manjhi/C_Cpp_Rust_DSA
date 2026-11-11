/*

Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

Note: After skipping the element, the subarray must still be non-empty.

Examples:

Input: arr[] = [1, 2, 3, -4, 5]
Output: 11
Explanation: We can get maximum sum subarray by skipping -4.

Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 9
Explanation: We can get maximum sum subarray by skipping -2 as [4,-1,1,5] sums to 9, which is the maximum achievable sum.

Constraints:
1 ≤ arr.size() ≤ 106
-103 ≤ arr[i] ≤ 103

*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSumSubarray(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     int noskip = arr[0];
     int oneskip = INT_MIN;
     int ans = arr[0];

     for(int i=1;i<n;i++)
     {
          int prevnoskip = noskip;
          int prevoneskip = oneskip;
          noskip = max(arr[i], prevnoskip+arr[i]);
          if(prevoneskip != INT_MIN)
               oneskip = max(prevnoskip, prevoneskip+arr[i]);
          else
               oneskip = prevnoskip;
          ans = max(ans, max(noskip, oneskip));
     } 
     return ans;
}

int main()
{
int n;
cout << "Enter Size of Vector: ";
cin >> n;

vector<int> vec(n);
for(int i=0;i<n;i++)
     cin >> vec[i];

int res = maxSumSubarray(vec);
cout << "   Result:- " << res << endl;

return 0;
}
