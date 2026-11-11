/*
   Check if a number is a power of 2
Hint: n > 0 && (n & (n-1)) == 0
Asked at: Amazon, Adobe
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n > 0 && (n & (n-1)) == 0)
          cout << "Number is a power of 2.\n";
     else
          cout << "Number is not a power of 2.\n";
     return 0;
}
