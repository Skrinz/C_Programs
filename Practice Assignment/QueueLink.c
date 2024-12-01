#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//enqueue()
//dequeue()
//isfull()
//isempty()
//peek()

typedef struct node{
int num;
struct node* next;
}*Nodeptr;

bool isfull(int size, int currsize){
    return  (size == currsize)? true: false;
}

bool isempty(int currsize){
    return (currsize == 0)? true: false;
}

void enqueue(Nodeptr *queue, int elem, int size, int *currsize){
    if(isfull(size, *currsize)){
        printf("The queue is full!!");
        return;
    }

    Nodeptr newNode = (Nodeptr) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed!");
        return;
    }
    newNode->num = elem;

    if(*queue == NULL){
        *queue = newNode;
         newNode->next = NULL;
    }else{
        Nodeptr trav = *queue;
        for(;trav->next != NULL; trav = trav->next){}
        trav->next = newNode;
    }
    
    (*currsize)++;
}

void dequeue(Nodeptr *queue, int *currsize){
    if(isempty(*currsize)){
        printf("The queue is empty!!");
        return;
    }
    Nodeptr temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    (*currsize)--;
}

int peek(Nodeptr queue){
    return queue->num;
}

void display(Nodeptr queue, int currsize){
    if(isempty(currsize)){
        printf("The queue is empty!!");
    return;
    }

    printf("[");
    while (queue != NULL) {
        printf(" %d", queue->num);
        queue = queue->next;
    }
    printf(" ]\n");
}

void freeAll(Nodeptr *queue){
    while (*queue != NULL) {
        Nodeptr temp = *queue;
        *queue = (*queue)->next;
        free(temp);
    }
}

int main() {
    Nodeptr queue = NULL;
    int size = 0, currsize = 0;

    printf("What is the size of the queue? ");
    scanf("%i", &size);
    
    while(1){
    char choice;
    printf("\n\n0)end\n1)enqueue\n2)dequeue\n3)peek\n4)display\nChoose an option:");
    scanf(" %c",&choice);

    switch(choice){
        case '1':
            int elem;
            printf("\nEnter an element: ");
            scanf("%i", &elem);

            enqueue(&queue, elem, size, &currsize);
            printf("\nAn element has been enqueued!!\n");
            break;

        case '2':
            dequeue(&queue, &currsize);

            printf("\nAn element has been dequeued!!\n");
            break;
            case '3':
            int front = peek(queue);

            printf("\nThe front element is %i\n", front);
            break;

        case '4':
            display(queue, currsize);
            break;

        case '0':
            freeAll(&queue);
            return 0;
            break;

        default:
            printf("Choice not found!!");
            break;
        }
    }
    
}