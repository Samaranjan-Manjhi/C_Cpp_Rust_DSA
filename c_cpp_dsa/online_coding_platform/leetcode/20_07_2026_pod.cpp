/*

   1260. Shift 2D Grid

   Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

   In one shift operation:
   Element at grid[i][j] moves to grid[i][j + 1].
   Element at grid[i][n - 1] moves to grid[i + 1][0].
   Element at grid[m - 1][n - 1] moves to grid[0][0].

   Return the 2D grid after applying shift operation k times.

   Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Example 2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]

Constraints:
m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100

 */


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
     int m = grid.size();
     int n = grid[0].size();
     int k_new = k%(m*n);
     vector<vector<int>> res(m, vector<int>(n));
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               int oldidx = (i*n) + j;
               int newidx = (oldidx + k_new)%(m*n);
               int new_row = newidx/n;
               int new_col = newidx%n;

               res[new_row][new_col] = grid[i][j];
          }
     }

     return res;
}

int main()
{
     int m, n;
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

     int k;
     cout << "Enter K Value: ";
     cin >> k;

     cout << "   Before Operation Input:- \n";
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout << v[i][j] << " ";
          }
          cout << "\n";
     }

     vector<vector<int>> res = shiftGrid(v, k);
     cout << "   After Operation Result:- \n";
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout << res[i][j] << " ";
          }
          cout << "\n";
     }

     return 0;
}
