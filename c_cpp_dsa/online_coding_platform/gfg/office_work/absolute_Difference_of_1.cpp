/*

Absolute Difference of 1

Given an array arr[] and a number k,  find all the numbers less than k that have at least two digits and the absolute difference between every adjacent digit of that number should be 1.

Note: Return an empty list if no such number is present.

Examples:

Input: arr[] = [7, 98, 56, 43, 45, 23, 12, 8], k = 54
Output: [43, 45, 23, 12]
Explanation: 43 45 23 12 all these numbers have adjacent digits diff as 1 and they are less than 54.

Input: arr[] = [87, 89, 45, 235, 465, 765, 123, 987, 499, 655], k = 1000
Output: [87, 89, 45, 765, 123, 987]
Explanation: 87 89 45 765 123 987 all these numbers have adjacent digits diff as 1 and they are less than 1000.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k, arr[i] ≤ 106

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getDigitDiff1AndLessK(vector<int>& arr, int k) 
{
     // code here
     int n = arr.size();
     vector<int> res;
     if(n == 0 || k < 10)
          return res;
     for(int i=0;i<n;i++)
     {
          if(arr[i] > 9 && arr[i] < k)
          {
               bool isYes = true;
               string temp = to_string(arr[i]);
               for(int j=1;j<temp.size();j++)
               {
                    int a = (temp[j-1] - '0');
                    int b = (temp[j] - '0');
                    if(abs(a-b) != 1)
                         isYes = false;
               }
               if(isYes)
                    res.push_back(arr[i]);
          }
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

     int k;
     cout << "Enter K value: ";
     cin >> k;

     vector<int> res = getDigitDiff1AndLessK(v, k);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}
