/*
   Separate odd and even numbers — odds first, evens after (any order within groups)
   Asked at: TCS, Wipro, Zoho
 */

#include <iostream>
#include <vector>
using namespace std;
void separate_odd_even(vector<int>& v)
{
     int n = v.size();
     
     int l = 0, r = n-1;
     while(l < r)
     {
          while(l < r && v[l]%2 != 0)
               l++;
          while(l < r && v[r]%2 == 0)
               r--;
          if(l < r)
          {
               swap(v[l], v[r]);
               l++; r--;
          }
     }
     
     /* // Works but slow
     int j = 0;
     for(int i=0;i<n;i++)
     {
          if(v[i]%2 != 0)
          {
               swap(v[i], v[j]);
               j++;
          }
     }
     */
}
void print(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
          cout << v[i] << " ";
     cout << endl;
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
     print(v);
     separate_odd_even(v);
     print(v);
     return 0;
}
