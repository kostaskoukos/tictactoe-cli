# Tic Tac Toe CLI

A simple command-line Tic Tac Toe game written in C++.

## How to Run Locally

1. **Clone the repository** (if you haven't already):

```sh
git clone https://github.com/kostaskoukos/tictactoe-cli
cd tictactoe-cli
```

2. **Compile the program**:

```sh
g++ -o tictactoe main.cpp
```

3. **Run the game**:

```sh
./tictactoe
```

## How to Play

- The game is played on a 3x3 grid.
- Players take turns entering the row and column numbers (e.g., `1 2`) to place their mark (X or O).
- The first player to get three of their marks in a row (vertically, horizontally, or diagonally) wins.
- If all cells are filled and no player has won, the game ends in a draw.

## How the Project Works

- The game logic, board display, and user input handling are implemented in `main.cpp`.
- The program alternates turns between two players, checks for a win or draw after each move, and displays the board state after every turn.
- The computer move is calculated through the [negaMax](https://en.wikipedia.org/wiki/Megamax) algorithm.
