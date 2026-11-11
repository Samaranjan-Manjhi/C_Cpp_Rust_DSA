/*
   Print all numbers from 1 to N that are perfect squares
   Without using sqrt() — use only loops
   Asked at: TCS, Wipro, Capgemini
 */
#include <iostream>
using namespace std;
bool isPerfectSquareNum(int n)
{
     if(n <= 0)
          return false;
     int l = 0, r = n;
     while(l <= r)
     {
          int mid = l+(r-l)/2;
          long long int sq = mid*mid;
          if(sq == n)
               return true;
          else if(sq < n)
               l = mid+1;
          else
               r = mid-1;
     }
     return false;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     for(int i=1;i<=n;i++)
     {
          if(isPerfectSquareNum(i))
               cout << i << " ";
     }
     cout << endl;
     return 0;
}
