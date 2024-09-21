#include <iostream>
#include "board.hpp"
#include "ai.hpp"
#include "utility.hpp"

int main() {
    Board board;  
    char currentPlayer = 'X';  

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    board.print();  

    while (true) {
        if (currentPlayer == 'X') {
            playerMove(board, currentPlayer);
        } else {
            std::cout << "AI is making a move..." << std::endl;
            AI::aiMove(board);
        }

        board.print();

        if (checkWin(board, currentPlayer)) {
            std::cout << (currentPlayer == 'X' ? "You win!" : "AI wins!") << std::endl;
            break;
        }
        if (checkDraw(board)) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }


    std::string key;
    std::cout << "Press any key followed by Enter to exit: ";
    std::cin >> key;  

    return 0;
}
