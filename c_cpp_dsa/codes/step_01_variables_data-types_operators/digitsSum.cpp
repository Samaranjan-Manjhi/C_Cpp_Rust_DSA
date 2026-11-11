/*
   Find the sum of all digits of a number without using strings
   e.g. 4567 -> 4+5+6+7 = 22
   Asked at: TCS, Wipro, Capgemini
 */
#include <iostream>
using namespace std;

int digit_sum(int n)
{
     int sum = 0;
     while(n > 0)
     {
          int d = n%10;
          sum += d;
          n /= 10;
     }
     return sum;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int res = digit_sum(n);
     cout << "Sum of all digits of a Number:- " << res << endl;
     return 0;
}
