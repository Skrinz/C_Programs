#ifndef DECLARATION_H
#define DECLARATION_H

typedef struct list{
    int data;
    struct list *next;
}Node;

void displayList(Node *list);
void insertAtEnd(Node *list, int newData);
void insertAtStart(Node *list, int newData);
void insertSorted(Node *list, int newData);
void deleteList(Node *list);
void deleteNode(Node *list, int remData);

#endif