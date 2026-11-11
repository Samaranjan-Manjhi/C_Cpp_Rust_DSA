/*

   1456. Maximum Number of Vowels in a Substring of Given Length

   Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
   Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

   Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length

 */


#include <iostream>
#include <string>

using namespace std;

/* // Gives Time Limit Exceeded
   void frstCharRemove(string& s)
   {
   if(s.length() == 0)
   return;
//if(s.length() == 1)

//if(s.length() >= 2)
{
for(int i=1;i<s.length();i++)
{
s[i-1] = s[i];
}
}
s.resize(s.length()-1);
}

bool isVowel(char ch)
{
if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
return true;
return false;
}

int getCnt(const string& s)
{
int cnt = 0;
for(char ch : s)
{
if(isVowel(ch))
cnt++;
}
return cnt;
}

int maxVowels(string s, int k) 
{
int ans = 0;
string temp = "";
for(int i=0;i<k;i++)
{
temp += s[i];
} 
cout << "temp:- " << temp << endl;
ans = getCnt(temp);
cout << "start ans value:  " << ans << endl;

for(int i=k;i<s.length();i++)
{
if(temp.length() >= k)
{
frstCharRemove(temp);
cout << "after remove start char: " << temp << endl;
temp += s[i];
cout << "after add at end char: " << temp << endl;
int tmp = getCnt(temp);
cout << "tmp value: " << tmp << endl;
ans = max(ans, tmp);
cout << "ans value:  " << ans << endl;
}
}     

return ans;
}
 */

bool isVowel(char ch)
{
     if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
          return true;
     return false;
}

int maxVowels(string s, int k) 
{
     int ans = 0;
     int cnt = 0;
     for(int i=0;i<k;i++)
     {
          if(isVowel(s[i]))
               cnt++;
     }
     ans = cnt;

     for(int i=k;i<s.length();i++)
     {
          if(isVowel(s[i]))
               cnt++;
          if(isVowel(s[i-k]))
               cnt--;
          ans = max(ans, cnt);
     }
     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     int k;
     cout << "Enter k value: ";
     cin >> k;

     int res = maxVowels(str, k);
     cout << "Max Vowels Count in length of k:- " << res << endl;

     return 0;
}
