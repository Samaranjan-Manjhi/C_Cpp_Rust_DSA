/*

   Given an integer n, determine whether its binary representation forms a palindrome. Return true if the binary representation of n is a palindrome; otherwise, return false.
Note: A binary representation is considered a palindrome if it reads the same forward and backward.

Examples:
Input: n = 17
Output: true
Explanation: Binary representation of 17 is (10001)2, which reads the same forward and backward, so it is a palindrome. 

Input: n = 16
Output: false
Explanation: Binary representation of 16 is (10000)2, which is not a palindrome. 

Constraints:
1 ≤ n ≤ 109

Company Tags
Amazon    Microsoft     Adobe

 */

#include <iostream>
#include <cstring>
using namespace std;

bool isBinaryPalindrome(int n) 
{
     // code here
     string str = "";
     while(n > 0)
     {
          int d = n % 2;
          str += (char) (d + '0');
          n /= 2;
     }   
     int l = 0, r  = str.length() - 1;
     while(l <= r)
     {
          if(str[l] != str[r])
               return false;
          l++;
          r--;
     }
     return true;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;

     bool res = isBinaryPalindrome(n);
     cout << "Result:- " << res << endl;

     return 0;
}
