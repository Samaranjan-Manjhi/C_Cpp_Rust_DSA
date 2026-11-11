/*

1-3 Palindrome

 Problem statement

You are given a string 'S'. You perform the following operations:

1. Split 'S' into three non-empty substrings such that each character of 'S' should present in exactly one substring.
2. Create a new string by concatenating 1st and 3rd parts.

Return 1 if you can make this new string a palindrome otherwise return 0.
For Example:-

Let 'N' = 6, 'S' = "abccba".
Three substrings are "ab", "cc", and "ba" and by concatenating 1st and 3rd parts we get "abba" which is a palindrome.
So our answer is 1.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:-

1 <= 'T' <= 10
3 <= 'N' <= 10^5
'S' consists of 'N' lowercase English letters.

The Sum of 'N' overall test cases does not exceed 10^5.
Time Limit: 1 sec

Sample Input 1:-

2
4
abcd
5
zzzzz   

Sample Output 1:-

0
1

Explanation of sample input 1:-

First test case:-
It can be proven that we cannot make the new string a palindrome.
So our answer is 0.

Second test case:-
Three substrings are "zzz", "z", and "z" and by concatenating 1st and 3rd parts we get "zzzz" which is a palindrome.
So our answer is 1.

Sample Input 2:-

2
4
abca
3
xyz

Sample Output 2:-

1
0

*/


#include <iostream>
#include <string>

using namespace std;

int palindrome13(string s) {
    // Write your code here

    return 0;
}

int main() {
    string s;

    cin >> s;

    int result = palindrome13(s);

    cout << result;

    return 0;
}
