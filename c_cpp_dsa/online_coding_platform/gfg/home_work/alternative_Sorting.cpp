/*

   Alternative Sorting

   Given an array arr of distinct integers. Rearrange the array in such a way that the first element is the largest and the second element is the smallest, the third element is the second largest and the fourth element is the second smallest, and so on.

Examples:

Input: arr[] = [7, 1, 2, 3, 4, 5, 6]
Output: [7, 1, 6, 2, 5, 3, 4]
Explanation: The first element is first maximum and second element is first minimum and so on.

Input: arr[] = [1, 6, 9, 4, 3, 7, 8, 2]
Output: [9, 1, 8, 2, 7, 3, 6, 4]
Explanation: The first element is first maximum and second element is first minimum and so on.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> alternateSort(vector<int>& arr) 
{
     // Your code goes here
     int n = arr.size();
     sort(arr.begin(), arr.end());
     vector<int> temp;
     for(int i=0;i<n/2;i++)
     {
          temp.push_back(arr[n-i-1]);
          temp.push_back(arr[i]);
     }
     if(n%2 != 0)
          temp.push_back(arr[n/2]);
     return temp;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "Elements Before alternateSort Operation:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;
     vector<int> res = alternateSort(v);
     cout << "Elements After alternateSort Operation:- ";
     for(int x : res)
          cout << x << " ";
     cout << endl;     

     return 0;
}
