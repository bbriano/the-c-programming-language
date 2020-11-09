#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 9000
#define MAX_LINES 9000

void qqsort(void *v[], int left, int right, int (*comp)(void *, void *));

int main(int argc, char *argv[]) {
    int numerical = 0;
    char *lineptr[MAX_LINES];
    size_t bufsize = MAX_LINE;
    char c;
    int nlines = 0;
    int linelen;

    // Parse options
    while (--argc > 0 && **++argv == '-')
        while ((c = *++*argv))
            switch (c) {
                case 'n':
                    numerical = 1;
                    break;
                default:
                    printf("no option: %c\n", c);
                    exit(1);
            }

    // Read from cin
    while ((linelen = getline(&lineptr[nlines], &bufsize, stdin)) != EOF)
        lineptr[nlines++][linelen-1] = '\0';

    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}


void qqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
}
