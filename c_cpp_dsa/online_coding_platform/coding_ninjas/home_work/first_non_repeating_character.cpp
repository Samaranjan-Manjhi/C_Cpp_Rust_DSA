/*

   First non repeating character

   Problem statement

   Ninja is now bored with numbers and is now playing with characters but hates when he gets repeated characters. Ninja is provided a string, and he wants to return the first unique character in the string.The string will contain characters only from the English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character, print the first character of the string. If there is no non-repeating character, return the first character of the string.

Constraints:
1 <= T <= 10
1 <= Length of Input String <= 10^4
Time Limit: 1 sec 

Sample Input 1 :
2
aDcadhc
AabBcC
Sample Output 1:
D
A

Explanation for Sample Input 1:
In the first test case, ‘a’ is repeated.’ D’ is the first non-repeating character in the string, so we return it.
In the second test case, all the characters are non-repeating, so we return the first character.

Sample Input 2 :
2
ABcd
AAAbcdb
Sample Output 2:
A
c 

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

char firstNonRepeatingCharacter(string str) 
{
     // Write your code here
     vector<char> freq(256, 0);
     for(char ch : str)
     {
          freq[ch]++;
     }
     char c = '\0';
     for(char ch : str)
     {
          if(freq[ch] == 1)
          {
               c = ch;
               break;
          }
     }
     if(c == '\0')
          c = str[0];

     return c;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     char ch = firstNonRepeatingCharacter(str);
     cout << "    Result:- " << ch << endl;

     return 0;
}
