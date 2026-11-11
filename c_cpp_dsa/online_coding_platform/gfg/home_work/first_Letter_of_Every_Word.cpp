/*

   First Letter of Every Word

   Given a string s, the task is to create a string with the first letter of every word in the string. The string s contains lower case English alphabets and its words have a single space between them. 

Examples:

Input: s = "geeks for geeks"
Output: gfg
Explanation: 
First word starts at index 0, take 'g' 
After first space, next word starts with 'f'
After second space, next word starts with 'g'

Input: s = "bad is good"
Output: big

Constraints:
1 ≤ |s| ≤ 105

 */


#include <iostream>
#include <string>

using namespace std;

string firstAlphabet(string &s) 
{
     // code here
     int n = s.length();
     string res = "";
     if(n > 0)
          res += s[0];
     for(int i=0;i<n;i++)
     {
          if(i > 0 && s[i-1] == ' ')
               res += s[i];
     }   
     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     string res = firstAlphabet(s);
     cout << "     Result:- " << res << endl;

     return 0;
}
