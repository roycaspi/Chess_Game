//
// Created by caspi on 11/25/2020.
//

#ifndef CHESSEX_PAWN_H
#define CHESSEX_PAWN_H
#include "Piece.h"
using namespace std;

class Pawn : public Piece {
public:
    Pawn(Color col, Position* p) :Piece(col, p) { col == White ? setType("p") : setType("P"); }
    Pawn(const Piece &p):Piece(p) {}
//    bool didMove() const { return moved; }
    bool validMove(const Position& from, const Position& to, Piece* board[8][8]) const;
 //   void setMoved(bool m) { moved = true; }


private:
  //  bool movedTwice;
 //   bool moved;
};


#endif //CHESSEX_PAWN_H
