/*

Count Pairs Odd Xor

Given an integer array arr[], determine the number of pairs (i, j) such that 0 ≤ i < j < arr.size() and the XOR of arr[i] and arr[j] is odd.

Examples:

Input: arr[] = [1, 2, 3]
Output: 2
Explanation: 
The possible pairs are:
(1, 2) → 1 ^ 2 = 3 (odd)
(1, 3) → 1 ^ 3 = 2 (even)
(2, 3) → 2 ^ 3 = 1 (odd)
Hence, there are 2 pairs whose XOR is odd.

Input: arr[] = [1, 2]
Output: 1
Explanation: 
The only possible pair is:
(1, 2) → 1 ^ 2 = 3 (odd)
Therefore, the number of pairs with odd XOR is 1.

Constraints:
1 ≤ arr.size() ≤ 92681
1 ≤ arr[i] ≤ 10^5

*/

#include <iostream>
#include <vector>

using namespace std;

int countXorPair(vector<int>& arr) 
{
     // code here
     // TLE
     /*
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
        int j = i+1;
        while(j < n)
        {
        if((arr[i]^arr[j])%2 != 0)
        cnt++;
        j++;
        }
        }   
        return cnt;
      */

     long long even = 0, odd = 0;
     for (int x : arr) 
     {
          if (x % 2 == 0)
               even++;
          else
               odd++;
     }

     return even * odd;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = countXorPair(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
