/*

   Largest from Digits

   Given an array arr[] of numbers from 0 to 9. Rearrange elements of the array such that after combining all the elements of the array, the number formed is maximum.

   Return the resulting number in the form of a string.

Examples:

Input: arr[] = [9, 0, 1, 3, 0]
Output: 93100
Explanation: Largest is 93100 which can be formed from array digits.

Input: arr[] = [1, 2, 3]
Output: 321
Explanation: Largest is 321 which can be formed from array digits.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9

 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string maxNumber(vector<int>& arr)
{
     // code here.
     sort(arr.begin(), arr.end());
     string res = "";
     for(int i=arr.size()-1;i>=0;i--)
          res += to_string(arr[i]);

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

     string res = maxNumber(v);
     cout << "    Result:- " << res << endl;

     return 0;
}

