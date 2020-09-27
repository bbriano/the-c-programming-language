#include <stdio.h>

void printd(int n);

int main() {
    printd(1234);
    putchar('\n');
    printd(-99);
    putchar('\n');
}

// Prints n in decimal
void printd(int n) {
    if (n < 0) putchar('-');
    n = n < 0 ? -n : n;
    if (n / 10) printd(n / 10);
    putchar(n % 10 + '0');
}
