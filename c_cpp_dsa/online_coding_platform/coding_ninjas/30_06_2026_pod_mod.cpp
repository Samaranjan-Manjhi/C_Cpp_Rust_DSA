/*

   Problem statement

   Rahul is a programming enthusiast. He is currently learning about arrays/lists. One day his teacher asked him to solve a very difficult problem. The problem was to find the length of the smallest subarray(subarray is a contiguous part of an array/list) in a given array/list ‘ARR’ of size ‘N’ with its sum greater than a given value. If there is no such subarray return 0.
Example: Given an ‘ARR’: [1, 2, 21, 7, 6, 12] and a number ‘X’: 23. The length of the smallest subarray is 2 as the subarray is [21, 7].
Note: Here are multiple subarrays whose sum is greater than ‘X’ such as [1, 2, 21] or [7, 6, 12] but we have to choose the minimum length subarray.

Constraints:
1 <= T <= 10^2
1 <= N <= 10^3
1 <= X <= 10^9
0 <= A[i] <= 10^9
Time Limit: 1 sec

Sample Input 1:
2
5 11
9 1 5 3 9
4 8
5 1 2 1 
Sample Output 1:
2
4
Explanation For Sample Input 1:
In the first test case, the length of the minimum subarray is 2. The subarray is [3, 9] as the sum is 12 which is greater than the given value 11.
In the second test case, the length of the minimum subarray is 4. The subarray is [5,1, 2, 1] as the sum is 9 which is greater than the given value 8.

Sample Input 2:
2
7  32
27 1 2 4 15 12 8 
6 10
9 1 2 11 4 1 
Sample Output 2:
3
1
Explanation For Sample Input 2
In the first test case, the length of the minimum subarray is 3. The subarray is [15,12, 8] as the sum is 35 which is greater than the given value 32.
In the second test case, the length of the minimum subarray is 1. The subarray is [11] as the sum is 11 which is greater than the given value 10.

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubArrayLen(vector<int>& arr, int target, int n) 
{
     // Write your code here.
     int l = 0;
     int sum = 0;
     int mini = INT_MAX;
     for(int r=0;r<n;r++)
     {
          sum += arr[r];
          while(sum > target)
          {
               mini = min(mini, r-l+1);
               sum -= arr[l];
               l++;
          }
     }
     if(mini != 0)
          return mini;
     return 0;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int tar;
     cout << "Enter Target Value: ";
     cin >> tar;

     int res = minSubArrayLen(v, tar, n);
     cout << "   Result:- " << res << endl;

     return 0;
}
