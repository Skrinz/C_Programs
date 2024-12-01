#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//basic stack functionalities
//push()
//pop()
//isfull()
//isempty()
//top()


typedef struct{
int currSize;
int *arr;
int size;
}Stack;


bool isfull(Stack stack){
    return (stack.currSize == stack.size-1)? true : false;
}

bool isempty(Stack stack){
    return (stack.currSize == -1)? true: false;
}

void push(Stack *stack, int elem){
    if(isfull(*stack)){
        printf("The stack is full!!");
        return;
    }

    stack->arr[stack->currSize++] = elem;
}

void pop(Stack *stack){
    if(isempty(*stack)){
        printf("The stack is empty!!");
        return;
    }
    stack->currSize--;
}

int top(Stack stack){
    return stack.arr[stack.currSize];
}

void display(Stack stack){
    if(isempty(stack)){
        printf("The stack is empty!!");
        return;
    }
    int i = stack.currSize;
    for(;i != -1;i--){
        printf("| %d |\n", stack.arr[i]);
    }
}

int main() {
    Stack stack;

    char choice;

    printf("What is the size of the stack? ");
    scanf("%i", &stack.size);
    stack.currSize = -1;

    stack.arr = (int*) malloc(sizeof(int)*stack.size);

    while(1){
        printf("\n\nChoose an option:\n0)end\n1)push\n2)pop\n3)peek\n4)display\n");
        scanf(" %c",&choice);

        switch(choice){
            case '1':
                int elem;
                printf("Enter an element: ");
                scanf("%i", &elem);

                push(&stack, elem);
                printf("\nAn element has been pushed!!\n");
                break;

            case '2':
                pop(&stack);
                printf("\nAn element has been popped!!\n");
                break;
                case '3':
                int peek = top(stack);

                printf("\nThe top element is %i\n", peek);
                break;

            case '4':
                display(stack);
                break;

            case '0':
                free(stack.arr);
                return 0;
                break;

            default:
                printf("Choice not found!!");
                break;
        }
    }
}