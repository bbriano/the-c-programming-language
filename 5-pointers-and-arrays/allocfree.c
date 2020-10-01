#include <stdio.h>
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free storage */

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp < n) /* it doesn't fit */
        return NULL;
    allocp += n;
    return allocp - n; /* old pointer */
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) /* p is in buffer */
        allocp = p;
}

int main() {
    int n = 'z' - 'a' + 1;
    char *a = alloc(n + 1);
    for (int i = 0; 'a' + i <= 'z'; i++)
        *(a + i) = 'a' + i;
    *(a + n + 1) = '\0';
    printf("%s\n", a);
    afree(a);
}
