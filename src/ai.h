#ifndef AI_H
#define AI_H

#include "board.h"

class AI {
public:
    static void aiMove(Board& Board);

private:
    static int minimax(Board& board, bool isAI);

};

#endif  