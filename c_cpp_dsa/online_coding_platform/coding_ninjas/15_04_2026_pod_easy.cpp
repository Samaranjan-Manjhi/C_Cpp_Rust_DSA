/*
   Problem statement

   You are given an N x M integer matrix. Your task is to modify this matrix in place so that if any cell contains the value 0, then all cells in the same row and column as that cell should also be set to 0.

Requirements:

If a cell in the matrix has the value 0, set all other cells in that cell's row and column to 0.
You should perform this modification in place (without using additional matrices).

You must do it in place.

For Example:

If the given grid is this:
[7, 19, 3]
[4, 21, 0]

Then the modified grid will be:
[7, 19, 0]
[0, 0,  0]

 */
#include <iostream>
#include <vector>
using namespace std;

void makeZero(vector<vector<int>>& matrix, int row, int col)
{
     int n = matrix.size();
     int m = matrix[0].size();
     bool frstRow = false,  frstCol = false;
     // For column
     for(int i=0;i<n;i++)
     {
          if(matrix[i][0] == 0) 
               frstCol = true;
     }
     // For Row
     for(int i=0;i<m;i++)
     {
          if(matrix[0][i] == 0)
               frstRow = true;
     }

     for(int i=1;i<n;i++)
     {
          for(int j=1;j<m;j++)
          {
               if(matrix[i][j] == 0)
               {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
               }
          }
     }

     for(int i=1;i<n;i++)
     {
          for(int j=1;j<m;j++)
          {
               if(matrix[i][0] == 0 || matrix[0][j] == 0)
               {
                    matrix[i][j] = 0;
               }
          }
     }

     if(frstCol)
     {
          for(int i=0;i<n;i++)
          {
               matrix[i][0] = 0;
          }
     }

     if(frstRow)
     {
          for(int i=0;i<m;i++)
          {
               matrix[0][i] = 0;
          }
     }
}

int main()
{
     int n, m;
     cout << "Enter Number: ";
     cin >> n >> m;
     int val;
     vector<vector<int>> res;
     for(int i=0;i<n;i++)
     {
          vector<int> temp;
          for(int j=0;j<m;j++)
          {
               cin >> val;
               temp.push_back(val);
          }
          res.push_back(temp);
     }

     cout << "Matrix Value: \n";
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               cout << res[i][j] << " ";
          }
          cout << endl;
     }


     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               if(res[i][j] == 0)
               {
                    cout << i << "   " << j << endl; 
                    makeZero(res, 0, 0);
               }
          }
          cout << endl;
     }


     cout << "Matrix Output: \n";
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {    
               cout << res[i][j] << " ";
          }
          cout << endl;
     }

     return 0;
}
