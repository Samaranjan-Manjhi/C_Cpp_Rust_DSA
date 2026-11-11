/*
   Factorial using recursion
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int fact_rec(int n)
{
     if(n == 0)
          return 1;
     else 
          return n*fact_rec(n-1);
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int fact = 1;
     cout << "Factorial: " << fact_rec(n) << endl;
     return 0;
}
