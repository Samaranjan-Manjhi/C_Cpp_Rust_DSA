/*

Triplet Family

Given an array arr[] of integers, check whether there exist three elements such that the sum of two elements is equal to the third element. 

Example:

Input: arr[] = [1, 2, 2, 3, 4]
Output: true
Explanation: The pair (2, 2) sums to 4.

Input: arr[] = [5, 4, 3]
Output: false
Explanation: No triplets satisfy the condition.

Input: arr[] = [0, 0, 1, 0, 0, 1]
Output: true
Explanation: The pair(0, 1) sums to 1.

Constraints:
1 <= arr.size() <= 10^3
0 <= arr[i] <= 10^5

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findTriplet(vector<int>& arr) 
{
     // code here
     sort(arr.begin(), arr.end());
     int n = arr.size();
     for (int r = n - 1; r >= 2; r--) 
     {
          int l = 0;
          int j = r - 1;

          while (l < j) 
          {
               int sum = arr[l] + arr[j];

               if (sum == arr[r]) 
                    return true;
               else if (sum < arr[r]) 
                    l++;
               else 
                    j--;
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

     bool res = findTriplet(v);
     if(res)
          cout << "     Yes\n";
     else
          cout << "     No\n";

     return 0;
}
