#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaration.h"

void displayList(Node *list){

    printf("\n{");
    list = list->next;
    while(list != NULL){
        printf("%i", list->data);
        list = list->next;
        if(list != NULL){
            printf(", ");
        }
    }
    printf("}\n\n");
}

void insertAtEnd(Node *list, int newData){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
   
    for(;list->next != NULL; list = list->next){}
   
    list->next = newNode;
   
}

void insertAtStart(Node *list, int newData){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
   
    newNode->next = list->next;
    list->next = newNode;
}

void insertSorted(Node *list, int newData){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
   
    for(;list->next != NULL && list->next->data < list->data; list = list->next){}
   
    newNode->next = list->next;
    list->next = newNode;
   
}

void deleteList(Node *list){
    Node *temp;
    while(list != NULL){
        temp = list->next;
        free(list);
        list = temp;
    }
}

void deleteNode(Node *list, int remData){
    for(;list->next != NULL && list->next->data != remData; list = list->next){}
   
    if(list->next == NULL && list->data != remData){
        printf("\n\n\tThe number you want to delete is not in the Linked List!!\n\n");
        return;
    }
   
    Node *nextNode;
   
    nextNode = list->next->next;
    free(list->next);
    list->next = nextNode;
    printf("\n\n\tThe data has been removed!!\n\n");

}