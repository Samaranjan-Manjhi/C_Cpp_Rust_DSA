/*

   Problem statement

   You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

Constraints:
1 <= N <= 10^3
-10^5 <= ARR[i] <= 10^5
-2 * 10^5 <= S <= 2 * 10^5
Time Limit: 1 sec

Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
2 + 3 = 5
Hence the output will be, (1,4) , (2,3).

Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
     // Write your code here.
     vector<vector<int>> res;
     sort(arr.begin(), arr.end());
     int n = arr.size();
     int l = 0, r = n - 1;
     while (l < r)
     {
          int sum = arr[l] + arr[r];
          if (sum == s)
          {
               // if both values are same
               if (arr[l] == arr[r])
               {
                    int count = r - l + 1;
                    int totalPairs = (count * (count - 1)) / 2;
                    for (int i = 0; i < totalPairs; i++)
                    {
                         res.push_back({arr[l], arr[r]});
                    }
                    break;
               }
               // count duplicates on left
               int leftCount = 1;
               while (l + leftCount < r && arr[l + leftCount] == arr[l])
                    leftCount++;
               // count duplicates on right
               int rightCount = 1;
               while (r - rightCount > l && arr[r - rightCount] == arr[r])
                    rightCount++;
               // total pairs formed
               int totalPairs = leftCount * rightCount;
               for (int i = 0; i < totalPairs; i++)
               {
                    res.push_back({arr[l], arr[r]});
               }
               l += leftCount;
               r -= rightCount;
          }
          else if (sum < s)
          {
               l++;
          }
          else
          {
               r--;
          }
     }

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

     int tar;
     cout << "Enter Target Value: ";
     cin >> tar;

     vector<vector<int>> res = pairSum(v, tar);
     for(int i=0;i<res.size();i++)
     {
          cout << res[i][0] << "  " << res[i][1] << endl;
     }

     return 0;
}
