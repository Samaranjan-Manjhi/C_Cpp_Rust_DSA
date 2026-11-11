/*

   Given an array of integers arr[], return true if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return false.

Examples:

Input: arr[] = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: We can divide the array into [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10.

Input: arr[] = [4, 3, 2, 1]
Output: false
Explanation: We cannot divide the array into two subarrays with equal sum.

Constraints:
1 ≤ arr.size() ≤ 105 
1 ≤ arr[i] ≤ 106

 */

#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     int sum = 0;
     for(int x : arr)
          sum += x;
     if(sum%2 != 0) return false;
     cout << "Sum:- " << sum << endl;
     vector<int> prefix_sum(n, 0);
     prefix_sum[0] = arr[0];
     for(int i=1;i<n;i++)
     {
          prefix_sum[i] = prefix_sum[i-1]+arr[i];
     }
     for(int i=0;i<prefix_sum.size();i++)
     {
          cout << prefix_sum[i] << " ";
          if(prefix_sum[i] == prefix_sum[prefix_sum.size()-1]/2)
               return true;
     }
     cout << endl;
     return false;
}    

int main()
{
     //vector<int> v{1, 2, 3, 4, 5, 5};
     //vector<int> v{4, 3, 2, 1};
     vector<int> v{3, 1, 1, 2};
     bool res = canSplit(v);
     if(res)
          cout << "Yes" << endl;
     else
          cout << "No" << endl;
     return 0;
}
