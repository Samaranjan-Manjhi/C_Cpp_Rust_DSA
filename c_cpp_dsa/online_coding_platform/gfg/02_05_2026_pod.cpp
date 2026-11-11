/*

Given an integer n, determine position of the only set bit (1) in its binary representation. The position is counted starting from 1 at the least significant bit (LSB).

    If n contains exactly one set bit, return its position.
    If n contains no set bits or more than one set bit, return -1.

Examples:

Input: n = 2
Output: 2
Explanation: 2 is represented as "10" in binary. It has only one set bit, which is at position 2.

Input: n = 5
Output: -1
Explanation: 5 is represented as "101" in binary. It has two set bits; therefore, the output is -1.

Constraints:
0 ≤ n ≤ 108

*/


#include <iostream>
#include <cstring>
using namespace std;

string numTobin(int n)
{
     string str = "";
     while(n > 0)
     {
          int d = n%2;
          str += (char)(d + '0');
          n /= 2;
     }
     int m = str.length();
     int l = 0, r = m-1;
     while(l < r)
     {
          swap(str[l], str[r]);
          l++; r--;
     }
     return str;
}

int findPosition(int n) 
{
     // code here
     string res = numTobin(n);
     cout << "String:- " << res << endl;   
     int cnt = 0;
     for(int i=0;i<res.length();i++)
     {
          if(res[i] == '1')
               cnt++;
     }
     if(cnt == 0 || cnt > 1)
          return -1;

     for(int i=res.length()-1;i>=0;i--)
     {
          if(res[i] == '1')
               return (res.length()-i);
     }
     return -1;
}

int main()
{
int n;
cout << "Enter Number: ";
cin >> n;

int res = findPosition(n);
cout << "Result:- " << res << endl;

return 0;
}
