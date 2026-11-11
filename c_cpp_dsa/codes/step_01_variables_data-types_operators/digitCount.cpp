/*
   Find the number of digits in an integer
   Asked at: TCS, Infosys
 */
#include <iostream>
using namespace std;

int digitCount(int n)
{
     int cnt = 0;
     while(n > 0)
     {
          int d = n%10;
          cnt++;
          n /= 10;
     }
     return cnt;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int res = digitCount(n);
     cout << "Count of Digits in Number:- " << res << endl;
     return 0;
}
