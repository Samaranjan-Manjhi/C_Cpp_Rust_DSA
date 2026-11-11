/*
   Replace each element with the greatest element on its right side
   e.g. [17,18,5,4,6,1] -> [18,6,6,6,1,-1]
   Asked at: Amazon, LeetCode Easy
 */

#include <iostream>
#include <vector>
using namespace std;
void replace_by_right_ele(vector<int>& v)
{
     int n = v.size();
     int r = n-1;
     int maxRight = -1;
     for(int i=r;i>=0;i--)
     {
          int curr = v[i];
          v[i] = maxRight;
          maxRight = max(maxRight, curr);
     }
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
     {
          cin >> v[i];
     }
     replace_by_right_ele(v);
     if(!v.empty())
     {
          for(int x : v)
               cout << x << " ";
     }
     cout << endl;
     return 0;
}
