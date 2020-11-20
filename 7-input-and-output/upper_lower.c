#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c;
    int upper;
    while (*++argv && **argv == '-')
        while (*++*argv)
            switch (**argv) {
                case 'u':
                    upper = 1;
                    break;
                default:
                    printf("invalid option: %c\n", **argv);
            }

    while ((c = getchar()) != EOF)
        if (upper)
            putchar(toupper(c));
        else
            putchar(tolower(c));
}
