/*
   Print diamond pattern (combination of two triangles)
   Asked at: Wipro, Capgemini, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     int n = 4;
     for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=n-i;j++)
               cout << " ";
          for(int j=1;j<=i;j++)
          {
               cout <<"*";
               for(int i=2;i<=n;i++)
                    cout << "*";
          }
          cout << endl;
     }


     return 0;
}
