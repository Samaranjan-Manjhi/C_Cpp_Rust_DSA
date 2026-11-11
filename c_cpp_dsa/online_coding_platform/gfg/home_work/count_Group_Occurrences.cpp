/*

   Count Group Occurrences

   Given a string s. Count the characters that have ‘k’ number of occurrences. If a character appears consecutively it is counted as 1 occurrence.

Examples:

Input: s = "abc", k = 1
Output: 3
Explanation: 'a', 'b' and 'c' all have 1 occurrence.

Input: s = "geeksforgeeks", k = 2
Output: 4
Explanation: 'g', 'e', 'k' and 's' have 2 occurrences.

Input: s = "aaaaa", k = 2
Output: 0
Explanation: There is only one group occurrence of 'a'

Constraints:
1<=s.length()<=105
1<=k<=103

 */


#include <iostream>
#include <string>
#include <map>

using namespace std;

int getCount(string s, int k) 
{
     // code here
     map<char, int> mp;
     for(int i=0;i<s.length();i++)
     {
          if(i == 0 || s[i] != s[i-1])
               mp[s[i]]++;
     }
     int cnt = 0;
     for (auto &it : mp)
     {
          if (it.second == k)
               cnt++;
     }
     return cnt;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     int k;
     cout << "Enter k Value: ";
     cin >> k;

     int res = getCount(str, k);
     cout << "     Result:- " << res << endl;

     return 0;
}
