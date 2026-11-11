/*

Company:- Sprinklr, Compass Grp
Problem statement

You are given a binary matrix (it contains only 0s and 1s) with dimensions ‘N * M’. You need to find and return the sum of coverages of all zeros of the given matrix.

Coverage for a particular 0 is defined as the total number of ‘1s’ around it (i.e., immediate left, immediate right, immediate up, and immediate bottom positions).

Constraints:
1 <= T <= 10
1 <= N, M <= 10^3
Time limit: 1 second

Sample Input 1:
1
2 2 
1 0
0 1

Sample Output 1:
4

Explanation of Input 1:
In the given matrix, there are 2 zeros. 
For the 0 at the 1st row, 2nd column position, coverage is 2(there is 1 adjacent top one and 1 adjacent right one).
For the 0 at the 2nd row, 2nd column the coverage is 2(there is 1 adjacent top one and 1 adjacent right one).
Hence the net coverage is 2 + 2 = 4.

Sample Input 2:
1
2 3
0 0 0
0 0 0

Sample Output 2
0

 */

#include <iostream>
#include <vector>
using namespace std;

int coverageOfMatrix(vector<vector<int>>& mat) 
{
     // Write your code here.
     int n = mat.size(), m = mat[0].size();
     int totalCoverage = 0;
     // Traverse every cell
     for (int i = 0; i < n; i++) 
     {
          for (int j = 0; j < m; j++) 
          {
               // Only process cells with 0
               if (mat[i][j] == 0) 
               {
                    int coverage = 0;

                    // Up
                    if (i - 1 >= 0 && mat[i - 1][j] == 1)
                         coverage++;

                    // Down
                    if (i + 1 < n && mat[i + 1][j] == 1)
                         coverage++;

                    // Left
                    if (j - 1 >= 0 && mat[i][j - 1] == 1)
                         coverage++;

                    // Right
                    if (j + 1 < m && mat[i][j + 1] == 1)
                         coverage++;

                    totalCoverage += coverage;
               }
          }
     }
     return totalCoverage; 
}

int main()
{
     //vector<vector<int>> v{{1, 0}, {0, 1}};
     //vector<vector<int>> v{{1, 0}, {0, 1}, {1, 0}};
     vector<vector<int>> v{{0, 0, 0}, {0, 0, 0}};
     cout << "Result:- " << coverageOfMatrix(v) << endl;


     return 0;
}
