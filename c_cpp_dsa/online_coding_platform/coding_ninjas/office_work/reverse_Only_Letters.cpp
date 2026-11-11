/*

   Reverse Only Letters

   Problem statement

   You are given a string, ‘S’. You need to reverse the string where characters that are not an alphabet stay in the same place, and the rest reverse their positions.

Eg: “a-bcd” becomes “d-cba”

Constraints:
1 <= T <= 10
0 <= |S| <= 5000
Where |S| denotes the length of string 'S'.
Time Limit: 1 Sec

Sample Input 1:
2
a-bcd
!s-cx
Sample Output 1:
d-cba
!x-cs

Explanation Of Sample Input 1:

In the first test case:
“a-bcd” after removing non-letter will be “abcd”.
Reversing “abcd” will get “dcba”.
Placing non-letters in the correct position in “dcba”, we get: “d-cba”.

In the second test case:
“!s-cx” after removing non-letter will be “scx”.
Reversing “scx” will get “xcs”.
Placing non-letters in the correct position in “xcs”, we get: “!x-cs”.

Sample Input 2:
2
a-bC-dEf-ghIj
Qedo1ct-eeLg=ntse-T!
Sample Output 2:
j-Ih-gfE-dCba
Test1ng-Leet=code-Q!

Explanation Of Sample Input 2:

In the first test case:
“a-bC-dEf-ghIj” after removing non-letter will be “abCdEfghlj”.
Reversing “abCdEfghlj” will get “jlhgfEdCba”.
Placing non-letters in the correct position in “jlhgfEdCba”, we get: “j-Ih-gfE-dCba”.

In the second test case:
“!s-cx” after removing non-letter will be “Qedo1ct-eeLg=ntse-T!”.
Reversing “QedocteeLgntseT” will get “TestngLeetcodeQ”.
Placing non-letters in the correct position in “TestngLeetcodeQ”, we get: “Test1ng-Leet=code-Q!”.

 */


#include <iostream>
#include <string>

using namespace std;

bool isAlpha(char c)
{
     if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
          return true;
     return false;
}

string reverseOnlyLetters(string & s) 
{
     // Write your code here.
     int n = s.length();
     string res = s;
     int l = 0, r = n-1;
     while(l < r)
     {
          while(l < n && !isAlpha(res[l]))
               l++;
          while(r >= 0 && !isAlpha(res[r]))
               r--;

          if(l < r)
          {
               swap(res[l], res[r]);
               l++;
               r--;
          }
     }

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     string res = reverseOnlyLetters(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
