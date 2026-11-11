#include <iostream>
using namespace std;

int main() {
    int x = -1;
    try {
        cout << "Try ";
        if (x < 0) {
            throw x;
            cout << "Throw ";
        }
    } catch (int x) {
        cout << "Caught ";
    }

    cout << "Exit";
    return 0;
}
