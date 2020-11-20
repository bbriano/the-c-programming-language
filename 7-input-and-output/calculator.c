#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int main() {
    float *base = malloc(sizeof(float) * STACK_SIZE);
    float *stack = base;
    char c;
    float f;
    int ret;
    float a, b;

    while (!feof(stdin)) {
        if (scanf("%f", &f) == 1) {
            *stack++ = f;
        } else if (scanf("%c", &c) == 1) {
            b = *--stack;
            a = *--stack;
            printf("%.4f ", a);
            switch (c) {
                case '+':
                    *stack++ = a + b;
                    printf("+");
                    break;
                case '-':
                    *stack++ = a - b;
                    printf("-");
                    break;
                case '*':
                    *stack++ = a * b;
                    printf("*");
                    break;
                case '/':
                    *stack++ = a / b;
                    printf("/");
                    break;
            }
            printf(" %.4f = %.4f\n", b, *(stack-1));
        }
    }
    free(base);
}
