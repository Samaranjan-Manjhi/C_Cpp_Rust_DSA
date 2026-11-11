/*

   Search array with adjacent diff at most k

   Given a step array arr[], its step value k, and a key x, we need to find the index of key x in the array arr[]. If multiple occurrences of key x exist, return the first occurrence of the key. In case of no occurrence of key x exists return -1.

Note: A step array is an array of integers where the difference between adjacent elements is at most k. For example: arr[] = [4, 6, 7, 9] and k = 2 is a step array as the difference between the adjacent elements in the arr[] is at most 2.  

Examples

Input: arr[] = [4, 5, 6, 7, 6] , k = 1 , x = 6
Output: 2
Explanation: In an array arr 6 is present at index 2. So, return 2.

Input: arr[] = [20, 40, 50], k = 20 , x = 70
Output: -1 
Explaination: As there is no occurrence of 70. So, return -1.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size ≤ 10^5
1 ≤ k ≤ 10^2
1 ≤ arr[i], x ≤ 10^5

 */


#include <iostream>
#include <vector>

using namespace std;

int findStepKeyIndex(vector<int>& arr, int k, int x) 
{
     // code here
     for(int i=0;i<arr.size();i++)
     {
          if(arr[i] == x)
               return i;
     }

     return -1;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int k;
     cout << "Enter k Value: ";
     cin >> k;

     int x;
     cout << "Enter x Value: ";
     cin >> x;

     int res = findStepKeyIndex(v, k, x);
     cout << "     Result:- " << res << endl;

     return 0;
}
