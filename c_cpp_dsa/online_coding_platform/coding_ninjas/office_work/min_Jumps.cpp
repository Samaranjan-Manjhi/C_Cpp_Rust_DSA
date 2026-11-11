/*

Min Jumps

 Problem statement

You live in a Ninja town which is in the form of a N * M grid. In this town, people travel from one place to another by jumping over the buildings which are present in each cell of the grid. It is Christmas eve, and Santa wants to give gifts and chocolates to the kids who live in the building which is present at the cell (N - 1, M - 1). Initially, Santa is present on cell (0, 0). Since Santa is in a hurry, help him find a path from starting point to the endpoint with the least amount of time.

The Santa may go only from one building to any of its adjacent buildings which is present either to the right or to the bottom or bottom right cell i.e. if the current position is (x, y), he may go to (x + 1, y + 1) or (x + 1, y) or (x, y + 1) given that the new coordinates are in the grid. The time taken to reach from one building to another is equal to the absolute difference between the heights of buildings.

Note:
1. The heights of the buildings are positive.
2. Santa starts from the cell (0, 0) and he has to reach the building (N - 1, M - 1).
3. Santa cannot leave the grid at any point of time.

Constraints:
1 <= T <= 10^2
1 <= N <= 10^2
1 <= M <= 10^2
1 <= Height <= 10^5
Time Limit: 1sec

Sample Input 1:
2
3 3
1 2 3
4 5 6
7 8 9
2 2
1 2
3 4
Sample Output 1:
8
3

Explanation For Sample Input 1:
For test case 1:
One of the possible ways is to go from (0, 0) to (1, 1) to (2, 2). 
So the total cost will be abs(1 - 5) + abs(5 - 9) = 8. 

For test case 2:
Optimal was to go from (0,0) to (1,1) is (0,0) --> (1,1) with the 
cost abs(1-4) = 3. 

Sample Input 2:
2
2 2
4 5
3 4
3 3
2 3 4
2 4 5
2 4 4
Sample Output 2:
0
2

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinCost(vector<vector<int>> arr, int n, int m) 
{
     // Write your code here.
     vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

     dp[0][0] = 0;

     for (int i = 0; i < n; i++) 
     {
          for (int j = 0; j < m; j++) 
          {

               // Move from top
               if (i > 0) 
               {
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + abs(arr[i][j] - arr[i-1][j]));
               }

               // Move from left
               if (j > 0) 
               {
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + abs(arr[i][j] - arr[i][j-1]));
               }

               // Move from diagonal
               if (i > 0 && j > 0) 
               {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(arr[i][j] - arr[i-1][j-1]));
               }
          }
     }

     return dp[n-1][m-1];
}

int main()
{
     int n;
     cout << "Enter No. of Rows: ";
     cin >> n;

     int m;
     cout << "Enter No. of Columns: ";
     cin >> m;

     vector<vector<int>> v(n, vector<int>(m));
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               cin >> v[i][j];
          }
     }

     int res = findMinCost(v, n, m);
     cout << "    Result:- " << res << endl;

     return 0;
}
