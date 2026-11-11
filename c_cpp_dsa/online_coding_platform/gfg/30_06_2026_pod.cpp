/*

   Given two arrays a[] and b[] of size n and m respectively, find the minimum number of insertions and deletions on the array a[], required to make both the arrays identical.

Note: Array b[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at the end.

Examples :

Input: a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
Output: 4
Explanation:
Delete 2 from a: a[] = [1, 5, 3, 1]
Insert 3 after 1: a[] = [1, 3, 5, 3, 1]
Delete the last two elements: a[] = [1, 3, 5]
Total operations = 1 + 1 + 2 = 4.

Input: a[] = [1, 4], b[] = [1, 4]
Output : 0
Explanation: Both the Arrays are already identical.

Constraints:
1 ≤ n, m ≤ 105
1 ≤ a[i], b[i] ≤ 105

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minInsAndDel(vector<int> &a, vector<int> &b) 
{
     // code here
     /* // Gives TLE
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0;i<=n;i++)
        {
        for(int j=0;j<=m;j++)
        {
        if(i == 0 || j == 0)
        {
        dp[i][j] = 0;
        }
        else if(a[i-1] == b[j-1])
        {
        dp[i][j] = 1+dp[i-1][j-1];
        }
        else
        {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
        }
        }
        int l = dp[n][m];

        return ((n-l) + (m-l));
      */

     unordered_map<int, int> m;
     for(int i = 0; i < b.size(); i++)
     {
          m[b[i]] = i;
     }
     vector<int> temp;
     for(int x : a)
     {
          if(m.find(x) != m.end())
          {
               temp.push_back(m[x]);
          }
     }

     vector<int> lis;
     for(int x : temp)
     {
          auto it = lower_bound(lis.begin(), lis.end(), x);

          if(it == lis.end())
               lis.push_back(x);
          else
               *it = x;
     }

     int l = lis.size();

     return ((a.size()-l) + (b.size()-l));
}

int main()
{
     int n, m;
     cout << "Enter Size of Vectors: ";
     cin >> n >> m;

     vector<int> a(n);
     for(int i=0;i<n;i++)
          cin >> a[i];

     vector<int> b(m);
     for(int i=0;i<m;i++)
          cin >> b[i];

     int res = minInsAndDel(a, b);
     cout << "    Result:- " << res << endl;

     return 0;
}
