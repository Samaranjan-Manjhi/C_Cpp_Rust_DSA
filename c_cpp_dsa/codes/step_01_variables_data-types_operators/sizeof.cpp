/*
   Print size of all data types using sizeof()
   Asked at: TCS, Wipro, Infosys
 */

#include <iostream>
using namespace std;
int main()
{
     cout << "Size of int:- " << sizeof(int) << " bytes" << endl;
     cout << "Size of float:- " << sizeof(float) << " bytes" << endl;
     cout << "Size of double:- " << sizeof(double) << " bytes" << endl;
     cout << "Size of char:- " << sizeof(char) << " bytes" << endl;
     cout << "Size of bool:- " << sizeof(bool) << " bytes" << endl;
     cout << "Size of void:- " << sizeof(void) << " bytes" << endl;
     cout << "Size of short int:- " << sizeof(short int) << " bytes" << endl;
     cout << "Size of long int:- " << sizeof(long int) << " bytes" << endl;
     cout << "Size of long long int:- " << sizeof(long long int) << " bytes" << endl;
     cout << "Size of unsigned int:- " << sizeof(unsigned int) << " bytes" << endl;
     return 0;
}
