/*

   Single Number II 

   Problem statement

   You are given an arbitrary array ‘arr’ consisting of N non-negative integers, where every element appears thrice except one. You need to find the element that appears only once.

Constraints:
1 <= T <= 100
4 <= N <= 10^4
0 <= arr[i] < 10^9
Time Limit: 1sec

Sample Input 1:
1
4
1 2 1 1
Sample Output 1:
2

Explanation For Sample Input 1:
Clearly, the 2 appears once while 1 appears thrice. Hence, 2 is the output.

Sample Input 2:
1
7 
1 3 3 3 1 1 4
Sample Output 2:
4

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int elementThatAppearsOnce(vector<int> arr) 
{
     // Write your code here.
     unordered_map<int, int> mp;
     for(int x : arr)
          mp[x]++;

     for(auto& m : mp)
     {
          if(m.second < 2)
               return m.first;
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

     int res = elementThatAppearsOnce(v);
     cout << "     Result:- " << res << endl;     

     return 0;
}
