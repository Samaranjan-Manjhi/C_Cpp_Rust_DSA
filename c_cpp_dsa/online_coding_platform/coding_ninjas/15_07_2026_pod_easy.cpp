/*

   Problem statement

   Jasprit loves playing cricket. He wants to be a part of the Indian cricket team and become the best pacer for India. So he started practicing every day and took guidance from his coach. Every day to measure how he is improving, he maintained the count of times he hits the stumps in a day.

   ‘N’ days have been passed and its track is denoted by the array ‘ARR’, and to track his improvement, his coach will also ask him the average count of hits of stumps per day for a particular range of days (i.e. ‘L’ to ‘R’) to him. Meanwhile, he will also add the count of time he hits the stumps in the ongoing days.

   Jasprit is not very good at maths, So being his friend he asked you to help him to add the count of times he hit the stumps in the day as well as give the average count of hits of stumps per day for a particular range of days asked by his coach.

   There will be a ‘Q’ number of such queries where each query will be either one of the following types:
   1) Add the stumps hit by Jasprit i.e. ‘X’ to the array ‘ARR’, denoted by query number ‘1’.
   2) Give the average of hits of stumps per day for days ranging from ‘[L, R]’ asked by his coach denoted by query number ‘2’.

   Can you help him with this problem?.
NOTE: The average here means the sum of all elements in the selected range divided by the number of elements rounded down, i.e. let's suppose ‘sum’ = 10 and ‘number of elements’ = 4, then the average will be = 10/4 = 2.5, which when rounded down gives 2.

The array ‘ARR’ is 0-based indexing and queries of type 2 are represented in 1-based indexing.
The answer to the query of type 2 will be rounded down to an integer.

EXAMPLE :
Input: ‘N’ = 2, ‘Q’ = 2, ‘ARR’ = [7, 5], ‘QUERIES’ = [[1, 8], [2, 1, 3]].

Output: 6
In this case, the array ‘ARR’ after the first query will be ‘ARR’ = [7, 5, 8].
In the second query, the average will be = the sum of hits from day 1 to day 3 divided by 3
i.e. (7+5+8)/3 = 20/3 = 6.6666… when rounded gives 6. Hence the output will be 6.

Constraints :
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10^5
1 <= ‘Q’ <= 10^5
0 <= ‘ARR[i]’ <= 10^4
0 <= ‘X’ <= 10^4
1 <= ‘L’ <=  ‘R' <= Total number of elements in the array ‘ARR’, before this operation.
It is guaranteed that sum of ‘N’ over all test cases is <= 10^5
It is guaranteed that sum of ‘N’ over all test cases is <= 10^5
It is guaranteed that there will be atleast one query of type ‘2’.
Time Limit: 1 sec

Sample Input 1 :
2
5 3
1 4 5 8 3
1 0
2 2 5
2 6 6
1 2
0
2 1 1
1 5
Sample Output 1 :
5 0
0

Explanation Of Sample Input 1 :

For the first test case,
After the first query, the array ‘ARR’ = [1, 4, 5, 8, 3, 0].
In the second query, the sum = 4+5+8+3 = 20 and number of elements is 4, hence the average = 20/4 = 5.
In the third query, the sum = 0 and number of elements is 1, hence the average = 0/1 = 0.

Hence, the output will be: 5 0

For the second test case,
In the first query, the sum = 0 and number of elements is 1, hence the average = 0/1 = 0.
After the second query, the array ‘ARR’ = [0, 5].

Hence, the output will be: 0

Sample Input 2 :
2
1 4
5
1 2
2 1 2
1 3
2 2 3
5 1
1 2 3 4 5
2 1 5
Sample Output 2 :
3 2
3

*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> getAverage(int n, int q, vector<int> &arr, vector<vector<int>> &queries) 
{
     // Write your code here.
     vector<int> res(arr.begin(), arr.end());
     vector<int> ans;
     vector<int> pre(n);
     pre[0] = res[0];
     for(int i=1;i<n;i++)
     {
          pre[i] = pre[i-1]+res[i];
     }
     for(int i=0;i<q;i++)
     {
          int temp = queries[i][0];
          int left = 0, right = 0;
          if(temp == 1)
          {
               res.push_back(queries[i][1]);
               pre.push_back(pre.back()+queries[i][1]);
          }
          else if(temp == 2)
          {
               left = queries[i][1];
               right = queries[i][2];

               int l = left-1;
               int r = right-1;
               //int sum = 0;
               //for(int j=l;j<=r;j++)
               //    sum += res[j];

               int sum;
               if(l == 0)
                    sum = pre[r];
               else
                    sum = pre[r] - pre[l-1];

               ans.push_back((sum)/(r-l+1));
          }
     }

     return ans;
}

int main() 
{
     int n, q;
     cout << "Enter arr size and queries size: ";
     cin >> n >> q;

     vector<int> arr(n);

     for (int i = 0; i < n; i++) 
     {
          cin >> arr[i];
     }

     vector<vector<int>> queries;

     for (int i = 0; i < q; i++) 
     {
          int type;
          cout << "Enter type: ";
          cin >> type;

          if (type == 1) 
          {
               int x;
               cout << "Enter Value to add in arr: ";
               cin >> x;
               queries.push_back({1, x});
          } 
          else 
          {
               int l, r;
               cout << "Enter Range value (l, r): ";
               cin >> l >> r;
               queries.push_back({2, l, r});
          }
     }

     vector<int> res = getAverage(n, q, arr, queries);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
