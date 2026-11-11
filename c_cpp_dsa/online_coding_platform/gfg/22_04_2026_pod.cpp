/*

   Given an integer array arr[] and a 2D array queries[][]. Each query queries[i] = [l, r] represents a subarray ranging from index l to r (inclusive). For every query, compute the mean (average) of the elements in the specified range, and return the floor value of that mean.

   Return an array where each element corresponds to the result of a query.

Examples:

Input: arr[] = [1, 2, 3, 4, 5], queries[][] = [[0, 2], [1, 3], [0, 4]]
Output: [2, 3, 3]
Explanation: The array is [1, 2, 3, 4, 5].
Query 1: l = 0, r = 2 → subarray [1, 2, 3] → sum = 6 → mean = 6/3 = 2
Query 2: l = 1, r = 3 → subarray [2, 3, 4] → sum = 9 → mean = 9/3 = 3
Query 3: l = 0, r = 4 → subarray [1, 2, 3, 4, 5] → sum = 15 → mean = 15/5 = 3
Hence the answer is [2, 3, 3]

Input: arr[] = [6, 7, 8, 10], queries[][] = [[0, 3], [1, 2]]
Output: [7, 7]
Explanation: The array is [6, 7, 8, 10].
Query 1: l = 0, r = 3 → subarray [6, 7, 8, 10] → sum = 31 → mean = 31/4 = 7 (floor value)
Query 1: l = 1, r = 2 → subarray [7, 8] → sum = 15 → mean = 15/2 = 7 (floor value)
Hence the answer is [7, 7]

Constraints: 
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 103
1 ≤ queries.size() ≤ 105
1 ≤ queries[i][0] ≤ queries[i][1] < arr.size()

 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) 
{
     // code here
     vector<int> out;
     int x = queries.size();
     /* // Not optimize
     for(int i=0;i<x;i++)
     {
          int sum = 0, avg = 0;
          int l = queries[i][0], r = queries[i][1];
          cout << "L: " << l << "  R: " << r << endl;
          avg = r-l+1;
          cout << "Avg Count: " << avg << endl;
          for(int k=l;k<=r;k++)
          {
               sum += arr[k];
          }
          cout << "Sum:- " << sum << endl;
          int temp = sum/avg;
          out.push_back(temp);
     }
     */
     
     vector<int> pre_sum(arr.size());
     pre_sum[0] = arr[0];
     for(int i=1;i<arr.size();i++)
     {
          pre_sum[i] = arr[i] + pre_sum[i-1];
     }

     for(int i=0;i<x;i++)
     {
          int sum = 0, avg = 0;
          int l = queries[i][0], r = queries[i][1];
          avg = r-l+1;
          sum += pre_sum[r] - (l > 0 ? pre_sum[l-1] : 0);
          int temp = sum/avg;
          out.push_back(temp);
     }
     return out;
}

int main()
{
     //vector<int> v{1, 2, 3, 4, 5};
     //vector<vector<int>> q{{0, 2}, {1, 3}, {0, 4}};

     vector<int> v{6, 7, 8, 10};
     vector<vector<int>> q{{0, 3}, {1, 2}};
     vector<int> res = findMean(v, q);
     for(int i=0;i<res.size();i++)
     {
          cout << res[i] << " ";
     }
     cout << endl;
     return 0;
}
