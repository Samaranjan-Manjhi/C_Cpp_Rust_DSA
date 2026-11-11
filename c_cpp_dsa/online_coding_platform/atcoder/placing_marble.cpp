/*
   Time Limit: 2 sec / Memory Limit: 256 MiB

Score :

100 points
Problem Statement

Snuke has a grid consisting of three squares numbered
1, 2 and 3. In each square, either 0 or 1 is written. The number written in Square i is

si​.

Snuke will place a marble on each square that says 1. Find the number of squares on which Snuke will place a marble.
Constraints

Each of 

s1​, s2​ and

s3​ is either 1 or 0.

Input

Input is given from Standard Input in the following format:

s1​s2​s3​

Output

Print the answer.
 */

#include <iostream>
using namespace std;
int main()
{
     string s;
     cin >> s;
     int cnt = 0;
     for(char c : s)
     {
          if(c == '1')
               cnt++;
     }
     cout << cnt << endl;
     return 0;
}
