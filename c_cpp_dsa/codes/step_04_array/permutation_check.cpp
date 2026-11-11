/*
   Check if an array is a permutation of 1 to N
   (all elements unique and in range [1, N])
   Asked at: TCS, Wipro, Zoho
 */

#include <iostream>
#include <vector>
using namespace std;
bool permutation_check(const vector<int>& v)
{
     int n = v.size();
     vector<int> res(n+1, 0);
     for(int x : v)
     {
          if(x < 1 || x > n)  return false;
          if(res[x])     return false;
          res[x] = true;
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
     bool res = permutation_check(v);
     if(res)
          cout << "Yes" << endl;
     else
          cout << "No" << endl;
     return 0;
}
