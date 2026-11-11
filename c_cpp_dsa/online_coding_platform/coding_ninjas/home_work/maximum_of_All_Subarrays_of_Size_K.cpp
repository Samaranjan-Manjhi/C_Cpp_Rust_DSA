/*

   Maximum of All Subarrays of Size K

   Problem statement

   You are given an array “A” of N integers. Your task is to find the maximum element in all K sized contiguous subarrays from left to right.
   For Example:

   If A = [3, 2, 3], and K = 2.
   Then max of [3, 2] = 3 and max of [2, 3] = 3
   So, the answer will be [3, 3]

   If A = [3, 2, 3, 5, 1, 7] and K = 3.
   Then max of [3, 2, 3] = 3 
   Then max of [2, 3, 5] = 5 
   Then max of [3, 5, 1] = 5 
   Then max of [5, 1, 7] = 7 
   So  the answer will be [3, 5, 5, 7]

   Follow Up :
   Can you solve the problem in O(N) time complexity and O(K) space complexity?

Constraints :
1 <= T <= 10    
1 <= N <= 10^5 
1 <= K <= N
1 <= A[i] <= 10^9
Time Limit: 1sec

Sample Input 1 :

2 
3 1
2 1 1
3 2
1 1 3
Sample Output 1 :
2 1 1
1 3

Explanation For Sample Input 1:
For the first test case,the given A = [2, 1, 1]  and K = 1
Therefore, max([2]) = 2 , max([1]) = 1, max([1]) = 1
Hence our answer is [2, 1, 1] 

For the second test case, the given A = [1, 1, 3] and K = 2 
Therefore, max([1, 1]) = 1, max([1, 3]) = 3
Hence our answer is [1, 3].

Sample Input 2 :
2
3 2
1 3 1
5 3
1 2 3 4 5
Sample Output 2 :
3 3
3 4 5

 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> maximumInAllSubarraysOfSizeK(vector<int> arr, int n, int k)
{
     // Write down your code here
     vector<int> res;
     if(k == 1)
          return arr;
     
     for(int i=0;i<n-k;i++)
     {
          
     }
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

     vector<int> res = maximumInAllSubarraysOfSizeK(v, n, k); 
     if(!res.empty())
     {
          cout << "     Result:- ";
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
