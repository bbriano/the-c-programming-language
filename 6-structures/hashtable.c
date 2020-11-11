#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100

typedef struct node {
    struct node *next;
    char *key;
    char *value;
} node;

unsigned hash(char *key);
node *makenode(char *key, char *value);
void killnode_rec(node *base);
node *lookup(node *table[], char *key);
node *install(node *table[], char *key, char *value);

int main() {
    node *table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;

    node *temp;

    install(table, "hello", "world");
    printf("SET %s: %s\n", "hello", "world");

    install(table, "coca", "cola");
    printf("SET %s: %s\n", "coca", "cola");

    temp = lookup(table, "coca");
    printf("GET %s: %s\n", temp->key, temp->value);

    temp = lookup(table, "hello");
    printf("GET %s: %s\n", temp->key, temp->value);

    install(table, "hello", "briano");
    printf("SET %s: %s\n", "hello", "briano");

    temp = lookup(table, "hello");
    printf("GET %s: %s\n", temp->key, temp->value);

    // Clean up
    for (int i = 0; i < TABLE_SIZE; i++)
        killnode_rec(table[i]);
}

node *makenode(char *key, char *value) {
    node *new = malloc(sizeof(node));
    if (new == NULL) return NULL;  // malloc failed to give memory
    new->next = NULL;
    new->key = strdup(key);
    new->value = strdup(value);
    return new;
}

void killnode_rec(node *current) {
    if (current == NULL) return;
    killnode_rec(current->next);
    free(current->key);
    free(current->value);
    free(current);
}

unsigned hash(char *key) {
    unsigned val;
    for (val = 0; *key != '\0'; key++)
        val = (31*val + *key) % TABLE_SIZE;
    return val;
}

node *lookup(node *table[], char *key) {
    node *current;
    for (current = table[hash(key)]; current != NULL; current = current->next) {
        if (strcmp(current->key, key) == 0)
            return current;
    }
    return NULL;
}

node *install(node *table[], char *key, char *value) {
    // Check if key already exists in table, just update the value if so
    node *current = lookup(table, key);
    if (current != NULL) {
        free(current->value);
        current->value = strdup(value);
        return current;
    }

    // Create new node if key doesn't exist in table
    node *new = makenode(key, value);
    if (new == NULL) return NULL;

    // Put new node in table base
    unsigned hashval = hash(key);
    new->next = table[hashval];
    table[hashval] = new;
    return new;
}
