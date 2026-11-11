/*
   Find sum of series: 1 + 1/2 + 1/3 + ... + 1/N
   Asked at: Capgemini, Wipro
 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     double sum = 0.0;
     for(int i=1;i<=n;++i)
     {
          sum += 1.0/i ;
     }
     cout << fixed << setprecision(6);
     cout << "Result:- " << sum << endl;
     return 0;
}
