/*

   Bubble Sort

   Given an array, arr[]. Sort the array using bubble sort algorithm.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After Sorting the array in ascending order of their values is [1, 3, 4, 7, 9].

Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: Sort the array in ascending order of their values.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [1, 2, 3, 4, 5]
Explanation: An array that is already sorted should remain unchanged after applying bubble sort.

Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 103

 */

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     for(int i=0;i<n-1;i++)
     {
          for(int j=0;j<n-1;j++)
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

     if(!v.empty())
     {
          cout << "   Result Before Bubble Sort:- ";
          for(int x : v)
               cout << x << " ";
          cout << endl;
     }
     bubbleSort(v);
     if(!v.empty())
     {
          cout << "   Result After Bubble Sort:- ";
          for(int x : v)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
