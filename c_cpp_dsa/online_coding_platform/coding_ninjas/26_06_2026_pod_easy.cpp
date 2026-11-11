/*

   Problem statement

   You are given an array of ‘N’ sentences. Each sentence is a space-delimited string of words. The first word in each sentence is an alphanumeric identifier. Then, at least one of the following conditions will hold true:
   1. After identifier, each word will consist only of lowercase English letters
   2. After the identifier, each word will consist only of numbers.
   We will call these two types of sentences, letter – sentence and number– sentence. It is guaranteed that each sentence has at least one word after its identifier. Your task is to sort these sentences such that the following two conditions will hold.
   1. All letter - sentences must come before number- sentences.
   2. The letter - sentences must be ordered lexicographically ignoring identifiers. The identifier will be used in case of ties.
   3. The number– sentence must be put in their original order of occurrence. 

   Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
0 <= N <= 1000  
3 <= |S| <= 100 
Where 'T' denotes the number of test cases, 'N' denotes the number of sentences, and |S| denotes the length of sentence, S.
Time Limit: 1 sec

Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.

Sample Input 1 :
2
3
d1 2 3
love8 coding world
a1 coding ninjas 
3 
rating1 2143 1706
g1 raone 
avengers1 assemble
Sample Output 1 :
a1 coding ninjas
love8 coding world
d1 2 3
avengers1 assemble
g1 raone
rating1 2143 1706
Explanation for sample input1:
For the first test case, 
Letter sentences are [“love8 coding world”,   “a1 coding ninjas”], and number sentences are [“d1 2 3”]
Sorted order of letter sentences = [“a1 coding ninjas”, “love8 coding world”]
The original order of number sentences =[“d1 2 3”]
So the answer is [“a1 coding ninjas”, “love8 coding world”, “d1 2 3”].
For the second test case:
Letter sentences are [“g1 raone”,  “avengers1 assemble”], and number sentences are [“rating1 2143 1706”]
Sorted order of letter sentences = [“avengers1 assemble”, “g1 raone”].
Original order of number sentences = [ “rating1 2143 1706”]
So the answer is [“avengers1 assemble” , “g1 raone” , “rating1 2143 1706”]

Sample Input 2 :
1
4
wait8 opportunity is coming
coding24 7 365
coding1 2 3 4 5
goodluck2 you my friend
Sample Output 2 :
wait8 opportunity is coming
goodluck2 you my friend
coding24 7 365 
coding1 2 3 4 5
Explanation for sample input2:
For the first test case:
Letter sentences are [“wait8 opportunity is coming”,  “goodluck2 you my friend”], and number sentences are [  “coding24 7 365”, “coding1 2 3 4 5”].
Sorted order of letter sentences = [“wait8 opportunity is coming”, “goodluck2 you my friend”].
Original order of number sentences =[“coding24 7 365”, “coding1 2 3 4 5”].
So the answer is [“wait8 opportunity is coming”, “goodluck2 you my friend”, “coding24 7 365”, “coding1 2 3 4 5”].

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Extract identifier
string getId(string s) 
{
     string id = "";
     int i = 0;
     while (i < s.length() && s[i] != ' ') 
     {
          id += s[i];
          i++;
     }
     return id;
}

// Extract content after identifier
string getContent(string s) 
{
     string content = "";
     int i = 0;
     while (i < s.length() && s[i] != ' ')
          i++;
     i++; // skip space
     while (i < s.length()) 
     {
          content += s[i];
          i++;
     }
     return content;
}

// Check if sentence is number-log
bool isNumberLog(string s) 
{
     int i = 0;
     while (i < s.length() && s[i] != ' ')
          i++;
     i++; // first character after space
     return (s[i] >= '0' && s[i] <= '9');
}

// Compare two letter sentences
bool smaller(string a, string b) 
{
     string c1 = getContent(a);
     string c2 = getContent(b);
     if (c1 < c2)
          return true;
     if (c1 > c2)
          return false;
     // Contents equal, compare identifiers
     return getId(a) < getId(b);
}

vector<string> reOrderSentences(vector<string> sentences)
{
     // Write your code here
     vector<string> letters;
     vector<string> numbers;
     // Separate sentences
     for (int i = 0; i < sentences.size(); i++) 
     {
          if (isNumberLog(sentences[i]))
          {
               numbers.push_back(sentences[i]);
          }
          else
          {
               letters.push_back(sentences[i]);
          }
     }

     /*
     // Bubble Sort
     int n = letters.size();
     for (int i = 0; i < n - 1; i++) 
     {
          for (int j = 0; j < n - i - 1; j++) 
          {
               if (!smaller(letters[j], letters[j + 1])) 
               {
                    string temp = letters[j];
                    letters[j] = letters[j + 1];
                    letters[j + 1] = temp;
               }
          }
     }
     */

     sort(letters.begin(), letters.end(), smaller);
     
     vector<string> ans;
     for (int i = 0; i < letters.size(); i++)
          ans.push_back(letters[i]);
     for (int i = 0; i < numbers.size(); i++)
          ans.push_back(numbers[i]);

     return ans;
}

int main()
{
     vector<string> in = {
          "d1 2 3",
          "love8 coding world",
          "a1 coding ninjas"
     };
     vector<string> res = reOrderSentences(in);
     for(int i=0;i<res.size();i++)
     {
          cout << res[i] << " ";
     }
     cout << endl;

     return 0;
}
