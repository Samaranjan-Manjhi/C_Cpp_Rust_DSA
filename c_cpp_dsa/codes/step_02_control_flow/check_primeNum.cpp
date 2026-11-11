/*
   Check if a number is prime
   Asked at: TCS, Zoho, Capgemini, Wipro
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
     int n;
     cout << "Enter a Number: ";
     cin >> n;

     if(n <= 1) 
     {
          cout << n << " is not a prime number.\n";
          return 0;
     }
     if(n == 2) 
     {
          cout << "2 is the only even prime number.\n";
          return 0;
     }
     if(n % 2 == 0) 
     {
          cout << n << " is not a prime number.\n";
          return 0;
     }

     bool isPrime = true;
     for(int i = 3; i <= sqrt(n); i += 2) 
     {
          if(n % i == 0) 
          {
               isPrime = false;
               break;
          }
     }
     if(isPrime)
          cout << n << " is a prime number.\n";
     else
          cout << n << " is not a prime number.\n";
     return 0;
}
