/*

   Maximum Difference 

   Problem statement

   You are given an array 'ARR' of the 'N' element. Your task is to find the maximum difference between any of the two elements from 'ARR'.
   If the maximum difference is even print “EVEN” without quotes. If the maximum difference is odd print “ODD” without quotes.

   For example:
   Given 'ARR' = [1, 10, 5, 2, 8, 1 ] , answer is "ODD".
   Here the maximum difference is between 10 and 1, 10 - 1 = 9

Constraints:
1 <= T <= 100
1 <= N <= 5000 
1 <= ARR[i] <= 10 ^ 9
where ‘N’ is the length of the array 'ARR', and 'ARR[i]' is an element of the 'ARR' respectively.
Time limit: 1 sec.

Sample Input 1:
2
4
2 9 3 4
6
1 1 1 1 1 1 
Sample Output 1:
ODD
EVEN
Explanation of Sample Input 1:
For the first test case, the maximum difference is 7, between 9 and 2.
For the second test case, all elements are the same, the maximum difference is 0.

Sample Input 2:
2
2
567 11
1
28
Sample Output 2:
EVEN
EVEN 

 */

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

string maximumDifference(int n, vector<int>& arr)
{
     // Write your code here.
     int mini = INT_MAX;
     int maxi = INT_MIN;
     for(int i=0;i<n;i++)
     {
          if(mini > arr[i])
               mini = arr[i];
          if(maxi < arr[i])
               maxi = arr[i];
     }
     //cout << "Mini: " << mini << "     maxi: " << maxi << endl;

     if(mini == INT_MAX)
          mini = 0;

     if(maxi == INT_MIN)
          maxi = 0;

     return (abs(maxi - mini)%2 == 0 ? "EVEN" : "ODD");
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     string res = maximumDifference(n, v);
     cout << "    Result:- " << res << endl;

     return 0;
}
