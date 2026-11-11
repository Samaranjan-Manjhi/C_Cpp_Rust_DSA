/*
   Given a = 5, b = 3, print a/b and (float)a/b. Explain the difference.
   Expected output: 1   1.666...
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     int n, m;
     cout << "Enter 2 Numbers: ";
     cin >> n >> m;
     cout << "Value of n/m:- " << (int)n/m << endl;
     //cout << "Value of n/m:- " << (float)(n/m) << endl; // Cast before division to avoid integer truncation
     cout << "Value of n/m:- " << (float)n/m << endl;
     return 0;
}
