#include <stdio.h>

void astrcopy(char s[], char t[]) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void pstrcopy(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void prostrcopy(char *s, char *t) {
    while ((*s++ = *t++));
}

int main() {
    char stra[999];
    char strb[999];
    char strc[999];

    astrcopy(stra, "hello, world");
    pstrcopy(strb, stra);
    prostrcopy(strc, strb);

    printf("stra: %s\n", stra);
    printf("strb: %s\n", strb);
    printf("strc: %s\n", strc);
}

