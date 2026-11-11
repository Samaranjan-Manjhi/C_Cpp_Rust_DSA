/*

Substrings with more 1's than 0's

Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.

Examples:

Input: s = "011"
Output: 4
Explanation: There are 4 substring which has more 1s than 0s. i.e "011","1","11" and "1"

Input: s = "0000"
Output: 0
Explanation: There is no substring with more 1s than 0s

Constraints:
1 < |s| <  6 * 10^4

*/

#include <iostream>
#include <string>

using namespace std;

// TLE
int countSubstring(string& s) 
{
     int n = s.length();
     int cnt = 0;

     for (int i = 0; i<n; i++)
     {
          int one = 0, zero = 0;
          for (int j = i; j<n; j++)
          {
               if (s[j] == '1')
                    one++;
               else
                    zero++;

               if (one > zero)
                    cnt++;
          }
     }

     return cnt;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     int res = countSubstring(str);
     cout << "     Result:- " << res << endl;

     return 0;
}
