/*

   Drive the car

   Given an array arr[] where each element represents the length of a sub-track, and an integer k representing the maximum distance a car can travel on any sub-track.

   You may add petrol to increase the car's maximum travel distance.
   Each unit of petrol increases this maximum distance by 1 kilometer for all sub-tracks.

   Determine the minimum units of petrol required so that the car can travel through every sub-track. If the car can already cover all sub-tracks with its initial capacity, return -1.

Examples:

Input: arr[] = [2, 5, 4, 5, 2], k = 7
Output: -1
Explanation: Since the car can already traverse all the given sub-tracks, no extra petrol is required. Hence, the answer is -1.

Input: arr[] = [1, 6, 3, 5, 2], k = 4
Output: 2
Explanation: After adding 2 units of petrol, the car's maximum travel distance becomes 6 km, allowing it to traverse all the given sub-tracks. Hence, the answer is 2.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ k, arr[i]  ≤ 10^9

 */


#include <iostream>
#include <vector>

using namespace std;

int required(vector<int>& arr, int k) 
{
     // code here
     int maxi = 0;
     for(int x : arr)
     {
          if(maxi < x)
               maxi = x;
     }

     if(k >= maxi)
          return -1;

     return maxi-k;
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

     int res = required(v, k);
     cout << "   Result:- " << res << endl;

     return 0;
}
