/*
   Check if a number is a palindrome (without converting to string)
   Asked at: Zoho, Infosys, Amazon
 */
#include <iostream>
using namespace std;
bool checkPalindrome(int n)
{
     int temp = n;
     int rev = 0;
     while(temp > 0)
     {
          int d = temp%10;
          rev = rev*10 + d;
          temp /= 10;
     }
     if(n == rev)   return true;
     return false;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     bool res = checkPalindrome(n);
     if(res)
          cout << "Number is Palindrome.\n";
     else
          cout << "Number is not a Palindrome.\n";
     return 0;
}
