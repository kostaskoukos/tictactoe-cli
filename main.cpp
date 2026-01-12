#include <array>
#include <iostream>

void printBoard(const std::array<char, 9> &board) {
  for (size_t i = 0; i < 9; ++i) {
    std::cout << board[i];

    if (i == 8)
      std::cout << "\n";
    else if ((i + 1) % 3 == 0)
      std::cout << "\n---------\n";
    else
      std::cout << " | ";
  }
}

int main(int argc, char *argv[]) {
  std::array<char, 9> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  printBoard(board);
  return 0;
}
