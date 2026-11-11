/*
   Given 3 bits x, y, z, compute the majority bit (1 if at least 2 are 1).
Hint: (x & y) | (y & z) | (x & z) // OR (x+y+z) >= 2 ? 1 : 0
Asked at: Dolat Capital, competitive programming
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b, c;
     cout << "Enter 3 bits(0 / 1): ";
     cin >> a >> b >> c;
     int cnt = (a & b) | (b & c) | (c & a);
     cout << "Result:- " << cnt << endl;
     return 0;
}
