#include "board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void Board::print() const {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

bool Board::isCellEmpty(int index) const {
    return board[index] == ' ';
}

void Board::setCell(int index, char player) {
    board[index] = player;
}

char Board::getCell(int index) const {
    return board[index];
}