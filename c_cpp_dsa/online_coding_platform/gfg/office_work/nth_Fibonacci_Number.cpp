/*

   Nth Fibonacci Number

   Find the n-th Fibonacci number for a given non-negative integer n.
   The Fibonacci sequence is defined as:

   F(0) = 0
   F(1) = 1
   F(n) = F(n - 1) + F(n - 2) for n ≥ 2

Examples :

Input: n = 5
Output: 5
Explanation: The 5th Fibonacci number is 5.

Input: n = 0
Output: 0 
Explanation: The 0th Fibonacci number is 0.

Input: n = 1
Output: 1
Explanation: The 1st Fibonacci number is 1.

Constraints:
0 ≤ n ≤ 30

 */



#include <iostream>

using namespace std;

int nthFibonacci(int n) 
{
     // code here
     int a = 0, b = 1;
     if(n == 0)
          return 0;
     if(n == 1)
          return 1;
     for(int i=2;i<=n;i++)
     {
          int temp = a + b;
          a = b;
          b = temp;
     }

     return b;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     int res = nthFibonacci(n);
     cout << "    Result:- " << res << endl;

     return 0;
}
