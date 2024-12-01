#include <stdio.h>

void main (){
    int selection;
    float profit = 0;
    float sales;
    float expenses;
    int quantityB;
    int quantityS;

    printf("What would you like to do? \n");
    printf("1) Check business situation? \n");
    printf("2) Check if product saleable? \n");
    scanf("%d", &selection);

    if (selection != 1 && selection != 2){
        printf("Input invalid.\n");
        return;
    }
    
    switch (selection){
        case 1:
            printf("Sales: ");
            scanf("%f", &sales);
            printf("Expenses: ");
            scanf("%f", &expenses);
            
            profit = sales - expenses;
            
            printf("Profit: %.2f\n", profit);
            
            if (profit > 0){
                printf("The business is earning.");
                
            } else if (profit < 0) {
                printf("The business is losing.");
                
            }else{
                printf("The business is break even.");
                
            }
            
            break;
        case 2:
            printf("Quantity sold: ");
            scanf("%d", &quantityS);
            printf("Quantity bought: ");
            scanf("%d", &quantityB);
            
            if (quantityS >= quantityB){
                printf("The product is saleable.");
            }else if (quantityS < quantityB){
                printf("The product is not saleable.");
                
            }
            
            break;
    }   
}

