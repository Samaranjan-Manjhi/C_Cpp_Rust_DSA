/*
   Fibonacci using recursion
   Asked at: TCS, Wipro, Amazon, Infosys
 */
#include <iostream>
using namespace std;
int fibbo_rec(int n)
{
     if(n <= 1)
          return n;
     return fibbo_rec(n-1) + fibbo_rec(n-2);
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     for(int i=0;i<n;i++)
     {
          cout << fibbo_rec(i) << " ";
     }
     cout << endl;
     return 0;
}
