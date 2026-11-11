/*
   Check if a triangle is valid given 3 sides
   (sum of any two sides must be greater than the third)
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b, c;
     cout << "Enter 3 sides of triangle: ";
     cin >> a >> b >> c;
     if((a+b)>c && (b+c)>a && (c+a)>b)
          cout << "Triangle is Valid.\n";
     else
          cout << "Triangle is Not Valid.\n";
     return 0;
}
