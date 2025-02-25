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
