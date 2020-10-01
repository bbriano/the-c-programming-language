#include <stdio.h>

int str_len(char *);

int main() {
    int len;
    char *str;
    /* scanf("%s", str); */
    /* fgets(str, 99, stdin); */
    str = "hello, world";
    len = str_len(str);
    /* printf("len(%s) = %d\n", str, len); */
    printf("%s\n", str);
    printf("%d\n", len);
}

int str_len(char *str) {
    int i;
    for (i = 0; *(str+i) != '\0'; i++);
    return i;
}
