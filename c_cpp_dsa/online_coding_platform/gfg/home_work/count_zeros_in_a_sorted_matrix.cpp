/*

   Count zeros in a sorted matrix

   Given a n * n binary Square Matrix where each row and column of the matrix is sorted in ascending order. Find the total number of zeros present in the matrix.

Examples:

Input: mat[][] = [[0,0,0], [0,0,1], [0,1,1]]
Output: 6
Explanation: 
The first, second and third row contains 3, 2 and 1
zeroes respectively.

Input: mat[][] = [[1,1], [1,1]]
Output: 0
Explanation:
There are no zeroes in any of the rows.

Constraints
0 < n ≤ 10^3
0 ≤ mat[i][j] ≤ 1

 */

#include <iostream>
#include <vector>

using namespace std;

int countZeros(vector<vector<int>>& mat) 
{
     // code here
     int cnt = 0;
     int n = mat.size();
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               if(mat[i][j] == 0)
                    cnt++;
          }
     }
     return cnt;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<vector<int>> v(n, vector<int> (n));
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               cin >> v[i][j];
          }
     }

     int res = countZeros(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
