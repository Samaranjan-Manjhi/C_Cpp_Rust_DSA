/*

   Average Count Array

   Given an integer array arr[] and an integer x.
   For each index i (0-based), calculate the floor value of the average of arr[i] and x:  avg = floor((arr[i] + x) / 2)
   Then, count how many times this calculated value occurs in the original array arr[].
   Store this count at index i of a new array result[].
   Return the array result[].

Examples:

Input: arr[] = [2, 4, 8, 6, 2], x = 2
Output: [2, 0, 0, 1, 2]
Explanation: For each element,
arr[0] = 2: floor((2 + 2) / 2) = 2. Value 2 appears 2 times.
arr[1] = 4: floor((4 + 2) / 2) = 3. Value 3 does not appear,.
arr[2] = 8: floor((8 + 2) / 2) = 5. Value 5 does not appear.
arr[3] = 6: floor((6 + 2) / 2) = 4. Value 4 appears once.
arr[4] = 2: floor((2 + 2) / 2) = 2. Value 2 appears 2 times.

Input : arr[] = [9, 5, 2, 4, 0, 3], x = 3 
Output : [0, 1, 1, 1, 0, 1] 
Explanation: The calculated average values are: [6, 4, 2, 3, 1, 3]
Their frequencies in arr[] are: [0, 1, 1, 1, 0, 1]

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ x ≤ 10^5
0 ≤ arr[i] ≤ 10^5

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> countArray(vector<int>& arr, int x) 
{
     // code here
     unordered_map<int, int> mp;
     for(int i : arr)
          mp[i]++;

     vector<int> res(arr.size(), 0);
     for(int i=0;i<arr.size();i++)
     {
          int temp = (arr[i]+x)/2;
          //cout << "temp:- " << temp << endl;
          int cnt = mp[temp];
          //cout << "cnt:- " << cnt << endl;
          res[i] = cnt;
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

     int x;
     cout << "Enter x Value: ";
     cin >> x;

     vector<int> res = countArray(v, x);
     cout << "Elements After countArray Operation:- ";
     for(int x : res)
          cout << x << " ";
     cout << endl;     

     return 0;
}
