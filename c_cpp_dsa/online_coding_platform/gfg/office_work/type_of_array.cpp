/*

Type of array

You are given an array arr[] having unique elements. Your task is to return the type of array described below.

    Return 1 if the array is in ascending order. 
    Return 2 if the array is in descending order
    Return 3 if the array is in descending rotated order
    Return 4 if the array is in ascending rotated order

You may assume that the input array is always one of the four types.

Examples:

Input: arr[] = [2, 1, 5, 4, 3]
Output: 3
Explanation: Descending rotated, rotate 2 times left.

Input: arr[] = [3, 4, 5, 1, 2]
Output: 4
Explanation: Ascending rotated, rotate 2 times right. 

Constraints:
3 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^6

*/

#include <iostream>
#include <vector>

using namespace std;

int typeOfArr(vector<int>& arr) 
{
     // code here.
     int n = arr.size();

     // check ascending
     bool asc = true;
     for (int i = 0; i < n - 1; i++) 
     {
          if (arr[i] > arr[i + 1]) 
          {
               asc = false;
               break;
          }
     }
     if (asc)
          return 1;

     // check descending
     bool desc = true;
     for (int i = 0; i < n - 1; i++) 
     {
          if (arr[i] < arr[i + 1]) 
          {
               desc = false;
               break;
          }
     }
     if (desc)
          return 2;

     // check ascending rotated (only one drop)
     int drop = 0;
     for (int i = 0; i < n - 1; i++) 
     {
          if (arr[i] > arr[i + 1])
               drop++;
     }
     if (arr[n - 1] > arr[0])
          drop++;

     if (drop == 1)
          return 4;

     // otherwise descending rotated
     return 3;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = typeOfArr(v);
     cout << "     Result:- " << res << endl;

     return 0;
}
