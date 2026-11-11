/*

   First and Second Smallests

   Given an array, arr[] of integers, your task is to return the smallest and second smallest element in the array. If the smallest and second smallest do not exist, return -1.

Examples:

Input: arr[] = [2, 4, 3, 5, 6]
Output: [2, 3] 
Explanation: 2 and 3 are respectively the smallest and second smallest elements in the array.

Input: arr[] = [1, 1, 1]
Output: [-1]
Explanation: Only element is 1 which is smallest, so there is no second smallest element.

Constraints:
1 ≤ arr.size ≤10^5
1 ≤ arr[i] ≤ 10^5

 */


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> minAnd2ndMin(vector<int> &arr) 
{
     // code here
     int n = arr.size();
     int sm = INT_MAX;
     int ssm = INT_MAX;
     for(int i=0;i<n;i++)
     {
          if(arr[i] < sm)
          {
               ssm = sm;
               sm = arr[i];
          }
          else if(arr[i] > sm && arr[i] < ssm)
          {
               ssm = arr[i];
          }
     }

     if(sm == INT_MAX || ssm == INT_MAX)
          return {-1};

     return {sm, ssm};
}

int main()
{
     int m;
     cout << "Enter Vector Size: ";
     cin >> m;

     vector<int> v1(m);
     for(int i=0;i<m;i++)
          cin >> v1[i];

     vector<int> res = minAnd2ndMin(v1);
     cout << "    Result :-  ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
