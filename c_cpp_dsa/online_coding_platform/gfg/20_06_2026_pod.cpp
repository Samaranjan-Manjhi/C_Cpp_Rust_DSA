/*

   Given two integers a and b in the form of strings. Return the last digit of ab.

Examples:

Input: a = "3", b = "10"
Output: 9
Explanation: 310 = 59049. Last digit is 9.

Input: a = "6", b = "2"
Output: 6
Explanation: 62 = 36. Last digit is 6.

Constraints:
1 ≤ a.size(), b.size() ≤ 1000
a and b consist only of numeric digits ('0' - '9')
a and b do not contain any leading zeros, except when number itself is "0"

 */

#include <iostream>
#include <string>

using namespace std;

int mod(string b, int m)
{
     int res = 0;
     for (char c : b)
          res = (res * 10 + (c - '0')) % m;
     return res;
}

int getLastDigit(string& a, string& b) 
{
     // code here
     if (b == "0") return 1;
     int x = a.back() - '0';
     if (x == 0) return 0;

     // cycle lengths
     int len = 4;
     if (x == 0 || x == 1 || x == 5 || x == 6)
          len = 1;
     else if (x == 4 || x == 9)
          len = 2;
     int exp = mod(b, len);
     if (exp == 0) exp = len;
     int res = 1;
     for (int i = 0; i < exp; i++)
          res = (res * x) % 10;

     return res;
}

int main()
{
     string a, b;
     cout << "Enter Input Strings [base(a), power(b)]: ";
     cin >> a >> b;

     int res = getLastDigit(a, b);
     cout << "Last Digit:- " << res << endl;

     return 0;
}
