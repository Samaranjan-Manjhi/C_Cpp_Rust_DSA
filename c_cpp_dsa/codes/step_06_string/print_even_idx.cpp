/*

   Print all characters at even index positions of a string.
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> even_idx_char(string& s)
{
     vector<char> ans;
     if(s.empty()) return ans;
     for(int i=0;i<s.length();i+=2)
     {
          ans.push_back(s[i]);
     }
     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     vector<char> res = even_idx_char(str);
     if(res.size() != 0)
          for(char ch : res)
               cout << ch << " ";
     cout << endl;

     return 0;
}
