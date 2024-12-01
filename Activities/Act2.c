
#include <stdio.h>

int main() {
   char gender;
   int num1;
   int num2;
   int selection;
   
   printf("What would you like to compare?\n");
   printf("1) Gender?\n2) Numbers?\n");
   scanf(" %d", &selection);
   
   switch (selection){
       case 1:
            printf("Enter the capital letter of the gender. (Boy or Girl)\n");
            scanf(" %c", &gender);
            
            if (gender == 'B'){
                printf("The gender is Boy.\n");
            }else if(gender == 'G'){
                printf("The gender is Girl.\n");
            }else{
                printf("The letter is not in the selection or.\n");
                printf("Please enter the capital letter of the gender.\n");
            }
            break;
            
        case 2:
            printf("What is number 1?\n");
            scanf(" %d", &num1);
            
            printf("What is number 2?\n");
            scanf(" %d", &num2);
            
            if (num1 >= num2){
                printf("Number 1 is greater than Number 2.\n");
            }else{
                printf("Number 2 is greater than Number 1.\n");
            }
            break;
            
        default:
            printf("The number you selected is invalid.\n");
            break;
    }
    return 0;
}
