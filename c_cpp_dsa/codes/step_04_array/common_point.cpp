/*
   Find the intersection of two unsorted arrays (common elements)
   Asked at: Amazon, TCS
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int common_ele(const vector<int>& v, const vector<int>& v1)
{
     unordered_set<int> s(v.begin(), v.end());
     for(int n : v1)
     {
          if(s.find(n) != s.end())
               return n;
     }
     return -1;
     // Works but not efficent
     /* 
        for(int i=0;i<v.size();i++)
        {
        int l = 0, r = v1.size()-1;
        while(l <= r)
        {
        if(v[i] == v1[l] || v[i] == v1[r])
        return v[i];
        else if(v[i] != v1[l])
        l++;
        else if(v[i] != v1[r])
        r--;
        }
        }
        return -1;
      */
}
int main()
{
     vector<int> v{3, 2, 5, 7, 1};
     vector<int> v1{4, 1, 0, 6, 9};
     cout << "Result:- " << common_ele(v, v1) << endl;
     return 0;
}
