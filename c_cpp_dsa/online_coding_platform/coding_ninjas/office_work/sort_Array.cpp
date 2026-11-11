/*

 Sort Array

 Problem statement

You are given an array consisting of 'N' positive integers where each integer is either 0 or 1 or 2. Your task is to sort the given array in non-decreasing order.
Note :

1. The array consists of only 3 distinct integers 0, 1, 2.
2. The array is non-empty.

Constraints :
1 <= T <= 100
1 <= N <= 10^4
0 <= arr[i] <= 2
where arr[i] is the array element at index 'i'.
Time Limit: 1 sec

Sample Input 1 :
2
5
2 0 1 0 2
2
0 1
Sample Output 1 :
0 0 1 2 2
0 1
Explanation for Sample Input 1:
Test Case 1: After sorting the array in ascending order, we will get 0 0 1 2 2
Test Case 2: The array is already in ascending order.

Sample Input 2 :
2
6
2 1 0 0 1 2
3
0 0 0
Sample Output 2 :
0 0 1 1 2 2
0 0 0

*/

#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int> &arr, int n)
{
     // Write your code here.
     int low = 0, mid = 0, high = n-1;
     while(mid <= high)
     {
          if(arr[mid] == 0)
          {
               swap(arr[low], arr[mid]);     
               low++;
               mid++;
          }
          else if(arr[mid] == 1)
          {
               mid++;
          }
          else
          {
               swap(arr[mid], arr[high]);
               high--;
          }
     }
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> vec(n);
     for(int i=0;i<n;i++)
          cin >> vec[i];

     cout << "Elements Before Sorting: ";
     for(int x : vec)
          cout << x << " ";
     cout << endl;

     sortArray(vec, n);

     cout << "Elements After Sorting: ";
     for(int x : vec)
          cout << x << " ";
     cout << endl;

     return 0;
}
