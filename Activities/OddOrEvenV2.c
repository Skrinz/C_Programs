#include <stdio.h>

int OddEven (int*);

int main (){
    int num_input1,num_input2;
    int check = 0;
    
    printf("Input integer: ");
    scanf("%d", &num_input1);

    check = OddEven(&num_input1);

    if (check == 1){
        printf("%d is an even number.\n", num_input1);
    }else{
        printf("%d is an odd number.\n", num_input1);
    }

    return 0;
}

int OddEven (int* x){
    
    if (*x % 2 == 0){
        return 1;
    }else{
        return 0;
    }
}