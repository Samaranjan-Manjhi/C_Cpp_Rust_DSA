/*
   Read name and age, print a greeting sentence
   (Practice: cin, cout, getline)
   Asked at: TCS, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     string name = "";
     cout << "Enter Name: ";
     getline(cin, name);
     int age;
     cout << "Enter Age: ";
     cin >> age;
     cout << "Hello, " << name << endl;
     cout << "\t Nice To Meet You.\n";
     return 0;
}
