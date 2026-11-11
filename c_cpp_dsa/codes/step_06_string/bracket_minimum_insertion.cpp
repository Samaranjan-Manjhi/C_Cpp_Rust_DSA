/*

   Given a string of brackets, find the minimum insertions to make it valid.
   (Count unmatched '(' and ')' using a counter — not a stack)
   Asked at: Amazon, Microsoft

 */

#include <iostream>
#include <string>

using namespace std;

int minimum_brackets_insertions(const string& s)
{
     if(s.length() == 0)
          return 0;
     int open = 0, close = 0;
     for(char ch : s)
     {
          if(ch == '(')
               open++;
          else if(ch == ')')
          {
               if(open > 0)
               {
                    open--;
               }
               else
               {
                    close++;
               }
          }    
     }
     return close+open;
}

int main()
{
     string str;
     cout << "Enter Input Brackets String: ";
     cin >> str;

     int res = minimum_brackets_insertions(str);
     cout << "Result:- " << res << endl;

     return 0;
}
