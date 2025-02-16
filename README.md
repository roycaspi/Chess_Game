Chess Game
Overview
The Chess Game project is a C++ implementation of the classic chess game. It provides a console-based interface where two players can engage in a standard game of chess, adhering to traditional rules and mechanics.

Features
Full Chess Mechanics: Implements all standard chess rules, including castling, en passant, and pawn promotion.
Object-Oriented Design: Utilizes classes for different pieces (King, Queen, Bishop, Knight, Rook, Pawn) and game management (Game, Position).
Move Validation: Ensures all moves are legal, preventing invalid piece movements.
Turn-Based Play: Alternates turns between two players, enforcing correct move sequences.
Console Interface: Provides a text-based interface for game interaction.
Installation
To set up the project locally:

Clone the repository:

bash
Copy
Edit
git clone https://github.com/roycaspi/Chess_Game.git
cd Chess_Game
Ensure you have a C++ compiler installed (GCC recommended).

Compilation
Compile the program using:

bash
Copy
Edit
g++ -o chess_game main.cpp Game.cpp Position.cpp Piece.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp
Usage
Run the executable:

bash
Copy
Edit
./chess_game
Gameplay Instructions
Starting the Game: Upon running the executable, the chessboard will be displayed with the initial setup.
Making Moves: Players are prompted to enter moves in standard algebraic notation (e.g., e2 e4 to move a piece from e2 to e4).
Turn Order: The game enforces alternating turns between White and Black.
Game End: The game detects checkmate and stalemate conditions, announcing the result accordingly.
Code Structure
The project follows an object-oriented design with the following key components:

Piece Hierarchy: An abstract Piece class serves as the base for all specific piece types (King, Queen, Bishop, Knight, Rook, Pawn), each implementing movement logic.
Game Management: The Game class oversees the overall game state, turn management, and move validation.
Board Representation: The Position class handles the chessboard layout and piece positioning.
Contributions
Contributions are welcome! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -m 'Add new feature').
Push to the branch (git push origin feature-branch).
Open a pull request.
