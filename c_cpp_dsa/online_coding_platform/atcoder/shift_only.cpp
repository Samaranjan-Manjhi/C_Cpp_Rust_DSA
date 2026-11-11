/*

   Time Limit: 2 sec / Memory Limit: 256 MiB

Score :

200 points
Problem Statement

There are
N positive integers written on a blackboard:

A1​,...,AN​.

Snuke can perform the following operation when all integers on the blackboard are even:

Replace each integer 

X on the blackboard by X divided by

2.

Find the maximum possible number of operations that Snuke can perform.
Constraints

1≤N≤200

1≤Ai​≤109

Input

Input is given from Standard Input in the following format:

N

A1​ 

A2​ ... 

AN​

Output

Print the maximum possible number of operations that Snuke can perform.


 */

#include <iostream>
#include <vector>
using namespace std;
int main()
{
     int n, val;
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)
     {
          cin >> v[i];
     }
     int cnt = 0;
     while(1)
     {
          bool all_even = true;
          for(int i=0;i<n;i++)
          {
               if(v[i]%2 != 0)
               {    
                    all_even = false;
                    break;
               }
          }
          if(!all_even)  break;

          for(int i=0;i<n;i++)
          {
               v[i] /= 2;
          }
          cnt++;
     }
     cout << cnt << endl;
     return 0;
}

