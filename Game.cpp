//
// Created by caspi on 11/28/2020.
//

#include "Game.h"

void fixRowDiff(Position& p)
{
    int row = p.getRow();//, rowto = to.getRow();
    switch (row) // fixes the row difference due to the print layout
    {
    case 0: row = 7; break;
    case 1: row = 6; break;
    case 2: row = 5; break;
    case 3: row = 4; break;
    case 4: row = 3; break;
    case 5: row = 2; break;
    case 6: row = 1; break;
    case 7: row = 0; break;
    }
    p.setRow(row);
}
void boardCpy(Piece* board[8][8], Piece* newBoard[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            newBoard[i][j] = board[i][j];
        }
    }
}
void endGameInnsufficientMaterial()
{
    cout << "The game is drawn due innsufficient material!" << endl;
    exit(1);
}
void endGameStalemate()
{
    cout << "The game is drawn due to stalemate!" << endl;
    exit(1);
}
void endGameCheckMate(Piece::Color winner)
{
    if (winner == Piece::Black)
        cout << "Black ";
    else
        cout << "White ";
    cout << "wins with checkmate!" << endl;
    exit(1);
}
bool inCheck(Position& kingPos, Piece* villian, Piece* whitePieces[16], Piece* blackPieces[16], Piece* board[8][8])
{
    int kingRow = kingPos.getRow(), kingCol = kingPos.getCol();
    Piece* king = board[kingRow][kingCol];
    if (king->getColor() == Piece::White)
    {
        for (int i = 0; i < 16; i++)
        {
            if (blackPieces[i]->validMove(*blackPieces[i]->getPos(), kingPos, board))
            {
                villian = blackPieces[i];
                return true;
            }
        }
    }
    else
    {
        for (int i = 0; i < 16; i++)
        {
            if (whitePieces[i]->validMove(*whitePieces[i]->getPos(), kingPos, board))
            {
                villian = whitePieces[i];
                return true;
            }
        }
    }
    return false;
}
bool checkMate(Position& kingPos, Piece* villian, Piece* whitePieces[16], Piece* blackPieces[16], Piece* board[8][8])
{
    int kingRow = kingPos.getRow(), kingCol = kingPos.getCol(), villianRow = villian->getPos()->getRow(), 
        villianCol = villian->getPos()->getCol();
    Piece* king = board[kingRow][kingCol];
    bool mate = false;
    if (king->getColor() == Piece::White)//checks if check mate
    {
        for (int i = 0; i < 16; i++)
        {
            if (whitePieces[i]->getPos()->getRow() != -1 //not dead
                && !(whitePieces[i]->validMove(*whitePieces[i]->getPos(), *villian->getPos(), board)))//can not kill the danger
            {
                mate = true;
                /*if (rowfrom > 0 && rowfrom < 7
                    && colfrom > 0 && colfrom < 7)
                {*/
            }
        }
        Piece* villian = NULL;
        Piece* tempBoard[8][8];
        boardCpy(board, tempBoard);
        if (king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol), board)) //check if the king can move
        {
            tempBoard[king->getPos()->getRow() + 1][king->getPos()->getCol()] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow() + 1, king->getPos()->getCol()));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol), board))
        {
            tempBoard[king->getPos()->getRow() - 1][king->getPos()->getCol()] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow() - 1, king->getPos()->getCol()));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow, kingCol + 1), board))
        {
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol() + 1] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow(), king->getPos()->getCol() + 1));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow, kingCol - 1), board))
        {
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol() - 1] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow(), king->getPos()->getCol() - 1));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol + 1), board))
        {
            tempBoard[king->getPos()->getRow() + 1][king->getPos()->getCol() + 1] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow() + 1, king->getPos()->getCol() + 1));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol - 1), board))
        {
            tempBoard[king->getPos()->getRow() - 1][king->getPos()->getCol() - 1] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow() - 1, king->getPos()->getCol() - 1));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol - 1), board))
        {
            tempBoard[king->getPos()->getRow() + 1][king->getPos()->getCol() - 1] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow() + 1, king->getPos()->getCol() - 1));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
        if (king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol + 1), board))
        {
            tempBoard[king->getPos()->getRow() - 1][king->getPos()->getCol() + 1] = king;
            tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
            king->setPos(new Position(king->getPos()->getRow() - 1, king->getPos()->getCol() + 1));
            if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                mate = true;
        }
/*            && !king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol), board)
            && !king->validMove(*king->getPos(), *new Position(kingRow, kingCol + 1), board)
            && !king->validMove(*king->getPos(), *new Position(kingRow, kingCol - 1), board)
            && !king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol + 1), board)
            && !king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol - 1), board)
            && !king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol - 1), board)
            && !king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol + 1), board))*///checks if king can not escape
        {
            if (villianRow - kingRow == 0
                || villianCol - kingCol == 0) //rook or queen are threatning
            {
                if (villianRow - kingRow == 0)
                {
                    int diff = villianCol - kingCol < 0 ? (villianCol - kingCol) * -1 : villianCol - kingCol;
                    if (villianCol - kingCol < 0)
                    {
                        for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                        {
                            for (int k = 0; k < 16; k++)
                            {
                                if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow, villianCol - j), board))
                                    mate = false;
                            }
                        }
                        if (mate == true)
                            endGameCheckMate(Piece::Black);
                    }
                    else
                    {
                        for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                        {
                            for (int k = 0; k < 16; k++)
                            {
                                if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow, villianCol + j), board))
                                    mate = false;
                            }
                        }
                        if (mate == true)
                            endGameCheckMate(Piece::Black);
                    }
                    if (villianCol - kingCol == 0)
                    {
                        int diff = villianRow - kingRow < 0 ? (villianRow - kingRow) * -1 : villianRow - kingRow;
                        if (villianRow - kingRow < 0)
                        {
                            for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                            {
                                for (int k = 0; k < 16; k++)
                                {
                                    if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow - j, villianCol), board))
                                        mate = false;
                                }
                            }
                            if (mate == true)
                                endGameCheckMate(Piece::Black);
                        }
                        else
                        {
                            for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                            {
                                for (int k = 0; k < 16; k++)
                                {
                                    if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow + j, villianCol), board))
                                        mate = false;
                                }
                            }
                            if (mate == true)
                                endGameCheckMate(Piece::Black);
                        }
                    }
                }
            }
            if (villianRow - kingRow == villianCol - kingCol || villianRow - kingRow == (villianCol - kingCol) * -1) //bishop or queen are threatning
            {
                int diff = villianRow - kingRow < 0 ? (villianRow - kingRow) * -1 : villianRow - kingRow;
                if (villianRow - kingRow < 0 && villianCol - kingCol < 0)
                {
                    for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow - j, villianCol - j), board))
                                mate = false;
                        }
                    }
                    if (mate == true)
                        endGameCheckMate(Piece::Black);
                }
                if (villianRow - kingRow > 0 && villianCol - kingCol > 0)
                {
                    for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow + j, villianCol + j), board))
                                mate = false;
                        }
                    }
                    if (mate == true)
                        endGameCheckMate(Piece::Black);
                }
                if (villianRow - kingRow > 0 && villianCol - kingCol < 0)
                {
                    for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow + j, villianCol - j), board))
                                mate = false;
                        }
                    }
                    if (mate == true)
                        endGameCheckMate(Piece::Black);
                }
                if (villianRow - kingRow < 0 && villianCol - kingCol > 0)
                {
                    for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if (whitePieces[k]->validMove(*whitePieces[k]->getPos(), *new Position(villianRow - j, villianCol + j), board))
                                mate = false;
                        }
                    }
                    if (mate == true)
                        endGameCheckMate(Piece::Black);
                }
            }

        }    
    }
    if (king->getColor() == Piece::Black)//checks if check mate
    {
            for (int i = 0; i < 16; i++)
            {
                if (blackPieces[i]->getPos()->getRow() != -1 //not dead
                    && !(blackPieces[i]->validMove(*blackPieces[i]->getPos(), *villian->getPos(), board)))//can not kill the danger
                {
                    mate = true;
                    /*if (rowfrom > 0 && rowfrom < 7
                        && colfrom > 0 && colfrom < 7)
                    {*/
                }
            }
            Piece* villian = NULL;
            Piece* tempBoard[8][8];
            boardCpy(board, tempBoard);
            if (king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol), board)) //check if the king can move
            {
                tempBoard[king->getPos()->getRow() + 1][king->getPos()->getCol()] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow() + 1, king->getPos()->getCol()));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol), board))
            {
                tempBoard[king->getPos()->getRow() - 1][king->getPos()->getCol()] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow() - 1, king->getPos()->getCol()));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow, kingCol + 1), board))
            {
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol() + 1] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow(), king->getPos()->getCol() + 1));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow, kingCol - 1), board))
            {
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol() - 1] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow(), king->getPos()->getCol() - 1));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol + 1), board))
            {
                tempBoard[king->getPos()->getRow() + 1][king->getPos()->getCol() + 1] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow() + 1, king->getPos()->getCol() + 1));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol - 1), board))
            {
                tempBoard[king->getPos()->getRow() - 1][king->getPos()->getCol() - 1] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow() - 1, king->getPos()->getCol() - 1));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol - 1), board))
            {
                tempBoard[king->getPos()->getRow() + 1][king->getPos()->getCol() - 1] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow() + 1, king->getPos()->getCol() - 1));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            if (king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol + 1), board))
            {
                tempBoard[king->getPos()->getRow() - 1][king->getPos()->getCol() + 1] = king;
                tempBoard[king->getPos()->getRow()][king->getPos()->getCol()] = NULL;
                king->setPos(new Position(king->getPos()->getRow() - 1, king->getPos()->getCol() + 1));
                if (inCheck(*king->getPos(), villian, whitePieces, blackPieces, tempBoard))
                    mate = true;
            }
            /*            && !king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol), board)
                        && !king->validMove(*king->getPos(), *new Position(kingRow, kingCol + 1), board)
                        && !king->validMove(*king->getPos(), *new Position(kingRow, kingCol - 1), board)
                        && !king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol + 1), board)
                        && !king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol - 1), board)
                        && !king->validMove(*king->getPos(), *new Position(kingRow + 1, kingCol - 1), board)
                        && !king->validMove(*king->getPos(), *new Position(kingRow - 1, kingCol + 1), board))*///checks if king can not escape
            {
                if (villianRow - kingRow == 0
                    || villianCol - kingCol == 0) //rook or queen are threatning
                {
                    if (villianRow - kingRow == 0)
                    {
                        int diff = villianCol - kingCol < 0 ? (villianCol - kingCol) * -1 : villianCol - kingCol;
                        if (villianCol - kingCol < 0)
                        {
                            for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                            {
                                for (int k = 0; k < 16; k++)
                                {
                                    if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow, villianCol - j), board))
                                        mate = false;
                                }
                            }
                            if (mate == true)
                                endGameCheckMate(Piece::White);
                        }
                        else
                        {
                            for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                            {
                                for (int k = 0; k < 16; k++)
                                {
                                    if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow, villianCol + j), board))
                                        mate = false;
                                }
                            }
                            if (mate == true)
                                endGameCheckMate(Piece::White);
                        }
                        if (villianCol - kingCol == 0)
                        {
                            int diff = villianRow - kingRow < 0 ? (villianRow - kingRow) * -1 : villianRow - kingRow;
                            if (villianRow - kingRow < 0)
                            {
                                for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                                {
                                    for (int k = 0; k < 16; k++)
                                    {
                                        if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow - j, villianCol), board))
                                            mate = false;
                                    }
                                }
                                if (mate == true)
                                    endGameCheckMate(Piece::White);
                            }
                            else
                            {
                                for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                                {
                                    for (int k = 0; k < 16; k++)
                                    {
                                        if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow + j, villianCol), board))
                                            mate = false;
                                    }
                                }
                                if (mate == true)
                                    endGameCheckMate(Piece::White);
                            }
                        }
                    }
                }
                if (villianRow - kingRow == villianCol - kingCol || villianRow - kingRow == (villianCol - kingCol) * -1) //bishop or queen are threatning
                {
                    int diff = villianRow - kingRow < 0 ? (villianRow - kingRow) * -1 : villianRow - kingRow;
                    if (villianRow - kingRow < 0 && villianCol - kingCol < 0)
                    {
                        for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                        {
                            for (int k = 0; k < 16; k++)
                            {
                                if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow + j, villianCol + j), board))
                                    mate = false;
                            }
                        }
                        if (mate == true)
                            endGameCheckMate(Piece::White);
                    }
                    if (villianRow - kingRow > 0 && villianCol - kingCol > 0)
                    {
                        for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                        {
                            for (int k = 0; k < 16; k++)
                            {
                                if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow - j, villianCol - j), board))
                                    mate = false;
                            }
                        }
                        if (mate == true)
                            endGameCheckMate(Piece::White);
                    }
                    if (villianRow - kingRow > 0 && villianCol - kingCol < 0)
                    {
                        for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                        {
                            for (int k = 0; k < 16; k++)
                            {
                                if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow - j, villianCol + j), board))
                                    mate = false;
                            }
                        }
                        if (mate == true)
                            endGameCheckMate(Piece::White);
                    }
                    if (villianRow - kingRow < 0 && villianCol - kingCol > 0)
                    {
                        for (int j = 1; j < diff; j++) // checks if some piece can block the route to the king
                        {
                            for (int k = 0; k < 16; k++)
                            {
                                if (blackPieces[k]->validMove(*blackPieces[k]->getPos(), *new Position(villianRow + j, villianCol - j), board))
                                    mate = false;
                            }
                        }
                        if (mate == true)
                            endGameCheckMate(Piece::White);
                    }
                }

            }
    }
    return mate;
}

void validInput(string input, int& turn)
{
    while (input[0] < 'A' || input[0] > 'H'
        || input[1] < '0' || input[1] > '8'
        || input[3] < 'A' || input[3] > 'H'
        || input[4] < '0' || input[4] > '8')
    {
        if ((input.length() == 7) && ((input[4] != '8' && input[4] != '0') || input[6] != 'R' 
            || input[6] != 'Q' || input[6] != 'B' || input[6] != 'N')) //checks if the input for the pawn was correct
        {
            cerr << turn << ") " << "Invaild input; please enter a move:" << endl;
            getline(cin, input);
            continue;
        }
        cerr << turn << ") " << "Invaild input; please enter a move:" << endl;
        getline(cin, input);
    }
}
void pieceMove(Position& from, Position& to, Piece* board[8][8], Piece* blackPieces[16],
    Piece* whitePieces[16], int &numpieces, int &turn)
{
    int rowfrom, rowto, colfrom, colto;
    colfrom = from.getCol();
    rowfrom = from.getRow();
    colto = to.getCol();
    rowto = to.getRow();
    Piece* currPiece = board[rowfrom][colfrom];
    if (currPiece->getType() == "P"
        || currPiece->getType() == "p") //check if en passant was requested
    {
        currPiece->setMovedTwice(false);
        if (rowfrom - rowto == 2 || rowfrom - rowto == -2)
            currPiece->setMovedTwice(true);
        if ((rowfrom - rowto == 1 && colfrom - colto == 1) || (rowfrom - rowto == 1 && colfrom - colto == -1)
            || (rowfrom - rowto == -1 && colfrom - colto == 1) || (rowfrom - rowto == -1 && colfrom - colto == -1))
        {
            if (board[rowto][colto] == NULL && board[rowfrom][colto]->getColor() != currPiece->getColor()
                && (board[rowfrom][colto]->getType() == "p" || board[rowfrom][colto]->getType() == "P")) //en passant
            {
                numpieces--;
                Position* dead = new Position(-1, -1);
                for (int i = 0; i < 16; i++) //updates the pieces array
                {
                    if (whitePieces[i] == board[rowfrom][colfrom])
                    {
                        whitePieces[i]->setPos(&to);
                    }
                    if (whitePieces[i] == board[rowfrom][colto])
                    {
                        whitePieces[i]->setPos(dead);
                    }
                    if (blackPieces[i] == board[rowfrom][colfrom])
                    {
                        blackPieces[i]->setPos(&to);
                    }
                    if (blackPieces[i] == board[rowfrom][colto])
                    {
                        blackPieces[i]->setPos(dead);
                    }
                }
            }
            else
            {
                numpieces--;
                Position* dead = new Position(-1, -1);
                for (int i = 0; i < 16; i++)
                {
                    if (whitePieces[i] == board[rowfrom][colfrom])
                    {
                        whitePieces[i]->setPos(&to);
                    }
                    if (blackPieces[i] == board[rowfrom][colfrom])
                    {
                        blackPieces[i]->setPos(&to);
                    }
                    if (whitePieces[i] == board[rowto][colto])
                    {
                        whitePieces[i]->setPos(dead);
                    }
                    if (blackPieces[i] == board[rowto][colto])
                    {
                        blackPieces[i]->setPos(dead);
                    }
                }
            }
        }
        for (int i = 0; i < 16; i++)
        {
            if (whitePieces[i] == board[rowfrom][colfrom])
            {
                whitePieces[i]->setPos(&to);
            }
            if (blackPieces[i] == board[rowfrom][colfrom])
            {
                blackPieces[i]->setPos(&to);
            }
        }
        currPiece->setMoved(true);
        board[rowto][colto] = currPiece;
        board[rowfrom][colfrom] = NULL;
        board[rowfrom][colto] = NULL;
        turn++;
        return;
    }
    if (currPiece->getType() == "K"
        || currPiece->getType() == "k") // check if the king is moving
    {
        if (currPiece->getColor() == Piece::White)
        {
            for (int i = 0; i < 16; i++)
            {
                 whitePieces[i]->setMyKingPos(&to);
                 blackPieces[i]->setOppKingPos(&to);
            }
        }
        else
        {
            for (int i = 0; i < 16; i++)
            {
                blackPieces[i]->setMyKingPos(&to);
                whitePieces[i]->setOppKingPos(&to);
            }
        }
        currPiece->setPos(&to);
        if ((colfrom - colto == 2 || colfrom - colto == -2)) // checks if castling was requested
        {
            currPiece->setMoved(true);
            board[rowto][colto] = currPiece; //move the king
            board[rowfrom][colfrom] = NULL;
            turn++;
            if (colfrom - colto == 2) //move the rook
            {
                Piece* rook = board[rowto][colto - 2];
                rook->setMoved(true);
                board[rowto][colto + 1] = rook;
                board[rowfrom][colto - 2] = NULL;
            }
            else
            {
                Piece* rook = board[rowto][colto + 1];
                rook->setMoved(true);
                board[rowto][colto - 1] = rook;
                board[rowfrom][colto + 1] = NULL;
            }
            return;
        }
    }
    if (board[rowto][colto] != NULL)
    {
        if (board[rowto][colto]->getColor() != currPiece->getColor()) // checks if a piece was taken
        {
            numpieces--;
            Position* dead = new Position(-1, -1);
            for (int i = 0; i < 16; i++)
            {
                if (whitePieces[i] == board[rowto][colto])
                {
                    whitePieces[i]->setPos(dead);
                    break;
                }
                if (blackPieces[i] == board[rowto][colto])
                {
                    blackPieces[i]->setPos(dead);
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 16; i++) //updates the the pieces in each colors array
        {
            if (whitePieces[i] == board[rowfrom][colfrom])
                whitePieces[i]->setPos(&to);
            if (blackPieces[i] == board[rowfrom][colfrom])
                blackPieces[i]->setPos(&to);
        }
    }
    for (int i = 0; i < 16; i++) //updates the the pieces in each colors array
    {
        if (whitePieces[i] == board[rowfrom][colfrom])
            whitePieces[i]->setPos(&to);
        if (blackPieces[i] == board[rowfrom][colfrom])
            blackPieces[i]->setPos(&to);
    }
    currPiece->setMoved(true);
    board[rowto][colto] = currPiece;
    board[rowfrom][colfrom] = NULL;
    turn++;
}

void validInputMove(string input, int& turn, int& numpieces, Piece* board[8][8], Piece* whitePieces[16],
    Piece* blackPieces[16], Game* g)
{
        int rowfrom, rowto, colfrom, colto;
        bool stalemate = false;
        colfrom = int(input[0]) - 'A';
        rowfrom = int(input[1]) - '1';
        Position* from = new Position(rowfrom, colfrom);
        colto = int(input[3]) - 'A';
        rowto = int(input[4]) - '1';
        Position* to = new Position(rowto, colto);
        fixRowDiff(*from);
        fixRowDiff(*to);
        Piece* currPiece = board[from->getRow()][from->getCol()];
        Piece* villian = currPiece;
        Piece* tempBoard[8][8];
        boardCpy(board, tempBoard);
        if (tempBoard[from->getRow()][from->getCol()]->getType() == "K"
            || tempBoard[from->getRow()][from->getCol()]->getType() == "k")
            tempBoard[from->getRow()][from->getCol()]->setMyKingPos(to);
        tempBoard[to->getRow()][to->getCol()] = tempBoard[from->getRow()][from->getCol()];
        tempBoard[from->getRow()][from->getCol()] = NULL;
        while ((currPiece == NULL)
            || !(currPiece->validMove(*from, *to, board))
            || (turn % 2 == 1 && currPiece->getColor() == Piece::Black)
            || (turn % 2 == 0 && currPiece->getColor() == Piece::White)
            || inCheck(currPiece->getMyKingPos(), villian, whitePieces, blackPieces, tempBoard) 
            || (((currPiece->getType() == "p" && to->getRow() == 0)
            || (currPiece->getType() == "P" && to->getRow() == 7)) 
                && input.length() != 7))// checks if move is valid for all it's possible parameters
        {
            if (!inCheck(currPiece->getMyKingPos(), villian, whitePieces, blackPieces, tempBoard) && stalemate)
            {
                endGameStalemate();
            }
            stalemate = true;
            cerr << turn << ") " << "Illegal move; please enter a move:" << endl;
            getline(cin, input);
            validInput(input, turn);
            colfrom = int(input[0]) - 'A';
            rowfrom = int(input[1]) - '1';
            from = new Position(rowfrom, colfrom);
            colto = int(input[3]) - 'A';
            rowto = int(input[4]) - '1';
            to = new Position(rowto, colto);
            fixRowDiff(*from);
            fixRowDiff(*to);
            currPiece = board[from->getRow()][from->getCol()];
            boardCpy(board, tempBoard);
            if (tempBoard[from->getRow()][from->getCol()]->getType() == "K"
                || tempBoard[from->getRow()][from->getCol()]->getType() == "k")
                tempBoard[from->getRow()][from->getCol()]->setMyKingPos(to);
            tempBoard[to->getRow()][to->getCol()] = tempBoard[from->getRow()][from->getCol()];
            tempBoard[from->getRow()][from->getCol()] = NULL;
        }
        if (input.length() == 7) //checks if promotion is needed
        {
            char newId = input[6];
            if (currPiece->getType() == "p" && to->getRow() == 0)
            {
                switch (newId)
                {
                case 'Q': board[to->getRow()][to->getCol()] = new Queen(Piece::White, to); break;
                case 'R': board[to->getRow()][to->getCol()] = new Rook(Piece::White, to); break;
                case 'B': board[to->getRow()][to->getCol()] = new Bishop(Piece::White, to); break;
                case 'N': board[to->getRow()][to->getCol()] = new Knight(Piece::White, to); break;
                }
                board[from->getRow()][from->getCol()] = NULL;
                turn++;
                return;
            }
            if (currPiece->getType() == "P" && to->getRow() == 7)
            {
                switch (newId)
                {
                case 'Q': board[to->getRow()][to->getCol()] = new Queen(Piece::Black, to); break;
                case 'R': board[to->getRow()][to->getCol()] = new Rook(Piece::Black, to); break;
                case 'B': board[to->getRow()][to->getCol()] = new Bishop(Piece::Black, to); break;
                case 'N': board[to->getRow()][to->getCol()] = new Knight(Piece::Black, to); break;
                }
                board[from->getRow()][from->getCol()] = NULL;
                turn++;
                return;
            }
        }
        pieceMove(*from, *to, board, blackPieces, whitePieces, numpieces, turn);
        if (inCheck(currPiece->getOppKingPos(), villian, whitePieces, blackPieces, board))
        {
            if (checkMate(currPiece->getOppKingPos(), villian, whitePieces, blackPieces, board))
            {
                delete from;
                delete to;
                for (int i = 0; i < 16; i++)
                {
                    delete whitePieces[i];
                    delete blackPieces[i];
                }
                endGameCheckMate(currPiece->getColor());
            }
        }
}

void printBoard(Piece* board[8][8])
{
    for (int i = 0, k = 8; i < 8; i++, k--)
    {
        cout << k << " ";
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != NULL)
            {
                cout << board[i][j]->getType() << " ";
            }
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << "  A B C D E F G H" << endl;
}

void Game::resetBoard(Piece** whitePieces, Piece** blackPieces, Piece* board[8][8]) 
{
    board[0][0] = new Rook(Piece::Black, new Position(0, 0));
    blackPieces[0] = board[0][0];
    board[0][1] = new Knight(Piece::Black, new Position(0, 1));
    blackPieces[1] = board[0][1];
    board[0][2] = new Bishop(Piece::Black, new Position(0, 2));
    blackPieces[2] = board[0][2];
    board[0][3] = new Queen(Piece::Black, new Position(0, 3));
    blackPieces[3] = board[0][3];
    board[0][4] = new King(Piece::Black, new Position(0, 4));
    blackPieces[4] = board[0][4];
    board[0][5] = new Bishop(Piece::Black, new Position(0, 5));
    blackPieces[5] = board[0][5];
    board[0][6] = new Knight(Piece::Black, new Position(0, 6));
    blackPieces[6] = board[0][6];
    board[0][7] = new Rook(Piece::Black, new Position(0, 7));
    blackPieces[7] = board[0][7];

    board[7][0] = new Rook(Piece::White, new Position(7, 0));
    whitePieces[0] = board[7][0];
    board[7][1] = new Knight(Piece::White, new Position(7, 1));
    whitePieces[1] = board[7][1];
    board[7][2] = new Bishop(Piece::White, new Position(7, 2));
    whitePieces[2] = board[7][2];
    board[7][3] = new Queen(Piece::White, new Position(7, 3));
    whitePieces[3] = board[7][3];
    board[7][4] = new King(Piece::White, new Position(7, 4));
    whitePieces[4] = board[7][4];
    board[7][5] = new Bishop(Piece::White, new Position(7, 5));
    whitePieces[5] = board[7][5];
    board[7][6] = new Knight(Piece::White, new Position(7, 6));
    whitePieces[6] = board[7][6];
    board[7][7] = new Rook(Piece::White, new Position(7, 7));
    whitePieces[7] = board[7][7];

    for (int i = 0, j = 8; i < 8; i++, j++)
    {
        board[1][i] = new Pawn(Piece::Black, new Position(1, i));
        blackPieces[j] = board[1][i];
        board[6][i] = new Pawn(Piece::White, new Position(6, i));
        whitePieces[j] = board[6][i];
    }
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = NULL;
        }
    }
    numpieces = 32;
}
Game& Game::operator++()
{
    numpieces++;
    return *this;
}
const Game* Game::operator++(int)
{
    Game* temp = this;
    this->numpieces++;
    return temp;
}
Game& Game::operator--()
{
    numpieces--;
    return *this;
}
const Game* Game::operator--(int)
{
    Game* temp = this;
    this->numpieces--;
    return temp;
}
Game::Game(Piece* board[8][8]) 
{
 //   Piece* board[8][8];
 //   Game* g = new Game();
    int turn;
    int rowfrom, rowto, colfrom, colto;
    turn = 1;
    string input;
    Piece* whitePieces[16];
    Piece* blackPieces[16];
    resetBoard(whitePieces, blackPieces, board);
    printBoard(board);
    while (true)
    {
        cout << turn << ") "; 
        if (turn % 2 == 1)
            cout << "White's ";
        else
            cout << "Black's ";
        cout << "turn, please enter a move:" << endl;
        getline(cin, input);
        validInput(input, turn);
        validInputMove(input, turn, numpieces, board, whitePieces, blackPieces, this);
        printBoard(board);
        if (numpieces == 2 || numpieces == 4) // insufficient material check
        {
            int king = 0, bishop = 0, knight = 0;
            for (int i = 0; i < 16; i++)
            {
                if (whitePieces[i]->getType() == "k")
                {
                    king++;
                }
                if (blackPieces[i]->getType() == "K")
                {
                    king++;
                }
                if (whitePieces[i]->getType() == "b")
                {
                    bishop++;
                }
                if (blackPieces[i]->getType() == "B")
                {
                    bishop++;
                }
                if (whitePieces[i]->getType() == "n")
                {
                    knight++;
                }
                if (blackPieces[i]->getType() == "N")
                {
                    knight++;
                }
                if (numpieces == 2 && king == 2)
                    endGameInnsufficientMaterial();
                if(numpieces == 4 && king == 2 && bishop == 2)
                    endGameInnsufficientMaterial();
                if (numpieces == 4 && king == 2 && knight == 2)
                    endGameInnsufficientMaterial();
            }
        }
    }
}