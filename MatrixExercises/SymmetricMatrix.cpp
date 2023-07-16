#include <iostream>

const int MAXSIZE = 100;

bool isSymmetric(int** matrix, int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[size - j - 1][size - i - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    unsigned size;
    std::cin >> size;

    int** matrix = new int* [size];
    for (size_t i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }

    if (isSymmetric(matrix, size)) {
        std::cout << "The matrix is symmetric about the secondary diagonal.";
    }
    else {
        std::cout << "The matrix is not symmetric about the secondary diagonal.";
    }

    //deallocating
    for (size_t i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
