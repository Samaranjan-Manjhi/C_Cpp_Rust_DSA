/*

   Geek and the Two Climbing Techniques

   Given two arrays a[] and b[] of equal size, where a[i] and b[i] denote the time required to climb the i-th step using technique 1 and technique 2, respectively, determine the minimum total time required to climb all steps. Geek may start with either technique but must alternate between the two techniques at every step.

Examples:

Input: a[] = [2, 1, 2], b[]= [3, 2, 1]
Output: 5
Explanation: Starting with technique 1: a[0] + b[1] + a[2] = 2 + 2 + 2 = 6
Starting with technique 2: b[0] + a[1] + b[2] = 3 + 1 + 1 = 5
The minimum of the two is 5, achieved by starting with technique 2.

Input: a[] = [1, 3, 1, 2], b[]= [2, 2, 3, 1]
Output: 5
Explanation: Starting with technique 1 yields the minimum total time of 5.

Constraints:
1 ≤ a.size(), b.size() ≤ 10^5
1 ≤ a[i], b[i] ≤ 10^6 

 */

#include <iostream>
#include <vector>

using namespace std;

int minTime(vector<int>& a, vector<int>& b)
{
     // code here
     int time = 0;
     int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
     for(int i=0;i<a.size();i++)
     {
          if(i%2 == 0)
               a0 += a[i];
          else
               a1 += a[i];
     }

     for(int i=0;i<b.size();i++)
     {
          if(i%2 == 0)
               b0 += b[i];
          else
               b1 += b[i];
     }

     int tech1 = a0 + b1;
     int tech2 = a1 + b0;

     time = min(tech1, tech2);

     return time;
}

int main()
{
     int n;
     cout << "Enter Size of Array1 (n = m): ";
     cin >> n;

     vector<int> a1(n);
     for(int i=0;i<n;i++)
          cin >> a1[i];

     int m;
     cout << "Enter Size of Array1 (m = n): ";
     cin >> m;

     vector<int> a2(n);
     for(int i=0;i<m;i++)
          cin >> a2[i];

     int res = minTime(a1, a2);
     cout << "    Result:- " << res << endl;

     return 0;
}
