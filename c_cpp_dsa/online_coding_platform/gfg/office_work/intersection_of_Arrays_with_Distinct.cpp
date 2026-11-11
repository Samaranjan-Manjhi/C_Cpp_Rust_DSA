/*

   Intersection of Arrays with Distinct

   Given two unsorted integer arrays a[] and b[] each consisting of distinct elements, the task is to return the count of elements in the intersection (or common elements) of the two arrays.

   Intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

Examples:

Input: a[] = [89, 24, 75, 11, 23], b[] = [89, 2, 4]
Output: 1
Explanation: 89 is the only element in the intersection of two arrays.

Input: a[] = [1, 2, 4, 3, 5, 6], b[] = [3, 4, 5, 6, 7]
Output: 4
Explanation: 3, 4, 5, and 6 are the elements in the intersection of two arrays.

Input: a[] = [20, 10, 30, 50, 40], b[] = [15, 25, 30, 20, 35]
Output: 2
Explanation: 20 and 30 are the elements in the intersection of the two arrays.

Constraints:
1  ≤  a.size(), b.size() ≤  10^5
1  ≤  a[i], b[i]  ≤  10^5

 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int intersectSize(vector<int> &a, vector<int> &b) 
{
     // code  here
     sort(a.begin(), a.end());
     sort(b.begin(), b.end());
     int m = a.size(), n = b.size();
     int i = 0, j = 0;
     int cnt = 0;
     while(i < m && j < n)
     {
          if(a[i] == b[j])
          {
               cnt++;
               i++;
               j++;
          }
          else if(a[i] < b[j])
          {
               i++;
          }
          else
          {
               j++;
          }
     }

     return cnt;
}

int main()
{
     int m, n;
     cout << "Enter Vector a Size: ";
     cin >> m;

     vector<int> v1(m);
     for(int i=0;i<m;i++)
          cin >> v1[i];

     cout << "Enter Vector b Size: ";
     cin >> n;

     vector<int> v2(n);
     for(int i=0;i<n;i++)
          cin >> v2[i];

     int res = intersectSize(v1, v2);
     cout << "    Result:-   " << res << endl;

     return 0;
}
