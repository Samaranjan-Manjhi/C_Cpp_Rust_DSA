/*
   Check if an array is a permutation of 1 to N
   Asked at: TCS, Wipro, Infosys
 */

#include <iostream>
#include <vector>
using namespace std;

bool check_permutation(const vector<int>& v)
{
     int n = v.size();
     /* // Not reliable
        int xor1 = 0, xor2 = 0;
        for(int i=1;i<n+1;i++)
        {
     //cout << "xor1:- " << i << endl;
     xor1 ^= i;
     }
     for(int i=0;i<n;i++)
     {
     //cout << "xor2:- " << v[i] << endl;
     xor2 ^= v[i];
     }
     return (xor1 == xor2);
      */
     vector<bool> seen(n + 1, false);
     for(int x : v)
     {
          if(x < 1 || x > n) return false;   // out of range
          if(seen[x]) return false;          // duplicate
          seen[x] = true;
     }
     return true;
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
     cout << "Is vector permutation " << (check_permutation(v) ? "Yes" : "No") << endl;
     return 0;
}
