#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], unsigned size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void sortMatrix(int** matrix, unsigned rows, unsigned colomns) {
    for (size_t i = 0; i < rows; i++) {
        bubbleSort(matrix[i], colomns);
    }

    for (size_t i = 0; i < colomns; i++) {
        int* colomn = new int[rows];
        for (size_t j = 0; j < rows; j++) {
            colomn[j] = matrix[j][i];
        }

        bubbleSort(colomn, rows);

        for (size_t j = 0; j < rows; j++) {
            matrix[j][i] = colomn[j];
        }

        delete[] colomn;
    }
}

int main()
{
    unsigned rows, colomns;

    std::cout << "Enter rows of matrix: ";
    std::cin >> rows;
    std::cout << std::endl;

    std::cout << "Enter colomns of matrix: ";
    std::cin >> colomns;
    std::cout << std::endl;

    int** matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new int[colomns];
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < colomns; j++) {
            std::cin >> matrix[i][j];
        }
    }

    sortMatrix(matrix, rows, colomns);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < colomns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (size_t i = 0; i < rows; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
