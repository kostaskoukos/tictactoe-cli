# Tic Tac Toe CLI

A simple command-line Tic Tac Toe game written in C++ to learn game theory techniques and algorithms such as minMax, negaMax, alpha-beta pruning, etc.

## How to Run Locally

1. **Clone the repository** (if you haven't already):

```sh
git clone https://github.com/kostaskoukos/tictactoe-cli
cd tictactoe-cli
```

1. **Compile the program**:

```sh
g++ -o tictactoe main.cpp
```

1. **Run the game**:

```sh
./tictactoe
```

## How to Play

- Choose between PvP and PvC.
- The usual Tic Tac Toe rules apply, with X playing first.
- To play a move, type the corresponding square's number (1-9).

## How the Project Works

- The board is implemented as a char array of size 9, `std:array<char, 9>`.
- The `calculateResult()` function controls the loop and game state.
- The computer move is calculated through the [negaMax](https://en.wikipedia.org/wiki/Megamax) algorithm with alpha-beta pruning.
