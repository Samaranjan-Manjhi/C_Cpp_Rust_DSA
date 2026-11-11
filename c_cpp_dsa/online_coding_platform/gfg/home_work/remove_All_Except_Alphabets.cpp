/*

   Remove All Except Alphabets

   Given a string s, remove all characters except lowercase and uppercase alphabets (a-z and A-Z) and return the resulting string.

   If no alphabetic characters remain after removal, return an empty string.

Examples:

Input: s = "$Gee*k;s..fo, r'Ge^eks?"
Output: "GeeksforGeeks"
Explanation: All characters other than alphabets are removed from the string "$Gee*k;s..fo, r'Ge^eks?", resulting in "GeeksforGeeks". 

Input:  s = "{{{}}> *& ^%*)"
Output: ""
Explanation: The string "{{{}}> *& ^%*)" does not contain any alphabetic characters, so after removing all non-alphabet characters, the resulting string is empty.

Constraints:
1 ≤ n ≤ 105

 */


#include <iostream>
#include <string>

using namespace std;

bool isAlpha(char c)
{
     if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
          return true;
     return false;
}

string removeChars(string &s) 
{
     // code here
     string res = "";
     for(char c : s)
     {
          if(isAlpha(c))
               res += c;
     }        

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     string res = removeChars(s);
     cout << "     Result:- " << res << endl;

     return 0;
}
