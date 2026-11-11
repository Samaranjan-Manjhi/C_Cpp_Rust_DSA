/*

   Dominant Number 

   Problem statement

   You are given an array of integers 'ARR' of size N. Your task is to find the dominant number in the array.
   A dominant number in an array is an integer that occurs more than N/3 times in the array, where N is the array’s length.

Note:
1. There will be only one such element (if it exists).
2. If there is no such element in the array, return -1.

For Example:
If the given array ARR = {3,3,3,1,5,6,3} we can see that here 3 occurs 4 times in the array, which is greater than 7/3(N/3), so the dominant number here is 3.

Note:
Try to solve the problem in linear time complexity

Constraints:
1 <= T <= 100
1 <= N<= 10^4
0 ≤ ARR[I] ≤ 10^5
Time Limit: 1 sec

Sample Input 1 :
3
6
3 1 1 8 1 2
3
1 2 4
4
3 2 1 3
Sample Output 1 :
1
-1
3

Explanation of The Sample Input 1:
For the first test case:
The given array is {3,1,1,8,1,2} we can see that 3 occurred three times in the array, which is greater than 6/3, so the dominant number will be 3. 

For the second test case:
The given array is {1,2,4} we can see that no number here is repeated more than once, so the answer here will be -1.

For the third test case
The given array is {3,2,1,3} we can see that  3 occurred two times in the array, which is greater than 4/3, so the dominant number will be 3. 

Sample Input 2 :
3
4
4 4 4 1
7
5 6 6 4 3 2 6
8
1 9 8 4 5 5 5 5
Sample Output 2 :
4
6
5

 */

#include <iostream>

using namespace std;

int dominantNumber(int* arr, int n) 
{
     // Write your code here.
     int cnd = 0, cnd1 = 0;
     int cnt = 0, cnt1 = 0;
     for(int i=0;i<n;i++)
     {
          if(cnd == arr[i])
          {
               cnt++;
          }
          else if(cnd1 == arr[i])
          {
               cnt1++;
          }
          else if(cnt == 0)
          {
               cnd = arr[i];
               cnt = 1;
          }
          else if(cnt1 == 0)
          {
               cnd1 = arr[i];
               cnt1 = 1;
          }
          else
          {
               cnt--;
               cnt1--;
          }
     }

     cnt = 0, cnt1 = 0;
     for(int i=0;i<n;i++)
     {
          if(arr[i] == cnd)
               cnt++;
          else if(arr[i] == cnd1)
               cnt1++;
     }

     if(cnt > n/3)
          return cnd;

     if(cnt1 > n/3)
          return cnd1;

     return -1;
}


int main()
{
     int n;

     cout << "Enter the size of the array: ";
     cin >> n;

     int arr[n];

     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }

     int result = dominantNumber(arr, n);

     if (result != -1)
          printf("Dominant number: %d\n", result);
     else
          printf("No dominant number found.\n");

     return 0;
}
