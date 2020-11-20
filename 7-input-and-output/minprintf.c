#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);
int sum(int x, ...);

int main() {
    minprintf("the sum is %d\n", sum(3, 5, 2, 7));
}

void minprintf(char *fmt, ...) {
    va_list ap;
    char c;
    int ival;
    double dval;
    char *sval;
    va_start(ap, fmt);
    for (; *fmt; fmt++) {
        if (*fmt != '%') {
            putchar(*fmt);
            continue;
        }
        switch (*++fmt) {
            case 'i':
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf("%s", sval);
                break;
            default:
                putchar(*fmt);
        }
    }
    va_end(ap);
}

int sum(int x, ...) {
    va_list ap;
    int res = x;
    int val;
    va_start(ap, x);
    while ((val = va_arg(ap, int)))
        res += val;
    va_end(ap);
    return res;
}
