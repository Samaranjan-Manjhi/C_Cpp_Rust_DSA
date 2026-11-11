/*
   Check if an array is sorted in ascending order
   Asked at: Wipro, Capgemini
 */

#include <iostream>
#include <vector>
using namespace std;

bool isArrSorted(vector<int> v)
{
     bool sorted = true;
     for(int i=1;i<v.size();i++)
     {
          if(v[i-1] > v[i])
          {
               sorted = false;
               break;
          }
     }
     return sorted;
}

int main()
{
     int n, val;
     cout << "Enter Size of Vector: ";
     cin >> n;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     cout << "Is Array sorted ? " << (isArrSorted(v) ? " Yes" : " No") << endl;
     return 0;
}
