/*

   Given an array arr[], determine whether it represents the level-order traversal of a valid max heap. Return true if it does; otherwise, return false.

Examples :
Input: arr[] = [90, 15, 10, 7, 12, 2]
Output: true
Explanation: The given array represents the following tree. Each parent node is greater than or equal to its children, so the max-heap property holds.


Input: arr[] = [9, 15, 10, 7, 12, 11]
Output: false
Explanation: The given array represents the following tree. It does not satisfy the max-heap property, as 9 is smaller than 15 and 10, and 10 is smaller than 11.


Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105

 */

#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(vector<int> &arr) 
{
     // code here
     int n = arr.size();
     if(n == 1)     return true;
     for(int i=0;i<=(n/2-1);i++)
     {
          int left = 2*i+1;
          int right = 2*i+2;
          if(left < n && arr[left] && right < n && arr[right])
          {
               if(arr[i] < arr[left] || arr[i] < arr[right])
                    return false;
          }
          else if(arr[left])
          {
               if(left < n && arr[i] < arr[left])
                    return false;
          }
          else if(right < n && arr[right])
          {
               if(arr[i] < arr[right])
                    return false;
          }
     }
     return true;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     bool res = isMaxHeap(v);
     if(res)
          cout << "Yes" << endl;
     else
          cout << "No" << endl;

     return 0;
}
