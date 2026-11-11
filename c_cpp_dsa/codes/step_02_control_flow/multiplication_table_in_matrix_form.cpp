/*
   Print the multiplication table of numbers 1 to N in matrix form
   (N rows and N columns)
   Asked at: Capgemini, TCS
 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=n;j++)
          {
               //cout << i*j << "\t"; // From Left Side aligned
               cout << setw(5) << i*j; // From Right side aligned
          }
          cout << endl;
     }
     return 0;
}
