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
1 <= N <= 10^5
Sum of total number of integers <= 10^5
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

void sortTuples(vector<vector<int>>& arr)
{
     // Write your code here
     int m = arr.size();
     int n = arr[0].size();
     if(m <= 1) return;
     sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b)
               {
               return a.back() < b.back();
               });
     /*
     // Selection SOrting algo for this
     for (int i = 0; i < m - 1; i++)
     {
     int min_idx = i;
     for (int j = i + 1; j < m; j++)
     {
     if (arr[j][n - 1] < arr[min_idx][n - 1])
     min_idx = j;
     }
     // Swap entire rows
     if (min_idx != i)
     swap(arr[i], arr[min_idx]);
     }
      */

     /*
        for(int i = 0; i < m - 1; i++)
        {
        int min_idx = i;
        for(int j = i + 1; j < m; j++)
        {
        if(arr[j][n-1] < arr[min_idx][n-1])
        min_idx = j;
        }

     // Instead of swap, insert arr[min_idx] at position i
     vector<int> key = arr[min_idx];
     while(min_idx > i)
     {
     arr[min_idx] = arr[min_idx - 1];
     min_idx--;
     }
     arr[i] = key;
     }
      */
}

void printMat(vector<vector<int>> v)
{
     int m = v.size();
     int n = v[0].size();
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cout << v[i][j] << " ";
          }
          cout << endl;
     }
}

int main()
{
     int m, n;
     cout << "Enter m & n: ";
     cin >> m >> n;
     vector<vector<int>> in(m, vector<int>(n));
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cin >> in[i][j];
          }
     }
     cout << "Before tuple Sort:- \n";
     printMat(in);
     sortTuples(in);
     cout << "After tuple Sort:- \n";
     printMat(in);

     return 0;
}
