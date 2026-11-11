/*
Print the inverted triangle pattern for N=4:
             ****
             ***
             **
             *
             Asked at: TCS, Wipro, Capgemini
*/
#include <iostream>
using namespace std;
int main()
{
     for(int i=1;i<=4;i++)
     {
          for(int j=i;j<=4;j++)
               cout << "*";
          cout << endl;
     }
     return 0;
}
