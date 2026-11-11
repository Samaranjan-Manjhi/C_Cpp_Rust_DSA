/*
   Right rotate an array by 1 position
   Asked at: TCS, Wipro
 */

#include <iostream>
#include <vector>
using namespace std;

void rightRotationBy1(vector<int>& v)
{
     int n = v.size();
     int temp = v[n-1];
     for(int i=n-2;i>=0;i--)
     {
          v[i+1] = v[i];
     }
     v[0] = temp;
}

void printV(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
          cout << v[i] << " ";
     cout << endl;
}

int main()
{
     vector<int> v{1, 2, 3, 4, 5};
     printV(v);
     rightRotationBy1(v);
     printV(v);
     return 0;
}
