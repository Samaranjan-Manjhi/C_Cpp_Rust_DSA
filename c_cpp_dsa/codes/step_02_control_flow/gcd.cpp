/*
   Find GCD of two numbers using Euclidean algorithm (loop version)
   Asked at: Amazon, Microsoft, Zoho
 */
#include <iostream>
using namespace std;
int main()
{
     int n, m;
     cout << "Enter Numbers: ";
     cin >> n >> m;
     int gcd;
     for(int i=1;i<=n && i<=m;i++)
     {
          if(n%i == 0 && m%i == 0)
               gcd = i;
     }
     cout << "GCD:- " << gcd << endl;
     return 0;
}
