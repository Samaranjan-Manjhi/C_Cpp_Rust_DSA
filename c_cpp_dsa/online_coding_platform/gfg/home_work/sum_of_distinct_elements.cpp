/*

   Sum of distinct elements

   You are given an array arr. Find the sum of distinct elements in an array.

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: 15
Explanation: Distinct elements are 1, 2, 3, 4, 5. So sum is 15.

Input: arr[] = [5, 5, 5, 5, 5]
Output: 5
Explanation: Only Distinct element is 5. So sum is 5.

Constraints:
1 ≤ arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 10^4

 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findSum(vector<int>& arr) 
{
     // code here
     int sum = 0;
     unordered_set<int>seen;
     int n = arr.size();
     for(int i=0;i<n;i++)
     {
          if(seen.find(arr[i]) == seen.end())
          {
               seen.insert(arr[i]);
               sum += arr[i];
          }
     }
     return sum;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findSum(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
