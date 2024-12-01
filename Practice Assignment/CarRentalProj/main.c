#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "declaration.h"

int main(){
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
    enqueue(customerQueue, "pop", "Alice", "");
    enqueue(customerQueue, "pop", "Charlie", "");
    enqueue(customerQueue, "push", "Bob", "Ca999");
    enqueue(customerQueue, "push", "Andy", "Ca439");
    enqueue(customerQueue, "pop", "Robert", "");

    // Process customer actions
    processCustomerActions(customerQueue, &carStack);

}