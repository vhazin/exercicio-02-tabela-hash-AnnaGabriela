#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

int hash(int key, int amount_keys) {
    return key % amount_keys;
}

void insertKey(Node *hash_table[], int index, Node *current_key) {
    if (hash_table[index] == NULL) {
        hash_table[index] = current_key;
        return;
    }

    Node *temp_key = malloc(sizeof(Node));
    temp_key = hash_table[index];

    while(temp_key->next != NULL) {
        temp_key = temp_key->next;
    }

    temp_key->next = current_key;
 }

void getKeys(Node *hash_table[], int table_size, int amount_keys) {
    int key, index;
    for(int i = 0; i < amount_keys; i++) {
        Node *current_key = malloc(sizeof(Node));
        scanf("%d", &key);
        current_key->key = key;
        current_key->next = NULL;
        index = hash(key, table_size);
        insertKey(hash_table, index, current_key);
    }
}

void displayOutput(Node *hash_table[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        Node *temp_list = hash_table[i];
        printf("%d -> ", i);
        while (temp_list != NULL) {
           printf("%d -> ", temp_list->key);
           temp_list = temp_list->next;
        }
        printf("\\\n");
    }
}

void initTable(Node *hash_table[], int table_size) {
    for(int i = 0; i < table_size; i++) {
        hash_table[i] = NULL;
    }
}

int main () {
    int amount_tests, table_size, amount_keys;

    scanf("%d", &amount_tests);

    for(int i = 1; i <= amount_tests; i++) {
        scanf("%d %d", &table_size, &amount_keys);
        Node *hash_table[table_size];
        initTable(hash_table, table_size);
        getKeys(hash_table, table_size, amount_keys);
        displayOutput(hash_table, table_size);
        if (i < amount_tests) printf("\n");
    }

    return 0;
}