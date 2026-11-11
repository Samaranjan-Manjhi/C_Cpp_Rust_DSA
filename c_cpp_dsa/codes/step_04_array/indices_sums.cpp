/*

   Find the sum of elements at even indices vs odd indices
   Asked at: TCS, Capgemini

 */

#include <iostream>
#include <vector>
using namespace std;
pair<int, int> indices_sum(const vector<int>& v)
{
     int even = 0, odd = 0;
     for(int i=0;i<v.size();i++)
     {
          if(i%2 == 0)
               even += v[i];
          else
               odd += v[i];
     }
     return {even, odd};
}
int main()
{
     int n;
     cout << "Enter Number:- ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];
     pair<int, int> res = indices_sum(v);
     cout << "Result:- " << res.first << " & " << res.second << endl;
     return 0;
}
