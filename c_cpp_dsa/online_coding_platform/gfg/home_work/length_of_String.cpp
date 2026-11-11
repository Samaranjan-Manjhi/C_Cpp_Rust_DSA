/*

   Length of String

   Given a string s, return the length of the string.

Examples:

Input: s = "Geeks"
Output: 5

Input: s = "Hello1234"
Output: 9

Constraints:
1 ≤ |s| ≤ 105

 */


#include <iostream>
#include <string>

using namespace std;

int lengthString(string &s) 
{
     // code here
     int len = 0;
     for(char c : s)
     {
          len++;
     }

     return len;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     int res = lengthString(s);
     cout << "    Result:- " << res << endl;

     return 0;
}
