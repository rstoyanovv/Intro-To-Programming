#include <iostream>

void displayBoard(char** board, unsigned size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(char** board, unsigned size, char player) {
    for (size_t i = 0; i < size; ++i) {
        bool rowWin = true;
        bool colWin = true;
        for (size_t j = 0; j < size; ++j) {
            if (board[i][j] != player) {
                rowWin = false;
            }
            if (board[j][i] != player) {
                colWin = false;
            }
        }
        if (rowWin || colWin) {
            return true;
        }
    }

    bool mainDiagonalWin = true;
    bool secondaryDiagonalWin = true;
    for (size_t i = 0; i < size; ++i) {
        if (board[i][i] != player) {
            mainDiagonalWin = false;
        }
        if (board[i][size - 1 - i] != player) {
            secondaryDiagonalWin = false;
        }
    }
    if (mainDiagonalWin || secondaryDiagonalWin) {
        return true;
    }

    return false;
}

int main() {
    unsigned n;

    std::cout << "Enter the board size: ";
    std::cin >> n;

    char** board = new char* [n];
    for (size_t i = 0; i < n; i++) {
        board[i] = new char[n];
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            board[i][j] = '-';
        }
    }

    bool isPlayerX = true; // True for Player X, False for Player O
    int totalMoves = n * n;

    while (totalMoves > 0) {
        displayBoard(board, n);

        int row, col;
        char symbol = (isPlayerX) ? 'X' : 'O';
        std::cout << "Player " << symbol << ", enter row and column (separated by space): ";
        std::cin >> row >> col;

        if (row < 0 || row >= n || col < 0 || col >= n || board[row][col] != '-') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row][col] = symbol;

        if (checkWin(board, n, symbol)) {
            std::cout << "Player " << symbol << " wins!" << std::endl;
            displayBoard(board, n);
            return 0;
        }

        isPlayerX = !isPlayerX;
        totalMoves--;
    }

    std::cout << "It's a draw!" << std::endl;
    displayBoard(board, n);

    for(size_t i = 0; i < n; i++) {
        delete board[i];
    }
    delete[] board;
    
    return 0;
}
