/*

   3312. Sorted GCD Pair Queries

   You are given an integer array nums of length n and an integer array queries.
   Let gcdPairs denote an array obtained by calculating the
   of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.
   For each query queries[i], you need to find the element at index queries[i] in gcdPairs.
   Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.
   The term gcd(a, b) denotes the greatest common divisor of a and b.

   Example 1:
Input: nums = [2,3,4], queries = [0,2,2]
Output: [1,2,2]
Explanation:
gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].
After sorting in ascending order, gcdPairs = [1, 1, 2].
So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].

Example 2:
Input: nums = [4,4,2,1], queries = [5,3,1,0]
Output: [4,2,1,1]
Explanation:
gcdPairs sorted in ascending order is [1, 1, 1, 2, 2, 4].

Example 3:
Input: nums = [2,2], queries = [0,0]
Output: [2,2]
Explanation:
gcdPairs = [2].

Constraints:
2 <= n == nums.length <= 105
1 <= nums[i] <= 5 * 104
1 <= queries.length <= 105
0 <= queries[i] < n * (n - 1) / 2

 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) 
{
     int maxi = 0;
     int n = nums.size();

     for (int x : nums) 
     {
          if (maxi < x)
               maxi = x;
     }

     vector<int> freq(maxi + 1);
     for (int x : nums) 
     {
          freq[x]++;
     }

     vector<int> divisibleCount(maxi + 1, 0);
     for (int d = 1; d <= maxi; d++) 
     {
          for (int multiple = d; multiple <= maxi; multiple += d) 
          {
               divisibleCount[d] += freq[multiple];
          }
     }

     vector<long long> exactPairs(maxi + 1, 0);

     for (int d = maxi; d >= 1; d--) 
     {
          long long k = divisibleCount[d];
          exactPairs[d] = k * (k - 1) / 2;

          for (int multiple = 2 * d; multiple <= maxi; multiple += d)
               exactPairs[d] -= exactPairs[multiple];
     }

     vector<long long> pre;
     vector<int> gcdVal;

     long long run = 0;

     for (int d = 1; d <= maxi; d++) 
     {
          if (exactPairs[d] > 0) 
          {
               run += exactPairs[d];
               pre.push_back(run);
               gcdVal.push_back(d);
          }
     }

     vector<int> ans;

     for (long long q : queries) 
     {
          int idx = lower_bound(pre.begin(), pre.end(), q + 1) - pre.begin();
          ans.push_back(gcdVal[idx]);
     }

     return ans;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> nums(n);
     for(int i=0;i<n;i++)
          cin >> nums[i];

     int q;
     cout << "Enter Queries Vector Size: ";
     cin >> q;

     vector<long long> queries(q);
     for(int i=0;i<q;i++)
          cin >> queries[i];

     vector<int> res = gcdValues(nums, queries);
     if(!res.empty())
     {
          cout << "    Result:- ";
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
