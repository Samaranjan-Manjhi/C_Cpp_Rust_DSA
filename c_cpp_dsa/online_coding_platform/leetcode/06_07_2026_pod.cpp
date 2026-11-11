/*

   1288. Remove Covered Intervals

   Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
   The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
   Return the number of remaining intervals.

   Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:
Input: intervals = [[1,4],[2,3]]
Output: 1

Constraints:
1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li < ri <= 105
All the given intervals are unique.

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) 
{
     sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) 
     {
          if(a[0] != b[0])
          {
              return a[0] < b[0];
          }
          return a[1] > b[1]; 
     });

     int cnt = 0;
     int maxi = 0;
     for(int i=0;i<intervals.size();i++)
     {
          int start = intervals[i][0];
          int end = intervals[i][1];

          if(end > maxi)
          {
               cnt++;
               maxi = end;
          }
     }

     return cnt;
}

int main()
{
     int n;
     cout << "Enter Size of Vcetor: ";
     cin >> n;

     vector<vector<int>> vec(n, vector<int>(2));
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<2;j++)
          {
               cin >> vec[i][j];
          }
     }

     int res = removeCoveredIntervals(vec);
     cout << "     Result:- " << res << endl;

     return 0;
}
