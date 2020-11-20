#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;
    while (*++argv) {
        fp = fopen(*argv, "r");
        if (fp == NULL) {
            fprintf(stderr, "ERROR: cannot open %s\n", *argv);
            exit(1);
        }
        while ((c = getc(fp)) != EOF)
            printf("%c", c);
        fclose(fp);
    }
}
