/*

   Length of the Last Word

   Given a string s consisting of upper-case and lower-case alphabets along with space characters ' ', return the length of the last word present in the string.
Note: The string may contain trailing spaces.

Examples :

Input: s = "Geeks for Geeks"
Output: 5
Explanation: The last word is "Geeks" of length 5.

Input: s = "Start Coding Here "
Output: 4
Explanation: The last word is "Here" of length 4.

Constraints:
1 ≤ |s| ≤ 100
|s| denotes the length of the string s.

 */


#include <iostream>
#include <string>

using namespace std;

int lastWordLen(string &s) 
{
     // code here
     int n = s.length();
     int len = 0;
     int res = 0;
     int r = n-1;
     if(s[n-1] == ' ')
     {
          while(s[r] == ' ' && r > 0)
          {
               r--;
          }
     }

     for(int i=r;i>=0;i--)
     {
          //cout << "s[i]: " << s[i] << endl;
          if(s[i] == ' ')
          {
               return res;
               break;
          }
          else
          {
               res++;
          }
     }

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     int res = lastWordLen(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
