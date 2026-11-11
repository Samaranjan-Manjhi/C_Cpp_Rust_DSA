/*

   Find frequency of each character in a string.
   Asked at: TCS, Wipro, Infosys

 */

#include <iostream>
//#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<pair<char, int>> frequency_of_each_char(const string& s)
{
     vector<pair<char, int>> out;
     //unordered_map<char, int> umap;
     map<char, int> umap;
     for(char ch : s)
     {
          umap[ch]++;
     }

     for(auto& r : umap)
     {
          out.push_back({r.first, r.second});
     }
     return out;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     vector<pair<char, int>> res = frequency_of_each_char(str);
     if(!res.empty())
     {
          for(auto s : res)
          {
               cout << "char:- " << s.first << " & count:- " << s.second << endl;
          }
     }

     return 0;
}
