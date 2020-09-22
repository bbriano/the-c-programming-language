#include <stdio.h>
#define MAXSTRLEN 9000

int get_line(char s[], int lim);

int main() {
    int n;
    char line[MAXSTRLEN + 1];
    n = get_line(line, MAXSTRLEN);
    while (n > 0)
        printf("%c", line[--n]);
    printf("\n");
}

int get_line(char s[], int lim) {
    int i;
    char c;
    i = 0;
    while ((i < lim) && ((c = getchar()) != EOF)) {
        if (c != '\n') {
            s[i++] = c;
        } else {
            s[i] = '\0';
            return i;
        }
    }
    s[i] = '\0';
    return -1;
}
