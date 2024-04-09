//
// Created by caspi on 11/25/2020.
//

#include "Pawn.h"

bool Pawn::validMove(const Position& from, const Position& to, Piece* board[8][8]) const {
    int rowto = to.getRow(), colto = to.getCol(), rowfrom = from.getRow(), colfrom = from.getCol();
    Piece* SquareTo = board[rowto][colto];
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
    if (getColor() == Black) //checks if white pawn move is legal
    {
        if (rowfrom - rowto < -2 || colfrom - colto < -1 || colfrom - colto > 1)
            return false;
        if ((rowfrom - rowto == -2 && !didMove()) && colfrom - colto == 0 && board[rowfrom + 1][colto] == NULL
            && board[rowto][colto] == NULL)
            return true;
        if ((rowfrom - rowto == -2 && !didMove()) && colfrom - colto == 0 && board[rowto][colto]->getPos()->getCol() == -1)
            if (board[rowfrom + 1][colto] != NULL)
            {
                if (board[rowfrom + 1][colto]->getPos()->getCol() == -1)
                    return true;
            }
        if (rowfrom - rowto > 0)
            return false;
        if (rowfrom - rowto == -1 && colfrom - colto == -1)
        {
            if (SquareTo == NULL) // checks en passant
            {
                    return board[rowfrom][colto]->getMovedTwice() ? true : false;
            }
            if (SquareTo->getPos()->getRow() == -1)
                return board[rowfrom][colto]->getMovedTwice() ? true : false;
            return SquareTo->getColor() != Black ? true : false;
        }
        if (rowfrom - rowto == -1 && colfrom - colto == 1)
        {
            if (SquareTo == NULL) // checks en passant
            {
                 return board[rowfrom][colto]->getMovedTwice() ? true : false;
            }
            if (SquareTo->getPos()->getRow() == -1)
                return board[rowfrom][colto]->getMovedTwice() ? true : false;
            return SquareTo->getColor() != Black ? true : false;
        }
        if (rowfrom - rowto == -1 && colfrom - colto == 0 && board[rowto][colto] != NULL)
        {
            if(board[rowto][colto]->getPos()->getCol() == -1)
                return true;
            return false;
        }
        if (rowfrom - rowto == -1 && colfrom - colto == 0 && board[rowto][colto] == NULL)
            return true;
    }
    if (getColor() == White)//checks if black pawn move is legal
    {
        if (rowfrom - rowto > 2 || colfrom - colto < -1 || colfrom - colto > 1)
            return false;
        if ((rowfrom - rowto == 2 && !didMove()) && colfrom - colto == 0 && board[rowfrom - 1][colfrom] == NULL 
            && board[rowto][colto] == NULL)
            return true;
        if ((rowfrom - rowto == 2 && !didMove()) && colfrom - colto == 0 && board[rowto][colto]->getPos()->getCol() == -1)
        {
            if (board[rowfrom - 1][colfrom] != NULL)
            {
                if (board[rowfrom - 1][colfrom]->getPos()->getCol() == -1)
                    return true;
            }
            return false;
        }
        if (rowfrom - rowto < 0)
            return false;
        if (rowfrom - rowto == 1 && colfrom - colto == -1)
        {
            if (SquareTo == NULL) // checks en passant
            {
                    return board[rowfrom][colto]->getMovedTwice() ? true : false;
            }
            if (SquareTo->getPos()->getRow() == -1)
                return board[rowfrom][colto]->getMovedTwice() ? true : false;
            return SquareTo->getColor() != White ? true : false;
        }
        if (rowfrom - rowto == 1 && colfrom - colto == 1)
        {
            if (SquareTo == NULL) // checks en passant
            {
                return board[rowfrom][colto]->getMovedTwice() ? true : false;
            }
            if (SquareTo->getPos()->getRow() == -1)
                return board[rowfrom][colto]->getMovedTwice() ? true : false;
            return SquareTo->getColor() != White ? true : false;
        }
        if (rowfrom - rowto == 1 && colfrom - colto == 0 && board[rowto][colto] != NULL)
        {
            if (board[rowto][colto]->getPos()->getCol() == -1)
                return true;
            return false;
        }
        if (rowfrom - rowto == 1 && colfrom - colto == 0 && board[rowto][colto] == NULL)
            return true;
    }
    return false;

}