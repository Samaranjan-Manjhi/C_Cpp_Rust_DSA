/*

   Count Words in String

   Given a string s consisting of multiple words, return the count of total words in the string. Words are separated by a single space.

Note: It is guaranteed that the last character of the given string is not a white space.

Examples:

Input: s = "Geeks"
Output: 1
Explanation: There is just one word in the given sentence

Input: s = "World is hello"
Output: 3
Explanation: There exists three words in the given sentence

Constraints:
1 <= |s| <= 104

 */


#include <iostream>
#include <string>
using namespace std;

int countWords(string& s) 
{
     // code here
     int cnt = 1;
     if(s.length() == 0)
          return 0;
     for(char c : s)
     {
          if(c == ' ')
               cnt++;
     }
     return cnt;
}

int main() 
{
     string s;

     cout << "Enter string: ";
     getline(cin, s);

     int result = countWords(s);

     cout << "Number of words: " << result << endl;

     return 0;
}
