/*

   Word Lengths

   Given a sentence s consisting of words formed using English letters and separated by a single space, return an array containing the length of each word in the order they appear in the sentence.

Examples:

Input: s = "the quick brown fox"
Output: 3 5 5 3
Explanation: The words are "the", "quick", "brown", and "fox", whose lengths are 3, 5, 5, and 3 respectively.

Input: s = "geeks for geeks"
Output: 5 3 5
Explanation: The words are "geeks", "for", and "geeks", whose lengths are 5, 3, and 5 respectively.

Constraints:
1 ≤ |s| ≤ 105

 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getLen(string s)
{
     int len = 0;
     for(char c : s)
          len++;
     return len;
}

vector<int> wordLengths(string &s) 
{
     // code here
     string temp = "";
     int n = s.length();
     vector<int> res;
     for(char c : s)
     {
          if(c != ' ')
          {
               temp += c;
          }
          else
          {
               int sz = getLen(temp);
               res.push_back(sz);
               temp = "";
          }
     }   

     int sz = getLen(temp);
     res.push_back(sz);

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     vector<int> res = wordLengths(s);
     cout << "     Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
