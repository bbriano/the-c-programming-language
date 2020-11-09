//            _            _       _
//   ___ __ _| | ___ _   _| | __ _| |_ ___  _ __ ___
//  / __/ _` | |/ __| | | | |/ _` | __/ _ \| '__/ __|
// | (_| (_| | | (__| |_| | | (_| | || (_) | | | (__
//  \___\__,_|_|\___|\__,_|_|\__,_|\__\___/|_|(_)___|
//
//  Example use case:
//  calculator 4 5 + 9 x 2 3 - +
//  80
//
//              +
//             / \
//            /   \
//           /     \
//          x       -
//         / \     / \
//        +   9   2   3
//       / \
//      4   5
//

#include <stdio.h>
#include <stdlib.h>

int strtoint(char *str);

int main(int argc, char *argv[]) {
    int *stack = (int*) malloc(argc);

    int left, right;
    for (int i = 1; i < argc; i++) {
        switch (*argv[i]) {
            case '+':
                right = *--stack;
                left  = *--stack;
                *stack++ = left + right;
                break;
            case '-':
                right = *--stack;
                left  = *--stack;
                *stack++ = left - right;
                break;
            case 'x':
                right = *--stack;
                left  = *--stack;
                *stack++ = left * right;
                break;
            default:
                /* *stack++ = strtoint(argv[i]); */
                *stack++ = atoi(argv[i]);
                break;
        }
    }

    printf("%d\n", *--stack);
    free(stack);
}

int strtoint(char *str) {
    int res = 0;
    char c;

    while ((c = *str++) != '\0') {
        if (c < '0' || c > '9') {
            printf("Invalid integer\n");
            exit(1);
        }
        res = res * 10 + c - '0';
    }
    return res;
}
