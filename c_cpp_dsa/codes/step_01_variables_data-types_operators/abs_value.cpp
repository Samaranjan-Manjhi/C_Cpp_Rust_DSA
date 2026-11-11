/*
   Without any loop, find the absolute value of an integer without abs().
Use: (x < 0) ? -x : x  OR  (x ^ (x >> 31)) - (x >> 31)
Asked at: Samsung, Sasken
 */
#include <iostream>
using namespace std;
int main()
{
     int x;
     cout << "Enter a Number: ";
     cin >> x;
     cout << "Absolute Value:- " << ((x < 0) ? -(x) : x) << endl;
     return 0;
}
