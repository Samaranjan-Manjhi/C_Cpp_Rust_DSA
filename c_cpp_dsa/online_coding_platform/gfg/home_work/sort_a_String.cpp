/*

   Sort a String

   Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

Examples:

Input: s = "edcab"
Output: "abcde"
Explanation: characters are in ascending
order in "abcde".

Input: s = "xzy"
Output: "xyz"
Explanation: characters are in ascending
order in "xyz".

Constraints:
1 ≤ |s| ≤ 105

 */


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string sortString(string &s) 
{
     // code here
     sort(s.begin(), s.end());
     return s;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     string res = sortString(str);
     cout << "     Result:- " << res << endl;     

     return 0;
}
