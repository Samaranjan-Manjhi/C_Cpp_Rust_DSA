/*

   Count the Specials

   Given an array arr[] (may contain duplicates) and a positive integer k, count the number of elements whose occurrence is exactly equal to the size of array arr[] divided by k times.

Examples:

Input: k = 2, arr[] = [1, 4, 1, 2, 4]
Output: 2
Explanation:In the given array, 1 and 4 occurs floor(5/2) = 2 times.So count is 2.

Input: k = 4, arr[] = [1, 1, 7, 1]
Output: 1
Explanation:In the given array, only 7 occurs floor(4/4) = 1 times.So count is 1.

Constraints:
1 <= arr.size() <= 105
1 <= arri <= 106
1 <= k <= arr.size()

 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSpecials(int k, vector<int> &arr) 
{
     // code here
     unordered_map<int, int> mp;
     for(int x : arr)
          mp[x]++;

     int cnt = arr.size()/k;
     int res = 0;
     for(auto& m : mp)
     {
          if(m.second == cnt)
               res++;
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

     int k;
     cout << "Enter K value: ";
     cin >> k;

     int res = countSpecials(k, v);
     cout << "   Result:- " << res << endl;

     return 0;
}
