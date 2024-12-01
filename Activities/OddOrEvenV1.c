#include <stdio.h>

void OddEven (int*, int*);

void main (){
    int num_input1,num_input2;
    
    printf("Input integer 1: ");
    scanf("%d", &num_input1);

    printf("Input integer 2: ");
    scanf("%d", &num_input2);

    OddEven (&num_input1, &num_input2);

}

void OddEven (int* x, int* y){
    
    if (*x % 2 == 0){
        printf("%d is an even number.\n", *x);
    }else{
        printf("%d is an odd number.\n", *x);
    }

     if (*y % 2 == 0){
        printf("%d is an even number.\n", *y);
    }else{
        printf("%d is an odd number.\n", *y);
    }

}