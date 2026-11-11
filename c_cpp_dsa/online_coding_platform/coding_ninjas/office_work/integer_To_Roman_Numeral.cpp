/*

Integer To Roman Numeral 

 Problem statement

Given an integer ‘N’, the task is to find its corresponding Roman numeral.
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol      Value
  I           1
  V           5
  X           10
  L           50
  C           100
  D           500
  M           1000

Example :
2 is written as II in the roman numeral, just two one’s added together. 
12 is written as XII, which is simply X(ten) + II(one+one). 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.

There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

Constraints:
1 <= T <= 10^2
1 <= N <= 4*10^3 - 1
Time Limit : 1 sec

Sample Input 1 :
2
3
12
Sample Output 1 :
III
XII

Explanation For Sample Input 1 :
For the first test case, 3 is written as III in Roman numeral, just three one’s added together.
For the second test case, the number 12 can be represented as XII, which is simply X + II.

Sample Input 2 :
2
40
27
Sample Output 2 :
XL
XXVII

Explanation For Sample Input 2 :
For the first test case, 40 is written as XL in Roman numeral, which is L - X.
For the second test case, the number 27 can be represented as XXVII, which is simply X + X + V + II.

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToRoman(int num) {
     // Write your code here.
     vector<pair<int, string>> roman = {
          {1000, "M"},
          {900, "CM"},
          {500, "D"},
          {400, "CD"},
          {100, "C"},
          {90, "XC"},
          {50, "L"},
          {40, "XL"},
          {10, "X"},
          {9, "IX"},
          {5, "V"},
          {4, "IV"},
          {1, "I"}};

     string ans = "";
     for(auto& it : roman)
     {
          while(num >= it.first)
          {
               ans += it.second;
               num -= it.first;
          }
     }

     return ans;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     string res = intToRoman(n);
     cout << "    Result:- " << res << endl;

     return 0;
}
