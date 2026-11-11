/*

   Positive and negative elements

   Given an array arr containing equal number of positive and negative elements, arrange the array such that every positive element is followed by a negative element.
Note: The relative order of positive and negative numbers should be maintained.

Examples:

Input: arr[] = [-1, 2, -3, 4, -5, 6]
Output: [2, -1, 4, -3, 6, -5]
Explanation: Positive numbers in order are 2, 4 and 6. Negative numbers in order are -1, -3 and -5. So the arrangement we get is 2, -1, 4, -3, 6 and -5.

Input: arr[] = [-3, 2, -4, 1]
Output: [2, -3, 1, -4] 
Explanation: The positive numbers are 2,1 and negative numbers are -3, -4  

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
2 ≤ arr.size() ≤ 10^6
-106 ≤ arr[i] ≤ 10^6

 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> arranged(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     vector<int> res, neg, pos;
     for(int x : arr)
     {
          if(x < 0)
               neg.push_back(x);
          else
               pos.push_back(x);
     }
     for(int i=0;i<pos.size();i++)
     {
          res.push_back(pos[i]);
          res.push_back(neg[i]);
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

     cout << "Elements Before arranged Operation:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;
     vector<int> res = arranged(v);
     cout << "Elements After arranged Operation:- ";
     for(int x : res)
          cout << x << " ";
     cout << endl;     

     return 0;
}
