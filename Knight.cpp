//
// Created by caspi on 11/25/2020.
//

#include "Knight.h"

bool Knight::validMove(const Position& from, const Position& to, Piece* board[8][8]) const {
    int rowto = to.getRow(), colto = to.getCol(), rowfrom = from.getRow(), colfrom = from.getCol();
    //int diff[] = { -2, -1, 1, 2 }; //the valid row and column differnces for a knight
    if (rowto > 7 || rowto < 0 || colto > 7 || colto < 0) //checks if out of bounds
        return false;
    if (board[rowto][colto] != NULL)
    {
        if (board[rowto][colto]->getPos()->getRow() != 1)
        {
            if (board[rowto][colto]->getColor() == this->getColor()) //checks if the square is taken by one of our pieces
                return false;
        }
    }
    if (rowfrom - rowto < -2 || rowfrom - rowto > 2 || rowfrom - rowto == 0 || rowfrom - rowto == colfrom - colto)//checks if the row difference is not valid
        return false;
    if (colfrom - colto < -2 || colfrom - colto > 2 || colfrom - colto == 0)//checks if the column difference is not valid
        return false;
    return true;
}