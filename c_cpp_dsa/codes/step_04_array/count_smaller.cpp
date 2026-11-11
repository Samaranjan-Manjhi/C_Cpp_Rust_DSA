/*
   Count elements smaller than current element for each position
Input: [8,5,2,6] -> Output: [3,1,0,2]
Asked at: Amazon, Flipkart
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> count_smaller_ele(const vector<int>& v)
{
     int n = v.size();
     //int j = 0;
     vector<int> res;
     for(int i=0;i<n;i++)
     {
          int cnt = 0;
          for(int j=0;j<n;j++)
          {
               if(v[i] > v[j])
                    cnt++;
          }
          res.push_back(cnt);
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
     vector<int> res = count_smaller_ele(v);
     if(!res.empty())
     {
          for(int x : res)
          {
               cout << x << " ";
          }
          cout << endl;
     }
     return 0; 
} 
