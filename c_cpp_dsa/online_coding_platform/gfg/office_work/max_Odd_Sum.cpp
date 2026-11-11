/*

Max Odd Sum

Given an array arr[] of integers, determine whether a subsequence exists with an odd sum. If such a subsequence exists, return the maximum possible odd sum. If no subsequence with an odd sum can be formed, return -1.

Examples:

Input: arr = [4, -3, 3, -5]
Output: 7
Explanation: The subsequence with the maximum odd sum is [4, 3], and the sum is 4 + 3 = 7.

Input: arr = [2, 5, -4, 3, -1]
Output: 9
Explanation: The subsequence with the maximum odd sum is [2, 5, 3, -1], and the sum is 2 + 5 + 3 + (-1) = 9.

Constraints:
1 ≤ arr.length ≤ 10^6
-103 ≤ arr[i] ≤ 10^3

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxOddSum(vector<int> &arr) 
{
     // code here.
     int sum = 0;
     int smallPosOdd = INT_MAX;
     int larNegOdd = INT_MIN;

     for(int x : arr)
     {
          if( x > 0)
          {
               sum += x;
               if(x % 2 != 0)
               {
                    smallPosOdd = min(smallPosOdd, x);
               }
          }   
          else if(x < 0 && x % 2 != 0)
          {
               larNegOdd = max(larNegOdd, x);
          }
     }

     if(sum % 2 != 0)
          return sum;

     int ans = -1;
     if(smallPosOdd != INT_MAX)
          ans = max(ans, sum - smallPosOdd);

     if(larNegOdd != INT_MIN)
          ans = max(ans, sum + larNegOdd);

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

     int res = findMaxOddSum(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
