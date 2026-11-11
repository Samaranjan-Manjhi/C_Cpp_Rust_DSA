/*

   Smallest Repeating K Times

   Given an array arr, the goal is to find out the smallest number that is repeated exactly ‘k’ times.

Note: If there is no such element then return -1.

Example:

Input: arr[] = [2, 2, 1, 3, 1], k = 2
Output: 1
Explanation: 2 and 1 both appear exactly 2 times. Since we need to find the smallest, output is 1.

Input: arr[] = [3, 5, 3, 2], k = 1
Output:  2 
Explanation: 5 and 2 each appear exactly 1 time. Since we need the smallest, the output is 2.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 104

 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int findDuplicate(vector<int>& arr, int k) 
{
     // code here
     map<int, int> mp;
     for(int x : arr)
     {
          mp[x]++;
     }
     sort(arr.begin(), arr.end());
     for(int x : arr)
     {
          if(mp[x] == k)
               return x;
     }
     return -1;
}

int main()
{
     int n, k;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "Enter Occurance: ";
     cin >> k;

     int res = findDuplicate(v, k);
     cout << "    Result:- " << res << endl;

     return 0;
}
