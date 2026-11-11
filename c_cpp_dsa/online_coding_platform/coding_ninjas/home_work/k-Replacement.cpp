/*

K-Replacement 

 Problem statement

Bob is a student and learned about alphabets and prime numbers today. He still sometimes gets confused between normal numbers and prime numbers. So his teacher thought of giving him a fun game that can help him to get confident in this topic.

The game was, there is string ‘STR’ of length ‘N’ which includes alphabets and digits. There is also a special character ‘K’. The game was to replace every prime number that occurred in the string ‘STR’ with ‘K’.

Bob has solved the task and finished the game, but he still has doubt that the final string he got after the replacement is correct. So being his friend he asked you to help him with it.

So your task is to play the same game and return the correct final string after replacement.

NOTE: 1 is neither prime nor composite.
EXAMPLE :

Input: ‘N’ = 8, 'K' = ?, ‘STR’ = A12a3CbB

Output: A1?a?CbB
In this case, the numbers are ‘1’, ‘2’, and ‘3’ at ‘2nd’, ‘3rd’, and ‘5th’ positions respectively (1-based indexing). But only ‘2’ and ‘3’ are prime numbers, So after replacing them with ‘K’ the final string will be “A1?a?CbB”.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :

1 <= ‘T’ <= 10
1 <= ‘N’ <= 10^5
‘K’ is a lower-case or upper-case English letter or any special character like ‘#’, ‘?’, ‘%’, ‘@’, ‘(’ and ‘)’.
‘STR’ consists of lower-case or uppercase letters or digits.
It is guaranteed that sum of ‘N’ over all test cases is <= 10^5
Time Limit: 1 sec

Sample Input 1 :

2
3 ?
1a2
6 %
Ax1yB3

Sample Output 1 :

1a?
Ax1yB%

Explanation Of Sample Input 1 :

For the first test case, the numbers are at the ‘1st’ and ‘3rd’ positions. But only ‘2’ is prime. Hence the final string after the replacement is “1a?”.

Hence, the output will be: 1a?

For the second test case, the numbers are at the ‘3rd’ and ‘6th’ positions respectively.  But only ‘3’ is prime. Hence the final string after the replacement is “Ax1yB%”.

Hence, the output will be: Ax1yB%

Sample Input 2 :

2
7 #
AbcDFgx
10 (
0123456789

Sample Output 2 :

AbcDFgx
01((4(6(89

*/


#include <iostream>
#include <string>
using namespace std;

string kReplacement(int n, char k, string str) {
    // Write your code here.
    return "";
}

int main() {
    int n;
    char k;
    string str;

    cout << "Enter value of n: ";
    cin >> n;

    cout << "Enter character k: ";
    cin >> k;

    cout << "Enter string: ";
    cin >> str;

    string result = kReplacement(n, k, str);

    cout << "Result: " << result << endl;

    return 0;
}
