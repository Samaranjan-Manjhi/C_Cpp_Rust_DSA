/*

   Problem statement

   You are given a string of length N representing the . You have to convert this code into the corresponding alphanumeric code containing small case english alphabet[a-z] and digits[0-9].

   For your convenience, the full table for the 26 letters of the English alphabet and 10 numeric digits is given below:
   list = [ ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." ]      
   where list[0] represents morse code for ‘a’, list[1] represents morse code for ‘b’, and list[35] represents morse code for ‘9’. Similarly, each letter and numeric is mapped with a morse code given in the list.               

Constraints:
1 <= T <= 10
1 <= N <= 5*(10^5)
Time Limit: 1sec

Sample Input 1 :
2
-.-. --- -.. .. -. --.
-. .. -. .--- .- ...
Sample Output 1 :
coding
ninjas
Explanation For Sample Input 1 :
In the first test case, On splitting the given string on the basis of space the list we get is :  [ "-.-.", "---", "-..", "..",  "-.", "--." ] where “-.-.” is morse code for ‘c’ and similarly further in the string.
In the second case, On splitting the given string on the basis of space the list we get is : [ "-.", "..", "-.", ".---", ".-", "..." ], where “-.” is morse code for ‘n’ and similarly further in the string.

Sample Input 2 :
2
----. ---.. ....- ..... ----- 
-.. .... --- -. .. --... --...
Sample Output 2 :
98450
dhoni77

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string morseToEnglish(string morsecode) 
{
     // Write your code here
     vector<string> list = {
          ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
          "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
          "..-", "...-", ".--", "-..-", "-.--", "--..",
          "-----", ".----", "..---", "...--", "....-", ".....",
          "-....", "--...", "---..", "----."
     };

     string str = "";
     string temp = "";

     for(char ch : morsecode)
     {
          if(ch == ' ')
          {
               auto it = find(list.begin(), list.end(), temp);
               if(it != list.end())
               {
                    int pos = distance(list.begin(), it);
                    if(pos < 26)
                         str += char('a' + pos);
                    else
                         str += char('0' + (pos - 26));
               }
               temp = "";
          }
          else
          {
               temp += ch;
          }
     }
     // last word
     if(temp != "")
     {
          auto it = find(list.begin(), list.end(), temp);
          if(it != list.end())
          {
               int pos = distance(list.begin(), it);
               if(pos < 26)
                    str += char('a' + pos);
               else
                    str += char('0' + (pos - 26));
          }
     }
     return str;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     string res = morseToEnglish(str);
     cout << "Result String:- " << res << endl;

     return 0;
}
