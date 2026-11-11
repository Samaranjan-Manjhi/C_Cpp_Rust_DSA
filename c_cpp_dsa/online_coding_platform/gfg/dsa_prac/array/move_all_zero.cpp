/*

You are given an array arr[] of non-negative integers. You have to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.

Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.

Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
Expected Complexities
Company Tags
Paytm Amazon Microsoft Samsung SAP Labs Linkedin Bloomberg NPCI

*/

#include <iostream>
#include <vector>
using namespace std;

void pushZerosToEnd(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     /*
     for(int i=0;i<n;i++)
     {
          for(int j=i+1;j<n;j++)
          {
               if(arr[i] == 0 && arr[j] != 0)
               {
                    swap(arr[i], arr[j]);
               }
          }
     }
     */

     int l = 0, r = 0;
     while(r < n)
     {
          if(arr[l] == 0 && arr[r] != 0)
          {
               swap(arr[l], arr[r]);
               l++;
          }
          if(arr[l] != 0)
               l++;
          r++;
     } 
}

void printVec(vector<int> v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     printVec(v);
     pushZerosToEnd(v);
     printVec(v);

     return 0;
}
