/*
   Find if an array contains any duplicate element
   Asked at: Amazon, Microsoft, Adobe
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> dub_ele(const vector<int>& v)
{
     vector<int> res;
     unordered_map<int, int> us;
     for(int i=0;i<v.size();i++)
     {
          us[v[i]]++;
     }

     for(auto& mp : us)
     {
          //cout << mp.first << "    " << mp.second << endl;
          if(mp.second > 1)
          {
               res.push_back(mp.first);
          }
     }
     return res;
}

int main()
{
     int n, val;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     vector<int> out = dub_ele(v);
     if(out.size() < 1)
          return 0;
     else
     {
          cout << "Dublicate Elements are: ";
          for(int i=out.size()-1;i>=0;i--)
          {
               cout << out[i] << " ";
          }
          cout << endl;
     }
     return 0;
}
