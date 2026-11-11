/*

   Given a string s consisting only of the characters '0', '1' and '2', determine the length of the smallest substring that contains all three characters at least once.

   If no such substring exists, return -1.

Examples :

Input: s = "10212"
Output: 3
Explanation: The substring "102" is the shortest substring that contains all three characters '0', '1', and '2', so the answer is 3.

Input: s = "12121"
Output: -1
Explanation: The character '0' is not present in the string, so no substring can contain all three characters '0', '1', and '2'. Hence, the answer is -1.

Constraints:
1 ≤ s.size() ≤ 105

 */

#include <iostream>
#include <cstring>
using namespace std;

int smallestSubstring(string s) 
{
     // code here
     int n = s.length();
     if(n < 3)
          return -1;
     int ze = 0, on = 0, tw = 0;
     for(char c : s)
     {
          if(c == '0')
               ze++;
          else if(c == '1')
               on++;
          else if(c == '2')
               tw++;
     } 
     if(ze < 1 || on < 1 || tw < 1)
          return -1;
     int sum = 0;
     int l = 0, r = 0;
     while()
     
     return -1;
}

int main()
{
     string str = "";
     cout << "Enter String: ";
     cin >> str;
     cout << "Result:- " << smallestSubstring(str) << endl;

     return 0;
}
