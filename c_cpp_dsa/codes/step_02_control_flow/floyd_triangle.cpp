/*
Print Floyd's triangle:
             1
             2 3
             4 5 6
             7 8 9 10
             Asked at: TCS, Wipro, Infosys
*/
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     static int cnt = 1;
     for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=i;j++)
          {
               cout << cnt ;
               cnt++;
          }
          //cnt++;
          cout << endl;
     }
     return 0;
}
