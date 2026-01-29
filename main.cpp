#include <array>
#include <iostream>

enum Result { ONGOING, X_WINS, O_WINS, DRAW };
enum Mode { PvP = 1, PvC = 2 };

void printBoard(const std::array<char, 9> &board) {
  std::cout << "\033[2J\033[1;1H";
  for (size_t i = 0; i < 9; ++i) {
    std::cout << board[i];

    if (i == 8)
      std::cout << "\n";
    else if ((i + 1) % 3 == 0)
      std::cout << "\n---------\n";
    else
      std::cout << " | ";
  }
  std::cout << "\n";
}

Result calculateResult(const std::array<char, 9> &board) {
  const int winPatterns[8][3] = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
      {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
      {0, 4, 8}, {2, 4, 6}             // Diagonals
  };

  for (const auto &pattern : winPatterns) {
    if (board[pattern[0]] == board[pattern[1]] &&
        board[pattern[1]] == board[pattern[2]]) {
      if (board[pattern[0]] == 'X')
        return X_WINS;
      else if (board[pattern[0]] == 'O')
        return O_WINS;
    }
  }
  for (const char &cell : board) {
    if (cell != 'X' && cell != 'O')
      return ONGOING;
  }
  return DRAW;
}
int getPlayerMove(const std::array<char, 9> &board, char turn) {
  int move = 0;
  std::cout << "Enter your move (1-9):";
  for (std::cin >> move;
       move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O';
       std::cin >> move) {
    std::cout << "Invalid move. Enter a new move (1-9):";
  }
  return move;
}

int negaMax(std::array<char, 9> &board, int color, int &move,
            bool isRoot = false) {
  Result res = calculateResult(board);
  if (res == DRAW)
    return 0;
  else if (res != ONGOING)
    return -1;

  int maxScore = -100;
  for (int i = 0; i < 9; ++i) {
    if (board[i] == 'X' || board[i] == 'O')
      continue;

    board[i] = (color == 1 ? 'X' : 'O'); // X = 1, O = -1
    int score = -negaMax(board, -color, move);
    board[i] = '1' + i; // Undo move
    if (score > maxScore) {
      maxScore = score;
      if (isRoot)
        move = i;
    }
  }
  return maxScore;
}

int calculateComputerMove(std::array<char, 9> &board, char turn) {
  int move;
  negaMax(board, turn == 'X' ? 1 : -1, move, true);
  return move + 1;
}

int main(int argc, char *argv[]) {
  std::cout << "Welcome to Tic-Tac-Toe!\n";

  std::cout << "Choose PvP (1) or PvC (2): ";
  int choice;
  for (std::cin >> choice; choice != PvP && choice != PvC; std::cin >> choice)
    std::cout << "Invalid choice. Choose PvP (1) or PvC (2): ";
  Mode mode = static_cast<Mode>(choice);

  std::array<char, 9> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char turn = 'X';
  int move = 0;
  Result res = ONGOING;

  if (mode == PvP) {
    while (res == ONGOING) {
      printBoard(board);

      std::cout << turn << "'s turn.\n";
      move = getPlayerMove(board, turn);

      board[move - 1] = turn;
      turn = (turn == 'X') ? 'O' : 'X';
      res = calculateResult(board);
    }
  } else {
    srand(time(NULL));
    bool computerPlays = mode == PvC && rand() % 2 == 0;
    while (res == ONGOING) {
      if (computerPlays) {
        move = calculateComputerMove(board, turn);
        computerPlays = false;
      } else {
        printBoard(board);

        if (move != 0)
          std::cout << "Computer played " << move << "\n";

        std::cout << turn << "'s turn.\n";
        move = getPlayerMove(board, turn);
        computerPlays = true;
      }
      board[move - 1] = turn;
      turn = (turn == 'X') ? 'O' : 'X';
      res = calculateResult(board);
    }
  }

  printBoard(board);
  if (res == X_WINS) {
    std::cout << "X wins!\n";
  } else if (res == O_WINS) {
    std::cout << "O wins!\n";
  } else {
    std::cout << "It's a draw!\n";
  }
  return 0;
}
