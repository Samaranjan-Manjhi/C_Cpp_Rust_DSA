/*

   Next Greater Number

   Problem statement

   You are given a string S which represents a number. You have to find the smallest number strictly greater than the given number which contains the same set of digits as of the original number i.e the frequency of each digit from 0 to 9 should be exactly the same as in the original number.

   For example:
   If the given string is 56789, then the next greater number is 56798. Note that although 56790 is also greater than the given number it contains 1 '0' which is not in the original number and also it does not contain the digit '8'.

Note:
The given string is non-empty.
If the answer does not exist, then return -1.
The given number does not contain any leading zeros.

Constraints:
1 <= T <= 100
1 <= len(S) <= 10^4
Time Limit: 1 sec

Sample Input 1:
1
1234
Sample Output 1:
1243

Explanation For Sample Input 1:
1243 is the next greater number consisting of the same set of digits (1,2,3 and 4)

Sample Input 2:
2
4321
65312    
Sample Output 2:
-1
65321

 */


#include <iostream>
#include <string>

using namespace std;

void doSwap(string& str, int l, int r)
{
     while(l < r)
     {
          swap(str[l], str[r]);
          l++;
          r--;
     }
}

string nextGreater(string S) 
{
     // Write your code here.
     int n = S.length();
     int i = n-2;
     string res = S;
     while(i >= 0 && ((res[i]-'0') >= (res[i+1]-'0')))
          i--;

     if(i < 0)
          return "-1";

     int j = n-1;
     while(((res[j]-'0') <= (res[i]-'0')))
          j--;

     swap(res[i], res[j]);

     doSwap(res, i+1, n-1);

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     string res = nextGreater(s);
     cout << "   Result:-  " << res << endl;

     return 0;
}
