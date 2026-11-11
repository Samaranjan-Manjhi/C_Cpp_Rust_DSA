/*
Given sorted array, remove duplicates in-place and return new length
             Do NOT use extra space
             Asked at: Amazon, TCS, Wipro, Adobe
*/

#include <iostream>
#include <vector>
using namespace std;

int getNewLength(vector<int>& v)
{
     int n = v.size();
     int i = 0;
     for(int j=1;j<n;j++)
     {
          if(v[j] != v[i])
          {
               i++;
               v[i] = v[j];
          }
     }
     return i+1;
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
     int res = getNewLength(v);
     cout << "New Length of Vector:- " << res  << endl;

     return 0;
}
