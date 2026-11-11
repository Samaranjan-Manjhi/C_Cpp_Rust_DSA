/*
   Given an array arr[] consisting of 0’s and 1’s. A flip operation involves changing all 0's to 1's and all 1's to 0's within a contiguous subarray. Formally, select a range (l, r) in the array arr[], such that (0 ≤ l ≤ r < n) holds and flip the elements in this range.

   Return the maximum number of 1's you can get in the array after doing at most 1 flip operation.

Examples :

Input: arr[] = [1, 0, 0, 1, 0]
Output: 4
Explanation: By flipping the subarray from index 1 to 2, the array becomes [1, 1, 1, 1, 0]. This results in a total of 4 ones, which is the maximum possible after at most one flip.

Input: arr[] = [1, 0, 0, 1, 0, 0, 1]
Output: 6
Explanation: By flipping the subarray from index 1 to 5, the array becomes [1, 1, 1, 0, 1, 1, 1]. This results in a total of 6 ones, which is the maximum possible after at most one flip.

Constraints:
1 ≤ n ≤ 106
0 ≤ arr[i] ≤ 1
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSum(vector<int>& arr)
{
     int res = INT_MIN;
     int curr = 0;
     for(int i=0;i<arr.size();i++)
     {
          if(curr < 0)
          {
               curr = arr[i];
          }
          else
          {
               curr += arr[i];
          }
          if(res < curr)
               res = curr;
     }
     cout << "Output : " << res << endl;
     return (res < 0) ? 0 : res;
}
int maxOnes(vector<int>& arr) 
{
     // code here
     int org_cnt1 = 0;
     int n = arr.size();
     for(int i=0;i<arr.size();i++)
     {
          if(arr[i] == 1)
          {
               org_cnt1++;
               arr[i] = -1;
          }
          else if(arr[i] == 0)
          {
               arr[i] = 1;
          }
     }
     for(int x : arr)
          cout << x << " ";
     cout << endl;
     int res = maxSum(arr); 
     cout << "Res:- " << res << endl;
     return res+org_cnt1;
}
int main()
{
     //vector<int> v{1, 0, 0, 1, 0};
     vector<int> v{1, 1};
     //vector<int> v{1, 0, 0, 1, 0, 0, 1};

     cout << "Result:- " << maxOnes(v) << endl;

     return 0;
}
