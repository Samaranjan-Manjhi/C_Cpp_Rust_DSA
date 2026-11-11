#include <iostream>
#include <string>

using namespace std;
class A {
    int a;
    public:
          A() {}
        A(int i) {
            a = i;
        }
        void assign(int i) {
            a = i;
        }
        int getA() {
            return a;
        }
};
int main() {
    A obj;
    obj.assign(5);
    cout << obj.getA();
}
