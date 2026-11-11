/*
   Find the largest of three numbers without if-else
Hint: use ternary operator
Asked at: Capgemini, Cognizant
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b, c;
     cout << "Enter 3 Numbers: ";
     cin >> a >> b >> c;
     int max = (a > b) ? ((a > c) ? a : c)
          : ((b > c) ? b : c);
     cout << "Largest Among 3:- " << max << endl;
     return 0;
}
