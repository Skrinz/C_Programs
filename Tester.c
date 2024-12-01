#include <stdio.h>

void main (){
	//declare variables
	int num1;
	int num2;
	int hcf;
	int max;
	
	//ask for user input
	printf("First number: ");
	scanf("%d", &num1);
	printf("Second number: ");
	scanf("%d", &num2);
	
	//check what is the minimum number
	max = (num1 > num2)? num2: num1;
	
	//process the input
	for(int i = 1; i <= ma ; ++i){
		//check if i is a factor of both integers
		if (num1 % i == 0 && num2 % i == 0)
			hcf = i;	
	}
	//print the HCF of both numbers
	printf("HCF of %d and %d is %d", num1, num2, hcf);
}
