/*
   Find all pairs (i, j) where i < j and arr[i] > arr[j] — brute force O(N^2)
   (Count inversions — brute force version before learning merge sort)
   Asked at: TCS, Infosys, Wipro
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
     vector<int> v{1, 7, 2, 45, 57 ,8 ,5 ,4, 3, 6, 90};
     int n = v.size();
     cout << "All Pairs are (i < j && v[i] > v[j]):- \n";
     for(int i=0;i<n-1;i++)
     {
          for(int j=i+1;j<n;j++)
          {
               if(i < j && v[i] > v[j])
               {
                    cout << "(" << i << " & " << j << ")" << endl;
                    swap(v[i] , v[j]);
               }
          }
     }
     cout << "Elements after sort (merge sort) :- ";
     for(int x : v)
     {
          cout << x << " ";
     }
     cout << endl;
     return 0;
}
