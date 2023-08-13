#include <iostream>

void biggestSum(int** matrix, int size) {

    int currentSumRow = 0;
    int currentMaxSum = 0;
    int maxRow = -1;

    int currentSumCol = 0 ;
    int currentMaxSumCol = 0;
    int maxColomn = -1;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            currentSumRow += matrix[i][j];
            currentSumCol += matrix[j][i];
        }

        if (currentSumRow > currentMaxSum) {
            currentMaxSum = currentSumRow;
            currentSumRow = 0;
            maxRow = i;
        }
        else {
            currentSumRow = 0;
        }
        
        if (currentSumCol > currentMaxSumCol) {
            currentMaxSumCol = currentSumCol;
            currentSumCol = 0;
            maxColomn = i;
        }
        else {
            currentSumCol= 0;
        }
    }

    std::cout << "Horizontal sum: " << currentMaxSum << " on row: " << maxRow + 1 << std::endl;
    std::cout << "Vertical sum: " << currentMaxSumCol << " on colomn: " << maxColomn + 1 << std::endl;
}


int main()
{
    int n;
    std::cout << "Enter size of matrix: ";
    std::cin >> n;
    if (n < 3 || n > 32) {
        throw std::exception("Invalid size!");
    }
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
    
    biggestSum(matrix, n);

    for (size_t i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
