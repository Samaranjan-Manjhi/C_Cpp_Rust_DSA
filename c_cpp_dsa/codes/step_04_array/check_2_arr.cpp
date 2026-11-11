/*
   Check if two arrays have the same elements (not necessarily same order)
   without sorting — use frequency map
   Asked at: TCS, Wipro
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool check_2_arr(const vector<int>& v, const vector<int>& v1)
{
     if(v.size() != v1.size())     
          return false;
     unordered_map<int, int> m1;
     unordered_map<int, int> m2;
     for(int x : v)
     {
          m1[x]++;
     }
     for(int x1 : v1)
     {
          m2[x1]++;
     }
     
     return m1 == m2;
}

int main()
{
     vector<int> v{1, 2, 3, 4, 5};
     vector<int> v1{2, 2, 5, 3, 4};
     bool res = check_2_arr(v, v1);
     if(res)
          cout << "Vectors are identical.\n";
     else
          cout << "Vectors are not identical.\n";
     return 0;
} 
