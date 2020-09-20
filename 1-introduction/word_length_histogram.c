#include <stdio.h>
#define OUT 0 /* Outside a word */
#define IN  1 /* Inside a word */
#define MAXWORDLEN 20

int main() {
    int i, j, c, state, ccount;
    char wordlen[MAXWORDLEN];
    for (i = 0; i < MAXWORDLEN; ++i) {
        wordlen[i] = 0;
    }

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                ++wordlen[ccount];
            }
            state = OUT;
        } else {
            if (state == OUT) {
                state = IN;
                ccount = 0;
            } else {
                ++ccount;
            }
        }
    }

    for (i = 0; i < MAXWORDLEN; ++i) {
        printf("%3d ", i + 1);
        for (j = 0; j < wordlen[i]; ++j) {
            printf("X");
        }
        printf("\n");
    }
}
