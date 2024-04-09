//
// Created by caspi on 11/23/2020.
//

#ifndef CHESSEX_PIECE_H
#define CHESSEX_PIECE_H
#include "Position.h"



class Piece {
public:
    enum Color { Black, White };
    Piece();
    Piece(const Piece& p) { color = p.color; type = p.type; moved = p.moved; curr = p.curr; }
    Piece(Color col, Position* p) : color(col), moved(false), curr(p), WkingPos(new Position(7, 4)), BkingPos(new Position(0, 4)) {}
    bool virtual validMove(const Position& from, const Position& to, Piece* board[8][8]) const = 0;
    Color getColor() const { return color; }
    Position& getMyKingPos() const { return (color == Black)? *BkingPos: *WkingPos; }
    Position& getOppKingPos() const { return (color == Black) ? *WkingPos : *BkingPos; }
    void setMyKingPos(Position* p) { (color == Black) ? BkingPos = p : WkingPos = p; }
    void setOppKingPos(Position* p) { (color == White) ? BkingPos = p : WkingPos = p; }
    string getType() const { return type; }
    bool getMovedTwice() const { return movedTwice; }
    Position* getPos() const { return curr; }
    void setMovedTwice(bool b) { movedTwice = b; }
    void setColor(Color col) { color = col; }
    void setType(string label) { type = label; }
    void setPos(Position* p) { curr = p; }
    void setMoved(bool m) { moved = true; }
    bool didMove() const { return moved; }
    Piece& operator=(const Piece& p) { color = p.color; type = p.type; return *this; }

private:
    Color color;
    string type;
    bool moved;
    bool movedTwice;
    Position* curr;
    Position* WkingPos;
    Position* BkingPos;

};


#endif //CHESSEX_PIECE_H
