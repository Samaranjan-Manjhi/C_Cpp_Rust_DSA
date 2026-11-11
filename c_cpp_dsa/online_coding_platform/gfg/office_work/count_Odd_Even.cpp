/*

   Count Odd Even

   Given an array arr[]. The task is to find the number of odd and even elements in the array.

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: 3 2
Explanation: In the given array, there are 3 odd elements (1, 3, 5) and 2 even elements (2 and 4).

Input: arr[] = [1, 6, 18, 7]
Output: 2 2
Explanation: In the given array, there are 2 odd elements (1, 7) and 2 even elements (6 and 18).

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 106
1 <= arri <= 106

 */

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> countOddEven(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     int odd = 0;
     for(int x : arr)
     {
          if(x%2!=0)
               odd++;     
     }
     //cout << odd << " " << n-odd << endl;
     return {odd, n-odd};
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     pair<int, int> res = countOddEven(v);
     cout << "   Result:  Odd:- " << res.first << "  Even:- " << res.second << endl;

     return 0;
}
