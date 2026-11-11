/*
   Check if a number is divisible by both 3 and 7 simultaneously
   Asked at: TCS, Capgemini
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n%21 == 0)
          cout << "Number is divisible by 3 & 7.\n";
     else
          cout << "Number is not divisible by 3 & 7.\n";
     return 0;
}
