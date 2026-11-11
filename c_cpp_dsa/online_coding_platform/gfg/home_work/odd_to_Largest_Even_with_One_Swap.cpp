/*

Odd to Largest Even with One Swap

Given an odd number in the form of string, the task is to make largest even number possible from the given number provided one is allowed to do exactly only one swap operation, if no such number is possible then return the input string itself.

Examples

Input: s = 4543
Output: 4534
Explanation: Swap second 4 and 3.

Input: s = 1539
Output: 1539
Explanation: No even no. present.

 Constraints:
1 <= Length of odd number string<= 105

*/


#include <iostream>
#include <string>
using namespace std;

string makeEven(string &s) {
    // code here
    return "";
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = makeEven(s);

    cout << "Result: " << result << endl;

    return 0;
}
