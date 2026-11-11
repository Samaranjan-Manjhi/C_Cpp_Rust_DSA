/*

   Minimum number of swaps required to sort an array

   Problem statement

   You have been given an array 'ARR' of 'N' distinct elements.
   Your task is to find the minimum no. of swaps required to sort the array.
   For example:
   For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].

Constraints:
1 <= T <= 100
1 <= N <= 1000
0 <= ARR[i] <= 10 ^ 9
Where 'ARR[i]' is the value of the input array elements.
Time Limit: 1 sec

Sample Input 1:
2
4
4 3 2 1
5
1 5 4 3 2
Sample Output 1:
2
2

Explanation of Sample Input 1:
For the first test case, swap index 0 with 3 i.e. 4 -> 1 and 1 with 2 i.e. 3 -> 2 to form the sorted array {1, 2, 3, 4}.
For the second test case, swap index 1 with 4 i.e. 5 -> 2 and 2 with 3 i.e. 4 -> 3 to form the sorted array {1, 2, 3, 4, 5}.

Sample Input 2:
2
4
1 2 3 4
6
3 5 2 4 6 8
Sample Output 2:
0
3

 */


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> &arr)
{
     // Write your code here.
     vector<int> temp(arr.begin(), arr.end());
     sort(temp.begin(), temp.end());

     unordered_map<int, int> mp;
     for(int i=0;i<arr.size();i++)
          mp[arr[i]] = i;

     int cnt = 0;
     for(int i=0;i<arr.size();i++)
     {
          if(temp[i] != arr[i])
          {
               int ids = mp[temp[i]];
               swap(arr[i], arr[ids]);

               mp[arr[i]] = i;
               mp[arr[ids]] = ids;

               cnt++;
          }
     }
     return cnt;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = minSwaps(v);
     cout << "     Result:- " << res << endl;

     return 0;
}
