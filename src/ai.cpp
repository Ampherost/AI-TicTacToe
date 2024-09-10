#include "ai.h"
#include "utility.h"
#include <algorithm>

int AI::minimax(Board& board, bool isAI) {
    // Base cases: Check for a winner or draw
    if (checkWin(board, 'O')) return 10;    // AI wins
    if (checkWin(board, 'X')) return -10;   // Player wins
    if (checkDraw(board)) return 0;         // Draw

    int bestScore = isAI ? -1000 : 1000;    // AI maximizes, player minimizes

    for (int i = 0; i < 9; ++i) {
        if (board.isCellEmpty(i)) {
            board.setCell(i, isAI ? 'O' : 'X');  // AI plays 'O', Player plays 'X'
            int score = minimax(board, !isAI);   // Recursive call
            board.setCell(i, ' ');  // Undo move

            bestScore = isAI ? std::max(bestScore, score) : std::min(bestScore, score);
        }
    }
    return bestScore;
}

void AI::aiMove(Board& board) {
    int bestMove = -1;
    int bestScore = -1000;

    for (int i = 0; i < 9; ++i) {
        if (board.isCellEmpty(i)) {
            board.setCell(i, 'O');
            int score = minimax(board, false);  // Player's turn after AI's move
            board.setCell(i, ' ');  // Undo move

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    board.setCell(bestMove, 'O');  // AI makes the best move
}