#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char c;
    int x, y, z;
    x = y = z = 0;

    while (--argc > 0 && **++argv == '-') {
        while ((c = *++*argv)) {
            switch (c) {
                case 'x':
                    x = 1;
                    break;
                case 'y':
                    y = 1;
                    break;
                case 'z':
                    z = 1;
                    break;
                default:
                    printf("unknown option: %c\n", c);
                    exit(1);
            }
        }
    }

    if (argc != 1) {
        printf("Usage argc -x -y -z word\n");
        exit(1);
    }

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("%s\n", *argv);
}
