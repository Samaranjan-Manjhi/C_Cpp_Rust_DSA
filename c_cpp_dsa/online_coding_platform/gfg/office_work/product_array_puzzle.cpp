/*

   Product array puzzle

   Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range.

Examples:

Input: arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

Input: arr[] = [12, 0]
Output: [0, 12]
Explanation: For i = 0, res[i] is 0.
For i = 1, res[i] is 12.

Constraints:
2 <= arr.size() <= 10^5
-100 <= arr[i] <= 100

 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     vector<int> res(n);
     int prod = 1;
     if(n == 2)
     {
          swap(arr[0], arr[1]);
          return arr;
     }

     int zerocnt = 0;
     for(int x : arr)
     {
          if(x == 0)
               zerocnt++;
          else
          {
               prod *= x;
          }
     }

     for(int i=0;i<n;i++)
     {
          if(zerocnt == 1)
          {
               if(arr[i] == 0)
                    res[i] = prod;
               else
                    res[i] = 0;
          }
          else if(zerocnt > 1)
          {
               res[i] = 0;
          }
          else
          {
               res[i] = prod/arr[i];
          }
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = productExceptSelf(v);
     cout << "   Result:- " ;
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }
     return 0;
}
