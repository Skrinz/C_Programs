#include <stdio.h>

int main (){
    int box_orange, box_potato, kilos_pork;
    float total_orange = 0, total_potato = 0, total_pork = 0, total_sales;

    printf("How many boxes of orange have you sold? ");
    scanf("%d", &box_orange);

    printf("How many boxes of potato have you sold? ");
    scanf("%d", &box_potato);

    printf("How many kilos of pork have you sold? ");
    scanf("%d", &kilos_pork);


    total_orange = (float)(16.50 * box_orange * 50) * 0.3;

    total_potato = (float) (21.23 * box_potato * 60) * 0.4;

    total_pork = (float)(160 * kilos_pork) * 0.4;

    total_sales = total_orange + total_potato + total_pork;

    printf("Total Sales: Php %.2f \n", total_sales);
    
    if (total_sales > 1000){
        printf("High Demand\n");
    }else if (total_sales > 500){
        printf("Average Demand\n");
    }else {
        printf("Low Demand\n");
    }

    return 0;
}