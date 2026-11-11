/*

   Unset Kth Bit

Given two numbers n and k, change the kth bit (1-based indexing, counted from the left) of n's binary representation to 0 if it is currently 1.

No changes is made in the following cases:

    If kth bit is already 0
    k exceeds the total number of bits in n

Examples:

Input: n = 13, k = 2
Output: 9
Explanation: Binary representation of 13 is 1101. the 2nd bit from the left is 1, so it becomes 0, giving 1001 = 9.

Input: n = 13, k = 6
Output: 13
Explanation: Binary representation of 13 is 1101, which only has 4 bits. there's no 6th bit from the left, so n is returned unchanged.

Constraints:
1 ≤ n ≤ 106
1 ≤ k ≤ 20

 */


#include <iostream>
#include <string>

using namespace std;

string bitCvt(int n)
{
     string res = "";
     while (n > 0)
     {
          int d = n%2;
          if (d == 0)
               res += '0';
          else
               res += '1';
          n /= 2;
     }

     int len = res.length();
     int l = 0, r = len - 1;
     while (l < r)
     {
          swap(res[l], res[r]);
          l++;
          r--;
     }

     return res;
}

int intcnt(string s)
{
     int num = 0;
     for(char c : s)
     {
          num = num * 2 + (c - '0');
     }

     return num;
}

int replaceBit(int n, int k) 
{
     // code here
     string res = bitCvt(n);
     cout << "Res:- " << res << endl;
     int len = res.length();
     int pos = k-1;
     if(len < k || res[pos] == '0')
          return n;
     if(res[pos] == '1')
          res[pos] = '0';
     cout << "Res1:- " << res << endl;

     int res1 = intcnt(res);

     return res1;
}

int main()
{
     int n;
     cout << "Enter Num Value: ";
     cin >> n;

     int k;
     cout << "Enter k value: ";
     cin >> k;

     int res = replaceBit(n, k);
     cout << "    Result:- " << res << endl;

     return 0;
}
