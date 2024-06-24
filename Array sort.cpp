#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // Sort array in ascending order
    std::sort(std::begin(arr), std::end(arr));
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sort array in descending order
    std::sort(std::begin(arr), std::end(arr), std::greater<int>());
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

