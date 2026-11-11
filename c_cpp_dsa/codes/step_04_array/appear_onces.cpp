/*
   Count occurrences of each element and print only those appearing once
   Asked at: TCS, Wipro, Amazon
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> appear_onces(const vector<int>& v)
{
     vector<int> ans;
     unordered_map<int, int> mp;
     for(int d : v)
          mp[d]++;
     for(int d : v)
     {
          //cout << m.first << "  " << m.second << endl;
          if(mp[d] == 1)
               ans.push_back(d);
     }
     return ans;
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
     vector<int> res = appear_onces(v);
     for(int i : res)
          cout << i << " ";
     cout << endl;
     return 0;
}
