/*

   Remove duplicate characters from a string (keep first occurrence).
   Asked at: Amazon, Zoho

 */

#include <iostream>
#include <string>

using namespace std;

string remove_dub_char_from_str(const string& s)
{
     bool seen[256] = {false};
     string res = "";
     for(char ch : s)
     {
          int idx = ch - 'a';
          if(!seen[(unsigned char)idx])
          {
               seen[(unsigned char)idx] = true;
               res += ch;
          }
     } 
     return res;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     string res = remove_dub_char_from_str(str);
     cout << "Result:-  " << res << endl;

     return 0;
}
