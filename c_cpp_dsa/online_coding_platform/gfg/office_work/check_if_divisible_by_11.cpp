/*

   Check if divisible by 11

   Given a number s . Check whether it is divisble by 11 or not.

Examples:

Input: s = 76945
Output: true
Explanation: The number is divisible by 11 as 76945 % 11 = 0.

Input: s = 12
Output: false
Explanation: The number is not divisible by 11 as 12 % 11 = 1.

Constraints:
1 ≤ |s| ≤ 10^1000+5

 */

#include <iostream>
#include <string>

using namespace std;

bool divisibleBy11(string &s) 
{
     // code here
     int n = s.length();
     int odd = 0, even = 0;
     for(int i=0;i<n;i++)
     {
          if(i%2 == 0)
               even += s[i] - '0';
          else
               odd += s[i] - '0';
     }

     int diff = abs(even - odd);

     if(diff % 11 == 0)
          return true;

     return false;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     bool res = divisibleBy11(s);
     if(res)
          cout << "     Yes\n";
     else
          cout << "     Nope\n";

     return 0;
}
