/*

   Last Duplicate in a Sorted Array

   You are given a sorted array arr[] that may contain duplicate elements. Your task is to find the index of the last occurrence of any duplicate element and return the index along with the value of that element. If no duplicate element is found, return [-1, -1].

Examples :

Input: arr[] = [1, 5, 5, 6, 6, 7]
Output: [4, 6]
Explanation: Last duplicate element is 6 having index 4.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [-1, -1]
Explanation: No duplicate elements are present in the array.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6

 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> dupLastIndex(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     for(int i=n-2;i>=0;i--)
     {
          if(arr[i] == arr[i+1])
               return {i+1, arr[i]};
     }
     return {-1, -1};
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = dupLastIndex(v);
     cout << "Elements After alternateSort Operation:- ";
     for(int x : res)
          cout << x << " ";
     cout << endl;     

     return 0;
}
