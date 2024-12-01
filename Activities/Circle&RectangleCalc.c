#include<stdio.h>

//calculate area of the rectangle (A=L*W)
int recArea(int length, int width){
	return length*width;
}

//calculate perimeter of the rectangle (P=2L+2W)
int recPeri(int length, int width){
	return 2*length+2*width;
}

//calculate area of circle (A=3.14*R*R)
double cirArea(int radius){
	return 3.14*radius*radius;
}

//calculate the circumference of circle (C=2*3.14*R)
double cirCirc(int radius){
	return 2*3.14*radius;
}

//selection area
int main()
{
	int length;
	int width;
	int radius;
	int answer = 0;
	char operations[4] = {'1', '2', '3', '4'};
	char op;
	
	printf("Select what to calculate: \n");
	printf("1. Calculate the area of rectangle.\n");
	printf("2. Calculate the perimeter of rectangle.\n");
	printf("3. Calculate the area of circle. \n");
	printf("4. Calculate the circumference of circle.\n");
	scanf(" %c", &op);
	
	switch (op){
		case '1':
			printf("Length: ");
			scanf(" %d", &length);
			
			printf("Width: ");
			scanf(" %d", &width);
			
			answer = recArea(length, width);
			printf("The area of the rectangle is %d", answer);
			break;
			
		case '2':
			printf("Length: ");
			scanf(" %d", &length);
			
			printf("Width: ");
			scanf(" %d", &width);
			
			answer = recPeri(length, width);
			printf("The area of the rectangle is %d", answer);
			break;
			
		case '3':
			printf("Radius: ");
			scanf(" %d", &radius); 
			
			answer = cirArea(radius);
			printf("The are of the circle is %lf", answer);
			break;
			
		case '4':
			printf("Radius: ");
			scanf(" %d", &radius); 
			
			answer = cirCirc(radius);
			printf("The are of the circle is %lf", answer);
			break;
			
		default:
			printf("Select Properly. :)");
			return -1;	
	}
	return 0;	
}
