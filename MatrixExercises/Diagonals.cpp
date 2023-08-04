#include <iostream>

void printDiagonal(int** matrix, unsigned size, int row, int colomn, bool mainDiagonal){
    while (row >= 0 && colomn >= 0 && row < size && colomn < size) {
        std::cout << matrix[row][colomn] << " ";
        if (mainDiagonal) {
            row++;
            colomn++;
        }
        else {
            row++;
            colomn--;
        }
    }

    std::cout << std::endl;
}

int main()
{
    unsigned size;

    std::cout << "Enter size of matrix: ";
    std::cin >> size;
    std::cout << std::endl;

    int** matrix = new int* [size];
    for (size_t i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Main diagonal:" << std::endl;
    printDiagonal(matrix, size, 0, 0, true);

    std::cout << "Other diagonals in the main direction:" << std::endl;
    for (size_t i = 1; i < size; i++) {
        printDiagonal(matrix, size, 0, i, true);
    }

    for (size_t i = 1; i < size; i++) {
        printDiagonal(matrix, size, i, 0, true);
    }

    std::cout << "Secondary diagonal:" << std::endl;
    printDiagonal(matrix, size, 0, size - 1, false);

    std::cout << "Other diagonals in the secondary direction:" << std::endl;
    for (size_t i = 1; i < size; i++) {
        printDiagonal(matrix, size, 0, size - 1 - i, false);
    }

    for (size_t i = 1; i < size; i++) {
        printDiagonal(matrix, size, i, size - 1, false);
    }

    for (size_t i = 0; i < size; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
