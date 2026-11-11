/*

   Create a class Rectangle with width and length.
   Add methods: area(), perimeter(), isSquare().
   Create 3 objects and call all methods.
   Asked at: TCS, Wipro, Infosys

 */

#include <iostream>
using namespace std;

class Rectangle
{
     private:
          int length;
          int width;

     public:
          // Constructor
          Rectangle(int l, int w)
          {
               length = l;
               width = w;
          }

          int area()
          {
               return length * width;
          }

          int perimeter()
          {
               return 2 * (length + width);
          }

          bool isSquare()
          {
               return length == width;
          }
};

int main()
{
     Rectangle rect1(10, 20);
     Rectangle rect2(15, 15);
     Rectangle rect3(8, 5);

     cout << "Rectangle 1\n";
     cout << "  Area = " << rect1.area() << endl;
     cout << "  Perimeter = " << rect1.perimeter() << endl;
     cout << "  Is Square? " << (rect1.isSquare() ? "Yes" : "No") << endl;

     cout << "\nRectangle 2\n";
     cout << "  Area = " << rect2.area() << endl;
     cout << "  Perimeter = " << rect2.perimeter() << endl;
     cout << "  Is Square? " << (rect2.isSquare() ? "Yes" : "No") << endl;

     cout << "\nRectangle 3\n";
     cout << "  Area = " << rect3.area() << endl;
     cout << "  Perimeter = " << rect3.perimeter() << endl;
     cout << "  Is Square? " << (rect3.isSquare() ? "Yes" : "No") << endl;

     return 0;
}
