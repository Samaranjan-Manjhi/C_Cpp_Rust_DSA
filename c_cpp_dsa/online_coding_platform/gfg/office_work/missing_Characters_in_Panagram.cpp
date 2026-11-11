/*

   Missing Characters in Panagram

   Given a string s, find the missing characters required to make it a pangram (a sentence containing every letter of the English alphabet at least once).

   Return all missing characters in lowercase and in lexicographical order. If the given string is already a pangram, return -1.

Examples:

Input: s = Abcdefghijklmnopqrstuvwxy
Output: z
Explanation: All alphabets except "z" are present in the string.

Input: s = Abc
Output: defghijklmnopqrstuvwxyz

Constraints:
1 <= |s| <= 10^4

 */

#include <iostream>
#include <string>

using namespace std;

string missingPanagram(string &s) 
{
     // code here
     int arr[26] = {0};
     for(char c : s)
     {
          if(c >= 'A' && c <= 'Z')
          {
               c = c + 32;
               arr[c-'a']++;
          }
          else
          {
               arr[c-'a']++;
          }
     }

     string res = "";
     for(int i=0;i<26;i++)
     {
          if(arr[i] == 0)
               res += (char)('a' +i);
     }

     if(res == "")
          return "-1";

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     string res = missingPanagram(s);
     cout << "     Result:- " << res << endl;

     return 0;
}
