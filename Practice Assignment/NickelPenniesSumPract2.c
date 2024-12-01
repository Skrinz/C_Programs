#include <stdio.h>

int main (){
    int nickel = 5;
    int isum;
    int penny, inpt2;
    int x;
    
    //ask the user for how many penny
    printf("How many pennies do you have?\n");
    scanf("%d", &penny);

    //ask the user for how many nickel
    printf("How many nickels do you have?\n");
    scanf("%d", &inpt2);

    //multiply the amount the nickel the user have with 5
    nickel *= inpt2;

    //ask the desired sum
    printf("What is your desired sum?\n");
    scanf("%d", &isum);
    
   //computation for exact change  
   int exp_pennies = isum % 5;
   int exp_nickels = isum / 5;
   
   if((inpt2 >= exp_nickels && penny >= exp_pennies) || penny >= isum || penny + nickel >= isum){
    printf("True");
   }else{
    printf("False");
   }
    return 0;     
}