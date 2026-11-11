/*

   Check if a string is a palindrome.
   O(N) two-pointer approach. Also handle ignoring non-alphanumeric.
   Asked at: TCS, Wipro, Amazon, Zoho

 */

#include <iostream>
#include <string.h>

using namespace std;

bool isAlphaNum(char c)
{
     return (c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9');
}

char toLowerChar(char c)
{
     if(c >= 'A' && c <= 'Z')
          return c+32;
     return c;
}

bool check_palindrome(string& s)
{
     int l = 0;
     int r = s.length()-1;
     while(l < r)
     {
          while(l < r && !isAlphaNum(s[l]))
               l++;
          while(l < r && !isAlphaNum(s[r]))
               r--;
          if(toLowerChar(s[l]) != toLowerChar(s[r]))
               return false;
          l++;
          r--;
     }
     return true;
}

int main()
{
     string str;
     cout << "Enter String to check palindrome: ";
     getline(cin, str);

     bool res = check_palindrome(str);
     if(res == 1)
          cout << "Result:--> " << str << " is palindrome." << endl;
     else
          cout << "Result:--> " << str << " is not palindrome." << endl;

     return 0;
}
