/*
   Find the missing number using XOR only (no arithmetic sum)
   Array of size N containing elements 1 to N+1 with one missing
   Asked at: Amazon, Microsoft, TCS
 */

#include <iostream>
#include <vector>
using namespace std;
int get_missing_num(const vector<int>& v)
{
     /*
        int n = v.size();
        int xor1 = 0, xor2 = 0;
        for(int i=1;i<=n+1;i++)
        xor1 ^= i;
        for(int i=0;i<n;i++)
        xor2 ^= v[i];
        int ans = xor1 ^ xor2;
        if(ans > 0)
        return ans;
        return -1;
      */
        int n = v.size();
     int x = 0;
     for(int i = 0; i < n; i++) 
     {
          x ^= (i + 1) ^ v[i];
     }
     x ^= (n + 1);
     return x;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n-1);
     for(int i=0;i<n-1;i++)
          cin >> v[i];
     int res = get_missing_num(v);
     if(res != -1)
          cout << "Result:- " << res << endl;
     return 0;
}
