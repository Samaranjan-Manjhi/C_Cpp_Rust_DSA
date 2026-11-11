/*

Last index of a character

Given a string s of size n and a character c, find the last index (0-based indexing) of c in s. If the character is not present, return -1. Both s and c contain only lowercase and uppercase English alphabets.

Examples:

Input: s = "Geeks", c = 'e'
Output: 2
Explanation: The last occurrence of 'e' is at index 2.

Input: s = "okiyh", c = 'z'
Output: -1
Explanation: The character 'z' is not present in the string.

Constraints:
1 ≤ n ≤ 105

*/


#include <iostream>
#include <string>
using namespace std;

int LastIndex(string &s, char c) 
{
     // code here
     for(int i=s.length()-1;i>=0;i--)
     {
          if(s[i] == c)
               return i;
     }
     return -1;
}

int main() {
    string s;
    char c;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter character to find: ";
    cin >> c;

    int result = LastIndex(s, c);

    cout << "Last index: " << result << endl;

    return 0;
}
