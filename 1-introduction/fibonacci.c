#include <stdio.h>

int main() {
    int prev = 1;
    int now = 0;
    while (now <= 1000000000) {
        printf("%d\n", now);
        int temp = prev;
        prev = now;
        now += temp;
    }
}
