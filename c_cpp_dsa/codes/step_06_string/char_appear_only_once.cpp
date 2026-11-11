/*

   Given string, print all characters in it that appear exactly once.
   Asked at: TCS, Wipro, Amazon

 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<char> char_appear_only_once(const string& s)
{
     map<char, int> mp;
     vector<char> res;
     for(char ch : s)
          mp[ch]++;

     for(char ch : s)
     {
          if(mp[ch] == 1)
               res.push_back(ch); 
     }
     return res;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     vector<char> res = char_appear_only_once(str);
     if(!res.empty())
     {
          cout << "Result:-  ";
          for(char r : res)
          {
               cout << r << " ";
          }
          cout << endl;
     }

     return 0;
}
