#include <iostream>

const int N = 5;

bool equalRings(int matrix[N][N], int& row, int& col) {
    for (int ring = 0; ring <= N / 2; ++ring) {
        int sum = 0;
        int elementsCount = 0;

        for (int c = ring; c < N - ring; ++c) {
            sum += matrix[ring][c];
            ++elementsCount;
        }

        for (int r = ring + 1; r < N - ring; ++r) {
            sum += matrix[r][N - ring - 1];
            ++elementsCount;
        }

        if (ring != N - ring - 1) {
            for (int c = N - ring - 2; c >= ring; --c) {
                sum += matrix[N - ring - 1][c];
                ++elementsCount;
            }
        }

        if (ring != N - ring - 1) {
            for (int r = N - ring - 2; r > ring; --r) {
                sum += matrix[r][ring];
                ++elementsCount;
            }
        }

        int expectedSum = sum / elementsCount * (N - 2 * ring) * 2 + (sum / elementsCount) * (N - 2 * ring - 2) * 2;
        if (sum != expectedSum) {
            row = ring;
            col = ring;
            return false;
        }
    }

    row = -1;
    col = -1;
    return true;
}

int main() {
    int matrix[N][N];

    int row, col;
    bool result = equalRings(matrix, row, col);

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    if (result) {
        std::cout << "All rings are equal." << std::endl;
    }
    else {
        std::cout << "Rings are not equal. First unequal ring starts at (" 
            << row - 1 << ", " << col - 1 << ")." << std::endl;
    }

    return 0;
}
