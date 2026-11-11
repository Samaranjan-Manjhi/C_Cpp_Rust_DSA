/*
   Left rotate an array by K positions
   Asked at: Amazon, Flipkart, TCS
 */

#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& v, int start, int end)
{
     while(start < end)
     {
          swap(v[start], v[end]);
          start++;
          end--;
     }
}

void rotatebyk(vector<int>& v, int k)
{
     int n = v.size();
     k %= n;
     Swap(v, 0, k-1);
     Swap(v, k, n-1);
     Swap(v, 0, n-1);
}

void printVec(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
}

int main()
{
     int n, val, k;
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
     cout << "Initial Element of vector:- ";
     printVec(v);
     cout << "Enter k Value: ";
     cin >> k;
     cout << "After left rotation:- ";
     rotatebyk(v, k);
     printVec(v);
     return 0;
}
