/*

   Given an integer array height[], where height[i] represents the height of the ith bar arranged in a row, find the maximum rectangular area that can be formed by selecting any two bars. The area is calculated based on the original positions of the selected bars.

Examples :

Input: height[] = [2, 5, 4, 3, 7]
Output: 10
Explanation:

The maximum rectangular area is formed by selecting the bars of heights 5 and 7.
There are 2 bars between them, so the area is: min(5, 7) × 2 = 10

Input: height[] = [1, 3, 4]
Output: 1
Explanation: Selecting bars 1 and 4 gives one bar between them, so the area is: min(1, 4) × 1 = 1

Constraints:
1 ≤ height.size() ≤ 105
1 ≤ height[i] ≤ 104

 */

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) 
{
     // code here
     int l = 0, r = height.size()-1;
     int maxi = (min(height[l], height[r])*(r-l-1));
     while(l <= r)
     {
          if(height[l] < height[r])
          {
               if(min(height[l], height[r])*(r-l-1) > maxi)
                    maxi = (min(height[l], height[r])*(r-l-1));
               l++;
          }
          else
          {
               if(min(height[l], height[r])*(r-l-1) > maxi)
                    maxi = (min(height[l], height[r])*(r-l-1));
               r--;
          }
     }
     return maxi;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)     
          cin >> v[i];

     int res = maxArea(v);
     cout << "Maximum Area between 2 bars:- " << res << endl;

     return 0;
}
