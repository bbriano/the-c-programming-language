#include <stdio.h>

int main() {
    char c;
    long nls;

    for (nls = 0; (c = getchar()) != EOF;) {
        if (c == '\n') {
            ++nls;
        }
    }

    printf("%ld\n", nls);
}
