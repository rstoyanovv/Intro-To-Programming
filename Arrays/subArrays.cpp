#include <iostream>

void printSubArray(int* array, int n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - i; j++) {
            std::cout << "[ ";
            for (size_t z = i; z <= i + j; z++) {
                std::cout << array[z] << " ";
            }
            std::cout << "] ";
        }
    }
}

int main()
{
    unsigned n;
    std::cin >> n;

    int* array = new int[n];

    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    printSubArray(array, n);

    delete[] array;
}
