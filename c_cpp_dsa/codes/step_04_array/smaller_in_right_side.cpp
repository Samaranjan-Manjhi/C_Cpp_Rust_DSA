/*
   Count elements smaller than the current element to its right
   (brute force O(N^2) first)
   Asked at: Flipkart, Amazon
 */

#include <iostream>
#include <vector>
using namespace std;
void count_small(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
     {
          int cnt = 0;
          for(int j=i+1;j<v.size();j++)
          {
               if(v[i] > v[j])
               {
                    cnt++;
               }
          }
          cout << "Element:- " << v[i] << "  Small Element on right side:- " << cnt << endl;
     }
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
     count_small(v);
     return 0;
}
