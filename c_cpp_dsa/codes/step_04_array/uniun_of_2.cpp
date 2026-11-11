/*
   Find the union of two unsorted arrays (all unique elements)
   Asked at: Amazon, TCS, Wipro
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> union_2(const vector<int>& v1, const vector<int>& v2)
{
     unordered_set<int> s(v1.begin(), v1.end());
     s.insert(v2.begin(), v2.end());
     vector<int> res;
     for(auto& d : s)
          res.push_back(d);
     return res;
}
int main()
{
     vector<int> v{1, 2, 3, 4, 5, 6};
     vector<int> v1{3, 4, 5, 6, 7, 8, 9};
     vector<int> res = union_2(v, v1);
     for(int i=res.size()-1;i>=0;i--)
          cout << res[i] << " ";
     cout << endl;
     return 0;
}
