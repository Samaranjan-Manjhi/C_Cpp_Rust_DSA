/*

   Anagram Mapping 

   Problem statement

   You are given two arrays ‘A’ and ‘B’, each containing ‘N’ distinct integers. You are also given that ‘B’ is an anagram of ‘A’
   Find the index mapping from array ‘A’ to array ‘B’, ie: for each element in ‘A’ you need to find the index in ‘B’ corresponding to that element.
   An array ‘B’ is an anagram of an array ‘A’ means ‘B’ is made by randomizing the order of the elements in ‘A’.
   For Example :
   If ‘N’ = 5, ‘A’ = {10, 20, 30, 40, 50} and ‘B’ = {20, 10, 40, 50, 30}
   Then we will print {1, 0, 4, 2, 3} because:
   A[0] occurs at 1st index in array B, A[1] occurs at 0th index, A[2] occurs at 4th index, A[3] occurs at 2nd index, A[4] occurs at 3rd index.

Constraints :
1 ≤ T ≤ 10      
1 ≤ N ≤ 10000
-10^9 ≤ A[i], B[i] ≤ 10^9
Time limit: 1 sec

Sample Input 1 :
2
5
10 20 30 40 50
20 10 40 50 30
5
10 20 30 40 50
10 20 30 40 50
Sample Output 1 :
1 0 4 2 3
0 1 2 3 4

Explanation For Sample Input 1 :
For test case 1 :
We will print {1, 0, 4, 2, 3} because:
A[0] occurs at 1st index in array B, A[1] occurs at 0th index, A[2] occurs at 4th index, A[3] occurs at 2nd index, A[4] occurs at 3rd index. 

For test case 2 : 
We will print {0, 1, 2, 3, 4} because:
Array ‘A’ is the same as array ‘B’, as they both have the same ordering of elements.

Sample Input 2 :
2
3
1 2 3
3 2 1
3
1 2 3
3 1 2
Sample Output 2 :
2 1 0
1 2 0

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> anagramMapping(int n, vector<int> a, vector<int> b) 
{
     // Write your code here.
     unordered_map<int, int> mp;
     for(int i=0;i<b.size();i++)
          mp[b[i]] = i;

     vector<int> res;
     for(int i=0;i<a.size();i++)
     {
          int cnt = mp[a[i]];
          res.push_back(cnt);
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> a(n), b(n);
     for(int i=0;i<n;i++)
          cin >> a[i];

     for(int i=0;i<n;i++)
          cin >> b[i];

     vector<int> res = anagramMapping(n, a, b);
     cout << "    Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
