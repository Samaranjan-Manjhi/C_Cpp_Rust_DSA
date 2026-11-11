/*

   Given two sorted arrays, merge them in-place (no extra space)
   First array has extra space for second array's elements
   Asked at: Amazon, Microsoft

 */

#include <iostream>
#include <vector>
using namespace std;

void mergeInplace(vector<int>& v1, vector<int>& v2)
{
     int x = v1.size();
     int y = v2.size();
     v1.resize(x + y);
     int i = x-1, j = y-1, k = x+y-1;
     while(i >= 0 && j >= 0)
     {
          if(v1[i] > v2[j])
          {
               v1[k] = v1[i];
               i--;
          }
          else if(v1[i] < v2[j])
          {
               v1[k] = v2[j];
               j--;
          }
          k--;
     }
     while(j >= 0)
     {
          v1[k] = v2[j];
          j--;
          k--;
     }
}

void printVec(vector<int>& v)
{
     for(int x : v)
          cout << x << " ";
     cout << endl;
}

int main()
{
     int n1;
     cout << "Enter Number: ";
     cin >> n1;

     int n2;
     cout << "Enter Number: ";
     cin >> n2;

     vector<int> v(n1);
     for(int i=0;i<n1;i++)
          cin >> v[i];

     vector<int> v1(n2);
     for(int i=0;i<n2;i++)
          cin >> v1[i];

     printVec(v);
     mergeInplace(v, v1);
     printVec(v);

     return 0;
}
