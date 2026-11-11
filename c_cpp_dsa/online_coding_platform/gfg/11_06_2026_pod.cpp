/*

   Given a string s of opening and closing brackets '(' and ')' only, find an equal point in the string. An equal point is a position k (0-based) such that the number of opening brackets before position k is equal to the number of closing brackets from position k to the end of the string. If multiple such points exist, return the first valid position.

   The string can be split at any position from 0 to n, where n is the length of the string.
   If we split at 0, it means there is an empty string on left.
   If we split at n, it means there is an empty string on right.

Examples:

Input: s = "(())))("
Output: 4
Explanation:

Input : s = "))"
Output: 2
Explanation: After index 2, the string splits into "))" and an empty string. The number of opening brackets in the first part is 0 and the number of closing brackets in the second part is also 0.

Constraints:
1 ≤ s.size() ≤ 105

 */

#include <iostream>
#include <string>

using namespace std;

int findIndex(string &s) 
{
     // code here
     int n = s.length();
     int closeBracket = 0, leftOpen = 0;
     for(char ch : s)
     {
          if(ch == ')')
               closeBracket++;
     }
     if(closeBracket == leftOpen)
          return 0;

     for(int i=0;i<n;i++)
     {
          if(s[i] == '(')
          {
               leftOpen++;

          }
          else if(s[i] == ')')
          {
               closeBracket--;
          }
          if(closeBracket == leftOpen)
               return i+1;
     }
     return n;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     int res = findIndex(str);
     cout << "Result:-  " << res << endl;

     return 0;
}
