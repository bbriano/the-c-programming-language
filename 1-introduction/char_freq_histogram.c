#include <stdio.h>

int main() {
    char c;
    int charfreq['z'-'a'];

    for (int i = 0; i <= 'z'-'a'; i++)
        charfreq[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z')
            ++charfreq[c-'a'];
    }

    for (int i = 0; i <= 'z'-'a'; i++) {
        printf("%c ", i+'a');
        for (int j = 0; j < charfreq[i]; j++)
            printf("#");
        printf("\n");
    }
}
