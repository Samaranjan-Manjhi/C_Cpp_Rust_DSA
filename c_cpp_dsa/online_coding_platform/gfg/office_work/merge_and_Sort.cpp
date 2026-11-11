/*

   Merge and Sort

   Given two arrays arr1[] and arr2[], return the merged array in ascending order containing unique elements.

Examples:

Input: arr1[] = [11, 1, 8], arr2[] = [10, 11]
Output: [1, 8, 10, 11]
Explanation: The ouput array after merging both the arrays and removing duplicates is [1, 8, 10, 11]

Input: arr1[] = [7, 1, 5, 3, 9], arr2[]  = [8, 4, 3, 5, 2, 6]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9] 

Constraints:
1 ≤ arr1.size(), arr2.size() ≤ 104
0 ≤ arr1[i], arr2[i] ≤ 109

 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> mergeNsort(vector<int>& arr1, vector<int>& arr2) 
{
     //  code here
     arr1.insert(arr1.end(), arr2.begin(), arr2.end());
     set<int> st(arr1.begin(), arr1.end());
     int n = st.size();
     vector<int> res(n);
     int i = 0;
     for(auto& x : st)
     {
          res[i++] = x;
     }
     return res;
}

int main()
{
     int n;
     cout << "Enter arr1 Size: ";
     cin >> n;

     vector<int> arr1(n);
     for(int i=0;i<n;i++)
          cin >> arr1[i];

     int m;
     cout << "Enter arr2 Size: ";
     cin >> m;

     vector<int> arr2(m);
     for(int i=0;i<m;i++)
          cin >> arr2[i];

     vector<int> res = mergeNsort(arr1, arr2);
     cout << "Elements After Merge and Sort:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
