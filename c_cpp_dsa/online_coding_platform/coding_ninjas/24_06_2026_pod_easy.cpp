/*

   Problem statement

   You are given an array 'arr' of length 'n'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
   Peak element is defined as that element that is greater than both of its neighbors. If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.
   Assume 'arr[-1]' and 'arr[n]' as negative infinity.
Note:
1.  There are no 2 adjacent elements having same value (as mentioned in the constraints).
2.  Do not print anything, just return the index of the peak element (0 - indexed).
3. 'True'/'False' will be printed depending on whether your answer is correct or not.

Example:
Input: 'arr' = [1, 8, 1, 5, 3]
Output: 3
Explanation: There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3.

Sample Input 1:
5
1 8 1 5 3
Expected Answer:
1
Output on Console:
True
Explanation of sample input 1 :
There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3. Any of these 2 numbers will print 'True'.

Sample Input 2:
3
1 2 1 
Expected Answer:
1
Output on Console:
True

Expected time complexity:
The expected time complexity is O(log 'n').

Constraints:
1 <= 'n' <= 10^5
1 <= 'arr[i]' <= 10^5
'arr[i]' != 'arr[i + 1]' for all 'i' in range 0 <= 'i' < 'n' - 1

 */

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int> &arr) 
{
     // Write your code here
     int n = arr.size();
     int maxi = 0;
     for(int i=0;i<n;i++)
     {
          int left = (i == 0) ? 0 : arr[i-1];
          int right = (i == n-1) ? 0 : arr[i+1];
          if(left < arr[i] && arr[i] > right)
               return i;
     }
     return -1;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findPeakElement(v);
     cout << "Peak Element found at index:- " << res << endl;

     return 0;
}
