/*

   Given an array arr[] containing only 0 and 1. Find the minimum toggles (switch from 0 to 1 or vice-versa) required such the array become partitioned, i.e., it has first 0s then 1s.

Examples:

Input: arr = [1, 0, 1, 1, 0]
Output: 2
Explaination: The changed array will be [0, 0, 1, 1, 1]. So the number of toggles here required is 2.

Input: arr = [0, 1, 0, 0, 1, 1, 1]
Output: 1
Explaination: The changed array will be [0, 0, 0, 0, 1, 1, 1]. Required toggles are 1.

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1

 */


#include <iostream>
#include <vector>

using namespace std;

int minToggle(vector<int>& arr) 
{
     // code here
     int allZeros = 0;
     for(int n : arr)
     {
          if(n == 0)
               allZeros++;
     }
     int ans = allZeros;
     int leftOnes = 0;
     for(int n : arr)
     {
          if(n == 0)
               allZeros--;
          else
               leftOnes++;

          ans = min(leftOnes+allZeros, ans);
     }
     return ans;
}

int main()
{
     int n;
     cout << "Enter size of vector: ";
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = minToggle(v);
     cout << "Result:-  " << res << endl;

     return 0;
}
