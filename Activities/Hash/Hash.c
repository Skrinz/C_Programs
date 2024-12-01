#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int value;
    struct Node* next;
} *Node;

Node create_node(int value) {
    Node node = malloc(sizeof(struct Node)); 
    node->value = value;
    node->next = NULL;
    return node;
}

int hash_function(int key) {
    return key % SIZE;
}

void initHash(Node* table) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
}

void Insorted(Node* table, int value) {
    int index = hash_function(value);
    
    Node node = create_node(value);
    
    if (table[index] == NULL || table[index]->value > value) {
        node->next = table[index];
        table[index] = node;
    } else {
        Node current = table[index];
        while (current->next != NULL && current->next->value <= value) {
            current = current->next;
        }
        
        node->next = current->next;
        current->next = node;
    }
}

void deleteHash(Node* table, int value) {
    int index = hash_function(value);
    
    if (table[index] == NULL) return;
    
    if (table[index]->value == value) {
        Node temp = table[index];
        table[index] = table[index]->next;
        free(temp);
        return;
    }
    
    Node current = table[index];
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        Node temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

int main() {
    Node hash_table[SIZE];
    initHash(hash_table);
    
    Insorted(hash_table, 5);
    Insorted(hash_table, 2);
    Insorted(hash_table, 8);
    Insorted(hash_table, 1);
    Insorted(hash_table, 3);
    Insorted(hash_table, 7);
    Insorted(hash_table, 4);
    Insorted(hash_table, 6);
    
    deleteHash(hash_table, 2);
    
    return 0;
}
