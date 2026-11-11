/*

   Sums of i-th row and i-th column

   Given a 2D integer array mat[][] of size n × m, check whether for every index i, the sum of the ith row is equal to the sum of the ith column. Return true if the condition holds for all valid indices, otherwise return false.

Note: If the matrix is not square (n != m), only compare indices up to min(n, m). For example, if there are 3 rows and 1 column, only compare the 1st row with the 1st column.

Examples:

Input: mat[][] = [[1, 2], [2, 1]]
Output: true
Explanation: Sum of 1st row = 1 + 2 = 3, and Sum of 1st column = 1 + 2 = 3. Similarly, Sum of 2nd row = 2 + 1 = 3, and Sum of 2nd column = 2 + 1 = 3. All corresponding row and column sums are equal.

Input: mat[][] = [[5], [0], [0]]
Output: true
Explanation: Only the first row and first column are considered. The sum of the first row is 5, and the sum of the first column is also 5. Both values are equal.

Input: mat[][] = [[1, 4, 2], [6, 1, 3]]
Output: false 
Explaination: Sum of the first row and first column are equal, but the sum of the second row is 10 which is not equal to the sum of the second column which is 5.

Constraints:
1 ≤ n, m ≤ 103   
0 ≤ mat[i][j] ≤ 103 

 */


#include <iostream>
#include <vector>

using namespace std;

bool sumOfRowCol(vector<vector<int>> &mat) 
{
     // code here
     int n = mat.size();
     int m = mat[0].size();
     int mini = min(n, m);

     for (int i = 0; i<mini; i++)
     {
          int rowSum = 0;
          int colSum = 0;
          for (int j = 0; j < m; j++)
          {
               rowSum += mat[i][j];
          }
          for (int j = 0; j < n; j++)
          {
               colSum += mat[j][i];
          }

          if (rowSum != colSum)
               return false;
     }

     return 1; 
}

int main()
{
     int n, m;
     cout << "Enter Matrix Size: ";
     cin >> n >> m;

     vector<vector<int>> v(n, vector<int>(m));
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               cin >> v[i][j];
          }
     }

     int res = sumOfRowCol(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
