#include <stdio.h>
/*
Write a C program to create a function that 
calculates the factorial of a number. The function 
should take an integer as an input and return the factorial of that integer.

Expected Input and Output

If the user inputs the number 5, the function should 
return 120, because the factorial of 5 (denoted as 5!) is 12345 = 120.
*/
int factorial(int);

int  main (){
    int num_input;
    int result = 0;

    printf("Input an integer: ");
    scanf("%d", &num_input);

    result = factorial(num_input);
    printf("The factorial of %d is %d.", num_input, result);

    return 0;
}

int factorial(int x){
    if (x <= 1){
        return 1;
    }
    
    return (x) * factorial(x - 1);
}