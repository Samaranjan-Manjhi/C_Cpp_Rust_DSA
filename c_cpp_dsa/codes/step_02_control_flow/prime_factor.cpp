/*
   Print all prime factors of a number
   Asked at: Amazon, Flipkart
 */
#include <iostream>
using namespace std;

bool isPrime(int n)
{
     if(n<=1) return false;
     if(n==2) return true;
     if(n%2==0) return false;
     for(int i=3;i*i<=n;i++)
     {
          if(n%i==0)
               return false;
     }
     return true;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     for(int i=2;i<=n;i++)
     {
          if(n%i==0)
          {
               if(isPrime(i))
                    cout << i << " ";
          }
     }
     cout << endl;
     return 0;
}
