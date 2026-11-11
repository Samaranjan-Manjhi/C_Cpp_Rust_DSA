/*
   Print the following pattern for N=4:
 *
 **
 ***
 ****
 Asked at: TCS, Wipro, Capgemini, Zoho
 */
#include <iostream>
using namespace std;
int main()
{
     for(int i=1;i<=4;i++)
     {
          for(int j=1;j<=i;j++)
               cout << "*";
          cout << endl;
     }
     return 0;
}
