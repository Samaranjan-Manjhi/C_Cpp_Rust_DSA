/*
   Problem statement

   You have an integer array ‘A’ of the form of [x, x+1, x+2, x+3, …….]. As the array is vast in size, you are given both endpoints of the array, i.e., If you are given two integers, ‘L’ and ‘R’, the array ‘A’ will be [L, L+1, L+2, ……., R-1, R]. Your task is to find the maximum possible value of ‘X’ such that the following two conditions hold.

   a ⊕ b = X, where ⊕ denotes bitwise xor operation.
   Both numbers ‘a’ and ‘b’ belong to the array ‘A’.
 */
#include <iostream>
using namespace std;
int maxXor(int L, int R)
{
     // Write your code here.
     //Optimize
     int res = 0;
     int m = L^R;
     while(m > 0)
     {
          res = (res << 1) | 1;
          m >>= 1;
     }
     return res;
}

int main()
{
     int n, m;
     cout << "Enter Range: " ;
     cin >> n >> m;
     int res = 0;
     for(int i=n;i<=m-1;i++)
     {
          for(int j=i+1;j<=m;j++)
          {
               int temp = i^j;
               if(res < temp)
                    res = temp;
          }
     }
     cout << "Result:- " << res << endl;
     return 0;
}
