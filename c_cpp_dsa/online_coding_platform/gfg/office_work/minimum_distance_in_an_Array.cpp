/*

   Minimum distance in an Array

   You are given an array, arr[]. Find the minimum index based distance between two different elements of the array, x and y. Return -1, if either x or y does not exist in the array.

Examples:

Input: arr[] = [1, 2, 3, 2], x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are two distances between x and y, which are 1 and 3 out of which the least is 1.

Input: arr[] = [86, 39, 90, 67, 84, 66, 62], x = 42, y = 12
Output: -1
Explanation: x = 42 and y = 12. We return -1 as x and y don't exist in the array.

Input: arr[] = [10, 20, 30, 40, 50], x = 10, y = 50
Output: 4
Explanation: The distance between x = 10 (index 0) and y = 50 (index 4) is 4, which is the only distance between them.

Constraints:
1 <= arr.size() <= 10^5
0 <= arr[i], x, y <= 10^5
x != y

 */


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minDist(vector<int>& arr, int x, int y) 
{
     // code here
     int last_x = -1, last_y = -1;
     int mini_dst = INT_MAX;
     for(int i=0;i<arr.size();i++)
     {
          if(arr[i] == x)
          {
               last_x = i;
               if(last_y != -1)
               {
                    mini_dst = min(mini_dst, abs(last_x - last_y));
               }
          }
          else if(arr[i] == y)
          {
               last_y = i;
               if(last_x != -1)
               {
                    mini_dst = min(mini_dst, abs(last_y - last_x));
               }
          }
     }

     if(last_x == -1 || last_y == -1)
          return -1;

     return mini_dst;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int x, y;
     cout << "Enter Value of x & y: ";
     cin >> x >> y;

     int res = minDist(v, x, y);
     cout << "   Result:-  " << res << endl;

     return 0;
}
