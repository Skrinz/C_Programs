#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaration.h"

int main() {
    char choice;
    Node *head = (Node*) malloc(sizeof(Node));
    head->next = NULL;

    printf("\tThe Linked List will only accept integers!\n\n");

    while(1){
        int data;
        int remData;
        printf("1)Insert at End\n2)Insert at Start\n3)Insert then Sort\n4)Remove a data\n5)Display Linked List\n0)End\n");
        scanf(" %c", &choice);
        while(getchar() != '\n');
       
       if((choice == '4' || choice == '5') && head->next == NULL){
            printf("\n\n\tThe Linked List is empyt!!\n\n");
            break;
       }else{
            printf("Enter an integer: ");
            scanf("%i", &data);
            while(getchar() != '\n');

            switch(choice){
                case '1':
                
                    insertAtEnd(head, data);
                
                    printf("\n\n\tNew node has been added at the end!!\n\n");
                    break;
                
                case '2':
                
                    insertAtEnd(head, data);
                
                    printf("\n\n\tNew node has been added at the start!!\n\n");
                    break;
                
                case '3':
                
                    insertAtEnd(head, data);
                
                    printf("\n\n\tThe added data has been sorted in the Linked List!!\n\n");
                    break;
                
                case '4':
                    if(head->next == NULL){
                        printf("\n\n\tThe linked list is empty!!\n\n");
                        break;
                    }
            
                    printf("Enter an integer to remove: ");
                    scanf("%i", &remData);
                    while(getchar() != '\n');
                
                    deleteNode(head, remData);
                    break;
            
                case '5':
                
                    displayList(head);
                    break;
                
                case '0':

                    deleteList(head);
                    printf("\n\n\tThe Linked List has been deleted!!\n\n");
                    return 0;
                
                default:
                    printf("\n\nChoice Invalid!!\n\n");
                    break;
            }  
        } 
    }     
}