/*

Successful Penalty Conversions

A football match event log is represented by a string s consisting of characters '0', '1', and '2'.

    '2' represents a penalty awarded.
    '1' represents a successful penalty conversion.
    '0' represents an unsuccessful penalty conversion.

A successful penalty conversion occurs when a penalty award is immediately followed by a successful conversion, i.e. the substring "21" appears in the log. Count the total number of successful penalty conversions in the string.

Examples:

Input: s = "1012012112110"
Output: 2
Explanation: The substring "21" appears at positions: 10120[21]12110 and 10120121[21]10. Hence the answer is 2.

Input: s = "111122"
Output: 0
Explanation: The substring "21" does not appear in the string.

Constraints:
1 ≤ s.size() ≤ 105

*/


#include <iostream>
#include <string>
using namespace std;

int countCoversions(string &s) {
    // code here
    return 0;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = countCoversions(s);

    cout << "Number of conversions: " << result << endl;

    return 0;
}
