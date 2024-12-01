#include <stdio.h>

void sortOddEvenPlaceValue (int*);

void main (){
    int num_input1;
    
    printf("Input integer: ");
    scanf("%d", &num_input1);

    sortOddEvenPlaceValue (&num_input1);

}

void sortOddEvenPlaceValue (int* x){
    int reverse_input = 0;
    int temp1 = (*x);
    while (temp1 > 0){
        int n = temp1 % 10; //assign the last digit of the input to n
        reverse_input = reverse_input * 10 + n; // multiply the reverse_input to 10 to update the digit place
        temp1 /= 10; // remove the last digit of the input
    }
    
    int temp2 = reverse_input;
    while(temp2 > 0){
        int digit = temp2 % 10;
        
        if ((digit) % 2 == 0){
            printf("%d even digit\n", digit);
        }else{
            printf("%d odd digit\n", digit);
        }
        
        temp2 /= 10;
    }
}