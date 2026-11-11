#include <iostream>
using namespace std;
void func(int a) {
    int b = a;
    b = b + 10;
}

int main() {
    int a = 10;
    func(a);
    cout << b << endl;
}
