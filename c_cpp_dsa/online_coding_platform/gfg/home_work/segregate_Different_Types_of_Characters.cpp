/*

   Segregate Different Types of Characters

   Given a string s containing letters, digits, and special characters, return an array of three strings [s1, s2, s3] such that: s1 contains all the letters, s2 contains all the digits, and s3 contains all the special characters.

   The relative order of the characters in each string must be exactly as they appear in s.
   If any type of character is not present, then return "-1" in the corresponding string.

Examples:

Input: s = "geeks01for02geeks03!!!"
Output: ["geeksforgeeks" , "010203" , "!!!"]
Explanation: s1 contains all the letters ("geeksforgeeks"), s2 contains all the digits ("010203"), and s3 contains the remaining special characters ("!!!") 

Input: s = "**Docoding123456789everyday##"
Output: ["Docodingeveryday" , "123456789" , "**##"]
Explanation: s1 contains all the letters ("Docodingeveryday"), s2 contains all the digits ("123456789"), and s3 contains all the special characters ("**##") 

Input: s = "ab##c"
Output: ["abc" , "-1" , "##"]

Constraints:
1 ≤ s.size() ≤ 105

 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString(string s) 
{
     // code here
     vector<string> ans;
     string ch = "", di = "", sy = "";
     for(char c : s)
     {
          if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
               ch += c;
          else if(c >= '0' && c <= '9')
               di += c;
          else
               sy += c;
     }
     if(ch == "")
          ans.push_back("-1");
     else
          ans.push_back(ch);

     if(di == "")
          ans.push_back("-1");
     else
          ans.push_back(di);

     if(sy == "")
          ans.push_back("-1");
     else
          ans.push_back(sy);

     return ans;
}

int main() 
{
     string s;

     cout << "Enter string: ";
     cin >> s;

     vector<string> result = splitString(s);

     cout << "Split strings: " << endl;
     for (string str : result) 
     {
          cout << str << endl;
     }

     return 0;
}
