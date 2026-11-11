/*
   Find all prime numbers up to N using nested loops (brute force first)
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) 
{
     if (n <= 1) return false;
     if (n == 2) return true;
     if (n % 2 == 0) return false;
     for (int i = 3; i <= sqrt(n); i += 2) 
     {
          if (n % i == 0)
               return false;
     }
     return true;
}

int main()
{
     int n;
     cout << "Enter a number: ";
     cin >> n;
     cout << "Prime Numbers are: "; 
     for(int i=0;i<=n;i++) 
     {
          if(isPrime(i))
               cout << i << " ";
     }
     cout << endl;
     return 0;
}
