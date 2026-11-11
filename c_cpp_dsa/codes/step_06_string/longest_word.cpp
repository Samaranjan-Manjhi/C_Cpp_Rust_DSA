/*

   Find the longest word in a sentence.
   Asked at: TCS, Wipro, Zoho

 */

#include <iostream>
#include <string>
using namespace std;

string longest_word_in_string(const string& s)
{
     string res = "";
     string out = "";
     for(char ch : s)
     {
          if(ch != ' ')
          {
               res += ch;         
          }
          else
          {
               if(out.length() < res.length())
                    out = res;
               res = "";
          }
     }
     if(out.length() < res.length())
          out = res;
     return out;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     string res = longest_word_in_string(str);
     cout << "Result:-   " << res << endl;

     return 0;
}
