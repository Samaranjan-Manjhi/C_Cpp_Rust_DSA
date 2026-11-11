/*

   Anagram

   Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
   Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.

Examples:

Input: s1 = "geeks" s2 = "kseeg"
Output: true 
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = "allergy", s2 = "allergyy" 
Output: false 
Explanation: Although the characters are mostly the same, s2 contains an extra 'y' character. Since the frequency of characters differs, the strings are not anagrams. 

Input: s1 = "listen", s2 = "lists" 
Output: false 
Explanation: The characters in the two strings are not the same — some are missing or extra. So, they are not anagrams.

Constraints:
1 ≤ s1.size(), s2.size() ≤ 105
s1, s2 consists of lowercase English letters.

 */


#include <iostream>
#include <string>

using namespace std;

bool areAnagrams(string& s1, string& s2) 
{
     // code here
     int n1 = s1.length();
     int n2 = s2.length();

     if(n1 != n2)
          return false;

     char v[26] = {0};
     for(char c : s1)
     {
          v[c-'a']++;
     }

     for(char c : s2)
     {
          v[c-'a']--;
     }

     for(int i=0;i<26;i++)
     {
          if(v[i] != 0)
               return false;
     }

     return true;
}

int main()
{
     string s1;
     cout << "Enter Input String1: ";
     getline(cin, s1);

     string s2;
     cout << "Enter Input String2: ";
     getline(cin, s2);

     bool res = areAnagrams(s1, s2);
     cout << "     Result:- ";
     if(res)
          cout << "  Yes\n";
     else
          cout << "  Nope\n";

     return 0;
}
