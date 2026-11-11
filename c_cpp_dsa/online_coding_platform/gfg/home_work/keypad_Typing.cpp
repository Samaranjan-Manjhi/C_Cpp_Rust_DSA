/*

Keypad Typing

Given a string s consisting of lowercase English letters. Each letter corresponds to a number on a standard keypad, as shown in the figure. Replace every character in s with its corresponding keypad number and return the resulting numeric string.

Examples:
2(abc), 3(def), 4(ghi), 5(jkl), 6(mno), 7(pqrs), 8(tuv), 9(wxyz)
Input: s = "geeksforgeeks"
Output: 4335736743357
Explanation: Each character in the string "geeksforgeeks" is converted to its corresponding digit based on the keypad, and the digits are concatenated in order. This results in the number 4335736743357, which is the required decimal representation.

Input: s = "geeksquiz"
Output: 433577849
Explanation: Each character in the string "geeksquiz" is converted to its corresponding digit based on the keypad, and the digits are concatenated in order. This results in the number 433577849, which is the required decimal representation.

Constraints:
1 ≤ s.size() ≤ 100

*/


#include <iostream>
#include <string>
using namespace std;

string printNumber(string& s) {
    // code here
    return "";
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = printNumber(s);

    cout << "Converted number: " << result << endl;

    return 0;
}
