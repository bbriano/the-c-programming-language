#include <stdio.h>

void printBoard(char board[8][8]) {
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; i++) {
        printf("|");
        for (int j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
}

int main() {
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    printBoard(board);
}

