/*

   Rotate array

   Problem statement

   Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.

Example:
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.

Sample Input 1:
8
7 5 2 11 2 43 1 1
2
Sample Output 1:
2 11 2 43 1 1 7 5
Explanation of Sample Input 1:
Rotate 1 steps to the left: 5 2 11 2 43 1 1 7
Rotate 2 steps to the left: 2 11 2 43 1 1 7 5

Sample Input 2:
4
5 6 7 8
3
Sample Output 2:
8 5 6 7
Explanation of Sample Input 2:
Rotate 1 steps to the left: 6 7 8 5
Rotate 2 steps to the left: 7 8 5 6
Rotate 2 steps to the left: 8 5 6 7

Expected Time Complexity:
O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.

Constraints:
1 <= 'n' <= 10^3
1 <= 'arr'[i] <= 10^9
1 <= 'k' < 'n'

Hints:
1. For an index ‘i’, find where it lands after k swaps.
2. When performing rotation once observe how the positions of all elements change.

 */

#include <iostream>
#include <vector>

using namespace std;

void doSwap(vector<int>& v, int l, int r)
{
     while(l < r)
     {
          swap(v[l], v[r]);
          l++;
          r--;
     }
}

vector<int> rotateArray(vector<int>arr, int k) 
{
     // Write your code here.
     vector<int> res(arr.begin(), arr.end());
     int n = res.size();
     k = k % n;
     doSwap(res, 0, k-1);
     doSwap(res, k, n-1);
     doSwap(res, 0, n-1);

     return res;
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

     vector<int> res = rotateArray(v, k);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
