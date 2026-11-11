/*
   Read two numbers, print their sum, difference, product, quotient
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     int x, y;
     cout << "Enter 2 Numbers: ";
     cin >> x >> y;
     cout << "Sum:- " << (x+y) << endl;
     cout << "Difference:- " << abs(x-y) << endl;
     cout << "Product:- " << x*y << endl;
     cout << "Quotient:- " << x/y << endl;
     return 0;
}
