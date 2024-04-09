//
// Created by caspi on 11/23/2020.
//

#ifndef CHESSEX_BISHOP_H
#define CHESSEX_BISHOP_H
#include "Piece.h"
//#define MAX_BISHOP_MOVES 16
using namespace std;

class Bishop :public Piece {
public:
    Bishop(Color col, Position* p) :Piece(col, p) { col == White ? setType("b") : setType("B"); }
    bool validMove(const Position& from, const Position& to, Piece* board[8][8]) const;
private:
};


#endif //CHESSEX_BISHOP_H
