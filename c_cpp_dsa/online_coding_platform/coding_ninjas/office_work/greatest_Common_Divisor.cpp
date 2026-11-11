/*

   Greatest Common Divisor

   Problem statement

   You are given two numbers, ‘X’ and ‘Y’. Your task is to find the greatest common divisor of the given two numbers.

   The Greatest Common Divisor of any two integers is the largest number that divides both integers.

   For Example:
   You are given ‘X’ as 20 and ‘Y’ as 15. The greatest common divisor, which divides both 15 and 20, is 5. Hence the answer is 5.

Constraints:
1 <= T <= 10
1 <= X, Y <= 10^9

Sample Input 1:
2
20 15
8 32
Sample Output 1:
5
8

Explanation:
For the first test case, the greatest common divisor which divides both 15 and 20 is 5. Hence the answer is 5.
For the second test case, the greatest common divisor which divides both 8 and 32 is 8. Hence the answer is 8.

Sample Input 2:
2
98 56
36 60
Sample Output 2:
14
12

 */


#include <iostream>

using namespace std;

int mygcd(int a, int b)
{
     if(b == 0)
          return a;

     return mygcd(b, a%b);
}

int findGcd(int x, int y)
{
     // Write your code here
     return mygcd(x, y);
}

int main()
{
     int x, y;
     cout << "Enter Value of x and y: ";
     cin >> x >> y;

     int res = findGcd(x, y);
     cout << "    Result:- " << res << endl;

     return 0;
}
