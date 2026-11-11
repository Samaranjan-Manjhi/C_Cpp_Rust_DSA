/*

   Minimum Deletions to Make Sorted

   Given an array arr[], find the minimum number of elements to delete so that the remaining elements form a strictly increasing sequence in the same order.

Examples:

Input: arr[] = [5, 6, 1, 7, 4]
Output: 2
Explanation: Removing 1 and 4 leaves [5, 6, 7] which is strictly increasing.

Input: arr[] = [1, 1, 1]
Output: 2
Explanation: Removing any 2 elements leaves [1] which is strictly increasing.

Constraints:
1 ≤ n ≤ 10^5 
1 ≤ arr[i] ≤ 10^5

 */


#include <iostream>
#include <vector>

using namespace std;

int minDeletions(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     if(n == 0)
          return 0;

     vector<int> res(n);
     int lis = 0;

     for(int x : arr)
     {
          int low = 0;
          int high = lis-1;
          int insert_idx = lis;
          while(low <= high)
          {
               int mid = low + (high - low) / 2;
               if(res[mid] >= x)
               {
                    insert_idx = mid;
                    high = mid - 1;
               }
               else
               {
                    low = mid + 1;
               }
          }

          res[insert_idx] = x;
          if(insert_idx == lis)
               lis++;
     }

     return n-lis;
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

     int res = minDeletions(v);
     cout << "    Result:-   " << res << endl;

     return 0;
}
