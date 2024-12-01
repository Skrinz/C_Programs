#ifndef DECLARATION_H
#define DECLARATION_H

#define delnew while(getchar() != '\n')

typedef char String[20];

typedef struct{
    int hour;
    int min;
}MyTime;

typedef struct{
    char type;
    String plateNum;
    String color;
    String model;
}Vehicle;

typedef struct{
    Vehicle vehicle;
    MyTime timeIn;
    MyTime timeOut;
    bool taken;
}ParkingInfo;

typedef struct{
    ParkingInfo *slot;
    int count;
    int max;
}ParkingArea, ParkingHistory;


void initParkingArea(ParkingArea *list, int max);
void printParkingReceipt(ParkingInfo pi);
void createVehicle(Vehicle *vehicle, char type, String plateNum, String color, String model);
void createMyTime(MyTime *time, int hour, int min);
void delParkingInfo(ParkingArea *list, int loc);
void displayParkingArea(ParkingArea list);
void displayParkingHistory(ParkingArea list);
void addParkIn(ParkingInfo *slot);
void addParkOut(ParkingInfo *slot);
bool checkOutVehicle(ParkingArea *pa, ParkingHistory *ph);
bool isFull(ParkingArea list);
int searchVehicleByPlateNum(ParkingArea pa, String plateNum);
int calcTotalTime(MyTime *timeIn, MyTime *timeOut, MyTime *totalTime);
int initCharge(char type);
double calcAddCharge(int totalMin);
ParkingHistory createParkingHistory(int max);
ParkingInfo createParkingInfo(ParkingArea *list);


#endif