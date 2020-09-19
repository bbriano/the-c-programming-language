#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20


int main() {
    printf("fahr\tcel\n");

    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        float cel = (fahr - 32) * (5 / 9.);
        printf("%4d\t%6.2f\n", fahr, cel);
    }
}
