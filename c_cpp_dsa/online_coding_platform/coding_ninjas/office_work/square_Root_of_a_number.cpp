/*

   Square Root of a number

   Problem statement

   You are given a positive integer ‘n’.

   Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Example:

Input: ‘n’ = 7
Output: 2
Explanation:
The square root of the number 7 lies between 2 and 3, so the floor value is 2.

Sample Input 1:
6
Sample Output 1:
2

Explanation of Sample Input 1:
The square root of the given number 6 lies between 2 and 3, so the floor value is 2.

Sample Input 2:
100
Sample Output 2:
10

Explanation of Sample Output 2:
The square root of the given number 100 is 10.

Expected Time Complexity:
Try solving this in O(log(n)).

Constraints:
0 <= n <= 10 ^ 9
Time Limit: 1 sec.

 */


#include <iostream>

using namespace std;

int floorSqrt(int n)
{
     // Write your code here.
     for(int i=1;i<=n;i++)
     {
          if(i*i == n)
               return i;
          else if(i*i > n)
               return i-1;
     }

     return 0;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     int res = floorSqrt(n);
     cout << "   Result:- " << res << endl;

     return 0;
}
