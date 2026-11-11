/*
   Write a recursive function to compute sum of first N odd numbers
   Asked at: TCS, Wipro
 */

#include <iostream>
using namespace std;

int sumOdd(int i, int n)
{
     if(i > n)
          return 0;
     return i + sumOdd(i+2, n);
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "Sum:- " << sumOdd(1, n) << endl;
     return 0;
}
