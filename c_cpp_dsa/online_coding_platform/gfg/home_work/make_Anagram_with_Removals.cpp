/*

Make Anagram with Removals

Given two strings s1 and s2 in lowercase, the task is to make them anagrams. The only allowed operation is to remove a character from any string.

Find the minimum number of characters to be deleted to make both the strings anagram.

Two strings are called anagrams of each other if one of them can be converted into another by rearranging its letters.

Examples:

Input: s1 = "bcadeh", s2 = "hea"
Output: 3
Explanation: We need to remove b, c and d from s1. Therefore answer of this test case is 3.

Input: s1 = "cddgk", s2 = "gcd"
Output: 2
Explanation: We need to remove d and k from s1. Therefore answer of this test case is 2.

Constraints:
1 ≤ |s1|, |s2| ≤ 105

*/


#include <iostream>
#include <string>
using namespace std;

int remAnagram(string &s1, string &s2) {
    // code here
    return 0;
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int result = remAnagram(s1, s2);

    cout << "Minimum characters to remove: " << result << endl;

    return 0;
}
