/*

   Minimum difference pair

   Given an array arr[]. find the minimum difference between any pair in the given array.

Examples:

Input: arr[] = [2, 4, 5, 9, 7]
Output: 1
Explanation: Difference between 5 and 4 is 1.

Input: arr[] = [3, 10, 8, 6]
Output: 2
Explanation: Difference between 8 and 6 is 2.

Constraints:
2 <= arr.size() <= 105
1 <= arr[i] <= 109

 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minDiff(vector<int>& arr) 
{
     // Code here
     sort(arr.begin(), arr.end());
     int n = arr.size();
     int ans = INT_MAX;
     for(int i=0;i<n-1;i++)
     {
          int curr = abs(arr[i] - arr[i+1]);
          ans = min(ans, curr);
     }

     return ans;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = minDiff(v);
     cout << "     Result:- " << res << endl;

     return 0;
}
