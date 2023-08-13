#include <iostream>

bool isInside(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int** smoother(int** matrix, int n, int m) {
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    int** temp = new int* [n];
    for (size_t i = 0; i < n; i++) {
        temp[i] = new int[m];
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            int sum = matrix[i][j], cnt = 1;

            for (size_t k = 0; k < 8; k++) {
                if (isInside(i + dx[k], j + dy[k], n, m))
                {
                    sum += matrix[i + dx[k]][j + dy[k]];
                    cnt++;
                }
            }
            temp[i][j] = (sum / cnt);
        }
    }

    return temp;
}

void printMatrix(int** matrix, int n, int m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter size of matrix:";
    std::cin >> n;
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

    int** newMatrix = smoother(matrix, 3, 3);
    printMatrix(newMatrix, n, n);

    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (size_t i = 0; i < n; i++)
    {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;
}
