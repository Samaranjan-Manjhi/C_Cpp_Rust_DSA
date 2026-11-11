/*
   Find all pairs in an array with a given difference
   Asked at: Amazon, Zoho
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> equal_diff(const vector<int>& v, int diff)
{
     vector<pair<int, int>> res;
     if(diff < 0)   
          return res;

     if(diff == 0)
     {
          unordered_map<int, int> freq;
          for(int x : v) freq[x]++;
          for(auto& p:freq)
          {
               if(p.second > 1)
                    res.push_back({p.first, p.first});
          }
          return res;
     }

     unordered_set<int> s(v.begin(), v.end());
     for(int x : s)
     {
          if(s.count(x+diff))
               res.push_back({x,x+diff});
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
     int tar;
     cout << "Enter Difference: ";
     cin >> tar;
     vector<pair<int, int>> res = equal_diff(v, tar);
     for(int i=0;i<res.size();i++)
     {
          cout << res[i].first << "   " << res[i].second << endl;
     }
     cout << endl;
     return 0;
}
