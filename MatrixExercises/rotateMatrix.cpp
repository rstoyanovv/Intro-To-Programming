#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void transpose(int** matrix, int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (i > j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}

void reflect(int** matrix, int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size / 2; j++) {
            swap(matrix[i][j], matrix[i][size - j - 1]);
        }
    }
}

void rotateMatrix(int** matrix, int size) {
    transpose(matrix, size);
    reflect(matrix, size);
}

void printMatrix(int** matrix, int n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;

    std::cout << "Enter size of matrix: ";
    std::cin >> n;
    std::cout << std::endl;

    int** matrix = new int* [n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    std::cout << "Enter matrix: " << std::endl;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix, n);
    printMatrix(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
