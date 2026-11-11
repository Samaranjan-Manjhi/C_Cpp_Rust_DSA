/*

   Majority in a Sorted Array

   Given a sorted array arr[] of size n, determine whether there is a majority element in the array or not. An element is called a majority element if it appears more than n/2 times in the array.

Examples:

Input: arr[] = [1, 2, 3, 3, 3, 3, 10]
Output: true
Explanation: The size of the array is 7. The middle element is arr[7/2] = arr[3] = 3. Element 3 appears 4 times. Since 4 > (7 / 2), it is a majority element.

Input: arr[] = [1, 1, 2, 4, 4, 4, 6, 6]
Output: false
Explanation: The size of the array is 8. The middle element is arr[8/2] = arr[4] = 4. Element 4 appears 3 times. Since 3 is not greater than (8 / 2), it is not a majority element.

Constraints:
1 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ 10^5

 */


#include <iostream>
#include <vector>

using namespace std;

bool isMajority(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     int cnd = -1;
     int cnt = 0;
     for(int x : arr)
     {
          if(cnt == 0)
          {
               cnd = x;
               cnt++;
          }
          else if(cnd == x)
          {
               cnt++;
          }
          else
          {
               cnt--;
          }
     }

     cnt = 0;
     for(int x : arr)
     {
          if(x == cnd)
               cnt++;
     }

     if(cnt > n/2)
          return true;

     return false;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     bool res = isMajority(v);
     cout << "     Result:- ";
     if(res)
          cout << "  Yes\n";
     else
          cout << "  Nope\n";

     return 0;
}
