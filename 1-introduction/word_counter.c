#include <stdio.h>

#define IN  1 // Inside a word
#define OUT 0 // Outsize a word

int main() {
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            ++nw;
            state = IN;
        }

        if (c == '\n') {
            ++nl;
        }

        ++nc;
    }

    printf("nl: %d\tnw: %d\tnc: %d\n", nl, nw, nc);
}
