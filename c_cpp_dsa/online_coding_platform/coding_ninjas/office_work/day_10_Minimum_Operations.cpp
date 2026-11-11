/*

Day 10 : Minimum Operations

 Problem statement

You are given an array 'ARR' of 'N' positive integers. You need to find the minimum number of operations needed to make all elements of the array equal. You can perform addition, multiplication, subtraction or division with any element on an array element.
Addition, Subtraction, Multiplication or Division on any element of the array will be considered as a single operation.

Example:
If the given array is [1,2,3] then the answer would be 2. One of the ways to make all the elements of the given array equal is by adding 1 to the array element with value 1 and subtracting 1 from the array element with value 3. So that final array would become [2,2,2]. 

Constraints:
1 <= T <= 10
1 <= N <= 10^5
0 <= ARR[i] <= 10^5
Where 'ARR[i]' is the element of the array 'ARR' at index 'i'.
Time Limit: 1 sec

Sample Input 1:
1
4
1 2 3 4
1
5
Sample Output 1:
3
0
Explanation for Sample Output 1:
In test case 1, There can be many ways by which we can convert the array elements equal, one of the way is:
1 + 2 = 3
2 + 1 = 3
4 - 1 = 3
Here the first operand is the element of the array and the second operand is the operation that we did for making all the numbers of the array equal.
Hence, we did 3 operations to change the elements of the array to 3. Hence the answer is 3.
In test case 2, There is only 1 element and hence no need to make equal and so answer is 0.

Sample Input 2:
2
3
2 4 2
5
1 2 1 4 1
Sample Output 2:
1
2
Explanation for Input 2:
In test case 1, by dividing 4 by 2 (i.e. 4 / 2) we can have all the elements equal to 2. Thus only 1 operation is performed and so answer is 1.
In test case 2, There can be many ways by which we can convert the array elements equal, one of the way is:
2 / 2 = 1
4 / 4 = 1
Here the first operand is the elements of the array and the second operand is the operation that we did for making all the numbers of the array equal.
Hence, we did 2 operations to change the elements of the array to 2. Hence the answer is 2.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minimumOperation(vector<int> &arr, int n) 
{
     // Write your code here.
     unordered_map<int, int> mp;
     for(int x : arr)
     {
          mp[x]++;
     }
     int maxfreq = 0;
     for(auto& m : mp)
     {
          maxfreq = max(maxfreq, m.second);
     }

     return n-maxfreq;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = minimumOperation(v, n);
     cout << "    Result:- " << res << endl;

     return 0;
}
