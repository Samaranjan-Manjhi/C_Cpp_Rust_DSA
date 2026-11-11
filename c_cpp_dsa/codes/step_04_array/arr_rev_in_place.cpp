/*
   Reverse an array in-place
   Asked at: TCS, Wipro, Infosys, Zoho
 */

#include <iostream>
#include <vector>
using namespace std;

void exchange(vector<int>& v, int s, int e)
{
     while(s < e)
     {
          v[s] = v[s]^v[e];
          v[e] = v[s]^v[e];
          v[s] = v[s]^v[e];
          s++;
          e--;
     }
}

void printVector(vector<int> v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
}

int main()
{
     int n, val;
     cout << "Enter size of Vector: ";
     cin >> n;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     cout << "Vector before reverse:- ";
     printVector(v);
     exchange(v, 0, n-1);
     cout << "Vector after reverse:- ";
     printVector(v);
     return 0;
}
