#include <stdio.h>

int main() {
    char c;
    /* do { */
    /*     c = getchar(); */
    /*     putchar(c); */
    /* } while (c != EOF); */

    while ((c = getchar()) != EOF)
        putchar(c);
}
