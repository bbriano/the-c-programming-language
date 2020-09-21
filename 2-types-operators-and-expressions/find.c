#include <stdio.h>
#define MAXCHARS 9999

int find(char[], char[]);
int get_line(char s[], int lim);

int main() {
    char sentence[MAXCHARS + 1]; /* sentence to be searched */
    char word[MAXCHARS + 1]; /* search key word */
    get_line(sentence, MAXCHARS);
    get_line(word, MAXCHARS);
    printf("%d\n", find(sentence, word));
}

/* copy a line from standard input, returns 0 if and only if EOF */
int get_line(char s[], int max) {
    int i;
    char c;
    for (i = 0; i < max && (c = getchar()) != EOF; i++) {
        if (c == '\n') {
            s[i] = '\0';
            return 1;
        }
        s[i] = c;
    }
    s[i] = '\0';
    return 0;
}

/* returns the index of the first occurence of w in s, returns -1 if w is not a substring of s */
int find(char s[], char w[]) {
    int i, j;
    int found;
    for (i = 0; s[i] != '\0'; i++) {
        found = 1;
        for (j = 0; w[j] != '\0'; j++) {
            if (s[i+j] != w[j]) {
                found = 0;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}
