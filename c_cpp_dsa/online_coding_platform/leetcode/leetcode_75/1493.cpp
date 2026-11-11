/*

   1493. Longest Subarray of 1's After Deleting One Element

   Given a binary array nums, you should delete one element from it.
   Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

   Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

 */

#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) 
{
     int n = nums.size();
     int left = 0, right = 0;
     int zero = 0;
     int maxLen = 0;
     while(left < n && right < n)
     {
          if(nums[right] == 0)
          {
               zero++;
          }
          while(zero > 1)
          {
               if(nums[left] == 0)
                    zero--;
               left++;
          }
          maxLen = max(maxLen, right-left+1);
          right++;
     }
     return maxLen-1;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = longestSubarray(v);
     cout << "Longest Subarray of 1's:- " << res << endl;

     return 0;
}
