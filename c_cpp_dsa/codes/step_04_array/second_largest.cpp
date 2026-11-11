/*
   Find the second largest element in an array
   Asked at: Amazon, Flipkart, TCS, Zoho
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int second_large(const vector<int>& v)
{
     int n = v.size();
     int maxi = v[0];
     int secondLargest = INT_MIN;
     for(int i=1;i<n;i++)
     {
          if(maxi < v[i])
          {
               secondLargest = maxi;
               maxi = v[i];
          }
          else if(secondLargest < v[i] && maxi != v[i])
          {
               secondLargest = v[i];
          }
     }
     if(secondLargest == INT_MIN)
          return -1;
     return secondLargest;
}

int main()
{
     int n, val;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     cout << "Second Largest Element:- " << second_large(v) << endl;
     return 0;
}
