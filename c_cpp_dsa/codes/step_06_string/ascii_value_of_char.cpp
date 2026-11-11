/*

   Find the ASCII value of each character in a string.
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> char_to_ascii_cast(string& s)
{
     vector<int> ans;
     for(char ch : s)
     {
          int x = ch;
          ans.push_back(x);
     }
     return ans;
}

vector<int> char_to_ascii_offset(string& s) 
{
     vector<int> ans;
     for(char ch : s) 
     {
          int ascii;
          if(ch >= 'A' && ch <= 'Z')
               ascii = 'A' + (ch - 'A');  // effectively same as ch
          else if(ch >= 'a' && ch <= 'z')
               ascii = 'a' + (ch - 'a');
          else
               ascii = ch; // digits or symbols
          ans.push_back(ascii);
     }
     return ans;
}

vector<int> char_to_ascii_pointer(string& s) 
{
     vector<int> ans;
     char* p = &s[0];  // pointer to first character
     for(int i = 0; i < s.length(); i++) 
     {
          ans.push_back(*(p + i));  // dereference pointer
     }
     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     vector<int> res = char_to_ascii_cast(str);
     for(int x : res)
     {
          cout << x << " ";
     }
     cout << endl;

     return 0;
}
