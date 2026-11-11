#include <iostream>
using namespace std;

class Base {
    public:
        void show() {
            cout << "Base class show() method called" << endl;
        }
};

class Derived: public Base {
    public: void show() {
        cout << "Derived class show() method called" << endl;
    }
};

int main() {
    Derived d;
    d.show();

}
