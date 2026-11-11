/*

   Convert string to uppercase / lowercase manually.
   (Without using toupper/tolower — use ASCII arithmetic too)
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>

using namespace std;

pair<string, string> convert_upper_lower_str(string& str)
{
     if(str.length() == 0)
          return {"", ""};
     string upper, lower;
     upper.reserve(str.size());
     lower.reserve(str.size());
     for(char ch : str)
     {
          if(ch >= 'a' && ch <= 'z') 
          {
               lower += ch;
               upper += (ch-32);
          }
          else if(ch >= 'A' && ch <= 'Z')
          {
               lower += (ch+32);
               upper += ch;
          }
          else
          {
               lower += ch;
               upper += ch;
          }
     }
     return {upper, lower};
}

int main()
{
     string s;
     cout << "Enter input String: ";
     getline(cin, s);

     pair<string, string> res = convert_upper_lower_str(s);
     cout << "String in upper case:- " << res.first << endl;
     cout << "String in lower case:- " << res.second << endl;

     return 0;
}
