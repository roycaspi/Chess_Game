//
// Created by caspi on 11/28/2020.
//

#ifndef CHESSEX_GAME_H
#define CHESSEX_GAME_H
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include <string>
#include <cstdlib>

using namespace std;

class Game {
public:
    Game(Piece* board[8][8]);
    int getNumPieces() const { return numpieces; }
    void resetBoard(Piece** whitePieces, Piece** blackPieces, Piece* board[8][8]);
    Game& operator ++ ();
    const Game* operator ++ (int);
    Game& operator -- ();
    const Game* operator -- (int);
    
private:
    int numpieces;

};


#endif //CHESSEX_GAME_H
