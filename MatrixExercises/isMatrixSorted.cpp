#include <iostream>

unsigned const SIZE = 5;

bool isRowSorted(int matrix[][SIZE], int row, int colomn) {
    for (size_t i = 0; i < colomn - 1; i++) {
        if (matrix[row][i] > matrix[row][i + 1]) {
            return false;
        }
        else {
            return true;
        }
    }
}

bool isColumnSorted(int matrix[][SIZE], int row, int colomn) {
    for (size_t i = 0; i < row - 1; i++) {
        if (matrix[i][colomn] > matrix[i + 1][colomn]) {
            return false;
        }
        else {
            return true;
        }
    }
}


int main()
{
    int matrix[SIZE][SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];
        }
    }

    bool allRowsAreSorted = true;
    bool allColumnsAreSorted = true;

    for (size_t i = 0; i < SIZE; i++) {
        if (!isRowSorted(matrix, i, SIZE)) {
            allRowsAreSorted = false;
        }
        if (!isColumnSorted(matrix, SIZE, i)) {
            allColumnsAreSorted = false;
        }
    }

    if (allRowsAreSorted && allColumnsAreSorted) {
        std::cout << "Matrix is sorted!" << std::endl;
    }
    else {
        std::cout << "Matrix is not sorted!" << std::endl;
    }
}
