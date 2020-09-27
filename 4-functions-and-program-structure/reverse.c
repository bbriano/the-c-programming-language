#include <stdio.h>

int get_line(char s[], int maxchar);
void reverse(char s[], int left, int right);
void swap(char s[], int i, int j);

int main() {
    char str[1000];
    int n;
    while ((n = get_line(str, 999)) != -1) {
        reverse(str, 0, n);
        printf("%s\n", str);
    }
}

// Read characters from standard in and put it in s
// Returns the lenght of the line or -1 if EOF
int get_line(char s[], int maxchar) {
    int i;
    char c;
    for (i = 0; i < maxchar && (c = getchar()) != EOF; i++) {
        if (c != '\n') {
            s[i] = c;
        } else {
            s[i] = '\0';
            return 1;
        }
    }
    s[i] = '\0';
    return -1;
}

// Reverse s in place using recursion
void reverse(char s[], int left, int right) {
    if (left >= right) return;
    swap(s, left, right);
    reverse(s, left+1, right-1);
}

// Interchange s[i] and s[j]
void swap(char s[], int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
