/*
   Without using multiplication, divide or mod, check if n is divisible by 4
Hint: (n & 3) == 0
Asked at: Google
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if((n & 3) == 0)
          cout << "Number is divisible by 4.\n";
     else
          cout << "Number is nit divisible by 4.\n";
     return 0;
}
