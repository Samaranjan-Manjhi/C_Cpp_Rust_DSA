/*

   Square Root

   Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

   Floor value of any number is the greatest Integer which is less than or equal to that number.

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.

Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.

Input: n = 1
Output: 1
Explanation: 1 is a perfect sqaure, so its square root is 1.

Constraints:
1 ≤ n ≤ 3*104

 */


#include <iostream>

using namespace std;

int floorSqrt(int n)
{
     // code here
     for(int i=1;i<=n;i++)
     {
          if(i*i > n)
               return i-1;
          else if(i*i == n)
               return i;
     }

     return -1;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     int res = floorSqrt(n);
     cout << "    Result:- " << res << endl;

     return 0;
}
