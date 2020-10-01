#include <stdio.h>

int astrcmp(char s[], char t[]) {
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int pstrcmp(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int main() {
    char world[999] = "hellob";
    char briano[999] = "helloc";
    printf("%d\n", astrcmp(world, briano));
    printf("%d\n", pstrcmp(world, briano));
}

