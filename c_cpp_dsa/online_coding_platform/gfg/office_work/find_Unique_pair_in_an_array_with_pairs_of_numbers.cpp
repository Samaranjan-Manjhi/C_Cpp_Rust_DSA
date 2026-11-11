/*

   Find Unique pair in an array with pairs of numbers

   Given an array arr where every element appears twice except a pair (two elements). Return the elements of this unique pair in sorted order.

Examples:

Input: arr[] = [2, 2, 5, 5, 6, 7]
Output: [6, 7]
Explanation: We can see we have [2, 2, 5, 5, 6, 7]. Here 2 and 5 are coming two times. So, the answer will be 6 7.

Input : arr[] = [1, 3, 4, 1]
Output : [3, 4]
Explanation: 1 is appearing two times and 3 and 4 appear one times.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^5

 */


#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> findUniquePair(vector<int>& arr) 
{
     // Complete the function and return the sorted vector.
     map<int, int> mp;
     for(int x : arr)
     {
          mp[x]++;
     }

     vector<int> res;
     for(auto& m : mp)
     {
          if(m.second%2 != 0)
               res.push_back(m.first);
     }   

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = findUniquePair(v);
     cout << "   Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
