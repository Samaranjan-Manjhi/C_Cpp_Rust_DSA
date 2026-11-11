/*

   Max Absolute Diff of Two Subarrays

   Given an array of integers arr[], find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.

Examples :

Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 12
Explanation: Two subarrays are [-2, -3] and [4, -1, -2, 1, 5]

Input: arr[] = [2, -1, -2, 1, -4, 2, 8]
Output: 16
Explanation: Two subarrays are [-1, -2, 1, -4] and [2, 8] 

Constraints:
2 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxDiffSubArrays(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     vector<int> leftMin(n), leftMax(n), rightMin(n), rightMax(n);

     int currMin = arr[0], currMax = arr[0];
     leftMin[0] = arr[0];
     leftMax[0] = arr[0];

     for (int i = 1; i<n; i++)
     {
          currMax = max(arr[i], currMax + arr[i]);
          leftMax[i] = max(currMax, leftMax[i - 1]);

          currMin = min(arr[i], currMin + arr[i]);
          leftMin[i] = min(currMin, leftMin[i - 1]);
     }

     currMin = arr[n - 1], currMax = arr[n - 1];
     rightMin[n - 1] = arr[n - 1], rightMax[n - 1] = arr[n - 1];

     for (int i = n - 2; i >= 0; i--)
     {
          currMax = max(arr[i], currMax + arr[i]);
          rightMax[i] = max(currMax, rightMax[i + 1]);

          currMin = min(arr[i], currMin + arr[i]);
          rightMin[i] = min(currMin, rightMin[i + 1]);
     }

     int ans = INT_MIN;
     for (int i = 0; i<n - 1; i++)
     {
          int d1 = abs(leftMin[i] - rightMax[i + 1]);
          int d2 = abs(leftMax[i] - rightMin[i + 1]);

          int d = max(d1, d2);
          ans = max(ans, d);

     }

     return ans;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = maxDiffSubArrays(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
