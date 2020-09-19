#include <stdio.h>


int main() {
    printf("type\tbyte\n");
    printf("char\t%lu\n", sizeof(char));
    printf("short\t%lu\n", sizeof(short));
    printf("int\t%lu\n", sizeof(int));
    printf("long\t%lu\n", sizeof(long));
    printf("float\t%lu\n", sizeof(float));
    printf("double\t%lu\n", sizeof(double));
}
