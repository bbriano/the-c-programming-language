#include <stdio.h>

#define BASE 2  // The base to be exponentiated
#define N 40    // How many powers to print

int power(int, int);

int main() {
    int exponent;

    printf("Base\tPower\n");
    for (exponent = 0; exponent < N; ++exponent)
        printf("%d^%d\t%d\n", BASE, exponent, power(BASE, exponent));
}

int power(int base, int exponent) {
    int i, result;

    result = 1;
    for (i = 0; i < exponent; ++i)
        result *= base;
    return result;
}
