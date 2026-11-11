/*

   Problem statement

   You are given an integer 'N'. Your task is to find the number formed after swapping each even bit of 'N' in its binary representation with its adjacent bit on the right, assuming that the least significant bit is an odd bit.

   For example :
   Consider the integer N = 45 whose binary representation is 101101. The resulting number formed after swapping each even bit with its adjacent bit to the right will be 30 (011110) in this case.

Constraints :
1 <= T <= 10^5
1 <= N <= 10^9
Time Limit: 1 sec

Sample Input 1 :
2
9
2
Sample Output 1 :
6 
1
Explanation For Sample Input 1 :
For the first test case : 
The binary representation of 9 is 1001. Here, we will swap the 2nd bit with the 1st bit and the 4th bit with 3rd bit. The resulting binary number will be 0110. Hence, the answer is 6 in this case.
For the second test case : 
The binary representation of 2 is 10. Here, we will swap the 2nd bit with the 1st bit. The resulting binary number will be 01 or 1. Hence, the answer is 1 in this case.

Sample Input 2 :
2
7
10
Sample Output 2 :
11
5

 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void swaping(string& s)
{
     if(s.length() == 0)
          return;
     int n = s.length();
     int l = 0, r = n-1;
     while(l < r)
     {
          swap(s[l], s[r]);
          l++;
          r--;
     }
}

void adjacentSwap(string& s)
{
     if(s.length() == 0)
          return;
     int n = s.length();
     for(int i=1;i<n;i+=2)
     {
          swap(s[i-1], s[i]);
     }
}

int outVal(const string& s)
{
     int ans = 0;
     for(char ch : s)
     {
          ans = ans*2+(ch-'0');
     }
     return ans;
}

int swapAdjacentBits(int n)
{ 
     // Write your code here
     string res = "";
     if(n == 0)
          res += '0';
     else
     {
          while(n > 0)
          {
               int d = n%2;
               res += to_string(d);
               n /= 2;
          }
     }
     if(res.length()%4 != 0)
          res.append(4-(res.length()%4), '0');
     swaping(res); 
     cout << "String:- " << res << endl;

     adjacentSwap(res);
     cout << "String after adjacent Swap:- " << res << endl;
     int value = outVal(res);
     return value;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     int res = swapAdjacentBits(n);
     cout << "Result:-   " << res << endl;

     return 0;
}
