#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

// Function to print the Tic-Tac-Toe board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; // Player won
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1; // Player won
    }

    return 0; // No winner yet
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Function to make a move for the player
void playerMove(char player) {
    int cell;
    printf("Enter your move (1-9): ");
    scanf("%d", &cell);

    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move. Try again.\n");
        playerMove(player);
    } else {
        board[row][col] = player;
    }
}

// Function to make a move for the computer
void computerMove(char player) {
    int row, col;
    srand(time(NULL));

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] == 'X' || board[row][col] == 'O');

    printf("Computer's move: %d\n", (row * 3) + col + 1);
    board[row][col] = player;
}

int main() {
    char player = 'X';
    int gameOver = 0;

    printf("Tic-Tac-Toe Game\n");

    do {
        printBoard();

        if (player == 'X') {
            playerMove(player);
        } else {
            computerMove(player);
        }

        if (checkWin(player)) {
            printBoard();
            printf("Player %c wins!\n", player);
            gameOver = 1;
        } else if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        }

        player = (player == 'X') ? 'O' : 'X';

    } while (!gameOver);

    return 0;
}
