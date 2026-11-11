/*
   Temperature converter: Celsius to Fahrenheit
   Asked at: TCS, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     int x;
     cout << "Enter Celsius Value: ";
     cin >> x;
     float fah = (9*x)/5+32;
     cout << "Celsius (" << x <<") to Fahrenheit:- " << fah << endl;
     return 0;
}
