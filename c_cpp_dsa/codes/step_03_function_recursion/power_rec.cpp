/*
   Power(x, n) using recursion — x^n = x * pow(x, n-1)
   Asked at: Amazon, Microsoft
 */
#include <iostream>
#include <cmath>
using namespace std;
int power(int x, int n)
{
     if(x == 0 || n == 0)
          return 1;
     return x*power(x, n-1);
}
int main()
{
     int x, n;
     cout << "Enter Nummbers: ";
     cin >> x >> n;
     cout << "Result: " << power(x, n) << endl;
     return 0;
}
