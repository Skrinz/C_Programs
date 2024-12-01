#include <stdio.h>
/*
Write a C program to calculate the average of three exam 
scores stored in an array and assign a letter grade based 
on the following scale:

Average Score >= 90: A
80 <= Average Score < 90: B
70 <= Average Score < 80: C
60 <= Average Score < 70: D
Average Score < 60: F
The program should take input for three exam scores, 
calculate the average, determine the letter grade, 
and print the result.

*/
int main (){
    int size = 3;
    int scores[size];
    int i;
    float avg = 0;
    int sum = 0;
    char grade;

    printf("Your scores? \n");

    //ask for the scores of the user
    for (i = 0; i < size; i++){
        printf("%d Exam scores: ", i+1);
        scanf("%d", &scores[i]);
    }

    //get the sum for the scores
    for (i = 0 ; i < size; i++){
        sum += scores[i];
    }
    
    //calculate for average
    avg = (float) sum/size;

    //get the grade assignment and print it
    if (avg >= 90){
        grade = 'A';
    }else if (avg >= 80 && avg < 90){
        grade = 'B';
    }else if (avg >= 70 && avg < 80){
        grade = 'C';
    }else if (avg >= 60 && avg < 70){
        grade = 'D';
    }else if (avg < 60){
        grade = 'F';
    }

    //print the average and the grade assignment
    printf("Your average score in %d Exam is %.2f.", size, avg);
    printf("\nAnd your grade assignmment is %c.", grade);

    return 0;
}