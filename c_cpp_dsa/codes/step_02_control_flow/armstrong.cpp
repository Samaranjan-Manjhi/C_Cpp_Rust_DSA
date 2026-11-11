/*
   Check Armstrong number (e.g. 153 = 1^3 + 5^3 + 3^3)
   Asked at: TCS, Capgemini
 */
#include <iostream>
#include <cmath>
using namespace std;
int getDigitCnt(int n)
{
     int cnt = 0;
     while(n>0)
     {
          int d = n%10;
          cnt++;
          n/=10;
     }
     return cnt;
}
bool check_Armstrong(int n)
{
     int cnt = getDigitCnt(n);
     int temp = n;
     int sum = 0;
     while(temp>0)
     {
          int d = temp%10;
          sum += pow(d, cnt);
          temp/=10;
     }
     if(n == sum)
          return true;
     return false;
}
int main()
{
     int n;
     cout << "Enter a Number: ";
     cin >> n;
     for(int i=1;i<=n;i++)
     {
          bool res = check_Armstrong(i);
          if(res)
               cout << i << " ";
               //cout << n << " is Armstrong.\n";
          //else
               //cout << n << " is not Armstrong.\n";
     }
     return 0;
}
