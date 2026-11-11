/*

   Subarrays with given sum

   Given an unsorted array arr[] of integers and a sum k. The task is to count the number of subarrays that add to a given number k.

Examples:

Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].

Input: arr[] = [1, 4, 20, 3, 10, 5], k = 33
Output: 1

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ arr.size() ≤ 10^6
-106 ≤ arr[i],k ≤ 10^6

 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subArraySum(vector<int>& arr, int k) 
{
     // code here.
     int n = arr.size();
     int cnt = 0;
     unordered_map<int, int> mp;
     mp[0] = 1;
     int prefixSum = 0;
     for(int x : arr)
     {
          prefixSum += x;
          if(mp.find(prefixSum-k) != mp.end())
               cnt = cnt + mp[prefixSum-k];

          mp[prefixSum] = mp[prefixSum] + 1;
     }
     return cnt;
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
     cout << "Enter k value: ";
     cin >> k;

     int res = subArraySum(v, k);
     cout << "    Result:- " << res << endl;

     return 0;
}
