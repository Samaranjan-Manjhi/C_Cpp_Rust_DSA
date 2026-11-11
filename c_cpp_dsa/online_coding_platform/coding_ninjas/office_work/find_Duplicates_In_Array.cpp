/*

Find Duplicates In Array

 Problem statement

You are given an array/list 'ARR' consisting of N integers, which contains elements only in the range 0 to N - 1. Some of the elements may be repeated in 'ARR'. Your task is to find all such duplicate elements.
Note:
1. All the elements are in the range 0 to N - 1.
2. The elements may not be in sorted order.
3. You can return the duplicate elements in any order.
4. If there are no duplicates present then return an empty array.

Constraints:
1 <= T <=  10^2
1 <= N <= 10^4
0 <= ARR[i] <= N - 1
Time Limit: 1 sec

Sample Input 1:
2
5
0 2 1 2 3 
7
3 2 1 3 2 1 5
Sample Output 1:
2
1 2 3
Explanation For Sample Input 1:
For the first test case, since 2 is the only duplicate element, so we return it.
For the second test case, since 1, 2, 3 are duplicates so we return them. Note that 2, 3, 1 and 3, 2, 1 are also acceptable.

Sample Input 2:
1
3
0 1 2
Sample Output 2:
-1
Explanation For Sample Input 2:
For the first test case, since there are no duplicates we return -1.

*/

#include <iostream>
#include <vector>

using namespace std;

vector < int > findDuplicates(vector < int > & arr, int n) 
{
     // Write your code here.
     vector<int> ans;
     vector<int> freq(n, 0);
     for(int x : arr)
     {
          freq[x]++;
     }

     for(int i=0;i<n;i++)
     {
          if(freq[i]>=2)
               ans.push_back(i);
     }

     return ans;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = findDuplicates(v, n);
     cout << "    Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
