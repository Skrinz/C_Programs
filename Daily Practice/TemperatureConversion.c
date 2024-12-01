#include <stdio.h>
#include <stdlib.h>

float cel_to_fah(float);
float fah_to_cel(float);
float ask_input(float*);
int choose_con(int*);
void print_result(float*);

void main (){
    float input;
    int conversion;
    float result = 0;

    ask_input(&input);

    choose_con(&conversion);

    if(conversion == 1){
        result = fah_to_cel(input);
    }else if (conversion == 2){
        result = cel_to_fah(input);
    }
    
    print_result(&result);
}

float ask_input(float* num_input){
   printf("Input the temperature: ");
   if (scanf("%f", &(*num_input)) != 1) {
       printf("Error: Invalid input\n");
       exit(1);
   }
}

int choose_con(int* choice){
   printf("1) To Celsius? \n2) To Fahrenheit?\n");
   if (scanf("%d", &(*choice)) != 1) {
       printf("Error: Invalid input\n");
       exit(1);
   }
}

void print_result(float* final){
    printf("The result is %.2f.", *final);
}


float fah_to_cel(float temperature){
    return 5.0/9.0*(temperature - 32);

}

float cel_to_fah(float temperature){
    return (9.0/5.0 * (temperature)) + 32;

}