/*
   Check if two floats are equal up to 6 decimal places.
Use: fabs(a - b) < 1e-6
Asked at: Zoho, Dolat Capital
 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
     float a, b;
     cout << "Enter 2 float Numbers: ";
     cin >> a >> b;
     bool res = fabs(a - b) < 1e-6;
     if(res)
          cout << "Both float Number equal up to 6 decimal.\n";
     else
          cout << "Both float Number not equal up to 6 decimal.\n";
     return 0;
}
