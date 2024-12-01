#include <stdio.h>

int maxNum(int*,int*);

int main (){
    int num_input1;
    int num_input2;
    int max;
   
    printf("Input first integer: ");
    scanf("%d", &num_input1);
   
    printf("Input second integer: ");
    scanf("%d", &num_input2);
   
    max = maxNum(&num_input1, &num_input2);
   
    if (max != -1){
        printf("The maximum between %d and %d is %d.", num_input1, num_input2, max);
       
    }else {
        printf("Both numbers are equal. ", num_input1, num_input2);
    }
   
    return 0;
}

int maxNum (int *num_input1, int*num_input2){
    if (*num_input1 == *num_input2){
        return -1;
    }
    return *num_input1 > *num_input2? *num_input1: *num_input2;
}