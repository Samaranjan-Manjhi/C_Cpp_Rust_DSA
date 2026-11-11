#include <iostream>

int main() 
{
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr + 1;

    std::cout << *p << " "; // 20
    p += 2;
    std::cout << *p << " "; // 40
    std::cout << *(p - 1) << std::endl; // 30

    return 0;
}
