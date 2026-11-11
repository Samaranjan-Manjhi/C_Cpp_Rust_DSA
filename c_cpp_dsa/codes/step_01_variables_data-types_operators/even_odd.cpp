/*
   Check if a number is even or odd without using %
Hint: use bitwise AND: n & 1
Asked at: TCS, Wipro, Cognizant
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter number: ";
     cin >> n;
     if((n&1) != 0)
          cout << "Number is Odd.\n";
     else
          cout << "Number is Even.\n";
     return 0;
}
