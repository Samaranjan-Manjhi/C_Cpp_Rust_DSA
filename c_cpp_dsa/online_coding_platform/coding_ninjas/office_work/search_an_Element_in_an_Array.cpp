/*

   Search an Element in an Array 

   Problem statement

   You have given a sorted array 'A' of 'N' integers.

   Now, you are given 'Q' queries, and each query consists of a single integer 'X'. Your task is to check whether 'X' is present in array 'A' or not for each query. If 'X' exists in array 'A', you need to print 1 else print 0.

Note :
The given array is sorted in non-decreasing order. 

Constraints:
1 <= T <= 10 
1 <= N <= 10^5    
-10^9 <= A[i] <= 10^9 
1 <= Q <= 10^4
-10^9 <= X <= 10^9

Where 'T' represents the number of test cases, 'N' represents the size of the array, 'A[i]' represents the elements of the array, 'Q' represents the number of queries and, 'X' denotes the number to be searched.
Time limit: 1 sec

Sample Input 1:
1
5
1 3 5 7 8
2
5
2
Sample Output 1:
1 0

Explanation for sample input 1:

For the first test case, the given array A is [1, 3, 5, 7,8].
So the answer for the given first query is 1 as 5 is present in the array.
For the second query answer is 0 as 2 is not present in the array.  

Sample Input 2:
1
6
1 2 2 3 4 10
3
5
7 
2
Sample Output 2:
0 0 1

Explanation for sample input 2:

For the first test case, the given array A is [1, 2, 2, 3, 4, 10].
So the answer for the given first query is 0 as 5 is not present in the array.
For the given second query answer is 0 as 7 is not present in the array.  
For the given third query answer is 1 as 2 is present in the array.

 */


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> searchInSortedArray(vector<int> &arr, int n, vector<int> &queries, int q)
{
     // Write your code here.
     vector<int> res;
     unordered_set<int> seen(arr.begin(), arr.end());
     for(int i=0;i<q;i++)
     {
          if(seen.find(queries[i]) != seen.end())
          {
               res.push_back(1);
          }	
          else
          {
               res.push_back(0);
          }
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Input Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int q;
     cout << "Enter Queries Vector Size: ";
     cin >> q;

     vector<int> qu(q);
     for(int i=0;i<q;i++)
          cin >> qu[i];

     vector<int> res = searchInSortedArray(v, n, qu, q);
     if(!res.empty())
     {
          cout << "   Result:- ";
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
