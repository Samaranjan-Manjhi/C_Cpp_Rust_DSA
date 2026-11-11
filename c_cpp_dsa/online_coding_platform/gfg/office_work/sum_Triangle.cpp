/*

Sum Triangle

Given an array arr[], construct its Sum Triangle as follows:

    The bottom row of the triangle is the original array.
    Each element in the row above is formed by adding the two adjacent elements directly below it.
    Continue this process until only one element remains at the top of the triangle.

Return all elements of the Sum Triangle in top-to-bottom order, and within each row from left to right.

Examples:

Input: arr[] = [4, 7, 3, 6, 7]
Output: [81, 40, 41, 21, 19, 22, 11, 10, 9, 13, 4, 7, 3, 6, 7]
Explanation:
       81
     40  41
   21  19  22
 11  10   9   13
4   7   3   6    7
The triangle is constructed from bottom to top by summing adjacent elements:
[4, 7, 3, 6, 7]
[11, 10, 9, 13]
[21, 19, 22]
[40, 41]
[81]
Reading the triangle from top to bottom and left to right gives: [81, 40, 41, 21, 19, 22, 11, 10, 9, 13, 4, 7, 3, 6, 7]

Input: arr[] = [1, 2, 4]
Output: [9, 3, 6, 1, 2, 4] 
Explanation:
   9
 3   6
1  2  4
Reading the triangle from top to bottom and left to right gives: [9, 3, 6, 1, 2, 4] 

Constraints:
1 ≤ arr.size() ≤ 25
1 ≤ arr[i] ≤ 100

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getTriangle(vector<int>& arr) 
{
     // code here
     vector<vector<int>> allRows;
     vector<int> currRow(arr.begin(), arr.end());
     allRows.push_back(currRow);
     // build triangle
     while(currRow.size() > 1)
     {
          vector<int> temp;
          for(int i = 0; i < currRow.size() - 1; i++)
          {
               temp.push_back(currRow[i] + currRow[i + 1]);
          }
          currRow = temp;
          allRows.push_back(currRow);
     }
     // reverse rows (top to bottom order required)
     reverse(allRows.begin(), allRows.end());
     // flatten result
     vector<int> res;
     for(auto &row : allRows)
     {
          for(int val : row)
          {
               res.push_back(val);
          }
     }
     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = getTriangle(v);
     for(int x : res)
          cout << x << " ";
     cout << endl;

     return 0;
}
