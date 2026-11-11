/*

   Snake Case

   Given a sentence s consisting of English alphabet characters and spaces, convert it into snake_case.

   In snake case:
   All letters are converted to lowercase.
   Words are separated by a single underscore ('_') instead of spaces.
   No spaces should appear in the resulting string.

   Return the snake_case representation of the given sentence.
Note: The input sentence does not begin with a whitespace character.

Examples:

Input: s = "Geeks ForGeeks"
Output: "geeks_forgeeks"
Explanation: All upper case characters are converted to lower case and the whitespace characters are replaced with underscore '_'.

Input: s = "Here comes the garden"
Output: "here_comes_the_garden"
Explanation: All upper case characters are converted to lower case and the whitespace characters are replaced with underscore '_'.

Constraints:
1 ≤ n ≤ 105, n is length of the sentence

 */


#include <iostream>
#include <string>

using namespace std;

string snakeCase(string &s) 
{
     // code here
     string res = "";
     for(char c : s)
     {
          if(c == ' ')
               res += '_';
          else if(c >= 'A' && c <= 'Z')
               res += c + 32;
          else
               res += c;
     }   

     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     string res = snakeCase(s);
     cout << "     Result:- " << res << endl;

     return 0;
}
