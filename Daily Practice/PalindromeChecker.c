#include <stdio.h>

int main (){
    int num_input;
    int input_success;
    int num_digits;

    //prompt an input for the user
    printf("Input 10 integer: ");
    //process the input so that it will only accept integers
    do{
        input_success = scanf("%d", &num_input);

        if (input_success != 1){
            printf("Invalid Input. Try Again.\n");
            while(getchar() != '\n');
            printf("Input an integer: ");
        }
    }while (input_success != 1);

    //get the last digit of the input
    int last_digit = num_input % 10;

    //get the first digit of the input
    int first_digit = num_input;
    while (first_digit >= 10){
        first_digit /= 10;
    }

    //check if the last digit and first digit is the same
    if (last_digit == first_digit){
        printf("The input is a palindrome.");
    }else {
        printf("The input is not a palindrome.");
    }

    return 0;
}