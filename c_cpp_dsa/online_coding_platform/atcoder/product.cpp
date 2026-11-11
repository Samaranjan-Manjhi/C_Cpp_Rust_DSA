/*
   ABC086A - Product /

   Time Limit: 2 sec / Memory Limit: 256 MiB

Score :

100 points
Problem Statement

AtCoDeer the deer found two positive integers,
a and b. Determine whether the product of a and

b is even or odd.
Constraints

1 ≤ a,b ≤
10000
a and b are integers.
 */

#include <iostream>
using namespace std;
int main()
{
     int a, b;
     cin >> a >> b;
     cout << ((a*b)%2 == 0 ? "Even" : "Odd") << endl;

     return 0;
}
