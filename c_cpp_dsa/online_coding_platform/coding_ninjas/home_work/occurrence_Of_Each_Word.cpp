/*

   Occurrence Of Each Word 

   Problem statement

   You are given a string S of words. Your task is to count the occurrence of each word present in the string S. A word is a sequence of one or more non-space characters, and there can be multiple spaces between two words, and also there can be leading or trailing spaces in a string S.
   For Example:
   For the given string  “what we think we become”
   “what”,” think”, and “become” occurs 1 time, and “we” occurs 2 times in the given string.

Constraints :
0 <= |S| <= 10^5 
Time Limit: 1sec

Sample Input 1 :
learning to learn
Sample Output 1 :
learn 1
learning 1
to 1
Explanation For Sample Input 1:
For the given string, “learning”, “to”, and “learn” occurs only 1 time.  

Sample Input 2 :
what we think we become
Sample Output 2 :
think 1
what 1
we 2
become 1

 */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

void occurrenceOfEachWord(string s)
{
     // Write your code here
     unordered_map<string, int> mp;
     stringstream ss(s);
     string word;
     while(ss >> word)
     {
          mp[word]++;
     }

     for(auto& m : mp)
     {
          cout << m.first << "  " << m.second << endl;
     }
}

int main()
{
     string str;
     cout << "Enter INPUT String: ";
     getline(cin, str);

     occurrenceOfEachWord(str);

     return 0;
}
