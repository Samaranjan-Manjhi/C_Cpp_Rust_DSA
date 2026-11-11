/*

   Given an array arr[], find and return the maximum product possible with the subset of elements present in the array.
Note:
The maximum product can be of a single element also.
Since the product can be large, return it modulo 109 + 7.

Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24

Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0

Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.

Constraints:
1 ≤ arr.size() ≤ 2 * 104
-10 ≤ arr[i] ≤ 10

 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int findMaxProduct(vector<int>& arr) 
{
     // code here
     sort(arr.begin(), arr.end());
     cout << "Elem after sorting: ";
     for(int x : arr)
          cout << x << " ";
     cout << endl;
     int maxPro = INT_MIN;
     int pro = 1;
     bool zero = false;
     for(int i=0;i<arr.size();i++)
     {
          cout << "arr[i]: " << arr[i] << endl;
          if(arr[i] == 0)
          {
               zero = true;
               continue;
          }
          pro = pro*arr[i];
          cout << "pro:- " << pro << endl;
          maxPro = max(maxPro, pro);
     }
     if(maxPro < 0 && zero == true)
          return 0;
     return maxPro;
}

int main()
{
     int n;
     cout << "Enter size of the vector: ";
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findMaxProduct(v);
     cout << "Result:-  " << res << endl;



     return 0;
}
