/*
   Check if an array can be divided into pairs with equal sum
   Asked at: TCS, Amazon
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_divide_into_2_parts(const vector<int>& v)
{
     /* // Partition equal sum
     int n = v.size();
     vector<int> prefix_sum(n, 0);
     prefix_sum[0] = v[0];
     for(int i=1;i<n;i++)
          prefix_sum[i] = prefix_sum[i-1]+v[i];
     if(prefix_sum[prefix_sum.size()-1]%2 != 0)
          return false;
     for(int i=0;i<prefix_sum.size();i++)
     {
          if(prefix_sum[i] == prefix_sum[prefix_sum.size()-1]/2)
          {
               return true;
          }
     }
     return false;
     */

     // Pair equal sum
     int n = v.size();
     int tar = v[0] + v[n-1];
     int l = 1, r = n-2;
     while(l < r)
     {
          if(v[l]+v[r] != tar)
               return false;
          else
          {
               l++;
               r--;
          }
     }
     return true;
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
     sort(v.begin(), v.end());
     bool res = is_divide_into_2_parts(v);
     if(res)
          cout << "Yes" << endl;
     else
          cout << "No" << endl;
     return 0;
}
