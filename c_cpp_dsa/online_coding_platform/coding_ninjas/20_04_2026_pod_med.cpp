/*
   Problem statement

   Given an array 'ARR'' of 'N' integers and an integer 'target', your task is to find three integers in 'ARR' such that the sum is closest to the target.
   Note

   In the case of two closest sums, print the smallest sum.

   Sample Input 1

   2
   4
   -1 2 1 -4
   1
   5
   1 2 3 4 -5
   10

   Sample Output 1

   2 
   9

   Explanation of Sample Input 1

   Test Case 1:
   Sum of triplets:
   (-1) + 2 + 1 = 2
   (-1) + 2 + (-4) = -3
   2 + 1 + (-4) = -1
   (-1) + 1 + (-4) = -4
   Out of all the triplet sums, 2 is closest to 1.

   Test Case 2: Sum of triplet {2, 3, 4 } i.e. 9 is the closest sum to 10.

   Sample Output 2

   2
   5
   10 12 7 8 -5
   16
   4
   6 8 2 5
   20

   Sample Output 2

   15
   19

 */

#include <iostream>
#include <vector>
using namespace std;

//int closest3Sum(vector<int> &arr, int n, int target)
int closest3Sum(vector<int> &arr, int target)
{
     // Write your code here
     int sum = 0, res = 0;
     for(int x : arr) sum += x;
     int n = arr.size();
     for(int i=0;i<n-2;i++)
     {
          for(int j=i+1;j<n-1;j++)
          {
               for(int k=j+1;k<n;k++)
               {
                    //if(arr[i]+arr[j]+arr[k] <= target && arr[i]+arr[j]+arr[k] <= sum)
                    if(arr[i]+arr[j]+arr[k] <= target)
                    {
                         //cout << arr[i] << "   " << arr[j] << "     " << arr[k] << endl;
                         res += arr[i]+arr[j]+arr[k];
                    }
               }
          }
     }  
     return res;
}

int main()
{
vector<int> v{-1, 2, 1, -4}; // 1
//vector<int> v{1, 2, 3, 4, -5}; // 10
//vector<int> v{10, 12, 7, 8, -5}; // 16
//vector<int> v{6, 8, 2, 5}; // 20
cout << "Result: " << closest3Sum(v, 1) << endl;
return 0;
}

