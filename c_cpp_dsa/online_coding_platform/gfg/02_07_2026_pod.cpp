/*

Check Subset sum divisible by k

Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the given array is divisible by k otherwise, return false.

Examples:

Input: arr[] = [3, 1, 7, 5] , k = 6
Output: true
Explanation: If we take the subset {7, 5} then sum will be 12 which is divisible by 6.

Input: arr[] = [1, 2, 6] , k = 5
Output: false
Explanation: All possible subsets of the given set are {1}, {2}, {6}, {1, 2}, {2, 6}, {1, 6} and {1, 2, 6}. There is no subset whose sum is divisible by 5.

Constraints:
1 ≤ arr.size(), k ≤ 103
1 ≤ arr[i] ≤ 103

*/

#include <iostream>
#include <vector>

using namespace std;

bool divisibleByK(vector<int>& arr, int k)
{
     // code here
     /* // TLE
        int n = arr.size();
        vector<bool> included(n, false);
        while (true) {
        long long current_sum = 0; 
        for (int i = 0; i < n; ++i) {
        if (included[i]) {
        current_sum += arr[i];
        }
        }
     //std::cout << current_sum << "\n";
     if(current_sum > 0 && current_sum%k == 0)
     return true;
     int i = 0;
     while (i < n && included[i]) {
     included[i] = false;
     i++;
     }
     if (i == n)
     break;

     included[i] = true;
     }
     return false;
      */

     int n = arr.size();
     vector<int> dp(k, false);

     for(int x : arr)
     {
          vector<int> next = dp;
          next[x%k] = true;

          for(int i=0;i<next.size();i++)
          {
               if(dp[i] == true)
               {
                    int newRem = (i+x)%k;
                    next[newRem] = true;
               }
          }
          dp = next;
          if(dp[0] == true)
               return true;
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
     cout << "Enter Divisor Value: ";
     cin >> k;

     bool res = divisibleByK(v, k);
     if(res)
          cout << "    Yes\n";
     else
          cout << "    No\n";

     return 0;
}
