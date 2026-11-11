#include <iostream>

using namespace std;

int main() {
    int input = 2;
    switch (input) {
    case 1:
        cout << "One ";
    case 2:
        cout << "Two ";
    case 3:
        cout << "Three ";
    default:
        cout << "Default ";
        break;
    }

    return 0;
}

