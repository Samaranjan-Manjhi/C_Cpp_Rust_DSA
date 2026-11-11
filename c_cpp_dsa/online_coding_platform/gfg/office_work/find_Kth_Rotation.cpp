/*

   Find Kth Rotation

   Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
   Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
   After 1st Rotation : [9, 2, 4, 6]
   After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.

Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 107

 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKRotation(vector<int> &arr)
{
     // Code Here
     int ans = 0;
     vector<int> res(arr.begin(), arr.end());
     sort(res.begin(), res.end());
     for(int i=0;i<arr.size();i++)
     {
          if(res[0] == arr[i])
               return i;
          else
               ans++;
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

     int res = findKRotation(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
