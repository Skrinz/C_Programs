#ifndef DECLARATION_H
#define DECLARATION_H

#define CAR_ID_LENGTH 5
#define Max_CARS 10

typedef struct node{
    char action[5]; // for "push"(return) or "pop"(rent)
    char customerName[100];// customer's name
    char carId[CAR_ID_LENGTH];//Car id rented, empty not rented
    struct node* next;

}Node;

typedef struct{
    char carId[CAR_ID_LENGTH];//array to hold carId
    int top; //index of the top element of the node
    
}CarStack;

typedef struct queue{
    Node *front;
    Node *back;
}*Queue;

//Queue Functions
Queue createQueue();
void enqueue(Queue q, char *action, char *customerName, char *carId);
Node* dequeue(Queue q);
bool isQueueEmpty(Queue q);

//Stack Funcitons
void initializeCarStack(CarStack* s);
bool pushCar(CarStack* s, char *carId);
char* popCar(CarStack *s);
bool isCarStackEmpty(CarStack* s);
bool isCarStackFull(CarStack* s);

void processCustomerActions(Queue q, CarStack* s);

#endif