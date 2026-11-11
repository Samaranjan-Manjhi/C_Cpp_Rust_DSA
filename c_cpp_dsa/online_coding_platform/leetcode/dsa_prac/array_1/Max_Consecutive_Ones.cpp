/*

   Given a binary array nums, return the maximum number of consecutive 1's in the array.

   Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.

 */

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
     int n = nums.size();
     int sum = 0, maxi = 0;
     for(int x : nums)
          sum += x;
     if(sum == 0)
          return -1;
     else
     {
          for(int i=0;i<n;i++)
          {
               int cnt = 1;
               while(i+1 < n && nums[i] == 1 && nums[i] == nums[i+1])
               {
                    cnt++;
                    i++;
               }
               if(cnt > 0)
               {
                    maxi = max(maxi, cnt);
               }
          }
     }
     return maxi;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     if(n == 0)
          return 0;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findMaxConsecutiveOnes(v);
     cout << "Result:-  " << res << endl;

     return 0;
}
