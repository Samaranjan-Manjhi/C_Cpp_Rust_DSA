/*
   Reverse the digits of a number (e.g. 1234 -> 4321)
   Asked at: TCS, Wipro, Capgemini
 */
#include <iostream>
using namespace std;
int reverseNumber(int n)
{
     int rev = 0;
     while(n > 0)
     {
          int d = n%10;
          rev = rev*10+d;
          n /= 10;
     }
     return rev;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int res = reverseNumber(n);
     cout << "Number after reverse:- " << res << endl;
     return 0;
}
