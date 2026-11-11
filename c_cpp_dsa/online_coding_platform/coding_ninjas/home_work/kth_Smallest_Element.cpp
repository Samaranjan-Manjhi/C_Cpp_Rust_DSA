/*

Kth Smallest Element

 Problem statement

You are given an array of integers 'ARR' of size 'N' and another integer 'K'.
Your task is to find and return 'K'th smallest value present in the array.
Note: All the elements in the array are distinct.

Example
If 'N' is 5 and 'K' is 3 and the array is 7, 2, 6, 1, 9
Sorting the array we get 1, 2, 6, 7, 9
Hence the 3rd smallest number is 6.

Sample Input 1:
7 5
5 9 1 8 10 6 4 
Sample Output 1:
8
Explanation of Input 1:
Sorted array will be 1 4 5 6 8 9 10, this shows that 8 is the fifth-smallest element in the array.

Sample Input 2:
7 2
24 8 23 28 3 1 19 
Sample Output 2:
3

Constraints:
1 <= N <=10 ^ 4
1 <= K <= N
1 <= ARR[i] <= 10 ^ 9
Time limit: 1 sec.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(int n,int k,vector<int> Arr)
{
     // Write your code here.
     priority_queue<int> maxHeap;
     for(int i=0;i<k;i++)
     {
          maxHeap.push(Arr[i]);
     }

     for(int i=k;i<n;i++)
     {
          if(Arr[i] < maxHeap.top())
          {
               maxHeap.pop();
               maxHeap.push(Arr[i]);
          }
     }
     return maxHeap.top();
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
     cout << "Enter k Value: ";
     cin >> k;

     int res = kthSmallest(n, k, v);
     cout << "    Result:- " << res << endl;

     return 0;
}
