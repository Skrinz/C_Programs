#include <stdio.h>

void main (){
    int gold;
    int pirates;
    int sum = 0;
    int checkTrip;

    printf("How many pirates? ");
    scanf("%d", &pirates);
    printf("How many gold? ");
    scanf("%d", &gold);

    sum = pirates +gold;

    if (sum > 100){
        checkTrip = 0;
    }else if (gold >= pirates){
        checkTrip = 1;
    }else {
        checkTrip = 0;
    }

    if (checkTrip){
        printf("Your adventure was a success.");
    }else {
        printf("Your adventure was a failure. ");
    }

}