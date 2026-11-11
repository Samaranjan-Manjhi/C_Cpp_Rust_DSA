/*
   Check if a string is palindrome using recursion
   Asked at: Amazon, Zoho
 */
#include <iostream>
#include <string.h>
using namespace std;
bool check_Palindrome(string& s, int start, int end)
{
     if(start >= end)
          return true;
     if(s[start] != s[end])
          return false;
     return check_Palindrome(s, start+1, end-1);
}
int main()
{
     string str;
     cout << "Enter String: ";
     getline(cin, str);
     cout << "Result: " << (check_Palindrome(str, 0, str.length()-1) ? "Yes" : "No") << endl;
     return 0;
}
