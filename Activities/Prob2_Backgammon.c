#include <stdio.h>

void main (){

    int dice1;
    int dice2;
    int sum;

    printf("Roll #1: ");
    scanf("%d", &dice1);
    printf("Roll #2: ");
    scanf("%d", &dice2);

    if (dice1 == dice2){
        sum = 2*(dice1 + dice2);
    }else{
        sum = dice1 + dice2;
    }

    printf("The sum of the 2 dice is %d. \n", sum);

}