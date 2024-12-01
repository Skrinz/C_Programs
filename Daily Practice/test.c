#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100
#define CAR_ID_LENGTH 5

// Queue structure
typedef struct Node {
    char action[5];
    char customerName[100];
    char carId[CAR_ID_LENGTH];
    struct Node* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue createQueue() {
    Queue q = {NULL, NULL};
    return q;
}

void enqueue(Queue* q, char* action, char* customerName, char* carId) {
    QueueNode* newNode = malloc(sizeof(QueueNode));
    strcpy(newNode->action, action);
    strcpy(newNode->customerName, customerName);
    strcpy(newNode->carId, carId);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

QueueNode* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;

    QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return temp;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Stack structure
typedef struct CarStack {
    char carIds[MAX_CARS][CAR_ID_LENGTH];
    int top;
} CarStack;

void initializeCarStack(CarStack* s) {
    s->top = -1;
}

int pushCar(CarStack* s, char* carId) {
    if (s->top >= MAX_CARS - 1) return 0;
    strcpy(s->carIds[++s->top], carId);
    return 1;
}

char* popCar(CarStack* s) {
    if (s->top == -1) return NULL;
    return strcpy(malloc(strlen(s->carIds[s->top]) + 1), s->carIds[s->top--]);
}

int isCarStackEmpty(CarStack* s) {
    return s->top == -1;
}

int isCarStackFull(CarStack* s) {
    return s->top >= MAX_CARS - 1;
}

// Main function to process customer actions
void processCustomerActions(Queue* customerQueue, CarStack* carStack) {
    QueueNode* currentNode;
    while ((currentNode = dequeue(customerQueue)) != NULL) {
        printf("Processing action for %s\n", currentNode->customerName);

        if (strcmp(currentNode->action, "pop") == 0) {
            char* rentedCarId = popCar(carStack);
            if (rentedCarId != NULL) {
                strcpy(currentNode->carId, rentedCarId);
                printf("Rented car ID: %s\n", currentNode->carId);
            } else {
                printf("No cars available\n");
            }
        } else if (strcmp(currentNode->action, "push") == 0) {
            if (pushCar(carStack, currentNode->carId) == 1) {
                printf("Returned car ID: %s\n", currentNode->carId);
            } else {
                printf("Stack full, cannot return car\n");
            }
        }

    }
}

int main() {
    Queue customerQueue = createQueue();
    CarStack carStack;

    initializeCarStack(&carStack);

    // Add cars to the stack
    pushCar(&carStack, "Ca123");
    pushCar(&carStack, "Ca456");
    pushCar(&carStack, "Ca789");
    pushCar(&carStack, "Ca439");
    pushCar(&carStack, "Ca956");
    pushCar(&carStack, "Ca829");

    // Enqueue customer actions
    enqueue(&customerQueue, "pop", "Alice", "");
    enqueue(&customerQueue, "pop", "Charlie", "");
    enqueue(&customerQueue, "push", "Bob", "Ca999");
    enqueue(&customerQueue, "push", "Andy", "Ca439");
    enqueue(&customerQueue, "pop", "Robert", "");

    // Process customer actions
    processCustomerActions(&customerQueue, &carStack);

    return 0;
}
