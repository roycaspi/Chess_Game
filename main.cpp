#include <iostream>
#include<string>
#include "Game.h"
using namespace std;



int main()
{
    Piece* board[8][8];
    new Game(board);
    return 0;
}
