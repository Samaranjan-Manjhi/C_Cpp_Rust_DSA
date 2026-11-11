/*
   Time Limit: 2 sec / Memory Limit: 256 MiB
Score :300 points

Problem Statement
You are given a string S consisting of lowercase English letters. Another string T is initially empty. Determine whether it is possible to obtain

S=T by performing the following operation an arbitrary number of times:
Append one of the following at the end of T: dream, dreamer, erase and eraser.

Constraints
1≦∣S∣≦105
S consists of lowercase English letters.

Input
The input is given from Standard Input in the following format:

S
Output
If it is possible to obtain S=T, print YES. Otherwise, print NO.

Sample Input 1
erasedream
Sample Output 1
YES
Append erase and dream at the end of T in this order, to obtain S=T.

Sample Input 2
dreameraser
Sample Output 2
YES
Append dream and eraser at the end of T in this order, to obtain S=T.

Sample Input 3
dreamerer
Sample Output 3
NO

 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
     string s;
     cin >> s;
     vector<string> v{"dream", "dreamer", "erase", "eraser"};
     while(!s.empty())
     {
          bool matched = false;
          for(string& word : v)
          {
               if(s.size() >= word.size() && s.substr(s.size()-word.size()) == word)
               {
                    s.erase(s.size()-word.size());
                    matched = true;
                    break;
               }
          }
          if(!matched)
          {
               cout << "NO" << endl;
               return 0;
          }
     }
     cout << "YES" << endl;
     return 0;
}
