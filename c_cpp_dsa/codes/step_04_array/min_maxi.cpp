/*
   Find maximum and minimum element in an array
   Asked at: TCS, Wipro, Infosys, Capgemini
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> maxi_mini(vector<int>& v)
{
     int maxi = v[0], mini = v[0];
     for(int i=1;i<v.size();i++)
     {
          if(v[i] > maxi)
               maxi = v[i];
          if(v[i] < mini)
               mini = v[i];
     }
     return {maxi, mini};
}
int main()
{
     int n, val;
     cout << "Enter size of vector: ";
     cin >> n;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     pair<int, int> res = maxi_mini(v);
     cout << "Maximum Value:- " << res.first << "  & Minimum Value:- " << res.second << endl;
     return 0;
}
