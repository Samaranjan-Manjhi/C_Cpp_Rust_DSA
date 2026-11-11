/*

Count number of elements between two given elements in array

Given an unsorted array arr[] and two elements num1 and num2. The task is to count the number of elements that occur between the given elements (excluding num1 and num2). If there are multiple occurrences of num1 and num2, we need to consider the leftmost occurrence of num1 and the rightmost occurrence of num2.

Examples:

Input: arr[] = [4, 2, 1, 10, 6], num1 = 4, and num2 = 6
Output: 3
Explanation: We have an array [4, 2, 1, 10, 6] and num1 = 4 and num2 = 6. So, the left most index of num1 is 0 and rightmost index of num2 is 4. So, the total number of element between them is [2, 1, 10] So, answer is 3.

Input: arr[] = [3, 2, 1, 4], num1 = 2, and num2 = 4
Output: 1
Explanation: here in array [3, 2, 1, 4] only one element [1] occur betweeen 2 and 4, So, answer is 1.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
2 ≤ arr.size() ≤ 10^6
1 ≤ arr[i], num1, num2 ≤ 10^6

*/

#include <iostream>
#include <vector>

using namespace std;

int getCount(vector<int> &arr, int num1, int num2) 
{
     // Your code goes here.
     int l = 0, r = 0;
     int n = arr.size();
     for(int i=0;i<n;i++)
     {
          if(arr[i] == num1)
          {
               l = i;
               break;
          }
     }
     for(int i=n-1;i>=0;i--)
     {
          if(arr[i] == num2)
          {
               r = i;
               break;
          }
     }
     //cout << "l:- " << l << "  r: " << r << endl;
     int ans = r-l-1;
     if(ans < 0)
          return 0;
     return r-l-1;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int num1;
     cout << "Enter Num1: ";
     cin >> num1;

     int num2;
     cout << "Enter Num2: ";
     cin >> num2;

     int res = getCount(v, num1, num2);
     cout << "   Result:- " << res << endl;

     return 0;
}
