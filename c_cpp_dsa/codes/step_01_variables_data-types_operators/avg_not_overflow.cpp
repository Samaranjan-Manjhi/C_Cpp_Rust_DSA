/*
   Read two integers a and b. Print their average WITHOUT overflow.
Hint: a/2 + b/2 + (a%2 + b%2)/2 --> Only +ve  (a & b) + ((a ^ b) >> 1) --> +ve/-ve
Asked at: Amazon, Google
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b;
     cout << "Enter 2 Numbers: ";
     cin >> a >> b;
     cout << "Average of 2 Numbers:- " << (a/2 + b/2 +(a%2 + b%2)/2) << endl;
     return 0;
}
