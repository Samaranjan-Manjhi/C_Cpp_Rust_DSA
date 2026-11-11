/*

   Check if a given string has balanced parentheses (only one type ()).
   Use a counter (not stack).
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>

using namespace std;

bool is_balanced_parentheses(const string& s)
{
     int open = 0, close = 0;
     int n = s.length();
     if(n%2 != 0)
          return false;
     for(char ch : s)
     {
          if(ch == '(')
               open++;
          else
          {
               open--;
               if(open < 0)
                    return false;
          }
     }
     if(open > 0)
          return false;

     return true;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     bool res = is_balanced_parentheses(str);
     //cout << "Given Input parentheses str is balanced:- " << res << endl;
     if(res)
          cout << "Yes\n";
     else
          cout << "No\n";

     return 0;
}
