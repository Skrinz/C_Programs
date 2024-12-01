#include <stdio.h>
#include <stdbool.h>

/*
Write a C program that checks if a given number is 
a prime number. A prime number is a natural number 
greater than 1 that has no positive divisors other than 1 and itself.
*/

bool is_prime(int);

int main (){
    int num_input;
    int result;

    printf("Input an integer: ");
    scanf("%d", &num_input);

    result = is_prime(num_input);

    if (result){
        printf("The integer is a prime.");
    }else {
        printf("The integer is not a prime.");
    }

    return 0;
}


bool is_prime (int x){
    if (x <= 0){
        return false;
    }

    for (int i = 2; i * i <= x; i++) {
       if (x % i == 0) {
           return false;
       }
   }
   return true;
}