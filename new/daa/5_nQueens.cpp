#include <iostream>
#include <vector>

// Function to print the N-Queens board
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] == 1) {
                std::cout << "Q ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function to check if a queen can be placed at a specific position
bool isSafe(const std::vector<std::vector<int>>& board, int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the lower left diagonal
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(std::vector<std::vector<int>>& board, int col) {
    int n = board.size();
    if (col >= n) {
        // All queens have been successfully placed
        printBoard(board);
        return true;
    }

    bool result = false;
    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            // Recur to place the remaining queens
            result = solveNQueens(board, col + 1) || result;

            board[i][col] = 0; // Backtrack
        }
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of queens (N): ";
    std::cin >> n;

    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));

    // First Queen is already placed, so start from the second column
    int startingColumn = 0;

    if (solveNQueens(board, startingColumn)) {
        std::cout << "Solutions found." << std::endl;
    } else {
        std::cout << "No solutions found." << std::endl;
    }

    return 0;
}

