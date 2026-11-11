/*
   Check if a number is even or odd using %
   Asked at: TCS, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n%2 == 0)
          cout << "Number is Even.\n";
     else
          cout << "Number is Odd.\n";
     return 0;
}
