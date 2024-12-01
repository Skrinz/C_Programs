// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define max 100

typedef struct{
    char *item;
    int quant;
}grocery;

grocery list[max];
int items = 0;


void addItem();
void displayList();
void removeItem();

int main() {
    int choice;
    
    while(1){
        printf("1) Add An Item\n2) Display Grocery List\n3) Remove An Item\n4) End\n");
        scanf("%i", &choice);
        
        switch (choice){
            case 1:
                addItem();
                printf("Item Added\n\n");
                break;
               
            case 2: 
                if(items == 0){
                    printf("Grocery List is empty!!\n\n");
                    break;
                }else{
                    displayList();
                    break;
                }
                
            case 3:
                if(items == 0){
                    printf("Grocery List is empty!!\n\n");
                    break;
                }else{
                    removeItem();
                    break;
                }
            case 4:
                return 0;
            default:
                printf("Invalide choice");
                break;
        
        }
    }
}

void addItem(){
    grocery temp;
    
    printf("Enter the name of the item: ");
    temp.item = malloc (100*sizeof(char));
    while (getchar() != '\n');
    fgets(temp.item, 100, stdin);
    
    printf("Enter the quantity of the item: ");
    scanf("%i", &temp.quant);
    getchar();
    
    list[items++] = temp;
}

void displayList(){
    printf("Items in the grocery list: \n");
    
    for(int i = 0; i < items; i++){
        list[i].item[strcspn(list[i].item,"\n")] = '\0';
        printf("%i. %s - Quantity: %i\n", i+1,list[i].item, list[i].quant);
    }
    
    printf("\n\n");
}


void removeItem(){
    char *removeItem = malloc(100 * sizeof(char));
    
    printf("What item to remove? ");
    while (getchar() != '\n');
    fgets(removeItem, 100, stdin);
    
    removeItem[strcspn(removeItem, "\n")] = '\0';
    
    for(int i = 0; i < items; i++){
        if(strcmp(removeItem, list[i].item) == 0){
            free(list[i].item);
            for(int j = i; j < items; j++){
                list[j] = list[j+1];
            }
            
            items--;
            printf("Item removed\n\n");
            free(removeItem);
            return;
        }else{
            printf("Item not in the Grocery List\n\n");
            free(removeItem);
            return;
        }
    }
}   