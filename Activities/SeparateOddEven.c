#include <stdio.h>
#include <stdlib.h>
/*
Input:
1, 0, 2, a Invalid Input. Try Again., 3, 4, 5, 6, 7, 8, 9

Process:
the prompts the user to enter 10 integers
checks if each input is a valid integer. If not, it displays error message and asks for input again
the code stores the valid input in the num array.
the code check each number in the num array and assigns it to either even array or the odd array--
-- based on whether it is even or odd.
the code prints the elements of the even array, separated by commas
the code prints the elements of the odd array, separated by commas.

Output:
The elements inside the array 
Numbers in the even array:  0,  2,  4,  6,  8
Numbers in the odd array:  1,  3,  5,  7,  9

*/

void checkOddOrEven(int*, int*, int* , int*, int*, int);
void printEvenArray(int*, int);
void printOddArray(int*, int);

int main (){
    int size = 10;
    int *num = (int *) malloc(size*sizeof(int)); 
    int *odd = (int *) malloc(size*sizeof(int)); 
    int *even = (int *) malloc(size*sizeof(int)); 
    int input_success;
    int even_size = 0, odd_size = 0;

    printf("Enter 10 integers: \n");//ask input from the user

    //check if the input is an integer. Will ask again if the input is not an integer
    while(input_success != 1){
        input_success = 0;
        for(int i = 0; i < size; i++){
            input_success = scanf("%d", &num[i]);//put the inputs in the number array

            if (input_success != 1){
                printf("Invalid Input. Try Again.\n");
                while (getchar() != '\n');//clear the invalid input
                --i;
            }
        }
    }

    //check the number array for even and odd integers and assign it to their respectve array
    checkOddOrEven(odd,even, &even_size, &odd_size, num, size);

    printf("The elements inside the array \n\n");

    //print the even elements of the array in separate 
    printEvenArray(even, even_size);

    //print the odd elements of the array in separate
    printOddArray(odd, odd_size);

    free(num);
    free(odd);
    free(even);
     
   
    return 0;
}

void checkOddOrEven(int* odd, int* even, int* e_size, int* o_size, int* num, int size){
    for(int i = 0; i < size; i++){
        if (num[i] % 2 == 0){
            even[*e_size] = num[i];
            (*e_size)++;
        }else if (num[i] % 2 != 0){
            odd[*o_size] = num[i];
            (*o_size)++;
        }
    }
}

void printEvenArray(int* even, int size){
    int comma_count = 0;
    printf("Numbers in the even array: ");
    for(int i = 0; i < size; i++){
        if(comma_count){
            printf(", ");
        }      
        printf(" %d", even[i]);
        comma_count = 1;
    }
}

void printOddArray(int* odd, int size){
    printf("\nNumbers in the odd array: ");
    int comma_count = 0;
    for(int i = 0; i < size; i++){
        if(comma_count){
            printf(", ");
        } 
            
        printf(" %d", odd[i]);
        comma_count = 1;
    }
}

