/*

 Problem statement

You are given a sorted array of ‘N’ distinct integers that are in the Arithmetic Progression sequence except for one element which is missing from the sequence. You have to find that missing number from the given sequence.
Note:

1. A sequence [arr0, arr1,…, arr(n-1)] is called an Arithmetic progression if for each 'i' ( 0 ≤ i < n - 1) the value arr[i+1] − arr[i] is the same. 
2. There is exactly one missing number in the given sequence.
3. All the numbers present in the sequence are distinct.
4. It is the guarantee that the first and last elements of the sequence are not missing elements.
Follow Up
The overall run time complexity should be O(log(N)).

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
3 <= N <= 10 ^ 4   
-10 ^ 9 <= Arr[i] <= 10 ^ 9 
Where ‘T’ is the number of test cases, ‘N’ is the size of the array and ‘Arr[i]’ is the size of the array elements.
Time Limit: 1 sec

Sample Input 1:
2
3
1 4 10
4
5 10 20 25 
Sample Output 1:
 7
 15

Explanation for sample input 1:
Test case 1:
The arithmetic sequence present in the first test case will have its first term as 4 and common difference as 3. So, the complete sequence will look like this ....- 1 4 7 10... Hence 7 is the missing element in the given sequence.

Test case 2:
The first term and common difference will be 5. The complete sequence will be ...5 10 15 20 25.... Hence 15 is the missing element from the given sequence.

Sample Input 2:
3
3
-1 0 2
5 
10 20 30 50 60
4
12 18 21 24
Sample Output 2:
1
40
15

*/


#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &arr, int n) 
{
     // Write your code here.
     if(n <= 2 )
          return 0;
     int x = arr[1] - arr[0];
     int y = arr[2] - arr[1];
     int a = min(x, y);
     for(int i=1;i<n;i++)
     {
          if(arr[i] != arr[i-1]+a)
               return arr[i-1]+a;
          else
               continue;
     }
     return 0;
}

int main()
{
int n;
cout << "Enter size of Vector: ";
cin >> n;

vector<int> v(n);
for(int i=0;i<n;i++)
     cin >> v[i];

int res = missingNumber(v, n);
cout << "Result:- " << res << endl;

return 0;
}
