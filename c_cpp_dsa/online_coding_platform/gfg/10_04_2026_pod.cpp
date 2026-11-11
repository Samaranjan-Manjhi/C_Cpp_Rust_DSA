/*
Given an array arr[], find any subsequence of three elements such that, arr[i] < arr[j] < arr[k] and (i < j < k).

If such a subsequence exists, return the three elements as an array. Otherwise, return an empty array.

Note:

    The driver code will print 1 if the returned subsequence is valid and present in the array.
    The driver code will print 0 if no such subsequence exists.
    If the returned subsequence does not satisfy the required format or conditions, the output will be -1.
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
     //vector<int> arr{12, 11, 10, 5, 6, 2, 30};
     vector<int> arr{1, 2, 3, 4};
     //vector<int> v{4, 3, 2, 1};
     int n = arr.size();
     vector<int> res;
     for(int i=0;i<n-2;i++)
     {
          for(int j=i+1;j<n-1;j++)
          {
               for(int k=j+1;k<n;k++)
               {
                    if(arr[i] < arr[j] && arr[j] < arr[k])
                         cout << arr[i]  << "   " << arr[j]  << "     " << arr[k] << endl;
               }
          }
     }
     return 0;
}
