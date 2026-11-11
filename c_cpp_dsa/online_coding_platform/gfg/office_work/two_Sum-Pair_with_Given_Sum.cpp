/*

   Two Sum - Pair with Given Sum

   Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.

Examples:

Input: arr[] = [0, -1, 2, -3, 1], target = -2
Output: true
Explanation: arr[3] + arr[4] = -3 + 1 = -2

Input: arr[] = [1, -2, 1, 0, 5], target = 0
Output: false
Explanation: None of the pair makes a sum of 0

Input: arr[] = [11], target = 11
Output: false
Explanation: No pair is possible as only one element is present in arr[]

Constraints:
1 ≤ arr.size ≤ 105
-105 ≤ arr[i] ≤ 105
-2*105 ≤ target ≤ 2*105

 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool twoSum(vector<int>& arr, int target)
{
     // code here
     int n = arr.size();
     sort(arr.begin(), arr.end());
     int l = 0, r = n-1;
     while(l < r)
     {
          int sum = arr[l] + arr[r];
          if(sum == target)
               return true;
          else if(sum > target)
          {
               r--;
          }
          else
          {
               l++;
          }
     }

     return false;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int x;
     cout << "Enter target Value: ";
     cin >> x;

     bool res = twoSum(v, x);
     cout << "     Result:- ";
     if(res)
          cout << "  Yes\n";
     else
          cout << "  Nope\n";

     return 0;
}
