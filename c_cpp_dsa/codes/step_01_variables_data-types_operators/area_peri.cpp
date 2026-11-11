/*
   Simple interest calculator: SI = (P * R * T) / 100
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
#include <cmath> 
using namespace std;
#define pie 3.14

float areaCir(float r)
{
     return pie*r*r;
}

float periCir(float r)
{
     return 2*pie*r;
}

float areaRect(float l, float b)
{
     return l*b;
}

float periRect(float l, float b)
{
     return (2*(l+b));
}

float areaTri(float b, float h)
{
     return 0.5*b*h;
}

float periTri(float a, float b, float c)
{
     return a+b+c;
}

int main()
{
     int choice;
     do 
     {
          cout << "------------Start--------------\n";
          cout << "1. Area of Circle\n";
          cout << "2. Perimeter of Circle\n";
          cout << "3. Area of Rectangle\n";
          cout << "4. Perimeter of Rectangle\n";
          cout << "5. Area of Triangle\n";
          cout << "6. Perimeter of Triangle\n";
          cout << "7. Exit ...\n";
          cout << "Enter Choice: ";
          cin >> choice;
          switch(choice)
          {
               case 1:
                    {
                         int r;
                         cout << "Enter Radius of Circle: ";
                         cin >> r;
                         cout << "Area of Circle:- " << areaCir(r) << endl;
                         break;
                    }
               case 2:
                    {
                         int r;
                         cout << "Enter Radius of Circle: ";
                         cin >> r;
                         cout << "Perimeter of Circle:- " << periCir(r) << endl;
                         break;
                    }
               case 3:
                    {
                         int l, b;
                         cout << "Enter length of Rectangle: ";
                         cin >> l;
                         cout << "Enter breadth of Rectangle: ";
                         cin >> b;
                         cout << "Area of Rectangle:- " << areaRect(l, b) << endl;
                         break;
                    }
               case 4:
                    {
                         int l, b;
                         cout << "Enter length of Rectangle: ";
                         cin >> l;
                         cout << "Enter breadth of Rectangle: ";
                         cin >> b;
                         cout << "Perimeter of Rectangle:- " << periRect(l, b) << endl;
                         break;
                    }
               case 5:
                    {
                         int b, h;
                         cout << "Enter base of Triangle: ";
                         cin >> b;
                         cout << "Enter height of Triangle: ";
                         cin >> h;
                         cout << "Area of Triangle:- " << areaTri(b, h) << endl;
                         break;
                    }
               case 6:
                    {
                         int a, b, c;
                         cout << "Enter side(A) of Triangle: ";
                         cin >> a;
                         cout << "Enter side(B) of Triangle: ";
                         cin >> b;
                         cout << "Enter side(C) of Triangle: ";
                         cin >> c;
                         cout << "Perimeter of Triangle:- " << periTri(a, b, c) << endl;
                         break;
                    }
               case 7:
                    {
                         cout << "Exiting ...\n";
                         return 0;
                    }
               default:
                    {
                         cout << "Enter choice is Wrong.\n";
                    }
          }

     }    while(choice != 7);

     return 0;
}
