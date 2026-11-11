/*

   Count Distinct Vowels in String

   Given a string s, count the total distinct vowels in the string. The string s contains lowercase letters only.

Examples:

Input: s = geeksforgeeks
Output: 1
Explanation: String "geeksforgeeks" has 2 distinct vowel "e" and "o".

Input: s = world
Output: 1
Explanation: It has only 1 distinct vowel "o".

Constraints:
1 ≤ |s| ≤ 104

 */


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int countVowels(string &s) 
{
     // code here
     unordered_map<char, int> mp;
     for(char c : s)
          mp[c]++;

     int cnt = 0;
     for(char c : s)
     {
          if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
          {
               if(mp[c] == 1)
                    cnt++;
          }
     }             

     return cnt;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int res = countVowels(s);
     cout << "      Result:- " << res << endl;

     return 0;
}
