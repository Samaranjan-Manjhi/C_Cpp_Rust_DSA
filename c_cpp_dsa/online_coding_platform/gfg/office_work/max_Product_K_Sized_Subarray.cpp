/*

Max Product K Sized Subarray

Given an array arr and an integer k. You have to find the maximum product of k contiguous elements in the array. 

Examples:

Input: arr[] = [1, 2, 3, 4] and k = 2
Output: 12 
Explanation: The sub-array of size 2 will be 3 4 and the product is 12.

Input: arr[] = [1, 6, 7, 8] and k = 3
Output: 336
Explanation: The sub-array of size 3 will be 6 7 8 and the product is 336.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ k ≤ 900
1 ≤ arr[i] ≤ 10^2

*/

#include <iostream>
#include <vector>

using namespace std;

int findMaxProduct(vector<int>& arr, int k) 
{
     // code here
     int prod = 1;
     int n = arr.size();

     for(int i=0;i<k;i++)
     {
          prod *= arr[i];
     }
     int ans = prod;
     for(int i=k;i<n;i++)
     {
          prod /= arr[i-k];
          prod = prod*arr[i];
          ans = max(ans, prod);
     }

     return ans;
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

     int res = findMaxProduct(v, k);
     cout << "     Result:- " << res << endl;

     return 0;
}
