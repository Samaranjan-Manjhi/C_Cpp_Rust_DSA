/*

   You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
   Return the number of special letters in word.

   Example 1:
Input: word = "aaAbcBC"
Output: 3
Explanation:
The special characters in word are 'a', 'b', and 'c'.

Example 2:
Input: word = "abc"
Output: 0
Explanation:
No character in word appears in uppercase.

Example 3:
Input: word = "abBCab"
Output: 1
Explanation:
The only special character in word is 'b'.

Constraints:
1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.

 */


#include <iostream>
#include <string.h>
#include <set>

using namespace std;

int numberOfSpecialChars(string word) 
{
     set<char> sml, cap;
     for(char ch : word)
     {
          if(ch >= 65 && ch <= 90)
               sml.insert(ch+32);
          else
               cap.insert(ch);
     }
     cout << "Small Set: ";
     for(char c : sml)
          cout << c << " ";

     cout << "Capital Set: ";
     for(char c : cap)
          cout << c << " ";
     
     cout << "\n";
     int cnt = 0;
     for(char c : sml)
     {
          if(cap.find(c) != cap.end())
               cnt++;
     } 

     return cnt;
}

int main()
{
     string str;
     cout << "Enter String: ";
     cin >> str;

     int res = numberOfSpecialChars(str);
     cout << "Result:-  " << res << endl;


     return 0;
}
