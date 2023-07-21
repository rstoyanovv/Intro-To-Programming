#include <iostream>

bool isEven(int number) {
    if (number % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int sumOfEvenElementsUnderMainDiagonal(int** matrix, unsigned n) {
    int sum = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i > j) {
                if (isEven(matrix[i][j])) {
                    sum += matrix[i][j];
                }
            }
        }
    }

    return sum;
}

int sumOfOddElementsAboveMainDiagonal(int** matrix, unsigned n) {
    int sum = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i <= j) {
                if (!isEven(matrix[i][j])) {
                    sum += matrix[i][j];
                }
            }
        }
    }

    return sum;
}

int main()
{
    unsigned n; // size of matrix
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

    std::cout << "Sum of even elements under main diagonal is: " << sumOfEvenElementsUnderMainDiagonal(matrix, n) << std::endl;
    std::cout << "Sum of odd elements above main diagonal is: " << sumOfOddElementsAboveMainDiagonal(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete matrix;
}
