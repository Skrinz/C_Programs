#include <stdio.h>
#include <math.h>

int main() {
    int num_input;
    int check_prime = 1;
    int ret;
    
    printf("Input an integer: ");
    
    do{
      ret = scanf("%d", &num_input);
       if (ret!= 1){
           printf("Invalid input. Try again\n");
           while (getchar() != '\n');
           printf("Input an integer: ");
       }

    }while (ret != 1);
    
    for (int x = 2 ; x <= sqrt(num_input); x++){
        if (num_input % x == 0){
            check_prime = 0;
            break;
        }
    }

    if (check_prime){
        printf("Prime");
    }else{
        printf("Not prime");
    }

    return 0;
}