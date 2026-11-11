/*
   Given two integers, check if exactly one of them is negative
Hint: use XOR on sign bits — (a < 0) ^ (b < 0)
Asked at: Dolat Capital, Samsung
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b;
     cout << "Enter 2 Numbers: ";
     cin >> a >> b;
     if((a < 0) ^ (b < 0))
          cout << "Only one is Negative.\n";
     else
          cout << "Both negative or Both positive.\n";
     return 0;
}
