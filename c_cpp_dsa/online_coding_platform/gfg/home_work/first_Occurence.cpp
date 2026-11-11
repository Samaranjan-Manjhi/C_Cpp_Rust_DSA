/*

First Occurence

Given two strings txt and pat, return the 0-based index of the first occurrence of the substring pat in txt. If pat is not found, return -1.
Note: You are not allowed to use the inbuilt function.

Examples :

Input: txt = "GeeksForGeeks", pat = "Fr"
Output: -1
Explanation: "Fr" is not present in the string "GeeksForGeeks" as substring.

Input: txt = "GeeksForGeeks", pat = "For"
Output: 5
Explanation: "For" is present as substring in "GeeksForGeeks" from index 5 (0 based indexing).

Input: txt = "GeeksForGeeks", pat = "gr"
Output: -1
Explanation: "gr" is not present in the string "GeeksForGeeks" as substring.

Constraints:
1 ≤ txt.size(),pat.size() ≤ 1000

*/


#include <iostream>
#include <string>
using namespace std;

int firstOccurence(string& txt, string& pat) 
{
    // code here
    return -1;
}

int main() 
{
    string txt, pat;

    cout << "Enter text: ";
    cin >> txt;

    cout << "Enter pattern: ";
    cin >> pat;

    int result = firstOccurence(txt, pat);

    cout << "First occurrence index: " << result << endl;

    return 0;
}
