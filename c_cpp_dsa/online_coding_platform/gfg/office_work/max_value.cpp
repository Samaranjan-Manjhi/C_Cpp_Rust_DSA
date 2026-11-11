/*

   Max valu

   In a given array arr[], find the maximum value of (arr[i] – i) - (arr[j] – j) where i is not equal to j and n is the size of the array. i and j vary from 0 to n-1  arr[].

Examples:

Input: arr[] = [9, 15, 4, 12, 13]
Output: 12
Explanation: (a[1]-1) - (a[2]-2) = (15-1)-(4-2) = 12

Input: arr[] = [3, 1, 2, 4]
Output: 3
Explanation: (a[0]-0) -(a[1]-1) = (3-0) - (1-1) = 3

Constraints:
2 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxVal(vector<int> &arr) 
{
     // code here
     int maxi = INT_MIN;
     int mini = INT_MAX;
     int n = arr.size();
     for(int i=0;i<n;i++)
     {
          int val = arr[i] - i;
          maxi = max(maxi, val);
          mini = min(mini, val);
     }

     return maxi-mini;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = maxVal(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
