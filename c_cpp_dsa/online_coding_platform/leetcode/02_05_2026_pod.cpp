/*

788. Rotated Digits

An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:
    0, 1, and 8 rotate to themselves,
    2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
    6 and 9 rotate to each other, and
    the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

Example 1:
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Example 2:
Input: n = 1
Output: 0

Example 3:
Input: n = 2
Output: 1

Constraints:
    1 <= n <= 104

*/

#include <iostream>
using namespace std;

bool contain_toxic(int num)
{
     while(num > 0)
     {
          int d = num%10;
          if(d == 3 || d == 4 || d == 7)
               return true;
          num /= 10;
     }
     return false;
}

bool contain_change(int num)
{
     while(num > 0)
     {
          int d = num%10;
          if(d == 2 || d == 5 || d == 6 || d == 9)
               return true;
          num /= 10;
     }
     return false;
}

int rotatedDigits(int n) 
{
     bool toNext = false;
     bool contain = false;
     int cnt = 0;
     for(int i=1;i<=n;i++)
     {
          toNext = contain_toxic(i);
          if(toNext == true)
          {
               //cout << i << " ---- Contain 3, 4 or 7.\n";
               continue;
          }
          else
          {
               //cout << i << " ----- Not Contain 3, 4 or 7.\n";
               contain = contain_change(i);
               if(contain == true)
                    cnt++;
          }
     }        
     return cnt;
}

int main()
{
int n;
cout << "Enter Number: ";
cin >> n;

int goodCnt = rotatedDigits(n);
cout << "Result:- " << goodCnt << endl;

return 0;
}
