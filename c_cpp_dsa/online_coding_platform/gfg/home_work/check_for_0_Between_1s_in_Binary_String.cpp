/*

   Check for 0 Between 1's in Binary String

   Given a binary string s consisting of '0' and '1', determine whether it is valid such that no '0' appears between two '1's.

   Return true if valid, otherwise return false.

Examples:

Input: s = "100"
Output: true
Explanation: The string contains only one '1', so no `'0' appears between two '1's', hence it is valid.

Input: s = "1110001"
Output: false
Explanation: The string has '0' occurring between '1's, so it is not valid.

Constraints:
1 ≤ s.size() ≤ 105

 */


#include <iostream>
#include <string>

using namespace std;

bool checkBinary(string &s) 
{
     // code here
     int n = s.length();
     int last = -1, first = -1;
     for(int i=0;i<n;i++)
     {
          if(s[i] == '1')
          {
               first = i;
               break;
          }
     }

     for(int i=n-1;i>=0;i--)
     {
          if(s[i] == '1')
          {
               last = i;
               break;
          }
     }

     for(int i=first;i<last;i++)
     {
          if(s[i] == '0')
               return false;
     }

     return true;
}

int main()
{
     string s;
     cout << "Enter String Input: ";
     cin >> s;

     bool res = checkBinary(s);
     if(res)
          cout << "     Result:-    " <<  "Yes" << endl;
     else
          cout << "     Result:-    " <<  "Nope" << endl;

     return 0;
}
