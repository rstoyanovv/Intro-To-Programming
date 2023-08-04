#include <iostream>

bool counter(char** matrix, unsigned size) {
    int counterA = 0;
    int counterB = 0;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (matrix[i][j] == 'a') {
                counterA++;
            }
            else {
                counterB++;
            }
        }
    }

    return counterA > counterB;
}

void printCoordinatesOfRarelyChar(char** matrix, unsigned size, char symbol) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (matrix[i][j] == symbol) {
                std::cout << "(" << i << "," << j << ")" << " ";
            }
        }
    }
}

int main()
{
    unsigned size;

    std::cout << "Enter size of matrix: ";
    std::cin >> size;
    std::cout << std::endl;

    char** matrix = new char* [size];
    for (size_t i = 0; i < size; i++) {
        matrix[i] = new char[size];
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }

    if (!counter) {
        printCoordinatesOfRarelyChar(matrix, size, 'a');
    }
    else {
        printCoordinatesOfRarelyChar(matrix, size, 'b');
    }

    for (size_t i = 0; i < size; i++) {
        delete matrix[i];
    }
    delete[] matrix;

}
