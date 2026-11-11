/*

   Q3. Find All Numbers Disappeared in an Array
   Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

   Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]

Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n

 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) 
{
     vector<int> res;
     int n = nums.size();
     set<int>s(nums.begin(), nums.end());
     for(int i=1;i<=n;i++)
     {
          if(s.find(i) == s.end())
               res.push_back(i);
     }
     return res;
}

int main()
{
     int n;
     cout << "Enter Size: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> out = findDisappearedNumbers(v);
     if(!out.empty())
     {
          for(int x : out)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
