//
// Created by caspi on 11/23/2020.
//

#ifndef CHESSEX_POSITION_H
#define CHESSEX_POSITION_H
#include <iostream>
using namespace std;

class Position {
public:
    Position(int row, int col) :row(row), col(col) {}
    int getRow() const { return row; }
    int getCol() const { return col; }
    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }

private:
    int row;
    int col;

};


#endif //CHESSEX_POSITION_H
