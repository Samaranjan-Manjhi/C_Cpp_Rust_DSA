/*
   Check if a year is a leap year
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if((n%400) == 0 || ((n%4) == 0 && (n%100) != 0))
          cout << "Year is leap year.\n";
     else
          cout << "Year is not leap year.\n";
     return 0;
}
