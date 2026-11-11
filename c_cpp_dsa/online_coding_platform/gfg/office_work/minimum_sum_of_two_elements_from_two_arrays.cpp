/*

Minimum sum of two elements from two arrays

Given two arrays arr1[] and arr2[] of the same size, find the minimum sum of two elements such that one element is from arr1[] and the other is from arr2[], and they are not at the same index in their respective arrays.

Examples:

Input: arr1[] = [5, 4, 13, 2, 1], arr2[] = [2, 3, 4, 6, 5]
Output: 3
Explanation: The minimum sum is obtained by taking 1 from arr1[] and 2 from arr2[]. The sum is 1 + 2 = 3.

Input: arr1[] = [5, 4, 13, 1], arr2[] = [3, 2, 6, 1]
Output: 3
Explanation: The minimum sum is obtained by taking 1 from arr1[] and 2 from arr2[]. We can't take 1 from arr2[] as it is at the same index.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ arr1.size() = arr2.size() ≤ 106
1 ≤ arr1[i], arr2[i] ≤ 105

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minSum(vector<int>& arr1, vector<int>& arr2) 
{
     // code here
     int n = arr1.size();
     int m = arr2.size();

     int min1 = arr1[0];
     int min1Idx = 0;
     for(int i=1;i<n;i++)
     {
          if(min1 > arr1[i])
          {
               min1 = arr1[i];
               min1Idx = i;
          }
     }

     int min2 = arr2[0];
     int min2Idx = 0;
     for(int i=1;i<m;i++)
     {
          if(min2 > arr2[i])
          {
               min2 = arr2[i];
               min2Idx = i;
          }
     }
     if(min1Idx != min2Idx)
          return (min1 + min2);

     int min11 = INT_MAX;
     int min11Idx;
     for(int i=0;i<n;i++)
     {
          if(i != min1Idx && arr1[i] < min11)
          {
               min11 = arr1[i];
               min11Idx = i;
          }
     }

     int min21 = INT_MAX;
     int min21Idx;
     for(int i=0;i<m;i++)
     {
          if(i != min2Idx && arr2[i] < min21)
          {
               min21 = arr2[i];
               min21Idx = i;
          }
     }

     return min(min1+min21, min2+min11);
}

int main()
{
     int n;
     cout << "Enter Vector1 Size: ";
     cin >> n;

     vector<int> v1(n);
     for(int i=0;i<n;i++)
          cin >> v1[i];

     int m;
     cout << "Enter Vector2 Size: ";
     cin >> m;

     vector<int> v2(m);
     for(int i=0;i<m;i++)
          cin >> v2[i];

     int res = minSum(v1, v2);
     cout << "    Result:- " << res << endl;

     return 0;
}
