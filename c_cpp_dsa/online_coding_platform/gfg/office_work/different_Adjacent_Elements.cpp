/*

Different Adjacent Elements

Given an array arr[] of integers, determine whether it is possible to rearrange the array using any number of swaps between adjacent elements - so that no two adjacent elements in the resulting array are equal.

Examples:

Input: arr[] = [1, 1, 2]
Output: true
Explanation: Swapping the last two elements gives [1, 2, 1], where no two adjacent elements are equal.

Input: arr[] = [7, 7, 7, 7]
Output: false
Explanation: Every element is identical, so any arrangement will always have equal adjacent elements - no sequence of swaps can fix this.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 105

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool distinctAdjacent1(vector<int> &arr) 
{
     int n = arr.size();
     unordered_map<int, int> mp;
     for(int x : arr)
     {
          mp[x]++;
     }

     int cnt = 0;
     for(auto& m : mp)
     {
          cnt = max(cnt, m.second);
     }

     return (cnt <= (n+1)/2);
}

bool distinctAdjacent(vector<int> &arr) 
{
     // code here
     int n = arr.size();
     int cnt = 0;
     int cnd = -1;
     for(int x : arr)
     {
          if(cnt == 0)
          {
               cnd = x;
               cnt++;
          }
          else if(cnd == x)
          {
               cnt++;
          }
          else
          {
               cnt--;
          }
     } 

     cnt = 0;
     for(int x : arr)
     {
          if(cnd == x)
               cnt++;
     }

     return (cnt <= (n+1)/2);
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     bool res = distinctAdjacent(v);
     bool res1 = distinctAdjacent1(v);
     if(res && res1)
          cout << "    Yes\n";
     else
          cout << "    Nope\n";

     return 0;
}
