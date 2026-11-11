/*

   String Rotated by 2 Places

   Given two strings s1 and s2. Return true if the string s2 can be obtained by rotating (in any direction) string s1 by exactly 2 places, otherwise, false.

Note: Both rotations should be performed in same direction chosen initially.

Examples:

Input: s1 = "amazon", s2 = "azonam"
Output: true
Explanation: "amazon" can be rotated anti-clockwise by two places, which will make it as "azonam".

Input: s1 = "geeksforgeeks", s2 = "geeksgeeksfor"
Output: false
Explanation: If we rotate "geeksforgeeks" by two place in any direction, we won't get "geeksgeeksfor".

Input: s1 = "ab", s2 = "ab"
Output: true
Explanation: If we rotate "ab" by two place in any direction, we always get "ab".

Constraints:
1 ≤ s1.length, s2.length ≤ 10^5

 */


#include <iostream>
#include <string>

using namespace std;

bool isRotated(string& s1, string& s2)
{
     // code here
     int n1 = s1.length();
     int n2 = s2.length();

     if (n1 != n2 || n1 < 2)
          return false;

     string left_rot = "";
     for (int i = 2; i < n1; i++)
          left_rot += s1[i];

     left_rot += s1[0];
     left_rot += s1[1];

     if (left_rot == s2)
          return true;

     string right_rot = "";

     right_rot += s1[n1 - 2];
     right_rot += s1[n1 - 1];

     for (int i = 0; i < n1 - 2; i++)
          right_rot += s1[i];

     if (right_rot == s2)
          return true;

     return false;
}

int main()
{
     string s1;
     cout << "Enter Input String1: ";
     cin >> s1;

     string s2;
     cout << "Enter Input String2: ";
     cin >> s2;

     bool res = isRotated(s1, s2);
     if(res)
          cout << "    Result:-   Yes" << endl;
     else
          cout << "    Result:-   Nope" << endl;

     return 0;
}
