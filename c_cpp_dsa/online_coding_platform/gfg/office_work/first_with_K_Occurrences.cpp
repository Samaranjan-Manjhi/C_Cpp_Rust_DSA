/*

   First with K Occurrences

   Given an array arr[] representing user IDs in chronological order of their occurrences, and an integer k, find the first user whose ID occurs exactly k times in the array.

   If no such user exists, return -1.

Examples:

Input: arr[] = [1, 7, 4, 3, 4, 8, 7], k = 2
Output: 7
Explanation: Both 7 and 4 occur exactly 2 times. Since 7 appears before 4 in the array, 7 is the required answer.  

Input: arr[] = [4, 1, 6, 1, 6, 4], k = 1 
Output: -1 
Explanation: Every element occurs 2 times, so no element occurs exactly 1 time.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstElement(vector<int>& arr, int k) 
{
     // code here
     unordered_map<int, int> mp;
     for(int x : arr)
          mp[x]++;

     for(int x : arr)
     {
          if(mp[x] == k)
               return x;
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

     int k;
     cout << "Enter K value: ";
     cin >> k;

     int res = firstElement(v, k);
     cout << "   Result:- " << res << endl;

     return 0;
}
