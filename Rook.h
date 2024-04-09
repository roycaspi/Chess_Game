//
// Created by caspi on 11/25/2020.
//

#ifndef CHESSEX_ROOK_H
#define CHESSEX_ROOK_H
#include "Piece.h"
//#define MAX_ROOK_MOVES 16
using namespace std;

class Rook :public Piece {
public:
    Rook(Color col, Position* p) :Piece(col, p) { col == White ? setType("r") : setType("R"); }
//    bool didMove() const { return moved; }
    bool validMove(const Position& from, const Position& to, Piece* board[8][8]) const;

private:
 //   bool moved;

};


#endif //CHESSEX_ROOK_H
