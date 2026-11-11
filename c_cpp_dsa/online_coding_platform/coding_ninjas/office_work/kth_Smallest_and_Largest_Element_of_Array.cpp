/*

   Kth Smallest and Largest Element of Array

   Problem statement

   You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.

Example:

Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.

Constraints:
1 <= T <= 50
1 <= N <= 10^4
1 <= K <= N
-10^9 <= Arr[i] <= 10^9
Where ‘T’ is the total number of test cases, ‘N’ is the size of array ‘Arr’ and Arr[i] is the element of the given array.
Time limit: 1 sec

Sample Input 1:
2
4 4
5 6 7 2
4 3
1 2 5 4
Sample Output 1:
7 2 
4 2

Explanation of Sample Input 1:

Test case 1:
Here, ‘N’ = 4, ‘Arr’ = [5, 6, 7, 2] and ‘K’ = 3.
Elements of the array in ascending order are [2, 5, 6, 7]
Thus the 4rd smallest and 4rd largest elements of this array are 7 and 2 respectively.

Test case 2:
See problem statement for an explanation.

Sample Input 2:
2
1 1
2
5 1
5 4 3 2 1
Sample Output 2:
2 2
1 5

 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
     // Write your code here.
     /*
        sort(arr.begin(), arr.end());
        return {arr[k-1], arr[n-k]};
      */

     priority_queue<int> maxHeap;

     // Min-Heap for Kth largest
     priority_queue<int, vector<int>, greater<int>> minHeap;

     for (int i = 0; i < n; i++) 
     {
          // It will give Kth smallest
          maxHeap.push(arr[i]);
          if (maxHeap.size() > k) 
          {
               maxHeap.pop();
          }

          // gives Kth largest
          minHeap.push(arr[i]);
          if (minHeap.size() > k) 
          {
               minHeap.pop();
          }
     }

     // maxHeap.top() = Kth smallest
     // minHeap.top() = Kth largest
     return {maxHeap.top(), minHeap.top()};
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

     vector<int> res = kthSmallLarge(v, n, k);
     cout << "   Result:-  ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
