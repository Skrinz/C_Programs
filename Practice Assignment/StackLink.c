#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//push()
//pop()
//isfull()
//isempty()
//top()

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

void push(Nodeptr *stack, int elem, int size, int *currsize){
    if(isfull(size, *currsize)){
        printf("The stack is full!!");
        return;
    }

    Nodeptr newNode = (Nodeptr) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed!");
        return;
    }
    newNode->num = elem;
    newNode->next = *stack;
    *stack = newNode;
    (*currsize)++;
}

void pop(Nodeptr *stack, int *currsize){
    if(isempty(*currsize)){
        printf("The stack is empty!!");
        return;
    }
    Nodeptr temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    (*currsize)--;
}

int top(Nodeptr stack){
    return stack->num;
}

void display(Nodeptr stack, int currsize){
    if(isempty(currsize)){
        printf("The stack is empty!!");
    return;
    }

    for(int i = 0; i< currsize; i++, stack = stack->next){
        printf("| %d |\n", stack->num);
    }
}

void freeAll(Nodeptr *stack){
    while (*stack != NULL) {
        Nodeptr temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

int main() {
    Nodeptr stack = NULL;
    int size = 0, currsize = 0;

    printf("What is the size of the stack? ");
    scanf("%i", &size);
    
    while(1){
    char choice;
    printf("\n\n0)end\n1)push\n2)pop\n3)peek\n4)display\nChoose an option:");
    scanf(" %c",&choice);

    switch(choice){
        case '1':
            int elem;
            printf("\nEnter an element: ");
            scanf("%i", &elem);

            push(&stack, elem, size, &currsize);
            printf("\nAn element has been pushed!!\n");
            break;

        case '2':
            pop(&stack, &currsize);


            printf("\nAn element has been popped!!\n");
            break;
            case '3':
            int peek = top(stack);

            printf("\nThe front element is %i\n", peek);
            break;

        case '4':
            display(stack, currsize);
            break;

        case '0':
            freeAll(&stack);
            return 0;
            break;

        default:
            printf("Choice not found!!");
            break;
        }
    }
    
}