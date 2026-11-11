/*
   Rotate array right by K positions in O(N) time O(1) space
Hint: reverse entire, reverse first K, reverse last N-K
Asked at: Amazon, Microsoft, Adobe
 */

#include <iostream>
#include <vector>
using namespace std;
void doSwap(vector<int>& v, int start, int end)
{
     while(start < end)
     {
          swap(v[start], v[end]);
          start++;
          end--;
     }
}
void printVec(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
          cout << v[i] << " ";
     cout << endl;
}
void rightRotationByk(vector<int>& v, int k)
{
     int n = v.size();    // For Left Rotation
     doSwap(v, n-k, n-1); // doSwap(v, 0, k-1);
     doSwap(v, 0, n-k-1); // doSwap(v, k, n-1);
     doSwap(v, 0, n-1);   // doSwap(v, 0, n-1);
}
int main()
{
     int n, k;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];
     cout << "Enter k Value: ";
     cin >> k;
     printVec(v);
     cout << "After right rotation by k:- ";
     rightRotationByk(v, k);
     printVec(v);
     return 0;
}
