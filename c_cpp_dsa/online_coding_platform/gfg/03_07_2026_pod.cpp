/*

   Ways to Increase LCS by One

   Given two strings s1 and s2 consisting of lowercase English letters of length n1 and n2 respectively, find the number of ways to insert exactly one character into string s1 such that the length of the Longest Common Subsequence (LCS) of both strings increases by exactly 1.

Examples :

Input: s1 = "abab", s2 = "abc"
Output: 3
Explanation: The LCS length of the given two strings is 2. There are 3 valid insertions in s1 which increase the LCS length to 3:
"abcab" -> LCS = 3
"abacb" -> LCS = 3
"ababc" -> LCS = 3

Input: s1 = "abcabc", s2 = "abcd"
Output: 4
Explanation: The LCS length of the given two strings is 3. There are 4 valid insertions in s1 which increase the LCS length to 4:
"abcdabc" -> LCS = 4
"abcadcb" -> LCS = 4
"abcabdc" -> LCS = 4
"abcabcd" -> LCS = 4

Constraints:
1<= n1, n2 <=100

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(string str1, string str2)
{
     int n1 = str1.size(), n2 = str2.size();
     vector<vector<int>> arr(n1 + 1, vector<int> (n2 + 1, 0));
     for (int i = n1 - 1; i >= 0; i--)
     {
          for (int j = n2 - 1; j >= 0; j--)
          {
               if (str1[i] == str2[j])
                    arr[i][j] = 1 + arr[i + 1][j + 1];
               else
                    arr[i][j] = max(arr[i + 1][j], arr[i][j + 1]);
          }
     }
     return arr[0][0];
}

int waysToIncreaseLCSBy1(string &s1, string &s2) 
{
     // code here
     /* // TLE
        int cnt = 0;
        int n1 = s1.size(), n2 = s2.size();
        int base = LCS(s1, s2);

        for (int pos = 0; pos <= n1; pos++)
        {
        for (char c = 'a'; c <= 'z'; c++)
        {
        string new_string;
        new_string.reserve(n1 + 1);
     // copy first part
     for (int i = 0; i < pos; i++) {
     new_string.push_back(s1[i]);
     }
     // insert character
     new_string.push_back(c);
     // copy second part
     for (int i = pos; i < n1; i++) {
     new_string.push_back(s1[i]);
     }
     if (LCS(new_string, s2) == base + 1) {
     cnt++;
     }
     }
     }

     return cnt;
      */

     int n1 = s1.size(), n2 = s2.size();

     int base = LCS(s1, s2);

     // prefix LCS
     vector<vector<int>> pre(n1 + 1, vector<int>(n2 + 1, 0));

     for (int i = 1; i <= n1; i++) 
     {
          for (int j = 1; j <= n2; j++) 
          {
               if (s1[i - 1] == s2[j - 1])
                    pre[i][j] = 1 + pre[i - 1][j - 1];
               else
                    pre[i][j] = max(pre[i - 1][j], pre[i][j - 1]);
          }
     }

     // suffix LCS
     vector<vector<int>> suf(n1 + 2, vector<int>(n2 + 2, 0));

     for (int i = n1; i >= 1; i--) 
     {
          for (int j = n2; j >= 1; j--) 
          {
               if (s1[i - 1] == s2[j - 1])
                    suf[i][j] = 1 + suf[i + 1][j + 1];
               else
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
          }
     }

     int cnt = 0;

     // try all insertion positions
     for (int pos = 0; pos <= n1; pos++) 
     {
          for (char c = 'a'; c <= 'z'; c++) 
          {
               bool ok = false;

               // try matching inserted char with every position in s2
               for (int k = 1; k <= n2; k++) 
               {
                    if (s2[k - 1] == c) 
                    {
                         int left = pre[pos][k - 1];
                         int right = suf[pos + 1][k + 1];

                         if (left + 1 + right == base + 1) 
                         {
                              ok = true;
                              break;
                         }
                    }
               }

               if (ok)
                    cnt++;
          }
     }

     return cnt;
}

int main()
{
     string str1;
     cout << "Enter First Input String: ";
     getline(cin, str1);

     string str2;
     cout << "Enter Second Input String: ";
     getline(cin, str2);

     int res = waysToIncreaseLCSBy1(str1, str2);
     cout << "    Result:- " << res << endl;

     return 0;
}
