/*

Merge Sort 

 Problem statement

Given a sequence of numbers ‘ARR’. Your task is to return a sorted sequence of ‘ARR’ in non-descending order with help of the merge sort algorithm.

Example :
Merge Sort Algorithm -
Merge sort is a Divide and Conquer based Algorithm. It divides the input array into two-parts, until the size of the input array is not ‘1’. In the return part, it will merge two sorted arrays a return a whole merged sorted array.
The above illustrates shows how merge sort works.

Note :
It is compulsory to use the ‘Merge Sort’ algorithm.

Constraints :
1 <= T <= 50
1 <= N <= 10^4
-10^9 <= arr[i] <= 10^9
Time Limit : 1 sec

Sample Input 1 :
2
7
3 4 1 6 2 5 7
4
4 3 1 2
Sample Output 1 :
1 2 3 4 5 6 7
1 2 3 4

Explanation For Sample Input 1:
Test Case 1 :
Given ‘ARR’ : { 3, 4, 1, 6, 2, 5, 7 }
Then sorted 'ARR' in non-descending order will be : { 1, 2, 3, 4, 5, 6, 7 }. Non-descending order means every element must be greater than or equal to the previse element.

Test Case 2 :
Given ‘ARR’ : { 4, 3, 1, 2 }
Then sorted 'ARR' in non-descending order will be : { 1, 2, 3, 4 }. 

Sample Input 2 :
2
4
5 4 6 7
3
2 1 1
Sample Output 2 :
4 5 6 7
1 1 2

*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
     vector<int> temp;
     int left = low;
     int right = mid+1;

     while(left <= mid && right <= high)
     {
          if(arr[left] <= arr[right])
               temp.push_back(arr[left++]);
          else
               temp.push_back(arr[right++]);
     }

     while(left <= mid)
     {
          temp.push_back(arr[left++]);
     }

     while(right <= high)
     {
          temp.push_back(arr[right++]);
     }

     for(int i=low;i<=high;i++)
     {
          arr[i] = temp[i-low];
     }
}

void mergeSortHelper(vector<int>& v, int low, int high)
{
     if(low >= high)
          return;

     int mid = (low + high)/2;

     mergeSortHelper(v, low, mid); // left Sort
     mergeSortHelper(v, mid+1, high); // right Sort

     merge(v, low, mid, high);
}

void mergeSort(vector<int>& arr, int n) 
{
     // Write your code here.
     mergeSortHelper(arr, 0, n-1);
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "Elements Before Merge Sort:- ";
     for(int x : v)
     {
          cout << x << " ";
     }
     cout << endl;

     mergeSort(v, n);

     cout << "Elements Before Merge Sort:- ";
     for(int x : v)
     {
          cout << x << " ";
     }
     cout << endl;

     return 0;
}
