/*

   Sum of Digits 

   Problem statement

   Ninja is given an integer ‘N’. One day Ninja decides to do the sum of all digits and replace the ‘N’ with the sum of digits until it becomes less than 10. Ninja wants to find what will be the value of ‘N’ after applying this operation.

   Help Ninja in finding out this value.

Constraints:
1 <= ‘T’ <= 11
1 <= ‘N’ <= 10 ^ 9
Time Limit: 1 sec.

Sample Input 1:
2
3
10
Sample Output 1:
3
1

Sample Explanation:
For the first test case:-
3 is less than 10. Hence we cannot apply the operation.
Thus answer is 3.

For the second test case:-
N = 10
Replace N with 1 + 0 = 1
N = 1
1 is less than 10. Hence we cannot apply the operation.
Thus answer is 1.

Sample Input 2:
2
13
14
Sample Output 2:
4
5

 */


#include <iostream>

using namespace std;

int addDigit(int x)
{
     int res = 0;
     while(x > 0)
     {
          int d = x%10;
          res += d;
          x /= 10;
     }
     return res;
}

int sumofDigits(int n)
{
     // Write your code here.
     if(n < 10)
          return n;
     int res = addDigit(n);
     if(res > 9)
     {
          res = addDigit(res);
     }
     return res;
}

int main()
{
     int n;
     cout << "Enter Numbers: ";
     cin >> n;

     int res = sumofDigits(n);
     cout << "     Result:- " << res << endl;

     return 0;
}
