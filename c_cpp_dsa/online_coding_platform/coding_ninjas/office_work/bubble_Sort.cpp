/*

Bubble Sort 

 Problem statement

Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Arr[i] <= 1000
Where 'T' represents the number of test cases, 'N' represents the size of the array, and Arr[i] represents the elements of the array.
Time Limit: 1 sec.

Sample Input 1:
1
5
6 2 8 4 10
Sample Output 1:
2 4 6 8 10

Sample Input 2:
2
2
1 2
4
4 3 2 1
Sample Output 2:
1 2
1 2 3 4

*/

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
     // Write your code here.
     for(int i=0;i<n-1;i++)
     {
          for(int j=0;j<n-i-1;j++)
          {
               if(arr[j] > arr[j+1])
               {
                    swap(arr[j], arr[j+1]);
               }
          }
     }
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "Elements Before Bubble Sort:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;

     bubbleSort(v, n);
     cout << "Elements After Bubble Sort:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;

     return 0;
}
