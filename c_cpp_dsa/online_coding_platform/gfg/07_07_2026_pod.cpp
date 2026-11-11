/*

   Largest Unblocked Submatrix

   Given two integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell (1-based indexing) in an n × m grid. Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area in the grid.

Note: No two blocked cells are in the same row or the same column.

Examples:

Input: n = 5, m = 5, arr[][] = [[2, 3], [5, 1]]
Output: 4

Explanation:
- Blocked cells (2, 3) and (5, 1) block rows 2, 5 and columns 1, 3.
- The longest unblocked row segment has length 2 (rows 3–4).
- The longest unblocked column segment has length 2 (columns 4–5).
- Therefore, the largest unblocked rectangle has area 2 × 2 = 4.

Input: n = 2, m = 2, arr[][] = [[2, 2]]
Output: 1
Explanation: Since only (1,1) cell is free from the enemy hence answer is 1.

Constraints:
1 ≤ n, m ≤ 10^4
0 ≤ k ≤ min(n, m)
1 ≤ r ≤ n
1 ≤ c ≤ m

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestArea(int n, int m, vector<vector<int>> &arr) 
{
     // code here
     vector<int> blockedRow, blockedCol;
     int k = arr.size();
     for(int i=0;i<k;i++)
     {
          blockedRow.push_back(arr[i][0]);
          blockedCol.push_back(arr[i][1]);
     }

     sort(blockedRow.begin(), blockedRow.end());
     sort(blockedCol.begin(), blockedCol.end());

     blockedRow.insert(blockedRow.begin(), 0);
     blockedRow.push_back(n+1);

     blockedCol.insert(blockedCol.begin(), 0);
     blockedCol.push_back(m+1);

     int maxRow = 0;
     for(int i=1;i<blockedRow.size();i++)
     {
          int gap = blockedRow[i] - blockedRow[i-1] - 1;
          maxRow = max(maxRow, gap);
     }

     int maxCol = 0;
     for(int i=1;i<blockedCol.size();i++)
     {
          int gap = blockedCol[i] - blockedCol[i-1] - 1;
          maxCol = max(maxCol, gap);
     }

     return maxCol * maxRow;
}

int main()
{
     int n;
     cout << "Enter No. of Rows Matrix: ";
     cin >> n;

     int m;
     cout << "Enter No. of Columns Matrix: ";
     cin >> m;

     int k;
     cout << "Enter No. of Rows of Blocked Cell: ";
     cin >> k;

     vector<vector<int>> vec(k, vector<int>(2));
     for(int i=0;i<k;i++)
     {
          cin >> vec[i][0] >> vec[i][1];
     }

     int res = largestArea(n, m, vec);
     cout << "    Result:- " << res << endl;

     return 0;
}
