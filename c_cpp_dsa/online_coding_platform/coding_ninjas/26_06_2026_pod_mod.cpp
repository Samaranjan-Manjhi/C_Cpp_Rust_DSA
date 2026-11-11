/*

 Problem statement

Given two integers, ‘N’ and ‘M’, your task is to find the sum of Fibonacci numbers between ‘fib(N)’ and ‘fib(M)’ where ‘fib(N)’ represents the Nth Fibonacci number and ‘fib(M)’ represents the Mth Fibonacci number. The sum is given by sum(N, M) = fib(N) + fib(N+1) + fib(N+2) … fib(M). Since the answer could be large, so you have to return the sum modulo 10^9 + 7.

The fibonacci relation is given by:
fib(0) = 0 
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2), n >= 2, where fib(n) represents the nth fibonacci number.

Constraints:
1 <= T <= 1000
0 <= N <= M <= 10^9
Where ‘T’ represents the number of test cases, and ‘N’ and ‘M’ represents the starting and ending of the range respectively.
Time Limit: 1 sec

Sample Input 1:
2
2 6
0 5
Sample Output 1:
19
12 
Explanation 1:
For the first test case, 
The Fibonacci numbers between fib(2) and fib(6) are {1, 2, 3, 5, 8}. Their sum is equal to 19. Hence the output is 19.
For the second test case,
The Fibonacci numbers between fib(0) and fib(5) are {0, 1, 1, 2, 3, 5}. Their sum is equal to 12. Hence the output is 12.

Sample Input 2:
2
3 6
6 7
Sample Output 2:
18
21

*/


#include <iostream>

using namespace std;

long long fibo(int n)
{
     long long a = 0, b = 1;
     for(int i=31;i>=0;i--)
     {
          long long c = a * ((2 * b) - a);
          long long d = (a * a) + (b * b);
          if((n >> i) & 1)
          {
               a = d;
               b = c + d;
          }
          else
          {
               a = c;
               b = d;
          }
     }
     return a;
}

int fiboSum(int n , int m)
{
	// Write your code here
     int mod = 1e9+7;
     long long x = fibo(m+2);
     long long y = fibo(n+1);

     int ans = (x-y)%mod;
     if(ans < 0)
          ans = ans+mod;

     return ans;
}

int main()
{
     int n;
     cout << "Enter n Value: ";
     cin >> n;

     int m;
     cout << "Enter m Value: ";
     cin >> m;

     int res = fiboSum(n, m);
     cout << "Result:- " << res << endl;

     return 0;
}
