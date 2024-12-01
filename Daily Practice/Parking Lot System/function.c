#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "declaration.h"

void initParkingArea(ParkingArea *list, int max){
    
    list->slot = (ParkingInfo *) malloc(sizeof(ParkingInfo)*max);
    list->count = 0;
    list->max = max;
    
    //initialize the value of parking info to default
    for(int i = 0; i < max;i++){
        createVehicle(&list->slot[i].vehicle, ' ', " ", " ", " ");
        createMyTime(&list->slot[i].timeIn, 0, 0);
        createMyTime(&list->slot[i].timeOut, 0, 0);
        list->slot[i].taken = false;
    }
}

void printParkingReceipt(ParkingInfo pi){
    printf("\t=============Parking Receipt=============");
    printf("\nTYPE: %c", pi.vehicle.type);
    printf("\nVEHICLE: %s - %s - %s",pi.vehicle.plateNum, pi.vehicle.color, pi.vehicle.model);
    printf("\nTIME IN: %i:%i", pi.timeIn.hour,  pi.timeIn.min);
    printf("\nTIME OUT: %i:%i", pi.timeOut.hour, pi.timeOut.hour);

    //calculate the total time 
    MyTime totalTime;
    int totalMinutes = calcTotalTime(&pi.timeIn, &pi.timeOut, &totalTime);

    printf("\nTOTAL TIME: %i:%i", totalTime.hour, totalTime.min);

    //calculate the charges base on type, charge after 3 hours, and total charge
    int initcharge = initCharge(pi.vehicle.type);
    double addcharge = calcAddCharge(totalMinutes);

    double totalcharge = (double) initcharge + addcharge;

    printf("\nInitial Charge (first 3 hours): Php %i.00", initcharge);
    printf("\nAdditional Charge (after 3 hours): Php %.2lf", addcharge);
    printf("\nTotal Charge: Php %.2lf", totalcharge);
    
}

void createVehicle(Vehicle *vehicle, char type, String plateNum, String color, String model){
    vehicle->type = type;
    strcpy(vehicle->plateNum, plateNum);
    strcpy(vehicle->color, color);
    strcpy(vehicle->model, model);
}

void createMyTime(MyTime *time, int hour, int min){
    time->hour = hour;
    time->min = min;
}

void delParkingInfo(ParkingArea *list, int loc){
    // free(list->slot[loc]);
}

void displayParkingArea(ParkingArea list){
    printf("\n\nNO SLOT     |    STATUS");
    
    for(int i = 0; i < list.max; i++){
        if(list.slot[i].taken == true){
            printf("%i          |    %s - %s - %s\n", list.slot[i].vehicle.plateNum,
                                                      list.slot[i].vehicle.color, 
                                                      list.slot[i].vehicle.model);
        }else{
            printf("%i          |    available\n");
        }
    }
}

void displayParkingHistory(ParkingArea list){
}

void addParkIn(ParkingInfo *slot){
    int hourin,minin;
    //input timein
    printf("\nTime In (hour): ");
    scanf("%i",hourin);
    delnew;

    printf("\nTime In (min): ");
    scanf("%i", minin);
    delnew;

    //put the time in input of the user to the structured list
    createMyTime(&slot->timeIn, hourin, minin);
    
}

void addParkOut(ParkingInfo *slot){
    int hourout, minout;
    //input timeout
    printf("\nTime Out (hour): ");
    scanf("%i", hourout);
    delnew;

    printf("\nTime Out (min): ");
    scanf("%i", minout);
    delnew;

    //put the time out input of the user to the structured list
    createMyTime(&slot->timeOut, hourout, minout);
}

bool checkOutVehicle(ParkingArea *pa, ParkingHistory *ph){

}

bool isFull(ParkingArea list){
    return list.count == list.max;
}

int searchVehicleByPlateNum(ParkingArea pa, String plateNum){
    int i = 0;

    while(i < pa.max){
        if(strcmp(pa.slot[i].vehicle.plateNum, plateNum) == 0){
            break;
        }else if(i == pa.max){
            return -1;
        }else{
            i++;
        }
    }

    return i;
}

int calcTotalTime(MyTime *timeIn, MyTime *timeOut, MyTime *totalTime){
    //calculate the total time in and out by minutes
    int totalOut = (timeOut->hour*60)+ timeOut->min; 
    int totalIn = (timeIn->hour*60)+ timeIn->min;

    int totalMinutes = totalOut - totalIn;

    int totalHours = totalMinutes/60;
    int totalMins = totalMinutes%60;
    
    totalTime->hour = totalHours;
    totalTime->min = totalMins;

    return totalMinutes;
}

int initCharge(char type){
     switch(type) {
        case 'A':
            return 30;
        case 'B':
            return 40;
        case 'C':
            return 100;
        default:
            return -1;
    }
}

double calcAddCharge(int totalMin){
    if(totalMin <= 180){
        return 0.00;
    }
    return (double) (10*(totalMin - 180))/60;
}

ParkingHistory createParkingHistory(int max){
    ParkingHistory pa;
    initParkingArea(&pa, max);
    return pa;
}

ParkingInfo createParkingInfo(ParkingArea *list){ 
    ParkingInfo info;
    char type;
    String plateNum, color, model;

    //input vehicle details (type, plate#, color, model)
    printf("Enter Vehicle Type (A - motorcycle; B - car, sedan, SUV; C - truck): ");
    scanf(" %c", &type);

    printf("\nPlate Number: ");
    fgets(plateNum, 20, stdin);
    plateNum[strcspn(plateNum, "\n")] = '\0';

    printf("\nColor: ");
    fgets(color, 20, stdin);
    color[strcspn(color, "\n")] = '\0';

    printf("\nModel: ");
    fgets(model, 20, stdin);
    model[strcspn(model, "\n")] = '\0';

    //put the vehicle input of the user to the structured list
    createVehicle(&info.vehicle, type, plateNum, color, model);

    //check in the vehicle
    addParkIn(&info);

    info.taken = true;
    
    list->count++;

    return info;
}