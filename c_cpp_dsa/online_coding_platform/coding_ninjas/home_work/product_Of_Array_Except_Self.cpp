/*

   Product Of Array Except Self

   Problem statement

   You have been given an integer array/list (ARR) of size N. You have to return an array/list PRODUCT such that PRODUCT[i] is equal to the product of all the elements of ARR except ARR[i]
Note :

Each product can cross the integer limits, so we should take modulo of the operation. 
Take MOD = 10^9 + 7 to always stay in the limits.

Follow up :
Can you try solving the problem in O(1) space?

Constraints :
1 <= T <= 100
0 <= N <= 10^5
0 <= ARR[i] <= 10^5
Time Limit: 1 sec

Sample Input 1 :
2
3
1 2 3
3
5 2 2
Sample Output 1 :
6 3 2
4 10 10

Explanation for Sample Output 1 :
Test case 1 : Given array = {1, 2, 3] 
Required array = [2 * 3, 1 * 3, 1 * 2] = [6, 3, 2]
Test case 2 : Given array = {5, 2, 2] 
Required array = [2 * 2, 5 * 2, 5 * 2] = [4, 10, 10]

Sample Input 2 :
2
1
100
2
1 2
Sample Output 2 :
1
2 1

 */


#include <iostream>

using namespace std;

int *getProductArrayExceptSelf(int *arr, int n)
{
     //Write your code here
     const long long MOD = 1e9 + 7;
     int *ans = new int[n];
     long long prefix = 1;
     // Prefix product
     for (int i = 0; i < n; i++)
     {
          ans[i] = prefix;
          prefix = (prefix * arr[i]) % MOD;
     }

     long long suffix = 1;
     // Suffix product
     for (int i = n - 1; i >= 0; i--)
     {
          ans[i] = (ans[i] * suffix) % MOD;
          suffix = (suffix * arr[i]) % MOD;
     }

     return ans;
}

int main()
{
     int n;
     cout << "Enter Array Size: ";
     cin >> n;

     int arr[n];
     for(int i=0;i<n;i++)
          cin >> arr[i];

     int *ans = getProductArrayExceptSelf(arr, n);
     cout << "     Result:- ";
     for(int i=0;i<n;i++)
     {
          cout << ans[i] << " ";
     }
     cout << endl;

     return 0;
}
