#include <iostream>

void deleteRow(int** matrix, int n, int m, int row) {
    for (size_t i = 0; i < n; i++) {
        if (i == row) {
            for (size_t j = i; j < n; j++) {
                for (size_t z = 0; z < m; z++) {
                    matrix[j - 1][z] = matrix[j][z];
                }
            }
        }
    }
}

void printMatrix(int** matrix, int n, int m) {
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    int n, m, k;
    std::cout << "Enter size of matrix: ";
    std::cin >> n >> m;

    std::cout << "Enter row to delete:";
    std::cin >> k;
    std::cout << std::endl;

    if (n < 3 || n > 16 || m < 3 || m > 32 || k < 0) {
        throw std::exception("Invalid size!");
    }
    std::cout << std::endl;

    int** matrix = new int* [n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    std::cout << "Enter matrix: " << std::endl;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << std::endl;
    deleteRow(matrix, n, m, k);
    printMatrix(matrix, n, m);

    for (size_t i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
