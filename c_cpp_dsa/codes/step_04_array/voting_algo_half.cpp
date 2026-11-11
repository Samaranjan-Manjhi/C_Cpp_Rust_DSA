/*
   Find the element that appears more than N/2 times (majority element)
   Use Boyer-Moore Voting Algorithm — O(N) time O(1) space
   Asked at: Amazon, Adobe, Flipkart
 */

#include <iostream>
#include <vector>
using namespace std;
int voting_algo(const vector<int>& v)
{
     int n = v.size();
     int cnt = 1, val = v[0];
     for(int i=1;i<n;i++)
     {
          if(cnt == 0)
          {
               val = v[i];
               cnt = 1;
          }
          else if(v[i] == val)
               cnt++;
          else
               cnt--;
     }
     return val;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];
     int res = voting_algo(v);
     cout << "Result:- " << res << endl;
     return 0;
}
