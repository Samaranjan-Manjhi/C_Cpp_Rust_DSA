/*
   Print the right-aligned triangle pattern for N=4:
 *
 **
 ***
 ****
 Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     for(int i=1;i<=4;i++)
     {
          for(int j=1;j<=4-i;j++)
               cout << " ";
          for(int k=1;k<=i;k++)
               cout << "*";
          cout << endl;
     }
     return 0;
}
