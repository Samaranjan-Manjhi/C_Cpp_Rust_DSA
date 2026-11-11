/*
   Given an integer, find the highest power of 2 less than or equal to it
   Asked at: Samsung
   1. pow(2, (int)log2(n)); // #include <cmath>
   2. Bit trick
   int highestPowerOf2(int n) {
   n |= (n >> 1);
   n |= (n >> 2);
   n |= (n >> 4);
   n |= (n >> 8);
   n |= (n >> 16);
   return n - (n >> 1);
   }
   3. Loop
   int p = 1;
   while (p * 2 <= n)
   p *= 2;
   return p;
 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "Highest Power of 2 equal or less:- " << pow(2, (int)log2(n)) << endl;
     return 0;
}
