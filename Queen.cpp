//
// Created by caspi on 11/25/2020.
//

#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

bool Queen::validMove(const Position& from, const Position& to, Piece* board[8][8]) const 
{
    int rowto = to.getRow(), colto = to.getCol(), rowfrom = from.getRow(), colfrom = from.getCol();
    Piece* CurrSquare;
  //  Rook* r = new Rook();
  //  Bishop* b = new Bishop();
    if (rowto > 7 || rowto < 0 || colto > 7 || colto < 0) //checks if out of bounds
        return false;
    if (board[rowto][colto] != NULL)
    {
        if (board[rowto][colto]->getPos()->getRow() != -1)
        {
            if (board[rowto][colto]->getColor() == this->getColor()) //checks if the square is taken by one of our pieces
                return false;
        }
    }
   // if (r->validMove(from, to, board))//todo check if works
    if (rowfrom - rowto == 0 || colfrom - colto == 0)//checks if the move is valid for the rook
    {
        if (rowfrom - rowto == 0)
        {
            int diff = (colfrom - colto < 0) ? (colfrom - colto) * -1 : colfrom - colto;
            for (int i = 1; i < diff; i++)
            {
                if (colfrom - colto < 0)
                {
                    CurrSquare = board[rowfrom][colfrom + i];
                    if (CurrSquare != NULL)
                    {
                        if(board[rowto][colto]->getPos()->getRow() != -1)
                            return false;
                    }
                }
                if (colfrom - colto > 0)
                {
                    CurrSquare = board[rowfrom][colfrom - i];
                    if (CurrSquare != NULL)
                    {
                        if(board[rowto][colto]->getPos()->getRow() != -1)
                            return false;
                    }
                }
            }
        }
        if (colfrom - colto == 0)
        {
            int diff = (rowfrom - rowto < 0) ? (rowfrom - rowto) * -1 : rowfrom - rowto;
            for (int i = 1; i < diff; i++)
            {
                if (rowfrom - rowto < 0)
                {
                    CurrSquare = board[rowfrom + i][colfrom];
                    if (CurrSquare != NULL)
                    {
                        if(board[rowto][colto]->getPos()->getRow() != -1)
                            return false;
                    }
                }
                if (rowfrom - rowto > 0)
                {
                    CurrSquare = board[rowfrom - i][colfrom];
                    if (CurrSquare != NULL)
                    {
                        if (board[rowto][colto]->getPos()->getRow() != -1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
   // if (b->validMove(from, to, board)) {}//todo check if works
    if (rowfrom - rowto == colfrom - colto || rowfrom - rowto == (colfrom - colto) * -1)//checks if the move is valid for the bishop
    {
        int diff = (rowfrom - rowto < 0) ? (rowfrom - rowto) * -1 : rowfrom - rowto;
        for (int i = 1; i < diff; i++)
        {
            if (rowfrom - rowto < 0 && colfrom - colto < 0)
            {
                CurrSquare = board[rowfrom + i][colfrom + i];
                if (CurrSquare != NULL)
                {
                    if (board[rowto][colto]->getPos()->getRow() != -1)
                        return false;
                }
            }
            if (rowfrom - rowto > 0 && colfrom - colto > 0)
            {
                CurrSquare = board[rowfrom - i][colfrom - i];
                if (CurrSquare != NULL)
                {
                    if (board[rowto][colto]->getPos()->getRow() != -1)
                        return false;
                }
            }
            if (rowfrom - rowto < 0 && colfrom - colto > 0)
            {
                CurrSquare = board[rowfrom + i][colfrom - i];
                if (CurrSquare != NULL)
                {
                    if (board[rowto][colto]->getPos()->getRow() != -1)
                        return false;
                }
            }
            if (rowfrom - rowto > 0 && colfrom - colto < 0)
            {
                CurrSquare = board[rowfrom - i][colfrom + i];
                if (CurrSquare != NULL)
                {
                    if (board[rowto][colto]->getPos()->getRow() != -1)
                        return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}