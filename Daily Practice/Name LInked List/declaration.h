#ifndef DECLARATION_H
#define DECLARATION_H

typedef struct {
  char firstname[20];
  char lastname[20];
}studName;
typedef struct node{
  studName var;
  struct node *next;
}Node;

void printThis(Node * trav);
void insertSorted(Node *trav, char firstname[], char lastname[]);
void insertEnd(Node *trav, char firstname[], char lastname[]);
void insertStart(Node *trav, char firstname[], char lastname[]);
void deleteName(Node *trav);
void createCycle(Node *trav, char lastname[]);
void deleteList(Node *trav);
bool checkCycle(Node *trav);

#endif