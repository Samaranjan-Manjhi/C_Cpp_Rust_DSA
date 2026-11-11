/*

Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:
Input: s = "abc"
Output: 1

Constraints:
    3 <= s.length <= 5 x 10^4
    s only consists of a, b or c characters.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int numberOfSubstrings(string s) 
{
     /* // TLE
     vector<string> substr;
     int n = s.length();
     for(int i=0;i<n;i++)
     {
          string temp = "";
          for(int j=i;j<n;j++)
          {
               temp += s[j];
               //cout << "temp: " << temp << endl;
               substr.push_back(temp);
          }
     }
     int cnt = 0;
     for(int i=0;i<substr.size();i++)
     {
          if(substr[i].find('a') != string::npos && substr[i].find('b') != string::npos && substr[i].find('c') != string::npos)
               cnt++;
     }
     return cnt;
     */


     int n = s.length();
     int left = 0, ans = 0;
     vector<int> freq(3, 0);
     for(int right=0;right<n;right++)
     {
          freq[s[right] - 'a']++;
          while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
          {
               ans += (n-right);
               freq[s[left] - 'a']--;
               left++;
          }
     }
     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     int res = numberOfSubstrings(str);
     cout << "      Result:- " << res << endl;

     return 0;
}
