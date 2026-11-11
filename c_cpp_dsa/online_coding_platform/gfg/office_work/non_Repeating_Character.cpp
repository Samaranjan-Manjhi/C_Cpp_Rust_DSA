/*

   Non Repeating Character

   Given a string s consisting of lowercase English Letters. return the first non-repeating character in s. If there is no non-repeating character, return '$'.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.

Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.

Input: s = "aabbccc"
Output: '$'
Explanation: All the characters in the given string are repeating.

Constraints:
1 ≤ s.size() ≤ 105

 */


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char nonRepeatingChar(string &s) 
{
     //  code here
     /*
        unordered_map<char, int> mp;
        for(char c : s)
        {
        mp[c]++;
        }

        for(char c : s)
        {
        if(mp[c] == 1)
        {
        return c;
        }
        }
      */

     int freq[26] = {0};
     for(char c : s)
     {
          freq[c-'a']++;
     }
     for(char c : s)
     {
          if(freq[c-'a'] == 1)
               return c;
     }

     return '$';
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     char res = nonRepeatingChar(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
