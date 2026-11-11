/*

   Roman Numeral To Integer

   Problem statement

   You are given a string 's' that represents a Roman number. Convert the Roman number to an integer and return it.
   Roman numerals are represented by seven different symbols: I, V, X, L, C, D, and M.

   Table of values:
   Symbol       Value
   I             1
   V             5
   X             10
   L             50
   C             100
   D             500
   M             1000

   For example:
   3 is written as III in Roman numeral, just three ones added together. 13 is written as XIII, which is simply X + III. The number 25 is written as XXV, which is XX + V 

   Sample Input 1:
   XII
   Sample Output 1:
   12

   Explanation For Sample Input 1 :
   We know that ‘X’ is 10, and we have 2 ‘I’ after it. Therefore the number is 12

   Sample Input 2:
   XC
   Sample Output 2:
   90

Constraints:
1 <= roman.length <= 15
Time limit: 1 second

Follow Up:
Can you solve this in O(N) time?

 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
     // Write your code here
     unordered_map<char, int> roman {
          {'I', 1}, 
               {'V', 5}, 
               {'X', 10},
               {'L', 50},
               {'C', 100},
               {'D', 500},
               {'M', 1000}
     };

     int ans = 0;
     for(int i=0;i<s.length();i++)
     {
          int curr = roman[s[i]];
          if(i != s.length()-1)
          {
               int next = roman[s[i+1]];
               if(curr < next)
               {
                    ans -= curr;
               }
               else
               {
                    ans += curr;
               }
          }
          else
          {
               ans += curr;
          }
     }

     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     int res = romanToInt(str);
     cout << "    Result:- " << res << endl;

     return 0;
}
