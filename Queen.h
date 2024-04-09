//
// Created by caspi on 11/25/2020.
//

#ifndef CHESSEX_QUEEN_H
#define CHESSEX_QUEEN_H
#include "Piece.h"
//#define MAX_QUEEN_MOVES 64
using namespace std;

class Queen : public Piece {
public:
    Queen(Color col, Position* p) :Piece(col, p) { col == White ? setType("q") : setType("Q"); }
    bool validMove(const Position& from, const Position& to, Piece* board[8][8]) const;

private:
};


#endif //CHESSEX_QUEEN_H
