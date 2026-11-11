/*

Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

Return the total count modulo 1e9+7.

Examples :

Input: s1 = "geeksforgeeks", s2 = "gks"
Output: 4
Explanation: We can pick characters from s1 as a subsequence from indices [0, 3, 4], [0, 3, 12], [0, 11, 12] and [8, 11, 12]. So total 4 subsequences of s1 that are equal to s2.

Input: s1 = "problemoftheday", s2 = "geek"
Output: 0
Explanation: No subsequence of string s1 is equal to string s2.

Constraints:
1 ≤ s1.size(), s2.size() ≤ 103

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1e9+7;

int countWays(string &s1, string &s2) 
{
     // code here
     int n = s1.length();
     int m = s2.length();
     vector<int> dp(m+1, 0);
     dp[0] = 1;

     for(int i=1;i<=n;i++)
     {
          for(int j=m;j>=1;j--)
          {
               if(s1[i-1] == s2[j-1])
               {
                    dp[j] = (dp[j] + dp[j-1])%mod;
               }
          }
     }
     return dp[m];
}

int main()
{
     string s1;
     cout << "Enter Main String: ";
     cin >> s1;

     string s2;
     cout << "Enter Search String: ";
     cin >> s2;

     int res = countWays(s1, s2);
     cout << "Result:- " << res << endl;

     return 0;
}
