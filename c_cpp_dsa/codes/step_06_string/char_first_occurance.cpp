/*

   Find position (index) of first occurrence of a character in a string.
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>

using namespace std;

pair<char, int> char_first_occurance_in_str(const string& s)
{
     //int j = 0;
     for(int i=0;i<s.length();i++)
     {
          int j = 0;
          char ch = s[i];
          while(j < s.length())
          {
               if(i == j)     j++;
               if(j < s.length() && ch == s[j])
               {
                    //cout << "j: " << j  << "  char:  " << s[i] << endl;
                    return {s[i], j};
               }
               j++;
          }
     }
     return {'\0', -1};
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     pair<char, int> res = char_first_occurance_in_str(str);
     cout << "First char " << res.first << " occuranse at index:- " << res.second << endl;

     return 0;
}
