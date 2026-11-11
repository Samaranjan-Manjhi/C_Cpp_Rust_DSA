/*

Alternate Merge Two Strings

Given two strings s1 and s2, merge them alternatively i.e. the first character of s1 then the first character of s2 and so on till the strings end.

Note: Add the whole string if other string is empty.

Examples:

Input: s1 = "Hello", s2 = "Bye"
Output: HBeylelo
Explanation: The characters of both the given strings are arranged alternatlively.

Input: s1 = "abc", s2 = "def"
Output: adbecf
Explanation: The characters of both the given strings are arranged alternatlively.

Constraints:
1<=|s1|, |s2| <=103

*/


#include <iostream>
#include <string>
using namespace std;

string merge(string &s1, string &s2) {
    // code here
    return "";
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    string result = merge(s1, s2);

    cout << "Merged string: " << result << endl;

    return 0;
}
