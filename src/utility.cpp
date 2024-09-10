#include "utility.hpp"
#include <iostream>

bool checkWin(const Board& board, char player) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (const auto& pattern : winPatterns) {
        if (board.getCell(pattern[0]) == player &&
            board.getCell(pattern[1]) == player &&
            board.getCell(pattern[2]) == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const Board& board) {
    for (int i = 0; i < 9; ++i) {
        if (board.isCellEmpty(i)) {
            return false;
        }
    }
    return true;  // No empty cells left, it's a draw
}

void playerMove(Board& board, char player) {
    int move;
    while (true) {
        std::cout << "Enter your move (1-9): ";
        std::cin >> move;
        move--;  // Convert to 0-based index
        if (move >= 0 && move < 9 && board.isCellEmpty(move)) {
            board.setCell(move, player);
            break;
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
        }
    }
}