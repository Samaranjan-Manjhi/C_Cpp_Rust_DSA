/*

Minimum move to front operations

Given an array arr[] of distinct integers from 1 to arr.size(), count the minimum number of moveToFront operations needed to arrange the elements in ascending order (1, 2, 3, ..., arr.size()). A moveToFront operation picks any element arr[i] and places it at the first position.

Examples:

Input: arr[] = [3, 2, 1, 4]
Output: 2
Explanation: We need to perform moveToFront on 1 and 2 to make the array sorted.

Input: arr[] = [5, 7, 4, 3, 2, 6, 1]
Output: 6
Explanation: We need to perform moveToFront on 1, 2, 3, 4, 5, and 6 to make the array sorted.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
Elements in arr are distinct and range from 1 to arr.size()

*/

#include <iostream>
#include <vector>

using namespace std;

int minMoves(vector<int> &arr) 
{
     // code here.
     int tar = arr.size();
     for (int i=arr.size(); i>=0; i--)
     {
          if (arr[i] == tar)
               tar--;
     }
     return tar;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = minMoves(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
