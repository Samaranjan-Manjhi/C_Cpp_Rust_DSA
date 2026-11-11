/*

   Check if array is sorted

   Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

Examples:

Input: arr[] = [10, 20, 30, 40, 50]
Output: true
Explanation: The given array is sorted.

Input: arr[] = [90, 80, 100, 70, 40, 30]
Output: false
Explanation: The given array is not sorted.

Constraints:
1 ≤ arr.size ≤ 106
- 109 ≤ arr[i] ≤ 109

 */


#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     if(n == 1)
          return true;
     for(int i=1;i<n;i++)
     {
          if(arr[i-1] > arr[i])
               return false;
     }

     return true;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     bool res = isSorted(v);
     cout << "     Result:- ";
     if(res)
          cout << "  Yes\n";
     else
          cout << "  Nope\n";

     return 0;
}
