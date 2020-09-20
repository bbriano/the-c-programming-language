#include <stdio.h>
#define MAXCHAR 100000 /* Maximum character count per line */

int get_line(char string[]);
void reverse(char r[], char s[], int len);
int main() {
    char c;
    int len;
    char line[MAXCHAR]; /* current line */
    char line_rev[MAXCHAR]; /* line reversed */

    while ((len = get_line(line)) >= 0) {
        reverse(line_rev, line, len);
        printf("%s\n", line_rev);
    }
}

/* getline: read a line into s, return length */
int get_line(char s[]) {
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            s[i] = c;
            ++i;
        } else {
            s[i] = '\0';
            return i;
        }
    }
    return -1;
}

/* reverse: put the reverse of s into r */
void reverse(char r[], char s[], int len) {
    int i;
    for (i = 0; i < len; ++i)
        r[i] = s[len-1-i];
    r[len] = '\0';
}
