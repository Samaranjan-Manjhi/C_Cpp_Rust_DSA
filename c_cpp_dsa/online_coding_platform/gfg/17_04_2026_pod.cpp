/*
   Given a string s, determine whether its characters can be rearranged to form a palindrome. Return true if it is possible to rearrange the string into a palindrome; otherwise, return false.

   Examples

Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba" 

Input: s = "geeksogeeks"
Output: true
Explanation: The characters of the string can be rearranged to form the palindrome "geeksoskeeg".

Input: s = "geeksforgeeks"
Output: false
Explanation: The given string can't be converted into a palindrome.

Constraints:
1 ≤ s.length ≤ 106
s consists of only lowercase English letters.
 */
#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;
bool canFormPalindrome(string &s) 
{
     // code here
     int cnt = 0;
     unordered_map<char, int> mp;
     for(char ch:s)
     {
          mp[ch]++;
     }
     for(auto it=mp.begin();it!=mp.end();it++)
     {
          //cout << it->first << "   " << it->second << endl;
          //if((it->second)%2 == 0)
          //continue;
          if(it->second%2 != 0)
               cnt++;
     }
     return (cnt <= 1);
}

int main()
{
     string str = "";
     cout << "Enter String: ";
     getline(cin, str);
     cout << " Is String palindrome:- " << (canFormPalindrome(str) ? "Yes" : "No") << endl;
     return 0;
}
