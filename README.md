# Chess Game

## Overview
A **C++ console-based Chess Game** implementing standard chess rules. The game ensures move validation, turn-based play, and checks for special chess rules such as castling and en passant.

## Features
- Implements **all standard chess rules**.
- Ensures **legal move validation**.
- Alternates turns between players.
- Displays **text-based chessboard**.
- Detects **checkmate and stalemate conditions**.

## Installation
```bash
git clone https://github.com/roycaspi/Chess_Game.git
cd Chess_Game
```

## Compilation
```bash
g++ -o chess_game main.cpp Game.cpp Position.cpp Piece.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp
```

## Usage
```bash
./chess_game
```

## Example Gameplay
```
Initial Board:
  a b c d e f g h
8 r n b q k b n r
7 p p p p p p p p
6 . . . . . . . .
5 . . . . . . . .
4 . . . . . . . .
3 . . . . . . . .
2 P P P P P P P P
1 R N B Q K B N R

Enter move (e.g., e2 e4):
e2 e4

Updated Board:
...
```
