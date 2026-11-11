/*

   Problem statement

   Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.
   For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].
   Now you are given Q queries, each query consists of two integers “L“ and “R”(1-based indexing). Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.

Note :
The value of the sum can be very large, return the answer as modulus 10^9+7.

Constraints :
1 <= T <= 100
1 <= N <= 10^4   
1 <= A[i] <= 10^9
1 <= Q <= 10^4
1 <= L <= R <= 10^18
Time Limit: 1sec

Sample Input 1 :
1
3
1 2 3
2
1 3
1 5
Sample Output 1 :
6 9
Explanation to Sample Input 1 :
For the first test case, the given array A is [1,2,3] therefore the infinite array “B” will be [1,2,3,1,2,3,1,2,3,.......]. So the answer for the given first query is 6 because the sum of the subarray from index 1 to 3 of infinite array “B” i.e. (B[1]+B[2]+B[3]) is 6.
For the given second query is 9 because the sum of the subarray from index 1 to 5 of array “B” .ie (B[1]+B[2]+B[3]+B[4]+B[5]) is 9.

Sample Input 2 :
1
4
5 2 6 9
3
1 5
10 13
7 11
Sample Output 2 :
27 22 28

 */

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) 
{
     // Write your code here
     // Prefix sum of original array
     vector<long long> prefix(n + 1, 0);
     for (int i = 0; i < n; i++)
     {
          prefix[i + 1] = (prefix[i] + arr[i]) % mod;
     }
     long long totalSum = prefix[n];
     vector<int> ans;
     for (int i = 0; i < q; i++)
     {
          long long L = queries[i][0];
          long long R = queries[i][1];
          // convert to 0-based indexing
          L--;
          R--;
          long long leftBlock = L / n;
          long long rightBlock = R / n;
          long long leftIndex = L % n;
          long long rightIndex = R % n;
          int result = 0;
          if (leftBlock == rightBlock)
          {
               // same block
               result = (prefix[rightIndex + 1] - prefix[leftIndex] + mod) % mod;
          }
          else
          {
               // left partial block
               result = (prefix[n] - prefix[leftIndex] + mod) % mod;
               // full blocks in between
               long long fullBlocks = (rightBlock - leftBlock - 1) % mod;
               result = (result + (fullBlocks * totalSum) % mod) % mod;
               // right partial block
               result = (result + prefix[rightIndex + 1]) % mod;
          }
          ans.push_back(result);
     }
     return ans;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> vec(n);
     for(int i=0;i<n;i++)
     {
          cin >> vec[i];
     }

     int q;
     cout << "Enter Queries Row: ";
     cin >> q;

     vector<vector<long long>> v(q, vector<long long>(2));
     for(int i=0;i<q;i++)
     {
          cin >> v[i][0] >> v[i][1];
     }

     vector<int> res = sumInRanges(vec, n, v, q);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
