/*

   Binary Substrings with Corners as 1

   Given a binary string s. You have to count the number of substrings that start and end with 1.

Examples:

Input: s = "1111"
Output: 6
Explanation: There are 6 substrings from the given string. They are "11", "11", "11", "111", "111", "1111".

Input: s = "01101"
Output: 3
Explanation: There are 3 substrings from the given string. They are "11", "101", "1101".

Constraints:
1 ≤ |s| ≤ 104

 */

#include <iostream>
#include <string>

using namespace std;

int binarySubstring(string& s) 
{
     // code here
     int cnt = 0;
     for(char c : s)
     {
          if(c == '1')
               cnt++;
     }
     if(cnt < 2)
          return 0;
     return cnt*(cnt-1)/2;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int res = binarySubstring(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
