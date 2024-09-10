#ifndef AI_HPP
#define AI_HPP

#include "board.hpp"

class AI {
public:
    static void aiMove(Board& Board);

private:
    static int minimax(Board& board, bool isAI);

};

#endif  