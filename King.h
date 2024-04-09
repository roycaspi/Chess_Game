//
// Created by caspi on 11/25/2020.
//

#ifndef CHESSEX_KING_H
#define CHESSEX_KING_H
#include "Piece.h"
using namespace std;

class King : public Piece {
public:
    King(Color col, Position* p) :Piece(col, p) { col == White ? setType("k") : setType("K"); }
    bool validMove(const Position& from, const Position& to, Piece* board[8][8]) const;
  //  bool didMove() const { return moved; }

private:
   // bool moved;

};


#endif //CHESSEX_KING_H
