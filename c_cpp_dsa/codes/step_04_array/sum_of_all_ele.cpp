/*
   Find the sum of all elements in an array
   Asked at: TCS, Wipro, Infosys
 */

#include <iostream>
#include <vector>
using namespace std;

int elements_sum(const vector<int>& v)
{
     int sum = 0;
     for(int i=0;i<v.size();i++)
     {
          sum += v[i];
     }
     return sum;
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
     cout << "Result:- " << elements_sum(v) << endl;
     return 0;
}
