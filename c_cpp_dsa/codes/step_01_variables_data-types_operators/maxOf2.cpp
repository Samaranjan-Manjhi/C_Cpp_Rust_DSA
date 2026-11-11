/*
   Find maximum of two numbers without using if (use ternary)
   Asked at: TCS, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     int x, y;
     cout << "Enter 2 Number: ";
     cin >> x >> y;
     int max = (x > y) ? x : y;
     cout << "Maximum Value:- " << max << endl;
     return 0;
}
