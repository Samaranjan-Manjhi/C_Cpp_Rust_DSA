/*

   Count Sorted Rows

   Given a matrix mat[][] of size n × m, count the number of rows that are sorted either in strictly increasing order or strictly decreasing order.

Examples:

Input: mat[][] = [[1, 2, 3], [6, 5, 4], [7, 9, 8]]
Output: 2
Explanation: The first row is sorted in strictly increasing order while the second row is sorted in strictly decreasing order.

Input: mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 3
Explanation: All the rows are sorted in strictly increasing order.

Constraints:
1 ≤ n, m, mat[i][j] ≤ 103

 */


#include <iostream>
#include <vector>

using namespace std;

int sortedCount(vector<vector<int>> &mat) 
{
     // code here
     int cnt = 0;
     for(auto& row : mat)
     {
          bool a = true, d = true;
          for(int i=0;i<row.size()-1;i++)
          {
               if(row[i] >= row[i+1])
                    a = false;
               if(row[i] <= row[i+1])
                    d = false;
          }
          if(a || d)
               cnt++;
     } 

     return cnt;
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

     int res = sortedCount(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
