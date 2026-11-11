/*
   Find the largest of three numbers using if-else
   Asked at: TCS, Wipro, Infosys, Capgemini
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b, c;
     cout << "Enter 3 Numbers: ";
     cin >> a >> b >> c;
     if(a > b && a > c)
          cout << a << " is largest Value.\n";
     else if(b > a && b > c)
          cout << b << " is largest Value.\n";
     else
          cout << c << " is largest Value.\n";
     return 0;
}
