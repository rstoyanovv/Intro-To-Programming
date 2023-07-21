#include <iostream>

void squareElementsOnSecondaryDiagonal(int** matrix, unsigned n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i + j == n - 1) {
                matrix[i][j] = matrix[i][j] * matrix[i][j];
            }
        }
    }
}

void printMatrix(int** matrix, unsigned n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    unsigned n;
    std::cin >> n;

    int** matrix = new int* [n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    squareElementsOnSecondaryDiagonal(matrix, n);
    printMatrix(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete matrix;
}

