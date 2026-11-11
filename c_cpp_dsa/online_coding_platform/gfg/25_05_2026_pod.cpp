/*

   Given an array arr[] containing distinct positive integers, and two integers start and end defining a range. Determine if the array contains all elements within inclusive range [start, end].
Note: If the array contains all elements in the given range return true otherwise return false.

Examples :
Input: start = 2, end = 5, arr[] =  [1, 4, 5, 2, 7, 8, 3]
Output: true
Explanation: All integers within the range [2, 5] are 2, 3, 4, and 5, and all of them are present in the array. Therefore, the answer is true for this test case.

Input: start = 2, end = 6, arr[] = [1, 4, 5, 2, 7, 8, 3]
Output: false
Explanation: The array does not contain 6; hence, it does not contain all the elements in the range [2, 6]. Therefore, the output is false.

Constraints:
1 ≤ arr.size(), arr[i] ≤ 105
1 ≤ start ≤ end ≤ 105

 */


#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool checkElements(int start, int end, vector<int> &arr) 
{
     // code here
     /*set<int> s;
     for(int i=0;i<arr.size();i++)
     {
          s.insert(arr[i]);
     }*/
     set<int> s(arr.begin(), arr.end());
     for(int i=start;i<=end;i++)
     {
          if(s.find(i) == s.end())
               return false;
     }
     return true;
}

int main()
{
     int s;
     cout << "Enter Starting point: ";
     cin >> s;
     int e;
     cout << "Enter Ending point: ";
     cin >> e;

     int n;
     cout << "Enter vector size: ";
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     bool res = checkElements(s, e, v);
     cout << "Result:- " << res << endl;

     return 0;
}
