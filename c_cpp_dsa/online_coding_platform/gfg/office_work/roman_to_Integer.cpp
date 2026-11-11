/*

   Roman to Integer

   Given a string s in Roman number format, your task is to convert it to an integer. Various symbols and their values are given below.
Note: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

Examples:

Input: s = "IX"
Output: 9
Explanation: IX is a Roman symbol which represents 10 – 1 = 9.

Input: s = "XL"
Output: 40
Explanation: XL is a Roman symbol which represents 50 – 10 = 40.

Input: s = "MCMIV"
Output: 1904
Explanation: M is 1000, CM is 1000 – 100 = 900, and IV is 4. So we have total as 1000 + 900 + 4 = 1904.

Constraints:
1 ≤ roman number ≤ 3999
s[i] belongs to [I, V, X, L, C, D, M]

 */


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInteger(string &s) 
{
     // code here
     unordered_map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
          {'C', 100}, {'D', 500}, {'M', 1000}};
     int ans = 0;
     for(int i=0;i<s.length();i++)
     {
          int curr = mp[s[i]];
          if(i != s.length()-1)
          {
               int next = mp[s[i+1]];
               if(curr < next)
               {
                    ans -= curr;
               }
               else
               {
                    ans += curr;
               }
          }
          else
          {
               ans += curr;
          }
     }


     return ans;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int res = romanToInteger(s);
     cout << "   Result:-  " << res << endl;

     return 0;
}
