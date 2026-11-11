/*

   Palindrome String

   Given a string s, return true if the string is a palindrome. Otherwise, return false.

   A string is considered a palindrome if it reads the same forwards and backwards.

Examples :

Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.

Input: s = "abc" 
Output: false
Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.

Constraints:
1 ≤ s.size() ≤ 106
The string s contains only lowercase english letters (a-z).

 */


#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string& s) 
{
     // code here
     int l = 0, r = s.length()-1;
     while(l < r)
     {
          if(s[l] != s[r])
               return false;

          l++;
          r--;
     }

     return true;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     bool res = isPalindrome(s);
     cout << "     Result:- ";
     if(res)
          cout << "  Yes\n";
     else
          cout << "  Nope\n";

     return 0;
}
