/*

   Equilibrium Point

   Given an array of integers arr[], the task is to find the first equilibrium point in the array.

   The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.

Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.

Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.

Constraints:
3 <= arr.size() <= 105
-104 <= arr[i] <= 104

 */


#include <iostream>
#include <vector>

using namespace std;

int findEquilibrium(vector<int> &arr) 
{
     // code here
     int n = arr.size();
     vector<int> pre(n), pos(n);
     pre[0] = arr[0];
     for(int i=1;i<n;i++)
     {
          pre[i] = pre[i-1]+arr[i];
     }

     pos[n-1] = arr[n-1];
     for(int i=n-2;i>=0;i--)
     {
          
          pos[i] = pos[i+1]+arr[i];
     }

     for(int i=0;i<n;i++)
     {
          if(pre[i] == pos[i])
               return i;
     }

     return -1;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findEquilibrium(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
