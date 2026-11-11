/*
   Grade calculator — read marks and print grade
   (90+ = A, 80+ = B, 70+ = C, 60+ = D, below = F)
   Asked at: TCS, Wipro, Infosys, Capgemini
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter mark to get Grade: ";
     cin >> n;
     if(n >= 90)
          cout << "A Grade.\n";
     else if(n >= 80 && n < 90)
          cout << "B Grade.\n";
     else if(n >= 70 && n < 80)
          cout << "C Grade.\n";
     else if(n >= 60 && n < 70)
          cout << "D Grade.\n";
     else
          cout << "Fail.\n";
     return 0;
}
