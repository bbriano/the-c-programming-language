#include <stdio.h>
#define MAX_LINE 9

void dellast(char *s);

int main() {
    dellast("hello");
    /* char *line; */
    /* while (fgets(line, MAX_LINE, stdin)) */
    /*     printf("%s", dellast(line)); */
}

void dellast(char *s) {
    if (*s == '\0')
        return;
    for (; *s != '\0'; s++)
        printf("%s\n", s);
    *(s-1) = '\0';
}
