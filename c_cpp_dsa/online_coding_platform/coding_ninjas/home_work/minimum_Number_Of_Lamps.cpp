/*

Minimum Number Of Lamps

 Problem statement

You are given a string 'S' containing dots(.) and asterisks(*) only, where the dot represents free spaces, and the asterisk denotes lamps. A lamp can lighten up its own cell as well as its immediate neighboring cells. You need to determine the minimum number of extra lamps that have to be installed at some free spaces in the string so that the whole string will be illuminated i.e. all the indices of the string can have access to the light of some lamp.
Note :

If a lamp is present at index 'I', then it illuminates index 'I' - 1, 'I' and 'I' + 1.

If a lamp is present at index 0, then it illuminates only 0 and 1.

Given that the length of the string is greater than or equal to 2.

If a lamp is present at the last index, then it illuminates the last and the second last index, given that the length of the string is greater than or equal to 2.

The length of each string is guaranteed to be at least 1.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:

 1 <= 'T' <= 100
 1 <= |'S'| <= 5 * 10 ^ 4

Where 'T' is the number of test cases, and |'S'| denotes the length of the string.

Time limit: 1 sec.

Sample Input 1:

1
……

Sample Output 1:

2

Explanation of Sample Input 1:

For the given string, since no lamps are installed initially if we install one lamp at index 2, it will light up indices 1,2,3 and another lamp at index 5, it will light up index 4, 5, 6. Hence the answer is 2.

Sample Input 2:

3
*.
.*
*.*..   

Sample Output 2:

0
0
1

Explanation of Sample Input 2

For the first and second test case, we don’t need to install any lamp, as they will be illuminated by their neighbouring cells.
For the third test case, indices from 1 to 4 will be illuminated. We only need to install one lamp at index 5. Hence the answer is 1.

*/


#include <iostream>
#include <string>

using namespace std;

int findMinimumLamps(string s)
{
    // Write your code here.

    return 0;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = findMinimumLamps(s);

    cout << "Minimum lamps required: " << result << endl;

    return 0;
}
