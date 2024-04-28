#include <iostream>

const int SIZE = 3; // Board size (3x3)

char board[SIZE][SIZE];

void initializeBoard() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      board[i][j] = ' ';
    }
  }
}

// Implement the functions mentioned above (drawBoard, getPlayerMove, etc.)

int main() {
  initializeBoard();

  char currentPlayer = 'X'; // Player starts

  while (true) {
    drawBoard();

    // Get player move and update board
    int row, col;
    getPlayerMove(row, col);
    if (!isMoveValid(row, col)) {
      std::cout << "Invalid move. Try again." << std::endl;
      continue;
    }
    board[row][col] = currentPlayer;

    // Check for winner or draw
    if (checkWin()) {
      drawBoard();
      std::cout << currentPlayer << " wins!" << std::endl;
      break;
    } else if (isBoardFull()) {
      drawBoard();
      std::cout << "It's a draw!" << std::endl;
      break;
    }

    // Make computer move (simple AI or random)

    // Switch player turn
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  return 0;
}