/*

   Remove Vowels

   Problem statement

   You are given a string STR of length N. Your task is to remove all the vowels present in that string and print the modified string.

   English alphabets ‘a’, ‘e’, ‘i’, ‘o’, ‘u’ are termed as vowels. All other alphabets are called consonants.

Note: You have to only remove vowels from the string. There will be no change in the relative position of all other alphabets.
For example:

(i)  If the input string is 'CodeGeek', the output should be CdGk after removing ‘o’ and ‘e’.

(ii) If the input string is 'Odinson', the output should be 'dnsn' after removing ‘o’ and ‘i’. 

Detailed explanation ( Input/output format, Notes, Images )
Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 10^4

STR may contain alphabets from 'a' to 'z' or 'A' to 'Z' and blank spaces.

Time Limit: 1 sec 

Sample Input 1:

2
Mobile
CodingNinjas

Sample Output 1:

Mbl
CdngNnjs

Explanation of Input 1:

(i) The output ‘Mbl’ is obtained after removing vowels ‘o’ and ‘i’ from second and fourth position respectively of given string ‘Mobile’.

(ii) The output ‘CdngNnjs’ is obtained after removing vowels ‘o’, ‘i’, ‘i’, and ‘a’ from second, fourth, eighth, and eleventh position respectively of given string ‘CodingNinjas’.

Sample Input 2:

3
B
aB
BcE

Sample Output 2

B
B
Bc

*/


#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch)
{
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		return true;

	return false;
}

string removeVowels(string inputString) 
{
	// Write your code here.
	string res = "";
	for(char ch : inputString)
	{
		if(!isVowel(ch))
			res += ch;
	}
	return res;
}

int main() {
	string inputString;

	cout << "Enter input string: ";
	//cin >> inputString;
	getline(cin, inputString);

	string result = removeVowels(inputString);

	cout << "Result: " << result << endl;

	return 0;
}
