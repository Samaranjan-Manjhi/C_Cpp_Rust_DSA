/*

   1004. Max Consecutive Ones III
   Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

   Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

 */

#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) 
{
     int n = nums.size();
     int zero = 0;
     int left = 0, right = 0;
     int maxi = 0;
     while(left < n && right < n)
     {
          if(nums[right] == 0)
          {
               zero++;
          }
          if(zero <= k)
          {
               maxi = max(maxi, right-left+1);
          }
          while(zero > k)
          {
               if(nums[left] == 0)
                    zero--;
               left++;
          }
          right++;
     }
     return maxi;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int k;
     cout << "No. of Swap: ";
     cin >> k;

     int res = longestOnes(v, k);
     cout << "Longest Ones:- " << res << endl;

     return 0;
}
