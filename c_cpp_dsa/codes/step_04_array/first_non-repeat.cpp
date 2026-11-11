/*
Find the first non-repeating element in an array
             Asked at: Amazon, Flipkart, Adobe
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int first_nonrepeat(const vector<int>& v)
{
     unordered_map<int, int> mp;
     for(int x : v)
          mp[x]++;
     for(int x : v)
     {
          if(mp[x] == 1)
               return x;
     }
     return -1;
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
     cout << "Result:- " << first_nonrepeat(v) << endl;
     return 0;
}
