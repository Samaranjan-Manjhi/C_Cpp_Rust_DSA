/*

   Second Largest

   Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.

Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getSecondLargest(vector<int> &arr) 
{
     // code here
     int lar = INT_MIN;
     int sec = INT_MIN;
     for(int i=0;i<arr.size();i++)
     {
          if(arr[i] > lar)
          {
               sec = lar;
               lar = arr[i];
          }
          else if(sec < arr[i] && arr[i] < lar)
          {
               sec = arr[i];
          }
     }

     if(sec == INT_MIN)
          return -1;

     return sec;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = getSecondLargest(v);
     cout << "     Result:- " << res << endl;

     return 0;
}
