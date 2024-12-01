#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 128

typedef struct Node {
    int value;
    struct Node* next;
} *Node;

Node create_node(int value) {
    Node node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void initHash(Node** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        (*table)[i] = NULL;
    }
}

void Insorted(Node** table, int value) {
    int index = hash_function(value);
    
    Node node = create_node(value);
    
    if ((*table)[index] == NULL || (*table)[index]->value > value) {
        node->next = (*table)[index];
        (*table)[index] = node;
    } else {
        Node* current = (*table)[index];
        while ((*current)->next != NULL && (*current)->next->value <= value) {
            (*current) = (*current)->next;
        }
        
        node->next = (*current)->next;
        (*current)->next = node;
    }
}

void deleteHash(Node** table, int value) {
    int index = hash_function(value);
    
    if ((*table)[index] == NULL) return;
    
    if ((*table)[index]->value == value) {
        Node* temp = (*table)[index];
        (*table)[index] = (*table)[index]->next;
        free(temp);
        return;
    }
    
    Node* current = (*table)[index];
    while ((*current)->next != NULL && (*current)->next->value != value) {
        current = (*current)->next;
    }
    
    if ((*current)->next != NULL) {
        Node* temp = (*current)->next;
        (*current)->next = (*current)->next->next;
        free(temp);
    }
}


void print_hash_table(Node** table) {
    printf("Hash Table contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = (*table)[i];
        while (current != NULL) {
            printf("%d -> ", (*current)->value);
            current = (*current)->next;
        }
        printf("NULL\n");
    }
}


int main() {
    Node hash_table[TABLE_SIZE];
    initHash(&hash_table);
    
    Insorted(&hash_table[0], 5);
    Insorted(&hash_table[0], 2);
    Insorted(&hash_table[0], 8);
    Insorted(&hash_table[0], 1);
    Insorted(&hash_table[0], 3);
    Insorted(&hash_table[0], 7);
    Insorted(&hash_table[0], 4);
    Insorted(&hash_table[0], 6);
    
    print_hash_table(&hash_table);
    
    deleteHash(&hash_table[0], 2);
    
    print_hash_table(&hash_table);
    
    return 0;
}
