/*
 
 Periodic String

 Problem statement
Given a string ‘S’ find whether the given string is periodic or not.

A string is said to be periodic if it repeats itself after a certain number of characters and the period of repetition is less than the size of the string.

For example: Let ‘S’ be “ababab” we can clearly see that this string is periodic as ‘ab’ is repeated 3 times to make the string ‘S’.

Constraints:
1 <= T <= 50
1<= S.length<=10^5

Where 'S.length' denotes the length of string ‘S’.
The given string consists of lowercase English alphabets only.

Time limit: 1 sec
Sample Input 1:
3
xxxxxx
aabbaaabba
abcba
Sample Output 1:
True
True
False
Explanation of sample input 1 :
Test Case 1:
In the first test case, we can clearly see that the string has a repeating string ‘x’ 6 times. So we return true

Test Case 2:

In the second test case, we can see that the string ‘aabba’ repeats twice to form the given string. Hence we return true,

Test Case 3:

In the third test case, we can see that there is no string which repeats itself to form the given string, hence we return false.
Sample Input 2:
2
vwvnqpnchqik
ubzumubzumubzumubzum
Sample Output 2:
False
True
 
 */


#include <iostream>
#include <string>

using namespace std;

bool isPeriodic(string s) 
{
	string str = s;
	str += s;
	int n = str.length();
	string res = "";
	for(int i = 1; i < n - 1; i++)
		res += str[i];

	if(res.find(s) != string::npos)
		return true;

	return false;
}

int main() 
{
	string s;

	cout << "Enter the string to check: ";
	cin >> s;

	if(isPeriodic(s)) 
	{
		cout << "The string is periodic." << endl;
	} 
	else 
	{
		cout << "The string is not periodic." << endl;
	}

	return 0;
}
