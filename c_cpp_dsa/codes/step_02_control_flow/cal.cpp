/*
     Calculator: read two numbers and an operator (+, -, *, /)
     using switch statement
     Asked at: TCS, Wipro, Zoho
 */
#include <iostream>
using namespace std;
int main()
{
     int a, b;
     cout << "Enter 2 Numbers: ";
     cin >> a >> b;
     char ch;
     cout << "Enter operation(+, -, *, /): ";
     cin >> ch;
     switch(ch)
     {
          case '+':
               {
                    cout << a << " " << ch << " " << b << " = " << a+b << endl;
                    break;
               }
          case '-':
               {
                    cout << a << " " << ch << " " << b << " = " << a-b << endl;
                    break;
               }
          case '*':
               {
                    cout << a << " " << ch << " " << b << " = " << a*b << endl;
                    break;
               }
          case '/':
               {
                    if(b != 0)
                         cout << a << " " << ch << " " << b << " = " << a/b << endl;
                    else
                         cout << "Error: Division by Zero.\n ";
                    break;
               }
          default :
               cout << "Invalid choice.\n";
     }
     return 0;
}
