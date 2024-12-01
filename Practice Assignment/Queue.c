#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//basic queue funcionailities
//enqueue()
//dequeue()
//isfull()
//isempty()
//peek()


typedef struct{
    int front;
    int back;
    int *arr;
    int size;
}Queue;

bool isfull(Queue queue){
    return (queue.front = (queue.back+1) % queue.size)? true : false;
}

bool isempty(Queue queue){
    return (queue.back == -1 && queue.front == -1)? true: false;
}

void enqueue(Queue *queue, int elem){
    if(isfull(*queue)){
        printf("The queue is full!!");
        return;
    }

    if(isempty(*queue)){
        queue->front = 0;
        queue->back = 0;
    }else{
        queue->back = (queue->back + 1) % queue->size;
    }
    queue->arr[queue->back] = elem;
}

void dequeue(Queue *queue){
    if(isempty(*queue)){
        printf("The queue is empty!!");
        return;
    }

    if(queue->front == queue->back){
        queue->front = -1;
        queue->back = -1;
    }else{
        queue->front = (queue->front + 1) % queue->size;
    } 
}

int peek(Queue queue){
    if(isempty(queue)){
        printf("The queue is empty!!");
        return;
    }
    return queue.arr[queue.front];
}

void display(Queue queue){
    if(isempty(queue)){
        printf("The queue is empty!!");
        return;
    }

    int i = queue.front;
    for(;i <= queue.back; i = (i+1) % queue.size){
        if(i == queue.front){
            printf("[%d ", queue.arr[i]);
        }else if(i == queue.back){
            printf(" %d]\n", queue.arr[i]);
        }else{
            printf(" %d ", queue.arr[i]);
        }
        
    }
}

int main() {
    Queue queue;

    char choice;

    printf("What is the size of the queue? ");
    scanf("%i", &queue.size);
    queue.back = -1;
    queue.front = -1;

    queue.arr = (int*) malloc(sizeof(int)*queue.size);

    while(1){
        printf("\n\nChoose an option:\n0)end\n1)enqueue\n2)dequeue\n3)peek\n4)display\n");
        scanf(" %c",&choice);

        switch(choice){
            case '1':
                int elem;
                printf("Enter an element: ");
                scanf("%i", &elem);

                push(&queue, elem);
                printf("\nAn element has been enqueued!!\n");
                break;

            case '2':
                pop(&queue);
                printf("\nAn element has been dequeued!!\n");
                break;
                case '3':
                int peek = top(queue);

                printf("\nThe front element is %i\n", peek);
                break;

            case '4':
                display(queue);
                break;

            case '0':
                free(queue.arr);
                return 0;
                break;

            default:
                printf("Choice not found!!");
                break;
        }
    }
}