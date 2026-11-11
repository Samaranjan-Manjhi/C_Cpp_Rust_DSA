/*
   Simple interest calculator: SI = (P * R * T) / 100
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     int p;
     cout << "Enter Principle Ammount: ";
     cin >> p;
     float r;
     cout << "Enter Rate of Interest: ";
     cin >> r;
     int t;
     cout << "Enter Year(s): ";
     cin >> t;
     float si = (p*r*t)/100;
     cout << "Simple Interest of P(" << p << ") at R(" << r << ") for T(" << t <<") is :- " << si << endl;
     return 0;
}
