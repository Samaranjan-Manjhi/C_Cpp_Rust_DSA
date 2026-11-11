/*
   Multiply a number by 7 using only bitwise operators and addition
Hint: x*7 = (x << 3) - x OR (n << 2) + (n << 1) + n
Asked at: Samsung, Dolat Capital
 */
#include <iostream>
using namespace std;
int main()
{
     int x;
     cout << "Enter a value: ";
     cin >> x;
     cout << "Result:- " << (x<<2)+(x<<1)+x << endl;
     return 0;
}
