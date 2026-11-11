/*

Reduce Elements by K

You are given an array arr[] and an integer k. In one operation you can choose any element of array and decrease its value by k.
Find the minimum number of operation such that all the elements in the array becomes less or equal to k.

Examples:

Input: arr[] = [5, 3, 2, 6, 8] and k = 5
Output: 2
Explanation: 
Elements 5, 3, and 2 are already less than or equal to 5.
Element 6 can be reduced by 5 in one operation to become 1.
Element 8 can be reduced by 5 in one operation to become 3.
Thus, a total of 2 operations are required.

Input: arr[] = [2, 6, 4, 8, 1, 6] and k = 4 
Output: 3 
Explanation: 
Elements 2, 4, and 1 are already less than or equal to 4.
Each occurrence of 6 can be reduced by 4 in one operation to become 2, requiring 2 operations.
Element 8 can be reduced by 4 in one operation to become 4, requiring 1 operation.
Therefore, the minimum number of operations required is 3.

Constraints :
1 ≤ arr.size() ≤ 2*10^4
1 ≤ k ≤ 10^5
1 ≤ arr[i] ≤ 10^5

*/

#include <iostream>
#include <vector>

using namespace std;

int minOps(vector<int>& arr, int k) 
{
     // code here
     int cnt = 0;
     for(int i=0;i<arr.size();i++)
     {
          if(arr[i] > k)
          {
               if(arr[i] % k == 0)
                    cnt += (arr[i]/k) - 1;
               else
                    cnt += arr[i]/k;
          }    
     }

     return cnt;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int k;
     cout << "Enter K value: ";
     cin >> k;

     int res = minOps(v, k);
     cout << "    Result:- " << res << endl;

     return 0;
}
