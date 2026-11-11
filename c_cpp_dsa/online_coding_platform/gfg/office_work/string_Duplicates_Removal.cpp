/*

   String Duplicates Removal

   Given a string s which may contain lowercase and uppercase characters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

Examples:

Input: s = "geEksforGEeks"
Output: "geEksforG"
Explanation: After removing duplicate characters such as E, e, k, s, we have string as "geEksforG".

Input: s = "HaPpyNewYear"
Output: "HaPpyNewYr"
Explanation: After removing duplicate characters such as e, a, we have string as "HaPpyNewYr".

Constraints:
1 ≤ s.size() ≤ 10^6
String contains uppercase and lowercase English letters.

 */


#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string removeDuplicates(string &s) 
{
     // code here
     //int n = s.length();
     string res = "";
     unordered_set<char> seen;
     for(char c : s)
     {
          if(seen.find(c) == seen.end())
          {
               seen.insert(c);
               res += c;
          }
     }

     return res;
}

int main()
{
     string s1;
     cout << "Enter Input String1: ";
     cin >> s1;

     string res = removeDuplicates(s1);
     cout << "    Result:-  " << res << endl;

     return 0;
}
