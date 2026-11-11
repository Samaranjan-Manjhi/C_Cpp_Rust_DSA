/*
   Find the only element that appears once when every other appears thrice
Hint: count bits at each position mod 3
Asked at: Amazon, Adobe, Samsung
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int appear_once(vector<int>& v)
{
     unordered_map<int, int> mp;
     for(int x : v)
          mp[x]++;
     for(auto& m : mp)
     {
          if(m.second == 1)
               return m.first;
     }
     return -1;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int>v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = appear_once(v);
     cout << "Result:- " << res << endl;

     return 0;
}
