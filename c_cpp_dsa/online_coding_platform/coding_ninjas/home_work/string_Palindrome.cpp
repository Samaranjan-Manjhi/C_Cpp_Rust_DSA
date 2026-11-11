/*

   String Palindrome 

   Problem statement

   Given a string, determine if it is a palindrome, considering only alphanumeric characters.
   Palindrome

   A palindrome is a word, number, phrase, or other sequences of characters which read the same backwards and forwards.

Example:
If the input string happens to be, "malayalam" then as we see that this word can be read the same as forward and backwards, it is said to be a valid palindrome.
The expected output for this example will print, 'true'.
From that being said, you are required to return a boolean value from the function that has been asked to implement.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.
Time Limit: 1 second

Sample Input 1 :
abcdcba
Sample Output 1 :
true 

Sample Input 2:
coding
Sample Output 2:
false

 */

#include <iostream>
#include <cstring>

using namespace std;

bool checkPalindrome(char str[]) 
{
     // Write your code here
     int len = strlen(str);
     int l = 0, r = len-1;
     while(l < r)
     {
          if(str[l] == str[r])
          {
               l++;
               r--;
          }
          else
          {
               return false;
          }
     }
     return true;
}

int main()
{
     int n;
     cout << "Enter size of string: ";
     cin >> n;

     char str[n+1];
     cin >> str;

     bool res = checkPalindrome(str);
     if(res)
          cout << "     Yes\n";
     else
          cout << "     Nope\n";

     return 0;
}
