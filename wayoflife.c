#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(int argc, char **argv) {
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    int w = win.ws_col;
    int h = win.ws_row;
    int board[h][w];
    int nbors[h][w];

    for (int row = 0; row < h; row++)
        for (int col = 0; col < w; col++)
            board[row][col] = rand() % 2 == 0;

    while (1) {
        // Neightbour counts
        for (int row = 0; row < h; row++)
            for (int col = 0; col < w; col++) {
                int live_count = 0;
                for (int i = -1; i <= 1; i++)
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0) continue;
                        if (row+i < 0 || row+i >= h) continue;
                        if (col+j < 0 || col+j >= w) continue;
                        live_count += board[row+i][col+j];
                    }
                nbors[row][col] = live_count;
            }

        // Draw
        system("clear");
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++)
                printf("%c", board[row][col] ? 'X' : ' ');
            printf("\n");
        }

        // Calculate next board
        for (int row = 0; row < h; row++)
            for (int col = 0; col < w; col++)
                if (board[row][col]) {
                    if (nbors[row][col] < 2 || nbors[row][col] > 3)
                        board[row][col] = 0;
                } else if (nbors[row][col] == 3)
                    board[row][col] = 1;

        usleep(500000);  // Pause execution micro seconds
    }
}
