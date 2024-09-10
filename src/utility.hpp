#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "board.hpp"

// Checks if a player has won the game
bool checkWin(const Board& board, char player);

// Checks if the game is a draw
bool checkDraw(const Board& board);

// Gets input from the player and update the board
void playerMove(Board& board, char player);

#endif  