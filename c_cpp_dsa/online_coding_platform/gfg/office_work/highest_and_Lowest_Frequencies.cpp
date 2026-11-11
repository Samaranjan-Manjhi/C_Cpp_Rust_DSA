/*

Highest and Lowest Frequencies

Given an array, the task is to find the difference between the highest occurrence and lowest occurrence of any numbers in an array. If only one type of element is present in the array return 0

Examples:

Input: arr[] = [1, 2, 2]
Output: 1
Explanation:  Lowest occurring element (1) occurs once. Highest occurring element (2) occurs 2 times

Input: arr[] = [7, 8, 4, 5, 4, 1, 1, 7, 7, 2, 5]
Output: 2
Explanation : Lowest occurring element (2) occurs once. Highest occurring element (7) occurs 3 times

Constraints:
1<= arr.size() <=10^6
1<= arr[i] <=10^6

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int findDiff(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     unordered_map<int, int> freq;
     for(int x : arr)
          freq[x]++;

     int maxi = INT_MIN, mini = INT_MAX;
     for(auto& f : freq)
     {
          if(f.second > maxi)
               maxi = f.second;
          if(f.second < mini)
               mini = f.second;
     }
     if(maxi == INT_MIN || mini == INT_MAX)
          return 0;
     return (maxi-mini);
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findDiff(v);
     cout << "     Result:- " << res << endl;

     return 0;
}
