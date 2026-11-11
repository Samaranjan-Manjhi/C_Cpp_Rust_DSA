/*

Frequency In A Sorted Array

 Problem statement

You are given a sorted array 'ARR' and a number 'X'. Your task is to count the number of occurrences of 'X' in 'ARR'.
Note :
1. If 'X' is not found in the array, return 0.
2. The given array is sorted in non-decreasing order.

Constraints :
1 <= T <= 10^2
1 <= N <= 10^4
0 <= ARR[i], X <= 10^9
Time Limit : 1 sec

Sample Input 1 :
2
7
1 1 2 2 2 2 3
2
5
1 2 2 3 3
4
Sample Output 1 :
4
0
Explanation For Sample Input 1 :
For the first test case, the target element 2 occurs four times in the array at indexes from 2 to 5. 
For the second test case, the target element 4 doesn’t occur in the array.

Sample Input 2 :
2
4
2 3 4 4
4
6
5 7 7 8 8 10
10
Sample Output 2 :
2
1

*/

#include <iostream>
#include <vector>

using namespace std;

int countOccurrences(vector<int> arr, int x) 
{
     // Write your code here.
     int cnt = 0;
     for(int val : arr)
     {
          if(val == x)
               cnt++;
     }
     return cnt;
}

int main()
{
     int n;
     cout << "Enter Vcetor Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int x;
     cout << "Enter Value of X: ";
     cin >> x;

     int res = countOccurrences(v, x);
     cout << "     Result:- " << res << endl;

     return 0;
}
