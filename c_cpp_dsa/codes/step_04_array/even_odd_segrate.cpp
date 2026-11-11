/*
   Segregate even and odd numbers — evens first, odds second
   Maintain relative order. O(N) time O(1) space.
   Asked at: Amazon, Zoho, TCS
 */

#include <iostream>
#include <vector>
using namespace std;
void segregate_even_odd(vector<int>& v)
{
     int n = v.size();
     //int l = 0, r = l+1;
     int l = 0, r = 0;
     while(r < n-1)
     {
          if(v[l]%2!=0 && v[r]%2==0)
          {
               swap(v[l], v[r]);
               l++;
          }
          if(v[l]%2==0)
               l++;
          r++;
     }
}
void printVec(const vector<int>& v)
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
     segregate_even_odd(v);
     printVec(v);
     return 0;
}
