/*
   Move all zeros to end while maintaining order of non-zero elements
   Asked at: Amazon, Microsoft, Google
 */

#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
}

void moveZeroes(vector<int>& v)
{
     int n = v.size();
     for(int i=0;i<n-1;i++)
     {
          for(int j=i+1;j<n;j++)
          {
               if(v[i] == 0 && v[j] != 0)
               {
                    swap(v[i], v[j]);
               }
          }
     }
}

void moveZeroes1(vector<int>& v)
{
     int j = 0; 
     for(int i = 0; i < v.size(); i++)
     {
          if(v[i] != 0)
          {
               swap(v[i], v[j]);
               j++;
          }
     }
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
     cout << "Initial Vector Elements:- ";
     printVec(v);
     cout << "After Shifting zeroes to End:- ";
     //moveZeroes(v); // O(n^2)
     moveZeroes1(v);  // O(n)
     printVec(v);
     return 0;
}
