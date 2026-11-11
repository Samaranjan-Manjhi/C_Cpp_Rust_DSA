/*
   Find all numbers between 1 and N that are both prime AND palindrome
   Asked at: Wipro, Infosys
 */
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
     if(n <= 1)     return false;
     if(n == 2)     return true;
     if(n%2 == 0)   return false;
     for(int i=3;i<=sqrt(n);i++)
     {
          if(n%i == 0)
               return false;
     }
     return true;
}
bool isPalindrome(int n)
{
     int temp = n;
     int rev = 0;
     while(temp > 0)
     {
          int d = temp%10;
          rev = rev*10+d;
          temp /= 10;
     }
     if(rev == n)
          return true;
     return false;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "Number prime & palindrome:- ";
     for(int i=1;i<=n;i++)
     {
          if(isPrime(i) && isPalindrome(i))
          {
               cout << i << " ";
          }
     }
     cout << endl;
     return 0;
}
