/*
   Find all prime numbers up to N — Sieve of Eratosthenes
   Asked at: Amazon, Microsoft, Google
 */
#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes - Find all primes up to n
vector<int> sieveOfEratosthenes(int n) 
{
     // Create a boolean array and initialize all as true
     vector<bool> isPrime(n + 1, true);
     isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
     // Start from 2, mark all multiples as non-prime
     for (int i = 2; i * i <= n; i++) 
     {
          if (isPrime[i]) 
          {
               // Mark all multiples of i as non-prime
               for (int j = i * i; j <= n; j += i) 
               {
                    isPrime[j] = false;
               }
          }
     }
     // Collect all prime numbers
     vector<int> primes;
     for (int i = 2; i <= n; i++) 
     {
          if (isPrime[i]) 
          {
               primes.push_back(i);
          }
     }
     return primes;
}

int main(int argc, char** argv) 
{
     int n;
     if(argc > 1)
          n = atoi(argv[1]);
     else
          n = 500;
     vector<int> primes = sieveOfEratosthenes(n);

     cout << "Prime numbers up to " << n << ":" << endl;
     for (int prime : primes) 
     {
          cout << prime << " ";
     }
     cout << endl;

     return 0;
}
