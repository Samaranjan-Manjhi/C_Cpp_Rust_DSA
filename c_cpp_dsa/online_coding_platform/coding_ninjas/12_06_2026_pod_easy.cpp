/*

   Problem statement

   You are given an array of tuples ‘ARR’ of length ‘N’. All the tuples are of length ‘L’. Sort the tuples in non-decreasing order by the last element of tuples. If the last element of two tuples are equal then the tuple with the smallest index should be placed first.
Note: The length of all the tuples will be the same.
Example:
Input: ‘N’ = 3, ‘L’ = 2,  ‘ARR’ = [(1, 1), (5, 3), (8, 2)]. 
Output: [(1, 1), (8, 2), (5, 3)].
The last values of each type are (1, 3, 2). Sorting them in non-decreasing order we get (1, 2, 3). Hence the final result is [(1, 1), (8, 2), (5, 3)].

Constraints :

1 <= T <= 10
1 <= N <= 10^5 Sum of total number of integers <= 10^5
1 <= ARR[i].length <= 1000
Time Limit: 1 sec

Sample Input 1 :
2
4 2
1 2
1 1
3 5
2 3
4 3
1 2 3
3 2 1
4 5 6
3 1 2
Sample Output 1 :
1 1 
1 2 
2 3 
3 5 
3 2 1 
3 1 2 
1 2 3 
4 5 6 
Explanation Of Sample Input 1 :
For the first case:
The last elements of the tuples are [2, 1, 5, 3]. Sorting them in non-decreasing order we get [1, 2, 3, 5]. So, the final output is [ (1, 1), (1, 2), (2, 3), (3, 5) ].
For the second case:
The last elements of the tuples are [3, 1, 6, 2]. Sorting them in non-decreasing order we get [1, 2, 3, 6]. So, the final output is [ (3, 2, 1), (3, 1, 2), (1, 2, 3), (4, 5, 6) ].

Sample Input 2 :
2
1 4
1 4 5 7
3 4
7 81 2 10
1 2 4 1
90 28 2 19
Sample Output 2 :
1 4 5 7
1 2 4 1
7 81 2 10
90 28 2 19

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sortTuples(vector<vector<int>>& arr)
{
     int n = arr.size();
     if(n == 0)
          return arr;

     /* // Time Limited Exceeded 
     for(int i=0;i<n-1;i++)
     {
          for(int j=0;j<n-i-1;j++)
          {
               if(arr[j].back() > arr[j+1].back())
               {
                    swap(arr[j], arr[j+1]);
               }
          }
     }
     */


     stable_sort(arr.begin(), arr.end(), 
     [] (const vector<int>& a, const vector<int>& b)
          {
               return a.back() < b.back();
          });
     return arr;
}

int main()
{
     int n, m;
     cout << "Enter Size of Vector of Vector : ";
     cin >> n >> m;

     vector<vector<int>>v(n, vector<int>(m));
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               cin >> v[i][j];
          }
     }

     vector<vector<int>> res = sortTuples(v);
     if(!res.empty())
     {
          for(int i=0;i<res.size();i++)
          {
               for(int j=0;j<res[i].size();j++)
               {
                    cout << res[i][j] << " ";
               }
               cout << endl;
          }
     }

     return 0;
}
