/*
   Build the running maximum (prefix max array)
   Asked at: TCS, Wipro, Capgemini
 */

#include <iostream>
#include <vector>
using namespace std;

void prefix_max(vector<int>& v)
{
     int n = v.size();
     int maxi = v[0]; 
     for(int i=1;i<n;i++)
     {
          maxi = max(maxi, v[i]);
          v[i] = maxi;
     }
}
void print(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
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
     print(v);
     prefix_max(v);
     print(v);
     return 0;
}
