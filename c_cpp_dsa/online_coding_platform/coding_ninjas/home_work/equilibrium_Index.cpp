/*

   Equilibrium Index 

   Problem statement

   You are given an array Arr consisting of N integers. You need to find the equilibrium index of the array.
   An index is considered as an equilibrium index if the sum of elements of the array to the left of that index is equal to the sum of elements to the right of it.

Note:
1. The array follows 0-based indexing, so you need to return the 0-based index of the element.
2. Note that the element at the equilibrium index won’t be considered for either left sum or right sum.
3. If there are multiple indices which satisfy the given condition, then return the left-most index i.e if there are indices i,j,k…. which are equilibrium indices, return the minimum among them
4. If no such index is present in the array, return -1.

Constraints:
1 <= T <= 50
1 <= N <= 10^5
-10^4 <= Arr[i] <= 10^4
Time Limit: 1 sec

Sample Input 1:
1
6
1 7 3 6 5 6
Sample Output 1:
3

Explanation for Sample Input 1:

The sum of elements to the left of arr[3] = 1 + 7 + 3 = 11.
The sum of elements to the right of arr[3] = 5 + 6 = 11.
Hence the answer is 3.

Sample Input 2:
2
6
1 2 2 9 3 2
4
1 2 3 4
Sample Output 2:
3
-1

Explanation for Sample Input 2:

In the first test case of sample input 2, the sum of elements on the left of index 3 (arr[3] = 9) is five which is equal to the sum of elements on the right of arr[3].
For the second test case, since no such index exists, we print -1.

 */


#include <iostream>
#include <vector>

using namespace std;

int findEquilibriumIndex(vector<int> &arr) 
{
     // Write your code here.
     int n = arr.size();
     vector<int> pre(n), pos(n);
     pre[0] = arr[0];
     for(int i=1;i<n;i++)
          pre[i] = arr[i]+pre[i-1];

     pos[n-1] = arr[n-1];
     for(int i=n-2;i>=0;i--)
          pos[i] = arr[i]+pos[i+1];

     for(int i=0;i<n;i++)
     {
          if(pre[i] == pos[i])
               return i;
     }

     return -1;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findEquilibriumIndex(v);
     cout << "     Result:- " << res << endl;     

     return 0;
}
