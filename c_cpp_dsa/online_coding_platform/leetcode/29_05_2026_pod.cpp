/*

   You are given an integer array nums.
   You replace each element in nums with the sum of its digits.
   Return the minimum element in nums after all replacements.

   Example 1:
Input: nums = [10,12,13,14]
Output: 1
Explanation:
nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:
Input: nums = [1,2,3,4]
Output: 1
Explanation:
nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:
Input: nums = [999,19,199]
Output: 10
Explanation:
nums becomes [27, 10, 19] after all replacements, with minimum element 10.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 104


 */


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int digitSum(int n)
{
     int res = 0;
     while(n > 0)
     {
          int d = n%10;
          res += d;
          n /= 10;
     }
     return res;
}

int minElement(vector<int>& nums) 
{
     int minValue = INT_MAX;
     for(int i=0;i<nums.size();i++)
     {
          int output = digitSum(nums[i]);
          minValue = min(minValue, output); 
     }
     return minValue;
}

int main()
{
     int n;
     cout << "Enter Size of vector: ";
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = minElement(v);
     cout << "Result:-->  " << res << endl;

     return 0;
}
