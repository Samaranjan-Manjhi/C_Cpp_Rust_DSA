/*
   Sum of digits of a number using recursion
   e.g. 1234 -> 1+2+3+4 = 10
   Asked at: Wipro, Cognizant
 */
#include <iostream>
using namespace std;
int sumOfDigit(int n)
{
     if(n == 0)     return 0; 
     return (n%10) + sumOfDigit(n/10);
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "Result: " << sumOfDigit(n) << endl;
     return 0;
}
