/*

Q1.   You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
   You are given an integer array nums representing the data status of this set after the error.
   Find the number that occurs twice and the number that is missing and return them in the form of an array.

   Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]

Constraints:
2 <= nums.length <= 104
1 <= nums[i] <= 104

 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) 
{
     int n = nums.size();
     vector<int> res;
     /* // [2, 2] fail
        for(int i=1;i<=n;i++)
        {
        if(nums[i-1] == nums[i])
        {
        res.push_back(nums[i]);
        res.push_back(nums[i]+1);
        break;
        }
        }
      */
     /* // [3,2,2] fail [2, 1]
        int j = 1;
        for(int i=0;i<n;i++)
        {
        if(nums[i] != j)
        {
        res.push_back(nums[i]);
        res.push_back(j);
        }
        j++;
        }
      */

     /*
        map<int, int> mp;
        int dub = -1, miss = -1;
        for(int i=0;i<n;i++)
        {
        mp[nums[i]]++;
        if(mp[nums[i]] > 1)
        dub = nums[i];
        }

        for(int i=1;i<n+1;i++)
        {
        if(mp.find(i) == mp.end())
        {
        miss = i;
        break;
        }
        }
        return {dub, miss};
      */

     int n = nums.size();
     vector<int> freq(n + 1, 0);
     int duplicate = -1, missing = -1;
     for (int x : nums) 
     {
          freq[x]++;
     }
     for (int i = 1; i <= n; i++) 
     {
          if (freq[i] == 2) 
               duplicate = i;
          else if (freq[i] == 0) 
               missing = i;
     }
     return {duplicate, missing};
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

     vector<int> out = findErrorNums(v);
     if(!out.empty())
     {
          for(int i=0;i<out.size();i++)
          {
               cout << out[i] << " ";
          }
          cout << endl;
     }

     return 0;
}
