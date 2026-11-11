/*

Check for Bitonic with Same Numbers

Given an array arr[] of non-negative integers, determine whether the array is perfect. An array is considered perfect if it first strictly increases, then remains constant, and finally strictly decreases. Any of these three parts can be empty.
Examples:

Input: arr[] = [1, 8, 8, 8, 3, 2]
Output: true
Explanation: The array [1, 8, 8, 8, 3, 2] first increases in the range [0, 1], stays constant in the range [1, 3], and then decreases in the range [3, 4]. Thus, the array is perfect.

Input: arr[] = [1, 1, 2, 2, 1]
Output: false
Explanation: The array does not follow the required pattern of strictly increasing, constant, and then strictly decreasing.

Constraints
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^8

*/

#include <iostream>
#include <vector>

using namespace std;

bool isPerfect(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     int i = 1;
     while(i < n && arr[i] > arr[i-1])
          i++;

     while(i < n && arr[i] == arr[i-1])
          i++;

     while(i < n && arr[i] < arr[i-1])
          i++;

     return (i == n);
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     bool res = isPerfect(v);
     if(res)
          cout << "     Yes\n";
     else
          cout << "     Nope\n";

     return 0;
}
