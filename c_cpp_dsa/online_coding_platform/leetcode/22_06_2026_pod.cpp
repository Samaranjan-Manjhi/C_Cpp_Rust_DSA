/*

   1189. Maximum Number of Balloons

   Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
   You can use each character in text at most once. Return the maximum number of instances that can be formed.

   Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0

Constraints:
1 <= text.length <= 104
text consists of lower case English letters only.

Note: This question is the same as 2287: Rearrange Characters to Make Target String.

 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int maxNumberOfBalloons(string text) 
{
     unordered_map<char, int> mp;
     for(char ch : text)
     {
          mp[ch]++;
     }
     int ans= 0;
     //ans = min({mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']});
     ans = mp['b'];

     if (mp['a'] < ans) ans = mp['a'];
     if (mp['l'] / 2 < ans) ans = mp['l'] / 2;
     if (mp['o'] / 2 < ans) ans = mp['o'] / 2;
     if (mp['n'] < ans) ans = mp['n'];

     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     int res = maxNumberOfBalloons(str);
     cout << "No. of Balloons:- " << res << endl;

     return 0;
}
