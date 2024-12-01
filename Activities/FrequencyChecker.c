#include <stdio.h>
#include <stdlib.h>
/*
Input: 10 integers from the user
Ex.
1, 2, 3, 4, 5, 1, 2, 3, 4, 5
Process:
if the input is an integer, assign it into an integer array.
if not then decrement i by 1, to take into account the used i increment. And ask for input again.
subsequently, initialize -1 to frequency array for processing later in the program.
check if for duplicates in the number array. then assign the number of duplicates to frequency array
print the frequency of the array.

Output:the 
The frequency of all elements of an array: 
1 can be found 2 times in the array.
2 can be found 2 times in the array.
3 can be found 2 times in the array.1
4 can be found 2 times in the array.
5 can be found 2 times in the array.

*/


void calculateFrequencies(int*, int, int*);

int main (){
    int size = 10;
    int num[size];
    int *freq = (int*) malloc(size*sizeof(int));
    int input_success;
    int i;

    printf("Enter 10 integers: \n");//ask input from the user

    //check if the input is an integer. Will ask again if the input is not an integer
    do{
        for(i = 0; i < size; i++){
            input_success = scanf("%d", &num[i]);//put the inputs in the number array
            freq[i] = -1;
            
            if (input_success != 1){
                printf("Invalid Input. Try Again.\n");
                while (getchar() != '\n');//clear the invalid input
                printf("Enter another input: \n");
                --i;
            }
        }
    }while (input_success != 1);
     
    calculateFrequencies(num, size, freq);
   
    //print the frequency of a number
    printf("The frequency of all elements of an array: ");
    for(i = 0; i < size; i++){
        if (freq[i] > 0 && freq[i] != -1){
            printf("\n%d can be found %d times in the array.", num[i], freq[i]);
        }
        
    }

    free(freq);

    return 0;
}


void calculateFrequencies(int *num, int size, int *freq){
    for (int i = 0; i < size; i++) {
        freq[i] = -1; // Initialize frequency array
    }

    for (int i = 0; i < size; i++){//make the initiate the starting point of the array
        if(freq[i] == -1){// if frequency element is not yet counted
            int count = 1;// the starting point itself is a frequency of the number
            for (int j = i + 1; j < size; j++){//go through the other element of the array 
                if (num[i] == num[j]){//if starting point and some point in the array are equal go inside
                    count++;//increase the frequency count
                    freq[j] = 0;//so that frequency array and number array don't have repetitions 
                }
            }
            freq[i] = count; // asign the frequency count to the starting point in array
        }
    }
}