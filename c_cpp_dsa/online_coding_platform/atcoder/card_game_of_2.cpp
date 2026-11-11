/*
   Time Limit: 2 sec / Memory Limit: 256 MiB

Score:

200 points
Problem Statement

We have
N cards. A number ai​ is written on the

i-th card.
Alice and Bob will play a game using these cards. In this game, Alice and Bob alternately take one card. Alice goes first.
The game ends when all the cards are taken by the two players, and the score of each player is the sum of the numbers written on the cards he/she has taken. When both players take the optimal strategy to maximize their scores, find Alice's score minus Bob's score.
Constraints

N is an integer between 1 and
100 (inclusive).
ai​ (1≤i≤N) is an integer between 1 and

100 (inclusive).

Input

Input is given from Standard Input in the following format: 
N
a1 a2 a3... aN


Output
Print Alice's score minus Bob's score when both players take the optimal strategy to maximize their scores.

Sample Input 1
2
3 1
Sample Output 1
2
First, Alice will take the card with 3. Then, Bob will take the card with 1. The difference of their scores will be 3 - 1 = 2.

Sample Input 2
3
2 7 4
Sample Output 2
5
First, Alice will take the card with 7. Then, Bob will take the card with 4. Lastly, Alice will take the card with 2. The difference of their scores will be 7 - 4 + 2 = 5.

Sample Input 3
4
20 18 2 18
Sample Output 3
18

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int diff(vector<int>& v)
{
     int n = v.size();
     int diff = 0;
     sort(v.begin(), v.end(), greater<int>());
     int sum = 0;
     for(int i=0;i<n;i++)
     {
          //cout << v[i] << " " ;
          if(i%2 == 1)
          {
               //cout << "v[i]:- " << v[i] << endl;
               diff += v[i];
          }
          else
          {
               sum += v[i];
          }
     }
     return sum-diff;
}

int main()
{
     int n, val;
     cin >> n;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     cout << "Result:- " << diff(v) << endl;
     return 0;
}
