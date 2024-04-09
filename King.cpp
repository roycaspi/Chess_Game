#include "King.h"

bool King::validMove(const Position& from, const Position& to, Piece* board[8][8]) const
{
    int rowto = to.getRow(), colto = to.getCol(), rowfrom = from.getRow(), colfrom = from.getCol();
    Piece* rook;
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
    if ((colfrom - colto == 2 || colfrom - colto == -2) && !didMove()) //check if castling is possible
    {
        if (colfrom - colto == 2)
        {
            rook = board[rowto][colto - 2];
            if ((rook->getColor() == White && rook->getType() != "r")
                || (rook->getColor() == Black && rook->getType() != "R")) //checks if the piece isn't the rook
                return false;
            if (rook == NULL || rook->didMove())
                return false;
            for (int i = 1; i < 4; i++)
            {
                if (board[rowfrom][colfrom - i] != NULL) // the way isn't clear
                {
                    if (board[rowto][colto]->getPos()->getRow() != 1)
                        return false;
                }
            }
            return true;
        }
        else
        {
            rook = board[rowto][colto + 1];
            if ((rook->getColor() == White && rook->getType() != "r")
                || (rook->getColor() == Black && rook->getType() != "R")) //checks if the piece isn't the rook
                return false;
            if (rook == NULL || rook->didMove() )
                return false;
            for (int i = 1; i < 3; i++)
            {
                if (board[rowfrom][colfrom + i] != NULL) // the way isn't clear
                {
                    if(board[rowto][colto]->getPos()->getRow() != 1)
                        return false;
                }
            }
            return true;
        }
    }
    if (rowfrom - rowto > 1 || rowfrom - rowto < -1 || colfrom - colto > 1 || colfrom - colto < -1)//check if the king made more than a step
        return false;
    return true;
}
