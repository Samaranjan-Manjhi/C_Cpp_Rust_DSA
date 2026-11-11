/*

You are given a binary array arr[] consisting only of 0s and 1s. Determine the minimum number of swaps required to group all the 1s together in a contiguous subarray.
A swap operation allows you to choose any two indices i and j and exchange their values (i.e., swap(arr[i], arr[j])).
If the array contains no 1s, return -1.

Examples:
Input: arr[] = [1, 0, 1, 0, 1]
Output: 1
Explanation: Only 1 swap is required to group all 1's together. Swapping index 1 and 4 will give arr[] = [1, 1, 1, 0, 0].

Input: arr[] = [1, 0, 1, 0, 1, 1] 
Output: 1
Explanation: Only 1 swap is required to group all 1's together. Swapping index 0 and 3 will give arr[] = [0, 0, 1, 1, 1, 1].

Input: arr[] = [0, 0, 0]
Output: -1
Explanation: No 1s are present in the array, so return -1.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 1

*/

#include <iostream>
#include <vector>
using namespace std;

int minSwaps(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     int cntOne = 0;
     for(int x : arr)
     {
          if(x == 1)
               cntOne++;
     }
     if(cntOne == 0)
          return -1;

     int k = cntOne;
     int currSum = 0;
     for(int i=0;i<k;i++)
     {
          if(arr[i] == 1)
               currSum++;
     }
     int maxi = currSum;
     for(int i=k;i<n;i++)
     {
          currSum += arr[i]-arr[i-k];
          maxi = max(currSum, maxi);
     }
     return cntOne-maxi;
}

int main()
{
int n;
cout << "Enter vector Size: ";
cin >> n;
if(n == 0)
     return 0;
vector<int> v(n);
for(int i =0;i<n;i++)
     cin >> v[i];

int res = minSwaps(v);
cout << "Result:- " << res << endl;

return 0;
}
