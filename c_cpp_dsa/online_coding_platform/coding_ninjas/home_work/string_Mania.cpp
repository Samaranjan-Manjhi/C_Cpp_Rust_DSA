/*

String Mania 

 Problem statement

Rohit love strings. But he has many strings with him, and he is confused about which one he loves more. So he decided to come up with a scoring system for the strings. The scoring system took two strings as input, let's call them ‘STR1’ and ‘STR2’ of length ‘N’ and length ‘M’ respectively.

The system will return ‘1’ if ‘STR1’ is better than ‘STR2’.

The system will return ‘0’ if ‘STR1’ is the same as ‘STR2’.

The system will return ‘-1’ if ‘STR2’ is better than ‘STR1’.

To decide which string is better he followed the below steps.

Let’s suppose there exists a index ‘i’ such that ‘0’ <= ‘i’ < ‘min(N,M)’ and for all ‘j<i’, ‘STR1[j]’ is equal to ‘STR2[j]’, and ‘STR1[i] != STR2[i]’.

Then if ‘STR1[i]>STR2[i]’, ‘STR1’ is better otherwise if ‘STR2[i]>STR1[i]’, ‘STR2’ is better,

And if there doesn’t exist any such ‘i’ then if ‘N>M’, ‘STR1’ is better,

And if ‘N<M’, ‘STR2’ is better, and if ‘N’ is equal to ‘M’, both strings are the same.

But Rohit has so many strings, so he doesn’t have time to go through all strings, So being his friend can you help him automate this process?.
EXAMPLE :

Input: ‘N’ = 3, ‘M’ = 4, ‘STR1’ = xyz, ‘STR2’ = abcd

Output: 1
In this case, ‘STR1[0]>STR2[0]’ hence ‘STR1’ is better than ‘STR2’. Hence the output will be ‘1’. 

Detailed explanation ( Input/output format, Notes, Images )
Constraints :

1 <= ‘T’ <= 10
1 <= ‘N’ <= 10^5
1 <= ‘M’ <= 10^5
‘STR1’ and ‘STR2’ consists of lowercase letters.
It is guaranteed that sum of ‘N’ over all test cases is <= 10^5
It is guaranteed that sum of ‘M’ over all test cases is <= 10^5
Time Limit: 1 sec

Sample Input 1 :

2
1 3
a
abc
3 3
abz
abc

Sample Output 1 :

-1
1

Explanation Of Sample Input 1 :

For the first test case, ‘STR2’ is better than ‘STR1’, as they are the same until the ‘0th’ index and then string ‘STR1’ ends and as explained in the statement for ‘M>N’, the answer is ‘-1’.

Hence, the output will be: -1

For the second test case, ‘STR1’ is better than ‘STR2’, as they are the same until the ‘1st’ index and then ‘STR1[2]>STR2[2]’.

Hence, the output will be: 1

Sample Input 2 :

3
2 3
ez
ehz
5 5
acefi
acefi
3 5
ags
agtaa

Sample Output 2 :

1
0
-1

*/


#include <iostream>
#include <string>

using namespace std;

int stringMania(int n, int m, string str1, string str2) {
    // Write your code here
    
    return 0;
}

int main() {
    int n, m;
    string str1, str2;

    cin >> n >> m;
    cin >> str1 >> str2;

    int result = stringMania(n, m, str1, str2);

    cout << result;

    return 0;
}
