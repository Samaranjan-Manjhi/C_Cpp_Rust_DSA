/*

   Max Sum Path in Two Arrays

   Given two sorted arrays of distinct integers in increasing order a[] and b[], which may have some common elements, find the maximum sum of a path from the beginning of any array to the end of any array. You may switch from one array to the other only at common elements.

Note:  When switching, count the common element only once.

Examples : 

Input: a[] = [2, 3, 7, 10, 12], b[] = [1, 5, 7, 8]
Output: 35
Explanation: The path will be (1 + 5 + 7 + 10 + 12) = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.

Input: a[] = [1, 2, 3], b[] = [3, 4, 5]
Output: 15
Explanation: The path will be (1 + 2 + 3 + 4 + 5) = 15.

Constraints:
1 ≤ a.size(), b.size() ≤ 10^4
1 ≤ a[i], b[i] ≤ 10^5

 */

#include <iostream>
#include <vector>

using namespace std;

int maxPathSum(vector<int> &a, vector<int> &b) 
{
     // Code here
     int sumA = 0, sumB = 0;
     int res = 0;
     int n = a.size(), m = b.size();
     int i = 0;
     int j = 0;
     int comm = 0;
     while(i < n && j < m)
     {
          if(a[i] < b[j])
          {
               sumA += a[i];
               i++;
          }
          else if(b[j] < a[i])
          {
               sumB += b[j];
               j++;
          }
          else if(a[i] == b[j])
          {
               comm = a[i];
               res += max(sumA, sumB);
               res += comm;
               sumA = 0;
               sumB = 0;
               i++;
               j++;
          }
     }

     if(j != m)
     {
          while(j < m)
          {
               sumB += b[j];
               j++;
          }
     }

     if(i != n)
     {
          while(i < n)
          {
               sumA += a[i];
               i++;
          }
     }

     res += max(sumA, sumB);

     return res;
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

     int res = maxPathSum(v1, v2);
     cout << "     Result:- " << res << endl;

     return 0;
}
