/*

   Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.

Examples:

Input: n = 2
Output: 1
Explanation: Since 1 cut is mandatory. Maximum obtainable product is 1 * 1 = 1.

Input: n = 5
Output: 6
Explanation: Maximum obtainable product is 2 * 3 = 6.

Constraints:
2 ≤ n ≤ 58

 */

#include <iostream>
#include <math.h>

using namespace std;

int maxProduct(int n) 
{
     // code here
     if(n == 2)
          return 1;
     if(n == 3)
          return 2;

     int maxi = 0;
     int count3 = n/3;
     int rem  = n%3;

     if(rem == 0)
     {
          return pow(3, count3);
     }
     else if(rem == 1)
     {
          return (pow(3, count3-1)*4);
     }
     else if(rem == 2)
     {
          return (pow(3, count3)*2);
     }
     return -1;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     int res = maxProduct(n);
     cout << "Result:- " << res << endl;

     return 0;
}
