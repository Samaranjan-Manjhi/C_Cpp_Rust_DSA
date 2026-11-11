/*
     Print the following right-aligned number pattern for N=4:
                1
               12
              123
             1234
     Asked at: TCS, Wipro, Capgemini
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
          for(int j=1;j<=n-i;j++)
          {
               cout << " ";
          }
          for(int j=1;j<=i;j++)
               cout << j ;
          cout << endl;
     }
     return 0;
}
