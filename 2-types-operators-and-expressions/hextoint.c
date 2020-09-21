#include <stdio.h>
#define MAXLENGTH 9999

int htoi(char[]);

int main() {
    char input[MAXLENGTH];
    scanf("%s", input);
    printf("%d\n", htoi(input));
}

int htoi(char s[]) {
    char c;
    int i;
    int res = 0;

    for (i = 0; (c = s[i]) != '\0'; ++i) {
        res *= 16;
        if (c >= '0' && c <= '9') {
            res += c - '0';
        } else if (c >= 'A' && c <= 'F') {
            res += c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            res += c - 'a' + 10;
        }
    }

    return res;
}
