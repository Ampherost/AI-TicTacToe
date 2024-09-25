#include <gtest/gtest.h>
#include "board.hpp"
#include "utility.hpp"  

TEST(BoardTest, InitialBoardIsEmpty) {
    Board board;

    for (int i = 0; i < 9; ++i) {
        EXPECT_TRUE(board.isCellEmpty(i)) << "Cell " << i << " should be empty.";
    }
}

TEST(BoardTest, PlayerCanMakeMove) {
    Board board;

    board.setCell(4, 'X');
    EXPECT_FALSE(board.isCellEmpty(4)) << "Cell 4 should no longer be empty.";
    EXPECT_EQ(board.getCell(4), 'X') << "Cell 4 should contain 'X'.";
}

TEST(BoardTest, PlayerXWinsHorizontally) {
    Board board;

    board.setCell(0, 'X');
    board.setCell(1, 'X');
    board.setCell(2, 'X');

    EXPECT_TRUE(checkWin(board, 'X')) << "Player 'X' should win with a horizontal row.";
}

TEST(BoardTest, DrawCondition) {
    Board board;

    board.setCell(0, 'X'); board.setCell(1, 'O'); board.setCell(2, 'X');
    board.setCell(3, 'X'); board.setCell(4, 'O'); board.setCell(5, 'X');
    board.setCell(6, 'O'); board.setCell(7, 'X'); board.setCell(8, 'O');

    EXPECT_TRUE(checkDraw(board)) << "The game should be a draw.";
    EXPECT_FALSE(checkWin(board, 'X')) << "Player 'X' should not win.";
    EXPECT_FALSE(checkWin(board, 'O')) << "Player 'O' should not win.";
}

TEST(BoardTest, PlayerOWinsVertically) {
    Board board;

    board.setCell(0, 'O');
    board.setCell(3, 'O');
    board.setCell(6, 'O');

    EXPECT_TRUE(checkWin(board, 'O')) << "Player 'O' should win with a vertical column.";
}
