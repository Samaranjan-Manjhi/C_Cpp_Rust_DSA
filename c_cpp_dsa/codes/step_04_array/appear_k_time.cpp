/*
   Print all elements that appear exactly K times in an array
   Asked at: Amazon, Flipkart
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<int> appear_k_time(const vector<int>& v, int k)
{
     vector<int> res;
     unordered_map<int, int> mp;
     unordered_set<int> s;
     for(int x : v)
          mp[x]++;
     bool found = false;
     for(int x : v)
     {
          if(mp[x] == k && s.find(x) == s.end())
          {
               res.push_back(x);
               s.insert(x);
          }
     }
     return res;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];
     int k;
     cout << "Enter k value: ";
     cin >> k;
     vector<int> res = appear_k_time(v, k);
     if(!res.empty())
          for(int x : res)
               cout << x << " ";
     cout << endl;
     return 0;
}
