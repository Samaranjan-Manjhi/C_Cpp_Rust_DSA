/*
   Find the smallest divisor of N greater than 1
   (can be used as the basis of a prime check)
   Asked at: TCS, Infosys
 */
#include <iostream>
using namespace std;
bool isPrime(int n)
{
     if(n <= 1)     return false;
     if(n == 2)     return true;
     if(n%2 == 0)   return false;
     for(int i=3;i<n;i++)
     {
          if(n%i == 0)
               return false;
     }
     return true;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n; 
     int cnt = 0;
     if(n <= 1)
     {
          cout << "No divisor greater than 1." << endl;
          return 0;
     }
     for(int i=2;i<=n;i++)
     {
          //if(n%i == 0 && isPrime(i))
          if(n%i == 0)
          {
               //cnt++;
               //if(cnt == 1)
               cout << "Result:- " << i << endl;
               break;
          }
     }
     return 0;
}
