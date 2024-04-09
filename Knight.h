//
// Created by caspi on 11/25/2020.
//

#ifndef CHESSEX_KNIGHT_H
#define CHESSEX_KNIGHT_H
#include "Piece.h"
using namespace std;

class Knight : public Piece {
public:
    Knight(Color col, Position* p) :Piece(col, p) { col == White ? setType("n") : setType("N"); }
    bool validMove(const Position& from, const Position& to, Piece* board[8][8]) const;

private:
};


#endif //CHESSEX_KNIGHT_H
