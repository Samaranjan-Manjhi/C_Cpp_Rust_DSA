/*

   Check Permutation

   Problem statement

   You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.
Note:
Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.

Example :
If 'STR1' = “listen” and 'STR2' = “silent” then the output will be 1.
Both the strings contain the same set of characters.

Constraints:
1 <= T <= 100
1 <= |STR1|, |STR2| <= 10^3
Where |STR1| and |STR2| are the lengths of the string 'STR1' and 'STR2' respectively.
Time limit: 1 sec

Sample Input 1:
2
listen silent
east eats
Sample Output 1:
1
1
Explanation for Sample Output 1:
In test case 1, "listen" and "silent" has same set of characters.
In test case 2, "east" and "eats" has same set of characters.

Sample Input 2:
2
triangle integral
hearts earth
Sample Output 2:
1
0
Explanation for Sample Output 1:
In test case 1, "triangle" and "integral" has same set of characters.
In test case 2, "hearts" and "earth" does not have same set of characters.

 */


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areAnagram(string &str1, string &str2)
{
     // Write your code here.
     if(str1.length() != str2.length())
          return false;
     unordered_map<char, int> m1, m2;
     for(char ch : str1)
          m1[ch]++;

     for(char ch : str2)
          m2[ch]++;

     return m1 == m2;
}

int main()
{
     string s1;
     cout << "Enter Input String1: ";
     cin >> s1;

     string s2;
     cout << "Enter Input String2: ";
     cin >> s2;

     bool res = areAnagram(s1, s2);
     if(res)
          cout << "    Yes\n";
     else
          cout << "    Nope\n";

     return 0;
}
