/*
   Time Limit: 2 sec / Memory Limit: 256 MiB

Score :

200 points
Problem Statement

Find the sum of the integers between
1 and N (inclusive), whose sum of digits written in base 10 is between A and

B (inclusive).
Constraints

1≤N≤104

1≤A≤B≤36
All input values are integers.

Input

Input is given from Standard Input in the following format:
N A B
Output

Print the sum of the integers between
1 and N (inclusive), whose sum of digits written in base 10 is between A and B (inclusive).

Sample Input 1
20 2 5
Sample Output 1
84
Among the integers not greater than 20, the ones whose sums of digits are between 2 and 5, are: 2,3,4,5,11,12,13,14 and 20. We should print the sum of these, 84.

Sample Input 2
10 1 2
Sample Output 2
13

Sample Input 3
100 4 16
Sample Output 3
4554

 */

#include <iostream>
using namespace std;

int sumNum(int n)
{
     int sum = 0;
     while(n > 0)
     {
          sum += (n%10);
          n /=10;
     } 
     return sum;
}

bool inRange(int n, int a, int b)
{
     int x = sumNum(n);
     //cout << "x:- " << x << endl;
     if(x >= a && x <= b)
          return true;
     return false;
}

int main()
{
     int n;
     cin >> n;
     int a;
     cin >> a;
     int b;
     cin >> b;
     int sum = 0;
     for(int i=1;i<=n;i++)
     {
          if(inRange(i, a, b))
          {
               //cout << "i:-  " << i << endl;
               sum += i;
          }
     }    
     cout << sum << endl;
     return 0;
}
