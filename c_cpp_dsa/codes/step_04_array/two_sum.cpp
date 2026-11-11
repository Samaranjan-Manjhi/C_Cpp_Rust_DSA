/*
   Two Sum — find pair with given target sum (brute force then hashmap)
   Asked at: Amazon, Microsoft, Google, Adobe, Flipkart
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> two_sum(const vector<int>& v, int t)
{
     vector<pair<int, int>> out;
     unordered_map<int, int> freq;
     for(int x : v)
     {
          int need = t-x;
          if(freq[need] > 0)
          {
               out.push_back({need, x});
               freq[need]--;
          }     
          else
               freq[x]++;
     }
     return out;
}

void print(vector<int> v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
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
     cout << "Enter Target: ";
     cin >> tar;
     //print(v);
     vector<pair<int, int>> res = two_sum(v, tar);
     for(int i=0;i<res.size();i++)
     {
          cout << res[i].first << "  " << res[i].second << endl;
     }
     return 0;
}
