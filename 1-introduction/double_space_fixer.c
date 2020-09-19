#include <stdio.h>

int main() {
    char now, prev;

    while ((now = getchar()) != EOF) {
        if (prev != ' ' || now != ' ') {
            putchar(now);
        }
        prev = now;
    }
}
