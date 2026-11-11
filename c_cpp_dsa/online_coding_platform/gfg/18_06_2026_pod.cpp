/*

   Given a binary matrix mat[][] containing only 0s and 1s, find the total coverage of all 0's. The coverage of a particular 0 cell is defined by checking 1's in its four directions (left, right, up, and down). For each direction, if there is at least one 1 anywhere between the 0 and the boundary of the matrix, the coverage increases by one.

   Return the sum of the coverage values for all 0 cells in the matrix.

Examples:

InInput : [1, 1, 1, 0
1, 0, 0, 1]
Output : 8
Explanation: Coverage of first zero is 2. Coverages of other two zeros is 3 Total coverage = 2 + 3 + 3 = 8
2056958046

Input: matrix = [[0, 1, 0],
[0, 1, 1],
[0, 0, 0]]
Output: 6
Explanation: Total Coverage is 1 + 2 + 1 + 0 + 1 + 1 = 6   

Input: matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage. There fore answer for this test case is 5.

Constraints:
1 ≤ matrix.size, matrix[0].size ≤ 100

 */

#include <iostream>
#include <vector>

using namespace std;

int findCoverage(vector<vector<int>>& mat) 
{
     // code here
     int n = mat.size();
     int m = mat[0].size();

     vector<vector<int>> left(n, vector<int>(m, 0));
     vector<vector<int>> right(n, vector<int>(m, 0));
     vector<vector<int>> up(n, vector<int>(m, 0));
     vector<vector<int>> down(n, vector<int>(m, 0));

     // LEFT + RIGHT
     for (int i = 0; i < n; i++) {
          int seen = 0;
          for (int j = 0; j < m; j++) {
               if (mat[i][j] == 1) seen = 1;
               left[i][j] = seen;
          }

          seen = 0;
          for (int j = m - 1; j >= 0; j--) {
               if (mat[i][j] == 1) seen = 1;
               right[i][j] = seen;
          }
     }

     // UP + DOWN
     for (int j = 0; j < m; j++) {
          int seen = 0;
          for (int i = 0; i < n; i++) {
               if (mat[i][j] == 1) seen = 1;
               up[i][j] = seen;
          }

          seen = 0;
          for (int i = n - 1; i >= 0; i--) {
               if (mat[i][j] == 1) seen = 1;
               down[i][j] = seen;
          }
     }

     int ans = 0;

     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {

               if (mat[i][j] == 0) {
                    int coverage = 0;

                    if (left[i][j]) coverage++;
                    if (right[i][j]) coverage++;
                    if (up[i][j]) coverage++;
                    if (down[i][j]) coverage++;

                    ans += coverage;
               }
          }
     }
     return ans;
}

int main()
{
     int n, m;
     cout << "Enter Size of Matrix: ";
     cin >> n >> m;

     vector<vector<int>> v(n, vector<int>(m));
     for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
               cin >> v[i][j];

     int res = findCoverage(v);
     cout << "Result:- " << res << endl;

     return 0;
}
