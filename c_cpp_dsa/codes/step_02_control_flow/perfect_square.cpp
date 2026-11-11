/*
   Check if N is a perfect square without using sqrt() — use loop only
   Asked at: Amazon, TCS, Wipro
 */
#include <iostream>
using namespace std;
bool isPerfSquare(int n)
{
     if(n < 0)     return false;
     if(n == 0 || n == 1)     return true;
     for(long long i=1;i*i<=n;i++)
     {
          if(i*i == n)
               return true;
     }
     return false;
}
// Binary Search for faster
bool isPerfSquare_fast(int n)
{    
     if(n < 0)     return false;
     long long l = 0, h = n;
     while(l <= h)
     {
          long long m = l + (h-l)/2;
          long long sq = m*m;
          if(sq == n)
               return true;
          else if(sq < n)
               l = m+1;
          else
               h = m-1;
     }
     return false;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     //if(isPerfSquare(n))
     if(isPerfSquare_fast(n))
          cout << n << " is Perfect Square Number." << endl;
     else
          cout << n << " is not a Perfect Square Number." << endl;
     return 0;
}
