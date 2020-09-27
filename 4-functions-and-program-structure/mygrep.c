#include <stdio.h>
#include <string.h>
#define MAXSTRLEN 9999

int get_line(char[], int);
int strequal(char[], char[], int);
int strsubstr(char[], char[]);

int main() {
    char line[MAXSTRLEN + 1];
    char keyword[MAXSTRLEN + 1];
    int strlen;

    get_line(keyword, MAXSTRLEN);
    while ((strlen = get_line(line, MAXSTRLEN)) != -1) {
        if (strsubstr(line, keyword)) {
            printf("%s\n", line);
        }
    }
}

/* read characters from standard in until line store characters in s */
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

/* returns 1 if t is a substring of s, else return 0 */
int strsubstr(char str[], char sub[]) {
    int str_len = strlen(str);
    int sub_len = strlen(sub);
    for (int i = 0; (i + sub_len) < str_len; i++)
        if (strequal(str+i, sub, sub_len)) return 1;
    return 0;
}

/* returns 1 if the first n char in s and c are equal, else return 0 */
int strequal(char s[], char t[], int n) {
    char c;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i]) return 0;
    return 1;
}
