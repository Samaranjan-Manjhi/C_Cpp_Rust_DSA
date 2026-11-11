/*
   Find the equilibrium index: index where sum of left = sum of right
   Asked at: Amazon, Adobe, Zoho
 */

#include <iostream>
#include  <vector>
using namespace std;
int equilibrium_idx(const vector<int>& v)
{
     int n = v.size();
     vector<int> prefix_sum(n, 0);
     prefix_sum[0] = v[0];
     for(int i=1;i<n;i++)
     {
          prefix_sum[i] = prefix_sum[i-1]+v[i];
     }
     if(prefix_sum[n-1]%2 != 0)
          return -1;
     else
     {
          for(int i=0;i<n;i++)
          {
               //cout << " Ans:-  " <<prefix_sum[i] << "              " << i << endl;
               if(prefix_sum[n-1]/2 == v[i])
               {
                    return i-1;
                    break;
               }
          }
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
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];
     cout << "Equilibrium Index:- " << equilibrium_idx(v) << endl;
     return 0;
}
