/*

   You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

   In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

   Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.



   Example 1:

Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
Explanation:
- Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
- Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
- It would take more than 2 edits for "ants" to equal a dictionary word.
- "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
Thus, we return ["word","note","wood"].

Example 2:

Input: queries = ["yes"], dictionary = ["not"]
Output: []
Explanation:
Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.



Constraints:

1 <= queries.length, dictionary.length <= 100
n == queries[i].length == dictionary[j].length
1 <= n <= 100
All queries[i] and dictionary[j] are composed of lowercase English letters.

 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int takeover(string& s1, string& s2)
{
     int cnt = 0;
     for(int i=0;i<s1.size();i++)
     {
          if(s1[i] != s2[i])
          {
               //cout << s1[i] << "   " << s2[i] << endl;
               cnt++;
          }
     }
     if(cnt > 2)
          return -1;
     return 0;
}

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
{
     // Write code here
     int q = queries.size();
     int d = dictionary.size();
     vector<string> res;
     for(int i=0;i<q;i++)
     {
          for(int j=0;j<d;j++)
          {
               int re = takeover(queries[i], dictionary[j]);
               if(re == 0 || queries[i] == dictionary[j])
               {
                    res.push_back(queries[i]);      
                    break;
               }
          }
     }
     return res;
}

int main()
{
     //vector<string> q{"word","note","ants","wood"};
     //vector<string> d{"wood","joke","moat"};

     //vector<string> q{"yes"};
     //vector<string> d{"not"};

     vector<string> q{"tsl","sri","yyy","rbc","dda","qus","hyb","ilu","ahd"};
     vector<string> d{"uyj","bug","dba","xbe","blu","wuo","tsf","tga"};

     vector<string> ans = twoEditWords(q, d);

     for(int i=0;i<ans.size();i++)
     {
          cout << ans[i] << " ";
     }
     cout << endl;
     return 0;
}
