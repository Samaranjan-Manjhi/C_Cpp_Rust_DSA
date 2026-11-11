/*

   Encrypt the string - 1

   Bingu was testing all the strings he had at his place and found that most of them were prone to a vicious attack by Banju, his arch-enemy. Bingu decided to encrypt all the strings he had, by the following method. Every substring of identical letters is replaced by a single instance of that letter followed by the number of occurrences of that letter. Then, the string thus obtained is further encrypted by reversing it.

   Example 1:

Input:
s = "aabc"
Output: 1c1b2a
Explanation: aabc
Step1: a2b1c1
Step2: 1c1b2a

Example 2:

Input:
s = "aaaaa"
Output: 5a
Explanation: aaaaa
Step 1: a5
Step 2: 5a

Your Task:
You don't need to read input or print anything.Your task is to complete the function encryptString() which takes a single argument(s) and returns the encrypted string.

Expected Time Complexity: O(|s|).
Expected Auxiliary Space: O(|s|).

Constraints
1 <= |s| <=1000

|s| denotes the length of the string s

 */


#include <iostream>
#include <string>

using namespace std;

string encryptString(string s) 
{
     // code here
     string res = "";
     int cnt = 1;
     char prev = s[0], curr;
     for(int i=1;i<s.length();i++)
     {
          curr = s[i];
          if(prev == curr)
          {
               cnt++;
          } 
          else
          {
               res += prev;
               res += to_string(cnt);
               prev = curr;
               cnt = 1;
          }
     }

     res += prev;
     res += to_string(cnt);
     int l = 0, r = res.length()-1;
     while(l < r)
     {
          swap(res[l], res[r]);
          l++;
          r--;
     }

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     string res = encryptString(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
