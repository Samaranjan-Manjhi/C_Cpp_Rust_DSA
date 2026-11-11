/*
   Find the index of the first occurrence of the minimum element
   Asked at: TCS, Wipro
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int first_index(const vector<int>& v)
{
     int minVal = v[0];
     int idx = 0;
     for(int i=1;i<v.size();i++)
     {
          if(v[i] < minVal)
          {
               minVal = v[i];
               idx = i;
          }
     } 
     return idx;
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
     cout << "First Index:- " << first_index(v) << endl;
     return 0;
}
