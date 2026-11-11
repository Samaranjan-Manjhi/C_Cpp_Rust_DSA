/*

   Ways to Express as Sum of Consecutives

   Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Examples:

Input: n = 10
Output: 1
Explanation: There is only one way, 10 = 1+2+3+4.

Input: n = 15
Output: 3
Explanation: There are 3 ways, (15 = 1+2+3+4+5), (15 = 4+5+6) and (15 = 7+8).

Constraints:
1 ≤ n ≤ 108

 */

#include <iostream>

using namespace std;

int getCount(int n) 
{
     // code here
     /* // tle
        int cnt = 0;
        int start = 1;
        while(start <= n/2)
        {
        int sum = 0;
        int curr = start;
        while(sum < n)
        {
        sum += curr;
        curr++;
        }

        if(sum == n)
        {
        cnt++;
        }

        start++;
        }
        return cnt;
      */

     int start = 1;
     int end = 2;
     int sum = start + end;
     int cnt = 0;

     while(start <= n/2)
     {
          if(sum == n)
          {
               cnt++;
               sum -= start;
               start++;
          }
          else if(sum < n)
          {
               end++;
               sum += end;
          }
          else
          {
               sum -= start;
               start++;
          }
     }

     return cnt;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     int res = getCount(n);
     cout << "     Result:- " << res << endl;

     return 0;
}
