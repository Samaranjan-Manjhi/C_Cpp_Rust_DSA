/*

   Remainder with 7

   Given a number as string n, return the remainder of the number when it is divided by 7.

Examples : 

Input: n = "5" 
Output: 5
Explanation: Since 5 is less than 7, the remainder when divided by 7 is 5.

Input: n = "8"
Output: 1
Explanation: 8 divided by 7 leaves remainder 1.

Constraints:
1 ≤ |n| ≤ 10^5

 */

#include <iostream>
#include <string>

using namespace std;

int remainderWith7(string &n)
{
     // code here
     int ans = 0;
     for(char c : n)
     {
          int d = c - '0';
          ans = ans * 10 + d;
          ans %= 7;
     }

     return ans;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int res = remainderWith7(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
