#include <iostream>

bool isContainsOne(int number) {
    while (number > 0) {
        if (number % 10 == 1) {
            return true;
        }
        number /= 10;
    }
    return false;
}

void printDiagonals(int** matrix, int size) {

    int sum = 0;
    int result = 1;

    //print under main diagonal including it
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (i >= j) {
                std::cout << matrix[i][j] << " ";
                if (i > j) {
                    sum += matrix[i][j];
                }              
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //print over main diagonal
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (i < j) {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //print under secondary diagonal
    for (size_t i = 1; i < size; i++) {
        for (size_t j = 1; j < size; j++) {
            if (i + j >= size) {
                std::cout << matrix[i][j] << " ";
                if (isContainsOne(matrix[i][j])) {
                    result *= matrix[i][j];
                }       
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //print over secondary diagonal including it
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (i + j < size) {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Sum under main diagonal: " << sum << std::endl;
    std::cout << "Product under secondary diagonal of numbers includes '1': " << result << std::endl;
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
    std::cout << "===========" << std::endl;

    printDiagonals(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
