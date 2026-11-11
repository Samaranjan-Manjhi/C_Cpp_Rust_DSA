/*
   Without any if/else/ternary, print 1 if a > b, -1 if a < b, 0 if equal.
Hint: (a > b) - (a < b)
Asked at: Samsung, Dolat Capital
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b;
     cout << "Enter 2 Numbers: ";
     cin >> a >> b;
     int out = (a > b) - (a < b);
     cout << "Result:- " << out << endl;
     return 0;
}
