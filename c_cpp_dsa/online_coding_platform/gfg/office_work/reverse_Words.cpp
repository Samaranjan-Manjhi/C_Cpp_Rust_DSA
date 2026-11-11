/*

   Reverse Words

   Given a string s, reverse the string without reversing its individual words. Words are separated by dots(.).

Note: The string may contain leading or trailing dots(.) or multiple dots(.) between two words. The returned string should only have a single dot(.) separating the words, and no extra dots should be included.

Examples :

Input: s = "i.like.this.program.very.much"
Output: "much.very.program.this.like.i"
Explanation: The words in the input string are reversed while maintaining the dots as separators, resulting in "much.very.program.this.like.i".

Input: s = "..geeks..for.geeks."
Output: "geeks.for.geeks"
Explanation: After removing extra dots and reversing the whole string, the input string becomes "geeks.for.geeks".

Input: s = "..home....."
Output: "home"
Explanation: The input string contains only one word with extra dots around it. After removing the extra dots, the output is "home".

Constraints:
1 ≤ s.length() ≤ 106
String s contains only lowercase English alphabets and dots.

 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseWords(string &s) 
{
     // code here
     string word = "";
     int n = s.length();
     vector<string> res;
     for(int i=0;i<n;i++)
     {
          if(s[i] != '.')
          {
               word += s[i];
          }
          else
          {
               if(word != "")
                    res.push_back(word);
               word = "";
          }
     }
     if(word != "")
          res.push_back(word);

     string re = "";
     int l = res.size();
     for(int i=l-1;i>=0;i--)
     {
          re += res[i];
          re += ".";
     }
     int len = re.length();
     if(len > 0)
          re.resize(len-1);
     return re;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     string res = reverseWords(s);
     cout << "     Result:- " << res << endl;

     return 0;
}
