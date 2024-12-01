#include <stdio.h>

void PosNeg(int*, int*);

void main (){
    int num_input1,num_input2;
    
    printf("Input integer 1: ");
    scanf("%d", &num_input1);

    printf("Input integer 2: ");
    scanf("%d", &num_input2);

    PosNeg(&num_input1, &num_input2);

}

void PosNeg(int* x, int* y){
    
    if (*x > 0){
        printf("%d is an positive number.\n", *x);
    }else if (*x < 0){
        printf("%d is an negative number.\n", *x);
    }

    if (*y > 0){
        printf("%d is an positive number.\n", *y);
    }else if (*y < 0){
        printf("%d is an negative number.\n", *y);
    }

}