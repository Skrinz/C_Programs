    #include <stdio.h>
    /*
    Write a C program that takes an integer as input and 
    calculates the sum of its digits. The program should 
    repeatedly prompt the user for input until a non-positive 
    integer is entered, at which point it should terminate.

    */

    int main (){
        int num_input;
        int digit = 0;
        int sum = 0;
        int input_success;
        
        while (1){
            printf("\nInput an integer: ");
            input_success = scanf("%d", &num_input);
            if (input_success != 1){
                while(getchar() != '\n');
                printf("Enter a positive integer.\n");  
            }

            if (num_input <= 0){
                printf("Program terminates.");
                break;
            }

            int temp = num_input;
            while(temp > 0){
                sum += temp % 10;
                temp /= 10; 
            }

            printf("The sum of digits is %d", sum);

        }
            
        return 0;
    }