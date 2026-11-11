/*

   Reverse sub array

   Given an array arr, you need to reverse a subarray of that array. The range of this subarray is given by indices l and r (1-based indexing).

Examples:

Input: arr[] = [1, 2, 3, 4, 5, 6, 7], l = 2, r = 4
Output: [1, 4, 3, 2, 5, 6, 7]
Explanation: After reversing the elements in range 2 to 4 (2, 3, 4), modified array is 1, 4, 3, 2, 5, 6, 7.

Input: arr[] = [1, 6, 7, 4], l = 1, r = 4
Output: [4, 7, 6, 1]
Explanation: After reversing the elements in range 1 to 4 (1, 6, 7, 4), modified array is 4, 7, 6, 1.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6
1 ≤ l ≤ r ≤ arr.size()

 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseSubArray(vector<int> &arr, int l, int r) 
{
     // code here
     vector<int> res(arr.begin(), arr.end());
     int i = l-1, j = r-1;
     while(i < j)
     {
          swap(res[i], res[j]);
          i++;
          j--;
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

     int l;
     cout << "Enter Left Position: ";
     cin >> l;

     int r;
     cout << "Enter Right Position: ";
     cin >> r;

     cout << "Elements Before reverseSubArray Operation:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;
     vector<int> res = reverseSubArray(v, l, r);
     cout << "Elements After reverseSubArray Operation:- ";
     for(int x : res)
          cout << x << " ";
     cout << endl;     

     return 0;
}
