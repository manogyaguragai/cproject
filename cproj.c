
#include <stdio.h>

char board[3][3]; // 2D array initialization

// Function to initialize the new game board with spaces
void new_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void board_printer() // Function to print the game board
{  
  printf("\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

int winner_checker(char player) // Function to check if a player has won
{ 
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }
  return 0;
}

void play_game() // Function to play the game
{
  int row, col;
  char player = 'X';
  int count = 0;
  new_board();
  while (1) {
    printf("Player %c's turn:\n", player);
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);
    if (row < 1 || row > 3 || col < 1 || col > 3) {
      printf("Invalid input. Try again.\n");
      continue;
    }
    if (board[row-1][col-1] != ' ') {
      printf("That space is already occupied. Try again.\n");
      continue;
    }
    board[row-1][col-1] = player;
    board_printer();
    if (winner_checker(player)) {
      printf("Player %c wins!\n", player);
      break;
    }
    count++;
    if (count == 9) {
      printf("It's a tie!\n");
      break;
    }
    player = (player == 'X') ? 'O' : 'X';
  }
}

int main() // Main function to start the program
{
  play_game();
  return 0;
}