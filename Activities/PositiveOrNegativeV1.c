#include <stdio.h>

int PosNeg(int*);

int main (){
    int num_input1,num_input2;
    int check = 0;
    
    printf("Input integer: ");
    scanf("%d", &num_input1);

    check = PosNeg(&num_input1);

    if (check == 1){
        printf("%d is a positive number.\n", num_input1);
    }else if (check == -1){
        printf("%d is a negative number.\n", num_input1);
    }

    return 0;
}

int PosNeg(int* x){

    if (*x > 0){
        return 1;
    }else if (*x < 0){
        return -1;
    }
}