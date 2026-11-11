/*
   Print all perfect numbers between 1 and N
   A perfect number = sum of its proper divisors (e.g. 6 = 1+2+3)
   Asked at: Wipro, Zoho, Capgemini
 */
#include <iostream>
using namespace std;
bool isPerfectNum(int n)
{
     int sum = 0;
     for(int i=1;i<n;i++)
     {
          if(n%i == 0)
          {
               sum += i;
          }
     }
     if(n == sum)
          return true;
     return false;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "Perfect Numbers:- ";
     for(int i=1;i<=n;i++)
     {
          if(isPerfectNum(i))
               cout << i << " ";
     }
     cout << endl;
     return 0;
}
