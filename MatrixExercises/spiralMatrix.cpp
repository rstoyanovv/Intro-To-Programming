#include <iostream>

void spiralMatrix(int rows, int columns, int** matrix)
{
    int value = 1;
    int top = 0, left = 0, bottom = rows, right = columns;

    while (top < bottom && left < right) {
        /* Print the first row from
               the remaining rows */
        for (int i = left; i < right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        /* Print the last column
         from the remaining columns */
        for (int i = top; i < bottom; i++) {
            matrix[i][right - 1] = value++;
        }
        right--;

        /* Print the last row from
                the remaining rows */
        if (top < bottom) {
            for (int i = right - 1; i >= left; i--) {
                matrix[bottom - 1][i] = value++;
            }
            bottom--;
        }

        /* Print the first column from
                   the remaining columns */
        if (left < right) {
            for (int i = bottom - 1; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
}

void printMatrix(int rows, int columns, int** matrix) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows, columns;
    std::cin >> rows >> columns;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }

    spiralMatrix(rows, columns, matrix);
    printMatrix(rows, columns, matrix);

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
