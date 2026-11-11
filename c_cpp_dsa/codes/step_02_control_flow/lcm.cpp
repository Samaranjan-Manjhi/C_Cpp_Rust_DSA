/*
   Find LCM of two numbers
   Asked at: TCS, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b;
     cout << "Enter Numbers: ";
     cin >> a >> b;
     int lcm = (a > b) ? a : b;
     for(int i=1;i<=(a*b);i++)
     {
          if(i%a==0 && i%b==0)
               cout << "LCM:- " << i << endl;
     }
     return 0;
}
