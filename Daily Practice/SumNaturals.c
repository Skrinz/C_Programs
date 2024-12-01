#include <stdio.h>
/*
Create a program that calculates the sum of the first n natural numbers using recursion.
*/
int sumNatural(int);

int  main (){
    int num_input;
    int result = 0;

    printf("Enter a number: ");
    scanf("%d", &num_input);

    result = sumNatural(num_input);
    printf("The sum of the first %d natural numbers is: %d.", num_input, result);

    return 0;
}

int sumNatural(int x){
    if (x<= 1){
        return 1;
    }
    
    return (x) + sumNatural(x - 1);
}