#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "declaration.h"

void printThis(Node * trav){
    while (trav->next!=NULL)
    {
        trav = trav->next;
        printf("%s, %s\n", trav->var.lastname, trav->var.firstname);
    }
}

void insertSorted(Node *trav, char firstname[], char lastname[]){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->var.firstname, firstname);
    strcpy(newNode->var.lastname, lastname);
    newNode->next = NULL;
    
    for(;trav->next!=NULL && strcmp(trav->next->var.lastname, lastname) < 0; trav = trav->next){}
    
    newNode->next = trav->next;
    trav->next = newNode;
    
}

void insertEnd(Node *trav, char firstname[], char lastname[]){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->var.firstname, firstname);
    strcpy(newNode->var.lastname, lastname);
    newNode->next = NULL;

    for(;trav->next != NULL; trav = trav->next){}
     
    trav->next = newNode;

}

void insertStart(Node *trav, char firstname[], char lastname[]){

    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->var.firstname, firstname);
    strcpy(newNode->var.lastname, lastname);

    newNode->next = trav->next;
    trav->next = newNode;
}

void deleteName(Node *trav){
    printThis(trav);
    printf("\n\n");

    char lName[20];

    printf("Enter the Last Name of the Person You want to Delete: ");
    scanf("%s",lName);
    lName[strcspn(lName,"\n")] = '\0';

    for(;trav->next != NULL && strcmp(trav->next->var.lastname, lName) != 0; trav = trav->next){}

    if(trav->next == NULL && strcmp(trav->var.lastname, lName) != 0){
        printf("\n\n\tThe name you want to delete is not in the Linked List!!\n\n");
        return; 
    }

    Node *nextNode;

    nextNode = trav->next->next; //next node after the matched node
    free(trav->next);
    trav->next = nextNode;
    printf("\n\n\tThe data has been removed!!\n\n");
}

void createCycle(Node *trav, char lastname[]){
    Node *entry = NULL;

    while(trav->next != NULL){
        if(strcmp(trav->next->var.lastname, lastname) == 0){
            entry = trav->next;
        }
        trav = trav->next;
    }

    trav->next = entry;
}

void deleteList(Node *trav){
    Node *next_node;
    while(trav != NULL){
        next_node = trav->next;
        free(trav);
        trav = next_node;
    }
}

bool checkCycle(Node *trav){
    Node *fast = trav;
    Node *slow = trav;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    if(fast == NULL || fast->next == NULL){
        return false;
    }
}