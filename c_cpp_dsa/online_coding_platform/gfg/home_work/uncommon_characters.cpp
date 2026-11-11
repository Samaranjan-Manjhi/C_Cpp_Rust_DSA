/*

   Uncommon characters

   You are given two strings s1 and s2. Your task is to identify the characters that appear in either string but not in both (i.e., characters that are unique to one of the strings). Return the result as a sorted string.

Examples:

Input: s1 = "geeksforgeeks", s2 = "geeksquiz"
Output: "fioqruz"
Explanation: The characters 'f', 'i', 'o', 'q', 'r', 'u', and 'z' are present in either s1 or s2, but not in both.

Input: s1 = "characters", s2 = "alphabets"
Output: "bclpr"
Explanation: The characters 'b', 'c', 'l', 'p', and 'r' are present in either s1 or s2, but not in both.

Input: s1 = "rome", s2 = "more"
Output: ""
Explanation: Both strings contain the same characters, so there are no unique characters. The output is an empty string.

Constraints:
1<= s1.size(), s2.size() <= 105
Both strings contain only lowercase English letters.

 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string uncommonChars(string& s1, string& s2) 
{
     // code here
     /*
        sort(s1.begin(), s1.end());   
        if(s1 == s2)
        return "";

        set<char> st;
        for(char c : s1)
        {
        st.insert(c);   
        }
        string res = "";
        for(char c : s2)
        {
        if(st.find(c) != st.end())
        {
        res += c;
        }
        }
        string ans = "";
        s2 += s1;
        sort(s2.begin(), s2.end());
        set<char> seen;
        for(char c : s2)
        {
        if(res.find(c) == string::npos)
        {
        if(seen.find(c) == seen.end())
        {
        ans += c;
        seen.insert(c);
        }
        }
        } 
        return ans;
      */

     vector<int> f1(26, 0), f2(26, 0);

     for(char c : s1)
          f1[c - 'a'] = 1;

     for(char c : s2)
          f2[c - 'a'] = 1;

     string ans;

     for(int i = 0; i < 26; i++) 
     {
          if(f1[i] != f2[i])
               ans += (char)(i + 'a');
     }

     return ans.empty() ? "-1" : ans;
}

int main()
{
     string str;
     cout << "Enter Input String1: ";
     cin >> str;

     string str1;
     cout << "Enter Input String2: ";
     cin >> str1;

     string res = uncommonChars(str, str1);
     cout << "     Result:- " << res << endl;

     return 0;
}
