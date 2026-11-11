/*

   Problem statement

   You have been given an array 'ARR' of integers consisting of ‘N’ integers and a positive integer ‘K’. Your task is to find a subarray(contiguous) of size ‘K’ such that the sum of its elements is minimum.
Note :
You can assume that the value of ‘K’ will always be less than or equal to ‘N’. So, the answer will always exist.

Constraints :
1 <= N <=  10^5
1 <= K <= N 
-10^5 <= ARR[i] <= 10^5
Time Limit: 1sec

Sample Input 1 :
8 3
10 4 2 5 6 3 8 1
Sample Output 1 :
11
Explanation Of Sample Input
All subarrays of size 3 and their respective sums are-
{10, 4, 1} : sum → 10+4+1 = 15
{4, 2, 5} : sum → 4+2+5 = 11
{2, 5, 6} : sum → 2+5+6 = 13
{5, 6, 3} : sum → 5+6+3 = 14
{6, 3, 8} : sum → 6+3+8 = 17
{3, 8, 1} : sum → 3+8+1 = 12
The subarray with a minimum sum of 11 is {4, 2, 5}.

Sample Input 2 :
8 4
1 -4 2 10 -2 3 1 0 -20
Sample Output 2 :
2

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubarraySum(int arr[], int n, int k) 
{
     // Write your code here 
     int manVal = INT_MAX;
     int sum = 0;
     for(int i=0;i<k;i++)
     {
          cout << "1 -- arr[i]: " << arr[i] << endl;
          sum += arr[i];
          cout << "1 -- sum :-  " << sum << endl;
     } 
     manVal = sum;

     for(int i=k;i<n;i++)
     {
          cout << "2 -- arr[i]: " << arr[i]  << "     less :- "  << arr[i-k] << endl;
          sum += arr[i]-arr[i-k];
          cout << "2 -- SUM :-  " << sum << endl;
          //if(sum > 0)
          manVal = min(manVal, sum);
     }

     return manVal;
}

int main()
{
     int arr[] = {10, 4, 2, 5, 6, 3, 8, 1};
     //int arr[] = {1, -4, 2, 10, -2, 3, 1, 0, -20};
     int k = 3;
     //int k = 4;
     int n = (sizeof(arr)/sizeof(arr[0]));
     int res = minSubarraySum(arr, n, k);
     cout << "Result:--   " << res << endl;

     return 0;
}
