/*
   Find the product of all elements except itself without using division
Input: [1,2,3,4] -> Output: [24,12,8,6]
Asked at: Amazon, Microsoft, Google, Flipkart
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> product_all_not_self(const vector<int>& v)
{
     int n = v.size();
     vector<int> res = v;
     vector<int> prefix_pro(n, 0);
     prefix_pro[0] = 1;
     for(int i=1;i<res.size();i++)
          prefix_pro[i] = prefix_pro[i-1] * v[i-1];
     //for(int p : prefix_pro)
     //     cout << p << " ";
     //cout << endl;

     int right = 1;
     for(int i=n-1;i>=0;--i)
     {
          prefix_pro[i] *= right;
          right *= v[i];
     }
     return prefix_pro;
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
     vector<int> res = product_all_not_self(v);
     if(!res.empty())
          for(int x : res)
               cout << x << " ";
     cout << endl;
     return 0;
}
