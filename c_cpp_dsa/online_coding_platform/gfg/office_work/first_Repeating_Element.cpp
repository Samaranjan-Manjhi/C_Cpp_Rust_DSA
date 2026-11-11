/*

   First Repeating Element

   Given an array arr[], find the first repeating element index. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing. 

Examples:

Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.

Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstRepeated(vector<int> &arr) 
{
     // code here
     unordered_map<int, int> mp;
     for(int x : arr)
     {
          mp[x]++;
     }

     for(int i=0;i<arr.size();i++)
     {
          if(mp[arr[i]] > 1)
               return i+1;
     }

     return -1;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = firstRepeated(v);
     cout << "    Result:- " << res << endl;

     return 0;
}

