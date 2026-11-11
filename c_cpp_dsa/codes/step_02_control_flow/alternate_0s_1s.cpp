/*
   Print alternating 0 and 1 in a single row for N elements
   e.g. N=6 output: 0 1 0 1 0 1
   Asked at: TCS, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     for(int i=1;i<=n;i++)
     {
          if(i%2==1)
               cout << 0 << " ";
          else
               cout << 1 << " ";
     }
     cout << endl;
     return 0;
}
