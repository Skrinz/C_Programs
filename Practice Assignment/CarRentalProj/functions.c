#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "declaration.h"

//Queue Functions
Queue createQueue(){
    Queue q = (Queue) malloc(sizeof(struct queue));
    q->front = q->back = NULL;
    return q;
}

bool isQueueEmpty(Queue q){
    return (q->front == NULL)? true: false;
}

void enqueue(Queue q, char *action, char *customerName, char *carId){
    Node * newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("\nMemory Allocation Failed!!\n");
        return;
    }
    strcpy(newNode->action, action);
    strcpy(newNode->customerName, customerName);
    strcpy(newNode->carId, carId);
    newNode->next = NULL;

    if(q->back == NULL){
        q->front = q->back = newNode;
    }else{
        q->back->next = newNode;
        q->back = newNode;
    }
}

Node* dequeue(Queue q){
    if(isQueueEmpty(q)){
        printf("\nQueue is empty\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->back = NULL;
    }

    free(temp);
    return temp;
}

//Stack Funcitons
bool isCarStackEmpty(CarStack* s){
    return (s->top == -1)? true: false;
}
bool isCarStackFull(CarStack *s){
    return (s->top >= Max_CARS - 1)? true: false;
}

void initializeCarStack(CarStack* s){
    s->top = -1;
}

bool pushCar(CarStack* s, char *carId){
    if(isCarStackFull(s)){
        printf("\nStack is Full!!\n");
        return false;
    }

    strcpy(s->carId[s->top+1], carId);
    s->top++;
    return true;
}

char* popCar(CarStack *s){
    if(isCarStackEmpty(s)){
        printf("\nStack is empty!!\n");
        return NULL;
    }

   char * carId = s->carId[s->top];
   s->top--;
   return carId;
}

void processCustomerActions(Queue q, CarStack* s){
    int action = 1;
    while(!isQueueEmpty(q)){
        Node* prioAction = dequeue(q);
        printf("Action %i:\n", action++);

        if(strcmp(prioAction->action, "pop") == 0){
            char* rentedCar = popCar(s);

            if(rentedCar != NULL){
                strcpy(prioAction->carId, rentedCar);
                printf("Car %s is rented  to %s\n\n", rentedCar, prioAction->customerName);
            }else{
                printf("No cars available for %s", prioAction->customerName);
            }
        }else if(strcmp(prioAction->action, "push") == 0){
            char *returnedCar = prioAction->carId;
        
            if(pushCar(s, returnedCar)){
                printf("%s returned Car %s\n\n", prioAction->customerName, returnedCar);
            }else{
                printf("Failed to return Car %s\n", returnedCar);
            }
        }
    }
}