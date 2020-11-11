#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_WORD_LEN 9999

struct node;
struct node node_make(char *key, int value);
void node_kill_rec(struct node *n);
struct node *node_insert(struct node *current, char *key, int value);
int node_len(struct node *current);
int node_height(struct node *current);
void node_print(struct node *current);

int main() {
    char word[MAX_WORD_LEN+1];
    int len;
    struct node *root = NULL;

    while ((len = scanf("%s", word)) != EOF) {
        root = node_insert(root, word, 1);
    }

    node_print(root);
    printf("tree_length = %d\n", node_len(root));
    printf("tree_height = %d\n", node_height(root));
    node_kill_rec(root);
}

struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
};

struct node node_make(char *key, int value) {
    struct node n;
    n.key = malloc(strlen(key)+1);
    strcpy(n.key, key);
    n.value = value;
    n.left = NULL;
    n.right = NULL;
    return n;
}

void node_kill_rec(struct node *n) {
    if (n == NULL) return;
    free(n->key);
    if (n->left) node_kill_rec(n->left);
    if (n->right) node_kill_rec(n->right);
    free(n);
}

struct node *node_insert(struct node *current, char *key, int value) {
    if (current == NULL) {
        current = (struct node *) malloc(sizeof(struct node));
        *current = node_make(key, value);
    } else if (strcmp(key, current->key) == 0) {
        current->value += value;
    } else if (strcmp(key, current->key) < 0) {
        current->left = node_insert(current->left, key, value);
    } else {
        current->right = node_insert(current->right, key, value);
    }
    return current;
}

int node_len(struct node *current) {
    if (current == NULL) return 0;
    return node_len(current->left) + node_len(current->right) + 1;
}

int node_height(struct node *current) {
    if (current == NULL) return -1;
    return max(node_height(current->left), node_height(current->right)) + 1;
}

void node_print(struct node *current) {
    if (current->left) node_print(current->left);
    printf("%s %d\n", current->key, current->value);
    if (current->right) node_print(current->right);
}
