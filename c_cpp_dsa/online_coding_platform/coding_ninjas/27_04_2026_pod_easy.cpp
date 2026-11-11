/*
   Problem statement

   Ninja is studying sorting algorithms. He has studied all comparison-based sorting algorithms and now decided to learn sorting algorithms that do not require comparisons.
   He was learning counting sort, but he is facing some problems. Can you help Ninja implement the counting sort?
   For example:
   You are given ‘ARR’ = {-2, 1, 2, -1, 0}. The sorted array will be {-2, -1, 0, 1, 2}.

Constraints:
1 <= T <= 10 
1 <= N <= 5000
-10^4 <= ARR[i] <= 10^4
Time limit: 1 sec

Sample Input 1:
2
5
-2 1 2 -1 0
5
1 2 3 -4 -5
Sample Output 1:
-2 -1 0 1 2
-5 -4 1 2 3

Explanation:
For the first test case, the sorted array will be {-2, -1, 0, 1, 2}.
For the second test case, the sorted array will be {-5, -4, 1, 2, 3}.

Sample Input 2:
2
4
1 3 4 2
4
1 1 -1 -1

Sample Output 2:
1 2 3 4
-1 -1 1 1

 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> CountSort(const vector<int>& arr)
{
     int n = arr.size();
     int maxi = INT_MIN;
     int mini = INT_MAX;
     for(int i=0;i<n;i++)
     {
          maxi = max(maxi, arr[i]);
          mini = min(mini, arr[i]);
     }

     vector<int> cntArr(maxi-mini+1, 0);
     for(int i=0;i<n;i++)
          cntArr[arr[i]-mini]++;

     for(int i=1;i<cntArr.size();i++)
          cntArr[i] += cntArr[i-1];

     vector<int> res(n);
     for(int i=n-1;i>=0;i--)
     {
          res[cntArr[arr[i]-mini]-1] = arr[i];
          cntArr[arr[i]-mini]--;
     }
     return res;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];
     vector<int> res = CountSort(v);
     if(!res.empty())
     {
          for(int i=0;i<res.size();i++)
               cout << res[i] << " ";
          cout << endl;
     }
     return 0;
}
