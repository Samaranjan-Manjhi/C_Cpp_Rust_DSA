/*
   Print Fibonacci series up to N terms
   Asked at: TCS, Wipro, Infosys, Capgemini
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b, n;
     cout << "Enter Number(n>=2): ";
     cin >> n;
     a = 0, b = 1;
     cout << a  << " " << b << " ";
     int i = 2;
     while(i < n)
     {
          int temp = a + b;
          a = b;
          b = temp;
          cout << temp << " ";
          i++;
     }
     cout << endl;
     return 0;
}
