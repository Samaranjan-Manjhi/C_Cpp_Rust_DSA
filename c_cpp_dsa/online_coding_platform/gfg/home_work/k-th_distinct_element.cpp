/*

   K-th distinct element

   Given an integer array arr[] and an integer k, find the k-th distinct element in the array. A distinct element is an element that appears exactly once in the entire array.  Distinct elements are considered in the same order as they appear in the array.

   Return the k-th distinct element if it exists; otherwise, return -1.

Examples:

Input: arr[] = [1, 2, 1, 3, 4, 2], k = 2
Output: 4
Explanation: The elements that appear exactly once are 3 and 4. In their order of appearance, the 2nd distinct element is 4.

Input: arr[] = [5, 1, 2, 5, 3, 2, 4], k = 3
Output: 4
Explanation: The elements that appear exactly once are 1, 3, and 4. The 3rd distinct element is 4.

Constranits:
1 ≤ n ≤ 105, where n is the length of the array
1 ≤ arr[i] ≤ 106
1 ≤ k ≤ n 

 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int kthDistinctElement(vector<int>& arr, int k) 
{
     // code here
     unordered_map<int, int> mp;   
     for(int x : arr)
     {
          mp[x]++;
     }

     vector<int> temp;
     for(int x : arr)
     {
          //cout << "x:- " << x << "   &  " << mp[x] << endl;
          if(mp[x] == 1)
          {
               temp.push_back(x);
          }
     }
     if(temp.size() < k)
          return -1;
     return temp[k-1];
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
     {
          cin >> v[i];
     }

     int k;
     cout << "Enter k Value: ";
     cin >> k;

     int res = kthDistinctElement(v, k);
     cout << "    Result:- " << res << endl;

     return 0;
}
