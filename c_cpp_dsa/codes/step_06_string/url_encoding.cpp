/*

   Replace all spaces in a string with '%20' (URL encoding).
   Asked at: Amazon, Microsoft

 */

#include <iostream>
#include <string>

using namespace std;

// Using another string
string replace_space_by_encode(string& s)
{
     string res;
     for(char ch : s)
     {
          if(ch == ' ')
          {
               res += "%20";
          }
          else
          {
               res += ch;
          }
     }
     return res;
}

// Without another string
string replace_space_by_encode1(string& s)
{
     int spaces = 0;
     for(char ch : s)
     {
          if(ch == ' ')
               spaces++;
     }

     int origLen = s.length();
     int newLen = origLen + spaces*2;

     s.resize(newLen);

     int i = origLen - 1;
     int j = newLen - 1;

     while(i >= 0)
     {
          if(s[i] == ' ')
          {
               s[j--] = '0';
               s[j--] = '2';
               s[j--] = '%';
          }
          else
          {
               s[j--] = s[i];
          }
          i--;
     }
     return s;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     string res1 = replace_space_by_encode1(str);
     cout << "Without using another string variable Result:--   " << res1 << endl;
     string res = replace_space_by_encode(str);
     cout << "Using another string Result:--   " << res << endl;

     return 0;
}
