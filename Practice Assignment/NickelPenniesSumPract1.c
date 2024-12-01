#include <stdio.h>

int main (){
    int nickel = 5;
    int penny = 1;
    int isum, acsum = 0;
    int inpt1, inpt2;
    int x, ret;
    
    //ask the user for how many penny
    printf("How many pennies do you have? (0-4)\n");
    do{
        ret = scanf("%d", &inpt1);
        if (ret != 1){
            printf("INVALID INPUT\n");
            printf("How many pennies do you have?(0-4)\n");
            while(getchar() != '\n');
        } else if (inpt1 < 0 || inpt1 > 4){
            printf("INVALID INPUT\n");
            printf("How many pennies do you have?(0-4)\n");
        }
    }while(ret != 1 || inpt1 < 0 || inpt1 > 4);
    
    //ask the user for how many nickel
    printf("How many nickels do you have?\n");
    do{
        ret = scanf("%d", &inpt2);
        if (ret != 1){
            printf("INVALID INPUT\n");
            printf("How many nickels do you have?\n");
            while(getchar() != '\n');
        }

    }while(ret != 1);
    
    //ask the desired sum
    printf("What is your desired sum?\n");
    do{
        ret = scanf("%d", &isum);
        if (ret != 1){
            printf("INVALID INPUT\n");
            printf("What is your desired sum?\n");
            while(getchar() != '\n');
        }

    }while(ret != 1);
    
  //computation for exact change  
    for(int x = 0; x <= inpt2; x++){
        for (int y = 0; y <= inpt1; y++){
            acsum = x*nickel + y*penny;
            if(acsum >= isum){
                break;
            }
        }
        if(acsum >= isum){
            break;
        }
    }
     
       // check if the pennies and nickels the user have align with their desired sum 
        if(acsum == isum){
               printf("True");
            }else {
                printf("False");    
            }
        return 0;     
}