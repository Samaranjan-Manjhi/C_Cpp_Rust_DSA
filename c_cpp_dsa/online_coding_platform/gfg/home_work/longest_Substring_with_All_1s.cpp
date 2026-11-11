/*

Longest Substring with All 1's

Given a binary string s. Return the length of the longest substring containing only ‘1’.

Examples:

Input: s = "110"
Output: 2
Explanation: "11" is the longest substring containing only 1's. 

Input: s = "11101110"
Output: 3
Explanation: "111" is the longest substring containing only 1's.

Constraints: 
1 ≤ |s| ≤ 105

*/


#include <iostream>
#include <string>
using namespace std;

int longestSubstring(string &s) {
    // code here
    return 0;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = longestSubstring(s);

    cout << "Length of longest substring: " << result << endl;

    return 0;
}
