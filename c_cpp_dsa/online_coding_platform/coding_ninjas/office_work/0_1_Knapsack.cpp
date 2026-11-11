/*

0 1 Knapsack 

 Problem statement

A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

Constraints:

1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3
Time Limit: 1 second

Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13

*/

#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
     // Write your code here
     int ans = 0;

     vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, 0));

     for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=maxWeight;j++)
          {
               if(weight[i-1] <= j)
               {
                    int take = value[i-1] + dp[i-1][j-weight[i-1]];
                    int notTake = dp[i-1][j];

                    dp[i][j] = max(take, notTake);
               }
               else
               {
                    dp[i][j] = dp[i-1][j];
               }
          }
     }

     return dp[n][maxWeight];
}

int main()
{
     int w;
     cout << "Enter Weight Vector Size: ";
     cin >> w;

     vector<int>wv(w);
     for(int i=0;i<w;i++)
          cin >> wv[i];

     int v;
     cout << "Enter Value Vector Size: ";
     cin >> v;

     vector<int>vv(v);
     for(int i=0;i<v;i++)
          cin >> vv[i];

     int maxWeight;
     cout << "Enter maxWeight Value: ";
     cin >> maxWeight;

     int res = knapsack(wv, vv, v, maxWeight);
     cout << "    Result:- " << res << endl;

     return 0;
}
