#include <iostream>
using namespace std;

int main() {
    try {
        throw 100;
    } catch (...) {
        cout << "Default Exception";
    } catch (int param) {
        cout << "Int Exception";
    }
    return 0;
}
