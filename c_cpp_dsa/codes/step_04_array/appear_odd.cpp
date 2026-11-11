/*
   Find the element that appears an odd number of times (XOR trick)
   Asked at: TCS, Wipro, Amazon
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
     vector<int>v{1, 3, 5, 3, 5, 5, 3, 3, 1};
     unordered_map<int, int> freq;
     /* // For multiple odd
     for(int x : v)
     {
          freq[x]++;
     }
     for(auto& f : freq)
     {
          if(f.second%2 == 1)
               cout << f.first << "    " << f.second << endl;
     }
     */
     
     int ans = 0;
     for(int x : v)
     {
          ans ^= x;
     }
     cout << "Result: " << ans << endl;
     return 0;
}
