/*

   Ninja World Tournament 

   Problem statement

   Ninja was feeling bored during the lockdown. So, he decided to watch the Ninja World Tournament. The tournament consists of several matches, where the scores of past matches may affect future matches’ scores.

   At the beginning of the match, every player starts with an empty track record. Ninja wants to calculate the final score for a player. So, given a list of strings, ‘MATCHRESULT’, where ‘MATCHRESULT[ i ]’ is the ‘i’th operation Ninja must apply to the track record and is one of the following:

   1) An integer “A”: Introduce a new score of ‘A’ on the track record.
   2) "+": Introduce a new score on the track record that is the sum of the previous two scores.
   3) "C": Nullify the previous score, removing it from the track record.
   4) "D": Introduce a new score on the track record that is double the previous score.

   Ninja deduced that this could be easily solved using programming. So, he needs your help to calculate the sum of all the scores present in the track record.

Note:
It is guaranteed there will always be a previous score before the “C” and “D” operations and two previous scores before the “+” operation.

Sample Input 1:
2
5
2 3 + D C
4
15 C 10 D
Sample Output 1:
10
30

Explanation of Sample Output 1:

Test Case 1 :  
Given MATCHRESULT = {“2”, “3”, “+”, “D”, “C”}. Initially, TRACKRECORD = {}.
For “2”, Introducing 2 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {2}.
For “3”, Introducing 3 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {2, 3}.
For “+”, Introducing the sum of 2 and 3, i.e., 5 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {2, 3, 5}.
For “D”, Introducing the double of 5, i.e., 10 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {2, 3, 5, 10}.
For “C”, Nullifying the score 10 and thus removing it from the ‘TRACKRECORD’. Therefore, TRACKRECORD = {2, 3, 5}.
Sum of all the scores = 2 + 3 + 5 = 10.

Test Case 2 :     
Given MATCHRESULT = {“15”, “C”, “10”, “D”}. Initially, TRACKRECORD = {}.
For “15”, Introducing 15 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {15}.
For “C”, Nullifying the score 15 and thus removing it from the ‘TRACKRECORD’. Therefore, TRACKRECORD = {}.
For “10”, Introducing 10 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {10}.
For “D”, Introducing the double of 10, i.e., 20 on the ‘TRACKRECORD’. Therefore, TRACKRECORD = {10, 20}.
Sum of all the scores = 10 + 20 = 30.

Sample Input 2:
2
6
7 D 2 + C D
7
15 48 13 + D D C
Sample Output 2:
27
259

 */

#include <iostream>
#include <vector>
#include <string>
#include <stack> 

using namespace std;

bool isPosNum(const string& s)
{
     if(s.empty())
          return false;
     size_t st = 0;
     size_t n = s.length();

     if(s[0] == '-' || s[0] == '+')
     {
          st = 1;
          if(n == 1)
               return false;
     }
     for(int i=st;i<n;i++)
     {
          char ch = s[i];
          if(ch < '0' || ch > '9')
               return false;
     }

     return true;
}

int calculateScore(vector<string> &matchResult, int n)
{
     // Write your code here.
     stack<int> st;
     for(int i=0;i<n;i++)
     {
          string temp = matchResult[i];
          if(isPosNum(temp))
          {
               int num = stoi(temp);
               st.push(num);
          }
          else if(temp == "+")
          {
               int frst = st.top();
               st.pop();
               int secd = st.top();
               //st.pop();
               int ans = frst + secd;
               st.push(frst);
               st.push(ans);
          }
          else if(temp == "D")
          {
               int frst = st.top();
               st.push(frst*2);
          }
          else if(temp == "C")
          {
               st.pop();
          }
     }
     int res = 0;
     while(!st.empty())
     {
          res += st.top();
          st.pop();
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<string> v(n);
     for(int i=0;i<n;i++)
     {
          cin >> v[i];
     }

     int res = calculateScore(v, n);
     cout << "    Result:- " << res << endl;

     return 0;
}
