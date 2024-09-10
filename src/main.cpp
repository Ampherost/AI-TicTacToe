#include <iostream>
#include "board.h"
#include "ai.h"
#include "utility.h"

int main() {
    Board board;  // Create the Tic-Tac-Toe game board
    char currentPlayer = 'X';  // Player 'X' goes first

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    board.print();  // Show the initial empty board

    // Main game loop
    while (true) {
        if (currentPlayer == 'X') {
            // Player's move (human)
            playerMove(board, currentPlayer);
        } else {
            // AI's move
            std::cout << "AI is making a move..." << std::endl;
            AI::aiMove(board);
        }

        // Print the updated board after the move
        board.print();

        // Check for a winner or draw
        if (checkWin(board, currentPlayer)) {
            std::cout << (currentPlayer == 'X' ? "You win!" : "AI wins!") << std::endl;
            break;
        }
        if (checkDraw(board)) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        // Switch the current player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
