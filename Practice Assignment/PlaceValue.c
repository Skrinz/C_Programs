#include <stdio.h>

int main (){
    int num_input, digit;
    int num_value = 0;
    int place = 0;
    int placement = 1;

    printf("What is your digit input? (Max 3) ");
    scanf("%d", &num_input);

    int n = num_input;
    
    //count how many places the input has
    while (n != 0){
        place++;
        n /= 10;
    }

    //display the designated digit placement of the input
    for (int x = 0; x < place; x++){
        if (place > 3){
            printf("Your digit input is out of the maximum range.");
            break;
        }

        digit = num_input % 10; // get the last number of the input
        num_input /= 10; //remove the last digit of the input

    
        switch (placement){
            case 1:
                printf("Ones place: %d\n", digit);
                break;
            case 10:
                printf("Tens place: %d\n", digit);
                break;
            case 100:
                printf("Hundreds place: %d\n", digit);
                break;
        }
        placement *= 10;
    }
    return 0;
}