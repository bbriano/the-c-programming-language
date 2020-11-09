#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 10;  // Number of lines to print

    if (argc < 0 || argc > 2) {
        printf("usage: tail -100\n");
    }

    if (argc == 2) {
        n = atoi(++argv[1]);
    }

    printf("%d\n", n);
}
