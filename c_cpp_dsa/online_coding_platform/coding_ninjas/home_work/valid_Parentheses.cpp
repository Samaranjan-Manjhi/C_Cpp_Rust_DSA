/*

   Valid Parentheses 

   Problem statement

   You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .
   Return true if the given string 'S' is balanced, else return false.

   For example:
   'S' = "{}()".
   There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
   So the 'S' is Balanced.

   Sample Input 1 :
   [()]{}{[()()]()}
   Sample Output 1 :
   Balanced
   Explanation Of the Sample Input 1 :
   There is always an opening brace before a closing brace i.e. '{' before '}', '(' before '), '[' before ']'.
   So the 'S' is Balanced.

   Sample Input 2 :
   [[}[
   Sample Output 2 :
   Not Balanced

Constraints:
1 <= 'N' <= 10^5
Where 'N' is the length of the input string 'S'.
Time Limit: 1 sec

 */

#include <iostream>
#include <string>
#include <stack> 

using namespace std;

bool isValidParenthesis(string s)
{
     // Write your code here.
     stack<char> st;
     for(char ch : s)
     {
          if((ch == '{' || ch == '(' || ch == '['))
               st.push(ch);
          else
          {
               if(!st.empty())
               {
                    if(ch == '}' && st.top() != '{')
                    {
                         return false;
                    }   
                    else if(ch == ')' && st.top() != '(')
                    {
                         return false;
                    }
                    else if(ch == ']' && st.top() != '[')
                    {
                         return false;
                    }
                    else
                    {
                         st.pop();
                    }
               }
               else
               {
                    return false;
               }
          }
     }
     if(!st.empty())
          return false;
     return true;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     bool res = isValidParenthesis(str);
     if(res)
          cout << "  Balanced\n";
     else
          cout << "  Not Balanced\n";

     return 0;
}
