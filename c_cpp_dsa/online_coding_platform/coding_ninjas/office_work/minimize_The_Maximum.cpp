/*

   Minimize The Maximum

   Problem statement

   You are given an array of N integers and an integer K. For each array element, you are allowed to increase or decrease it by a value k. The task is to minimize the difference between the maximum element and the minimum element after modifications.
Constraints :
1 <= T <= 5
1 <= N <= 10^5
0 <= arr[i] <= 10^5
0 <= K <= 10^5
Time limit = 1 sec

Sample Input 1 :
1
3
1 15 10
6
Sample Output 1:
5

Explanation For Sample Input 1 :
Arrays that can be obtained by either increasing or decreasing each element by k are
[-5 9 4]   difference between maximum and minimum is 16
[-5 9 16] difference between maximum and minimum is 21
[-5 21 16] difference between maximum and minimum is 26
[-5 21 4] difference between maximum and minimum is 26
[7 9 4]   difference between maximum and minimum is 5
[7 9 16] difference between maximum and minimum is 9
[7 21 16] difference between maximum and minimum is 14
[7 21 4] difference between maximum and minimum is 17
So the minimum of all differences between maximum and minimum elements is 5. So, we need to return 5.

Sample Input 2 :
1
3
1 2 3 
2
Sample Output 2:
2

 */


#include <iostream>
#include <algorithm>

using namespace std;

int minimizeMaximum(int arr[], int n, int k)
{
     // Write your code here.
     sort(arr, arr+n);
     int ans = arr[n-1] - arr[0];
     for(int i=0;i<n-1;i++)
     {
          int newMin = min(arr[0]+k, arr[i+1]-k);
          int newMax = max(arr[i]+k, arr[n-1]-k);

          int curr = newMax - newMin;

          ans = min(curr, ans); 
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

     int k;
     cout << "Enter k value: ";
     cin >> k;

     int res = minimizeMaximum(arr, n, k);
     cout << "    Result:- " << res << endl;

     return 0;
}
