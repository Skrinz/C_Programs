#include <stdio.h>

void main (){
    int card1;
    int card2;
    int sum = 0;

    printf("Your first card: ");
    scanf("%d", &card1);
    printf("Your second card: ");
    scanf("%d", &card2);

    if (card1 == 11){
        card1 = 1;
    }else if (card2 == 11){
        card2 = 1;
    }
    
    sum = card1 + card2;

    if (sum > 21){
        sum = 0;
    }

    printf("Sum of the two cards is %d.\n", sum);

}