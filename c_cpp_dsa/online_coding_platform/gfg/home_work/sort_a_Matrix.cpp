/*

   Sort a Matrix

   Given an n*n matrix mat[][]. returns the matrix with all elements sorted in non-decreasing order.

Examples:

Input: mat[][] = [[10, 20, 30, 40],
[15, 25, 35, 45], 
[27, 29, 37, 48],
[32, 33, 39, 50]]
Output:
[[10, 15, 20, 25], 
[27, 29, 30, 32],
[33, 35, 37, 39],
[40, 45, 48, 50]]
Explanation:
Sorting the matrix gives this result.

Input: mat[][] = [[1, 5, 3],
[2, 8, 7],
[4, 6, 9]]
Output:
[[1, 2, 3], 
[4, 5, 6],
[7, 8, 9]]
Explanation:
Sorting the matrix gives this result.

Constraints:
1 ≤ n ≤ 1000
1 ≤ mat[i][j] ≤ 105

 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sortedMatrix(vector<vector<int>> mat) 
{
     // code here
     int m = mat.size();
     int n = mat[0].size();
     vector<vector<int>> res;
     vector<int> temp;
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               temp.push_back(mat[i][j]);
          }
     }
     sort(temp.begin(), temp.end());
     int k = 0;
     for(int i=0;i<m;i++)
     {
          vector<int> res1;
          for(int j=0;j<n;j++)
          {
               res1.push_back(temp[k++]);
          }
          res.push_back(res1);
     }

     return res;
}

int main()
{
     int n, m;
     cout << "Enter Matrix Size(m*n): ";
     cin >> m >> n;

     vector<vector<int>> v(m, vector<int>(n));
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cin >> v[i][j];
          }
     }

     cout << "   Result: Elements Before sortedMatrix \n";
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout << v[i][j] << " ";
          }
          cout << endl;
     }

     vector<vector<int>> res = sortedMatrix(v);
     cout << "   Result:- Elements Before sortedMatrix \n";
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout << res[i][j] << " ";
          }
          cout << endl;
     }

     return 0;
}
