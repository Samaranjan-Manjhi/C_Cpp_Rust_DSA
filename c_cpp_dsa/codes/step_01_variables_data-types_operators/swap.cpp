/*
   Swap two numbers without using a third variable
Methods: arithmetic (a=a+b; b=a-b; a=a-b) and XOR (a^=b; b^=a; a^=b)
Asked at: TCS, Infosys, Zoho
 */
#include <iostream>
using namespace std;
int main()
{
     int n, m;
     cout << "Enter 2 Number: ";
     cin >> n >> m;
     cout << "Before Swapping: " << n << "  " << m << endl;
     n ^= m;
     m ^= n;
     n ^= m;
     cout << "After Swapping: " << n << "  " << m << endl;
     return 0;
}
