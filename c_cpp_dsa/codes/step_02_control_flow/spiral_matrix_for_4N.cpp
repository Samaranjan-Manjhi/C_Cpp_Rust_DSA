/*
   Print the number spiral matrix for N=4 clockwise starting from 1
   Asked at: Amazon, Zoho
 */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
void printSpiral(int n)
{
     vector<vector<int>> mt(n, vector<int>(n));
     int val = 1;
     int left = 0, right = n-1;
     int top = 0, bottom = n-1;
     while(left <= right && top <= bottom)
     {
          for(int i=left;i<=right;i++)
          {
               mt[top][i] = val++;
          }
          top++;
          for(int i=top;i<=bottom;i++)
          {
               mt[i][right] = val++;
          }
          right--;
          if(top <= bottom)
          {
               for(int i=right;i>=left;i--)
               {
                    mt[bottom][i] = val++;
               }
               bottom--;
          }
          if(left <= right)
          {
               for(int i=bottom;i>=top;i--)
               {
                    mt[i][left] = val++;
               }
               left++;
          }
     } 
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout << setw(4) << mt[i][j];
          }
     }
     cout << endl;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     printSpiral(n);
     return 0;
}
