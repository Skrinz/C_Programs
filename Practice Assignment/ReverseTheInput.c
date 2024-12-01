#include <stdio.h>

void revPlaceValue(int*);

void main (){
    int num_input;

    printf("What is your digit input?\n");
    scanf("%d", &num_input);

    printf("The original integer is %d\n", num_input);

    revPlaceValue(&num_input);
   
    printf("The reverse is %d\n", num_input);

  
}

void revPlaceValue(int* num_input){
    //reverse the input
    int reverse_input = 0;
    int temp = (*num_input);
    while (temp > 0){
        int n = temp % 10; //assign the last digit of the input to n
        reverse_input = reverse_input * 10 + n; // multiply the reverse_input to 10 to update the digit place
        temp /= 10; // remove the last digit of the input
    }
    (*num_input) = reverse_input;
}