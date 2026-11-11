/*

   One odd Occuring

   Given an array of arr[] positive integers where all numbers occur even number of times except one number which occurs odd number of times. Return that number.

Examples:

Input:arr[] = [1, 2, 3, 2, 3, 1, 3]
Output: 3
Explaination: 3 occurs three times.

Input:arr[] = [5, 7, 2, 7, 5, 2, 5]
Output: 5
Explaination: 5 occurs three times.


Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^6

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getOddOccurrence(vector<int>& arr) 
{
     // code here
     unordered_map<int, int> mp;
     for(int i : arr)
          mp[i]++;
     for(auto& m : mp)
     {
          if(m.second%2 != 0)
               return m.first;
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

     int res = getOddOccurrence(v);
     cout << "    Result:- " << res << endl;

     return 0;
}
