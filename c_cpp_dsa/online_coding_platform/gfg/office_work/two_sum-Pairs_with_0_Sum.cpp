/*

   Two sum - Pairs with 0 Sum

   Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.

Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

Examples:

Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].

Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
Output: [[-6, 6],[-1, 1]]
Explanation: The distinct pairs are [-1, 1] and [-6, 6].

Constraints:
3 ≤ arr.size ≤ 105
-105 ≤ arr[i] ≤ 105

 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> getPairs(vector<int>& arr) 
{
     // code here
     vector<vector<int>> res;
     int n = arr.size();
     sort(arr.begin(), arr.end());
     int l = 0, r = n - 1;
     while (l < r)
     {
          vector<int> temp;
          int sum = arr[l] + arr[r];

          if (sum == 0)
          {
               temp.push_back(arr[l]);
               temp.push_back(arr[r]);
               res.push_back(temp);
               l++;
               r--;
               while (l > 0 && l < n && arr[l - 1] == arr[l])
                    l++;

               while (r > 0 && arr[r - 1] == arr[r])
                    r--;
          }
          else if (sum > 0)
          {
               r--;
          }
          else
          {
               l++;
          }
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<vector<int>> res = getPairs(v);
     cout << "    Result:- ";
     if(!res.empty())
     {
          for(int i=0;i<res.size();i++)
               cout << res[i][0] << "  " << res[i][1] << endl;
     }

     return 0;
}
