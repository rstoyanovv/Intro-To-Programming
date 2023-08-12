#include <iostream>
#pragma warning(disable: 4996)

const int MAX_SIZE = 3;
const int MAX_SIZE2 = 16;

int main() {
    int cnt = 0;
    char strMatrix[MAX_SIZE][MAX_SIZE][MAX_SIZE2];

    for (int rowIndex = 0; rowIndex < MAX_SIZE; rowIndex++) {
        for (int colIndex = 0; colIndex < MAX_SIZE; colIndex++) {
            std::cin >> strMatrix[rowIndex][colIndex];
        }
    }

    for (int rowIndex = 0; rowIndex < MAX_SIZE; rowIndex++) {
        for (int colIndex = 0; colIndex <= rowIndex; colIndex++) {
            int len = std::strlen(strMatrix[rowIndex][colIndex]);

            char revStr[MAX_SIZE2];
            for (int strIndex = len - 1; strIndex >= 0; strIndex--) {
                revStr[len - strIndex - 1] = strMatrix[rowIndex][colIndex][strIndex];
            }
            revStr[len] = '\0';

            if (strcmp(strMatrix[rowIndex][colIndex], revStr) == 0) {
                cnt++;
            }
        }
    }

    std::cout << cnt;
}
