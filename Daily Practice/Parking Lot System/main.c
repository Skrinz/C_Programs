#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "declaration.h"

void main(){
   ParkingArea list;
   ParkingHistory rec;
   int max, loc;
   char choice;


   //ask the user the maximum area of the parking lot
   printf("Enter the maximum parking lot: ");
   scanf("%i", &max);

   //initialize the parking slot information
   initParkingArea(&list, max);

   ParkingHistory rec = createParkingHistory(max);

   //display the rates
   printf("\n\tFirst 3 hours | Succeeding hours");
   printf("\n\tA      30     |   +10");
   printf("\n\tB      40     |   +10");
   printf("\n\tC     100     |   +10");

   while(1){

      printf("\n\n1)Park In\n2)Check Out\n3) Display Parking Area\n4) Check Parking History\n0) Exit\n");
      scanf(" %c", &choice);
      delnew;

      switch(choice){
            case '1':
               displayParkingArea(list);

               if(isFull(list) == true){
                  printf("\n\nSorry the parking area is full!!\n\n");
                  break;
               }

               //ask the user where do they want to park
               printf("\nWhere do you want to park? ");
               scanf("%i", &loc);
               delnew;

               //if the parking lot is taken display taken otherwise proceed;
               if(list.slot[loc].taken == true){
                  printf("The parking lot is taken\n");
                  break;
               }

               //create parking info not including time out
               list.slot[loc] = createParkingInfo(&list);



               break;
            case '2':
            case '3':
               //displayParkingArea();
               break;
            case '4':
               //displayParkingHistory();
               break;
            case '0':
               //delParkingInfo();
               return;
            default:
               printf("\n\nChoice Invalid!!\n\n");
               break;
      }

   }
}


//a switch case  of optiions (Parkin, check out, display parking area, check parking history)
   /*(parkin)
         -display the parking area ## void displayParkingArea(ParkingArea list)
            - if there is no car parked the display should have the default status (no value)
            - if there are car parked they should be in the proper no slot

         ////if the parking area is full display it is full and break otherwise proceed;
               ## bool isFull(list);
         //ask the user where do they want to park
            ////if the parking lot is taken display taken otherwise proceed;
               if(list.slot[loc].taken == true){
                  printf("The parking lot is taken\n");
                  break;
               }

         -ask for car details not including time in and time out
            ## ParkingInfo createParkingInfo(ParkingArea *list)

         ##  addParkIn(list.slot[loc], int loc)

   */

   //(parkout)search the plate number that wants to timeout then past it to parking receipt function