#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();

    void print() const;

    bool isCellEmpty(int index) const;

    void setCell(int index, char player);

    char getCell(int index) const;

private:
char board[9];

};

#endif  