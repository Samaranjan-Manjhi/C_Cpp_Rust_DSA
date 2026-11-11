#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter Vector Size: ";
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        // Check how many times the same element repeats
        while (i + 1 < n && vec[i] == vec[i + 1]) {
            count++;
            i++;
        }

        // Only print if the element repeats more than once


        if (count > 1) {
            std::cout << count << " times " << vec[i] << "'s" << std::endl;
        }
    }

    return 0;
}

