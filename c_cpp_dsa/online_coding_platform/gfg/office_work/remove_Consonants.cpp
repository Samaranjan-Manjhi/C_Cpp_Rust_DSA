/*

   Remove Consonants

   Given a string s, remove all consonants and return the modified string containing only vowels.

   If the string does not contain any vowels, return an empty string.

Examples:

Input: s = "abEkipo"
Output: "aEio"
Explanation: a, E, i, o are only vowels in the string.

Input: s = "rrty"
Output: ""
Explanation: There are no vowels.

Constraints
1 ≤ n ≤ 10^5, n is length of the string
The string should consist of only alphabets.

 */


#include <iostream>
#include <string>

using namespace std;

string remConsonants(string &s) 
{
     // code here
     string ans = "";
     for(char ch : s)
     {
          if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
               ans += ch;
     }

     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     string res = remConsonants(str);
     cout << "      Result:- " << res << endl; 

     return 0;
}
