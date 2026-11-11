/*

   Front-Back Transformation of String

   Given a string s consisting only of English alphabets, transform each character by replacing it with the character present at the corresponding position in the reversed English alphabet. Thus, 'a' becomes 'z', 'b' becomes 'y', 'c' becomes 'x', and similarly 'z' becomes 'a'. Uppercase letters are also transformed in the same way while preserving their case. Return the resulting transformed string.

Examples:

Input: s = "Hello"
Output: Svool
Explanation: 'H' is replaced by 'S', 'e' by 'v', 'l' by 'o', and 'o' by 'l'. Therefore, the transformed string becomes "Svool".

Input: s = "GfG"
Output: TuT
Explanation:'G' is replaced by 'T' and 'f' is replaced by 'u'. Hence, the resulting string is "TuT".

Constraints:
1 <= |s| <= 10^5

 */

#include <iostream>

using namespace std;

string transformString(string &s) 
{
     // code here
     string res = "";
     for(char c : s)
     {
          if(c >= 'a' && c <= 'z')
               res += 'z' - (c - 'a');
          if(c >= 'A' && c <= 'Z')
               res += 'Z' - (c - 'A');
     }

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     string res = transformString(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
