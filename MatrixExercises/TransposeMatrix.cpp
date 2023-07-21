#include <iostream>

const int SIZE = 4;

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void transposeMatrix(int matrix[SIZE][SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = i + 1; j < SIZE; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    int matrix[SIZE][SIZE]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    transposeMatrix(matrix);
    printMatrix(matrix);
}
